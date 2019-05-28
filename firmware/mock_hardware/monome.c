#include "delay.h"
#include "print_funcs.h"
#include <string.h>

#include "events.h"
#include "ftdi.h"
#include "monome.h"

//------ defines

// manufacturer string length
#define MONOME_MANSTR_LEN 6
// product string lengthextern
#define MONOME_PRODSTR_LEN 8
// serial string length
#define MONOME_SERSTR_LEN 9
// tx buffer length
#define MONOME_TX_BUF_LEN 72

// level above which an LED must be set to be displayed on mono-brightness grid
#define VB_CUTOFF 7
//------- typedefs

//--- descriptor types

// protocol enumeration
typedef enum
{
    eProtocol40h, /// 40h and arduinome protocol (pre-2007)
    eProtocolSeries, /// series protocol (2007-2011)
    eProtocolMext, /// extended protocol (2011 - ? ), arcs + grids
    eProtocolNumProtocols // dummy and count
} eMonomeProtocol;

// device descriptor
typedef struct e_monomeDesc
{
    eMonomeProtocol protocol;
    eMonomeDevice device;
    u8 cols; // number of columns
    u8 rows; // number of rows
    u8 encs; // number of encoders
    u8 tilt; // has tilt (??)
    u8 vari; // is variable brightness, true/false
} monomeDesc;

//// dummy functions
static void read_serial_dummy(void) { return; }

//-------------------------------------
//------ extern variables

// connected flag
// u8 monomeConnect = 0;

// dirty flags for each quadrant or knob (bitwise)
u8 monomeFrameDirty = 0;
// a buffer big enough to hold all l data for 256 or arc4
// each led gets a full byte
u8 monomeLedBuffer[MONOME_MAX_LED_BYTES];

// global pointers to send functions.
read_serial_t monome_read_serial = &read_serial_dummy;
set_intense_t monome_set_intense;
// grid_led_t monome_grid_led;
grid_map_t monome_grid_map;
grid_level_map_t monome_grid_level_map;
ring_map_t monome_ring_map;
refresh_t monome_refresh;
//-----------------------------------------
//----- static variables

// descriptor for connected device
monomeDesc mdesc = {
    .protocol = eProtocolNumProtocols, // dummy
    .device = eDeviceNumDevices, // dummy
    .cols = 0,
    .rows = 0,
    .encs = 0,
    .tilt = 0,
};

// local rx byte count
static u8 rxBytes;
// event data
static event_t ev;
// local tx buffer
static u8 txBuf[MONOME_TX_BUF_LEN];

//---------------------------------------------
//------ static function declarations

// setup for each protocol
static void setup_40h(u8 cols, u8 rows);
static void setup_series(u8 cols, u8 rows);
static u8 setup_mext(void);

// rx for each protocol
static void read_serial_40h(void);
static void read_serial_series(void);
static void read_serial_mext(void);

// set intensity
static void set_intense_series(u8 level);
static void set_intense_mext(u8 level);

// tx for each protocol
///// no real reason not to use only grid/map at the moment
/* static void grid_led_40h(u8 x, u8 y, u8 val); */
/* static void grid_led_series(u8 x, u8 y, u8 val); */
/* static void grid_led_mext(u8 x, u8 y, u8 val); */

static void grid_map_40h(u8 x, u8 y, const u8* data);
static void grid_map_series(u8 x, u8 y, const u8* data);
static void grid_map_mext(u8 x, u8 y, const u8* data);

/// TODO: varibright
//static void grid_map_level_40h(u8 x, u8 val);
//static void grid_map_level_series(u8 x, u8 y, u8* data);
// static void grid_map_level_mext(u8 x, u8 y, const u8* data);

//static void ring_set_mext(u8 n, u8 rho, u8 val);
static void ring_map_mext(u8 n, u8* data);

//static void connect_write_event(void);
static inline void monome_grid_key_write_event(u8 x, u8 y, u8 val);
static inline void monome_grid_adc_write_event(u8 n, u16 val);
static inline void monome_ring_enc_write_event(u8 n, u8 val);
static inline void monome_ring_key_write_event(u8 n, u8 val);

//---------------------------------
//----- static variables

//----  function pointer arrays

// read serial and spawn events
static const read_serial_t readSerialFuncs[eProtocolNumProtocols] = {
    &read_serial_40h,
    &read_serial_series,
    &read_serial_mext,
};

// set intensity
static const set_intense_t intenseFuncs[eProtocolNumProtocols] = {
    NULL, // unsupported
    &set_intense_series,
    &set_intense_mext,
};

// grid/led
/* static grid_led_t gridLedFuncs[eProtocolNumProtocols] = { */
/*   &grid_led_40h, */
/*   &grid_led_series, */
/*   &grid_led_mext, */
/* }; */

// grid/map
static const grid_map_t gridMapFuncs[eProtocolNumProtocols] = {
    &grid_map_40h,
    &grid_map_series,
    &grid_map_mext,
};

// grid/level/map
/* static grid_level_map_t gridMapLevelFuncs[eProtocolNumProtavr32_lib/src/ocols] = { */
/*   NULL, // unsupported */
/*   NULL, // unsupported */
/*   &grid_map_level_mext, */
/* }; */

static const ring_map_t ringMapFuncs[eProtocolNumProtocols] = {
    NULL, // unsupported
    NULL, // unsupported
    &ring_map_mext,
};

// grid vs arc refresh
static const refresh_t refreshFuncs[eProtocolNumProtocols] = {
    &monome_grid_refresh,
    &monome_arc_refresh
};

//================================================
//----- extern function definitions

// init
void init_monome(void)
{
    u32 i;
    for (i = 0; i < MONOME_MAX_LED_BYTES; i++)
    {
        monomeLedBuffer[i] = 0;
    }
    //  print_dbg("\r\n finished monome class init");
}

// determine if FTDI string descriptors match monome device pattern
u8 check_monome_device_desc(char* mstr, char* pstr, char* sstr)
{
    char buf[16];
    u8 matchMan = 0;
    u8 i;
    u8 ret;
    //-- source strings are unicode so we need to look at every other byte
    // manufacturer
    for (i = 0; i < MONOME_MANSTR_LEN; i++)
    {
        buf[i] = mstr[i * 2];
    }
    buf[i] = 0;
    matchMan = (strncmp(buf, "monome", MONOME_MANSTR_LEN) == 0);
    /* print_dbg("\r\n manstring: "); */
    /* print_dbg(buf); */

    // serial number string
    for (i = 0; i < MONOME_SERSTR_LEN; i++)
    {
        buf[i] = sstr[i * 2];
    }
    buf[i] = 0;
    /* print_dbg("\r\n serial string: "); */
    /* print_dbg(buf); */
    if (matchMan == 0)
    {
        // didn't match the manufacturer string, but check the serial for DIYs
        if (strncmp(buf, "a40h", 4) == 0)
        {
            // this is probably an arduinome
            mdesc.protocol = eProtocol40h;
            mdesc.device = eDeviceGrid;
            mdesc.cols = 8;
            mdesc.rows = 8;
            // tilt?
            ret = 1;
        }
        else
        {
            // not a monome
            return 0;
        }
    }
    else
    { // matched manufctrr string
        if (buf[0] != 'm')
        {
            // not a monome, somehow. shouldn't happen
            return 0;
        }
        if (buf[3] == 'h')
        {
            // this is a 40h
            setup_40h(8, 8);
            return 1;
        }
        if (strncmp(buf, "m64-", 4) == 0)
        {
            // series 64
            setup_series(8, 8);
            return 1;
        }
        if (strncmp(buf, "m128-", 5) == 0)
        {
            // series 128
            setup_series(16, 8);
            return 1;
        }
        if (strncmp(buf, "m256-", 5) == 0)
        {
            // series 256
            setup_series(16, 16);
            return 1;
        }
        // if we got here, serial number didn't match series or 40h patterns.
        // so this is probably an extended-protocol device.
        // we need to query for device attributes
        return setup_mext();
    }
    return 0;
}

// check dirty flags and refresh leds
void monome_grid_refresh(void)
{
    // may need to wait after each quad until tx transfer is complete
    u8 busy = ftdi_tx_busy();

    // check quad 0
    if (monomeFrameDirty & 0b0001)
    {
        while (busy)
        {
            busy = ftdi_tx_busy();
        }
        (*monome_grid_map)(0, 0, monomeLedBuffer);
        monomeFrameDirty &= 0b1110;
        busy = 1;
    }
    // check quad 1
    if (monomeFrameDirty & 0b0010)
    {
        if (mdesc.cols > 7)
        {
            while (busy)
            {
                busy = ftdi_tx_busy();
            }
            (*monome_grid_map)(8, 0, monomeLedBuffer + 8);
            monomeFrameDirty &= 0b1101;
            busy = 1;
        }
    }
    // check quad 2
    if (monomeFrameDirty & 0b0100)
    {
        if (mdesc.rows > 7)
        {
            while (busy)
            {
                busy = ftdi_tx_busy();
            }
            (*monome_grid_map)(0, 8, monomeLedBuffer + 128);
            monomeFrameDirty &= 0b1011;
            busy = 1;
        }
    }
    // check quad 3
    if (monomeFrameDirty & 0b1000)
    {
        if ((mdesc.rows > 7) && (mdesc.cols > 7))
        {
            while (busy)
            {
                busy = ftdi_tx_busy();
            }
            (*monome_grid_map)(8, 8, monomeLedBuffer + 136);
            monomeFrameDirty &= 0b0111;
            busy = 1;
        }
    }
    while (busy)
    {
        busy = ftdi_tx_busy();
    }
}

// check flags and refresh arc
void monome_arc_refresh(void)
{
    // may need to wait after each quad until tx transfer is complete
    u8 busy = ftdi_tx_busy();
    u8 i;

    for (i = 0; i < mdesc.encs; i++)
    {
        if (monomeFrameDirty & (1 << i))
        {
            // if(i==1) print_dbg("\r\nsecond");
            while (busy)
            {
                busy = ftdi_tx_busy();
            }
            (*monome_ring_map)(i, monomeLedBuffer + (i << 6));
            monomeFrameDirty &= ~(1 << i);
            busy = 1;
        }
    }

    while (busy)
    {
        busy = ftdi_tx_busy();
    }
}

//---- convert to/from event data
// connect
void monome_connect_write_event(void)
{
    u8* data = (u8*)(&(ev.data));

    // print_dbg("\r\n posting monome connection event. ");
    // print_dbg(" device type: ");
    // print_dbg_ulong(mdesc.device);
    // print_dbg(" cols : ");
    // print_dbg_ulong(mdesc.cols);
    // print_dbg(" rows: ");
    // print_dbg_ulong(mdesc.rows);

    ev.type = kEventMonomeConnect;
    ev.type = kEventMonomeConnect;
    *data++ = (u8)(mdesc.device); // device (8bits)
    *data++ = mdesc.cols; // width / count
    *data++ = mdesc.rows; // height / resolution
    //  *data = 0; 		// unused
    event_post(&ev);
}

void monome_connect_parse_event_data(u32 data, eMonomeDevice* dev, u8* w, u8* h)
{
    u8* pdata = (u8*)(&data);
    *dev = (eMonomeDevice)(*pdata++);
    *w = *pdata++;
    *h = *pdata;
}

// grid key
static inline void monome_grid_key_write_event(u8 x, u8 y, u8 val)
{
    u8* data = (u8*)(&(ev.data));
    data[0] = x;
    data[1] = y;
    data[2] = val;
    ev.type = kEventMonomeGridKey;
    event_post(&ev);
}

void monome_grid_key_parse_event_data(u32 data, u8* x, u8* y, u8* val)
{
    u8* bdata = (u8*)(&data);
    *x = bdata[0];
    *y = bdata[1];
    *val = bdata[2];
}

// grid tilt / adc
static inline void monome_grid_adc_write_event(u8 n, u16 val)
{
    // TODO
}
void monome_grid_adc_parse_event_data(u32 data, u8* n, u16* val)
{
    // TODO
}

// ring encoder
static inline void monome_ring_enc_write_event(u8 n, u8 val)
{
    u8* data = (u8*)(&(ev.data));
    data[0] = n;
    data[1] = val;
    ev.type = kEventMonomeRingEnc;
    event_post(&ev);
}
void monome_ring_enc_parse_event_data(u32 data, u8* n, s8* val)
{
    u8* bdata = (u8*)(&data);
    *n = bdata[0];
    *val = bdata[1];
}

// ring press/lift
static inline void monome_ring_key_write_event(u8 n, u8 val)
{
    // TODO
}
void monome_ring_key_parse_event_data(u32 data, u8* n, u8* val)
{
    // TODO
}

// set quadrant refresh flag from pos
void monome_calc_quadrant_flag(u8 x, u8 y)
{
    if (x > 7)
    {
        if (y > 7)
        {
            monomeFrameDirty |= 0b1000;
        }
        else
        {
            monomeFrameDirty |= 0b0010;
        }
    }
    else
    {
        if (y > 7)
        {
            monomeFrameDirty |= 0b0100;
        }
        else
        {
            monomeFrameDirty |= 0b0001;
        }
    }
}

// set given quadrant dirty flag
extern void monome_set_quadrant_flag(u8 q)
{
    monomeFrameDirty |= (1 << q);
}

// convert flat framebuffer idx to x,y
void monome_idx_xy(u32 idx, u8* x, u8* y)
{
    *x = idx & 0xf;
    *y = (idx >> 4);
}

// convert x,y to framebuffer idx
u32 monome_xy_idx(u8 x, u8 y)
{
    return x | (y << 4);
}

// top-level led/set function
void monome_led_set(u8 x, u8 y, u8 z)
{
    monomeLedBuffer[monome_xy_idx(x, y)] = z;
    monome_calc_quadrant_flag(x, y);
}

// top-level led/toggle function
void monome_led_toggle(u8 x, u8 y)
{
    monomeLedBuffer[monome_xy_idx(x, y)] ^= 0xff;
    monome_calc_quadrant_flag(x, y);
}

// arc led/set function
void monome_arc_led_set(u8 enc, u8 ring, u8 val)
{
    monomeLedBuffer[ring + (enc << 6)] = val;
    monomeFrameDirty |= (1 << enc);
}

eMonomeDevice monome_device(void) { return mdesc.device; }
u8 monome_size_x(void) { return mdesc.cols; }
u8 monome_size_y(void) { return mdesc.rows; }
u8 monome_is_vari(void) { return mdesc.vari; }
u8 monome_encs(void) { return mdesc.encs; }

//=============================================
//------ static function definitions

// set function pointers
void set_funcs(void)
{
    // print_dbg("\r\n setting monome functions, protocol idx: ");
    // print_dbg_ulong(mdesc.protocol);
    monome_read_serial = readSerialFuncs[mdesc.protocol];
    monome_grid_map = gridMapFuncs[mdesc.protocol];
    monome_grid_level_map = gridMapFuncs[mdesc.protocol];
    monome_ring_map = ringMapFuncs[mdesc.protocol];
    monome_set_intense = intenseFuncs[mdesc.protocol];
    monome_refresh = refreshFuncs[mdesc.device == eDeviceArc]; // toggle on grid vs arc
}

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
///// protocol - specific functions

/////////////////////////////
// setup

// setup 40h-protocol device
static void setup_40h(u8 cols, u8 rows)
{
    // print_dbg("\r\n setup 40h device");
    mdesc.protocol = eProtocol40h;
    mdesc.device = eDeviceGrid;
    mdesc.cols = 8;
    mdesc.rows = 8;
    mdesc.vari = 0;
    set_funcs();
    monome_connect_write_event();
}

// setup series device
static void setup_series(u8 cols, u8 rows)
{
    // print_dbg("\r\n setup series device");
    mdesc.protocol = eProtocolSeries;
    mdesc.device = eDeviceGrid;
    mdesc.cols = cols;
    mdesc.rows = rows;
    mdesc.vari = 0;
    mdesc.tilt = 1;
    set_funcs();
    monome_connect_write_event();
    //  monomeConnect = 1;
    //  test_draw();
}

// setup extended device, return success /failure of query
static u8 setup_mext(void)
{
    u8* prx;
    u8 w = 0;
    u8 busy;

    // print_dbg("\r\n setup mext device");
    mdesc.protocol = eProtocolMext;

    mdesc.vari = 1;

    rxBytes = 0;

    while (rxBytes != 6)
    {
        // FIXME: fuck these delays
        delay_ms(1);
        ftdi_write(&w, 1); // query

        delay_ms(1);
        ftdi_read();

        delay_ms(1);
        busy = 1;

        // print_dbg("\r\n setup request ftdi read; waiting...");
        while (busy)
        {
            busy = ftdi_rx_busy();
        }
        rxBytes = ftdi_rx_bytes();

        // print_dbg(" done waiting. bytes read: ");
        // print_dbg_ulong(rxBytes);

        if (rxBytes != 6)
        {
            print_dbg("\r\n got unexpected byte count in response to mext setup request; \r\n");
            prx = ftdi_rx_buf();

            for (; rxBytes != 0; rxBytes--)
            {
                print_dbg_ulong(*(++prx));
                print_dbg(" ");
            }

            // return 0;
        }
    }

    prx = ftdi_rx_buf();
    prx++; // 1st returned byte is 0
    if (*prx == 1)
    {
        mdesc.device = eDeviceGrid;
        prx++;
        if (*prx == 1)
        {
            // print_dbg("\r\n monome 64");
            mdesc.rows = 8;
            mdesc.cols = 8;
        }
        else if (*prx == 2)
        {
            // print_dbg("\r\n monome 128");
            mdesc.rows = 8;
            mdesc.cols = 16;
        }
        else if (*prx == 4)
        {
            // print_dbg("\r\n monome 256");
            mdesc.rows = 16;
            mdesc.cols = 16;
        }
        else
        {
            return 0; // bail
        }
        mdesc.tilt = 1;
    }
    else if (*prx == 5)
    {
        mdesc.device = eDeviceArc;
        mdesc.encs = *(++prx);
        print_dbg("\r\n monome arc ");
        print_dbg_ulong(*prx);
    }
    else
    {
        print_dbg_hex(*prx);
        print_dbg_hex(*(++prx));
        print_dbg_hex(*(++prx));
        return 0; // bail
    }

    // get id
    w = 1;
    delay_ms(1);
    ftdi_write(&w, 1);
    delay_ms(1);
    ftdi_read();
    delay_ms(1);
    busy = 1;
    while (busy)
    {
        busy = ftdi_rx_busy();
    }
    rxBytes = ftdi_rx_bytes();
    prx = ftdi_rx_buf();
    if (*(prx + 2) == 'k')
        mdesc.vari = 0;
    // print_dbg("\r\ndone waiting. bytes read: ");
    // print_dbg_ulong(rxBytes);
    // print_dbg("\r\ndata: ");
    // print_dbg_char(*prx);
    //   for(;rxBytes != 0; rxBytes--) {
    //     print_dbg_char(*(++prx));
    //   }

    set_funcs();
    monome_connect_write_event();
    //  monomeConnect = 1;
    // print_dbg("\r\n connected monome device, mext protocol");
    //  test_draw();
    return 1;
}

////////////////////////////
//--- rx
// rx for each protocol
/// parse serial input from device
/// should be called when read is complete
/// (e.g. from usb transfer callback )

static void read_serial_40h(void)
{
    u8* prx = ftdi_rx_buf();
    u8 i;
    rxBytes = ftdi_rx_bytes();
    // print_dbg("\r\n read_serial_40h, byte count: ");
    // print_dbg_ulong(rxBytes);
    // print_dbg(" ; data : [ 0x");
    // print_dbg_hex(prx[0]);
    // print_dbg(" , 0x");
    // print_dbg_hex(prx[1]);
    // print_dbg(" ]");
    i = 0;
    while (i < rxBytes)
    {
        // FIXME: can we expect other event types? (besides press/lift)
        // print_dbg(" ; x : 0x");
        // print_dbg_hex((prx[1] & 0xf0) >> 4);
        // print_dbg("; y : 0x");
        // print_dbg_hex(prx[1] & 0xf);
        // print_dbg(" ; z : 0x");
        // print_dbg_hex(   ((prx[0] & 0xf) != 0) );

        // press event
        if ((prx[0] & 0xf0) == 0)
        {
            monome_grid_key_write_event(
                ((prx[1] & 0xf0) >> 4),
                prx[1] & 0xf,
                ((prx[0] & 0xf) != 0));
        }

        i += 2;
        prx += 2;
    }
}

static void read_serial_series(void)
{
    u8* prx = ftdi_rx_buf();
    u8 i;
    rxBytes = ftdi_rx_bytes();
    // print_dbg("\r\n read_serial_series, byte count: ");
    // print_dbg_ulong(rxBytes);
    // print_dbg(" ; data : [ 0x");
    // print_dbg_hex(prx[0]);
    // print_dbg(" , 0x");
    // print_dbg_hex(prx[1]);
    // print_dbg(" ]");
    i = 0;
    while (i < rxBytes)
    {
        // FIXME: can we expect other event types? (besides press/lift)
        /* print_dbg(" ; x : 0x"); */
        /* print_dbg_hex((prx[1] & 0xf0) >> 4); */
        /* print_dbg("; y : 0x"); */
        /* print_dbg_hex(prx[1] & 0xf); */
        /* print_dbg(" ; z : 0x"); */
        /* print_dbg_hex(	 ((prx[0] & 0xf0) == 0) ); */

        // process consecutive pairs of bytes
        monome_grid_key_write_event(((prx[1] & 0xf0) >> 4),
            prx[1] & 0xf,
            ((prx[0] & 0xf0) == 0));
        i += 2;
        prx += 2;
    }
}

static void read_serial_mext(void)
{
    //  static u8 nbr; // number of bytes read
    static u8 nbp; // number of bytes processed
    static u8* prx; // pointer to rx buf
    static u8 com;

    rxBytes = ftdi_rx_bytes();
    if (rxBytes)
    {
        nbp = 0;
        prx = ftdi_rx_buf();
        while (nbp < rxBytes)
        {
            com = (u8)(*(prx++));
            nbp++;
            switch (com)
            {
                case 0x20: // grid key up
                    monome_grid_key_write_event(*prx, *(prx + 1), 0);
                    nbp += 2;
                    prx += 2;
                    break;
                case 0x21: // grid key down
                    monome_grid_key_write_event(*prx, *(prx + 1), 1);
                    nbp += 2;
                    prx += 2;
                    break;
                case 0x50: // ring delta
                    monome_ring_enc_write_event(*prx, *(prx + 1));
                    nbp += 2;
                    prx += 2;
                    break;
                case 0x51: // ring key up
                    monome_ring_key_write_event(*prx++, 0);
                    prx++;
                    break;
                case 0x52: // ring key down
                    monome_ring_key_write_event(*prx++, 1);
                    nbp++;
                    break;
                    /// TODO: more commands...
                default:
                    return;
            }
        }
    }
}

//--- tx

///// not using per-led updates.
/* static void grid_led_40h(u8 x, u8 y, u8 val) { */
/*   // TODO */
/* } */

/* static void grid_led_series(u8 x, u8 y, u8 val) { */
/*   //  static u8 tx[2]; */
/*   txBuf[0] = 0x20 & ((val > 0) << 4); */
/*   txBuf[1] = (x << 4) | y; */
/*   ftdi_write(txBuf, 2); */
/* } */

/* static void grid_led_mext(u8 x, u8 y, u8 val) { */
/*   //  static u8 tx[3]; */
/*   txBuf[0] = 0x10 | (val > 0); */
/*   txBuf[1] = x; */
/*   txBuf[2] = y; */
/*   ftdi_write(txBuf, 3); */
/* } */

// update a whole frame
// . note that our input data is one byte per led!!
// this will hopefully help optimize operator routines,
// which cannot be called less often than refresh/tx, and are therefore prioritized.
////////////////////////////////////////////////
// HACKED to always do var-bright update
////////////////////////////////////////////////
static void grid_map_mext(u8 x, u8 y, const u8* data)
{
    //  static u8 tx[11] = { 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    static u8* ptx;
    static u8 i, j;

    txBuf[0] = 0x1A;
    txBuf[1] = x;
    txBuf[2] = y;

    ptx = txBuf + 3;

    // copy and convert
    for (i = 0; i < MONOME_QUAD_LEDS; i++)
    {
        // *ptx = 0;
        for (j = 0; j < 4; j++)
        {
            // binary value of data byte to bitfield of tx byte
            // *ptx |= ((*data > 0) << j);
            *ptx = (*data) << 4;
            data++;
            *ptx |= *data;
            data++;
            ptx++;
        }
        data += MONOME_QUAD_LEDS; // skip the rest of the row to get back in target quad
        // ptx++;
    }
    ftdi_write(txBuf, 32 + 3);
}

static void grid_map_40h(u8 x, u8 y, const u8* data)
{
    // print_dbg("\n\r=== grid_map_40h ===");
    static u8 i, j;
    // ignore all but first quadrant -- do any devices larger than 8x8 speak 40h?
    if (x != 0 || y != 0)
    {
        return;
    }
    for (i = 0; i < MONOME_QUAD_LEDS; i++)
    {
        // led row command + row number
        txBuf[(i * 2)] = 0x70 + i;
        txBuf[(i * 2) + 1] = 0;
        // print_dbg("\r\n * data bytes: ");
        for (j = 0; j < MONOME_QUAD_LEDS; j++)
        {
            // set row bit if led should be on
            // print_dbg("0x");
            // print_dbg_hex(*data);
            // print_dbg(" ");
            txBuf[(i * 2) + 1] |= ((*data > 0) << j);
            // advance data to next bit
            ++data;
        }
        // skip next 8 bytes to get to next row
        data += MONOME_QUAD_LEDS;
        // print_dbg("\n\r 40h: send led_row command: ");
        // print_dbg_hex(txBuf[i*2]);
        // print_dbg(" row data: 0x");
        // print_dbg_hex(txBuf[(i*2) + 1]);
    }
    ftdi_write(txBuf, 16);
}

static void grid_map_series(u8 x, u8 y, const u8* data)
{
    static u8* ptx;
    static u8 i, j;
    // command (upper nibble)
    txBuf[0] = 0x80;
    // quadrant index (lower nibble, 0-3)
    txBuf[0] |= ((x > 7) | ((y > 7) << 1));

    // print_dbg("\n\r series map: ");
    // print_dbg_hex(txBuf[0]);

    // pointer to tx data
    ptx = txBuf + 1;

    // copy and convert
    for (i = 0; i < MONOME_QUAD_LEDS; i++)
    {
        *ptx = 0;
        for (j = 0; j < MONOME_QUAD_LEDS; j++)
        {
            // binary value of data byte to bitfield of tx byte
            *ptx |= ((*data > VB_CUTOFF) << j);
            ++data;
        }
        // print_dbg(" ");
        // print_dbg_hex(*ptx);

        data += MONOME_QUAD_LEDS; // skip the rest of the row to get back in target quad
        ++ptx;
    }
    ftdi_write(txBuf, MONOME_QUAD_LEDS + 1);
}

/* static void grid_map_level_mext(u8 x, u8 y, const u8* data) { */
/*   // TODO */
/* } */

static void ring_map_mext(u8 n, u8* data)
{
    //  static u8 tx[11] = { 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    static u8* ptx;
    static u8 i;

    txBuf[0] = 0x92;
    txBuf[1] = n;

    ptx = txBuf + 2;

    // smash 64 LEDs together, nibbles
    for (i = 0; i < 32; i++)
    {
        *ptx = *data << 4;
        data++;
        *ptx |= *data;
        data++;
        ptx++;
    }

    ftdi_write(txBuf, 32 + 2);
}

static void set_intense_series(u8 v)
{
    /*
message id:	(10) intensity
bytes:		1
format:		iiiibbbb
			i (message id) = 10
			b (brightness) = 0-15 (4 bits)
encode:		byte 0 = ((id) << 4) | b = 160 + b
*/
    txBuf[0] = 0xa0;
    txBuf[0] |= (v & 0x0f);
    ftdi_write(txBuf, 1);
}

static void set_intense_mext(u8 v)
{
    // TODO
}
