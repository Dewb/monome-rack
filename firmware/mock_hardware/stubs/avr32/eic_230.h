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
#ifndef AVR32_EIC_230_H_INCLUDED
#define AVR32_EIC_230_H_INCLUDED

#define AVR32_EIC_H_VERSION 230

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_EIC_<register>
 - Bitfield mask:   AVR32_EIC_<register>_<bitfield>
 - Bitfield offset: AVR32_EIC_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_EIC_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_EIC_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_EIC_<bitfield>
 - Bitfield offset: AVR32_EIC_<bitfield>_OFFSET
 - Bitfield size:   AVR32_EIC_<bitfield>_SIZE
 - Bitfield values: AVR32_EIC_<bitfield>_<value name>
 - Bitfield values: AVR32_EIC_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_EIC_ASYNC                                    0x00000028
#define AVR32_EIC_ASYNC_INT0                                        0
#define AVR32_EIC_ASYNC_INT0_MASK                          0x00000001
#define AVR32_EIC_ASYNC_INT0_OFFSET                                 0
#define AVR32_EIC_ASYNC_INT0_SIZE                                   1
#define AVR32_EIC_ASYNC_INT1                                        1
#define AVR32_EIC_ASYNC_INT1_MASK                          0x00000002
#define AVR32_EIC_ASYNC_INT1_OFFSET                                 1
#define AVR32_EIC_ASYNC_INT1_SIZE                                   1
#define AVR32_EIC_ASYNC_INT2                                        2
#define AVR32_EIC_ASYNC_INT2_MASK                          0x00000004
#define AVR32_EIC_ASYNC_INT2_OFFSET                                 2
#define AVR32_EIC_ASYNC_INT2_SIZE                                   1
#define AVR32_EIC_ASYNC_INT3                                        3
#define AVR32_EIC_ASYNC_INT3_MASK                          0x00000008
#define AVR32_EIC_ASYNC_INT3_OFFSET                                 3
#define AVR32_EIC_ASYNC_INT3_SIZE                                   1
#define AVR32_EIC_ASYNC_INT4                                        4
#define AVR32_EIC_ASYNC_INT4_MASK                          0x00000010
#define AVR32_EIC_ASYNC_INT4_OFFSET                                 4
#define AVR32_EIC_ASYNC_INT4_SIZE                                   1
#define AVR32_EIC_ASYNC_INT5                                        5
#define AVR32_EIC_ASYNC_INT5_MASK                          0x00000020
#define AVR32_EIC_ASYNC_INT5_OFFSET                                 5
#define AVR32_EIC_ASYNC_INT5_SIZE                                   1
#define AVR32_EIC_ASYNC_INT6                                        6
#define AVR32_EIC_ASYNC_INT6_MASK                          0x00000040
#define AVR32_EIC_ASYNC_INT6_OFFSET                                 6
#define AVR32_EIC_ASYNC_INT6_SIZE                                   1
#define AVR32_EIC_ASYNC_INT7                                        7
#define AVR32_EIC_ASYNC_INT7_MASK                          0x00000080
#define AVR32_EIC_ASYNC_INT7_OFFSET                                 7
#define AVR32_EIC_ASYNC_INT7_SIZE                                   1
#define AVR32_EIC_ASYNC_NMI                                         8
#define AVR32_EIC_ASYNC_NMI_MASK                           0x00000100
#define AVR32_EIC_ASYNC_NMI_OFFSET                                  8
#define AVR32_EIC_ASYNC_NMI_SIZE                                    1
#define AVR32_EIC_CTRL                                     0x00000038
#define AVR32_EIC_CTRL_INT0                                         0
#define AVR32_EIC_CTRL_INT0_MASK                           0x00000001
#define AVR32_EIC_CTRL_INT0_OFFSET                                  0
#define AVR32_EIC_CTRL_INT0_SIZE                                    1
#define AVR32_EIC_CTRL_INT1                                         1
#define AVR32_EIC_CTRL_INT1_MASK                           0x00000002
#define AVR32_EIC_CTRL_INT1_OFFSET                                  1
#define AVR32_EIC_CTRL_INT1_SIZE                                    1
#define AVR32_EIC_CTRL_INT2                                         2
#define AVR32_EIC_CTRL_INT2_MASK                           0x00000004
#define AVR32_EIC_CTRL_INT2_OFFSET                                  2
#define AVR32_EIC_CTRL_INT2_SIZE                                    1
#define AVR32_EIC_CTRL_INT3                                         3
#define AVR32_EIC_CTRL_INT3_MASK                           0x00000008
#define AVR32_EIC_CTRL_INT3_OFFSET                                  3
#define AVR32_EIC_CTRL_INT3_SIZE                                    1
#define AVR32_EIC_CTRL_INT4                                         4
#define AVR32_EIC_CTRL_INT4_MASK                           0x00000010
#define AVR32_EIC_CTRL_INT4_OFFSET                                  4
#define AVR32_EIC_CTRL_INT4_SIZE                                    1
#define AVR32_EIC_CTRL_INT5                                         5
#define AVR32_EIC_CTRL_INT5_MASK                           0x00000020
#define AVR32_EIC_CTRL_INT5_OFFSET                                  5
#define AVR32_EIC_CTRL_INT5_SIZE                                    1
#define AVR32_EIC_CTRL_INT6                                         6
#define AVR32_EIC_CTRL_INT6_MASK                           0x00000040
#define AVR32_EIC_CTRL_INT6_OFFSET                                  6
#define AVR32_EIC_CTRL_INT6_SIZE                                    1
#define AVR32_EIC_CTRL_INT7                                         7
#define AVR32_EIC_CTRL_INT7_MASK                           0x00000080
#define AVR32_EIC_CTRL_INT7_OFFSET                                  7
#define AVR32_EIC_CTRL_INT7_SIZE                                    1
#define AVR32_EIC_CTRL_NMI                                          8
#define AVR32_EIC_CTRL_NMI_MASK                            0x00000100
#define AVR32_EIC_CTRL_NMI_OFFSET                                   8
#define AVR32_EIC_CTRL_NMI_SIZE                                     1
#define AVR32_EIC_DIS                                      0x00000034
#define AVR32_EIC_DIS_INT0                                          0
#define AVR32_EIC_DIS_INT0_MASK                            0x00000001
#define AVR32_EIC_DIS_INT0_OFFSET                                   0
#define AVR32_EIC_DIS_INT0_SIZE                                     1
#define AVR32_EIC_DIS_INT1                                          1
#define AVR32_EIC_DIS_INT1_MASK                            0x00000002
#define AVR32_EIC_DIS_INT1_OFFSET                                   1
#define AVR32_EIC_DIS_INT1_SIZE                                     1
#define AVR32_EIC_DIS_INT2                                          2
#define AVR32_EIC_DIS_INT2_MASK                            0x00000004
#define AVR32_EIC_DIS_INT2_OFFSET                                   2
#define AVR32_EIC_DIS_INT2_SIZE                                     1
#define AVR32_EIC_DIS_INT3                                          3
#define AVR32_EIC_DIS_INT3_MASK                            0x00000008
#define AVR32_EIC_DIS_INT3_OFFSET                                   3
#define AVR32_EIC_DIS_INT3_SIZE                                     1
#define AVR32_EIC_DIS_INT4                                          4
#define AVR32_EIC_DIS_INT4_MASK                            0x00000010
#define AVR32_EIC_DIS_INT4_OFFSET                                   4
#define AVR32_EIC_DIS_INT4_SIZE                                     1
#define AVR32_EIC_DIS_INT5                                          5
#define AVR32_EIC_DIS_INT5_MASK                            0x00000020
#define AVR32_EIC_DIS_INT5_OFFSET                                   5
#define AVR32_EIC_DIS_INT5_SIZE                                     1
#define AVR32_EIC_DIS_INT6                                          6
#define AVR32_EIC_DIS_INT6_MASK                            0x00000040
#define AVR32_EIC_DIS_INT6_OFFSET                                   6
#define AVR32_EIC_DIS_INT6_SIZE                                     1
#define AVR32_EIC_DIS_INT7                                          7
#define AVR32_EIC_DIS_INT7_MASK                            0x00000080
#define AVR32_EIC_DIS_INT7_OFFSET                                   7
#define AVR32_EIC_DIS_INT7_SIZE                                     1
#define AVR32_EIC_DIS_NMI                                           8
#define AVR32_EIC_DIS_NMI_MASK                             0x00000100
#define AVR32_EIC_DIS_NMI_OFFSET                                    8
#define AVR32_EIC_DIS_NMI_SIZE                                      1
#define AVR32_EIC_EDGE                                     0x00000018
#define AVR32_EIC_EDGE_INT0                                         0
#define AVR32_EIC_EDGE_INT0_MASK                           0x00000001
#define AVR32_EIC_EDGE_INT0_OFFSET                                  0
#define AVR32_EIC_EDGE_INT0_SIZE                                    1
#define AVR32_EIC_EDGE_INT1                                         1
#define AVR32_EIC_EDGE_INT1_MASK                           0x00000002
#define AVR32_EIC_EDGE_INT1_OFFSET                                  1
#define AVR32_EIC_EDGE_INT1_SIZE                                    1
#define AVR32_EIC_EDGE_INT2                                         2
#define AVR32_EIC_EDGE_INT2_MASK                           0x00000004
#define AVR32_EIC_EDGE_INT2_OFFSET                                  2
#define AVR32_EIC_EDGE_INT2_SIZE                                    1
#define AVR32_EIC_EDGE_INT3                                         3
#define AVR32_EIC_EDGE_INT3_MASK                           0x00000008
#define AVR32_EIC_EDGE_INT3_OFFSET                                  3
#define AVR32_EIC_EDGE_INT3_SIZE                                    1
#define AVR32_EIC_EDGE_INT4                                         4
#define AVR32_EIC_EDGE_INT4_MASK                           0x00000010
#define AVR32_EIC_EDGE_INT4_OFFSET                                  4
#define AVR32_EIC_EDGE_INT4_SIZE                                    1
#define AVR32_EIC_EDGE_INT5                                         5
#define AVR32_EIC_EDGE_INT5_MASK                           0x00000020
#define AVR32_EIC_EDGE_INT5_OFFSET                                  5
#define AVR32_EIC_EDGE_INT5_SIZE                                    1
#define AVR32_EIC_EDGE_INT6                                         6
#define AVR32_EIC_EDGE_INT6_MASK                           0x00000040
#define AVR32_EIC_EDGE_INT6_OFFSET                                  6
#define AVR32_EIC_EDGE_INT6_SIZE                                    1
#define AVR32_EIC_EDGE_INT7                                         7
#define AVR32_EIC_EDGE_INT7_MASK                           0x00000080
#define AVR32_EIC_EDGE_INT7_OFFSET                                  7
#define AVR32_EIC_EDGE_INT7_SIZE                                    1
#define AVR32_EIC_EDGE_NMI                                          8
#define AVR32_EIC_EDGE_NMI_MASK                            0x00000100
#define AVR32_EIC_EDGE_NMI_OFFSET                                   8
#define AVR32_EIC_EDGE_NMI_SIZE                                     1
#define AVR32_EIC_EN                                       0x00000030
#define AVR32_EIC_EN_INT0                                           0
#define AVR32_EIC_EN_INT0_MASK                             0x00000001
#define AVR32_EIC_EN_INT0_OFFSET                                    0
#define AVR32_EIC_EN_INT0_SIZE                                      1
#define AVR32_EIC_EN_INT1                                           1
#define AVR32_EIC_EN_INT1_MASK                             0x00000002
#define AVR32_EIC_EN_INT1_OFFSET                                    1
#define AVR32_EIC_EN_INT1_SIZE                                      1
#define AVR32_EIC_EN_INT2                                           2
#define AVR32_EIC_EN_INT2_MASK                             0x00000004
#define AVR32_EIC_EN_INT2_OFFSET                                    2
#define AVR32_EIC_EN_INT2_SIZE                                      1
#define AVR32_EIC_EN_INT3                                           3
#define AVR32_EIC_EN_INT3_MASK                             0x00000008
#define AVR32_EIC_EN_INT3_OFFSET                                    3
#define AVR32_EIC_EN_INT3_SIZE                                      1
#define AVR32_EIC_EN_INT4                                           4
#define AVR32_EIC_EN_INT4_MASK                             0x00000010
#define AVR32_EIC_EN_INT4_OFFSET                                    4
#define AVR32_EIC_EN_INT4_SIZE                                      1
#define AVR32_EIC_EN_INT5                                           5
#define AVR32_EIC_EN_INT5_MASK                             0x00000020
#define AVR32_EIC_EN_INT5_OFFSET                                    5
#define AVR32_EIC_EN_INT5_SIZE                                      1
#define AVR32_EIC_EN_INT6                                           6
#define AVR32_EIC_EN_INT6_MASK                             0x00000040
#define AVR32_EIC_EN_INT6_OFFSET                                    6
#define AVR32_EIC_EN_INT6_SIZE                                      1
#define AVR32_EIC_EN_INT7                                           7
#define AVR32_EIC_EN_INT7_MASK                             0x00000080
#define AVR32_EIC_EN_INT7_OFFSET                                    7
#define AVR32_EIC_EN_INT7_SIZE                                      1
#define AVR32_EIC_EN_MASK                                  0x00000001
#define AVR32_EIC_EN_NMI                                            8
#define AVR32_EIC_EN_NMI_MASK                              0x00000100
#define AVR32_EIC_EN_NMI_OFFSET                                     8
#define AVR32_EIC_EN_NMI_SIZE                                       1
#define AVR32_EIC_EN_OFFSET                                         0
#define AVR32_EIC_EN_SIZE                                           1
#define AVR32_EIC_FILTER                                   0x00000020
#define AVR32_EIC_FILTER_INT0                                       0
#define AVR32_EIC_FILTER_INT0_MASK                         0x00000001
#define AVR32_EIC_FILTER_INT0_OFFSET                                0
#define AVR32_EIC_FILTER_INT0_SIZE                                  1
#define AVR32_EIC_FILTER_INT1                                       1
#define AVR32_EIC_FILTER_INT1_MASK                         0x00000002
#define AVR32_EIC_FILTER_INT1_OFFSET                                1
#define AVR32_EIC_FILTER_INT1_SIZE                                  1
#define AVR32_EIC_FILTER_INT2                                       2
#define AVR32_EIC_FILTER_INT2_MASK                         0x00000004
#define AVR32_EIC_FILTER_INT2_OFFSET                                2
#define AVR32_EIC_FILTER_INT2_SIZE                                  1
#define AVR32_EIC_FILTER_INT3                                       3
#define AVR32_EIC_FILTER_INT3_MASK                         0x00000008
#define AVR32_EIC_FILTER_INT3_OFFSET                                3
#define AVR32_EIC_FILTER_INT3_SIZE                                  1
#define AVR32_EIC_FILTER_INT4                                       4
#define AVR32_EIC_FILTER_INT4_MASK                         0x00000010
#define AVR32_EIC_FILTER_INT4_OFFSET                                4
#define AVR32_EIC_FILTER_INT4_SIZE                                  1
#define AVR32_EIC_FILTER_INT5                                       5
#define AVR32_EIC_FILTER_INT5_MASK                         0x00000020
#define AVR32_EIC_FILTER_INT5_OFFSET                                5
#define AVR32_EIC_FILTER_INT5_SIZE                                  1
#define AVR32_EIC_FILTER_INT6                                       6
#define AVR32_EIC_FILTER_INT6_MASK                         0x00000040
#define AVR32_EIC_FILTER_INT6_OFFSET                                6
#define AVR32_EIC_FILTER_INT6_SIZE                                  1
#define AVR32_EIC_FILTER_INT7                                       7
#define AVR32_EIC_FILTER_INT7_MASK                         0x00000080
#define AVR32_EIC_FILTER_INT7_OFFSET                                7
#define AVR32_EIC_FILTER_INT7_SIZE                                  1
#define AVR32_EIC_FILTER_NMI                                        8
#define AVR32_EIC_FILTER_NMI_MASK                          0x00000100
#define AVR32_EIC_FILTER_NMI_OFFSET                                 8
#define AVR32_EIC_FILTER_NMI_SIZE                                   1
#define AVR32_EIC_ICR                                      0x00000010
#define AVR32_EIC_ICR_INT0                                          0
#define AVR32_EIC_ICR_INT0_MASK                            0x00000001
#define AVR32_EIC_ICR_INT0_OFFSET                                   0
#define AVR32_EIC_ICR_INT0_SIZE                                     1
#define AVR32_EIC_ICR_INT1                                          1
#define AVR32_EIC_ICR_INT1_MASK                            0x00000002
#define AVR32_EIC_ICR_INT1_OFFSET                                   1
#define AVR32_EIC_ICR_INT1_SIZE                                     1
#define AVR32_EIC_ICR_INT2                                          2
#define AVR32_EIC_ICR_INT2_MASK                            0x00000004
#define AVR32_EIC_ICR_INT2_OFFSET                                   2
#define AVR32_EIC_ICR_INT2_SIZE                                     1
#define AVR32_EIC_ICR_INT3                                          3
#define AVR32_EIC_ICR_INT3_MASK                            0x00000008
#define AVR32_EIC_ICR_INT3_OFFSET                                   3
#define AVR32_EIC_ICR_INT3_SIZE                                     1
#define AVR32_EIC_ICR_INT4                                          4
#define AVR32_EIC_ICR_INT4_MASK                            0x00000010
#define AVR32_EIC_ICR_INT4_OFFSET                                   4
#define AVR32_EIC_ICR_INT4_SIZE                                     1
#define AVR32_EIC_ICR_INT5                                          5
#define AVR32_EIC_ICR_INT5_MASK                            0x00000020
#define AVR32_EIC_ICR_INT5_OFFSET                                   5
#define AVR32_EIC_ICR_INT5_SIZE                                     1
#define AVR32_EIC_ICR_INT6                                          6
#define AVR32_EIC_ICR_INT6_MASK                            0x00000040
#define AVR32_EIC_ICR_INT6_OFFSET                                   6
#define AVR32_EIC_ICR_INT6_SIZE                                     1
#define AVR32_EIC_ICR_INT7                                          7
#define AVR32_EIC_ICR_INT7_MASK                            0x00000080
#define AVR32_EIC_ICR_INT7_OFFSET                                   7
#define AVR32_EIC_ICR_INT7_SIZE                                     1
#define AVR32_EIC_ICR_NMI                                           8
#define AVR32_EIC_ICR_NMI_MASK                             0x00000100
#define AVR32_EIC_ICR_NMI_OFFSET                                    8
#define AVR32_EIC_ICR_NMI_SIZE                                      1
#define AVR32_EIC_IDR                                      0x00000004
#define AVR32_EIC_IDR_INT0                                          0
#define AVR32_EIC_IDR_INT0_MASK                            0x00000001
#define AVR32_EIC_IDR_INT0_OFFSET                                   0
#define AVR32_EIC_IDR_INT0_SIZE                                     1
#define AVR32_EIC_IDR_INT1                                          1
#define AVR32_EIC_IDR_INT1_MASK                            0x00000002
#define AVR32_EIC_IDR_INT1_OFFSET                                   1
#define AVR32_EIC_IDR_INT1_SIZE                                     1
#define AVR32_EIC_IDR_INT2                                          2
#define AVR32_EIC_IDR_INT2_MASK                            0x00000004
#define AVR32_EIC_IDR_INT2_OFFSET                                   2
#define AVR32_EIC_IDR_INT2_SIZE                                     1
#define AVR32_EIC_IDR_INT3                                          3
#define AVR32_EIC_IDR_INT3_MASK                            0x00000008
#define AVR32_EIC_IDR_INT3_OFFSET                                   3
#define AVR32_EIC_IDR_INT3_SIZE                                     1
#define AVR32_EIC_IDR_INT4                                          4
#define AVR32_EIC_IDR_INT4_MASK                            0x00000010
#define AVR32_EIC_IDR_INT4_OFFSET                                   4
#define AVR32_EIC_IDR_INT4_SIZE                                     1
#define AVR32_EIC_IDR_INT5                                          5
#define AVR32_EIC_IDR_INT5_MASK                            0x00000020
#define AVR32_EIC_IDR_INT5_OFFSET                                   5
#define AVR32_EIC_IDR_INT5_SIZE                                     1
#define AVR32_EIC_IDR_INT6                                          6
#define AVR32_EIC_IDR_INT6_MASK                            0x00000040
#define AVR32_EIC_IDR_INT6_OFFSET                                   6
#define AVR32_EIC_IDR_INT6_SIZE                                     1
#define AVR32_EIC_IDR_INT7                                          7
#define AVR32_EIC_IDR_INT7_MASK                            0x00000080
#define AVR32_EIC_IDR_INT7_OFFSET                                   7
#define AVR32_EIC_IDR_INT7_SIZE                                     1
#define AVR32_EIC_IDR_NMI                                           8
#define AVR32_EIC_IDR_NMI_MASK                             0x00000100
#define AVR32_EIC_IDR_NMI_OFFSET                                    8
#define AVR32_EIC_IDR_NMI_SIZE                                      1
#define AVR32_EIC_IER                                      0x00000000
#define AVR32_EIC_IER_INT0                                          0
#define AVR32_EIC_IER_INT0_MASK                            0x00000001
#define AVR32_EIC_IER_INT0_OFFSET                                   0
#define AVR32_EIC_IER_INT0_SIZE                                     1
#define AVR32_EIC_IER_INT1                                          1
#define AVR32_EIC_IER_INT1_MASK                            0x00000002
#define AVR32_EIC_IER_INT1_OFFSET                                   1
#define AVR32_EIC_IER_INT1_SIZE                                     1
#define AVR32_EIC_IER_INT2                                          2
#define AVR32_EIC_IER_INT2_MASK                            0x00000004
#define AVR32_EIC_IER_INT2_OFFSET                                   2
#define AVR32_EIC_IER_INT2_SIZE                                     1
#define AVR32_EIC_IER_INT3                                          3
#define AVR32_EIC_IER_INT3_MASK                            0x00000008
#define AVR32_EIC_IER_INT3_OFFSET                                   3
#define AVR32_EIC_IER_INT3_SIZE                                     1
#define AVR32_EIC_IER_INT4                                          4
#define AVR32_EIC_IER_INT4_MASK                            0x00000010
#define AVR32_EIC_IER_INT4_OFFSET                                   4
#define AVR32_EIC_IER_INT4_SIZE                                     1
#define AVR32_EIC_IER_INT5                                          5
#define AVR32_EIC_IER_INT5_MASK                            0x00000020
#define AVR32_EIC_IER_INT5_OFFSET                                   5
#define AVR32_EIC_IER_INT5_SIZE                                     1
#define AVR32_EIC_IER_INT6                                          6
#define AVR32_EIC_IER_INT6_MASK                            0x00000040
#define AVR32_EIC_IER_INT6_OFFSET                                   6
#define AVR32_EIC_IER_INT6_SIZE                                     1
#define AVR32_EIC_IER_INT7                                          7
#define AVR32_EIC_IER_INT7_MASK                            0x00000080
#define AVR32_EIC_IER_INT7_OFFSET                                   7
#define AVR32_EIC_IER_INT7_SIZE                                     1
#define AVR32_EIC_IER_NMI                                           8
#define AVR32_EIC_IER_NMI_MASK                             0x00000100
#define AVR32_EIC_IER_NMI_OFFSET                                    8
#define AVR32_EIC_IER_NMI_SIZE                                      1
#define AVR32_EIC_IMR                                      0x00000008
#define AVR32_EIC_IMR_INT0                                          0
#define AVR32_EIC_IMR_INT0_MASK                            0x00000001
#define AVR32_EIC_IMR_INT0_OFFSET                                   0
#define AVR32_EIC_IMR_INT0_SIZE                                     1
#define AVR32_EIC_IMR_INT1                                          1
#define AVR32_EIC_IMR_INT1_MASK                            0x00000002
#define AVR32_EIC_IMR_INT1_OFFSET                                   1
#define AVR32_EIC_IMR_INT1_SIZE                                     1
#define AVR32_EIC_IMR_INT2                                          2
#define AVR32_EIC_IMR_INT2_MASK                            0x00000004
#define AVR32_EIC_IMR_INT2_OFFSET                                   2
#define AVR32_EIC_IMR_INT2_SIZE                                     1
#define AVR32_EIC_IMR_INT3                                          3
#define AVR32_EIC_IMR_INT3_MASK                            0x00000008
#define AVR32_EIC_IMR_INT3_OFFSET                                   3
#define AVR32_EIC_IMR_INT3_SIZE                                     1
#define AVR32_EIC_IMR_INT4                                          4
#define AVR32_EIC_IMR_INT4_MASK                            0x00000010
#define AVR32_EIC_IMR_INT4_OFFSET                                   4
#define AVR32_EIC_IMR_INT4_SIZE                                     1
#define AVR32_EIC_IMR_INT5                                          5
#define AVR32_EIC_IMR_INT5_MASK                            0x00000020
#define AVR32_EIC_IMR_INT5_OFFSET                                   5
#define AVR32_EIC_IMR_INT5_SIZE                                     1
#define AVR32_EIC_IMR_INT6                                          6
#define AVR32_EIC_IMR_INT6_MASK                            0x00000040
#define AVR32_EIC_IMR_INT6_OFFSET                                   6
#define AVR32_EIC_IMR_INT6_SIZE                                     1
#define AVR32_EIC_IMR_INT7                                          7
#define AVR32_EIC_IMR_INT7_MASK                            0x00000080
#define AVR32_EIC_IMR_INT7_OFFSET                                   7
#define AVR32_EIC_IMR_INT7_SIZE                                     1
#define AVR32_EIC_IMR_NMI                                           8
#define AVR32_EIC_IMR_NMI_MASK                             0x00000100
#define AVR32_EIC_IMR_NMI_OFFSET                                    8
#define AVR32_EIC_IMR_NMI_SIZE                                      1
#define AVR32_EIC_INT0                                              0
#define AVR32_EIC_INT0_MASK                                0x00000001
#define AVR32_EIC_INT0_OFFSET                                       0
#define AVR32_EIC_INT0_SIZE                                         1
#define AVR32_EIC_INT1                                              1
#define AVR32_EIC_INT1_MASK                                0x00000002
#define AVR32_EIC_INT1_OFFSET                                       1
#define AVR32_EIC_INT1_SIZE                                         1
#define AVR32_EIC_INT2                                              2
#define AVR32_EIC_INT2_MASK                                0x00000004
#define AVR32_EIC_INT2_OFFSET                                       2
#define AVR32_EIC_INT2_SIZE                                         1
#define AVR32_EIC_INT3                                              3
#define AVR32_EIC_INT3_MASK                                0x00000008
#define AVR32_EIC_INT3_OFFSET                                       3
#define AVR32_EIC_INT3_SIZE                                         1
#define AVR32_EIC_INT4                                              4
#define AVR32_EIC_INT4_MASK                                0x00000010
#define AVR32_EIC_INT4_OFFSET                                       4
#define AVR32_EIC_INT4_SIZE                                         1
#define AVR32_EIC_INT5                                              5
#define AVR32_EIC_INT5_MASK                                0x00000020
#define AVR32_EIC_INT5_OFFSET                                       5
#define AVR32_EIC_INT5_SIZE                                         1
#define AVR32_EIC_INT6                                              6
#define AVR32_EIC_INT6_MASK                                0x00000040
#define AVR32_EIC_INT6_OFFSET                                       6
#define AVR32_EIC_INT6_SIZE                                         1
#define AVR32_EIC_INT7                                              7
#define AVR32_EIC_INT7_MASK                                0x00000080
#define AVR32_EIC_INT7_OFFSET                                       7
#define AVR32_EIC_INT7_SIZE                                         1
#define AVR32_EIC_ISR                                      0x0000000c
#define AVR32_EIC_ISR_INT0                                          0
#define AVR32_EIC_ISR_INT0_MASK                            0x00000001
#define AVR32_EIC_ISR_INT0_OFFSET                                   0
#define AVR32_EIC_ISR_INT0_SIZE                                     1
#define AVR32_EIC_ISR_INT1                                          1
#define AVR32_EIC_ISR_INT1_MASK                            0x00000002
#define AVR32_EIC_ISR_INT1_OFFSET                                   1
#define AVR32_EIC_ISR_INT1_SIZE                                     1
#define AVR32_EIC_ISR_INT2                                          2
#define AVR32_EIC_ISR_INT2_MASK                            0x00000004
#define AVR32_EIC_ISR_INT2_OFFSET                                   2
#define AVR32_EIC_ISR_INT2_SIZE                                     1
#define AVR32_EIC_ISR_INT3                                          3
#define AVR32_EIC_ISR_INT3_MASK                            0x00000008
#define AVR32_EIC_ISR_INT3_OFFSET                                   3
#define AVR32_EIC_ISR_INT3_SIZE                                     1
#define AVR32_EIC_ISR_INT4                                          4
#define AVR32_EIC_ISR_INT4_MASK                            0x00000010
#define AVR32_EIC_ISR_INT4_OFFSET                                   4
#define AVR32_EIC_ISR_INT4_SIZE                                     1
#define AVR32_EIC_ISR_INT5                                          5
#define AVR32_EIC_ISR_INT5_MASK                            0x00000020
#define AVR32_EIC_ISR_INT5_OFFSET                                   5
#define AVR32_EIC_ISR_INT5_SIZE                                     1
#define AVR32_EIC_ISR_INT6                                          6
#define AVR32_EIC_ISR_INT6_MASK                            0x00000040
#define AVR32_EIC_ISR_INT6_OFFSET                                   6
#define AVR32_EIC_ISR_INT6_SIZE                                     1
#define AVR32_EIC_ISR_INT7                                          7
#define AVR32_EIC_ISR_INT7_MASK                            0x00000080
#define AVR32_EIC_ISR_INT7_OFFSET                                   7
#define AVR32_EIC_ISR_INT7_SIZE                                     1
#define AVR32_EIC_ISR_NMI                                           8
#define AVR32_EIC_ISR_NMI_MASK                             0x00000100
#define AVR32_EIC_ISR_NMI_OFFSET                                    8
#define AVR32_EIC_ISR_NMI_SIZE                                      1
#define AVR32_EIC_LEVEL                                    0x0000001c
#define AVR32_EIC_LEVEL_INT0                                        0
#define AVR32_EIC_LEVEL_INT0_MASK                          0x00000001
#define AVR32_EIC_LEVEL_INT0_OFFSET                                 0
#define AVR32_EIC_LEVEL_INT0_SIZE                                   1
#define AVR32_EIC_LEVEL_INT1                                        1
#define AVR32_EIC_LEVEL_INT1_MASK                          0x00000002
#define AVR32_EIC_LEVEL_INT1_OFFSET                                 1
#define AVR32_EIC_LEVEL_INT1_SIZE                                   1
#define AVR32_EIC_LEVEL_INT2                                        2
#define AVR32_EIC_LEVEL_INT2_MASK                          0x00000004
#define AVR32_EIC_LEVEL_INT2_OFFSET                                 2
#define AVR32_EIC_LEVEL_INT2_SIZE                                   1
#define AVR32_EIC_LEVEL_INT3                                        3
#define AVR32_EIC_LEVEL_INT3_MASK                          0x00000008
#define AVR32_EIC_LEVEL_INT3_OFFSET                                 3
#define AVR32_EIC_LEVEL_INT3_SIZE                                   1
#define AVR32_EIC_LEVEL_INT4                                        4
#define AVR32_EIC_LEVEL_INT4_MASK                          0x00000010
#define AVR32_EIC_LEVEL_INT4_OFFSET                                 4
#define AVR32_EIC_LEVEL_INT4_SIZE                                   1
#define AVR32_EIC_LEVEL_INT5                                        5
#define AVR32_EIC_LEVEL_INT5_MASK                          0x00000020
#define AVR32_EIC_LEVEL_INT5_OFFSET                                 5
#define AVR32_EIC_LEVEL_INT5_SIZE                                   1
#define AVR32_EIC_LEVEL_INT6                                        6
#define AVR32_EIC_LEVEL_INT6_MASK                          0x00000040
#define AVR32_EIC_LEVEL_INT6_OFFSET                                 6
#define AVR32_EIC_LEVEL_INT6_SIZE                                   1
#define AVR32_EIC_LEVEL_INT7                                        7
#define AVR32_EIC_LEVEL_INT7_MASK                          0x00000080
#define AVR32_EIC_LEVEL_INT7_OFFSET                                 7
#define AVR32_EIC_LEVEL_INT7_SIZE                                   1
#define AVR32_EIC_LEVEL_NMI                                         8
#define AVR32_EIC_LEVEL_NMI_MASK                           0x00000100
#define AVR32_EIC_LEVEL_NMI_OFFSET                                  8
#define AVR32_EIC_LEVEL_NMI_SIZE                                    1
#define AVR32_EIC_MODE                                     0x00000014
#define AVR32_EIC_MODE_INT0                                         0
#define AVR32_EIC_MODE_INT0_MASK                           0x00000001
#define AVR32_EIC_MODE_INT0_OFFSET                                  0
#define AVR32_EIC_MODE_INT0_SIZE                                    1
#define AVR32_EIC_MODE_INT1                                         1
#define AVR32_EIC_MODE_INT1_MASK                           0x00000002
#define AVR32_EIC_MODE_INT1_OFFSET                                  1
#define AVR32_EIC_MODE_INT1_SIZE                                    1
#define AVR32_EIC_MODE_INT2                                         2
#define AVR32_EIC_MODE_INT2_MASK                           0x00000004
#define AVR32_EIC_MODE_INT2_OFFSET                                  2
#define AVR32_EIC_MODE_INT2_SIZE                                    1
#define AVR32_EIC_MODE_INT3                                         3
#define AVR32_EIC_MODE_INT3_MASK                           0x00000008
#define AVR32_EIC_MODE_INT3_OFFSET                                  3
#define AVR32_EIC_MODE_INT3_SIZE                                    1
#define AVR32_EIC_MODE_INT4                                         4
#define AVR32_EIC_MODE_INT4_MASK                           0x00000010
#define AVR32_EIC_MODE_INT4_OFFSET                                  4
#define AVR32_EIC_MODE_INT4_SIZE                                    1
#define AVR32_EIC_MODE_INT5                                         5
#define AVR32_EIC_MODE_INT5_MASK                           0x00000020
#define AVR32_EIC_MODE_INT5_OFFSET                                  5
#define AVR32_EIC_MODE_INT5_SIZE                                    1
#define AVR32_EIC_MODE_INT6                                         6
#define AVR32_EIC_MODE_INT6_MASK                           0x00000040
#define AVR32_EIC_MODE_INT6_OFFSET                                  6
#define AVR32_EIC_MODE_INT6_SIZE                                    1
#define AVR32_EIC_MODE_INT7                                         7
#define AVR32_EIC_MODE_INT7_MASK                           0x00000080
#define AVR32_EIC_MODE_INT7_OFFSET                                  7
#define AVR32_EIC_MODE_INT7_SIZE                                    1
#define AVR32_EIC_MODE_NMI                                          8
#define AVR32_EIC_MODE_NMI_MASK                            0x00000100
#define AVR32_EIC_MODE_NMI_OFFSET                                   8
#define AVR32_EIC_MODE_NMI_SIZE                                     1
#define AVR32_EIC_NMI                                               8
#define AVR32_EIC_NMI_MASK                                 0x00000100
#define AVR32_EIC_NMI_OFFSET                                        8
#define AVR32_EIC_NMI_SIZE                                          1
#define AVR32_EIC_PIN                                              24
#define AVR32_EIC_PIN_MASK                                 0x07000000
#define AVR32_EIC_PIN_OFFSET                                       24
#define AVR32_EIC_PIN_SIZE                                          3
#define AVR32_EIC_PRESC                                             8
#define AVR32_EIC_PRESC_MASK                               0x00001f00
#define AVR32_EIC_PRESC_OFFSET                                      8
#define AVR32_EIC_PRESC_SIZE                                        5
#define AVR32_EIC_SCAN                                     0x0000002c
#define AVR32_EIC_SCAN_EN                                           0
#define AVR32_EIC_SCAN_EN_MASK                             0x00000001
#define AVR32_EIC_SCAN_EN_OFFSET                                    0
#define AVR32_EIC_SCAN_EN_SIZE                                      1
#define AVR32_EIC_SCAN_PIN                                         24
#define AVR32_EIC_SCAN_PIN_MASK                            0x07000000
#define AVR32_EIC_SCAN_PIN_OFFSET                                  24
#define AVR32_EIC_SCAN_PIN_SIZE                                     3
#define AVR32_EIC_SCAN_PRESC                                        8
#define AVR32_EIC_SCAN_PRESC_MASK                          0x00001f00
#define AVR32_EIC_SCAN_PRESC_OFFSET                                 8
#define AVR32_EIC_SCAN_PRESC_SIZE                                   5
#define AVR32_EIC_TEST                                     0x00000024
#define AVR32_EIC_TEST_EN                                          31
#define AVR32_EIC_TEST_EN_MASK                             0x80000000
#define AVR32_EIC_TEST_EN_OFFSET                                   31
#define AVR32_EIC_TEST_EN_SIZE                                      1
#define AVR32_EIC_TEST_INT0                                         0
#define AVR32_EIC_TEST_INT0_MASK                           0x00000001
#define AVR32_EIC_TEST_INT0_OFFSET                                  0
#define AVR32_EIC_TEST_INT0_SIZE                                    1
#define AVR32_EIC_TEST_INT1                                         1
#define AVR32_EIC_TEST_INT1_MASK                           0x00000002
#define AVR32_EIC_TEST_INT1_OFFSET                                  1
#define AVR32_EIC_TEST_INT1_SIZE                                    1
#define AVR32_EIC_TEST_INT2                                         2
#define AVR32_EIC_TEST_INT2_MASK                           0x00000004
#define AVR32_EIC_TEST_INT2_OFFSET                                  2
#define AVR32_EIC_TEST_INT2_SIZE                                    1
#define AVR32_EIC_TEST_INT3                                         3
#define AVR32_EIC_TEST_INT3_MASK                           0x00000008
#define AVR32_EIC_TEST_INT3_OFFSET                                  3
#define AVR32_EIC_TEST_INT3_SIZE                                    1
#define AVR32_EIC_TEST_INT4                                         4
#define AVR32_EIC_TEST_INT4_MASK                           0x00000010
#define AVR32_EIC_TEST_INT4_OFFSET                                  4
#define AVR32_EIC_TEST_INT4_SIZE                                    1
#define AVR32_EIC_TEST_INT5                                         5
#define AVR32_EIC_TEST_INT5_MASK                           0x00000020
#define AVR32_EIC_TEST_INT5_OFFSET                                  5
#define AVR32_EIC_TEST_INT5_SIZE                                    1
#define AVR32_EIC_TEST_INT6                                         6
#define AVR32_EIC_TEST_INT6_MASK                           0x00000040
#define AVR32_EIC_TEST_INT6_OFFSET                                  6
#define AVR32_EIC_TEST_INT6_SIZE                                    1
#define AVR32_EIC_TEST_INT7                                         7
#define AVR32_EIC_TEST_INT7_MASK                           0x00000080
#define AVR32_EIC_TEST_INT7_OFFSET                                  7
#define AVR32_EIC_TEST_INT7_SIZE                                    1
#define AVR32_EIC_TEST_NMI                                          8
#define AVR32_EIC_TEST_NMI_MASK                            0x00000100
#define AVR32_EIC_TEST_NMI_OFFSET                                   8
#define AVR32_EIC_TEST_NMI_SIZE                                     1
#define AVR32_EIC_TEST_TEST_EN                                     31
#define AVR32_EIC_TEST_TEST_EN_MASK                        0x80000000
#define AVR32_EIC_TEST_TEST_EN_OFFSET                              31
#define AVR32_EIC_TEST_TEST_EN_SIZE                                 1

#define AVR32_EIC_EDGE_IRQ                             0x00000000
#define AVR32_EIC_FALLING_EDGE                         0x00000000
#define AVR32_EIC_FILTER_OFF                           0x00000000
#define AVR32_EIC_FILTER_ON                            0x00000001
#define AVR32_EIC_HIGH_LEVEL                           0x00000001
#define AVR32_EIC_LEVEL_IRQ                            0x00000001
#define AVR32_EIC_LOW_LEVEL                            0x00000000
#define AVR32_EIC_RISING_EDGE                          0x00000001
#define AVR32_EIC_SYNC                                 0x00000000
#define AVR32_EIC_USE_ASYNC                            0x00000001



#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_eic_ier_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_ier_t;



typedef struct avr32_eic_idr_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_idr_t;



typedef struct avr32_eic_imr_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_imr_t;



typedef struct avr32_eic_isr_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_isr_t;



typedef struct avr32_eic_icr_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_icr_t;



typedef struct avr32_eic_mode_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_mode_t;



typedef struct avr32_eic_edge_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_edge_t;



typedef struct avr32_eic_level_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_level_t;



typedef struct avr32_eic_filter_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_filter_t;



typedef struct avr32_eic_test_t {
    unsigned int test_en         : 1;
    unsigned int                 :22;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_test_t;



typedef struct avr32_eic_async_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_async_t;



typedef struct avr32_eic_scan_t {
    unsigned int                 : 5;
    unsigned int pin             : 3;
    unsigned int                 :11;
    unsigned int presc           : 5;
    unsigned int                 : 7;
    unsigned int en              : 1;
} avr32_eic_scan_t;



typedef struct avr32_eic_en_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_en_t;



typedef struct avr32_eic_dis_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_dis_t;



typedef struct avr32_eic_ctrl_t {
    unsigned int                 :23;
    unsigned int nmi             : 1;
    unsigned int int7            : 1;
    unsigned int int6            : 1;
    unsigned int int5            : 1;
    unsigned int int4            : 1;
    unsigned int int3            : 1;
    unsigned int int2            : 1;
    unsigned int int1            : 1;
    unsigned int int0            : 1;
} avr32_eic_ctrl_t;



typedef struct avr32_eic_t {
  union {
          unsigned long                  ier       ;//0x0000
          avr32_eic_ier_t                IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0004
          avr32_eic_idr_t                IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x0008
    const avr32_eic_imr_t                IMR       ;
  };
  union {
    const unsigned long                  isr       ;//0x000c
    const avr32_eic_isr_t                ISR       ;
  };
  union {
          unsigned long                  icr       ;//0x0010
          avr32_eic_icr_t                ICR       ;
  };
  union {
          unsigned long                  mode      ;//0x0014
          avr32_eic_mode_t               MODE      ;
  };
  union {
          unsigned long                  edge      ;//0x0018
          avr32_eic_edge_t               EDGE      ;
  };
  union {
          unsigned long                  level     ;//0x001c
          avr32_eic_level_t              LEVEL     ;
  };
  union {
          unsigned long                  filter    ;//0x0020
          avr32_eic_filter_t             FILTER    ;
  };
  union {
          unsigned long                  test      ;//0x0024
          avr32_eic_test_t               TEST      ;
  };
  union {
          unsigned long                  async     ;//0x0028
          avr32_eic_async_t              ASYNC     ;
  };
  union {
          unsigned long                  scan      ;//0x002c
          avr32_eic_scan_t               SCAN      ;
  };
  union {
          unsigned long                  en        ;//0x0030
          avr32_eic_en_t                 EN        ;
  };
  union {
          unsigned long                  dis       ;//0x0034
          avr32_eic_dis_t                DIS       ;
  };
  union {
          unsigned long                  ctrl      ;//0x0038
          avr32_eic_ctrl_t               CTRL      ;
  };
} avr32_eic_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif

/*#ifdef AVR32_EIC_230_H_INCLUDED*/
#endif

