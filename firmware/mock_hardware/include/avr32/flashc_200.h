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
 * Model        : UC3A0512
 * Revision     : $Revision: 74772 $
 * Checkin Date : $Date: 2010-05-14 06:51:12 +0200 (Fri, 14 May 2010) $ 
 *
 ****************************************************************************/
#ifndef AVR32_FLASHC_200_H_INCLUDED
#define AVR32_FLASHC_200_H_INCLUDED

#define AVR32_FLASHC_H_VERSION 200

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_FLASHC_<register>
 - Bitfield mask:   AVR32_FLASHC_<register>_<bitfield>
 - Bitfield offset: AVR32_FLASHC_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_FLASHC_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_FLASHC_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_FLASHC_<bitfield>
 - Bitfield offset: AVR32_FLASHC_<bitfield>_OFFSET
 - Bitfield size:   AVR32_FLASHC_<bitfield>_SIZE
 - Bitfield values: AVR32_FLASHC_<bitfield>_<value name>
 - Bitfield values: AVR32_FLASHC_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_FLASHC_1024                                     0x00000007
#define AVR32_FLASHC_128                                      0x00000002
#define AVR32_FLASHC_256                                      0x00000003
#define AVR32_FLASHC_32                                       0x00000000
#define AVR32_FLASHC_384                                      0x00000004
#define AVR32_FLASHC_512                                      0x00000005
#define AVR32_FLASHC_64                                       0x00000001
#define AVR32_FLASHC_768                                      0x00000006
#define AVR32_FLASHC_BOOTPROT                                         17
#define AVR32_FLASHC_BOOTPROT_MASK                            0x000e0000
#define AVR32_FLASHC_BOOTPROT_OFFSET                                  17
#define AVR32_FLASHC_BOOTPROT_SIZE                                     3
#define AVR32_FLASHC_CMD                                               0
#define AVR32_FLASHC_CMD_CPB                                  0x00000003
#define AVR32_FLASHC_CMD_EA                                   0x00000006
#define AVR32_FLASHC_CMD_EAGPF                                0x0000000b
#define AVR32_FLASHC_CMD_EGPB                                 0x00000008
#define AVR32_FLASHC_CMD_EP                                   0x00000002
#define AVR32_FLASHC_CMD_EUP                                  0x0000000e
#define AVR32_FLASHC_CMD_LP                                   0x00000004
#define AVR32_FLASHC_CMD_MASK                                 0x0000003f
#define AVR32_FLASHC_CMD_NOP                                  0x00000000
#define AVR32_FLASHC_CMD_OFFSET                                        0
#define AVR32_FLASHC_CMD_PGPFB                                0x0000000a
#define AVR32_FLASHC_CMD_QPR                                  0x0000000c
#define AVR32_FLASHC_CMD_QPRUP                                0x0000000f
#define AVR32_FLASHC_CMD_SIZE                                          6
#define AVR32_FLASHC_CMD_SSB                                  0x00000009
#define AVR32_FLASHC_CMD_UP                                   0x00000005
#define AVR32_FLASHC_CMD_WGPB                                 0x00000007
#define AVR32_FLASHC_CMD_WP                                   0x00000001
#define AVR32_FLASHC_CMD_WUP                                  0x0000000d
#define AVR32_FLASHC_CPB                                      0x00000003
#define AVR32_FLASHC_EA                                       0x00000006
#define AVR32_FLASHC_EAGPF                                    0x0000000b
#define AVR32_FLASHC_EGPB                                     0x00000008
#define AVR32_FLASHC_EP                                       0x00000002
#define AVR32_FLASHC_EPFL                                             16
#define AVR32_FLASHC_EPFL_MASK                                0x00010000
#define AVR32_FLASHC_EPFL_OFFSET                                      16
#define AVR32_FLASHC_EPFL_SIZE                                         1
#define AVR32_FLASHC_EUP                                      0x0000000e
#define AVR32_FLASHC_FCMD                                     0x00000004
#define AVR32_FLASHC_FCMD_CMD                                          0
#define AVR32_FLASHC_FCMD_CMD_CPB                             0x00000003
#define AVR32_FLASHC_FCMD_CMD_EA                              0x00000006
#define AVR32_FLASHC_FCMD_CMD_EAGPF                           0x0000000b
#define AVR32_FLASHC_FCMD_CMD_EGPB                            0x00000008
#define AVR32_FLASHC_FCMD_CMD_EP                              0x00000002
#define AVR32_FLASHC_FCMD_CMD_EUP                             0x0000000e
#define AVR32_FLASHC_FCMD_CMD_LP                              0x00000004
#define AVR32_FLASHC_FCMD_CMD_MASK                            0x0000003f
#define AVR32_FLASHC_FCMD_CMD_NOP                             0x00000000
#define AVR32_FLASHC_FCMD_CMD_OFFSET                                   0
#define AVR32_FLASHC_FCMD_CMD_PGPFB                           0x0000000a
#define AVR32_FLASHC_FCMD_CMD_QPR                             0x0000000c
#define AVR32_FLASHC_FCMD_CMD_QPRUP                           0x0000000f
#define AVR32_FLASHC_FCMD_CMD_SIZE                                     6
#define AVR32_FLASHC_FCMD_CMD_SSB                             0x00000009
#define AVR32_FLASHC_FCMD_CMD_UP                              0x00000005
#define AVR32_FLASHC_FCMD_CMD_WGPB                            0x00000007
#define AVR32_FLASHC_FCMD_CMD_WP                              0x00000001
#define AVR32_FLASHC_FCMD_CMD_WUP                             0x0000000d
#define AVR32_FLASHC_FCMD_KEY                                         24
#define AVR32_FLASHC_FCMD_KEY_KEY                             0x000000a5
#define AVR32_FLASHC_FCMD_KEY_MASK                            0xff000000
#define AVR32_FLASHC_FCMD_KEY_OFFSET                                  24
#define AVR32_FLASHC_FCMD_KEY_SIZE                                     8
#define AVR32_FLASHC_FCMD_PAGEN                                        8
#define AVR32_FLASHC_FCMD_PAGEN_MASK                          0x00ffff00
#define AVR32_FLASHC_FCMD_PAGEN_OFFSET                                 8
#define AVR32_FLASHC_FCMD_PAGEN_SIZE                                  16
#define AVR32_FLASHC_FCR                                      0x00000000
#define AVR32_FLASHC_FCR_FRDY                                          0
#define AVR32_FLASHC_FCR_FRDY_MASK                            0x00000001
#define AVR32_FLASHC_FCR_FRDY_OFFSET                                   0
#define AVR32_FLASHC_FCR_FRDY_SIZE                                     1
#define AVR32_FLASHC_FCR_FWS                                           6
#define AVR32_FLASHC_FCR_FWS_MASK                             0x00000040
#define AVR32_FLASHC_FCR_FWS_OFFSET                                    6
#define AVR32_FLASHC_FCR_FWS_SIZE                                      1
#define AVR32_FLASHC_FCR_LOCKE                                         2
#define AVR32_FLASHC_FCR_LOCKE_MASK                           0x00000004
#define AVR32_FLASHC_FCR_LOCKE_OFFSET                                  2
#define AVR32_FLASHC_FCR_LOCKE_SIZE                                    1
#define AVR32_FLASHC_FCR_PROGE                                         3
#define AVR32_FLASHC_FCR_PROGE_MASK                           0x00000008
#define AVR32_FLASHC_FCR_PROGE_OFFSET                                  3
#define AVR32_FLASHC_FCR_PROGE_SIZE                                    1
#define AVR32_FLASHC_FGPFRHI                                  0x0000000c
#define AVR32_FLASHC_FGPFRHI_GPF32                                     0
#define AVR32_FLASHC_FGPFRHI_GPF32_MASK                       0x00000001
#define AVR32_FLASHC_FGPFRHI_GPF32_OFFSET                              0
#define AVR32_FLASHC_FGPFRHI_GPF32_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF33                                     1
#define AVR32_FLASHC_FGPFRHI_GPF33_MASK                       0x00000002
#define AVR32_FLASHC_FGPFRHI_GPF33_OFFSET                              1
#define AVR32_FLASHC_FGPFRHI_GPF33_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF34                                     2
#define AVR32_FLASHC_FGPFRHI_GPF34_MASK                       0x00000004
#define AVR32_FLASHC_FGPFRHI_GPF34_OFFSET                              2
#define AVR32_FLASHC_FGPFRHI_GPF34_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF35                                     3
#define AVR32_FLASHC_FGPFRHI_GPF35_MASK                       0x00000008
#define AVR32_FLASHC_FGPFRHI_GPF35_OFFSET                              3
#define AVR32_FLASHC_FGPFRHI_GPF35_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF36                                     4
#define AVR32_FLASHC_FGPFRHI_GPF36_MASK                       0x00000010
#define AVR32_FLASHC_FGPFRHI_GPF36_OFFSET                              4
#define AVR32_FLASHC_FGPFRHI_GPF36_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF37                                     5
#define AVR32_FLASHC_FGPFRHI_GPF37_MASK                       0x00000020
#define AVR32_FLASHC_FGPFRHI_GPF37_OFFSET                              5
#define AVR32_FLASHC_FGPFRHI_GPF37_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF38                                     6
#define AVR32_FLASHC_FGPFRHI_GPF38_MASK                       0x00000040
#define AVR32_FLASHC_FGPFRHI_GPF38_OFFSET                              6
#define AVR32_FLASHC_FGPFRHI_GPF38_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF39                                     7
#define AVR32_FLASHC_FGPFRHI_GPF39_MASK                       0x00000080
#define AVR32_FLASHC_FGPFRHI_GPF39_OFFSET                              7
#define AVR32_FLASHC_FGPFRHI_GPF39_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF40                                     8
#define AVR32_FLASHC_FGPFRHI_GPF40_MASK                       0x00000100
#define AVR32_FLASHC_FGPFRHI_GPF40_OFFSET                              8
#define AVR32_FLASHC_FGPFRHI_GPF40_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF41                                     9
#define AVR32_FLASHC_FGPFRHI_GPF41_MASK                       0x00000200
#define AVR32_FLASHC_FGPFRHI_GPF41_OFFSET                              9
#define AVR32_FLASHC_FGPFRHI_GPF41_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF42                                    10
#define AVR32_FLASHC_FGPFRHI_GPF42_MASK                       0x00000400
#define AVR32_FLASHC_FGPFRHI_GPF42_OFFSET                             10
#define AVR32_FLASHC_FGPFRHI_GPF42_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF43                                    11
#define AVR32_FLASHC_FGPFRHI_GPF43_MASK                       0x00000800
#define AVR32_FLASHC_FGPFRHI_GPF43_OFFSET                             11
#define AVR32_FLASHC_FGPFRHI_GPF43_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF44                                    12
#define AVR32_FLASHC_FGPFRHI_GPF44_MASK                       0x00001000
#define AVR32_FLASHC_FGPFRHI_GPF44_OFFSET                             12
#define AVR32_FLASHC_FGPFRHI_GPF44_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF45                                    13
#define AVR32_FLASHC_FGPFRHI_GPF45_MASK                       0x00002000
#define AVR32_FLASHC_FGPFRHI_GPF45_OFFSET                             13
#define AVR32_FLASHC_FGPFRHI_GPF45_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF46                                    14
#define AVR32_FLASHC_FGPFRHI_GPF46_MASK                       0x00004000
#define AVR32_FLASHC_FGPFRHI_GPF46_OFFSET                             14
#define AVR32_FLASHC_FGPFRHI_GPF46_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF47                                    15
#define AVR32_FLASHC_FGPFRHI_GPF47_MASK                       0x00008000
#define AVR32_FLASHC_FGPFRHI_GPF47_OFFSET                             15
#define AVR32_FLASHC_FGPFRHI_GPF47_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF48                                    16
#define AVR32_FLASHC_FGPFRHI_GPF48_MASK                       0x00010000
#define AVR32_FLASHC_FGPFRHI_GPF48_OFFSET                             16
#define AVR32_FLASHC_FGPFRHI_GPF48_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF49                                    17
#define AVR32_FLASHC_FGPFRHI_GPF49_MASK                       0x00020000
#define AVR32_FLASHC_FGPFRHI_GPF49_OFFSET                             17
#define AVR32_FLASHC_FGPFRHI_GPF49_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF50                                    18
#define AVR32_FLASHC_FGPFRHI_GPF50_MASK                       0x00040000
#define AVR32_FLASHC_FGPFRHI_GPF50_OFFSET                             18
#define AVR32_FLASHC_FGPFRHI_GPF50_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF51                                    19
#define AVR32_FLASHC_FGPFRHI_GPF51_MASK                       0x00080000
#define AVR32_FLASHC_FGPFRHI_GPF51_OFFSET                             19
#define AVR32_FLASHC_FGPFRHI_GPF51_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF52                                    20
#define AVR32_FLASHC_FGPFRHI_GPF52_MASK                       0x00100000
#define AVR32_FLASHC_FGPFRHI_GPF52_OFFSET                             20
#define AVR32_FLASHC_FGPFRHI_GPF52_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF53                                    21
#define AVR32_FLASHC_FGPFRHI_GPF53_MASK                       0x00200000
#define AVR32_FLASHC_FGPFRHI_GPF53_OFFSET                             21
#define AVR32_FLASHC_FGPFRHI_GPF53_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF54                                    22
#define AVR32_FLASHC_FGPFRHI_GPF54_MASK                       0x00400000
#define AVR32_FLASHC_FGPFRHI_GPF54_OFFSET                             22
#define AVR32_FLASHC_FGPFRHI_GPF54_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF55                                    23
#define AVR32_FLASHC_FGPFRHI_GPF55_MASK                       0x00800000
#define AVR32_FLASHC_FGPFRHI_GPF55_OFFSET                             23
#define AVR32_FLASHC_FGPFRHI_GPF55_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF56                                    24
#define AVR32_FLASHC_FGPFRHI_GPF56_MASK                       0x01000000
#define AVR32_FLASHC_FGPFRHI_GPF56_OFFSET                             24
#define AVR32_FLASHC_FGPFRHI_GPF56_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF57                                    25
#define AVR32_FLASHC_FGPFRHI_GPF57_MASK                       0x02000000
#define AVR32_FLASHC_FGPFRHI_GPF57_OFFSET                             25
#define AVR32_FLASHC_FGPFRHI_GPF57_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF58                                    26
#define AVR32_FLASHC_FGPFRHI_GPF58_MASK                       0x04000000
#define AVR32_FLASHC_FGPFRHI_GPF58_OFFSET                             26
#define AVR32_FLASHC_FGPFRHI_GPF58_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF59                                    27
#define AVR32_FLASHC_FGPFRHI_GPF59_MASK                       0x08000000
#define AVR32_FLASHC_FGPFRHI_GPF59_OFFSET                             27
#define AVR32_FLASHC_FGPFRHI_GPF59_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF60                                    28
#define AVR32_FLASHC_FGPFRHI_GPF60_MASK                       0x10000000
#define AVR32_FLASHC_FGPFRHI_GPF60_OFFSET                             28
#define AVR32_FLASHC_FGPFRHI_GPF60_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF61                                    29
#define AVR32_FLASHC_FGPFRHI_GPF61_MASK                       0x20000000
#define AVR32_FLASHC_FGPFRHI_GPF61_OFFSET                             29
#define AVR32_FLASHC_FGPFRHI_GPF61_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF62                                    30
#define AVR32_FLASHC_FGPFRHI_GPF62_MASK                       0x40000000
#define AVR32_FLASHC_FGPFRHI_GPF62_OFFSET                             30
#define AVR32_FLASHC_FGPFRHI_GPF62_SIZE                                1
#define AVR32_FLASHC_FGPFRHI_GPF63                                    31
#define AVR32_FLASHC_FGPFRHI_GPF63_MASK                       0x80000000
#define AVR32_FLASHC_FGPFRHI_GPF63_OFFSET                             31
#define AVR32_FLASHC_FGPFRHI_GPF63_SIZE                                1
#define AVR32_FLASHC_FGPFRLO                                  0x00000010
#define AVR32_FLASHC_FGPFRLO_BOOTPROT                                 17
#define AVR32_FLASHC_FGPFRLO_BOOTPROT_MASK                    0x000e0000
#define AVR32_FLASHC_FGPFRLO_BOOTPROT_OFFSET                          17
#define AVR32_FLASHC_FGPFRLO_BOOTPROT_SIZE                             3
#define AVR32_FLASHC_FGPFRLO_EPFL                                     16
#define AVR32_FLASHC_FGPFRLO_EPFL_MASK                        0x00010000
#define AVR32_FLASHC_FGPFRLO_EPFL_OFFSET                              16
#define AVR32_FLASHC_FGPFRLO_EPFL_SIZE                                 1
#define AVR32_FLASHC_FGPFRLO_GPF20                                    20
#define AVR32_FLASHC_FGPFRLO_GPF20_MASK                       0x00100000
#define AVR32_FLASHC_FGPFRLO_GPF20_OFFSET                             20
#define AVR32_FLASHC_FGPFRLO_GPF20_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_GPF21                                    21
#define AVR32_FLASHC_FGPFRLO_GPF21_MASK                       0x00200000
#define AVR32_FLASHC_FGPFRLO_GPF21_OFFSET                             21
#define AVR32_FLASHC_FGPFRLO_GPF21_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_GPF22                                    22
#define AVR32_FLASHC_FGPFRLO_GPF22_MASK                       0x00400000
#define AVR32_FLASHC_FGPFRLO_GPF22_OFFSET                             22
#define AVR32_FLASHC_FGPFRLO_GPF22_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_GPF23                                    23
#define AVR32_FLASHC_FGPFRLO_GPF23_MASK                       0x00800000
#define AVR32_FLASHC_FGPFRLO_GPF23_OFFSET                             23
#define AVR32_FLASHC_FGPFRLO_GPF23_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_GPF24                                    24
#define AVR32_FLASHC_FGPFRLO_GPF24_MASK                       0x01000000
#define AVR32_FLASHC_FGPFRLO_GPF24_OFFSET                             24
#define AVR32_FLASHC_FGPFRLO_GPF24_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_GPF25                                    25
#define AVR32_FLASHC_FGPFRLO_GPF25_MASK                       0x02000000
#define AVR32_FLASHC_FGPFRLO_GPF25_OFFSET                             25
#define AVR32_FLASHC_FGPFRLO_GPF25_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_GPF26                                    26
#define AVR32_FLASHC_FGPFRLO_GPF26_MASK                       0x04000000
#define AVR32_FLASHC_FGPFRLO_GPF26_OFFSET                             26
#define AVR32_FLASHC_FGPFRLO_GPF26_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_GPF27                                    27
#define AVR32_FLASHC_FGPFRLO_GPF27_MASK                       0x08000000
#define AVR32_FLASHC_FGPFRLO_GPF27_OFFSET                             27
#define AVR32_FLASHC_FGPFRLO_GPF27_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_GPF28                                    28
#define AVR32_FLASHC_FGPFRLO_GPF28_MASK                       0x10000000
#define AVR32_FLASHC_FGPFRLO_GPF28_OFFSET                             28
#define AVR32_FLASHC_FGPFRLO_GPF28_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_GPF29                                    29
#define AVR32_FLASHC_FGPFRLO_GPF29_MASK                       0x20000000
#define AVR32_FLASHC_FGPFRLO_GPF29_OFFSET                             29
#define AVR32_FLASHC_FGPFRLO_GPF29_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_GPF30                                    30
#define AVR32_FLASHC_FGPFRLO_GPF30_MASK                       0x40000000
#define AVR32_FLASHC_FGPFRLO_GPF30_OFFSET                             30
#define AVR32_FLASHC_FGPFRLO_GPF30_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_GPF31                                    31
#define AVR32_FLASHC_FGPFRLO_GPF31_MASK                       0x80000000
#define AVR32_FLASHC_FGPFRLO_GPF31_OFFSET                             31
#define AVR32_FLASHC_FGPFRLO_GPF31_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_LOCK0                                     0
#define AVR32_FLASHC_FGPFRLO_LOCK0_MASK                       0x00000001
#define AVR32_FLASHC_FGPFRLO_LOCK0_OFFSET                              0
#define AVR32_FLASHC_FGPFRLO_LOCK0_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_LOCK1                                     1
#define AVR32_FLASHC_FGPFRLO_LOCK10                                   10
#define AVR32_FLASHC_FGPFRLO_LOCK10_MASK                      0x00000400
#define AVR32_FLASHC_FGPFRLO_LOCK10_OFFSET                            10
#define AVR32_FLASHC_FGPFRLO_LOCK10_SIZE                               1
#define AVR32_FLASHC_FGPFRLO_LOCK11                                   11
#define AVR32_FLASHC_FGPFRLO_LOCK11_MASK                      0x00000800
#define AVR32_FLASHC_FGPFRLO_LOCK11_OFFSET                            11
#define AVR32_FLASHC_FGPFRLO_LOCK11_SIZE                               1
#define AVR32_FLASHC_FGPFRLO_LOCK12                                   12
#define AVR32_FLASHC_FGPFRLO_LOCK12_MASK                      0x00001000
#define AVR32_FLASHC_FGPFRLO_LOCK12_OFFSET                            12
#define AVR32_FLASHC_FGPFRLO_LOCK12_SIZE                               1
#define AVR32_FLASHC_FGPFRLO_LOCK13                                   13
#define AVR32_FLASHC_FGPFRLO_LOCK13_MASK                      0x00002000
#define AVR32_FLASHC_FGPFRLO_LOCK13_OFFSET                            13
#define AVR32_FLASHC_FGPFRLO_LOCK13_SIZE                               1
#define AVR32_FLASHC_FGPFRLO_LOCK14                                   14
#define AVR32_FLASHC_FGPFRLO_LOCK14_MASK                      0x00004000
#define AVR32_FLASHC_FGPFRLO_LOCK14_OFFSET                            14
#define AVR32_FLASHC_FGPFRLO_LOCK14_SIZE                               1
#define AVR32_FLASHC_FGPFRLO_LOCK15                                   15
#define AVR32_FLASHC_FGPFRLO_LOCK15_MASK                      0x00008000
#define AVR32_FLASHC_FGPFRLO_LOCK15_OFFSET                            15
#define AVR32_FLASHC_FGPFRLO_LOCK15_SIZE                               1
#define AVR32_FLASHC_FGPFRLO_LOCK1_MASK                       0x00000002
#define AVR32_FLASHC_FGPFRLO_LOCK1_OFFSET                              1
#define AVR32_FLASHC_FGPFRLO_LOCK1_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_LOCK2                                     2
#define AVR32_FLASHC_FGPFRLO_LOCK2_MASK                       0x00000004
#define AVR32_FLASHC_FGPFRLO_LOCK2_OFFSET                              2
#define AVR32_FLASHC_FGPFRLO_LOCK2_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_LOCK3                                     3
#define AVR32_FLASHC_FGPFRLO_LOCK3_MASK                       0x00000008
#define AVR32_FLASHC_FGPFRLO_LOCK3_OFFSET                              3
#define AVR32_FLASHC_FGPFRLO_LOCK3_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_LOCK4                                     4
#define AVR32_FLASHC_FGPFRLO_LOCK4_MASK                       0x00000010
#define AVR32_FLASHC_FGPFRLO_LOCK4_OFFSET                              4
#define AVR32_FLASHC_FGPFRLO_LOCK4_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_LOCK5                                     5
#define AVR32_FLASHC_FGPFRLO_LOCK5_MASK                       0x00000020
#define AVR32_FLASHC_FGPFRLO_LOCK5_OFFSET                              5
#define AVR32_FLASHC_FGPFRLO_LOCK5_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_LOCK6                                     6
#define AVR32_FLASHC_FGPFRLO_LOCK6_MASK                       0x00000040
#define AVR32_FLASHC_FGPFRLO_LOCK6_OFFSET                              6
#define AVR32_FLASHC_FGPFRLO_LOCK6_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_LOCK7                                     7
#define AVR32_FLASHC_FGPFRLO_LOCK7_MASK                       0x00000080
#define AVR32_FLASHC_FGPFRLO_LOCK7_OFFSET                              7
#define AVR32_FLASHC_FGPFRLO_LOCK7_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_LOCK8                                     8
#define AVR32_FLASHC_FGPFRLO_LOCK8_MASK                       0x00000100
#define AVR32_FLASHC_FGPFRLO_LOCK8_OFFSET                              8
#define AVR32_FLASHC_FGPFRLO_LOCK8_SIZE                                1
#define AVR32_FLASHC_FGPFRLO_LOCK9                                     9
#define AVR32_FLASHC_FGPFRLO_LOCK9_MASK                       0x00000200
#define AVR32_FLASHC_FGPFRLO_LOCK9_OFFSET                              9
#define AVR32_FLASHC_FGPFRLO_LOCK9_SIZE                                1
#define AVR32_FLASHC_FRDY                                              0
#define AVR32_FLASHC_FRDY_MASK                                0x00000001
#define AVR32_FLASHC_FRDY_OFFSET                                       0
#define AVR32_FLASHC_FRDY_SIZE                                         1
#define AVR32_FLASHC_FSR                                      0x00000008
#define AVR32_FLASHC_FSR_FRDY                                          0
#define AVR32_FLASHC_FSR_FRDY_MASK                            0x00000001
#define AVR32_FLASHC_FSR_FRDY_OFFSET                                   0
#define AVR32_FLASHC_FSR_FRDY_SIZE                                     1
#define AVR32_FLASHC_FSR_FSZ                                          13
#define AVR32_FLASHC_FSR_FSZ_1024                             0x00000007
#define AVR32_FLASHC_FSR_FSZ_128                              0x00000002
#define AVR32_FLASHC_FSR_FSZ_256                              0x00000003
#define AVR32_FLASHC_FSR_FSZ_32                               0x00000000
#define AVR32_FLASHC_FSR_FSZ_384                              0x00000004
#define AVR32_FLASHC_FSR_FSZ_512                              0x00000005
#define AVR32_FLASHC_FSR_FSZ_64                               0x00000001
#define AVR32_FLASHC_FSR_FSZ_768                              0x00000006
#define AVR32_FLASHC_FSR_FSZ_MASK                             0x0000e000
#define AVR32_FLASHC_FSR_FSZ_OFFSET                                   13
#define AVR32_FLASHC_FSR_FSZ_SIZE                                      3
#define AVR32_FLASHC_FSR_LOCK0                                        16
#define AVR32_FLASHC_FSR_LOCK0_MASK                           0x00010000
#define AVR32_FLASHC_FSR_LOCK0_OFFSET                                 16
#define AVR32_FLASHC_FSR_LOCK0_SIZE                                    1
#define AVR32_FLASHC_FSR_LOCK1                                        17
#define AVR32_FLASHC_FSR_LOCK10                                       26
#define AVR32_FLASHC_FSR_LOCK10_MASK                          0x04000000
#define AVR32_FLASHC_FSR_LOCK10_OFFSET                                26
#define AVR32_FLASHC_FSR_LOCK10_SIZE                                   1
#define AVR32_FLASHC_FSR_LOCK11                                       27
#define AVR32_FLASHC_FSR_LOCK11_MASK                          0x08000000
#define AVR32_FLASHC_FSR_LOCK11_OFFSET                                27
#define AVR32_FLASHC_FSR_LOCK11_SIZE                                   1
#define AVR32_FLASHC_FSR_LOCK12                                       28
#define AVR32_FLASHC_FSR_LOCK12_MASK                          0x10000000
#define AVR32_FLASHC_FSR_LOCK12_OFFSET                                28
#define AVR32_FLASHC_FSR_LOCK12_SIZE                                   1
#define AVR32_FLASHC_FSR_LOCK13                                       29
#define AVR32_FLASHC_FSR_LOCK13_MASK                          0x20000000
#define AVR32_FLASHC_FSR_LOCK13_OFFSET                                29
#define AVR32_FLASHC_FSR_LOCK13_SIZE                                   1
#define AVR32_FLASHC_FSR_LOCK14                                       30
#define AVR32_FLASHC_FSR_LOCK14_MASK                          0x40000000
#define AVR32_FLASHC_FSR_LOCK14_OFFSET                                30
#define AVR32_FLASHC_FSR_LOCK14_SIZE                                   1
#define AVR32_FLASHC_FSR_LOCK15                                       31
#define AVR32_FLASHC_FSR_LOCK15_MASK                          0x80000000
#define AVR32_FLASHC_FSR_LOCK15_OFFSET                                31
#define AVR32_FLASHC_FSR_LOCK15_SIZE                                   1
#define AVR32_FLASHC_FSR_LOCK1_MASK                           0x00020000
#define AVR32_FLASHC_FSR_LOCK1_OFFSET                                 17
#define AVR32_FLASHC_FSR_LOCK1_SIZE                                    1
#define AVR32_FLASHC_FSR_LOCK2                                        18
#define AVR32_FLASHC_FSR_LOCK2_MASK                           0x00040000
#define AVR32_FLASHC_FSR_LOCK2_OFFSET                                 18
#define AVR32_FLASHC_FSR_LOCK2_SIZE                                    1
#define AVR32_FLASHC_FSR_LOCK3                                        19
#define AVR32_FLASHC_FSR_LOCK3_MASK                           0x00080000
#define AVR32_FLASHC_FSR_LOCK3_OFFSET                                 19
#define AVR32_FLASHC_FSR_LOCK3_SIZE                                    1
#define AVR32_FLASHC_FSR_LOCK4                                        20
#define AVR32_FLASHC_FSR_LOCK4_MASK                           0x00100000
#define AVR32_FLASHC_FSR_LOCK4_OFFSET                                 20
#define AVR32_FLASHC_FSR_LOCK4_SIZE                                    1
#define AVR32_FLASHC_FSR_LOCK5                                        21
#define AVR32_FLASHC_FSR_LOCK5_MASK                           0x00200000
#define AVR32_FLASHC_FSR_LOCK5_OFFSET                                 21
#define AVR32_FLASHC_FSR_LOCK5_SIZE                                    1
#define AVR32_FLASHC_FSR_LOCK6                                        22
#define AVR32_FLASHC_FSR_LOCK6_MASK                           0x00400000
#define AVR32_FLASHC_FSR_LOCK6_OFFSET                                 22
#define AVR32_FLASHC_FSR_LOCK6_SIZE                                    1
#define AVR32_FLASHC_FSR_LOCK7                                        23
#define AVR32_FLASHC_FSR_LOCK7_MASK                           0x00800000
#define AVR32_FLASHC_FSR_LOCK7_OFFSET                                 23
#define AVR32_FLASHC_FSR_LOCK7_SIZE                                    1
#define AVR32_FLASHC_FSR_LOCK8                                        24
#define AVR32_FLASHC_FSR_LOCK8_MASK                           0x01000000
#define AVR32_FLASHC_FSR_LOCK8_OFFSET                                 24
#define AVR32_FLASHC_FSR_LOCK8_SIZE                                    1
#define AVR32_FLASHC_FSR_LOCK9                                        25
#define AVR32_FLASHC_FSR_LOCK9_MASK                           0x02000000
#define AVR32_FLASHC_FSR_LOCK9_OFFSET                                 25
#define AVR32_FLASHC_FSR_LOCK9_SIZE                                    1
#define AVR32_FLASHC_FSR_LOCKE                                         2
#define AVR32_FLASHC_FSR_LOCKE_MASK                           0x00000004
#define AVR32_FLASHC_FSR_LOCKE_OFFSET                                  2
#define AVR32_FLASHC_FSR_LOCKE_SIZE                                    1
#define AVR32_FLASHC_FSR_PROGE                                         3
#define AVR32_FLASHC_FSR_PROGE_MASK                           0x00000008
#define AVR32_FLASHC_FSR_PROGE_OFFSET                                  3
#define AVR32_FLASHC_FSR_PROGE_SIZE                                    1
#define AVR32_FLASHC_FSR_QPRR                                          5
#define AVR32_FLASHC_FSR_QPRR_MASK                            0x00000020
#define AVR32_FLASHC_FSR_QPRR_OFFSET                                   5
#define AVR32_FLASHC_FSR_QPRR_SIZE                                     1
#define AVR32_FLASHC_FSR_SECURITY                                      4
#define AVR32_FLASHC_FSR_SECURITY_MASK                        0x00000010
#define AVR32_FLASHC_FSR_SECURITY_OFFSET                               4
#define AVR32_FLASHC_FSR_SECURITY_SIZE                                 1
#define AVR32_FLASHC_FSZ                                              13
#define AVR32_FLASHC_FSZ_1024                                 0x00000007
#define AVR32_FLASHC_FSZ_128                                  0x00000002
#define AVR32_FLASHC_FSZ_256                                  0x00000003
#define AVR32_FLASHC_FSZ_32                                   0x00000000
#define AVR32_FLASHC_FSZ_384                                  0x00000004
#define AVR32_FLASHC_FSZ_512                                  0x00000005
#define AVR32_FLASHC_FSZ_64                                   0x00000001
#define AVR32_FLASHC_FSZ_768                                  0x00000006
#define AVR32_FLASHC_FSZ_MASK                                 0x0000e000
#define AVR32_FLASHC_FSZ_OFFSET                                       13
#define AVR32_FLASHC_FSZ_SIZE                                          3
#define AVR32_FLASHC_FWS                                               6
#define AVR32_FLASHC_FWS_MASK                                 0x00000040
#define AVR32_FLASHC_FWS_OFFSET                                        6
#define AVR32_FLASHC_FWS_SIZE                                          1
#define AVR32_FLASHC_GPF20                                            20
#define AVR32_FLASHC_GPF20_MASK                               0x00100000
#define AVR32_FLASHC_GPF20_OFFSET                                     20
#define AVR32_FLASHC_GPF20_SIZE                                        1
#define AVR32_FLASHC_GPF21                                            21
#define AVR32_FLASHC_GPF21_MASK                               0x00200000
#define AVR32_FLASHC_GPF21_OFFSET                                     21
#define AVR32_FLASHC_GPF21_SIZE                                        1
#define AVR32_FLASHC_GPF22                                            22
#define AVR32_FLASHC_GPF22_MASK                               0x00400000
#define AVR32_FLASHC_GPF22_OFFSET                                     22
#define AVR32_FLASHC_GPF22_SIZE                                        1
#define AVR32_FLASHC_GPF23                                            23
#define AVR32_FLASHC_GPF23_MASK                               0x00800000
#define AVR32_FLASHC_GPF23_OFFSET                                     23
#define AVR32_FLASHC_GPF23_SIZE                                        1
#define AVR32_FLASHC_GPF24                                            24
#define AVR32_FLASHC_GPF24_MASK                               0x01000000
#define AVR32_FLASHC_GPF24_OFFSET                                     24
#define AVR32_FLASHC_GPF24_SIZE                                        1
#define AVR32_FLASHC_GPF25                                            25
#define AVR32_FLASHC_GPF25_MASK                               0x02000000
#define AVR32_FLASHC_GPF25_OFFSET                                     25
#define AVR32_FLASHC_GPF25_SIZE                                        1
#define AVR32_FLASHC_GPF26                                            26
#define AVR32_FLASHC_GPF26_MASK                               0x04000000
#define AVR32_FLASHC_GPF26_OFFSET                                     26
#define AVR32_FLASHC_GPF26_SIZE                                        1
#define AVR32_FLASHC_GPF27                                            27
#define AVR32_FLASHC_GPF27_MASK                               0x08000000
#define AVR32_FLASHC_GPF27_OFFSET                                     27
#define AVR32_FLASHC_GPF27_SIZE                                        1
#define AVR32_FLASHC_GPF28                                            28
#define AVR32_FLASHC_GPF28_MASK                               0x10000000
#define AVR32_FLASHC_GPF28_OFFSET                                     28
#define AVR32_FLASHC_GPF28_SIZE                                        1
#define AVR32_FLASHC_GPF29                                            29
#define AVR32_FLASHC_GPF29_MASK                               0x20000000
#define AVR32_FLASHC_GPF29_OFFSET                                     29
#define AVR32_FLASHC_GPF29_SIZE                                        1
#define AVR32_FLASHC_GPF30                                            30
#define AVR32_FLASHC_GPF30_MASK                               0x40000000
#define AVR32_FLASHC_GPF30_OFFSET                                     30
#define AVR32_FLASHC_GPF30_SIZE                                        1
#define AVR32_FLASHC_GPF31                                            31
#define AVR32_FLASHC_GPF31_MASK                               0x80000000
#define AVR32_FLASHC_GPF31_OFFSET                                     31
#define AVR32_FLASHC_GPF31_SIZE                                        1
#define AVR32_FLASHC_GPF32                                             0
#define AVR32_FLASHC_GPF32_MASK                               0x00000001
#define AVR32_FLASHC_GPF32_OFFSET                                      0
#define AVR32_FLASHC_GPF32_SIZE                                        1
#define AVR32_FLASHC_GPF33                                             1
#define AVR32_FLASHC_GPF33_MASK                               0x00000002
#define AVR32_FLASHC_GPF33_OFFSET                                      1
#define AVR32_FLASHC_GPF33_SIZE                                        1
#define AVR32_FLASHC_GPF34                                             2
#define AVR32_FLASHC_GPF34_MASK                               0x00000004
#define AVR32_FLASHC_GPF34_OFFSET                                      2
#define AVR32_FLASHC_GPF34_SIZE                                        1
#define AVR32_FLASHC_GPF35                                             3
#define AVR32_FLASHC_GPF35_MASK                               0x00000008
#define AVR32_FLASHC_GPF35_OFFSET                                      3
#define AVR32_FLASHC_GPF35_SIZE                                        1
#define AVR32_FLASHC_GPF36                                             4
#define AVR32_FLASHC_GPF36_MASK                               0x00000010
#define AVR32_FLASHC_GPF36_OFFSET                                      4
#define AVR32_FLASHC_GPF36_SIZE                                        1
#define AVR32_FLASHC_GPF37                                             5
#define AVR32_FLASHC_GPF37_MASK                               0x00000020
#define AVR32_FLASHC_GPF37_OFFSET                                      5
#define AVR32_FLASHC_GPF37_SIZE                                        1
#define AVR32_FLASHC_GPF38                                             6
#define AVR32_FLASHC_GPF38_MASK                               0x00000040
#define AVR32_FLASHC_GPF38_OFFSET                                      6
#define AVR32_FLASHC_GPF38_SIZE                                        1
#define AVR32_FLASHC_GPF39                                             7
#define AVR32_FLASHC_GPF39_MASK                               0x00000080
#define AVR32_FLASHC_GPF39_OFFSET                                      7
#define AVR32_FLASHC_GPF39_SIZE                                        1
#define AVR32_FLASHC_GPF40                                             8
#define AVR32_FLASHC_GPF40_MASK                               0x00000100
#define AVR32_FLASHC_GPF40_OFFSET                                      8
#define AVR32_FLASHC_GPF40_SIZE                                        1
#define AVR32_FLASHC_GPF41                                             9
#define AVR32_FLASHC_GPF41_MASK                               0x00000200
#define AVR32_FLASHC_GPF41_OFFSET                                      9
#define AVR32_FLASHC_GPF41_SIZE                                        1
#define AVR32_FLASHC_GPF42                                            10
#define AVR32_FLASHC_GPF42_MASK                               0x00000400
#define AVR32_FLASHC_GPF42_OFFSET                                     10
#define AVR32_FLASHC_GPF42_SIZE                                        1
#define AVR32_FLASHC_GPF43                                            11
#define AVR32_FLASHC_GPF43_MASK                               0x00000800
#define AVR32_FLASHC_GPF43_OFFSET                                     11
#define AVR32_FLASHC_GPF43_SIZE                                        1
#define AVR32_FLASHC_GPF44                                            12
#define AVR32_FLASHC_GPF44_MASK                               0x00001000
#define AVR32_FLASHC_GPF44_OFFSET                                     12
#define AVR32_FLASHC_GPF44_SIZE                                        1
#define AVR32_FLASHC_GPF45                                            13
#define AVR32_FLASHC_GPF45_MASK                               0x00002000
#define AVR32_FLASHC_GPF45_OFFSET                                     13
#define AVR32_FLASHC_GPF45_SIZE                                        1
#define AVR32_FLASHC_GPF46                                            14
#define AVR32_FLASHC_GPF46_MASK                               0x00004000
#define AVR32_FLASHC_GPF46_OFFSET                                     14
#define AVR32_FLASHC_GPF46_SIZE                                        1
#define AVR32_FLASHC_GPF47                                            15
#define AVR32_FLASHC_GPF47_MASK                               0x00008000
#define AVR32_FLASHC_GPF47_OFFSET                                     15
#define AVR32_FLASHC_GPF47_SIZE                                        1
#define AVR32_FLASHC_GPF48                                            16
#define AVR32_FLASHC_GPF48_MASK                               0x00010000
#define AVR32_FLASHC_GPF48_OFFSET                                     16
#define AVR32_FLASHC_GPF48_SIZE                                        1
#define AVR32_FLASHC_GPF49                                            17
#define AVR32_FLASHC_GPF49_MASK                               0x00020000
#define AVR32_FLASHC_GPF49_OFFSET                                     17
#define AVR32_FLASHC_GPF49_SIZE                                        1
#define AVR32_FLASHC_GPF50                                            18
#define AVR32_FLASHC_GPF50_MASK                               0x00040000
#define AVR32_FLASHC_GPF50_OFFSET                                     18
#define AVR32_FLASHC_GPF50_SIZE                                        1
#define AVR32_FLASHC_GPF51                                            19
#define AVR32_FLASHC_GPF51_MASK                               0x00080000
#define AVR32_FLASHC_GPF51_OFFSET                                     19
#define AVR32_FLASHC_GPF51_SIZE                                        1
#define AVR32_FLASHC_GPF52                                            20
#define AVR32_FLASHC_GPF52_MASK                               0x00100000
#define AVR32_FLASHC_GPF52_OFFSET                                     20
#define AVR32_FLASHC_GPF52_SIZE                                        1
#define AVR32_FLASHC_GPF53                                            21
#define AVR32_FLASHC_GPF53_MASK                               0x00200000
#define AVR32_FLASHC_GPF53_OFFSET                                     21
#define AVR32_FLASHC_GPF53_SIZE                                        1
#define AVR32_FLASHC_GPF54                                            22
#define AVR32_FLASHC_GPF54_MASK                               0x00400000
#define AVR32_FLASHC_GPF54_OFFSET                                     22
#define AVR32_FLASHC_GPF54_SIZE                                        1
#define AVR32_FLASHC_GPF55                                            23
#define AVR32_FLASHC_GPF55_MASK                               0x00800000
#define AVR32_FLASHC_GPF55_OFFSET                                     23
#define AVR32_FLASHC_GPF55_SIZE                                        1
#define AVR32_FLASHC_GPF56                                            24
#define AVR32_FLASHC_GPF56_MASK                               0x01000000
#define AVR32_FLASHC_GPF56_OFFSET                                     24
#define AVR32_FLASHC_GPF56_SIZE                                        1
#define AVR32_FLASHC_GPF57                                            25
#define AVR32_FLASHC_GPF57_MASK                               0x02000000
#define AVR32_FLASHC_GPF57_OFFSET                                     25
#define AVR32_FLASHC_GPF57_SIZE                                        1
#define AVR32_FLASHC_GPF58                                            26
#define AVR32_FLASHC_GPF58_MASK                               0x04000000
#define AVR32_FLASHC_GPF58_OFFSET                                     26
#define AVR32_FLASHC_GPF58_SIZE                                        1
#define AVR32_FLASHC_GPF59                                            27
#define AVR32_FLASHC_GPF59_MASK                               0x08000000
#define AVR32_FLASHC_GPF59_OFFSET                                     27
#define AVR32_FLASHC_GPF59_SIZE                                        1
#define AVR32_FLASHC_GPF60                                            28
#define AVR32_FLASHC_GPF60_MASK                               0x10000000
#define AVR32_FLASHC_GPF60_OFFSET                                     28
#define AVR32_FLASHC_GPF60_SIZE                                        1
#define AVR32_FLASHC_GPF61                                            29
#define AVR32_FLASHC_GPF61_MASK                               0x20000000
#define AVR32_FLASHC_GPF61_OFFSET                                     29
#define AVR32_FLASHC_GPF61_SIZE                                        1
#define AVR32_FLASHC_GPF62                                            30
#define AVR32_FLASHC_GPF62_MASK                               0x40000000
#define AVR32_FLASHC_GPF62_OFFSET                                     30
#define AVR32_FLASHC_GPF62_SIZE                                        1
#define AVR32_FLASHC_GPF63                                            31
#define AVR32_FLASHC_GPF63_MASK                               0x80000000
#define AVR32_FLASHC_GPF63_OFFSET                                     31
#define AVR32_FLASHC_GPF63_SIZE                                        1
#define AVR32_FLASHC_KEY_KEY                                  0x000000a5
#define AVR32_FLASHC_KEY_MASK                                 0xff000000
#define AVR32_FLASHC_KEY_OFFSET                                       24
#define AVR32_FLASHC_KEY_SIZE                                          8
#define AVR32_FLASHC_LOCK0_SIZE                                        1
#define AVR32_FLASHC_LOCK10_SIZE                                       1
#define AVR32_FLASHC_LOCK11_SIZE                                       1
#define AVR32_FLASHC_LOCK12_SIZE                                       1
#define AVR32_FLASHC_LOCK13_SIZE                                       1
#define AVR32_FLASHC_LOCK14_SIZE                                       1
#define AVR32_FLASHC_LOCK15_SIZE                                       1
#define AVR32_FLASHC_LOCK1_SIZE                                        1
#define AVR32_FLASHC_LOCK2_SIZE                                        1
#define AVR32_FLASHC_LOCK3_SIZE                                        1
#define AVR32_FLASHC_LOCK4_SIZE                                        1
#define AVR32_FLASHC_LOCK5_SIZE                                        1
#define AVR32_FLASHC_LOCK6_SIZE                                        1
#define AVR32_FLASHC_LOCK7_SIZE                                        1
#define AVR32_FLASHC_LOCK8_SIZE                                        1
#define AVR32_FLASHC_LOCK9_SIZE                                        1
#define AVR32_FLASHC_LOCKE                                             2
#define AVR32_FLASHC_LOCKE_MASK                               0x00000004
#define AVR32_FLASHC_LOCKE_OFFSET                                      2
#define AVR32_FLASHC_LOCKE_SIZE                                        1
#define AVR32_FLASHC_LP                                       0x00000004
#define AVR32_FLASHC_NOP                                      0x00000000
#define AVR32_FLASHC_PAGEN                                             8
#define AVR32_FLASHC_PAGEN_MASK                               0x00ffff00
#define AVR32_FLASHC_PAGEN_OFFSET                                      8
#define AVR32_FLASHC_PAGEN_SIZE                                       16
#define AVR32_FLASHC_PGPFB                                    0x0000000a
#define AVR32_FLASHC_PROGE                                             3
#define AVR32_FLASHC_PROGE_MASK                               0x00000008
#define AVR32_FLASHC_PROGE_OFFSET                                      3
#define AVR32_FLASHC_PROGE_SIZE                                        1
#define AVR32_FLASHC_QPR                                      0x0000000c
#define AVR32_FLASHC_QPRR                                              5
#define AVR32_FLASHC_QPRR_MASK                                0x00000020
#define AVR32_FLASHC_QPRR_OFFSET                                       5
#define AVR32_FLASHC_QPRR_SIZE                                         1
#define AVR32_FLASHC_QPRUP                                    0x0000000f
#define AVR32_FLASHC_SECURITY                                          4
#define AVR32_FLASHC_SECURITY_MASK                            0x00000010
#define AVR32_FLASHC_SECURITY_OFFSET                                   4
#define AVR32_FLASHC_SECURITY_SIZE                                     1
#define AVR32_FLASHC_SSB                                      0x00000009
#define AVR32_FLASHC_UP                                       0x00000005
#define AVR32_FLASHC_WGPB                                     0x00000007
#define AVR32_FLASHC_WP                                       0x00000001
#define AVR32_FLASHC_WUP                                      0x0000000d




#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_flashc_fcr_t {
    unsigned int                 :25;
    unsigned int fws             : 1;
    unsigned int                 : 2;
    unsigned int proge           : 1;
    unsigned int locke           : 1;
    unsigned int                 : 1;
    unsigned int frdy            : 1;
} avr32_flashc_fcr_t;



typedef struct avr32_flashc_fcmd_t {
    unsigned int key             : 8;
    unsigned int pagen           :16;
    unsigned int                 : 2;
    unsigned int cmd             : 6;
} avr32_flashc_fcmd_t;



typedef struct avr32_flashc_fsr_t {
    unsigned int lock15          : 1;
    unsigned int lock14          : 1;
    unsigned int lock13          : 1;
    unsigned int lock12          : 1;
    unsigned int lock11          : 1;
    unsigned int lock10          : 1;
    unsigned int lock9           : 1;
    unsigned int lock8           : 1;
    unsigned int lock7           : 1;
    unsigned int lock6           : 1;
    unsigned int lock5           : 1;
    unsigned int lock4           : 1;
    unsigned int lock3           : 1;
    unsigned int lock2           : 1;
    unsigned int lock1           : 1;
    unsigned int lock0           : 1;
    unsigned int fsz             : 3;
    unsigned int                 : 7;
    unsigned int qprr            : 1;
    unsigned int security        : 1;
    unsigned int proge           : 1;
    unsigned int locke           : 1;
    unsigned int                 : 1;
    unsigned int frdy            : 1;
} avr32_flashc_fsr_t;



typedef struct avr32_flashc_fgpfrhi_t {
    unsigned int gpf63           : 1;
    unsigned int gpf62           : 1;
    unsigned int gpf61           : 1;
    unsigned int gpf60           : 1;
    unsigned int gpf59           : 1;
    unsigned int gpf58           : 1;
    unsigned int gpf57           : 1;
    unsigned int gpf56           : 1;
    unsigned int gpf55           : 1;
    unsigned int gpf54           : 1;
    unsigned int gpf53           : 1;
    unsigned int gpf52           : 1;
    unsigned int gpf51           : 1;
    unsigned int gpf50           : 1;
    unsigned int gpf49           : 1;
    unsigned int gpf48           : 1;
    unsigned int gpf47           : 1;
    unsigned int gpf46           : 1;
    unsigned int gpf45           : 1;
    unsigned int gpf44           : 1;
    unsigned int gpf43           : 1;
    unsigned int gpf42           : 1;
    unsigned int gpf41           : 1;
    unsigned int gpf40           : 1;
    unsigned int gpf39           : 1;
    unsigned int gpf38           : 1;
    unsigned int gpf37           : 1;
    unsigned int gpf36           : 1;
    unsigned int gpf35           : 1;
    unsigned int gpf34           : 1;
    unsigned int gpf33           : 1;
    unsigned int gpf32           : 1;
} avr32_flashc_fgpfrhi_t;



typedef struct avr32_flashc_fgpfrlo_t {
    unsigned int gpf31           : 1;
    unsigned int gpf30           : 1;
    unsigned int gpf29           : 1;
    unsigned int gpf28           : 1;
    unsigned int gpf27           : 1;
    unsigned int gpf26           : 1;
    unsigned int gpf25           : 1;
    unsigned int gpf24           : 1;
    unsigned int gpf23           : 1;
    unsigned int gpf22           : 1;
    unsigned int gpf21           : 1;
    unsigned int gpf20           : 1;
    unsigned int bootprot        : 3;
    unsigned int epfl            : 1;
    unsigned int lock15          : 1;
    unsigned int lock14          : 1;
    unsigned int lock13          : 1;
    unsigned int lock12          : 1;
    unsigned int lock11          : 1;
    unsigned int lock10          : 1;
    unsigned int lock9           : 1;
    unsigned int lock8           : 1;
    unsigned int lock7           : 1;
    unsigned int lock6           : 1;
    unsigned int lock5           : 1;
    unsigned int lock4           : 1;
    unsigned int lock3           : 1;
    unsigned int lock2           : 1;
    unsigned int lock1           : 1;
    unsigned int lock0           : 1;
} avr32_flashc_fgpfrlo_t;



typedef struct avr32_flashc_t {
  union {
          unsigned long                  fcr       ;//0x0000
          avr32_flashc_fcr_t             FCR       ;
  };
  union {
          unsigned long                  fcmd      ;//0x0004
          avr32_flashc_fcmd_t            FCMD      ;
  };
  union {
          unsigned long                  fsr       ;//0x0008
          avr32_flashc_fsr_t             FSR       ;
  };
  union {
    const unsigned long                  fgpfrhi   ;//0x000c
    const avr32_flashc_fgpfrhi_t         FGPFRHI   ;
  };
  union {
    const unsigned long                  fgpfrlo   ;//0x0010
    const avr32_flashc_fgpfrlo_t         FGPFRLO   ;
  };
} avr32_flashc_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif

/*#ifdef AVR32_FLASHC_200_H_INCLUDED*/
#endif

