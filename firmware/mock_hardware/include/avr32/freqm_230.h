/*****************************************************************************
 *
 * Copyright (C) 2008-2010 Atmel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * * Neither the name of the copyright holders nor the names of
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * 
 * Model        : UC3000
 * Revision     : $Revision: 74772 $
 * Checkin Date : $Date: 2010-05-14 06:51:12 +0200 (Fri, 14 May 2010) $ 
 *
 ****************************************************************************/
#ifndef AVR32_FREQM_230_H_INCLUDED
#define AVR32_FREQM_230_H_INCLUDED

#define AVR32_FREQM_H_VERSION 230

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_FREQM_<register>
 - Bitfield mask:   AVR32_FREQM_<register>_<bitfield>
 - Bitfield offset: AVR32_FREQM_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_FREQM_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_FREQM_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_FREQM_<bitfield>
 - Bitfield offset: AVR32_FREQM_<bitfield>_OFFSET
 - Bitfield size:   AVR32_FREQM_<bitfield>_SIZE
 - Bitfield values: AVR32_FREQM_<bitfield>_<value name>
 - Bitfield values: AVR32_FREQM_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_FREQM_BUSY                                              0
#define AVR32_FREQM_BUSY_MASK                                0x00000001
#define AVR32_FREQM_BUSY_OFFSET                                       0
#define AVR32_FREQM_BUSY_SIZE                                         1
#define AVR32_FREQM_CLKSEL                                           16
#define AVR32_FREQM_CLKSEL_CPU                               0x00000000
#define AVR32_FREQM_CLKSEL_CRIPLEL                           0x0000000a
#define AVR32_FREQM_CLKSEL_GENCLK0                           0x0000000b
#define AVR32_FREQM_CLKSEL_GENCLK1                           0x0000000c
#define AVR32_FREQM_CLKSEL_GENCLK2                           0x0000000d
#define AVR32_FREQM_CLKSEL_GENCLK3                           0x0000000e
#define AVR32_FREQM_CLKSEL_GENCLK4                           0x0000000f
#define AVR32_FREQM_CLKSEL_GENCLK5                           0x00000010
#define AVR32_FREQM_CLKSEL_HSB                               0x00000001
#define AVR32_FREQM_CLKSEL_MASK                              0x001f0000
#define AVR32_FREQM_CLKSEL_OFFSET                                    16
#define AVR32_FREQM_CLKSEL_OSC0                              0x00000004
#define AVR32_FREQM_CLKSEL_OSC1                              0x00000005
#define AVR32_FREQM_CLKSEL_OSC32                             0x00000006
#define AVR32_FREQM_CLKSEL_PBA                               0x00000002
#define AVR32_FREQM_CLKSEL_PBB                               0x00000003
#define AVR32_FREQM_CLKSEL_PLL0                              0x00000008
#define AVR32_FREQM_CLKSEL_PLL1                              0x00000009
#define AVR32_FREQM_CLKSEL_RCOSC                             0x00000007
#define AVR32_FREQM_CLKSEL_SIZE                                       5
#define AVR32_FREQM_CPU                                      0x00000000
#define AVR32_FREQM_CRIPLEL                                  0x0000000a
#define AVR32_FREQM_CTRL                                     0x00000000
#define AVR32_FREQM_CTRL_START                                        0
#define AVR32_FREQM_CTRL_START_MASK                          0x00000001
#define AVR32_FREQM_CTRL_START_OFFSET                                 0
#define AVR32_FREQM_CTRL_START_SIZE                                   1
#define AVR32_FREQM_DONE                                              0
#define AVR32_FREQM_DONE_MASK                                0x00000001
#define AVR32_FREQM_DONE_OFFSET                                       0
#define AVR32_FREQM_DONE_SIZE                                         1
#define AVR32_FREQM_GENCLK0                                  0x0000000b
#define AVR32_FREQM_GENCLK1                                  0x0000000c
#define AVR32_FREQM_GENCLK2                                  0x0000000d
#define AVR32_FREQM_GENCLK3                                  0x0000000e
#define AVR32_FREQM_GENCLK4                                  0x0000000f
#define AVR32_FREQM_GENCLK5                                  0x00000010
#define AVR32_FREQM_HSB                                      0x00000001
#define AVR32_FREQM_ICR                                      0x00000020
#define AVR32_FREQM_ICR_DONE                                          0
#define AVR32_FREQM_ICR_DONE_MASK                            0x00000001
#define AVR32_FREQM_ICR_DONE_OFFSET                                   0
#define AVR32_FREQM_ICR_DONE_SIZE                                     1
#define AVR32_FREQM_IDR                                      0x00000014
#define AVR32_FREQM_IDR_DONE                                          0
#define AVR32_FREQM_IDR_DONE_MASK                            0x00000001
#define AVR32_FREQM_IDR_DONE_OFFSET                                   0
#define AVR32_FREQM_IDR_DONE_SIZE                                     1
#define AVR32_FREQM_IER                                      0x00000010
#define AVR32_FREQM_IER_DONE                                          0
#define AVR32_FREQM_IER_DONE_MASK                            0x00000001
#define AVR32_FREQM_IER_DONE_OFFSET                                   0
#define AVR32_FREQM_IER_DONE_SIZE                                     1
#define AVR32_FREQM_IMR                                      0x00000018
#define AVR32_FREQM_IMR_DONE                                          0
#define AVR32_FREQM_IMR_DONE_MASK                            0x00000001
#define AVR32_FREQM_IMR_DONE_OFFSET                                   0
#define AVR32_FREQM_IMR_DONE_SIZE                                     1
#define AVR32_FREQM_ISR                                      0x0000001c
#define AVR32_FREQM_ISR_DONE                                          0
#define AVR32_FREQM_ISR_DONE_MASK                            0x00000001
#define AVR32_FREQM_ISR_DONE_OFFSET                                   0
#define AVR32_FREQM_ISR_DONE_SIZE                                     1
#define AVR32_FREQM_MODE                                     0x00000004
#define AVR32_FREQM_MODE_CLKSEL                                      16
#define AVR32_FREQM_MODE_CLKSEL_CPU                          0x00000000
#define AVR32_FREQM_MODE_CLKSEL_CRIPLEL                      0x0000000a
#define AVR32_FREQM_MODE_CLKSEL_GENCLK0                      0x0000000b
#define AVR32_FREQM_MODE_CLKSEL_GENCLK1                      0x0000000c
#define AVR32_FREQM_MODE_CLKSEL_GENCLK2                      0x0000000d
#define AVR32_FREQM_MODE_CLKSEL_GENCLK3                      0x0000000e
#define AVR32_FREQM_MODE_CLKSEL_GENCLK4                      0x0000000f
#define AVR32_FREQM_MODE_CLKSEL_GENCLK5                      0x00000010
#define AVR32_FREQM_MODE_CLKSEL_HSB                          0x00000001
#define AVR32_FREQM_MODE_CLKSEL_MASK                         0x001f0000
#define AVR32_FREQM_MODE_CLKSEL_OFFSET                               16
#define AVR32_FREQM_MODE_CLKSEL_OSC0                         0x00000004
#define AVR32_FREQM_MODE_CLKSEL_OSC1                         0x00000005
#define AVR32_FREQM_MODE_CLKSEL_OSC32                        0x00000006
#define AVR32_FREQM_MODE_CLKSEL_PBA                          0x00000002
#define AVR32_FREQM_MODE_CLKSEL_PBB                          0x00000003
#define AVR32_FREQM_MODE_CLKSEL_PLL0                         0x00000008
#define AVR32_FREQM_MODE_CLKSEL_PLL1                         0x00000009
#define AVR32_FREQM_MODE_CLKSEL_RCOSC                        0x00000007
#define AVR32_FREQM_MODE_CLKSEL_SIZE                                  5
#define AVR32_FREQM_MODE_REFNUM                                       8
#define AVR32_FREQM_MODE_REFNUM_MASK                         0x0000ff00
#define AVR32_FREQM_MODE_REFNUM_OFFSET                                8
#define AVR32_FREQM_MODE_REFNUM_SIZE                                  8
#define AVR32_FREQM_MODE_REFSEL                                       0
#define AVR32_FREQM_MODE_REFSEL_MASK                         0x00000001
#define AVR32_FREQM_MODE_REFSEL_OFFSET                                0
#define AVR32_FREQM_MODE_REFSEL_REF_OSC32                    0x00000001
#define AVR32_FREQM_MODE_REFSEL_REF_RCOSC                    0x00000000
#define AVR32_FREQM_MODE_REFSEL_SIZE                                  1
#define AVR32_FREQM_OSC0                                     0x00000004
#define AVR32_FREQM_OSC1                                     0x00000005
#define AVR32_FREQM_OSC32                                    0x00000006
#define AVR32_FREQM_PBA                                      0x00000002
#define AVR32_FREQM_PBB                                      0x00000003
#define AVR32_FREQM_PLL0                                     0x00000008
#define AVR32_FREQM_PLL1                                     0x00000009
#define AVR32_FREQM_RCOSC                                    0x00000007
#define AVR32_FREQM_REFNUM                                            8
#define AVR32_FREQM_REFNUM_MASK                              0x0000ff00
#define AVR32_FREQM_REFNUM_OFFSET                                     8
#define AVR32_FREQM_REFNUM_SIZE                                       8
#define AVR32_FREQM_REFSEL                                            0
#define AVR32_FREQM_REFSEL_MASK                              0x00000001
#define AVR32_FREQM_REFSEL_OFFSET                                     0
#define AVR32_FREQM_REFSEL_REF_OSC32                         0x00000001
#define AVR32_FREQM_REFSEL_REF_RCOSC                         0x00000000
#define AVR32_FREQM_REFSEL_SIZE                                       1
#define AVR32_FREQM_REF_OSC32                                0x00000001
#define AVR32_FREQM_REF_RCOSC                                0x00000000
#define AVR32_FREQM_START                                             0
#define AVR32_FREQM_START_MASK                               0x00000001
#define AVR32_FREQM_START_OFFSET                                      0
#define AVR32_FREQM_START_SIZE                                        1
#define AVR32_FREQM_STATUS                                   0x00000008
#define AVR32_FREQM_STATUS_BUSY                                       0
#define AVR32_FREQM_STATUS_BUSY_MASK                         0x00000001
#define AVR32_FREQM_STATUS_BUSY_OFFSET                                0
#define AVR32_FREQM_STATUS_BUSY_SIZE                                  1
#define AVR32_FREQM_VALUE                                    0x0000000c
#define AVR32_FREQM_VALUE_MASK                               0x00ffffff
#define AVR32_FREQM_VALUE_OFFSET                                      0
#define AVR32_FREQM_VALUE_SIZE                                       24
#define AVR32_FREQM_VALUE_VALUE                                       0
#define AVR32_FREQM_VALUE_VALUE_MASK                         0x00ffffff
#define AVR32_FREQM_VALUE_VALUE_OFFSET                                0
#define AVR32_FREQM_VALUE_VALUE_SIZE                                 24




#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_freqm_ctrl_t {
    unsigned int                 :31;
    unsigned int start           : 1;
} avr32_freqm_ctrl_t;



typedef struct avr32_freqm_mode_t {
    unsigned int                 :11;
    unsigned int clksel          : 5;
    unsigned int refnum          : 8;
    unsigned int                 : 7;
    unsigned int refsel          : 1;
} avr32_freqm_mode_t;



typedef struct avr32_freqm_status_t {
    unsigned int                 :31;
    unsigned int busy            : 1;
} avr32_freqm_status_t;



typedef struct avr32_freqm_value_t {
    unsigned int                 : 8;
    unsigned int value           :24;
} avr32_freqm_value_t;



typedef struct avr32_freqm_ier_t {
    unsigned int                 :31;
    unsigned int done            : 1;
} avr32_freqm_ier_t;



typedef struct avr32_freqm_idr_t {
    unsigned int                 :31;
    unsigned int done            : 1;
} avr32_freqm_idr_t;



typedef struct avr32_freqm_imr_t {
    unsigned int                 :31;
    unsigned int done            : 1;
} avr32_freqm_imr_t;



typedef struct avr32_freqm_isr_t {
    unsigned int                 :31;
    unsigned int done            : 1;
} avr32_freqm_isr_t;



typedef struct avr32_freqm_icr_t {
    unsigned int                 :31;
    unsigned int done            : 1;
} avr32_freqm_icr_t;



typedef struct avr32_freqm_t {
  union {
          unsigned long                  ctrl      ;//0x0000
          avr32_freqm_ctrl_t             CTRL      ;
  };
  union {
          unsigned long                  mode      ;//0x0004
          avr32_freqm_mode_t             MODE      ;
  };
  union {
    const unsigned long                  status    ;//0x0008
    const avr32_freqm_status_t           STATUS    ;
  };
  union {
          unsigned long                  value     ;//0x000c
          avr32_freqm_value_t            VALUE     ;
  };
  union {
          unsigned long                  ier       ;//0x0010
          avr32_freqm_ier_t              IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0014
          avr32_freqm_idr_t              IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x0018
    const avr32_freqm_imr_t              IMR       ;
  };
  union {
    const unsigned long                  isr       ;//0x001c
    const avr32_freqm_isr_t              ISR       ;
  };
  union {
          unsigned long                  icr       ;//0x0020
          avr32_freqm_icr_t              ICR       ;
  };
} avr32_freqm_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif

/*#ifdef AVR32_FREQM_230_H_INCLUDED*/
#endif

