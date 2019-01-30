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
 * Model        : UC3A3128
 * Revision     : $Revision: 74772 $
 * Checkin Date : $Date: 2010-05-14 06:51:12 +0200 (Fri, 14 May 2010) $ 
 *
 ****************************************************************************/
#ifndef AVR32_GPIO_110_H_INCLUDED
#define AVR32_GPIO_110_H_INCLUDED

#define AVR32_GPIO_H_VERSION 110

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_GPIO_<register>
 - Bitfield mask:   AVR32_GPIO_<register>_<bitfield>
 - Bitfield offset: AVR32_GPIO_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_GPIO_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_GPIO_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_GPIO_<bitfield>
 - Bitfield offset: AVR32_GPIO_<bitfield>_OFFSET
 - Bitfield size:   AVR32_GPIO_<bitfield>_SIZE
 - Bitfield values: AVR32_GPIO_<bitfield>_<value name>
 - Bitfield values: AVR32_GPIO_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_GPIO_GFER                                     0x000000c0
#define AVR32_GPIO_GFERC                                    0x000000c8
#define AVR32_GPIO_GFERS                                    0x000000c4
#define AVR32_GPIO_GFERT                                    0x000000cc
#define AVR32_GPIO_GPER                                     0x00000000
#define AVR32_GPIO_GPERC                                    0x00000008
#define AVR32_GPIO_GPERS                                    0x00000004
#define AVR32_GPIO_GPERT                                    0x0000000c
#define AVR32_GPIO_IER                                      0x00000090
#define AVR32_GPIO_IERC                                     0x00000098
#define AVR32_GPIO_IERS                                     0x00000094
#define AVR32_GPIO_IERT                                     0x0000009c
#define AVR32_GPIO_IFR                                      0x000000d0
#define AVR32_GPIO_IFRC                                     0x000000d8
#define AVR32_GPIO_IMR0                                     0x000000a0
#define AVR32_GPIO_IMR0C                                    0x000000a8
#define AVR32_GPIO_IMR0S                                    0x000000a4
#define AVR32_GPIO_IMR0T                                    0x000000ac
#define AVR32_GPIO_IMR1                                     0x000000b0
#define AVR32_GPIO_IMR1C                                    0x000000b8
#define AVR32_GPIO_IMR1S                                    0x000000b4
#define AVR32_GPIO_IMR1T                                    0x000000bc
#define AVR32_GPIO_LOCAL_ODER                               0x00000040
#define AVR32_GPIO_LOCAL_ODERC                              0x00000048
#define AVR32_GPIO_LOCAL_ODERS                              0x00000044
#define AVR32_GPIO_LOCAL_ODERT                              0x0000004c
#define AVR32_GPIO_LOCAL_OVR                                0x00000050
#define AVR32_GPIO_LOCAL_OVRC                               0x00000058
#define AVR32_GPIO_LOCAL_OVRS                               0x00000054
#define AVR32_GPIO_LOCAL_OVRT                               0x0000005c
#define AVR32_GPIO_LOCAL_PVR                                0x00000060
#define AVR32_GPIO_ODER                                     0x00000040
#define AVR32_GPIO_ODERC                                    0x00000048
#define AVR32_GPIO_ODERS                                    0x00000044
#define AVR32_GPIO_ODERT                                    0x0000004c
#define AVR32_GPIO_ODMER                                    0x00000080
#define AVR32_GPIO_ODMERC                                   0x00000088
#define AVR32_GPIO_ODMERS                                   0x00000084
#define AVR32_GPIO_ODMERT                                   0x0000008c
#define AVR32_GPIO_OVR                                      0x00000050
#define AVR32_GPIO_OVRC                                     0x00000058
#define AVR32_GPIO_OVRS                                     0x00000054
#define AVR32_GPIO_OVRT                                     0x0000005c
#define AVR32_GPIO_PMR0                                     0x00000010
#define AVR32_GPIO_PMR0C                                    0x00000018
#define AVR32_GPIO_PMR0S                                    0x00000014
#define AVR32_GPIO_PMR0T                                    0x0000001c
#define AVR32_GPIO_PMR1                                     0x00000020
#define AVR32_GPIO_PMR1C                                    0x00000028
#define AVR32_GPIO_PMR1S                                    0x00000024
#define AVR32_GPIO_PMR1T                                    0x0000002c
#define AVR32_GPIO_PUER                                     0x00000070
#define AVR32_GPIO_PUERC                                    0x00000078
#define AVR32_GPIO_PUERS                                    0x00000074
#define AVR32_GPIO_PUERT                                    0x0000007c
#define AVR32_GPIO_PVR                                      0x00000060




#ifdef __AVR32_ABI_COMPILER__

typedef struct avr32_gpio_local_port_t {
          unsigned int                   :32       ;//0x0000
          unsigned int                   :32       ;//0x0004
          unsigned int                   :32       ;//0x0008
          unsigned int                   :32       ;//0x000c
          unsigned int                   :32       ;//0x0010
          unsigned int                   :32       ;//0x0014
          unsigned int                   :32       ;//0x0018
          unsigned int                   :32       ;//0x001c
          unsigned int                   :32       ;//0x0020
          unsigned int                   :32       ;//0x0024
          unsigned int                   :32       ;//0x0028
          unsigned int                   :32       ;//0x002c
          unsigned int                   :32       ;//0x0030
          unsigned int                   :32       ;//0x0034
          unsigned int                   :32       ;//0x0038
          unsigned int                   :32       ;//0x003c
          unsigned long                  oder      ;//0x0040
          unsigned long                  oders     ;//0x0044
          unsigned long                  oderc     ;//0x0048
          unsigned long                  odert     ;//0x004c
          unsigned long                  ovr       ;//0x0050
          unsigned long                  ovrs      ;//0x0054
          unsigned long                  ovrc      ;//0x0058
          unsigned long                  ovrt      ;//0x005c
    const unsigned long                  pvr       ;//0x0060
          unsigned int                   :32       ;//0x0064
          unsigned int                   :32       ;//0x0068
          unsigned int                   :32       ;//0x006c
          unsigned int                   :32       ;//0x0070
          unsigned int                   :32       ;//0x0074
          unsigned int                   :32       ;//0x0078
          unsigned int                   :32       ;//0x007c
          unsigned int                   :32       ;//0x0080
          unsigned int                   :32       ;//0x0084
          unsigned int                   :32       ;//0x0088
          unsigned int                   :32       ;//0x008c
          unsigned int                   :32       ;//0x0090
          unsigned int                   :32       ;//0x0094
          unsigned int                   :32       ;//0x0098
          unsigned int                   :32       ;//0x009c
          unsigned int                   :32       ;//0x00a0
          unsigned int                   :32       ;//0x00a4
          unsigned int                   :32       ;//0x00a8
          unsigned int                   :32       ;//0x00ac
          unsigned int                   :32       ;//0x00b0
          unsigned int                   :32       ;//0x00b4
          unsigned int                   :32       ;//0x00b8
          unsigned int                   :32       ;//0x00bc
          unsigned int                   :32       ;//0x00c0
          unsigned int                   :32       ;//0x00c4
          unsigned int                   :32       ;//0x00c8
          unsigned int                   :32       ;//0x00cc
          unsigned int                   :32       ;//0x00d0
          unsigned int                   :32       ;//0x00d4
          unsigned int                   :32       ;//0x00d8
          unsigned int                   :32       ;//0x00dc
          unsigned int                   :32       ;//0x00e0
          unsigned int                   :32       ;//0x00e4
          unsigned int                   :32       ;//0x00e8
          unsigned int                   :32       ;//0x00ec
          unsigned int                   :32       ;//0x00f0
          unsigned int                   :32       ;//0x00f4
          unsigned int                   :32       ;//0x00f8
          unsigned int                   :32       ;//0x00fc
} avr32_gpio_local_port_t;


typedef struct avr32_gpio_local_t {
  avr32_gpio_local_port_t port[AVR32_GPIO_PORT_LENGTH];//0x0
} avr32_gpio_local_t;



typedef struct avr32_gpio_port_t {
          unsigned long                  gper      ;//0x0000
          unsigned long                  gpers     ;//0x0004
          unsigned long                  gperc     ;//0x0008
          unsigned long                  gpert     ;//0x000c
          unsigned long                  pmr0      ;//0x0010
          unsigned long                  pmr0s     ;//0x0014
          unsigned long                  pmr0c     ;//0x0018
          unsigned long                  pmr0t     ;//0x001c
          unsigned long                  pmr1      ;//0x0020
          unsigned long                  pmr1s     ;//0x0024
          unsigned long                  pmr1c     ;//0x0028
          unsigned long                  pmr1t     ;//0x002c
          unsigned int                   :32       ;//0x0030
          unsigned int                   :32       ;//0x0034
          unsigned int                   :32       ;//0x0038
          unsigned int                   :32       ;//0x003c
          unsigned long                  oder      ;//0x0040
          unsigned long                  oders     ;//0x0044
          unsigned long                  oderc     ;//0x0048
          unsigned long                  odert     ;//0x004c
          unsigned long                  ovr       ;//0x0050
          unsigned long                  ovrs      ;//0x0054
          unsigned long                  ovrc      ;//0x0058
          unsigned long                  ovrt      ;//0x005c
    const unsigned long                  pvr       ;//0x0060
          unsigned int                   :32       ;//0x0064
          unsigned int                   :32       ;//0x0068
          unsigned int                   :32       ;//0x006c
          unsigned long                  puer      ;//0x0070
          unsigned long                  puers     ;//0x0074
          unsigned long                  puerc     ;//0x0078
          unsigned long                  puert     ;//0x007c
          unsigned long                  odmer     ;//0x0080
          unsigned long                  odmers    ;//0x0084
          unsigned long                  odmerc    ;//0x0088
          unsigned long                  odmert    ;//0x008c
          unsigned long                  ier       ;//0x0090
          unsigned long                  iers      ;//0x0094
          unsigned long                  ierc      ;//0x0098
          unsigned long                  iert      ;//0x009c
          unsigned long                  imr0      ;//0x00a0
          unsigned long                  imr0s     ;//0x00a4
          unsigned long                  imr0c     ;//0x00a8
          unsigned long                  imr0t     ;//0x00ac
          unsigned long                  imr1      ;//0x00b0
          unsigned long                  imr1s     ;//0x00b4
          unsigned long                  imr1c     ;//0x00b8
          unsigned long                  imr1t     ;//0x00bc
          unsigned long                  gfer      ;//0x00c0
          unsigned long                  gfers     ;//0x00c4
          unsigned long                  gferc     ;//0x00c8
          unsigned long                  gfert     ;//0x00cc
    const unsigned long                  ifr       ;//0x00d0
          unsigned int                   :32       ;//0x00d4
          unsigned long                  ifrc      ;//0x00d8
          unsigned int                   :32       ;//0x00dc
          unsigned int                   :32       ;//0x00e0
          unsigned int                   :32       ;//0x00e4
          unsigned int                   :32       ;//0x00e8
          unsigned int                   :32       ;//0x00ec
          unsigned int                   :32       ;//0x00f0
          unsigned int                   :32       ;//0x00f4
          unsigned int                   :32       ;//0x00f8
          unsigned int                   :32       ;//0x00fc
} avr32_gpio_port_t;


typedef struct avr32_gpio_t {
  avr32_gpio_port_t port[AVR32_GPIO_PORT_LENGTH];//0x0
} avr32_gpio_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif

/*#ifdef AVR32_GPIO_110_H_INCLUDED*/
#endif

