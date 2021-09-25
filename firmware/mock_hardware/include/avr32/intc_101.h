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
 * Model        : AP7200
 * Revision     : $Revision: 74772 $
 * Checkin Date : $Date: 2010-05-14 06:51:12 +0200 (Fri, 14 May 2010) $ 
 *
 ****************************************************************************/
#ifndef AVR32_INTC_101_H_INCLUDED
#define AVR32_INTC_101_H_INCLUDED

#define AVR32_INTC_H_VERSION 101

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_INTC_<register>
 - Bitfield mask:   AVR32_INTC_<register>_<bitfield>
 - Bitfield offset: AVR32_INTC_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_INTC_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_INTC_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_INTC_<bitfield>
 - Bitfield offset: AVR32_INTC_<bitfield>_OFFSET
 - Bitfield size:   AVR32_INTC_<bitfield>_SIZE
 - Bitfield values: AVR32_INTC_<bitfield>_<value name>
 - Bitfield values: AVR32_INTC_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_INTC_AUTOVECTOR                                        0
#define AVR32_INTC_AUTOVECTOR_MASK                          0x00003fff
#define AVR32_INTC_AUTOVECTOR_OFFSET                                 0
#define AVR32_INTC_AUTOVECTOR_SIZE                                  14
#define AVR32_INTC_CAUSE                                             0
#define AVR32_INTC_CAUSE_MASK                               0x0000003f
#define AVR32_INTC_CAUSE_OFFSET                                      0
#define AVR32_INTC_CAUSE_SIZE                                        6
#define AVR32_INTC_ICR                                      0x00000200
#define AVR32_INTC_ICR_CAUSE                                         0
#define AVR32_INTC_ICR_CAUSE_MASK                           0x0000003f
#define AVR32_INTC_ICR_CAUSE_OFFSET                                  0
#define AVR32_INTC_ICR_CAUSE_SIZE                                    6
#define AVR32_INTC_INT0                                     0x00000000
#define AVR32_INTC_INT1                                     0x00000001
#define AVR32_INTC_INT2                                     0x00000002
#define AVR32_INTC_INT3                                     0x00000003
#define AVR32_INTC_INTLEVEL                                         30
#define AVR32_INTC_INTLEVEL_INT0                            0x00000000
#define AVR32_INTC_INTLEVEL_INT1                            0x00000001
#define AVR32_INTC_INTLEVEL_INT2                            0x00000002
#define AVR32_INTC_INTLEVEL_INT3                            0x00000003
#define AVR32_INTC_INTLEVEL_MASK                            0xc0000000
#define AVR32_INTC_INTLEVEL_OFFSET                                  30
#define AVR32_INTC_INTLEVEL_SIZE                                     2
#define AVR32_INTC_IPR                                      0x00000000
#define AVR32_INTC_IPR_AUTOVECTOR                                    0
#define AVR32_INTC_IPR_AUTOVECTOR_MASK                      0x00003fff
#define AVR32_INTC_IPR_AUTOVECTOR_OFFSET                             0
#define AVR32_INTC_IPR_AUTOVECTOR_SIZE                              14
#define AVR32_INTC_IPR_INTLEVEL                                     30
#define AVR32_INTC_IPR_INTLEVEL_INT0                        0x00000000
#define AVR32_INTC_IPR_INTLEVEL_INT1                        0x00000001
#define AVR32_INTC_IPR_INTLEVEL_INT2                        0x00000002
#define AVR32_INTC_IPR_INTLEVEL_INT3                        0x00000003
#define AVR32_INTC_IPR_INTLEVEL_MASK                        0xc0000000
#define AVR32_INTC_IPR_INTLEVEL_OFFSET                              30
#define AVR32_INTC_IPR_INTLEVEL_SIZE                                 2
#define AVR32_INTC_IRR                                      0x00000100




#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_intc_ipr_t {
    unsigned int intlevel        : 2;
    unsigned int                 :16;
    unsigned int autovector      :14;
} avr32_intc_ipr_t;



typedef struct avr32_intc_icr_t {
    unsigned int                 :26;
    unsigned int cause           : 6;
} avr32_intc_icr_t;



typedef struct avr32_intc_t {
  union {
          unsigned long                  ipr       [AVR32_INTC_NUM_INT_GRPS];//0x0000
          avr32_intc_ipr_t               IPR       [AVR32_INTC_NUM_INT_GRPS];
  };
  union {
          unsigned long                  ipr_reserved[64 - AVR32_INTC_NUM_INT_GRPS];//Padding
          avr32_intc_ipr_t               IPR_RESERVED[64 - AVR32_INTC_NUM_INT_GRPS];
  };
    const unsigned long                  irr       [AVR32_INTC_NUM_INT_GRPS];//0x0100
    const unsigned long                  irr_reserved[64 - AVR32_INTC_NUM_INT_GRPS];//Padding
  union {
    const unsigned long                  icr       [4];//0x0200
    const avr32_intc_icr_t               ICR       [4];
  };
} avr32_intc_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif


#if !defined (DEPRECATED_DISABLE)

#define AVR32_INTC_ICR_CAUSEGRP                                    0
#define AVR32_INTC_ICR_CAUSEGRP_MASK                      0x0000003f
#define AVR32_INTC_ICR_CAUSEGRP_OFFSET                             0
#define AVR32_INTC_ICR_CAUSEGRP_SIZE                               6

#define AVR32_INTC_INTLEV                                         30
#define AVR32_INTC_INTLEV_INT0                            0x00000000
#define AVR32_INTC_INTLEV_INT1                            0x00000001
#define AVR32_INTC_INTLEV_INT2                            0x00000002
#define AVR32_INTC_INTLEV_INT3                            0x00000003
#define AVR32_INTC_INTLEV_MASK                            0xc0000000
#define AVR32_INTC_INTLEV_OFFSET                                  30
#define AVR32_INTC_INTLEV_SIZE                                     2

#define AVR32_INTC_IPR_INTLEV                                     30
#define AVR32_INTC_IPR_INTLEV_INT0                        0x00000000
#define AVR32_INTC_IPR_INTLEV_INT1                        0x00000001
#define AVR32_INTC_IPR_INTLEV_INT2                        0x00000002
#define AVR32_INTC_IPR_INTLEV_INT3                        0x00000003
#define AVR32_INTC_IPR_INTLEV_MASK                        0xc0000000
#define AVR32_INTC_IPR_INTLEV_OFFSET                              30
#define AVR32_INTC_IPR_INTLEV_SIZE                                 2
#define AVR32_INTC_IPR_OFFSET                                      0
#define AVR32_INTC_IPR_OFFSET_MASK                        0x00003fff
#define AVR32_INTC_IPR_OFFSET_OFFSET                               0
#define AVR32_INTC_IPR_OFFSET_SIZE                                14

#define AVR32_INTC_OFFSET                                          0
#define AVR32_INTC_OFFSET_MASK                            0x00003fff
#define AVR32_INTC_OFFSET_OFFSET                                   0
#define AVR32_INTC_OFFSET_SIZE                                    14

#endif


/*#ifdef AVR32_INTC_101_H_INCLUDED*/
#endif

