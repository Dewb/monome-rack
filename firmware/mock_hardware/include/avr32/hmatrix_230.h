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
#ifndef AVR32_HMATRIX_230_H_INCLUDED
#define AVR32_HMATRIX_230_H_INCLUDED

#define AVR32_HMATRIX_H_VERSION 230

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_HMATRIX_<register>
 - Bitfield mask:   AVR32_HMATRIX_<register>_<bitfield>
 - Bitfield offset: AVR32_HMATRIX_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_HMATRIX_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_HMATRIX_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_HMATRIX_<bitfield>
 - Bitfield offset: AVR32_HMATRIX_<bitfield>_OFFSET
 - Bitfield size:   AVR32_HMATRIX_<bitfield>_SIZE
 - Bitfield values: AVR32_HMATRIX_<bitfield>_<value name>
 - Bitfield values: AVR32_HMATRIX_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_HMATRIX_ARBT                                             24
#define AVR32_HMATRIX_ARBT_FIXED_PRIORITY                      0x00000001
#define AVR32_HMATRIX_ARBT_MASK                                0x01000000
#define AVR32_HMATRIX_ARBT_OFFSET                                      24
#define AVR32_HMATRIX_ARBT_ROUND_ROBIN                         0x00000000
#define AVR32_HMATRIX_ARBT_SIZE                                         1
#define AVR32_HMATRIX_DEFMSTR_TYPE                                     16
#define AVR32_HMATRIX_DEFMSTR_TYPE_FIXED_DEFAULT               0x00000002
#define AVR32_HMATRIX_DEFMSTR_TYPE_LAST_DEFAULT                0x00000001
#define AVR32_HMATRIX_DEFMSTR_TYPE_MASK                        0x00030000
#define AVR32_HMATRIX_DEFMSTR_TYPE_NO_DEFAULT                  0x00000000
#define AVR32_HMATRIX_DEFMSTR_TYPE_OFFSET                              16
#define AVR32_HMATRIX_DEFMSTR_TYPE_SIZE                                 2
#define AVR32_HMATRIX_EIGHT_BEAT                               0x00000003
#define AVR32_HMATRIX_FIXED_DEFAULT                            0x00000002
#define AVR32_HMATRIX_FIXED_DEFMSTR                                    18
#define AVR32_HMATRIX_FIXED_DEFMSTR_MASK                       0x003c0000
#define AVR32_HMATRIX_FIXED_DEFMSTR_OFFSET                             18
#define AVR32_HMATRIX_FIXED_DEFMSTR_SIZE                                4
#define AVR32_HMATRIX_FIXED_PRIORITY                           0x00000001
#define AVR32_HMATRIX_FOUR_BEAT                                0x00000002
#define AVR32_HMATRIX_INFINITE                                 0x00000000
#define AVR32_HMATRIX_LAST_DEFAULT                             0x00000001
#define AVR32_HMATRIX_M0PR                                              0
#define AVR32_HMATRIX_M0PR_MASK                                0x0000000f
#define AVR32_HMATRIX_M0PR_OFFSET                                       0
#define AVR32_HMATRIX_M0PR_SIZE                                         4
#define AVR32_HMATRIX_M10PR                                             8
#define AVR32_HMATRIX_M10PR_MASK                               0x00000f00
#define AVR32_HMATRIX_M10PR_OFFSET                                      8
#define AVR32_HMATRIX_M10PR_SIZE                                        4
#define AVR32_HMATRIX_M11PR                                            12
#define AVR32_HMATRIX_M11PR_MASK                               0x0000f000
#define AVR32_HMATRIX_M11PR_OFFSET                                     12
#define AVR32_HMATRIX_M11PR_SIZE                                        4
#define AVR32_HMATRIX_M12PR                                            16
#define AVR32_HMATRIX_M12PR_MASK                               0x000f0000
#define AVR32_HMATRIX_M12PR_OFFSET                                     16
#define AVR32_HMATRIX_M12PR_SIZE                                        4
#define AVR32_HMATRIX_M13PR                                            20
#define AVR32_HMATRIX_M13PR_MASK                               0x00f00000
#define AVR32_HMATRIX_M13PR_OFFSET                                     20
#define AVR32_HMATRIX_M13PR_SIZE                                        4
#define AVR32_HMATRIX_M14PR                                            24
#define AVR32_HMATRIX_M14PR_MASK                               0x0f000000
#define AVR32_HMATRIX_M14PR_OFFSET                                     24
#define AVR32_HMATRIX_M14PR_SIZE                                        4
#define AVR32_HMATRIX_M15PR                                            28
#define AVR32_HMATRIX_M15PR_MASK                               0xf0000000
#define AVR32_HMATRIX_M15PR_OFFSET                                     28
#define AVR32_HMATRIX_M15PR_SIZE                                        4
#define AVR32_HMATRIX_M1PR                                              4
#define AVR32_HMATRIX_M1PR_MASK                                0x000000f0
#define AVR32_HMATRIX_M1PR_OFFSET                                       4
#define AVR32_HMATRIX_M1PR_SIZE                                         4
#define AVR32_HMATRIX_M2PR                                              8
#define AVR32_HMATRIX_M2PR_MASK                                0x00000f00
#define AVR32_HMATRIX_M2PR_OFFSET                                       8
#define AVR32_HMATRIX_M2PR_SIZE                                         4
#define AVR32_HMATRIX_M3PR                                             12
#define AVR32_HMATRIX_M3PR_MASK                                0x0000f000
#define AVR32_HMATRIX_M3PR_OFFSET                                      12
#define AVR32_HMATRIX_M3PR_SIZE                                         4
#define AVR32_HMATRIX_M4PR                                             16
#define AVR32_HMATRIX_M4PR_MASK                                0x000f0000
#define AVR32_HMATRIX_M4PR_OFFSET                                      16
#define AVR32_HMATRIX_M4PR_SIZE                                         4
#define AVR32_HMATRIX_M5PR                                             20
#define AVR32_HMATRIX_M5PR_MASK                                0x00f00000
#define AVR32_HMATRIX_M5PR_OFFSET                                      20
#define AVR32_HMATRIX_M5PR_SIZE                                         4
#define AVR32_HMATRIX_M6PR                                             24
#define AVR32_HMATRIX_M6PR_MASK                                0x0f000000
#define AVR32_HMATRIX_M6PR_OFFSET                                      24
#define AVR32_HMATRIX_M6PR_SIZE                                         4
#define AVR32_HMATRIX_M7PR                                             28
#define AVR32_HMATRIX_M7PR_MASK                                0xf0000000
#define AVR32_HMATRIX_M7PR_OFFSET                                      28
#define AVR32_HMATRIX_M7PR_SIZE                                         4
#define AVR32_HMATRIX_M8PR                                              0
#define AVR32_HMATRIX_M8PR_MASK                                0x0000000f
#define AVR32_HMATRIX_M8PR_OFFSET                                       0
#define AVR32_HMATRIX_M8PR_SIZE                                         4
#define AVR32_HMATRIX_M9PR                                              4
#define AVR32_HMATRIX_M9PR_MASK                                0x000000f0
#define AVR32_HMATRIX_M9PR_OFFSET                                       4
#define AVR32_HMATRIX_M9PR_SIZE                                         4
#define AVR32_HMATRIX_MCFG0                                    0x00000000
#define AVR32_HMATRIX_MCFG0_ULBT                                        0
#define AVR32_HMATRIX_MCFG0_ULBT_EIGHT_BEAT                    0x00000003
#define AVR32_HMATRIX_MCFG0_ULBT_FOUR_BEAT                     0x00000002
#define AVR32_HMATRIX_MCFG0_ULBT_INFINITE                      0x00000000
#define AVR32_HMATRIX_MCFG0_ULBT_MASK                          0x00000007
#define AVR32_HMATRIX_MCFG0_ULBT_OFFSET                                 0
#define AVR32_HMATRIX_MCFG0_ULBT_SINGLE                        0x00000001
#define AVR32_HMATRIX_MCFG0_ULBT_SIXTEEN_BEAT                  0x00000004
#define AVR32_HMATRIX_MCFG0_ULBT_SIZE                                   3
#define AVR32_HMATRIX_MCFG1                                    0x00000004
#define AVR32_HMATRIX_MCFG10                                   0x00000028
#define AVR32_HMATRIX_MCFG10_ULBT                                       0
#define AVR32_HMATRIX_MCFG10_ULBT_EIGHT_BEAT                   0x00000003
#define AVR32_HMATRIX_MCFG10_ULBT_FOUR_BEAT                    0x00000002
#define AVR32_HMATRIX_MCFG10_ULBT_INFINITE                     0x00000000
#define AVR32_HMATRIX_MCFG10_ULBT_MASK                         0x00000007
#define AVR32_HMATRIX_MCFG10_ULBT_OFFSET                                0
#define AVR32_HMATRIX_MCFG10_ULBT_SINGLE                       0x00000001
#define AVR32_HMATRIX_MCFG10_ULBT_SIXTEEN_BEAT                 0x00000004
#define AVR32_HMATRIX_MCFG10_ULBT_SIZE                                  3
#define AVR32_HMATRIX_MCFG11                                   0x0000002c
#define AVR32_HMATRIX_MCFG11_ULBT                                       0
#define AVR32_HMATRIX_MCFG11_ULBT_EIGHT_BEAT                   0x00000003
#define AVR32_HMATRIX_MCFG11_ULBT_FOUR_BEAT                    0x00000002
#define AVR32_HMATRIX_MCFG11_ULBT_INFINITE                     0x00000000
#define AVR32_HMATRIX_MCFG11_ULBT_MASK                         0x00000007
#define AVR32_HMATRIX_MCFG11_ULBT_OFFSET                                0
#define AVR32_HMATRIX_MCFG11_ULBT_SINGLE                       0x00000001
#define AVR32_HMATRIX_MCFG11_ULBT_SIXTEEN_BEAT                 0x00000004
#define AVR32_HMATRIX_MCFG11_ULBT_SIZE                                  3
#define AVR32_HMATRIX_MCFG12                                   0x00000030
#define AVR32_HMATRIX_MCFG12_ULBT                                       0
#define AVR32_HMATRIX_MCFG12_ULBT_EIGHT_BEAT                   0x00000003
#define AVR32_HMATRIX_MCFG12_ULBT_FOUR_BEAT                    0x00000002
#define AVR32_HMATRIX_MCFG12_ULBT_INFINITE                     0x00000000
#define AVR32_HMATRIX_MCFG12_ULBT_MASK                         0x00000007
#define AVR32_HMATRIX_MCFG12_ULBT_OFFSET                                0
#define AVR32_HMATRIX_MCFG12_ULBT_SINGLE                       0x00000001
#define AVR32_HMATRIX_MCFG12_ULBT_SIXTEEN_BEAT                 0x00000004
#define AVR32_HMATRIX_MCFG12_ULBT_SIZE                                  3
#define AVR32_HMATRIX_MCFG13                                   0x00000034
#define AVR32_HMATRIX_MCFG13_ULBT                                       0
#define AVR32_HMATRIX_MCFG13_ULBT_EIGHT_BEAT                   0x00000003
#define AVR32_HMATRIX_MCFG13_ULBT_FOUR_BEAT                    0x00000002
#define AVR32_HMATRIX_MCFG13_ULBT_INFINITE                     0x00000000
#define AVR32_HMATRIX_MCFG13_ULBT_MASK                         0x00000007
#define AVR32_HMATRIX_MCFG13_ULBT_OFFSET                                0
#define AVR32_HMATRIX_MCFG13_ULBT_SINGLE                       0x00000001
#define AVR32_HMATRIX_MCFG13_ULBT_SIXTEEN_BEAT                 0x00000004
#define AVR32_HMATRIX_MCFG13_ULBT_SIZE                                  3
#define AVR32_HMATRIX_MCFG14                                   0x00000038
#define AVR32_HMATRIX_MCFG14_ULBT                                       0
#define AVR32_HMATRIX_MCFG14_ULBT_EIGHT_BEAT                   0x00000003
#define AVR32_HMATRIX_MCFG14_ULBT_FOUR_BEAT                    0x00000002
#define AVR32_HMATRIX_MCFG14_ULBT_INFINITE                     0x00000000
#define AVR32_HMATRIX_MCFG14_ULBT_MASK                         0x00000007
#define AVR32_HMATRIX_MCFG14_ULBT_OFFSET                                0
#define AVR32_HMATRIX_MCFG14_ULBT_SINGLE                       0x00000001
#define AVR32_HMATRIX_MCFG14_ULBT_SIXTEEN_BEAT                 0x00000004
#define AVR32_HMATRIX_MCFG14_ULBT_SIZE                                  3
#define AVR32_HMATRIX_MCFG15                                   0x0000003c
#define AVR32_HMATRIX_MCFG15_ULBT                                       0
#define AVR32_HMATRIX_MCFG15_ULBT_EIGHT_BEAT                   0x00000003
#define AVR32_HMATRIX_MCFG15_ULBT_FOUR_BEAT                    0x00000002
#define AVR32_HMATRIX_MCFG15_ULBT_INFINITE                     0x00000000
#define AVR32_HMATRIX_MCFG15_ULBT_MASK                         0x00000007
#define AVR32_HMATRIX_MCFG15_ULBT_OFFSET                                0
#define AVR32_HMATRIX_MCFG15_ULBT_SINGLE                       0x00000001
#define AVR32_HMATRIX_MCFG15_ULBT_SIXTEEN_BEAT                 0x00000004
#define AVR32_HMATRIX_MCFG15_ULBT_SIZE                                  3
#define AVR32_HMATRIX_MCFG1_ULBT                                        0
#define AVR32_HMATRIX_MCFG1_ULBT_EIGHT_BEAT                    0x00000003
#define AVR32_HMATRIX_MCFG1_ULBT_FOUR_BEAT                     0x00000002
#define AVR32_HMATRIX_MCFG1_ULBT_INFINITE                      0x00000000
#define AVR32_HMATRIX_MCFG1_ULBT_MASK                          0x00000007
#define AVR32_HMATRIX_MCFG1_ULBT_OFFSET                                 0
#define AVR32_HMATRIX_MCFG1_ULBT_SINGLE                        0x00000001
#define AVR32_HMATRIX_MCFG1_ULBT_SIXTEEN_BEAT                  0x00000004
#define AVR32_HMATRIX_MCFG1_ULBT_SIZE                                   3
#define AVR32_HMATRIX_MCFG2                                    0x00000008
#define AVR32_HMATRIX_MCFG2_ULBT                                        0
#define AVR32_HMATRIX_MCFG2_ULBT_EIGHT_BEAT                    0x00000003
#define AVR32_HMATRIX_MCFG2_ULBT_FOUR_BEAT                     0x00000002
#define AVR32_HMATRIX_MCFG2_ULBT_INFINITE                      0x00000000
#define AVR32_HMATRIX_MCFG2_ULBT_MASK                          0x00000007
#define AVR32_HMATRIX_MCFG2_ULBT_OFFSET                                 0
#define AVR32_HMATRIX_MCFG2_ULBT_SINGLE                        0x00000001
#define AVR32_HMATRIX_MCFG2_ULBT_SIXTEEN_BEAT                  0x00000004
#define AVR32_HMATRIX_MCFG2_ULBT_SIZE                                   3
#define AVR32_HMATRIX_MCFG3                                    0x0000000c
#define AVR32_HMATRIX_MCFG3_ULBT                                        0
#define AVR32_HMATRIX_MCFG3_ULBT_EIGHT_BEAT                    0x00000003
#define AVR32_HMATRIX_MCFG3_ULBT_FOUR_BEAT                     0x00000002
#define AVR32_HMATRIX_MCFG3_ULBT_INFINITE                      0x00000000
#define AVR32_HMATRIX_MCFG3_ULBT_MASK                          0x00000007
#define AVR32_HMATRIX_MCFG3_ULBT_OFFSET                                 0
#define AVR32_HMATRIX_MCFG3_ULBT_SINGLE                        0x00000001
#define AVR32_HMATRIX_MCFG3_ULBT_SIXTEEN_BEAT                  0x00000004
#define AVR32_HMATRIX_MCFG3_ULBT_SIZE                                   3
#define AVR32_HMATRIX_MCFG4                                    0x00000010
#define AVR32_HMATRIX_MCFG4_ULBT                                        0
#define AVR32_HMATRIX_MCFG4_ULBT_EIGHT_BEAT                    0x00000003
#define AVR32_HMATRIX_MCFG4_ULBT_FOUR_BEAT                     0x00000002
#define AVR32_HMATRIX_MCFG4_ULBT_INFINITE                      0x00000000
#define AVR32_HMATRIX_MCFG4_ULBT_MASK                          0x00000007
#define AVR32_HMATRIX_MCFG4_ULBT_OFFSET                                 0
#define AVR32_HMATRIX_MCFG4_ULBT_SINGLE                        0x00000001
#define AVR32_HMATRIX_MCFG4_ULBT_SIXTEEN_BEAT                  0x00000004
#define AVR32_HMATRIX_MCFG4_ULBT_SIZE                                   3
#define AVR32_HMATRIX_MCFG5                                    0x00000014
#define AVR32_HMATRIX_MCFG5_ULBT                                        0
#define AVR32_HMATRIX_MCFG5_ULBT_EIGHT_BEAT                    0x00000003
#define AVR32_HMATRIX_MCFG5_ULBT_FOUR_BEAT                     0x00000002
#define AVR32_HMATRIX_MCFG5_ULBT_INFINITE                      0x00000000
#define AVR32_HMATRIX_MCFG5_ULBT_MASK                          0x00000007
#define AVR32_HMATRIX_MCFG5_ULBT_OFFSET                                 0
#define AVR32_HMATRIX_MCFG5_ULBT_SINGLE                        0x00000001
#define AVR32_HMATRIX_MCFG5_ULBT_SIXTEEN_BEAT                  0x00000004
#define AVR32_HMATRIX_MCFG5_ULBT_SIZE                                   3
#define AVR32_HMATRIX_MCFG6                                    0x00000018
#define AVR32_HMATRIX_MCFG6_ULBT                                        0
#define AVR32_HMATRIX_MCFG6_ULBT_EIGHT_BEAT                    0x00000003
#define AVR32_HMATRIX_MCFG6_ULBT_FOUR_BEAT                     0x00000002
#define AVR32_HMATRIX_MCFG6_ULBT_INFINITE                      0x00000000
#define AVR32_HMATRIX_MCFG6_ULBT_MASK                          0x00000007
#define AVR32_HMATRIX_MCFG6_ULBT_OFFSET                                 0
#define AVR32_HMATRIX_MCFG6_ULBT_SINGLE                        0x00000001
#define AVR32_HMATRIX_MCFG6_ULBT_SIXTEEN_BEAT                  0x00000004
#define AVR32_HMATRIX_MCFG6_ULBT_SIZE                                   3
#define AVR32_HMATRIX_MCFG7                                    0x0000001c
#define AVR32_HMATRIX_MCFG7_ULBT                                        0
#define AVR32_HMATRIX_MCFG7_ULBT_EIGHT_BEAT                    0x00000003
#define AVR32_HMATRIX_MCFG7_ULBT_FOUR_BEAT                     0x00000002
#define AVR32_HMATRIX_MCFG7_ULBT_INFINITE                      0x00000000
#define AVR32_HMATRIX_MCFG7_ULBT_MASK                          0x00000007
#define AVR32_HMATRIX_MCFG7_ULBT_OFFSET                                 0
#define AVR32_HMATRIX_MCFG7_ULBT_SINGLE                        0x00000001
#define AVR32_HMATRIX_MCFG7_ULBT_SIXTEEN_BEAT                  0x00000004
#define AVR32_HMATRIX_MCFG7_ULBT_SIZE                                   3
#define AVR32_HMATRIX_MCFG8                                    0x00000020
#define AVR32_HMATRIX_MCFG8_ULBT                                        0
#define AVR32_HMATRIX_MCFG8_ULBT_EIGHT_BEAT                    0x00000003
#define AVR32_HMATRIX_MCFG8_ULBT_FOUR_BEAT                     0x00000002
#define AVR32_HMATRIX_MCFG8_ULBT_INFINITE                      0x00000000
#define AVR32_HMATRIX_MCFG8_ULBT_MASK                          0x00000007
#define AVR32_HMATRIX_MCFG8_ULBT_OFFSET                                 0
#define AVR32_HMATRIX_MCFG8_ULBT_SINGLE                        0x00000001
#define AVR32_HMATRIX_MCFG8_ULBT_SIXTEEN_BEAT                  0x00000004
#define AVR32_HMATRIX_MCFG8_ULBT_SIZE                                   3
#define AVR32_HMATRIX_MCFG9                                    0x00000024
#define AVR32_HMATRIX_MCFG9_ULBT                                        0
#define AVR32_HMATRIX_MCFG9_ULBT_EIGHT_BEAT                    0x00000003
#define AVR32_HMATRIX_MCFG9_ULBT_FOUR_BEAT                     0x00000002
#define AVR32_HMATRIX_MCFG9_ULBT_INFINITE                      0x00000000
#define AVR32_HMATRIX_MCFG9_ULBT_MASK                          0x00000007
#define AVR32_HMATRIX_MCFG9_ULBT_OFFSET                                 0
#define AVR32_HMATRIX_MCFG9_ULBT_SINGLE                        0x00000001
#define AVR32_HMATRIX_MCFG9_ULBT_SIXTEEN_BEAT                  0x00000004
#define AVR32_HMATRIX_MCFG9_ULBT_SIZE                                   3
#define AVR32_HMATRIX_MRCR                                     0x00000100
#define AVR32_HMATRIX_MRCR_RCB0                                         0
#define AVR32_HMATRIX_MRCR_RCB0_MASK                           0x00000001
#define AVR32_HMATRIX_MRCR_RCB0_OFFSET                                  0
#define AVR32_HMATRIX_MRCR_RCB0_SIZE                                    1
#define AVR32_HMATRIX_MRCR_RCB1                                         1
#define AVR32_HMATRIX_MRCR_RCB10                                       10
#define AVR32_HMATRIX_MRCR_RCB10_MASK                          0x00000400
#define AVR32_HMATRIX_MRCR_RCB10_OFFSET                                10
#define AVR32_HMATRIX_MRCR_RCB10_SIZE                                   1
#define AVR32_HMATRIX_MRCR_RCB11                                       11
#define AVR32_HMATRIX_MRCR_RCB11_MASK                          0x00000800
#define AVR32_HMATRIX_MRCR_RCB11_OFFSET                                11
#define AVR32_HMATRIX_MRCR_RCB11_SIZE                                   1
#define AVR32_HMATRIX_MRCR_RCB12                                       12
#define AVR32_HMATRIX_MRCR_RCB12_MASK                          0x00001000
#define AVR32_HMATRIX_MRCR_RCB12_OFFSET                                12
#define AVR32_HMATRIX_MRCR_RCB12_SIZE                                   1
#define AVR32_HMATRIX_MRCR_RCB13                                       13
#define AVR32_HMATRIX_MRCR_RCB13_MASK                          0x00002000
#define AVR32_HMATRIX_MRCR_RCB13_OFFSET                                13
#define AVR32_HMATRIX_MRCR_RCB13_SIZE                                   1
#define AVR32_HMATRIX_MRCR_RCB14                                       14
#define AVR32_HMATRIX_MRCR_RCB14_MASK                          0x00004000
#define AVR32_HMATRIX_MRCR_RCB14_OFFSET                                14
#define AVR32_HMATRIX_MRCR_RCB14_SIZE                                   1
#define AVR32_HMATRIX_MRCR_RCB15                                       15
#define AVR32_HMATRIX_MRCR_RCB15_MASK                          0x00008000
#define AVR32_HMATRIX_MRCR_RCB15_OFFSET                                15
#define AVR32_HMATRIX_MRCR_RCB15_SIZE                                   1
#define AVR32_HMATRIX_MRCR_RCB1_MASK                           0x00000002
#define AVR32_HMATRIX_MRCR_RCB1_OFFSET                                  1
#define AVR32_HMATRIX_MRCR_RCB1_SIZE                                    1
#define AVR32_HMATRIX_MRCR_RCB2                                         2
#define AVR32_HMATRIX_MRCR_RCB2_MASK                           0x00000004
#define AVR32_HMATRIX_MRCR_RCB2_OFFSET                                  2
#define AVR32_HMATRIX_MRCR_RCB2_SIZE                                    1
#define AVR32_HMATRIX_MRCR_RCB3                                         3
#define AVR32_HMATRIX_MRCR_RCB3_MASK                           0x00000008
#define AVR32_HMATRIX_MRCR_RCB3_OFFSET                                  3
#define AVR32_HMATRIX_MRCR_RCB3_SIZE                                    1
#define AVR32_HMATRIX_MRCR_RCB4                                         4
#define AVR32_HMATRIX_MRCR_RCB4_MASK                           0x00000010
#define AVR32_HMATRIX_MRCR_RCB4_OFFSET                                  4
#define AVR32_HMATRIX_MRCR_RCB4_SIZE                                    1
#define AVR32_HMATRIX_MRCR_RCB5                                         5
#define AVR32_HMATRIX_MRCR_RCB5_MASK                           0x00000020
#define AVR32_HMATRIX_MRCR_RCB5_OFFSET                                  5
#define AVR32_HMATRIX_MRCR_RCB5_SIZE                                    1
#define AVR32_HMATRIX_MRCR_RCB6                                         6
#define AVR32_HMATRIX_MRCR_RCB6_MASK                           0x00000040
#define AVR32_HMATRIX_MRCR_RCB6_OFFSET                                  6
#define AVR32_HMATRIX_MRCR_RCB6_SIZE                                    1
#define AVR32_HMATRIX_MRCR_RCB7                                         7
#define AVR32_HMATRIX_MRCR_RCB7_MASK                           0x00000080
#define AVR32_HMATRIX_MRCR_RCB7_OFFSET                                  7
#define AVR32_HMATRIX_MRCR_RCB7_SIZE                                    1
#define AVR32_HMATRIX_MRCR_RCB8                                         8
#define AVR32_HMATRIX_MRCR_RCB8_MASK                           0x00000100
#define AVR32_HMATRIX_MRCR_RCB8_OFFSET                                  8
#define AVR32_HMATRIX_MRCR_RCB8_SIZE                                    1
#define AVR32_HMATRIX_MRCR_RCB9                                         9
#define AVR32_HMATRIX_MRCR_RCB9_MASK                           0x00000200
#define AVR32_HMATRIX_MRCR_RCB9_OFFSET                                  9
#define AVR32_HMATRIX_MRCR_RCB9_SIZE                                    1
#define AVR32_HMATRIX_NO_DEFAULT                               0x00000000
#define AVR32_HMATRIX_PRAS0                                    0x00000080
#define AVR32_HMATRIX_PRAS0_M0PR                                        0
#define AVR32_HMATRIX_PRAS0_M0PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRAS0_M0PR_OFFSET                                 0
#define AVR32_HMATRIX_PRAS0_M0PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS0_M1PR                                        4
#define AVR32_HMATRIX_PRAS0_M1PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRAS0_M1PR_OFFSET                                 4
#define AVR32_HMATRIX_PRAS0_M1PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS0_M2PR                                        8
#define AVR32_HMATRIX_PRAS0_M2PR_MASK                          0x00000f00
#define AVR32_HMATRIX_PRAS0_M2PR_OFFSET                                 8
#define AVR32_HMATRIX_PRAS0_M2PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS0_M3PR                                       12
#define AVR32_HMATRIX_PRAS0_M3PR_MASK                          0x0000f000
#define AVR32_HMATRIX_PRAS0_M3PR_OFFSET                                12
#define AVR32_HMATRIX_PRAS0_M3PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS0_M4PR                                       16
#define AVR32_HMATRIX_PRAS0_M4PR_MASK                          0x000f0000
#define AVR32_HMATRIX_PRAS0_M4PR_OFFSET                                16
#define AVR32_HMATRIX_PRAS0_M4PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS0_M5PR                                       20
#define AVR32_HMATRIX_PRAS0_M5PR_MASK                          0x00f00000
#define AVR32_HMATRIX_PRAS0_M5PR_OFFSET                                20
#define AVR32_HMATRIX_PRAS0_M5PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS0_M6PR                                       24
#define AVR32_HMATRIX_PRAS0_M6PR_MASK                          0x0f000000
#define AVR32_HMATRIX_PRAS0_M6PR_OFFSET                                24
#define AVR32_HMATRIX_PRAS0_M6PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS0_M7PR                                       28
#define AVR32_HMATRIX_PRAS0_M7PR_MASK                          0xf0000000
#define AVR32_HMATRIX_PRAS0_M7PR_OFFSET                                28
#define AVR32_HMATRIX_PRAS0_M7PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS1                                    0x00000088
#define AVR32_HMATRIX_PRAS10                                   0x000000d0
#define AVR32_HMATRIX_PRAS10_M0PR                                       0
#define AVR32_HMATRIX_PRAS10_M0PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRAS10_M0PR_OFFSET                                0
#define AVR32_HMATRIX_PRAS10_M0PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS10_M1PR                                       4
#define AVR32_HMATRIX_PRAS10_M1PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRAS10_M1PR_OFFSET                                4
#define AVR32_HMATRIX_PRAS10_M1PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS10_M2PR                                       8
#define AVR32_HMATRIX_PRAS10_M2PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRAS10_M2PR_OFFSET                                8
#define AVR32_HMATRIX_PRAS10_M2PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS10_M3PR                                      12
#define AVR32_HMATRIX_PRAS10_M3PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRAS10_M3PR_OFFSET                               12
#define AVR32_HMATRIX_PRAS10_M3PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS10_M4PR                                      16
#define AVR32_HMATRIX_PRAS10_M4PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRAS10_M4PR_OFFSET                               16
#define AVR32_HMATRIX_PRAS10_M4PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS10_M5PR                                      20
#define AVR32_HMATRIX_PRAS10_M5PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRAS10_M5PR_OFFSET                               20
#define AVR32_HMATRIX_PRAS10_M5PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS10_M6PR                                      24
#define AVR32_HMATRIX_PRAS10_M6PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRAS10_M6PR_OFFSET                               24
#define AVR32_HMATRIX_PRAS10_M6PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS10_M7PR                                      28
#define AVR32_HMATRIX_PRAS10_M7PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRAS10_M7PR_OFFSET                               28
#define AVR32_HMATRIX_PRAS10_M7PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS11                                   0x000000d8
#define AVR32_HMATRIX_PRAS11_M0PR                                       0
#define AVR32_HMATRIX_PRAS11_M0PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRAS11_M0PR_OFFSET                                0
#define AVR32_HMATRIX_PRAS11_M0PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS11_M1PR                                       4
#define AVR32_HMATRIX_PRAS11_M1PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRAS11_M1PR_OFFSET                                4
#define AVR32_HMATRIX_PRAS11_M1PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS11_M2PR                                       8
#define AVR32_HMATRIX_PRAS11_M2PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRAS11_M2PR_OFFSET                                8
#define AVR32_HMATRIX_PRAS11_M2PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS11_M3PR                                      12
#define AVR32_HMATRIX_PRAS11_M3PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRAS11_M3PR_OFFSET                               12
#define AVR32_HMATRIX_PRAS11_M3PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS11_M4PR                                      16
#define AVR32_HMATRIX_PRAS11_M4PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRAS11_M4PR_OFFSET                               16
#define AVR32_HMATRIX_PRAS11_M4PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS11_M5PR                                      20
#define AVR32_HMATRIX_PRAS11_M5PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRAS11_M5PR_OFFSET                               20
#define AVR32_HMATRIX_PRAS11_M5PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS11_M6PR                                      24
#define AVR32_HMATRIX_PRAS11_M6PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRAS11_M6PR_OFFSET                               24
#define AVR32_HMATRIX_PRAS11_M6PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS11_M7PR                                      28
#define AVR32_HMATRIX_PRAS11_M7PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRAS11_M7PR_OFFSET                               28
#define AVR32_HMATRIX_PRAS11_M7PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS12                                   0x000000e0
#define AVR32_HMATRIX_PRAS12_M0PR                                       0
#define AVR32_HMATRIX_PRAS12_M0PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRAS12_M0PR_OFFSET                                0
#define AVR32_HMATRIX_PRAS12_M0PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS12_M1PR                                       4
#define AVR32_HMATRIX_PRAS12_M1PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRAS12_M1PR_OFFSET                                4
#define AVR32_HMATRIX_PRAS12_M1PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS12_M2PR                                       8
#define AVR32_HMATRIX_PRAS12_M2PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRAS12_M2PR_OFFSET                                8
#define AVR32_HMATRIX_PRAS12_M2PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS12_M3PR                                      12
#define AVR32_HMATRIX_PRAS12_M3PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRAS12_M3PR_OFFSET                               12
#define AVR32_HMATRIX_PRAS12_M3PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS12_M4PR                                      16
#define AVR32_HMATRIX_PRAS12_M4PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRAS12_M4PR_OFFSET                               16
#define AVR32_HMATRIX_PRAS12_M4PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS12_M5PR                                      20
#define AVR32_HMATRIX_PRAS12_M5PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRAS12_M5PR_OFFSET                               20
#define AVR32_HMATRIX_PRAS12_M5PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS12_M6PR                                      24
#define AVR32_HMATRIX_PRAS12_M6PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRAS12_M6PR_OFFSET                               24
#define AVR32_HMATRIX_PRAS12_M6PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS12_M7PR                                      28
#define AVR32_HMATRIX_PRAS12_M7PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRAS12_M7PR_OFFSET                               28
#define AVR32_HMATRIX_PRAS12_M7PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS13                                   0x000000e8
#define AVR32_HMATRIX_PRAS13_M0PR                                       0
#define AVR32_HMATRIX_PRAS13_M0PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRAS13_M0PR_OFFSET                                0
#define AVR32_HMATRIX_PRAS13_M0PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS13_M1PR                                       4
#define AVR32_HMATRIX_PRAS13_M1PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRAS13_M1PR_OFFSET                                4
#define AVR32_HMATRIX_PRAS13_M1PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS13_M2PR                                       8
#define AVR32_HMATRIX_PRAS13_M2PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRAS13_M2PR_OFFSET                                8
#define AVR32_HMATRIX_PRAS13_M2PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS13_M3PR                                      12
#define AVR32_HMATRIX_PRAS13_M3PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRAS13_M3PR_OFFSET                               12
#define AVR32_HMATRIX_PRAS13_M3PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS13_M4PR                                      16
#define AVR32_HMATRIX_PRAS13_M4PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRAS13_M4PR_OFFSET                               16
#define AVR32_HMATRIX_PRAS13_M4PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS13_M5PR                                      20
#define AVR32_HMATRIX_PRAS13_M5PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRAS13_M5PR_OFFSET                               20
#define AVR32_HMATRIX_PRAS13_M5PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS13_M6PR                                      24
#define AVR32_HMATRIX_PRAS13_M6PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRAS13_M6PR_OFFSET                               24
#define AVR32_HMATRIX_PRAS13_M6PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS13_M7PR                                      28
#define AVR32_HMATRIX_PRAS13_M7PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRAS13_M7PR_OFFSET                               28
#define AVR32_HMATRIX_PRAS13_M7PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS14                                   0x000000f0
#define AVR32_HMATRIX_PRAS14_M0PR                                       0
#define AVR32_HMATRIX_PRAS14_M0PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRAS14_M0PR_OFFSET                                0
#define AVR32_HMATRIX_PRAS14_M0PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS14_M1PR                                       4
#define AVR32_HMATRIX_PRAS14_M1PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRAS14_M1PR_OFFSET                                4
#define AVR32_HMATRIX_PRAS14_M1PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS14_M2PR                                       8
#define AVR32_HMATRIX_PRAS14_M2PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRAS14_M2PR_OFFSET                                8
#define AVR32_HMATRIX_PRAS14_M2PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS14_M3PR                                      12
#define AVR32_HMATRIX_PRAS14_M3PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRAS14_M3PR_OFFSET                               12
#define AVR32_HMATRIX_PRAS14_M3PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS14_M4PR                                      16
#define AVR32_HMATRIX_PRAS14_M4PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRAS14_M4PR_OFFSET                               16
#define AVR32_HMATRIX_PRAS14_M4PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS14_M5PR                                      20
#define AVR32_HMATRIX_PRAS14_M5PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRAS14_M5PR_OFFSET                               20
#define AVR32_HMATRIX_PRAS14_M5PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS14_M6PR                                      24
#define AVR32_HMATRIX_PRAS14_M6PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRAS14_M6PR_OFFSET                               24
#define AVR32_HMATRIX_PRAS14_M6PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS14_M7PR                                      28
#define AVR32_HMATRIX_PRAS14_M7PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRAS14_M7PR_OFFSET                               28
#define AVR32_HMATRIX_PRAS14_M7PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS15                                   0x000000f8
#define AVR32_HMATRIX_PRAS15_M0PR                                       0
#define AVR32_HMATRIX_PRAS15_M0PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRAS15_M0PR_OFFSET                                0
#define AVR32_HMATRIX_PRAS15_M0PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS15_M1PR                                       4
#define AVR32_HMATRIX_PRAS15_M1PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRAS15_M1PR_OFFSET                                4
#define AVR32_HMATRIX_PRAS15_M1PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS15_M2PR                                       8
#define AVR32_HMATRIX_PRAS15_M2PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRAS15_M2PR_OFFSET                                8
#define AVR32_HMATRIX_PRAS15_M2PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS15_M3PR                                      12
#define AVR32_HMATRIX_PRAS15_M3PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRAS15_M3PR_OFFSET                               12
#define AVR32_HMATRIX_PRAS15_M3PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS15_M4PR                                      16
#define AVR32_HMATRIX_PRAS15_M4PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRAS15_M4PR_OFFSET                               16
#define AVR32_HMATRIX_PRAS15_M4PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS15_M5PR                                      20
#define AVR32_HMATRIX_PRAS15_M5PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRAS15_M5PR_OFFSET                               20
#define AVR32_HMATRIX_PRAS15_M5PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS15_M6PR                                      24
#define AVR32_HMATRIX_PRAS15_M6PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRAS15_M6PR_OFFSET                               24
#define AVR32_HMATRIX_PRAS15_M6PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS15_M7PR                                      28
#define AVR32_HMATRIX_PRAS15_M7PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRAS15_M7PR_OFFSET                               28
#define AVR32_HMATRIX_PRAS15_M7PR_SIZE                                  4
#define AVR32_HMATRIX_PRAS1_M0PR                                        0
#define AVR32_HMATRIX_PRAS1_M0PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRAS1_M0PR_OFFSET                                 0
#define AVR32_HMATRIX_PRAS1_M0PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS1_M1PR                                        4
#define AVR32_HMATRIX_PRAS1_M1PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRAS1_M1PR_OFFSET                                 4
#define AVR32_HMATRIX_PRAS1_M1PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS1_M2PR                                        8
#define AVR32_HMATRIX_PRAS1_M2PR_MASK                          0x00000f00
#define AVR32_HMATRIX_PRAS1_M2PR_OFFSET                                 8
#define AVR32_HMATRIX_PRAS1_M2PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS1_M3PR                                       12
#define AVR32_HMATRIX_PRAS1_M3PR_MASK                          0x0000f000
#define AVR32_HMATRIX_PRAS1_M3PR_OFFSET                                12
#define AVR32_HMATRIX_PRAS1_M3PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS1_M4PR                                       16
#define AVR32_HMATRIX_PRAS1_M4PR_MASK                          0x000f0000
#define AVR32_HMATRIX_PRAS1_M4PR_OFFSET                                16
#define AVR32_HMATRIX_PRAS1_M4PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS1_M5PR                                       20
#define AVR32_HMATRIX_PRAS1_M5PR_MASK                          0x00f00000
#define AVR32_HMATRIX_PRAS1_M5PR_OFFSET                                20
#define AVR32_HMATRIX_PRAS1_M5PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS1_M6PR                                       24
#define AVR32_HMATRIX_PRAS1_M6PR_MASK                          0x0f000000
#define AVR32_HMATRIX_PRAS1_M6PR_OFFSET                                24
#define AVR32_HMATRIX_PRAS1_M6PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS1_M7PR                                       28
#define AVR32_HMATRIX_PRAS1_M7PR_MASK                          0xf0000000
#define AVR32_HMATRIX_PRAS1_M7PR_OFFSET                                28
#define AVR32_HMATRIX_PRAS1_M7PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS2                                    0x00000090
#define AVR32_HMATRIX_PRAS2_M0PR                                        0
#define AVR32_HMATRIX_PRAS2_M0PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRAS2_M0PR_OFFSET                                 0
#define AVR32_HMATRIX_PRAS2_M0PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS2_M1PR                                        4
#define AVR32_HMATRIX_PRAS2_M1PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRAS2_M1PR_OFFSET                                 4
#define AVR32_HMATRIX_PRAS2_M1PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS2_M2PR                                        8
#define AVR32_HMATRIX_PRAS2_M2PR_MASK                          0x00000f00
#define AVR32_HMATRIX_PRAS2_M2PR_OFFSET                                 8
#define AVR32_HMATRIX_PRAS2_M2PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS2_M3PR                                       12
#define AVR32_HMATRIX_PRAS2_M3PR_MASK                          0x0000f000
#define AVR32_HMATRIX_PRAS2_M3PR_OFFSET                                12
#define AVR32_HMATRIX_PRAS2_M3PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS2_M4PR                                       16
#define AVR32_HMATRIX_PRAS2_M4PR_MASK                          0x000f0000
#define AVR32_HMATRIX_PRAS2_M4PR_OFFSET                                16
#define AVR32_HMATRIX_PRAS2_M4PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS2_M5PR                                       20
#define AVR32_HMATRIX_PRAS2_M5PR_MASK                          0x00f00000
#define AVR32_HMATRIX_PRAS2_M5PR_OFFSET                                20
#define AVR32_HMATRIX_PRAS2_M5PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS2_M6PR                                       24
#define AVR32_HMATRIX_PRAS2_M6PR_MASK                          0x0f000000
#define AVR32_HMATRIX_PRAS2_M6PR_OFFSET                                24
#define AVR32_HMATRIX_PRAS2_M6PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS2_M7PR                                       28
#define AVR32_HMATRIX_PRAS2_M7PR_MASK                          0xf0000000
#define AVR32_HMATRIX_PRAS2_M7PR_OFFSET                                28
#define AVR32_HMATRIX_PRAS2_M7PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS3                                    0x00000098
#define AVR32_HMATRIX_PRAS3_M0PR                                        0
#define AVR32_HMATRIX_PRAS3_M0PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRAS3_M0PR_OFFSET                                 0
#define AVR32_HMATRIX_PRAS3_M0PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS3_M1PR                                        4
#define AVR32_HMATRIX_PRAS3_M1PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRAS3_M1PR_OFFSET                                 4
#define AVR32_HMATRIX_PRAS3_M1PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS3_M2PR                                        8
#define AVR32_HMATRIX_PRAS3_M2PR_MASK                          0x00000f00
#define AVR32_HMATRIX_PRAS3_M2PR_OFFSET                                 8
#define AVR32_HMATRIX_PRAS3_M2PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS3_M3PR                                       12
#define AVR32_HMATRIX_PRAS3_M3PR_MASK                          0x0000f000
#define AVR32_HMATRIX_PRAS3_M3PR_OFFSET                                12
#define AVR32_HMATRIX_PRAS3_M3PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS3_M4PR                                       16
#define AVR32_HMATRIX_PRAS3_M4PR_MASK                          0x000f0000
#define AVR32_HMATRIX_PRAS3_M4PR_OFFSET                                16
#define AVR32_HMATRIX_PRAS3_M4PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS3_M5PR                                       20
#define AVR32_HMATRIX_PRAS3_M5PR_MASK                          0x00f00000
#define AVR32_HMATRIX_PRAS3_M5PR_OFFSET                                20
#define AVR32_HMATRIX_PRAS3_M5PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS3_M6PR                                       24
#define AVR32_HMATRIX_PRAS3_M6PR_MASK                          0x0f000000
#define AVR32_HMATRIX_PRAS3_M6PR_OFFSET                                24
#define AVR32_HMATRIX_PRAS3_M6PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS3_M7PR                                       28
#define AVR32_HMATRIX_PRAS3_M7PR_MASK                          0xf0000000
#define AVR32_HMATRIX_PRAS3_M7PR_OFFSET                                28
#define AVR32_HMATRIX_PRAS3_M7PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS4                                    0x000000a0
#define AVR32_HMATRIX_PRAS4_M0PR                                        0
#define AVR32_HMATRIX_PRAS4_M0PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRAS4_M0PR_OFFSET                                 0
#define AVR32_HMATRIX_PRAS4_M0PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS4_M1PR                                        4
#define AVR32_HMATRIX_PRAS4_M1PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRAS4_M1PR_OFFSET                                 4
#define AVR32_HMATRIX_PRAS4_M1PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS4_M2PR                                        8
#define AVR32_HMATRIX_PRAS4_M2PR_MASK                          0x00000f00
#define AVR32_HMATRIX_PRAS4_M2PR_OFFSET                                 8
#define AVR32_HMATRIX_PRAS4_M2PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS4_M3PR                                       12
#define AVR32_HMATRIX_PRAS4_M3PR_MASK                          0x0000f000
#define AVR32_HMATRIX_PRAS4_M3PR_OFFSET                                12
#define AVR32_HMATRIX_PRAS4_M3PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS4_M4PR                                       16
#define AVR32_HMATRIX_PRAS4_M4PR_MASK                          0x000f0000
#define AVR32_HMATRIX_PRAS4_M4PR_OFFSET                                16
#define AVR32_HMATRIX_PRAS4_M4PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS4_M5PR                                       20
#define AVR32_HMATRIX_PRAS4_M5PR_MASK                          0x00f00000
#define AVR32_HMATRIX_PRAS4_M5PR_OFFSET                                20
#define AVR32_HMATRIX_PRAS4_M5PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS4_M6PR                                       24
#define AVR32_HMATRIX_PRAS4_M6PR_MASK                          0x0f000000
#define AVR32_HMATRIX_PRAS4_M6PR_OFFSET                                24
#define AVR32_HMATRIX_PRAS4_M6PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS4_M7PR                                       28
#define AVR32_HMATRIX_PRAS4_M7PR_MASK                          0xf0000000
#define AVR32_HMATRIX_PRAS4_M7PR_OFFSET                                28
#define AVR32_HMATRIX_PRAS4_M7PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS5                                    0x000000a8
#define AVR32_HMATRIX_PRAS5_M0PR                                        0
#define AVR32_HMATRIX_PRAS5_M0PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRAS5_M0PR_OFFSET                                 0
#define AVR32_HMATRIX_PRAS5_M0PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS5_M1PR                                        4
#define AVR32_HMATRIX_PRAS5_M1PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRAS5_M1PR_OFFSET                                 4
#define AVR32_HMATRIX_PRAS5_M1PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS5_M2PR                                        8
#define AVR32_HMATRIX_PRAS5_M2PR_MASK                          0x00000f00
#define AVR32_HMATRIX_PRAS5_M2PR_OFFSET                                 8
#define AVR32_HMATRIX_PRAS5_M2PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS5_M3PR                                       12
#define AVR32_HMATRIX_PRAS5_M3PR_MASK                          0x0000f000
#define AVR32_HMATRIX_PRAS5_M3PR_OFFSET                                12
#define AVR32_HMATRIX_PRAS5_M3PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS5_M4PR                                       16
#define AVR32_HMATRIX_PRAS5_M4PR_MASK                          0x000f0000
#define AVR32_HMATRIX_PRAS5_M4PR_OFFSET                                16
#define AVR32_HMATRIX_PRAS5_M4PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS5_M5PR                                       20
#define AVR32_HMATRIX_PRAS5_M5PR_MASK                          0x00f00000
#define AVR32_HMATRIX_PRAS5_M5PR_OFFSET                                20
#define AVR32_HMATRIX_PRAS5_M5PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS5_M6PR                                       24
#define AVR32_HMATRIX_PRAS5_M6PR_MASK                          0x0f000000
#define AVR32_HMATRIX_PRAS5_M6PR_OFFSET                                24
#define AVR32_HMATRIX_PRAS5_M6PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS5_M7PR                                       28
#define AVR32_HMATRIX_PRAS5_M7PR_MASK                          0xf0000000
#define AVR32_HMATRIX_PRAS5_M7PR_OFFSET                                28
#define AVR32_HMATRIX_PRAS5_M7PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS6                                    0x000000b0
#define AVR32_HMATRIX_PRAS6_M0PR                                        0
#define AVR32_HMATRIX_PRAS6_M0PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRAS6_M0PR_OFFSET                                 0
#define AVR32_HMATRIX_PRAS6_M0PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS6_M1PR                                        4
#define AVR32_HMATRIX_PRAS6_M1PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRAS6_M1PR_OFFSET                                 4
#define AVR32_HMATRIX_PRAS6_M1PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS6_M2PR                                        8
#define AVR32_HMATRIX_PRAS6_M2PR_MASK                          0x00000f00
#define AVR32_HMATRIX_PRAS6_M2PR_OFFSET                                 8
#define AVR32_HMATRIX_PRAS6_M2PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS6_M3PR                                       12
#define AVR32_HMATRIX_PRAS6_M3PR_MASK                          0x0000f000
#define AVR32_HMATRIX_PRAS6_M3PR_OFFSET                                12
#define AVR32_HMATRIX_PRAS6_M3PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS6_M4PR                                       16
#define AVR32_HMATRIX_PRAS6_M4PR_MASK                          0x000f0000
#define AVR32_HMATRIX_PRAS6_M4PR_OFFSET                                16
#define AVR32_HMATRIX_PRAS6_M4PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS6_M5PR                                       20
#define AVR32_HMATRIX_PRAS6_M5PR_MASK                          0x00f00000
#define AVR32_HMATRIX_PRAS6_M5PR_OFFSET                                20
#define AVR32_HMATRIX_PRAS6_M5PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS6_M6PR                                       24
#define AVR32_HMATRIX_PRAS6_M6PR_MASK                          0x0f000000
#define AVR32_HMATRIX_PRAS6_M6PR_OFFSET                                24
#define AVR32_HMATRIX_PRAS6_M6PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS6_M7PR                                       28
#define AVR32_HMATRIX_PRAS6_M7PR_MASK                          0xf0000000
#define AVR32_HMATRIX_PRAS6_M7PR_OFFSET                                28
#define AVR32_HMATRIX_PRAS6_M7PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS7                                    0x000000b8
#define AVR32_HMATRIX_PRAS7_M0PR                                        0
#define AVR32_HMATRIX_PRAS7_M0PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRAS7_M0PR_OFFSET                                 0
#define AVR32_HMATRIX_PRAS7_M0PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS7_M1PR                                        4
#define AVR32_HMATRIX_PRAS7_M1PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRAS7_M1PR_OFFSET                                 4
#define AVR32_HMATRIX_PRAS7_M1PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS7_M2PR                                        8
#define AVR32_HMATRIX_PRAS7_M2PR_MASK                          0x00000f00
#define AVR32_HMATRIX_PRAS7_M2PR_OFFSET                                 8
#define AVR32_HMATRIX_PRAS7_M2PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS7_M3PR                                       12
#define AVR32_HMATRIX_PRAS7_M3PR_MASK                          0x0000f000
#define AVR32_HMATRIX_PRAS7_M3PR_OFFSET                                12
#define AVR32_HMATRIX_PRAS7_M3PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS7_M4PR                                       16
#define AVR32_HMATRIX_PRAS7_M4PR_MASK                          0x000f0000
#define AVR32_HMATRIX_PRAS7_M4PR_OFFSET                                16
#define AVR32_HMATRIX_PRAS7_M4PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS7_M5PR                                       20
#define AVR32_HMATRIX_PRAS7_M5PR_MASK                          0x00f00000
#define AVR32_HMATRIX_PRAS7_M5PR_OFFSET                                20
#define AVR32_HMATRIX_PRAS7_M5PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS7_M6PR                                       24
#define AVR32_HMATRIX_PRAS7_M6PR_MASK                          0x0f000000
#define AVR32_HMATRIX_PRAS7_M6PR_OFFSET                                24
#define AVR32_HMATRIX_PRAS7_M6PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS7_M7PR                                       28
#define AVR32_HMATRIX_PRAS7_M7PR_MASK                          0xf0000000
#define AVR32_HMATRIX_PRAS7_M7PR_OFFSET                                28
#define AVR32_HMATRIX_PRAS7_M7PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS8                                    0x000000c0
#define AVR32_HMATRIX_PRAS8_M0PR                                        0
#define AVR32_HMATRIX_PRAS8_M0PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRAS8_M0PR_OFFSET                                 0
#define AVR32_HMATRIX_PRAS8_M0PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS8_M1PR                                        4
#define AVR32_HMATRIX_PRAS8_M1PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRAS8_M1PR_OFFSET                                 4
#define AVR32_HMATRIX_PRAS8_M1PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS8_M2PR                                        8
#define AVR32_HMATRIX_PRAS8_M2PR_MASK                          0x00000f00
#define AVR32_HMATRIX_PRAS8_M2PR_OFFSET                                 8
#define AVR32_HMATRIX_PRAS8_M2PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS8_M3PR                                       12
#define AVR32_HMATRIX_PRAS8_M3PR_MASK                          0x0000f000
#define AVR32_HMATRIX_PRAS8_M3PR_OFFSET                                12
#define AVR32_HMATRIX_PRAS8_M3PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS8_M4PR                                       16
#define AVR32_HMATRIX_PRAS8_M4PR_MASK                          0x000f0000
#define AVR32_HMATRIX_PRAS8_M4PR_OFFSET                                16
#define AVR32_HMATRIX_PRAS8_M4PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS8_M5PR                                       20
#define AVR32_HMATRIX_PRAS8_M5PR_MASK                          0x00f00000
#define AVR32_HMATRIX_PRAS8_M5PR_OFFSET                                20
#define AVR32_HMATRIX_PRAS8_M5PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS8_M6PR                                       24
#define AVR32_HMATRIX_PRAS8_M6PR_MASK                          0x0f000000
#define AVR32_HMATRIX_PRAS8_M6PR_OFFSET                                24
#define AVR32_HMATRIX_PRAS8_M6PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS8_M7PR                                       28
#define AVR32_HMATRIX_PRAS8_M7PR_MASK                          0xf0000000
#define AVR32_HMATRIX_PRAS8_M7PR_OFFSET                                28
#define AVR32_HMATRIX_PRAS8_M7PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS9                                    0x000000c8
#define AVR32_HMATRIX_PRAS9_M0PR                                        0
#define AVR32_HMATRIX_PRAS9_M0PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRAS9_M0PR_OFFSET                                 0
#define AVR32_HMATRIX_PRAS9_M0PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS9_M1PR                                        4
#define AVR32_HMATRIX_PRAS9_M1PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRAS9_M1PR_OFFSET                                 4
#define AVR32_HMATRIX_PRAS9_M1PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS9_M2PR                                        8
#define AVR32_HMATRIX_PRAS9_M2PR_MASK                          0x00000f00
#define AVR32_HMATRIX_PRAS9_M2PR_OFFSET                                 8
#define AVR32_HMATRIX_PRAS9_M2PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS9_M3PR                                       12
#define AVR32_HMATRIX_PRAS9_M3PR_MASK                          0x0000f000
#define AVR32_HMATRIX_PRAS9_M3PR_OFFSET                                12
#define AVR32_HMATRIX_PRAS9_M3PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS9_M4PR                                       16
#define AVR32_HMATRIX_PRAS9_M4PR_MASK                          0x000f0000
#define AVR32_HMATRIX_PRAS9_M4PR_OFFSET                                16
#define AVR32_HMATRIX_PRAS9_M4PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS9_M5PR                                       20
#define AVR32_HMATRIX_PRAS9_M5PR_MASK                          0x00f00000
#define AVR32_HMATRIX_PRAS9_M5PR_OFFSET                                20
#define AVR32_HMATRIX_PRAS9_M5PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS9_M6PR                                       24
#define AVR32_HMATRIX_PRAS9_M6PR_MASK                          0x0f000000
#define AVR32_HMATRIX_PRAS9_M6PR_OFFSET                                24
#define AVR32_HMATRIX_PRAS9_M6PR_SIZE                                   4
#define AVR32_HMATRIX_PRAS9_M7PR                                       28
#define AVR32_HMATRIX_PRAS9_M7PR_MASK                          0xf0000000
#define AVR32_HMATRIX_PRAS9_M7PR_OFFSET                                28
#define AVR32_HMATRIX_PRAS9_M7PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS0                                    0x00000084
#define AVR32_HMATRIX_PRBS0_M10PR                                       8
#define AVR32_HMATRIX_PRBS0_M10PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRBS0_M10PR_OFFSET                                8
#define AVR32_HMATRIX_PRBS0_M10PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS0_M11PR                                      12
#define AVR32_HMATRIX_PRBS0_M11PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRBS0_M11PR_OFFSET                               12
#define AVR32_HMATRIX_PRBS0_M11PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS0_M12PR                                      16
#define AVR32_HMATRIX_PRBS0_M12PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRBS0_M12PR_OFFSET                               16
#define AVR32_HMATRIX_PRBS0_M12PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS0_M13PR                                      20
#define AVR32_HMATRIX_PRBS0_M13PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRBS0_M13PR_OFFSET                               20
#define AVR32_HMATRIX_PRBS0_M13PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS0_M14PR                                      24
#define AVR32_HMATRIX_PRBS0_M14PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRBS0_M14PR_OFFSET                               24
#define AVR32_HMATRIX_PRBS0_M14PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS0_M15PR                                      28
#define AVR32_HMATRIX_PRBS0_M15PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRBS0_M15PR_OFFSET                               28
#define AVR32_HMATRIX_PRBS0_M15PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS0_M8PR                                        0
#define AVR32_HMATRIX_PRBS0_M8PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRBS0_M8PR_OFFSET                                 0
#define AVR32_HMATRIX_PRBS0_M8PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS0_M9PR                                        4
#define AVR32_HMATRIX_PRBS0_M9PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRBS0_M9PR_OFFSET                                 4
#define AVR32_HMATRIX_PRBS0_M9PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS1                                    0x0000008c
#define AVR32_HMATRIX_PRBS10                                   0x000000d4
#define AVR32_HMATRIX_PRBS10_M10PR                                      8
#define AVR32_HMATRIX_PRBS10_M10PR_MASK                        0x00000f00
#define AVR32_HMATRIX_PRBS10_M10PR_OFFSET                               8
#define AVR32_HMATRIX_PRBS10_M10PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS10_M11PR                                     12
#define AVR32_HMATRIX_PRBS10_M11PR_MASK                        0x0000f000
#define AVR32_HMATRIX_PRBS10_M11PR_OFFSET                              12
#define AVR32_HMATRIX_PRBS10_M11PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS10_M12PR                                     16
#define AVR32_HMATRIX_PRBS10_M12PR_MASK                        0x000f0000
#define AVR32_HMATRIX_PRBS10_M12PR_OFFSET                              16
#define AVR32_HMATRIX_PRBS10_M12PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS10_M13PR                                     20
#define AVR32_HMATRIX_PRBS10_M13PR_MASK                        0x00f00000
#define AVR32_HMATRIX_PRBS10_M13PR_OFFSET                              20
#define AVR32_HMATRIX_PRBS10_M13PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS10_M14PR                                     24
#define AVR32_HMATRIX_PRBS10_M14PR_MASK                        0x0f000000
#define AVR32_HMATRIX_PRBS10_M14PR_OFFSET                              24
#define AVR32_HMATRIX_PRBS10_M14PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS10_M15PR                                     28
#define AVR32_HMATRIX_PRBS10_M15PR_MASK                        0xf0000000
#define AVR32_HMATRIX_PRBS10_M15PR_OFFSET                              28
#define AVR32_HMATRIX_PRBS10_M15PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS10_M8PR                                       0
#define AVR32_HMATRIX_PRBS10_M8PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRBS10_M8PR_OFFSET                                0
#define AVR32_HMATRIX_PRBS10_M8PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS10_M9PR                                       4
#define AVR32_HMATRIX_PRBS10_M9PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRBS10_M9PR_OFFSET                                4
#define AVR32_HMATRIX_PRBS10_M9PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS11                                   0x000000dc
#define AVR32_HMATRIX_PRBS11_M10PR                                      8
#define AVR32_HMATRIX_PRBS11_M10PR_MASK                        0x00000f00
#define AVR32_HMATRIX_PRBS11_M10PR_OFFSET                               8
#define AVR32_HMATRIX_PRBS11_M10PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS11_M11PR                                     12
#define AVR32_HMATRIX_PRBS11_M11PR_MASK                        0x0000f000
#define AVR32_HMATRIX_PRBS11_M11PR_OFFSET                              12
#define AVR32_HMATRIX_PRBS11_M11PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS11_M12PR                                     16
#define AVR32_HMATRIX_PRBS11_M12PR_MASK                        0x000f0000
#define AVR32_HMATRIX_PRBS11_M12PR_OFFSET                              16
#define AVR32_HMATRIX_PRBS11_M12PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS11_M13PR                                     20
#define AVR32_HMATRIX_PRBS11_M13PR_MASK                        0x00f00000
#define AVR32_HMATRIX_PRBS11_M13PR_OFFSET                              20
#define AVR32_HMATRIX_PRBS11_M13PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS11_M14PR                                     24
#define AVR32_HMATRIX_PRBS11_M14PR_MASK                        0x0f000000
#define AVR32_HMATRIX_PRBS11_M14PR_OFFSET                              24
#define AVR32_HMATRIX_PRBS11_M14PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS11_M15PR                                     28
#define AVR32_HMATRIX_PRBS11_M15PR_MASK                        0xf0000000
#define AVR32_HMATRIX_PRBS11_M15PR_OFFSET                              28
#define AVR32_HMATRIX_PRBS11_M15PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS11_M8PR                                       0
#define AVR32_HMATRIX_PRBS11_M8PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRBS11_M8PR_OFFSET                                0
#define AVR32_HMATRIX_PRBS11_M8PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS11_M9PR                                       4
#define AVR32_HMATRIX_PRBS11_M9PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRBS11_M9PR_OFFSET                                4
#define AVR32_HMATRIX_PRBS11_M9PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS12                                   0x000000e4
#define AVR32_HMATRIX_PRBS12_M10PR                                      8
#define AVR32_HMATRIX_PRBS12_M10PR_MASK                        0x00000f00
#define AVR32_HMATRIX_PRBS12_M10PR_OFFSET                               8
#define AVR32_HMATRIX_PRBS12_M10PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS12_M11PR                                     12
#define AVR32_HMATRIX_PRBS12_M11PR_MASK                        0x0000f000
#define AVR32_HMATRIX_PRBS12_M11PR_OFFSET                              12
#define AVR32_HMATRIX_PRBS12_M11PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS12_M12PR                                     16
#define AVR32_HMATRIX_PRBS12_M12PR_MASK                        0x000f0000
#define AVR32_HMATRIX_PRBS12_M12PR_OFFSET                              16
#define AVR32_HMATRIX_PRBS12_M12PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS12_M13PR                                     20
#define AVR32_HMATRIX_PRBS12_M13PR_MASK                        0x00f00000
#define AVR32_HMATRIX_PRBS12_M13PR_OFFSET                              20
#define AVR32_HMATRIX_PRBS12_M13PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS12_M14PR                                     24
#define AVR32_HMATRIX_PRBS12_M14PR_MASK                        0x0f000000
#define AVR32_HMATRIX_PRBS12_M14PR_OFFSET                              24
#define AVR32_HMATRIX_PRBS12_M14PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS12_M15PR                                     28
#define AVR32_HMATRIX_PRBS12_M15PR_MASK                        0xf0000000
#define AVR32_HMATRIX_PRBS12_M15PR_OFFSET                              28
#define AVR32_HMATRIX_PRBS12_M15PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS12_M8PR                                       0
#define AVR32_HMATRIX_PRBS12_M8PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRBS12_M8PR_OFFSET                                0
#define AVR32_HMATRIX_PRBS12_M8PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS12_M9PR                                       4
#define AVR32_HMATRIX_PRBS12_M9PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRBS12_M9PR_OFFSET                                4
#define AVR32_HMATRIX_PRBS12_M9PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS13                                   0x000000ec
#define AVR32_HMATRIX_PRBS13_M10PR                                      8
#define AVR32_HMATRIX_PRBS13_M10PR_MASK                        0x00000f00
#define AVR32_HMATRIX_PRBS13_M10PR_OFFSET                               8
#define AVR32_HMATRIX_PRBS13_M10PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS13_M11PR                                     12
#define AVR32_HMATRIX_PRBS13_M11PR_MASK                        0x0000f000
#define AVR32_HMATRIX_PRBS13_M11PR_OFFSET                              12
#define AVR32_HMATRIX_PRBS13_M11PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS13_M12PR                                     16
#define AVR32_HMATRIX_PRBS13_M12PR_MASK                        0x000f0000
#define AVR32_HMATRIX_PRBS13_M12PR_OFFSET                              16
#define AVR32_HMATRIX_PRBS13_M12PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS13_M13PR                                     20
#define AVR32_HMATRIX_PRBS13_M13PR_MASK                        0x00f00000
#define AVR32_HMATRIX_PRBS13_M13PR_OFFSET                              20
#define AVR32_HMATRIX_PRBS13_M13PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS13_M14PR                                     24
#define AVR32_HMATRIX_PRBS13_M14PR_MASK                        0x0f000000
#define AVR32_HMATRIX_PRBS13_M14PR_OFFSET                              24
#define AVR32_HMATRIX_PRBS13_M14PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS13_M15PR                                     28
#define AVR32_HMATRIX_PRBS13_M15PR_MASK                        0xf0000000
#define AVR32_HMATRIX_PRBS13_M15PR_OFFSET                              28
#define AVR32_HMATRIX_PRBS13_M15PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS13_M8PR                                       0
#define AVR32_HMATRIX_PRBS13_M8PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRBS13_M8PR_OFFSET                                0
#define AVR32_HMATRIX_PRBS13_M8PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS13_M9PR                                       4
#define AVR32_HMATRIX_PRBS13_M9PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRBS13_M9PR_OFFSET                                4
#define AVR32_HMATRIX_PRBS13_M9PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS14                                   0x000000f4
#define AVR32_HMATRIX_PRBS14_M10PR                                      8
#define AVR32_HMATRIX_PRBS14_M10PR_MASK                        0x00000f00
#define AVR32_HMATRIX_PRBS14_M10PR_OFFSET                               8
#define AVR32_HMATRIX_PRBS14_M10PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS14_M11PR                                     12
#define AVR32_HMATRIX_PRBS14_M11PR_MASK                        0x0000f000
#define AVR32_HMATRIX_PRBS14_M11PR_OFFSET                              12
#define AVR32_HMATRIX_PRBS14_M11PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS14_M12PR                                     16
#define AVR32_HMATRIX_PRBS14_M12PR_MASK                        0x000f0000
#define AVR32_HMATRIX_PRBS14_M12PR_OFFSET                              16
#define AVR32_HMATRIX_PRBS14_M12PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS14_M13PR                                     20
#define AVR32_HMATRIX_PRBS14_M13PR_MASK                        0x00f00000
#define AVR32_HMATRIX_PRBS14_M13PR_OFFSET                              20
#define AVR32_HMATRIX_PRBS14_M13PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS14_M14PR                                     24
#define AVR32_HMATRIX_PRBS14_M14PR_MASK                        0x0f000000
#define AVR32_HMATRIX_PRBS14_M14PR_OFFSET                              24
#define AVR32_HMATRIX_PRBS14_M14PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS14_M15PR                                     28
#define AVR32_HMATRIX_PRBS14_M15PR_MASK                        0xf0000000
#define AVR32_HMATRIX_PRBS14_M15PR_OFFSET                              28
#define AVR32_HMATRIX_PRBS14_M15PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS14_M8PR                                       0
#define AVR32_HMATRIX_PRBS14_M8PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRBS14_M8PR_OFFSET                                0
#define AVR32_HMATRIX_PRBS14_M8PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS14_M9PR                                       4
#define AVR32_HMATRIX_PRBS14_M9PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRBS14_M9PR_OFFSET                                4
#define AVR32_HMATRIX_PRBS14_M9PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS15                                   0x000000fc
#define AVR32_HMATRIX_PRBS15_M10PR                                      8
#define AVR32_HMATRIX_PRBS15_M10PR_MASK                        0x00000f00
#define AVR32_HMATRIX_PRBS15_M10PR_OFFSET                               8
#define AVR32_HMATRIX_PRBS15_M10PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS15_M11PR                                     12
#define AVR32_HMATRIX_PRBS15_M11PR_MASK                        0x0000f000
#define AVR32_HMATRIX_PRBS15_M11PR_OFFSET                              12
#define AVR32_HMATRIX_PRBS15_M11PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS15_M12PR                                     16
#define AVR32_HMATRIX_PRBS15_M12PR_MASK                        0x000f0000
#define AVR32_HMATRIX_PRBS15_M12PR_OFFSET                              16
#define AVR32_HMATRIX_PRBS15_M12PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS15_M13PR                                     20
#define AVR32_HMATRIX_PRBS15_M13PR_MASK                        0x00f00000
#define AVR32_HMATRIX_PRBS15_M13PR_OFFSET                              20
#define AVR32_HMATRIX_PRBS15_M13PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS15_M14PR                                     24
#define AVR32_HMATRIX_PRBS15_M14PR_MASK                        0x0f000000
#define AVR32_HMATRIX_PRBS15_M14PR_OFFSET                              24
#define AVR32_HMATRIX_PRBS15_M14PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS15_M15PR                                     28
#define AVR32_HMATRIX_PRBS15_M15PR_MASK                        0xf0000000
#define AVR32_HMATRIX_PRBS15_M15PR_OFFSET                              28
#define AVR32_HMATRIX_PRBS15_M15PR_SIZE                                 4
#define AVR32_HMATRIX_PRBS15_M8PR                                       0
#define AVR32_HMATRIX_PRBS15_M8PR_MASK                         0x0000000f
#define AVR32_HMATRIX_PRBS15_M8PR_OFFSET                                0
#define AVR32_HMATRIX_PRBS15_M8PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS15_M9PR                                       4
#define AVR32_HMATRIX_PRBS15_M9PR_MASK                         0x000000f0
#define AVR32_HMATRIX_PRBS15_M9PR_OFFSET                                4
#define AVR32_HMATRIX_PRBS15_M9PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS1_M10PR                                       8
#define AVR32_HMATRIX_PRBS1_M10PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRBS1_M10PR_OFFSET                                8
#define AVR32_HMATRIX_PRBS1_M10PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS1_M11PR                                      12
#define AVR32_HMATRIX_PRBS1_M11PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRBS1_M11PR_OFFSET                               12
#define AVR32_HMATRIX_PRBS1_M11PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS1_M12PR                                      16
#define AVR32_HMATRIX_PRBS1_M12PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRBS1_M12PR_OFFSET                               16
#define AVR32_HMATRIX_PRBS1_M12PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS1_M13PR                                      20
#define AVR32_HMATRIX_PRBS1_M13PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRBS1_M13PR_OFFSET                               20
#define AVR32_HMATRIX_PRBS1_M13PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS1_M14PR                                      24
#define AVR32_HMATRIX_PRBS1_M14PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRBS1_M14PR_OFFSET                               24
#define AVR32_HMATRIX_PRBS1_M14PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS1_M15PR                                      28
#define AVR32_HMATRIX_PRBS1_M15PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRBS1_M15PR_OFFSET                               28
#define AVR32_HMATRIX_PRBS1_M15PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS1_M8PR                                        0
#define AVR32_HMATRIX_PRBS1_M8PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRBS1_M8PR_OFFSET                                 0
#define AVR32_HMATRIX_PRBS1_M8PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS1_M9PR                                        4
#define AVR32_HMATRIX_PRBS1_M9PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRBS1_M9PR_OFFSET                                 4
#define AVR32_HMATRIX_PRBS1_M9PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS2                                    0x00000094
#define AVR32_HMATRIX_PRBS2_M10PR                                       8
#define AVR32_HMATRIX_PRBS2_M10PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRBS2_M10PR_OFFSET                                8
#define AVR32_HMATRIX_PRBS2_M10PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS2_M11PR                                      12
#define AVR32_HMATRIX_PRBS2_M11PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRBS2_M11PR_OFFSET                               12
#define AVR32_HMATRIX_PRBS2_M11PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS2_M12PR                                      16
#define AVR32_HMATRIX_PRBS2_M12PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRBS2_M12PR_OFFSET                               16
#define AVR32_HMATRIX_PRBS2_M12PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS2_M13PR                                      20
#define AVR32_HMATRIX_PRBS2_M13PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRBS2_M13PR_OFFSET                               20
#define AVR32_HMATRIX_PRBS2_M13PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS2_M14PR                                      24
#define AVR32_HMATRIX_PRBS2_M14PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRBS2_M14PR_OFFSET                               24
#define AVR32_HMATRIX_PRBS2_M14PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS2_M15PR                                      28
#define AVR32_HMATRIX_PRBS2_M15PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRBS2_M15PR_OFFSET                               28
#define AVR32_HMATRIX_PRBS2_M15PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS2_M8PR                                        0
#define AVR32_HMATRIX_PRBS2_M8PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRBS2_M8PR_OFFSET                                 0
#define AVR32_HMATRIX_PRBS2_M8PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS2_M9PR                                        4
#define AVR32_HMATRIX_PRBS2_M9PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRBS2_M9PR_OFFSET                                 4
#define AVR32_HMATRIX_PRBS2_M9PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS3                                    0x0000009c
#define AVR32_HMATRIX_PRBS3_M10PR                                       8
#define AVR32_HMATRIX_PRBS3_M10PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRBS3_M10PR_OFFSET                                8
#define AVR32_HMATRIX_PRBS3_M10PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS3_M11PR                                      12
#define AVR32_HMATRIX_PRBS3_M11PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRBS3_M11PR_OFFSET                               12
#define AVR32_HMATRIX_PRBS3_M11PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS3_M12PR                                      16
#define AVR32_HMATRIX_PRBS3_M12PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRBS3_M12PR_OFFSET                               16
#define AVR32_HMATRIX_PRBS3_M12PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS3_M13PR                                      20
#define AVR32_HMATRIX_PRBS3_M13PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRBS3_M13PR_OFFSET                               20
#define AVR32_HMATRIX_PRBS3_M13PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS3_M14PR                                      24
#define AVR32_HMATRIX_PRBS3_M14PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRBS3_M14PR_OFFSET                               24
#define AVR32_HMATRIX_PRBS3_M14PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS3_M15PR                                      28
#define AVR32_HMATRIX_PRBS3_M15PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRBS3_M15PR_OFFSET                               28
#define AVR32_HMATRIX_PRBS3_M15PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS3_M8PR                                        0
#define AVR32_HMATRIX_PRBS3_M8PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRBS3_M8PR_OFFSET                                 0
#define AVR32_HMATRIX_PRBS3_M8PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS3_M9PR                                        4
#define AVR32_HMATRIX_PRBS3_M9PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRBS3_M9PR_OFFSET                                 4
#define AVR32_HMATRIX_PRBS3_M9PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS4                                    0x000000a4
#define AVR32_HMATRIX_PRBS4_M10PR                                       8
#define AVR32_HMATRIX_PRBS4_M10PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRBS4_M10PR_OFFSET                                8
#define AVR32_HMATRIX_PRBS4_M10PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS4_M11PR                                      12
#define AVR32_HMATRIX_PRBS4_M11PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRBS4_M11PR_OFFSET                               12
#define AVR32_HMATRIX_PRBS4_M11PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS4_M12PR                                      16
#define AVR32_HMATRIX_PRBS4_M12PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRBS4_M12PR_OFFSET                               16
#define AVR32_HMATRIX_PRBS4_M12PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS4_M13PR                                      20
#define AVR32_HMATRIX_PRBS4_M13PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRBS4_M13PR_OFFSET                               20
#define AVR32_HMATRIX_PRBS4_M13PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS4_M14PR                                      24
#define AVR32_HMATRIX_PRBS4_M14PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRBS4_M14PR_OFFSET                               24
#define AVR32_HMATRIX_PRBS4_M14PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS4_M15PR                                      28
#define AVR32_HMATRIX_PRBS4_M15PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRBS4_M15PR_OFFSET                               28
#define AVR32_HMATRIX_PRBS4_M15PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS4_M8PR                                        0
#define AVR32_HMATRIX_PRBS4_M8PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRBS4_M8PR_OFFSET                                 0
#define AVR32_HMATRIX_PRBS4_M8PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS4_M9PR                                        4
#define AVR32_HMATRIX_PRBS4_M9PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRBS4_M9PR_OFFSET                                 4
#define AVR32_HMATRIX_PRBS4_M9PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS5                                    0x000000ac
#define AVR32_HMATRIX_PRBS5_M10PR                                       8
#define AVR32_HMATRIX_PRBS5_M10PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRBS5_M10PR_OFFSET                                8
#define AVR32_HMATRIX_PRBS5_M10PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS5_M11PR                                      12
#define AVR32_HMATRIX_PRBS5_M11PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRBS5_M11PR_OFFSET                               12
#define AVR32_HMATRIX_PRBS5_M11PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS5_M12PR                                      16
#define AVR32_HMATRIX_PRBS5_M12PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRBS5_M12PR_OFFSET                               16
#define AVR32_HMATRIX_PRBS5_M12PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS5_M13PR                                      20
#define AVR32_HMATRIX_PRBS5_M13PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRBS5_M13PR_OFFSET                               20
#define AVR32_HMATRIX_PRBS5_M13PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS5_M14PR                                      24
#define AVR32_HMATRIX_PRBS5_M14PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRBS5_M14PR_OFFSET                               24
#define AVR32_HMATRIX_PRBS5_M14PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS5_M15PR                                      28
#define AVR32_HMATRIX_PRBS5_M15PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRBS5_M15PR_OFFSET                               28
#define AVR32_HMATRIX_PRBS5_M15PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS5_M8PR                                        0
#define AVR32_HMATRIX_PRBS5_M8PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRBS5_M8PR_OFFSET                                 0
#define AVR32_HMATRIX_PRBS5_M8PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS5_M9PR                                        4
#define AVR32_HMATRIX_PRBS5_M9PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRBS5_M9PR_OFFSET                                 4
#define AVR32_HMATRIX_PRBS5_M9PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS6                                    0x000000b4
#define AVR32_HMATRIX_PRBS6_M10PR                                       8
#define AVR32_HMATRIX_PRBS6_M10PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRBS6_M10PR_OFFSET                                8
#define AVR32_HMATRIX_PRBS6_M10PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS6_M11PR                                      12
#define AVR32_HMATRIX_PRBS6_M11PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRBS6_M11PR_OFFSET                               12
#define AVR32_HMATRIX_PRBS6_M11PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS6_M12PR                                      16
#define AVR32_HMATRIX_PRBS6_M12PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRBS6_M12PR_OFFSET                               16
#define AVR32_HMATRIX_PRBS6_M12PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS6_M13PR                                      20
#define AVR32_HMATRIX_PRBS6_M13PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRBS6_M13PR_OFFSET                               20
#define AVR32_HMATRIX_PRBS6_M13PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS6_M14PR                                      24
#define AVR32_HMATRIX_PRBS6_M14PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRBS6_M14PR_OFFSET                               24
#define AVR32_HMATRIX_PRBS6_M14PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS6_M15PR                                      28
#define AVR32_HMATRIX_PRBS6_M15PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRBS6_M15PR_OFFSET                               28
#define AVR32_HMATRIX_PRBS6_M15PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS6_M8PR                                        0
#define AVR32_HMATRIX_PRBS6_M8PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRBS6_M8PR_OFFSET                                 0
#define AVR32_HMATRIX_PRBS6_M8PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS6_M9PR                                        4
#define AVR32_HMATRIX_PRBS6_M9PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRBS6_M9PR_OFFSET                                 4
#define AVR32_HMATRIX_PRBS6_M9PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS7                                    0x000000bc
#define AVR32_HMATRIX_PRBS7_M10PR                                       8
#define AVR32_HMATRIX_PRBS7_M10PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRBS7_M10PR_OFFSET                                8
#define AVR32_HMATRIX_PRBS7_M10PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS7_M11PR                                      12
#define AVR32_HMATRIX_PRBS7_M11PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRBS7_M11PR_OFFSET                               12
#define AVR32_HMATRIX_PRBS7_M11PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS7_M12PR                                      16
#define AVR32_HMATRIX_PRBS7_M12PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRBS7_M12PR_OFFSET                               16
#define AVR32_HMATRIX_PRBS7_M12PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS7_M13PR                                      20
#define AVR32_HMATRIX_PRBS7_M13PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRBS7_M13PR_OFFSET                               20
#define AVR32_HMATRIX_PRBS7_M13PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS7_M14PR                                      24
#define AVR32_HMATRIX_PRBS7_M14PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRBS7_M14PR_OFFSET                               24
#define AVR32_HMATRIX_PRBS7_M14PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS7_M15PR                                      28
#define AVR32_HMATRIX_PRBS7_M15PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRBS7_M15PR_OFFSET                               28
#define AVR32_HMATRIX_PRBS7_M15PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS7_M8PR                                        0
#define AVR32_HMATRIX_PRBS7_M8PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRBS7_M8PR_OFFSET                                 0
#define AVR32_HMATRIX_PRBS7_M8PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS7_M9PR                                        4
#define AVR32_HMATRIX_PRBS7_M9PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRBS7_M9PR_OFFSET                                 4
#define AVR32_HMATRIX_PRBS7_M9PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS8                                    0x000000c4
#define AVR32_HMATRIX_PRBS8_M10PR                                       8
#define AVR32_HMATRIX_PRBS8_M10PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRBS8_M10PR_OFFSET                                8
#define AVR32_HMATRIX_PRBS8_M10PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS8_M11PR                                      12
#define AVR32_HMATRIX_PRBS8_M11PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRBS8_M11PR_OFFSET                               12
#define AVR32_HMATRIX_PRBS8_M11PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS8_M12PR                                      16
#define AVR32_HMATRIX_PRBS8_M12PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRBS8_M12PR_OFFSET                               16
#define AVR32_HMATRIX_PRBS8_M12PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS8_M13PR                                      20
#define AVR32_HMATRIX_PRBS8_M13PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRBS8_M13PR_OFFSET                               20
#define AVR32_HMATRIX_PRBS8_M13PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS8_M14PR                                      24
#define AVR32_HMATRIX_PRBS8_M14PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRBS8_M14PR_OFFSET                               24
#define AVR32_HMATRIX_PRBS8_M14PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS8_M15PR                                      28
#define AVR32_HMATRIX_PRBS8_M15PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRBS8_M15PR_OFFSET                               28
#define AVR32_HMATRIX_PRBS8_M15PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS8_M8PR                                        0
#define AVR32_HMATRIX_PRBS8_M8PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRBS8_M8PR_OFFSET                                 0
#define AVR32_HMATRIX_PRBS8_M8PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS8_M9PR                                        4
#define AVR32_HMATRIX_PRBS8_M9PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRBS8_M9PR_OFFSET                                 4
#define AVR32_HMATRIX_PRBS8_M9PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS9                                    0x000000cc
#define AVR32_HMATRIX_PRBS9_M10PR                                       8
#define AVR32_HMATRIX_PRBS9_M10PR_MASK                         0x00000f00
#define AVR32_HMATRIX_PRBS9_M10PR_OFFSET                                8
#define AVR32_HMATRIX_PRBS9_M10PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS9_M11PR                                      12
#define AVR32_HMATRIX_PRBS9_M11PR_MASK                         0x0000f000
#define AVR32_HMATRIX_PRBS9_M11PR_OFFSET                               12
#define AVR32_HMATRIX_PRBS9_M11PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS9_M12PR                                      16
#define AVR32_HMATRIX_PRBS9_M12PR_MASK                         0x000f0000
#define AVR32_HMATRIX_PRBS9_M12PR_OFFSET                               16
#define AVR32_HMATRIX_PRBS9_M12PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS9_M13PR                                      20
#define AVR32_HMATRIX_PRBS9_M13PR_MASK                         0x00f00000
#define AVR32_HMATRIX_PRBS9_M13PR_OFFSET                               20
#define AVR32_HMATRIX_PRBS9_M13PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS9_M14PR                                      24
#define AVR32_HMATRIX_PRBS9_M14PR_MASK                         0x0f000000
#define AVR32_HMATRIX_PRBS9_M14PR_OFFSET                               24
#define AVR32_HMATRIX_PRBS9_M14PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS9_M15PR                                      28
#define AVR32_HMATRIX_PRBS9_M15PR_MASK                         0xf0000000
#define AVR32_HMATRIX_PRBS9_M15PR_OFFSET                               28
#define AVR32_HMATRIX_PRBS9_M15PR_SIZE                                  4
#define AVR32_HMATRIX_PRBS9_M8PR                                        0
#define AVR32_HMATRIX_PRBS9_M8PR_MASK                          0x0000000f
#define AVR32_HMATRIX_PRBS9_M8PR_OFFSET                                 0
#define AVR32_HMATRIX_PRBS9_M8PR_SIZE                                   4
#define AVR32_HMATRIX_PRBS9_M9PR                                        4
#define AVR32_HMATRIX_PRBS9_M9PR_MASK                          0x000000f0
#define AVR32_HMATRIX_PRBS9_M9PR_OFFSET                                 4
#define AVR32_HMATRIX_PRBS9_M9PR_SIZE                                   4
#define AVR32_HMATRIX_RCB0                                              0
#define AVR32_HMATRIX_RCB0_MASK                                0x00000001
#define AVR32_HMATRIX_RCB0_OFFSET                                       0
#define AVR32_HMATRIX_RCB0_SIZE                                         1
#define AVR32_HMATRIX_RCB1                                              1
#define AVR32_HMATRIX_RCB10                                            10
#define AVR32_HMATRIX_RCB10_MASK                               0x00000400
#define AVR32_HMATRIX_RCB10_OFFSET                                     10
#define AVR32_HMATRIX_RCB10_SIZE                                        1
#define AVR32_HMATRIX_RCB11                                            11
#define AVR32_HMATRIX_RCB11_MASK                               0x00000800
#define AVR32_HMATRIX_RCB11_OFFSET                                     11
#define AVR32_HMATRIX_RCB11_SIZE                                        1
#define AVR32_HMATRIX_RCB12                                            12
#define AVR32_HMATRIX_RCB12_MASK                               0x00001000
#define AVR32_HMATRIX_RCB12_OFFSET                                     12
#define AVR32_HMATRIX_RCB12_SIZE                                        1
#define AVR32_HMATRIX_RCB13                                            13
#define AVR32_HMATRIX_RCB13_MASK                               0x00002000
#define AVR32_HMATRIX_RCB13_OFFSET                                     13
#define AVR32_HMATRIX_RCB13_SIZE                                        1
#define AVR32_HMATRIX_RCB14                                            14
#define AVR32_HMATRIX_RCB14_MASK                               0x00004000
#define AVR32_HMATRIX_RCB14_OFFSET                                     14
#define AVR32_HMATRIX_RCB14_SIZE                                        1
#define AVR32_HMATRIX_RCB15                                            15
#define AVR32_HMATRIX_RCB15_MASK                               0x00008000
#define AVR32_HMATRIX_RCB15_OFFSET                                     15
#define AVR32_HMATRIX_RCB15_SIZE                                        1
#define AVR32_HMATRIX_RCB1_MASK                                0x00000002
#define AVR32_HMATRIX_RCB1_OFFSET                                       1
#define AVR32_HMATRIX_RCB1_SIZE                                         1
#define AVR32_HMATRIX_RCB2                                              2
#define AVR32_HMATRIX_RCB2_MASK                                0x00000004
#define AVR32_HMATRIX_RCB2_OFFSET                                       2
#define AVR32_HMATRIX_RCB2_SIZE                                         1
#define AVR32_HMATRIX_RCB3                                              3
#define AVR32_HMATRIX_RCB3_MASK                                0x00000008
#define AVR32_HMATRIX_RCB3_OFFSET                                       3
#define AVR32_HMATRIX_RCB3_SIZE                                         1
#define AVR32_HMATRIX_RCB4                                              4
#define AVR32_HMATRIX_RCB4_MASK                                0x00000010
#define AVR32_HMATRIX_RCB4_OFFSET                                       4
#define AVR32_HMATRIX_RCB4_SIZE                                         1
#define AVR32_HMATRIX_RCB5                                              5
#define AVR32_HMATRIX_RCB5_MASK                                0x00000020
#define AVR32_HMATRIX_RCB5_OFFSET                                       5
#define AVR32_HMATRIX_RCB5_SIZE                                         1
#define AVR32_HMATRIX_RCB6                                              6
#define AVR32_HMATRIX_RCB6_MASK                                0x00000040
#define AVR32_HMATRIX_RCB6_OFFSET                                       6
#define AVR32_HMATRIX_RCB6_SIZE                                         1
#define AVR32_HMATRIX_RCB7                                              7
#define AVR32_HMATRIX_RCB7_MASK                                0x00000080
#define AVR32_HMATRIX_RCB7_OFFSET                                       7
#define AVR32_HMATRIX_RCB7_SIZE                                         1
#define AVR32_HMATRIX_RCB8                                              8
#define AVR32_HMATRIX_RCB8_MASK                                0x00000100
#define AVR32_HMATRIX_RCB8_OFFSET                                       8
#define AVR32_HMATRIX_RCB8_SIZE                                         1
#define AVR32_HMATRIX_RCB9                                              9
#define AVR32_HMATRIX_RCB9_MASK                                0x00000200
#define AVR32_HMATRIX_RCB9_OFFSET                                       9
#define AVR32_HMATRIX_RCB9_SIZE                                         1
#define AVR32_HMATRIX_ROUND_ROBIN                              0x00000000
#define AVR32_HMATRIX_SCFG0                                    0x00000040
#define AVR32_HMATRIX_SCFG0_ARBT                                       24
#define AVR32_HMATRIX_SCFG0_ARBT_FIXED_PRIORITY                0x00000001
#define AVR32_HMATRIX_SCFG0_ARBT_MASK                          0x01000000
#define AVR32_HMATRIX_SCFG0_ARBT_OFFSET                                24
#define AVR32_HMATRIX_SCFG0_ARBT_ROUND_ROBIN                   0x00000000
#define AVR32_HMATRIX_SCFG0_ARBT_SIZE                                   1
#define AVR32_HMATRIX_SCFG0_DEFMSTR_TYPE                               16
#define AVR32_HMATRIX_SCFG0_DEFMSTR_TYPE_FIXED_DEFAULT         0x00000002
#define AVR32_HMATRIX_SCFG0_DEFMSTR_TYPE_LAST_DEFAULT          0x00000001
#define AVR32_HMATRIX_SCFG0_DEFMSTR_TYPE_MASK                  0x00030000
#define AVR32_HMATRIX_SCFG0_DEFMSTR_TYPE_NO_DEFAULT            0x00000000
#define AVR32_HMATRIX_SCFG0_DEFMSTR_TYPE_OFFSET                        16
#define AVR32_HMATRIX_SCFG0_DEFMSTR_TYPE_SIZE                           2
#define AVR32_HMATRIX_SCFG0_FIXED_DEFMSTR                              18
#define AVR32_HMATRIX_SCFG0_FIXED_DEFMSTR_MASK                 0x003c0000
#define AVR32_HMATRIX_SCFG0_FIXED_DEFMSTR_OFFSET                       18
#define AVR32_HMATRIX_SCFG0_FIXED_DEFMSTR_SIZE                          4
#define AVR32_HMATRIX_SCFG0_SLOT_CYCLE                                  0
#define AVR32_HMATRIX_SCFG0_SLOT_CYCLE_MASK                    0x000000ff
#define AVR32_HMATRIX_SCFG0_SLOT_CYCLE_OFFSET                           0
#define AVR32_HMATRIX_SCFG0_SLOT_CYCLE_SIZE                             8
#define AVR32_HMATRIX_SCFG1                                    0x00000044
#define AVR32_HMATRIX_SCFG10                                   0x00000068
#define AVR32_HMATRIX_SCFG10_ARBT                                      24
#define AVR32_HMATRIX_SCFG10_ARBT_FIXED_PRIORITY               0x00000001
#define AVR32_HMATRIX_SCFG10_ARBT_MASK                         0x01000000
#define AVR32_HMATRIX_SCFG10_ARBT_OFFSET                               24
#define AVR32_HMATRIX_SCFG10_ARBT_ROUND_ROBIN                  0x00000000
#define AVR32_HMATRIX_SCFG10_ARBT_SIZE                                  1
#define AVR32_HMATRIX_SCFG10_DEFMSTR_TYPE                              16
#define AVR32_HMATRIX_SCFG10_DEFMSTR_TYPE_FIXED_DEFAULT        0x00000002
#define AVR32_HMATRIX_SCFG10_DEFMSTR_TYPE_LAST_DEFAULT         0x00000001
#define AVR32_HMATRIX_SCFG10_DEFMSTR_TYPE_MASK                 0x00030000
#define AVR32_HMATRIX_SCFG10_DEFMSTR_TYPE_NO_DEFAULT           0x00000000
#define AVR32_HMATRIX_SCFG10_DEFMSTR_TYPE_OFFSET                       16
#define AVR32_HMATRIX_SCFG10_DEFMSTR_TYPE_SIZE                          2
#define AVR32_HMATRIX_SCFG10_FIXED_DEFMSTR                             18
#define AVR32_HMATRIX_SCFG10_FIXED_DEFMSTR_MASK                0x003c0000
#define AVR32_HMATRIX_SCFG10_FIXED_DEFMSTR_OFFSET                      18
#define AVR32_HMATRIX_SCFG10_FIXED_DEFMSTR_SIZE                         4
#define AVR32_HMATRIX_SCFG10_SLOT_CYCLE                                 0
#define AVR32_HMATRIX_SCFG10_SLOT_CYCLE_MASK                   0x000000ff
#define AVR32_HMATRIX_SCFG10_SLOT_CYCLE_OFFSET                          0
#define AVR32_HMATRIX_SCFG10_SLOT_CYCLE_SIZE                            8
#define AVR32_HMATRIX_SCFG11                                   0x0000006c
#define AVR32_HMATRIX_SCFG11_ARBT                                      24
#define AVR32_HMATRIX_SCFG11_ARBT_FIXED_PRIORITY               0x00000001
#define AVR32_HMATRIX_SCFG11_ARBT_MASK                         0x01000000
#define AVR32_HMATRIX_SCFG11_ARBT_OFFSET                               24
#define AVR32_HMATRIX_SCFG11_ARBT_ROUND_ROBIN                  0x00000000
#define AVR32_HMATRIX_SCFG11_ARBT_SIZE                                  1
#define AVR32_HMATRIX_SCFG11_DEFMSTR_TYPE                              16
#define AVR32_HMATRIX_SCFG11_DEFMSTR_TYPE_FIXED_DEFAULT        0x00000002
#define AVR32_HMATRIX_SCFG11_DEFMSTR_TYPE_LAST_DEFAULT         0x00000001
#define AVR32_HMATRIX_SCFG11_DEFMSTR_TYPE_MASK                 0x00030000
#define AVR32_HMATRIX_SCFG11_DEFMSTR_TYPE_NO_DEFAULT           0x00000000
#define AVR32_HMATRIX_SCFG11_DEFMSTR_TYPE_OFFSET                       16
#define AVR32_HMATRIX_SCFG11_DEFMSTR_TYPE_SIZE                          2
#define AVR32_HMATRIX_SCFG11_FIXED_DEFMSTR                             18
#define AVR32_HMATRIX_SCFG11_FIXED_DEFMSTR_MASK                0x003c0000
#define AVR32_HMATRIX_SCFG11_FIXED_DEFMSTR_OFFSET                      18
#define AVR32_HMATRIX_SCFG11_FIXED_DEFMSTR_SIZE                         4
#define AVR32_HMATRIX_SCFG11_SLOT_CYCLE                                 0
#define AVR32_HMATRIX_SCFG11_SLOT_CYCLE_MASK                   0x000000ff
#define AVR32_HMATRIX_SCFG11_SLOT_CYCLE_OFFSET                          0
#define AVR32_HMATRIX_SCFG11_SLOT_CYCLE_SIZE                            8
#define AVR32_HMATRIX_SCFG12                                   0x00000070
#define AVR32_HMATRIX_SCFG12_ARBT                                      24
#define AVR32_HMATRIX_SCFG12_ARBT_FIXED_PRIORITY               0x00000001
#define AVR32_HMATRIX_SCFG12_ARBT_MASK                         0x01000000
#define AVR32_HMATRIX_SCFG12_ARBT_OFFSET                               24
#define AVR32_HMATRIX_SCFG12_ARBT_ROUND_ROBIN                  0x00000000
#define AVR32_HMATRIX_SCFG12_ARBT_SIZE                                  1
#define AVR32_HMATRIX_SCFG12_DEFMSTR_TYPE                              16
#define AVR32_HMATRIX_SCFG12_DEFMSTR_TYPE_FIXED_DEFAULT        0x00000002
#define AVR32_HMATRIX_SCFG12_DEFMSTR_TYPE_LAST_DEFAULT         0x00000001
#define AVR32_HMATRIX_SCFG12_DEFMSTR_TYPE_MASK                 0x00030000
#define AVR32_HMATRIX_SCFG12_DEFMSTR_TYPE_NO_DEFAULT           0x00000000
#define AVR32_HMATRIX_SCFG12_DEFMSTR_TYPE_OFFSET                       16
#define AVR32_HMATRIX_SCFG12_DEFMSTR_TYPE_SIZE                          2
#define AVR32_HMATRIX_SCFG12_FIXED_DEFMSTR                             18
#define AVR32_HMATRIX_SCFG12_FIXED_DEFMSTR_MASK                0x003c0000
#define AVR32_HMATRIX_SCFG12_FIXED_DEFMSTR_OFFSET                      18
#define AVR32_HMATRIX_SCFG12_FIXED_DEFMSTR_SIZE                         4
#define AVR32_HMATRIX_SCFG12_SLOT_CYCLE                                 0
#define AVR32_HMATRIX_SCFG12_SLOT_CYCLE_MASK                   0x000000ff
#define AVR32_HMATRIX_SCFG12_SLOT_CYCLE_OFFSET                          0
#define AVR32_HMATRIX_SCFG12_SLOT_CYCLE_SIZE                            8
#define AVR32_HMATRIX_SCFG13                                   0x00000074
#define AVR32_HMATRIX_SCFG13_ARBT                                      24
#define AVR32_HMATRIX_SCFG13_ARBT_FIXED_PRIORITY               0x00000001
#define AVR32_HMATRIX_SCFG13_ARBT_MASK                         0x01000000
#define AVR32_HMATRIX_SCFG13_ARBT_OFFSET                               24
#define AVR32_HMATRIX_SCFG13_ARBT_ROUND_ROBIN                  0x00000000
#define AVR32_HMATRIX_SCFG13_ARBT_SIZE                                  1
#define AVR32_HMATRIX_SCFG13_DEFMSTR_TYPE                              16
#define AVR32_HMATRIX_SCFG13_DEFMSTR_TYPE_FIXED_DEFAULT        0x00000002
#define AVR32_HMATRIX_SCFG13_DEFMSTR_TYPE_LAST_DEFAULT         0x00000001
#define AVR32_HMATRIX_SCFG13_DEFMSTR_TYPE_MASK                 0x00030000
#define AVR32_HMATRIX_SCFG13_DEFMSTR_TYPE_NO_DEFAULT           0x00000000
#define AVR32_HMATRIX_SCFG13_DEFMSTR_TYPE_OFFSET                       16
#define AVR32_HMATRIX_SCFG13_DEFMSTR_TYPE_SIZE                          2
#define AVR32_HMATRIX_SCFG13_FIXED_DEFMSTR                             18
#define AVR32_HMATRIX_SCFG13_FIXED_DEFMSTR_MASK                0x003c0000
#define AVR32_HMATRIX_SCFG13_FIXED_DEFMSTR_OFFSET                      18
#define AVR32_HMATRIX_SCFG13_FIXED_DEFMSTR_SIZE                         4
#define AVR32_HMATRIX_SCFG13_SLOT_CYCLE                                 0
#define AVR32_HMATRIX_SCFG13_SLOT_CYCLE_MASK                   0x000000ff
#define AVR32_HMATRIX_SCFG13_SLOT_CYCLE_OFFSET                          0
#define AVR32_HMATRIX_SCFG13_SLOT_CYCLE_SIZE                            8
#define AVR32_HMATRIX_SCFG14                                   0x00000078
#define AVR32_HMATRIX_SCFG14_ARBT                                      24
#define AVR32_HMATRIX_SCFG14_ARBT_FIXED_PRIORITY               0x00000001
#define AVR32_HMATRIX_SCFG14_ARBT_MASK                         0x01000000
#define AVR32_HMATRIX_SCFG14_ARBT_OFFSET                               24
#define AVR32_HMATRIX_SCFG14_ARBT_ROUND_ROBIN                  0x00000000
#define AVR32_HMATRIX_SCFG14_ARBT_SIZE                                  1
#define AVR32_HMATRIX_SCFG14_DEFMSTR_TYPE                              16
#define AVR32_HMATRIX_SCFG14_DEFMSTR_TYPE_FIXED_DEFAULT        0x00000002
#define AVR32_HMATRIX_SCFG14_DEFMSTR_TYPE_LAST_DEFAULT         0x00000001
#define AVR32_HMATRIX_SCFG14_DEFMSTR_TYPE_MASK                 0x00030000
#define AVR32_HMATRIX_SCFG14_DEFMSTR_TYPE_NO_DEFAULT           0x00000000
#define AVR32_HMATRIX_SCFG14_DEFMSTR_TYPE_OFFSET                       16
#define AVR32_HMATRIX_SCFG14_DEFMSTR_TYPE_SIZE                          2
#define AVR32_HMATRIX_SCFG14_FIXED_DEFMSTR                             18
#define AVR32_HMATRIX_SCFG14_FIXED_DEFMSTR_MASK                0x003c0000
#define AVR32_HMATRIX_SCFG14_FIXED_DEFMSTR_OFFSET                      18
#define AVR32_HMATRIX_SCFG14_FIXED_DEFMSTR_SIZE                         4
#define AVR32_HMATRIX_SCFG14_SLOT_CYCLE                                 0
#define AVR32_HMATRIX_SCFG14_SLOT_CYCLE_MASK                   0x000000ff
#define AVR32_HMATRIX_SCFG14_SLOT_CYCLE_OFFSET                          0
#define AVR32_HMATRIX_SCFG14_SLOT_CYCLE_SIZE                            8
#define AVR32_HMATRIX_SCFG15                                   0x0000007c
#define AVR32_HMATRIX_SCFG15_ARBT                                      24
#define AVR32_HMATRIX_SCFG15_ARBT_FIXED_PRIORITY               0x00000001
#define AVR32_HMATRIX_SCFG15_ARBT_MASK                         0x01000000
#define AVR32_HMATRIX_SCFG15_ARBT_OFFSET                               24
#define AVR32_HMATRIX_SCFG15_ARBT_ROUND_ROBIN                  0x00000000
#define AVR32_HMATRIX_SCFG15_ARBT_SIZE                                  1
#define AVR32_HMATRIX_SCFG15_DEFMSTR_TYPE                              16
#define AVR32_HMATRIX_SCFG15_DEFMSTR_TYPE_FIXED_DEFAULT        0x00000002
#define AVR32_HMATRIX_SCFG15_DEFMSTR_TYPE_LAST_DEFAULT         0x00000001
#define AVR32_HMATRIX_SCFG15_DEFMSTR_TYPE_MASK                 0x00030000
#define AVR32_HMATRIX_SCFG15_DEFMSTR_TYPE_NO_DEFAULT           0x00000000
#define AVR32_HMATRIX_SCFG15_DEFMSTR_TYPE_OFFSET                       16
#define AVR32_HMATRIX_SCFG15_DEFMSTR_TYPE_SIZE                          2
#define AVR32_HMATRIX_SCFG15_FIXED_DEFMSTR                             18
#define AVR32_HMATRIX_SCFG15_FIXED_DEFMSTR_MASK                0x003c0000
#define AVR32_HMATRIX_SCFG15_FIXED_DEFMSTR_OFFSET                      18
#define AVR32_HMATRIX_SCFG15_FIXED_DEFMSTR_SIZE                         4
#define AVR32_HMATRIX_SCFG15_SLOT_CYCLE                                 0
#define AVR32_HMATRIX_SCFG15_SLOT_CYCLE_MASK                   0x000000ff
#define AVR32_HMATRIX_SCFG15_SLOT_CYCLE_OFFSET                          0
#define AVR32_HMATRIX_SCFG15_SLOT_CYCLE_SIZE                            8
#define AVR32_HMATRIX_SCFG1_ARBT                                       24
#define AVR32_HMATRIX_SCFG1_ARBT_FIXED_PRIORITY                0x00000001
#define AVR32_HMATRIX_SCFG1_ARBT_MASK                          0x01000000
#define AVR32_HMATRIX_SCFG1_ARBT_OFFSET                                24
#define AVR32_HMATRIX_SCFG1_ARBT_ROUND_ROBIN                   0x00000000
#define AVR32_HMATRIX_SCFG1_ARBT_SIZE                                   1
#define AVR32_HMATRIX_SCFG1_DEFMSTR_TYPE                               16
#define AVR32_HMATRIX_SCFG1_DEFMSTR_TYPE_FIXED_DEFAULT         0x00000002
#define AVR32_HMATRIX_SCFG1_DEFMSTR_TYPE_LAST_DEFAULT          0x00000001
#define AVR32_HMATRIX_SCFG1_DEFMSTR_TYPE_MASK                  0x00030000
#define AVR32_HMATRIX_SCFG1_DEFMSTR_TYPE_NO_DEFAULT            0x00000000
#define AVR32_HMATRIX_SCFG1_DEFMSTR_TYPE_OFFSET                        16
#define AVR32_HMATRIX_SCFG1_DEFMSTR_TYPE_SIZE                           2
#define AVR32_HMATRIX_SCFG1_FIXED_DEFMSTR                              18
#define AVR32_HMATRIX_SCFG1_FIXED_DEFMSTR_MASK                 0x003c0000
#define AVR32_HMATRIX_SCFG1_FIXED_DEFMSTR_OFFSET                       18
#define AVR32_HMATRIX_SCFG1_FIXED_DEFMSTR_SIZE                          4
#define AVR32_HMATRIX_SCFG1_SLOT_CYCLE                                  0
#define AVR32_HMATRIX_SCFG1_SLOT_CYCLE_MASK                    0x000000ff
#define AVR32_HMATRIX_SCFG1_SLOT_CYCLE_OFFSET                           0
#define AVR32_HMATRIX_SCFG1_SLOT_CYCLE_SIZE                             8
#define AVR32_HMATRIX_SCFG2                                    0x00000048
#define AVR32_HMATRIX_SCFG2_ARBT                                       24
#define AVR32_HMATRIX_SCFG2_ARBT_FIXED_PRIORITY                0x00000001
#define AVR32_HMATRIX_SCFG2_ARBT_MASK                          0x01000000
#define AVR32_HMATRIX_SCFG2_ARBT_OFFSET                                24
#define AVR32_HMATRIX_SCFG2_ARBT_ROUND_ROBIN                   0x00000000
#define AVR32_HMATRIX_SCFG2_ARBT_SIZE                                   1
#define AVR32_HMATRIX_SCFG2_DEFMSTR_TYPE                               16
#define AVR32_HMATRIX_SCFG2_DEFMSTR_TYPE_FIXED_DEFAULT         0x00000002
#define AVR32_HMATRIX_SCFG2_DEFMSTR_TYPE_LAST_DEFAULT          0x00000001
#define AVR32_HMATRIX_SCFG2_DEFMSTR_TYPE_MASK                  0x00030000
#define AVR32_HMATRIX_SCFG2_DEFMSTR_TYPE_NO_DEFAULT            0x00000000
#define AVR32_HMATRIX_SCFG2_DEFMSTR_TYPE_OFFSET                        16
#define AVR32_HMATRIX_SCFG2_DEFMSTR_TYPE_SIZE                           2
#define AVR32_HMATRIX_SCFG2_FIXED_DEFMSTR                              18
#define AVR32_HMATRIX_SCFG2_FIXED_DEFMSTR_MASK                 0x003c0000
#define AVR32_HMATRIX_SCFG2_FIXED_DEFMSTR_OFFSET                       18
#define AVR32_HMATRIX_SCFG2_FIXED_DEFMSTR_SIZE                          4
#define AVR32_HMATRIX_SCFG2_SLOT_CYCLE                                  0
#define AVR32_HMATRIX_SCFG2_SLOT_CYCLE_MASK                    0x000000ff
#define AVR32_HMATRIX_SCFG2_SLOT_CYCLE_OFFSET                           0
#define AVR32_HMATRIX_SCFG2_SLOT_CYCLE_SIZE                             8
#define AVR32_HMATRIX_SCFG3                                    0x0000004c
#define AVR32_HMATRIX_SCFG3_ARBT                                       24
#define AVR32_HMATRIX_SCFG3_ARBT_FIXED_PRIORITY                0x00000001
#define AVR32_HMATRIX_SCFG3_ARBT_MASK                          0x01000000
#define AVR32_HMATRIX_SCFG3_ARBT_OFFSET                                24
#define AVR32_HMATRIX_SCFG3_ARBT_ROUND_ROBIN                   0x00000000
#define AVR32_HMATRIX_SCFG3_ARBT_SIZE                                   1
#define AVR32_HMATRIX_SCFG3_DEFMSTR_TYPE                               16
#define AVR32_HMATRIX_SCFG3_DEFMSTR_TYPE_FIXED_DEFAULT         0x00000002
#define AVR32_HMATRIX_SCFG3_DEFMSTR_TYPE_LAST_DEFAULT          0x00000001
#define AVR32_HMATRIX_SCFG3_DEFMSTR_TYPE_MASK                  0x00030000
#define AVR32_HMATRIX_SCFG3_DEFMSTR_TYPE_NO_DEFAULT            0x00000000
#define AVR32_HMATRIX_SCFG3_DEFMSTR_TYPE_OFFSET                        16
#define AVR32_HMATRIX_SCFG3_DEFMSTR_TYPE_SIZE                           2
#define AVR32_HMATRIX_SCFG3_FIXED_DEFMSTR                              18
#define AVR32_HMATRIX_SCFG3_FIXED_DEFMSTR_MASK                 0x003c0000
#define AVR32_HMATRIX_SCFG3_FIXED_DEFMSTR_OFFSET                       18
#define AVR32_HMATRIX_SCFG3_FIXED_DEFMSTR_SIZE                          4
#define AVR32_HMATRIX_SCFG3_SLOT_CYCLE                                  0
#define AVR32_HMATRIX_SCFG3_SLOT_CYCLE_MASK                    0x000000ff
#define AVR32_HMATRIX_SCFG3_SLOT_CYCLE_OFFSET                           0
#define AVR32_HMATRIX_SCFG3_SLOT_CYCLE_SIZE                             8
#define AVR32_HMATRIX_SCFG4                                    0x00000050
#define AVR32_HMATRIX_SCFG4_ARBT                                       24
#define AVR32_HMATRIX_SCFG4_ARBT_FIXED_PRIORITY                0x00000001
#define AVR32_HMATRIX_SCFG4_ARBT_MASK                          0x01000000
#define AVR32_HMATRIX_SCFG4_ARBT_OFFSET                                24
#define AVR32_HMATRIX_SCFG4_ARBT_ROUND_ROBIN                   0x00000000
#define AVR32_HMATRIX_SCFG4_ARBT_SIZE                                   1
#define AVR32_HMATRIX_SCFG4_DEFMSTR_TYPE                               16
#define AVR32_HMATRIX_SCFG4_DEFMSTR_TYPE_FIXED_DEFAULT         0x00000002
#define AVR32_HMATRIX_SCFG4_DEFMSTR_TYPE_LAST_DEFAULT          0x00000001
#define AVR32_HMATRIX_SCFG4_DEFMSTR_TYPE_MASK                  0x00030000
#define AVR32_HMATRIX_SCFG4_DEFMSTR_TYPE_NO_DEFAULT            0x00000000
#define AVR32_HMATRIX_SCFG4_DEFMSTR_TYPE_OFFSET                        16
#define AVR32_HMATRIX_SCFG4_DEFMSTR_TYPE_SIZE                           2
#define AVR32_HMATRIX_SCFG4_FIXED_DEFMSTR                              18
#define AVR32_HMATRIX_SCFG4_FIXED_DEFMSTR_MASK                 0x003c0000
#define AVR32_HMATRIX_SCFG4_FIXED_DEFMSTR_OFFSET                       18
#define AVR32_HMATRIX_SCFG4_FIXED_DEFMSTR_SIZE                          4
#define AVR32_HMATRIX_SCFG4_SLOT_CYCLE                                  0
#define AVR32_HMATRIX_SCFG4_SLOT_CYCLE_MASK                    0x000000ff
#define AVR32_HMATRIX_SCFG4_SLOT_CYCLE_OFFSET                           0
#define AVR32_HMATRIX_SCFG4_SLOT_CYCLE_SIZE                             8
#define AVR32_HMATRIX_SCFG5                                    0x00000054
#define AVR32_HMATRIX_SCFG5_ARBT                                       24
#define AVR32_HMATRIX_SCFG5_ARBT_FIXED_PRIORITY                0x00000001
#define AVR32_HMATRIX_SCFG5_ARBT_MASK                          0x01000000
#define AVR32_HMATRIX_SCFG5_ARBT_OFFSET                                24
#define AVR32_HMATRIX_SCFG5_ARBT_ROUND_ROBIN                   0x00000000
#define AVR32_HMATRIX_SCFG5_ARBT_SIZE                                   1
#define AVR32_HMATRIX_SCFG5_DEFMSTR_TYPE                               16
#define AVR32_HMATRIX_SCFG5_DEFMSTR_TYPE_FIXED_DEFAULT         0x00000002
#define AVR32_HMATRIX_SCFG5_DEFMSTR_TYPE_LAST_DEFAULT          0x00000001
#define AVR32_HMATRIX_SCFG5_DEFMSTR_TYPE_MASK                  0x00030000
#define AVR32_HMATRIX_SCFG5_DEFMSTR_TYPE_NO_DEFAULT            0x00000000
#define AVR32_HMATRIX_SCFG5_DEFMSTR_TYPE_OFFSET                        16
#define AVR32_HMATRIX_SCFG5_DEFMSTR_TYPE_SIZE                           2
#define AVR32_HMATRIX_SCFG5_FIXED_DEFMSTR                              18
#define AVR32_HMATRIX_SCFG5_FIXED_DEFMSTR_MASK                 0x003c0000
#define AVR32_HMATRIX_SCFG5_FIXED_DEFMSTR_OFFSET                       18
#define AVR32_HMATRIX_SCFG5_FIXED_DEFMSTR_SIZE                          4
#define AVR32_HMATRIX_SCFG5_SLOT_CYCLE                                  0
#define AVR32_HMATRIX_SCFG5_SLOT_CYCLE_MASK                    0x000000ff
#define AVR32_HMATRIX_SCFG5_SLOT_CYCLE_OFFSET                           0
#define AVR32_HMATRIX_SCFG5_SLOT_CYCLE_SIZE                             8
#define AVR32_HMATRIX_SCFG6                                    0x00000058
#define AVR32_HMATRIX_SCFG6_ARBT                                       24
#define AVR32_HMATRIX_SCFG6_ARBT_FIXED_PRIORITY                0x00000001
#define AVR32_HMATRIX_SCFG6_ARBT_MASK                          0x01000000
#define AVR32_HMATRIX_SCFG6_ARBT_OFFSET                                24
#define AVR32_HMATRIX_SCFG6_ARBT_ROUND_ROBIN                   0x00000000
#define AVR32_HMATRIX_SCFG6_ARBT_SIZE                                   1
#define AVR32_HMATRIX_SCFG6_DEFMSTR_TYPE                               16
#define AVR32_HMATRIX_SCFG6_DEFMSTR_TYPE_FIXED_DEFAULT         0x00000002
#define AVR32_HMATRIX_SCFG6_DEFMSTR_TYPE_LAST_DEFAULT          0x00000001
#define AVR32_HMATRIX_SCFG6_DEFMSTR_TYPE_MASK                  0x00030000
#define AVR32_HMATRIX_SCFG6_DEFMSTR_TYPE_NO_DEFAULT            0x00000000
#define AVR32_HMATRIX_SCFG6_DEFMSTR_TYPE_OFFSET                        16
#define AVR32_HMATRIX_SCFG6_DEFMSTR_TYPE_SIZE                           2
#define AVR32_HMATRIX_SCFG6_FIXED_DEFMSTR                              18
#define AVR32_HMATRIX_SCFG6_FIXED_DEFMSTR_MASK                 0x003c0000
#define AVR32_HMATRIX_SCFG6_FIXED_DEFMSTR_OFFSET                       18
#define AVR32_HMATRIX_SCFG6_FIXED_DEFMSTR_SIZE                          4
#define AVR32_HMATRIX_SCFG6_SLOT_CYCLE                                  0
#define AVR32_HMATRIX_SCFG6_SLOT_CYCLE_MASK                    0x000000ff
#define AVR32_HMATRIX_SCFG6_SLOT_CYCLE_OFFSET                           0
#define AVR32_HMATRIX_SCFG6_SLOT_CYCLE_SIZE                             8
#define AVR32_HMATRIX_SCFG7                                    0x0000005c
#define AVR32_HMATRIX_SCFG7_ARBT                                       24
#define AVR32_HMATRIX_SCFG7_ARBT_FIXED_PRIORITY                0x00000001
#define AVR32_HMATRIX_SCFG7_ARBT_MASK                          0x01000000
#define AVR32_HMATRIX_SCFG7_ARBT_OFFSET                                24
#define AVR32_HMATRIX_SCFG7_ARBT_ROUND_ROBIN                   0x00000000
#define AVR32_HMATRIX_SCFG7_ARBT_SIZE                                   1
#define AVR32_HMATRIX_SCFG7_DEFMSTR_TYPE                               16
#define AVR32_HMATRIX_SCFG7_DEFMSTR_TYPE_FIXED_DEFAULT         0x00000002
#define AVR32_HMATRIX_SCFG7_DEFMSTR_TYPE_LAST_DEFAULT          0x00000001
#define AVR32_HMATRIX_SCFG7_DEFMSTR_TYPE_MASK                  0x00030000
#define AVR32_HMATRIX_SCFG7_DEFMSTR_TYPE_NO_DEFAULT            0x00000000
#define AVR32_HMATRIX_SCFG7_DEFMSTR_TYPE_OFFSET                        16
#define AVR32_HMATRIX_SCFG7_DEFMSTR_TYPE_SIZE                           2
#define AVR32_HMATRIX_SCFG7_FIXED_DEFMSTR                              18
#define AVR32_HMATRIX_SCFG7_FIXED_DEFMSTR_MASK                 0x003c0000
#define AVR32_HMATRIX_SCFG7_FIXED_DEFMSTR_OFFSET                       18
#define AVR32_HMATRIX_SCFG7_FIXED_DEFMSTR_SIZE                          4
#define AVR32_HMATRIX_SCFG7_SLOT_CYCLE                                  0
#define AVR32_HMATRIX_SCFG7_SLOT_CYCLE_MASK                    0x000000ff
#define AVR32_HMATRIX_SCFG7_SLOT_CYCLE_OFFSET                           0
#define AVR32_HMATRIX_SCFG7_SLOT_CYCLE_SIZE                             8
#define AVR32_HMATRIX_SCFG8                                    0x00000060
#define AVR32_HMATRIX_SCFG8_ARBT                                       24
#define AVR32_HMATRIX_SCFG8_ARBT_FIXED_PRIORITY                0x00000001
#define AVR32_HMATRIX_SCFG8_ARBT_MASK                          0x01000000
#define AVR32_HMATRIX_SCFG8_ARBT_OFFSET                                24
#define AVR32_HMATRIX_SCFG8_ARBT_ROUND_ROBIN                   0x00000000
#define AVR32_HMATRIX_SCFG8_ARBT_SIZE                                   1
#define AVR32_HMATRIX_SCFG8_DEFMSTR_TYPE                               16
#define AVR32_HMATRIX_SCFG8_DEFMSTR_TYPE_FIXED_DEFAULT         0x00000002
#define AVR32_HMATRIX_SCFG8_DEFMSTR_TYPE_LAST_DEFAULT          0x00000001
#define AVR32_HMATRIX_SCFG8_DEFMSTR_TYPE_MASK                  0x00030000
#define AVR32_HMATRIX_SCFG8_DEFMSTR_TYPE_NO_DEFAULT            0x00000000
#define AVR32_HMATRIX_SCFG8_DEFMSTR_TYPE_OFFSET                        16
#define AVR32_HMATRIX_SCFG8_DEFMSTR_TYPE_SIZE                           2
#define AVR32_HMATRIX_SCFG8_FIXED_DEFMSTR                              18
#define AVR32_HMATRIX_SCFG8_FIXED_DEFMSTR_MASK                 0x003c0000
#define AVR32_HMATRIX_SCFG8_FIXED_DEFMSTR_OFFSET                       18
#define AVR32_HMATRIX_SCFG8_FIXED_DEFMSTR_SIZE                          4
#define AVR32_HMATRIX_SCFG8_SLOT_CYCLE                                  0
#define AVR32_HMATRIX_SCFG8_SLOT_CYCLE_MASK                    0x000000ff
#define AVR32_HMATRIX_SCFG8_SLOT_CYCLE_OFFSET                           0
#define AVR32_HMATRIX_SCFG8_SLOT_CYCLE_SIZE                             8
#define AVR32_HMATRIX_SCFG9                                    0x00000064
#define AVR32_HMATRIX_SCFG9_ARBT                                       24
#define AVR32_HMATRIX_SCFG9_ARBT_FIXED_PRIORITY                0x00000001
#define AVR32_HMATRIX_SCFG9_ARBT_MASK                          0x01000000
#define AVR32_HMATRIX_SCFG9_ARBT_OFFSET                                24
#define AVR32_HMATRIX_SCFG9_ARBT_ROUND_ROBIN                   0x00000000
#define AVR32_HMATRIX_SCFG9_ARBT_SIZE                                   1
#define AVR32_HMATRIX_SCFG9_DEFMSTR_TYPE                               16
#define AVR32_HMATRIX_SCFG9_DEFMSTR_TYPE_FIXED_DEFAULT         0x00000002
#define AVR32_HMATRIX_SCFG9_DEFMSTR_TYPE_LAST_DEFAULT          0x00000001
#define AVR32_HMATRIX_SCFG9_DEFMSTR_TYPE_MASK                  0x00030000
#define AVR32_HMATRIX_SCFG9_DEFMSTR_TYPE_NO_DEFAULT            0x00000000
#define AVR32_HMATRIX_SCFG9_DEFMSTR_TYPE_OFFSET                        16
#define AVR32_HMATRIX_SCFG9_DEFMSTR_TYPE_SIZE                           2
#define AVR32_HMATRIX_SCFG9_FIXED_DEFMSTR                              18
#define AVR32_HMATRIX_SCFG9_FIXED_DEFMSTR_MASK                 0x003c0000
#define AVR32_HMATRIX_SCFG9_FIXED_DEFMSTR_OFFSET                       18
#define AVR32_HMATRIX_SCFG9_FIXED_DEFMSTR_SIZE                          4
#define AVR32_HMATRIX_SCFG9_SLOT_CYCLE                                  0
#define AVR32_HMATRIX_SCFG9_SLOT_CYCLE_MASK                    0x000000ff
#define AVR32_HMATRIX_SCFG9_SLOT_CYCLE_OFFSET                           0
#define AVR32_HMATRIX_SCFG9_SLOT_CYCLE_SIZE                             8
#define AVR32_HMATRIX_SFR                                               0
#define AVR32_HMATRIX_SFR0                                     0x00000110
#define AVR32_HMATRIX_SFR0_SFR                                          0
#define AVR32_HMATRIX_SFR0_SFR_MASK                            0xffffffff
#define AVR32_HMATRIX_SFR0_SFR_OFFSET                                   0
#define AVR32_HMATRIX_SFR0_SFR_SIZE                                    32
#define AVR32_HMATRIX_SFR1                                     0x00000114
#define AVR32_HMATRIX_SFR10                                    0x00000138
#define AVR32_HMATRIX_SFR10_SFR                                         0
#define AVR32_HMATRIX_SFR10_SFR_MASK                           0xffffffff
#define AVR32_HMATRIX_SFR10_SFR_OFFSET                                  0
#define AVR32_HMATRIX_SFR10_SFR_SIZE                                   32
#define AVR32_HMATRIX_SFR11                                    0x0000013c
#define AVR32_HMATRIX_SFR11_SFR                                         0
#define AVR32_HMATRIX_SFR11_SFR_MASK                           0xffffffff
#define AVR32_HMATRIX_SFR11_SFR_OFFSET                                  0
#define AVR32_HMATRIX_SFR11_SFR_SIZE                                   32
#define AVR32_HMATRIX_SFR12                                    0x00000140
#define AVR32_HMATRIX_SFR12_SFR                                         0
#define AVR32_HMATRIX_SFR12_SFR_MASK                           0xffffffff
#define AVR32_HMATRIX_SFR12_SFR_OFFSET                                  0
#define AVR32_HMATRIX_SFR12_SFR_SIZE                                   32
#define AVR32_HMATRIX_SFR13                                    0x00000144
#define AVR32_HMATRIX_SFR13_SFR                                         0
#define AVR32_HMATRIX_SFR13_SFR_MASK                           0xffffffff
#define AVR32_HMATRIX_SFR13_SFR_OFFSET                                  0
#define AVR32_HMATRIX_SFR13_SFR_SIZE                                   32
#define AVR32_HMATRIX_SFR14                                    0x00000148
#define AVR32_HMATRIX_SFR14_SFR                                         0
#define AVR32_HMATRIX_SFR14_SFR_MASK                           0xffffffff
#define AVR32_HMATRIX_SFR14_SFR_OFFSET                                  0
#define AVR32_HMATRIX_SFR14_SFR_SIZE                                   32
#define AVR32_HMATRIX_SFR15                                    0x0000014c
#define AVR32_HMATRIX_SFR15_SFR                                         0
#define AVR32_HMATRIX_SFR15_SFR_MASK                           0xffffffff
#define AVR32_HMATRIX_SFR15_SFR_OFFSET                                  0
#define AVR32_HMATRIX_SFR15_SFR_SIZE                                   32
#define AVR32_HMATRIX_SFR1_SFR                                          0
#define AVR32_HMATRIX_SFR1_SFR_MASK                            0xffffffff
#define AVR32_HMATRIX_SFR1_SFR_OFFSET                                   0
#define AVR32_HMATRIX_SFR1_SFR_SIZE                                    32
#define AVR32_HMATRIX_SFR2                                     0x00000118
#define AVR32_HMATRIX_SFR2_SFR                                          0
#define AVR32_HMATRIX_SFR2_SFR_MASK                            0xffffffff
#define AVR32_HMATRIX_SFR2_SFR_OFFSET                                   0
#define AVR32_HMATRIX_SFR2_SFR_SIZE                                    32
#define AVR32_HMATRIX_SFR3                                     0x0000011c
#define AVR32_HMATRIX_SFR3_SFR                                          0
#define AVR32_HMATRIX_SFR3_SFR_MASK                            0xffffffff
#define AVR32_HMATRIX_SFR3_SFR_OFFSET                                   0
#define AVR32_HMATRIX_SFR3_SFR_SIZE                                    32
#define AVR32_HMATRIX_SFR4                                     0x00000120
#define AVR32_HMATRIX_SFR4_SFR                                          0
#define AVR32_HMATRIX_SFR4_SFR_MASK                            0xffffffff
#define AVR32_HMATRIX_SFR4_SFR_OFFSET                                   0
#define AVR32_HMATRIX_SFR4_SFR_SIZE                                    32
#define AVR32_HMATRIX_SFR5                                     0x00000124
#define AVR32_HMATRIX_SFR5_SFR                                          0
#define AVR32_HMATRIX_SFR5_SFR_MASK                            0xffffffff
#define AVR32_HMATRIX_SFR5_SFR_OFFSET                                   0
#define AVR32_HMATRIX_SFR5_SFR_SIZE                                    32
#define AVR32_HMATRIX_SFR6                                     0x00000128
#define AVR32_HMATRIX_SFR6_SFR                                          0
#define AVR32_HMATRIX_SFR6_SFR_MASK                            0xffffffff
#define AVR32_HMATRIX_SFR6_SFR_OFFSET                                   0
#define AVR32_HMATRIX_SFR6_SFR_SIZE                                    32
#define AVR32_HMATRIX_SFR7                                     0x0000012c
#define AVR32_HMATRIX_SFR7_SFR                                          0
#define AVR32_HMATRIX_SFR7_SFR_MASK                            0xffffffff
#define AVR32_HMATRIX_SFR7_SFR_OFFSET                                   0
#define AVR32_HMATRIX_SFR7_SFR_SIZE                                    32
#define AVR32_HMATRIX_SFR8                                     0x00000130
#define AVR32_HMATRIX_SFR8_SFR                                          0
#define AVR32_HMATRIX_SFR8_SFR_MASK                            0xffffffff
#define AVR32_HMATRIX_SFR8_SFR_OFFSET                                   0
#define AVR32_HMATRIX_SFR8_SFR_SIZE                                    32
#define AVR32_HMATRIX_SFR9                                     0x00000134
#define AVR32_HMATRIX_SFR9_SFR                                          0
#define AVR32_HMATRIX_SFR9_SFR_MASK                            0xffffffff
#define AVR32_HMATRIX_SFR9_SFR_OFFSET                                   0
#define AVR32_HMATRIX_SFR9_SFR_SIZE                                    32
#define AVR32_HMATRIX_SFR_MASK                                 0xffffffff
#define AVR32_HMATRIX_SFR_OFFSET                                        0
#define AVR32_HMATRIX_SFR_SIZE                                         32
#define AVR32_HMATRIX_SINGLE                                   0x00000001
#define AVR32_HMATRIX_SIXTEEN_BEAT                             0x00000004
#define AVR32_HMATRIX_SLOT_CYCLE                                        0
#define AVR32_HMATRIX_SLOT_CYCLE_MASK                          0x000000ff
#define AVR32_HMATRIX_SLOT_CYCLE_OFFSET                                 0
#define AVR32_HMATRIX_SLOT_CYCLE_SIZE                                   8
#define AVR32_HMATRIX_ULBT                                              0
#define AVR32_HMATRIX_ULBT_EIGHT_BEAT                          0x00000003
#define AVR32_HMATRIX_ULBT_FOUR_BEAT                           0x00000002
#define AVR32_HMATRIX_ULBT_INFINITE                            0x00000000
#define AVR32_HMATRIX_ULBT_MASK                                0x00000007
#define AVR32_HMATRIX_ULBT_OFFSET                                       0
#define AVR32_HMATRIX_ULBT_SINGLE                              0x00000001
#define AVR32_HMATRIX_ULBT_SIXTEEN_BEAT                        0x00000004
#define AVR32_HMATRIX_ULBT_SIZE                                         3
#define AVR32_HMATRIX_VARIANT                                          16
#define AVR32_HMATRIX_VARIANT_MASK                             0x00070000
#define AVR32_HMATRIX_VARIANT_OFFSET                                   16
#define AVR32_HMATRIX_VARIANT_SIZE                                      3
#define AVR32_HMATRIX_VERSION                                  0x000001fc
#define AVR32_HMATRIX_VERSION_MASK                             0x00000fff
#define AVR32_HMATRIX_VERSION_OFFSET                                    0
#define AVR32_HMATRIX_VERSION_SIZE                                     12
#define AVR32_HMATRIX_VERSION_VARIANT                                  16
#define AVR32_HMATRIX_VERSION_VARIANT_MASK                     0x00070000
#define AVR32_HMATRIX_VERSION_VARIANT_OFFSET                           16
#define AVR32_HMATRIX_VERSION_VARIANT_SIZE                              3
#define AVR32_HMATRIX_VERSION_VERSION                                   0
#define AVR32_HMATRIX_VERSION_VERSION_MASK                     0x00000fff
#define AVR32_HMATRIX_VERSION_VERSION_OFFSET                            0
#define AVR32_HMATRIX_VERSION_VERSION_SIZE                             12




#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_hmatrix_mcfg_t {
    unsigned int                 :29;
    unsigned int ulbt            : 3;
} avr32_hmatrix_mcfg_t;



typedef struct avr32_hmatrix_scfg_t {
    unsigned int                 : 7;
    unsigned int arbt            : 1;
    unsigned int                 : 2;
    unsigned int fixed_defmstr   : 4;
    unsigned int defmstr_type    : 2;
    unsigned int                 : 8;
    unsigned int slot_cycle      : 8;
} avr32_hmatrix_scfg_t;



typedef struct avr32_hmatrix_pras_t {
    unsigned int m7pr            : 4;
    unsigned int m6pr            : 4;
    unsigned int m5pr            : 4;
    unsigned int m4pr            : 4;
    unsigned int m3pr            : 4;
    unsigned int m2pr            : 4;
    unsigned int m1pr            : 4;
    unsigned int m0pr            : 4;
} avr32_hmatrix_pras_t;



typedef struct avr32_hmatrix_prbs_t {
    unsigned int m15pr           : 4;
    unsigned int m14pr           : 4;
    unsigned int m13pr           : 4;
    unsigned int m12pr           : 4;
    unsigned int m11pr           : 4;
    unsigned int m10pr           : 4;
    unsigned int m9pr            : 4;
    unsigned int m8pr            : 4;
} avr32_hmatrix_prbs_t;



typedef struct avr32_hmatrix_mrcr_t {
    unsigned int                 :16;
    unsigned int rcb15           : 1;
    unsigned int rcb14           : 1;
    unsigned int rcb13           : 1;
    unsigned int rcb12           : 1;
    unsigned int rcb11           : 1;
    unsigned int rcb10           : 1;
    unsigned int rcb9            : 1;
    unsigned int rcb8            : 1;
    unsigned int rcb7            : 1;
    unsigned int rcb6            : 1;
    unsigned int rcb5            : 1;
    unsigned int rcb4            : 1;
    unsigned int rcb3            : 1;
    unsigned int rcb2            : 1;
    unsigned int rcb1            : 1;
    unsigned int rcb0            : 1;
} avr32_hmatrix_mrcr_t;



typedef struct avr32_hmatrix_version_t {
    unsigned int                 :13;
    unsigned int variant         : 3;
    unsigned int                 : 4;
    unsigned int version         :12;
} avr32_hmatrix_version_t;


typedef struct avr32_hmatrix_prs_t {
  union {
          unsigned long                  pras      ;//0x0000
          avr32_hmatrix_pras_t           PRAS      ;
  };
  union {
          unsigned long                  prbs      ;//0x0004
          avr32_hmatrix_prbs_t           PRBS      ;
  };
} avr32_hmatrix_prs_t;


typedef struct avr32_hmatrix_t {
  union {
          unsigned long                  mcfg      [16];//0x0000
          avr32_hmatrix_mcfg_t           MCFG      [16];
  };
  union {
          unsigned long                  scfg      [16];//0x0040
          avr32_hmatrix_scfg_t           SCFG      [16];
  };
  avr32_hmatrix_prs_t prs[16];//0x80
  union {
          unsigned long                  mrcr      ;//0x0100
          avr32_hmatrix_mrcr_t           MRCR      ;
  };
          unsigned int                   :32       ;//0x0104
          unsigned int                   :32       ;//0x0108
          unsigned int                   :32       ;//0x010c
          unsigned long                  sfr       [16];//0x0110
          unsigned int                   :32       ;//0x0150
          unsigned int                   :32       ;//0x0154
          unsigned int                   :32       ;//0x0158
          unsigned int                   :32       ;//0x015c
          unsigned int                   :32       ;//0x0160
          unsigned int                   :32       ;//0x0164
          unsigned int                   :32       ;//0x0168
          unsigned int                   :32       ;//0x016c
          unsigned int                   :32       ;//0x0170
          unsigned int                   :32       ;//0x0174
          unsigned int                   :32       ;//0x0178
          unsigned int                   :32       ;//0x017c
          unsigned int                   :32       ;//0x0180
          unsigned int                   :32       ;//0x0184
          unsigned int                   :32       ;//0x0188
          unsigned int                   :32       ;//0x018c
          unsigned int                   :32       ;//0x0190
          unsigned int                   :32       ;//0x0194
          unsigned int                   :32       ;//0x0198
          unsigned int                   :32       ;//0x019c
          unsigned int                   :32       ;//0x01a0
          unsigned int                   :32       ;//0x01a4
          unsigned int                   :32       ;//0x01a8
          unsigned int                   :32       ;//0x01ac
          unsigned int                   :32       ;//0x01b0
          unsigned int                   :32       ;//0x01b4
          unsigned int                   :32       ;//0x01b8
          unsigned int                   :32       ;//0x01bc
          unsigned int                   :32       ;//0x01c0
          unsigned int                   :32       ;//0x01c4
          unsigned int                   :32       ;//0x01c8
          unsigned int                   :32       ;//0x01cc
          unsigned int                   :32       ;//0x01d0
          unsigned int                   :32       ;//0x01d4
          unsigned int                   :32       ;//0x01d8
          unsigned int                   :32       ;//0x01dc
          unsigned int                   :32       ;//0x01e0
          unsigned int                   :32       ;//0x01e4
          unsigned int                   :32       ;//0x01e8
          unsigned int                   :32       ;//0x01ec
          unsigned int                   :32       ;//0x01f0
          unsigned int                   :32       ;//0x01f4
          unsigned int                   :32       ;//0x01f8
  union {
    const unsigned long                  version   ;//0x01fc
    const avr32_hmatrix_version_t        VERSION   ;
  };
} avr32_hmatrix_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif

/*#ifdef AVR32_HMATRIX_230_H_INCLUDED*/
#endif

