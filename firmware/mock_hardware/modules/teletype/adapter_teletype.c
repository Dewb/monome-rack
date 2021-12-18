#include "mock_hardware_api.h"
#include "mock_hardware_api_private.h"

#include "module/edit_mode.h"
#include "module/flash.h"
#include "module/gitversion.h"
#include "module/globals.h"
#include "module/live_mode.h"
#include "module/preset_w_mode.h"
#include "src/serialize.h"
#include "src/teletype_io.h"
#include "types.h"

void clock_null(uint8_t phase) { }
typedef void (*clock_pulse_t)(uint8_t phase);
volatile uint8_t clock_external;
volatile clock_pulse_t clock_pulse = &clock_null;

void tele_usb_disk() { }

extern u8 get_revision(void)
{
    return 0;
}

void hardware_serializePreset(tt_serializer_t* stream, uint8_t preset_num)
{
    if (preset_num == 255) {
        // save from active scene state and text
        serialize_scene(stream, &scene_state, &scene_text);
    }
    else
    {
        // save from flash
        scene_state_t scene;
        ss_init(&scene);

        char text[SCENE_TEXT_LINES][SCENE_TEXT_CHARS];
        memset(text, 0, SCENE_TEXT_LINES * SCENE_TEXT_CHARS);
        
        flash_read(preset_num, &scene, &text, 1, 1, 1);
        serialize_scene(stream, &scene, &text);
    }
}


// copied and modified from module/flash.c
void fake_flash_read(scene_state_t* src_scene, scene_state_t* dest_scene,
    char (*src_text)[SCENE_TEXT_LINES][SCENE_TEXT_CHARS], char (*dest_text)[SCENE_TEXT_LINES][SCENE_TEXT_CHARS],
    uint8_t init_pattern, uint8_t init_grid,
    uint8_t init_i2c_op_address)
{
    memcpy(ss_scripts_ptr(dest_scene), ss_scripts_ptr(src_scene),
        // Exclude size of TEMP script as above
        ss_scripts_size() - sizeof(scene_script_t));

    if (init_pattern)
    {
        memcpy(ss_patterns_ptr(dest_scene), ss_patterns_ptr(src_scene),
            ss_patterns_size());
    }
    if (init_grid)
    {
        memcpy(&dest_scene->grid, &src_scene->grid, sizeof(scene_grid_t));
    }
    memcpy(dest_text, src_text, SCENE_TEXT_LINES * SCENE_TEXT_CHARS);
    // need to reset timestamps
    uint32_t ticks = tele_get_ticks();
    for (size_t i = 0; i < TEMP_SCRIPT; i++)
        dest_scene->scripts[i].last_time = ticks;
    dest_scene->variables.time = 0;

    if (init_i2c_op_address)
        dest_scene->i2c_op_address = -1;
    ss_midi_init(dest_scene);
}

// copied and modified from module/flash.c
void fake_do_preset_read(scene_state_t* src_scene, scene_state_t* dest_scene,
    char (*src_text)[SCENE_TEXT_LINES][SCENE_TEXT_CHARS], char (*dest_text)[SCENE_TEXT_LINES][SCENE_TEXT_CHARS],
    uint8_t init_pattern, uint8_t init_grid,
    uint8_t init_i2c_op_address, uint8_t run_init)
{
    ss_grid_init(dest_scene);
    fake_flash_read(src_scene, dest_scene, src_text, dest_text, init_pattern, init_grid, init_i2c_op_address);

    set_dash_updated();
    if (run_init) {
        scene_state.initializing = true;
        run_script(&scene_state, INIT_SCRIPT);
        scene_state.initializing = false;
    }
}

void hardware_deserializePreset(tt_deserializer_t* stream, uint8_t preset_num, bool clearExisting)
{
    if (preset_num == 255)
    {
        scene_state_t scene;
        ss_init(&scene);

        char text[SCENE_TEXT_LINES][SCENE_TEXT_CHARS];
        memset(text, 0, SCENE_TEXT_LINES * SCENE_TEXT_CHARS);

        if (!clearExisting) {
            memcpy(&scene, &scene_state, sizeof(scene_state_t));
            memcpy(text, scene_text, SCENE_TEXT_LINES * SCENE_TEXT_CHARS);
        }
        deserialize_scene(stream, &scene, &text);

        // load into active scene state and text
        fake_do_preset_read(&scene, &scene_state, &text, &scene_text, 1, 1, 1, clearExisting ? 1 : 0);

        // refresh some obvious things that might have been affected by the load
        set_preset_w_mode();
        set_edit_mode_script(get_edit_script());
        tele_pattern_updated();
        scene_state.grid.grid_dirty = 1;
    }
    else
    {
        // load into flash
        scene_state_t scene;
        ss_init(&scene);

        char text[SCENE_TEXT_LINES][SCENE_TEXT_CHARS];
        memset(text, 0, SCENE_TEXT_LINES * SCENE_TEXT_CHARS);

        deserialize_scene(stream, &scene, &text);
        flash_write(preset_num, &scene, &text);
    }
}

void calibrate_adc()
{
    // set PARAM and IN calibration to cover 0-16383
    ss_set_in_min(&scene_state, 0);
    ss_set_in_max(&scene_state, 16380);
    ss_set_param_min(&scene_state, 0);
    ss_set_param_max(&scene_state, 16380);
}

void hardware_afterVRAMUpdate()
{
    tele_metro_updated();
    tele_vars_updated();
    set_preset_w_mode();
    set_edit_mode_script(get_edit_script());
    tele_pattern_updated();
    scene_state.grid.grid_dirty = 1;

    calibrate_adc();
}

void hardware_afterInit()
{
    calibrate_adc();
}

int ss_defeat_counter = 0;
extern void process_keypress(uint8_t key, uint8_t mod_key, bool is_held_key, bool is_release);

void hardware_afterStep()
{
    if (++ss_defeat_counter > 48000)
    {
        // send a fake keypress to reset screensaver timer
        process_keypress(0xFF, 0, false, true);
        ss_defeat_counter = 0;
    }
}

void hardware_getVersion(char* buffer)
{
    strcpy(buffer, git_version);
}

double hardware_getClockPeriod()
{
    return 0.001;
}
