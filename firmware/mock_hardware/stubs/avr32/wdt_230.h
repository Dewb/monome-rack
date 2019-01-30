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
#ifndef AVR32_WDT_230_H_INCLUDED
#define AVR32_WDT_230_H_INCLUDED

#define AVR32_WDT_H_VERSION 230

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_WDT_<register>
 - Bitfield mask:   AVR32_WDT_<register>_<bitfield>
 - Bitfield offset: AVR32_WDT_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_WDT_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_WDT_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_WDT_<bitfield>
 - Bitfield offset: AVR32_WDT_<bitfield>_OFFSET
 - Bitfield size:   AVR32_WDT_<bitfield>_SIZE
 - Bitfield values: AVR32_WDT_<bitfield>_<value name>
 - Bitfield values: AVR32_WDT_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_WDT_CLR                                      0x00000004
#define AVR32_WDT_CTRL                                     0x00000000
#define AVR32_WDT_CTRL_EN                                           0
#define AVR32_WDT_CTRL_EN_MASK                             0x00000001
#define AVR32_WDT_CTRL_EN_OFFSET                                    0
#define AVR32_WDT_CTRL_EN_SIZE                                      1
#define AVR32_WDT_CTRL_KEY                                         24
#define AVR32_WDT_CTRL_KEY_MASK                            0xff000000
#define AVR32_WDT_CTRL_KEY_OFFSET                                  24
#define AVR32_WDT_CTRL_KEY_SIZE                                     8
#define AVR32_WDT_CTRL_PSEL                                         8
#define AVR32_WDT_CTRL_PSEL_MASK                           0x00001f00
#define AVR32_WDT_CTRL_PSEL_OFFSET                                  8
#define AVR32_WDT_CTRL_PSEL_SIZE                                    5
#define AVR32_WDT_EN                                                0
#define AVR32_WDT_EN_MASK                                  0x00000001
#define AVR32_WDT_EN_OFFSET                                         0
#define AVR32_WDT_EN_SIZE                                           1
#define AVR32_WDT_KEY                                              24
#define AVR32_WDT_KEY_MASK                                 0xff000000
#define AVR32_WDT_KEY_OFFSET                                       24
#define AVR32_WDT_KEY_SIZE                                          8
#define AVR32_WDT_PSEL                                              8
#define AVR32_WDT_PSEL_MASK                                0x00001f00
#define AVR32_WDT_PSEL_OFFSET                                       8
#define AVR32_WDT_PSEL_SIZE                                         5

#define AVR32_WDT_KEY_VALUE                            0x00000055



#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_wdt_ctrl_t {
    unsigned int key             : 8;
    unsigned int                 :11;
    unsigned int psel            : 5;
    unsigned int                 : 7;
    unsigned int en              : 1;
} avr32_wdt_ctrl_t;



typedef struct avr32_wdt_t {
  union {
          unsigned long                  ctrl      ;//0x0000
          avr32_wdt_ctrl_t               CTRL      ;
  };
          unsigned long                  clr       ;//0x0004
} avr32_wdt_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif

/*#ifdef AVR32_WDT_230_H_INCLUDED*/
#endif

