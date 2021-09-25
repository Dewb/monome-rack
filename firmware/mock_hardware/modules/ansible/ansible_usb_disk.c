#include "init_common.h"
#include "main.h"
#include "monome.h"
#include "print_funcs.h"

#include "ansible_preset_docdef.h"
#include "ansible_usb_disk.h"

typedef char * FS_STRING;

#define DEBUG_ANSIBLE_USB_DISK 0
#define DISK_BLINK_INTERVAL 250

static void handler_UsbDiskKey(int32_t data);
static void handler_UsbDiskFront(int32_t data);

static bool usb_disk_mount_drive(void);
static bool usb_disk_backup_binary(FS_STRING fname);
static bool usb_disk_restore_backup(FS_STRING fname);
static bool usb_disk_load_flash(FS_STRING fname);
static bool usb_disk_save_flash(FS_STRING fname);
static void flush(void);
static void blink_read(void* o);
static void blink_write(void* o);

static char ansible_usb_disk_textbuf[ANSIBLE_USBDISK_TXTBUF_LEN] = { 0 };
static uint8_t usb_disk_buffer[ANSIBLE_USBDISK_BLOCKSIZE] = { 0 };
static jsmntok_t ansible_usb_disk_tokbuf[ANSIBLE_USBDISK_TOKBUF_LEN];

static volatile bool usb_disk_locked = false;

static bool usb_disk_lock(void)
{
    if (!usb_disk_locked)
    {
        usb_disk_locked = true;
        print_dbg("\r\n\r\n> usb disk locked");
        return true;
    }
    return false;
}

static void usb_disk_unlock(void)
{
    usb_disk_locked = false;
    print_dbg("\r\n> usb disk unlocked\r\n");
}

static volatile bool load_armed = false, save_armed = false;
static bool blink = false;

static void handler_UsbDiskKey(int32_t data)
{
}

static void handler_UsbDiskFront(s32 data)
{
}

static void blink_read(void* o)
{
}

static void blink_write(void* o)
{
}

void set_mode_usb_disk(void)
{
}

bool usb_disk_enter()
{
}

void usb_disk_exit()
{
}

void usb_disk_skip_apps(bool skip)
{
}

void usb_disk_select_app(ansible_mode_t mode)
{
}

size_t gets_chunks(char* dst, size_t len)
{
    return 0;
}

static void copy_chunks(char* dst, const char* src, size_t len)
{
}

static uint16_t buf_pos = 0;
size_t total_written = 0;

static void flush(void)
{
}

void puts_buffered(const char* src, size_t len)
{
}

static bool usb_disk_mount_drive(void)
{
}

static bool usb_disk_backup_binary(FS_STRING fname)
{
}

static bool usb_disk_restore_backup(FS_STRING fname)
{
}

static bool usb_disk_load_flash(FS_STRING fname)
{
}

static bool usb_disk_save_flash(FS_STRING fname)
{
}
