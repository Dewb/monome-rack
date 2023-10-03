## Teletype Keyboard Layouts

These JSON files define keyboard layouts for Teletype, selectable from the right-click menu. Keyboard layout choice is global for all Teletype modules, and is saved with the Rack settings, not the patch. 

### Why does Teletype need custom keyboard layouts?

The Teletype module firmware code operates directly on HID scancodes sent in USB packets. It acts more like a videogame input mapping system than a text entry system. Rack's GLFW input processing does attempt to do international layout translation, but this text-only mapping is not sufficient for Teletype to understand which keys are being pressed. Even on US keyboards, we have to remap from GLFW scancodes back to HID scancodes.

### How do I use this to improve support for my keyboard?

Copy one of the existing layouts and change the values of `"output"` to match the HID codes that Teletype should receive for a given GLFW keycode. 

For example, in the US Dvorak layout, the A key is still A, but the scancodes for B, C, and D should now produce <key>X</key>, <key>J</key>, and <key>E</key>.

```json
{
    "name": "US Dvorak",
    "keymap": [
        ...
        { "input": "GLFW_KEY_A", "output": "HID_A" },
        { "input": "GLFW_KEY_B", "output": "HID_X" },
        { "input": "GLFW_KEY_C", "output": "HID_J" },
        { "input": "GLFW_KEY_D", "output": "HID_E" },
        ...
    ]
}
```

By default, the entire key will be translated regardless which modifier keys are pressed, and the modifier state will be passed along to Teletype as is. 

If you need to map a character that is accessible via the shift key in your layout to a completely different key than its non-shifted character, you can add `"input_shift": true` to only remap the shifted character. If you need to customize the behavior so an input key produces a character that requires a shift key in the default US HID layout, you can add `"output_shift": true` to send a synthetic shift modifier to Teletype.

For example, one of the differences between US and UK keyboards is that the <key>"</key> and <key>@</key> characters swap positions as shifted characters on the <key>'</key> and <key>2</key> keys. 

```json
{
    "name": "UK",
    "keymap": [
        ...
        { "input": "GLFW_KEY_APOSTROPHE", "output": "HID_QUOTE" },
        { "input": "GLFW_KEY_APOSTROPHE", "input_shift": true, "output": "HID_2", "output_shift": true },
        ...
        { "input": "GLFW_KEY_2", "output": "HID_2" },
        { "input": "GLFW_KEY_2", "input_shift": true, "output": "HID_QUOTE", "output_shift": true },
        ...
    ]
}
```

Remapping of other modifiers is not currently supported, and Alt/Control/Meta are passed to Teletype unchanged. If you need the ability to remap other modifiers in order to properly map your keyboard, please [open an issue](https://github.com/Dewb/monome-rack/issues/new/choose).

### What are the GLFW and HID scancode names?

#### GLFW:
* GLFW documentation: https://www.glfw.org/docs/3.3/group__keys.html

#### HID:
* Atmel ASF USB HID header: https://github.com/avrxml/asf/blob/master/common/services/usb/class/hid/usb_protocol_hid.h

Teletype may add additional constants to cover gaps in ASF support, see
[TeletypeKeyboard.cpp](https://github.com/Dewb/monome-rack/tree/main/src/teletype/TeletypeKeyboard.cpp)
for a definitive list.
