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
#ifndef AVR32_PWM_130_H_INCLUDED
#define AVR32_PWM_130_H_INCLUDED

#define AVR32_PWM_H_VERSION 130

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_PWM_<register>
 - Bitfield mask:   AVR32_PWM_<register>_<bitfield>
 - Bitfield offset: AVR32_PWM_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_PWM_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_PWM_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_PWM_<bitfield>
 - Bitfield offset: AVR32_PWM_<bitfield>_OFFSET
 - Bitfield size:   AVR32_PWM_<bitfield>_SIZE
 - Bitfield values: AVR32_PWM_<bitfield>_<value name>
 - Bitfield values: AVR32_PWM_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_PWM_CALG                                              8
#define AVR32_PWM_CALG_MASK                                0x00000100
#define AVR32_PWM_CALG_OFFSET                                       8
#define AVR32_PWM_CALG_SIZE                                         1
#define AVR32_PWM_CCNT                                     0x0000020c
#define AVR32_PWM_CCNT_CNT                                          0
#define AVR32_PWM_CCNT_CNT_MASK                            0xffffffff
#define AVR32_PWM_CCNT_CNT_OFFSET                                   0
#define AVR32_PWM_CCNT_CNT_SIZE                                    32
#define AVR32_PWM_CDTY                                     0x00000204
#define AVR32_PWM_CDTY_CDTY                                         0
#define AVR32_PWM_CDTY_CDTY_MASK                           0xffffffff
#define AVR32_PWM_CDTY_CDTY_OFFSET                                  0
#define AVR32_PWM_CDTY_CDTY_SIZE                                   32
#define AVR32_PWM_CDTY_MASK                                0xffffffff
#define AVR32_PWM_CDTY_OFFSET                                       0
#define AVR32_PWM_CDTY_SIZE                                        32
#define AVR32_PWM_CHID0                                             0
#define AVR32_PWM_CHID0_MASK                               0x00000001
#define AVR32_PWM_CHID0_OFFSET                                      0
#define AVR32_PWM_CHID0_SIZE                                        1
#define AVR32_PWM_CHID1                                             1
#define AVR32_PWM_CHID1_MASK                               0x00000002
#define AVR32_PWM_CHID1_OFFSET                                      1
#define AVR32_PWM_CHID1_SIZE                                        1
#define AVR32_PWM_CHID2                                             2
#define AVR32_PWM_CHID2_MASK                               0x00000004
#define AVR32_PWM_CHID2_OFFSET                                      2
#define AVR32_PWM_CHID2_SIZE                                        1
#define AVR32_PWM_CHID3                                             3
#define AVR32_PWM_CHID3_MASK                               0x00000008
#define AVR32_PWM_CHID3_OFFSET                                      3
#define AVR32_PWM_CHID3_SIZE                                        1
#define AVR32_PWM_CHID4                                             4
#define AVR32_PWM_CHID4_MASK                               0x00000010
#define AVR32_PWM_CHID4_OFFSET                                      4
#define AVR32_PWM_CHID4_SIZE                                        1
#define AVR32_PWM_CHID5                                             5
#define AVR32_PWM_CHID5_MASK                               0x00000020
#define AVR32_PWM_CHID5_OFFSET                                      5
#define AVR32_PWM_CHID5_SIZE                                        1
#define AVR32_PWM_CHID6                                             6
#define AVR32_PWM_CHID6_MASK                               0x00000040
#define AVR32_PWM_CHID6_OFFSET                                      6
#define AVR32_PWM_CHID6_SIZE                                        1
#define AVR32_PWM_CLKA                                     0x0000000b
#define AVR32_PWM_CLKB                                     0x0000000c
#define AVR32_PWM_CLK_OFF                                  0x00000000
#define AVR32_PWM_CLK_SEL_PREAB                            0x00000001
#define AVR32_PWM_CMR                                      0x00000200
#define AVR32_PWM_CMR_CALG                                          8
#define AVR32_PWM_CMR_CALG_MASK                            0x00000100
#define AVR32_PWM_CMR_CALG_OFFSET                                   8
#define AVR32_PWM_CMR_CALG_SIZE                                     1
#define AVR32_PWM_CMR_CPD                                          10
#define AVR32_PWM_CMR_CPD_MASK                             0x00000400
#define AVR32_PWM_CMR_CPD_OFFSET                                   10
#define AVR32_PWM_CMR_CPD_SIZE                                      1
#define AVR32_PWM_CMR_CPOL                                          9
#define AVR32_PWM_CMR_CPOL_MASK                            0x00000200
#define AVR32_PWM_CMR_CPOL_OFFSET                                   9
#define AVR32_PWM_CMR_CPOL_SIZE                                     1
#define AVR32_PWM_CMR_CPRE                                          0
#define AVR32_PWM_CMR_CPRE_CLKA                            0x0000000b
#define AVR32_PWM_CMR_CPRE_CLKB                            0x0000000c
#define AVR32_PWM_CMR_CPRE_MASK                            0x0000000f
#define AVR32_PWM_CMR_CPRE_MCK                             0x00000000
#define AVR32_PWM_CMR_CPRE_MCK_DIV_1024                    0x0000000a
#define AVR32_PWM_CMR_CPRE_MCK_DIV_128                     0x00000007
#define AVR32_PWM_CMR_CPRE_MCK_DIV_16                      0x00000004
#define AVR32_PWM_CMR_CPRE_MCK_DIV_2                       0x00000001
#define AVR32_PWM_CMR_CPRE_MCK_DIV_256                     0x00000008
#define AVR32_PWM_CMR_CPRE_MCK_DIV_32                      0x00000005
#define AVR32_PWM_CMR_CPRE_MCK_DIV_4                       0x00000002
#define AVR32_PWM_CMR_CPRE_MCK_DIV_512                     0x00000009
#define AVR32_PWM_CMR_CPRE_MCK_DIV_64                      0x00000006
#define AVR32_PWM_CMR_CPRE_MCK_DIV_8                       0x00000003
#define AVR32_PWM_CMR_CPRE_OFFSET                                   0
#define AVR32_PWM_CMR_CPRE_SIZE                                     4
#define AVR32_PWM_CNT                                               0
#define AVR32_PWM_CNT_MASK                                 0xffffffff
#define AVR32_PWM_CNT_OFFSET                                        0
#define AVR32_PWM_CNT_SIZE                                         32
#define AVR32_PWM_CPD                                              10
#define AVR32_PWM_CPD_MASK                                 0x00000400
#define AVR32_PWM_CPD_OFFSET                                       10
#define AVR32_PWM_CPD_SIZE                                          1
#define AVR32_PWM_CPOL                                              9
#define AVR32_PWM_CPOL_MASK                                0x00000200
#define AVR32_PWM_CPOL_OFFSET                                       9
#define AVR32_PWM_CPOL_SIZE                                         1
#define AVR32_PWM_CPRD                                     0x00000208
#define AVR32_PWM_CPRD_CPRD                                         0
#define AVR32_PWM_CPRD_CPRD_MASK                           0xffffffff
#define AVR32_PWM_CPRD_CPRD_OFFSET                                  0
#define AVR32_PWM_CPRD_CPRD_SIZE                                   32
#define AVR32_PWM_CPRD_MASK                                0xffffffff
#define AVR32_PWM_CPRD_OFFSET                                       0
#define AVR32_PWM_CPRD_SIZE                                        32
#define AVR32_PWM_CPRE                                              0
#define AVR32_PWM_CPRE_CLKA                                0x0000000b
#define AVR32_PWM_CPRE_CLKB                                0x0000000c
#define AVR32_PWM_CPRE_MASK                                0x0000000f
#define AVR32_PWM_CPRE_MCK                                 0x00000000
#define AVR32_PWM_CPRE_MCK_DIV_1024                        0x0000000a
#define AVR32_PWM_CPRE_MCK_DIV_128                         0x00000007
#define AVR32_PWM_CPRE_MCK_DIV_16                          0x00000004
#define AVR32_PWM_CPRE_MCK_DIV_2                           0x00000001
#define AVR32_PWM_CPRE_MCK_DIV_256                         0x00000008
#define AVR32_PWM_CPRE_MCK_DIV_32                          0x00000005
#define AVR32_PWM_CPRE_MCK_DIV_4                           0x00000002
#define AVR32_PWM_CPRE_MCK_DIV_512                         0x00000009
#define AVR32_PWM_CPRE_MCK_DIV_64                          0x00000006
#define AVR32_PWM_CPRE_MCK_DIV_8                           0x00000003
#define AVR32_PWM_CPRE_OFFSET                                       0
#define AVR32_PWM_CPRE_SIZE                                         4
#define AVR32_PWM_CUPD                                     0x00000210
#define AVR32_PWM_CUPD_CUPD                                         0
#define AVR32_PWM_CUPD_CUPD_MASK                           0xffffffff
#define AVR32_PWM_CUPD_CUPD_OFFSET                                  0
#define AVR32_PWM_CUPD_CUPD_SIZE                                   32
#define AVR32_PWM_CUPD_MASK                                0xffffffff
#define AVR32_PWM_CUPD_OFFSET                                       0
#define AVR32_PWM_CUPD_SIZE                                        32
#define AVR32_PWM_DIS                                      0x00000008
#define AVR32_PWM_DIS_CHID0                                         0
#define AVR32_PWM_DIS_CHID0_MASK                           0x00000001
#define AVR32_PWM_DIS_CHID0_OFFSET                                  0
#define AVR32_PWM_DIS_CHID0_SIZE                                    1
#define AVR32_PWM_DIS_CHID1                                         1
#define AVR32_PWM_DIS_CHID1_MASK                           0x00000002
#define AVR32_PWM_DIS_CHID1_OFFSET                                  1
#define AVR32_PWM_DIS_CHID1_SIZE                                    1
#define AVR32_PWM_DIS_CHID2                                         2
#define AVR32_PWM_DIS_CHID2_MASK                           0x00000004
#define AVR32_PWM_DIS_CHID2_OFFSET                                  2
#define AVR32_PWM_DIS_CHID2_SIZE                                    1
#define AVR32_PWM_DIS_CHID3                                         3
#define AVR32_PWM_DIS_CHID3_MASK                           0x00000008
#define AVR32_PWM_DIS_CHID3_OFFSET                                  3
#define AVR32_PWM_DIS_CHID3_SIZE                                    1
#define AVR32_PWM_DIS_CHID4                                         4
#define AVR32_PWM_DIS_CHID4_MASK                           0x00000010
#define AVR32_PWM_DIS_CHID4_OFFSET                                  4
#define AVR32_PWM_DIS_CHID4_SIZE                                    1
#define AVR32_PWM_DIS_CHID5                                         5
#define AVR32_PWM_DIS_CHID5_MASK                           0x00000020
#define AVR32_PWM_DIS_CHID5_OFFSET                                  5
#define AVR32_PWM_DIS_CHID5_SIZE                                    1
#define AVR32_PWM_DIS_CHID6                                         6
#define AVR32_PWM_DIS_CHID6_MASK                           0x00000040
#define AVR32_PWM_DIS_CHID6_OFFSET                                  6
#define AVR32_PWM_DIS_CHID6_SIZE                                    1
#define AVR32_PWM_DIVA                                              0
#define AVR32_PWM_DIVA_CLK_OFF                             0x00000000
#define AVR32_PWM_DIVA_CLK_SEL_PREAB                       0x00000001
#define AVR32_PWM_DIVA_MASK                                0x000000ff
#define AVR32_PWM_DIVA_OFFSET                                       0
#define AVR32_PWM_DIVA_SIZE                                         8
#define AVR32_PWM_DIVB                                             16
#define AVR32_PWM_DIVB_CLK_OFF                             0x00000000
#define AVR32_PWM_DIVB_CLK_SEL_PREAB                       0x00000001
#define AVR32_PWM_DIVB_MASK                                0x00ff0000
#define AVR32_PWM_DIVB_OFFSET                                      16
#define AVR32_PWM_DIVB_SIZE                                         8
#define AVR32_PWM_ENA                                      0x00000004
#define AVR32_PWM_ENA_CHID0                                         0
#define AVR32_PWM_ENA_CHID0_MASK                           0x00000001
#define AVR32_PWM_ENA_CHID0_OFFSET                                  0
#define AVR32_PWM_ENA_CHID0_SIZE                                    1
#define AVR32_PWM_ENA_CHID1                                         1
#define AVR32_PWM_ENA_CHID1_MASK                           0x00000002
#define AVR32_PWM_ENA_CHID1_OFFSET                                  1
#define AVR32_PWM_ENA_CHID1_SIZE                                    1
#define AVR32_PWM_ENA_CHID2                                         2
#define AVR32_PWM_ENA_CHID2_MASK                           0x00000004
#define AVR32_PWM_ENA_CHID2_OFFSET                                  2
#define AVR32_PWM_ENA_CHID2_SIZE                                    1
#define AVR32_PWM_ENA_CHID3                                         3
#define AVR32_PWM_ENA_CHID3_MASK                           0x00000008
#define AVR32_PWM_ENA_CHID3_OFFSET                                  3
#define AVR32_PWM_ENA_CHID3_SIZE                                    1
#define AVR32_PWM_ENA_CHID4                                         4
#define AVR32_PWM_ENA_CHID4_MASK                           0x00000010
#define AVR32_PWM_ENA_CHID4_OFFSET                                  4
#define AVR32_PWM_ENA_CHID4_SIZE                                    1
#define AVR32_PWM_ENA_CHID5                                         5
#define AVR32_PWM_ENA_CHID5_MASK                           0x00000020
#define AVR32_PWM_ENA_CHID5_OFFSET                                  5
#define AVR32_PWM_ENA_CHID5_SIZE                                    1
#define AVR32_PWM_ENA_CHID6                                         6
#define AVR32_PWM_ENA_CHID6_MASK                           0x00000040
#define AVR32_PWM_ENA_CHID6_OFFSET                                  6
#define AVR32_PWM_ENA_CHID6_SIZE                                    1
#define AVR32_PWM_IDR                                      0x00000014
#define AVR32_PWM_IDR_CHID0                                         0
#define AVR32_PWM_IDR_CHID0_MASK                           0x00000001
#define AVR32_PWM_IDR_CHID0_OFFSET                                  0
#define AVR32_PWM_IDR_CHID0_SIZE                                    1
#define AVR32_PWM_IDR_CHID1                                         1
#define AVR32_PWM_IDR_CHID1_MASK                           0x00000002
#define AVR32_PWM_IDR_CHID1_OFFSET                                  1
#define AVR32_PWM_IDR_CHID1_SIZE                                    1
#define AVR32_PWM_IDR_CHID2                                         2
#define AVR32_PWM_IDR_CHID2_MASK                           0x00000004
#define AVR32_PWM_IDR_CHID2_OFFSET                                  2
#define AVR32_PWM_IDR_CHID2_SIZE                                    1
#define AVR32_PWM_IDR_CHID3                                         3
#define AVR32_PWM_IDR_CHID3_MASK                           0x00000008
#define AVR32_PWM_IDR_CHID3_OFFSET                                  3
#define AVR32_PWM_IDR_CHID3_SIZE                                    1
#define AVR32_PWM_IDR_CHID4                                         4
#define AVR32_PWM_IDR_CHID4_MASK                           0x00000010
#define AVR32_PWM_IDR_CHID4_OFFSET                                  4
#define AVR32_PWM_IDR_CHID4_SIZE                                    1
#define AVR32_PWM_IDR_CHID5                                         5
#define AVR32_PWM_IDR_CHID5_MASK                           0x00000020
#define AVR32_PWM_IDR_CHID5_OFFSET                                  5
#define AVR32_PWM_IDR_CHID5_SIZE                                    1
#define AVR32_PWM_IDR_CHID6                                         6
#define AVR32_PWM_IDR_CHID6_MASK                           0x00000040
#define AVR32_PWM_IDR_CHID6_OFFSET                                  6
#define AVR32_PWM_IDR_CHID6_SIZE                                    1
#define AVR32_PWM_IER                                      0x00000010
#define AVR32_PWM_IER_CHID0                                         0
#define AVR32_PWM_IER_CHID0_MASK                           0x00000001
#define AVR32_PWM_IER_CHID0_OFFSET                                  0
#define AVR32_PWM_IER_CHID0_SIZE                                    1
#define AVR32_PWM_IER_CHID1                                         1
#define AVR32_PWM_IER_CHID1_MASK                           0x00000002
#define AVR32_PWM_IER_CHID1_OFFSET                                  1
#define AVR32_PWM_IER_CHID1_SIZE                                    1
#define AVR32_PWM_IER_CHID2                                         2
#define AVR32_PWM_IER_CHID2_MASK                           0x00000004
#define AVR32_PWM_IER_CHID2_OFFSET                                  2
#define AVR32_PWM_IER_CHID2_SIZE                                    1
#define AVR32_PWM_IER_CHID3                                         3
#define AVR32_PWM_IER_CHID3_MASK                           0x00000008
#define AVR32_PWM_IER_CHID3_OFFSET                                  3
#define AVR32_PWM_IER_CHID3_SIZE                                    1
#define AVR32_PWM_IER_CHID4                                         4
#define AVR32_PWM_IER_CHID4_MASK                           0x00000010
#define AVR32_PWM_IER_CHID4_OFFSET                                  4
#define AVR32_PWM_IER_CHID4_SIZE                                    1
#define AVR32_PWM_IER_CHID5                                         5
#define AVR32_PWM_IER_CHID5_MASK                           0x00000020
#define AVR32_PWM_IER_CHID5_OFFSET                                  5
#define AVR32_PWM_IER_CHID5_SIZE                                    1
#define AVR32_PWM_IER_CHID6                                         6
#define AVR32_PWM_IER_CHID6_MASK                           0x00000040
#define AVR32_PWM_IER_CHID6_OFFSET                                  6
#define AVR32_PWM_IER_CHID6_SIZE                                    1
#define AVR32_PWM_IMR                                      0x00000018
#define AVR32_PWM_IMR_CHID0                                         0
#define AVR32_PWM_IMR_CHID0_MASK                           0x00000001
#define AVR32_PWM_IMR_CHID0_OFFSET                                  0
#define AVR32_PWM_IMR_CHID0_SIZE                                    1
#define AVR32_PWM_IMR_CHID1                                         1
#define AVR32_PWM_IMR_CHID1_MASK                           0x00000002
#define AVR32_PWM_IMR_CHID1_OFFSET                                  1
#define AVR32_PWM_IMR_CHID1_SIZE                                    1
#define AVR32_PWM_IMR_CHID2                                         2
#define AVR32_PWM_IMR_CHID2_MASK                           0x00000004
#define AVR32_PWM_IMR_CHID2_OFFSET                                  2
#define AVR32_PWM_IMR_CHID2_SIZE                                    1
#define AVR32_PWM_IMR_CHID3                                         3
#define AVR32_PWM_IMR_CHID3_MASK                           0x00000008
#define AVR32_PWM_IMR_CHID3_OFFSET                                  3
#define AVR32_PWM_IMR_CHID3_SIZE                                    1
#define AVR32_PWM_IMR_CHID4                                         4
#define AVR32_PWM_IMR_CHID4_MASK                           0x00000010
#define AVR32_PWM_IMR_CHID4_OFFSET                                  4
#define AVR32_PWM_IMR_CHID4_SIZE                                    1
#define AVR32_PWM_IMR_CHID5                                         5
#define AVR32_PWM_IMR_CHID5_MASK                           0x00000020
#define AVR32_PWM_IMR_CHID5_OFFSET                                  5
#define AVR32_PWM_IMR_CHID5_SIZE                                    1
#define AVR32_PWM_IMR_CHID6                                         6
#define AVR32_PWM_IMR_CHID6_MASK                           0x00000040
#define AVR32_PWM_IMR_CHID6_OFFSET                                  6
#define AVR32_PWM_IMR_CHID6_SIZE                                    1
#define AVR32_PWM_ISR                                      0x0000001c
#define AVR32_PWM_ISR_CHID0                                         0
#define AVR32_PWM_ISR_CHID0_MASK                           0x00000001
#define AVR32_PWM_ISR_CHID0_OFFSET                                  0
#define AVR32_PWM_ISR_CHID0_SIZE                                    1
#define AVR32_PWM_ISR_CHID1                                         1
#define AVR32_PWM_ISR_CHID1_MASK                           0x00000002
#define AVR32_PWM_ISR_CHID1_OFFSET                                  1
#define AVR32_PWM_ISR_CHID1_SIZE                                    1
#define AVR32_PWM_ISR_CHID2                                         2
#define AVR32_PWM_ISR_CHID2_MASK                           0x00000004
#define AVR32_PWM_ISR_CHID2_OFFSET                                  2
#define AVR32_PWM_ISR_CHID2_SIZE                                    1
#define AVR32_PWM_ISR_CHID3                                         3
#define AVR32_PWM_ISR_CHID3_MASK                           0x00000008
#define AVR32_PWM_ISR_CHID3_OFFSET                                  3
#define AVR32_PWM_ISR_CHID3_SIZE                                    1
#define AVR32_PWM_ISR_CHID4                                         4
#define AVR32_PWM_ISR_CHID4_MASK                           0x00000010
#define AVR32_PWM_ISR_CHID4_OFFSET                                  4
#define AVR32_PWM_ISR_CHID4_SIZE                                    1
#define AVR32_PWM_ISR_CHID5                                         5
#define AVR32_PWM_ISR_CHID5_MASK                           0x00000020
#define AVR32_PWM_ISR_CHID5_OFFSET                                  5
#define AVR32_PWM_ISR_CHID5_SIZE                                    1
#define AVR32_PWM_ISR_CHID6                                         6
#define AVR32_PWM_ISR_CHID6_MASK                           0x00000040
#define AVR32_PWM_ISR_CHID6_OFFSET                                  6
#define AVR32_PWM_ISR_CHID6_SIZE                                    1
#define AVR32_PWM_MCK                                      0x00000000
#define AVR32_PWM_MCK_DIV_1024                             0x0000000a
#define AVR32_PWM_MCK_DIV_128                              0x00000007
#define AVR32_PWM_MCK_DIV_16                               0x00000004
#define AVR32_PWM_MCK_DIV_2                                0x00000001
#define AVR32_PWM_MCK_DIV_256                              0x00000008
#define AVR32_PWM_MCK_DIV_32                               0x00000005
#define AVR32_PWM_MCK_DIV_4                                0x00000002
#define AVR32_PWM_MCK_DIV_512                              0x00000009
#define AVR32_PWM_MCK_DIV_64                               0x00000006
#define AVR32_PWM_MCK_DIV_8                                0x00000003
#define AVR32_PWM_MR                                       0x00000000
#define AVR32_PWM_MR_DIVA                                           0
#define AVR32_PWM_MR_DIVA_CLK_OFF                          0x00000000
#define AVR32_PWM_MR_DIVA_CLK_SEL_PREAB                    0x00000001
#define AVR32_PWM_MR_DIVA_MASK                             0x000000ff
#define AVR32_PWM_MR_DIVA_OFFSET                                    0
#define AVR32_PWM_MR_DIVA_SIZE                                      8
#define AVR32_PWM_MR_DIVB                                          16
#define AVR32_PWM_MR_DIVB_CLK_OFF                          0x00000000
#define AVR32_PWM_MR_DIVB_CLK_SEL_PREAB                    0x00000001
#define AVR32_PWM_MR_DIVB_MASK                             0x00ff0000
#define AVR32_PWM_MR_DIVB_OFFSET                                   16
#define AVR32_PWM_MR_DIVB_SIZE                                      8
#define AVR32_PWM_MR_PREA                                           8
#define AVR32_PWM_MR_PREA_MASK                             0x00000f00
#define AVR32_PWM_MR_PREA_MCK                              0x00000000
#define AVR32_PWM_MR_PREA_MCK_DIV_1024                     0x0000000a
#define AVR32_PWM_MR_PREA_MCK_DIV_128                      0x00000007
#define AVR32_PWM_MR_PREA_MCK_DIV_16                       0x00000004
#define AVR32_PWM_MR_PREA_MCK_DIV_2                        0x00000001
#define AVR32_PWM_MR_PREA_MCK_DIV_256                      0x00000008
#define AVR32_PWM_MR_PREA_MCK_DIV_32                       0x00000005
#define AVR32_PWM_MR_PREA_MCK_DIV_4                        0x00000002
#define AVR32_PWM_MR_PREA_MCK_DIV_512                      0x00000009
#define AVR32_PWM_MR_PREA_MCK_DIV_64                       0x00000006
#define AVR32_PWM_MR_PREA_MCK_DIV_8                        0x00000003
#define AVR32_PWM_MR_PREA_OFFSET                                    8
#define AVR32_PWM_MR_PREA_SIZE                                      4
#define AVR32_PWM_MR_PREB                                          24
#define AVR32_PWM_MR_PREB_MASK                             0x0f000000
#define AVR32_PWM_MR_PREB_MCK                              0x00000000
#define AVR32_PWM_MR_PREB_MCK_DIV_1024                     0x0000000a
#define AVR32_PWM_MR_PREB_MCK_DIV_128                      0x00000007
#define AVR32_PWM_MR_PREB_MCK_DIV_16                       0x00000004
#define AVR32_PWM_MR_PREB_MCK_DIV_2                        0x00000001
#define AVR32_PWM_MR_PREB_MCK_DIV_256                      0x00000008
#define AVR32_PWM_MR_PREB_MCK_DIV_32                       0x00000005
#define AVR32_PWM_MR_PREB_MCK_DIV_4                        0x00000002
#define AVR32_PWM_MR_PREB_MCK_DIV_512                      0x00000009
#define AVR32_PWM_MR_PREB_MCK_DIV_64                       0x00000006
#define AVR32_PWM_MR_PREB_MCK_DIV_8                        0x00000003
#define AVR32_PWM_MR_PREB_OFFSET                                   24
#define AVR32_PWM_MR_PREB_SIZE                                      4
#define AVR32_PWM_PREA                                              8
#define AVR32_PWM_PREA_MASK                                0x00000f00
#define AVR32_PWM_PREA_MCK                                 0x00000000
#define AVR32_PWM_PREA_MCK_DIV_1024                        0x0000000a
#define AVR32_PWM_PREA_MCK_DIV_128                         0x00000007
#define AVR32_PWM_PREA_MCK_DIV_16                          0x00000004
#define AVR32_PWM_PREA_MCK_DIV_2                           0x00000001
#define AVR32_PWM_PREA_MCK_DIV_256                         0x00000008
#define AVR32_PWM_PREA_MCK_DIV_32                          0x00000005
#define AVR32_PWM_PREA_MCK_DIV_4                           0x00000002
#define AVR32_PWM_PREA_MCK_DIV_512                         0x00000009
#define AVR32_PWM_PREA_MCK_DIV_64                          0x00000006
#define AVR32_PWM_PREA_MCK_DIV_8                           0x00000003
#define AVR32_PWM_PREA_OFFSET                                       8
#define AVR32_PWM_PREA_SIZE                                         4
#define AVR32_PWM_PREB                                             24
#define AVR32_PWM_PREB_MASK                                0x0f000000
#define AVR32_PWM_PREB_MCK                                 0x00000000
#define AVR32_PWM_PREB_MCK_DIV_1024                        0x0000000a
#define AVR32_PWM_PREB_MCK_DIV_128                         0x00000007
#define AVR32_PWM_PREB_MCK_DIV_16                          0x00000004
#define AVR32_PWM_PREB_MCK_DIV_2                           0x00000001
#define AVR32_PWM_PREB_MCK_DIV_256                         0x00000008
#define AVR32_PWM_PREB_MCK_DIV_32                          0x00000005
#define AVR32_PWM_PREB_MCK_DIV_4                           0x00000002
#define AVR32_PWM_PREB_MCK_DIV_512                         0x00000009
#define AVR32_PWM_PREB_MCK_DIV_64                          0x00000006
#define AVR32_PWM_PREB_MCK_DIV_8                           0x00000003
#define AVR32_PWM_PREB_OFFSET                                      24
#define AVR32_PWM_PREB_SIZE                                         4
#define AVR32_PWM_SR                                       0x0000000c
#define AVR32_PWM_SR_CHID0                                          0
#define AVR32_PWM_SR_CHID0_MASK                            0x00000001
#define AVR32_PWM_SR_CHID0_OFFSET                                   0
#define AVR32_PWM_SR_CHID0_SIZE                                     1
#define AVR32_PWM_SR_CHID1                                          1
#define AVR32_PWM_SR_CHID1_MASK                            0x00000002
#define AVR32_PWM_SR_CHID1_OFFSET                                   1
#define AVR32_PWM_SR_CHID1_SIZE                                     1
#define AVR32_PWM_SR_CHID2                                          2
#define AVR32_PWM_SR_CHID2_MASK                            0x00000004
#define AVR32_PWM_SR_CHID2_OFFSET                                   2
#define AVR32_PWM_SR_CHID2_SIZE                                     1
#define AVR32_PWM_SR_CHID3                                          3
#define AVR32_PWM_SR_CHID3_MASK                            0x00000008
#define AVR32_PWM_SR_CHID3_OFFSET                                   3
#define AVR32_PWM_SR_CHID3_SIZE                                     1
#define AVR32_PWM_SR_CHID4                                          4
#define AVR32_PWM_SR_CHID4_MASK                            0x00000010
#define AVR32_PWM_SR_CHID4_OFFSET                                   4
#define AVR32_PWM_SR_CHID4_SIZE                                     1
#define AVR32_PWM_SR_CHID5                                          5
#define AVR32_PWM_SR_CHID5_MASK                            0x00000020
#define AVR32_PWM_SR_CHID5_OFFSET                                   5
#define AVR32_PWM_SR_CHID5_SIZE                                     1
#define AVR32_PWM_SR_CHID6                                          6
#define AVR32_PWM_SR_CHID6_MASK                            0x00000040
#define AVR32_PWM_SR_CHID6_OFFSET                                   6
#define AVR32_PWM_SR_CHID6_SIZE                                     1
#define AVR32_PWM_VARIANT                                          16
#define AVR32_PWM_VARIANT_MASK                             0x00070000
#define AVR32_PWM_VARIANT_OFFSET                                   16
#define AVR32_PWM_VARIANT_SIZE                                      3
#define AVR32_PWM_VERSION                                  0x000000fc
#define AVR32_PWM_VERSION_MASK                             0x00000fff
#define AVR32_PWM_VERSION_OFFSET                                    0
#define AVR32_PWM_VERSION_SIZE                                     12
#define AVR32_PWM_VERSION_VARIANT                                  16
#define AVR32_PWM_VERSION_VARIANT_MASK                     0x00070000
#define AVR32_PWM_VERSION_VARIANT_OFFSET                           16
#define AVR32_PWM_VERSION_VARIANT_SIZE                              3
#define AVR32_PWM_VERSION_VERSION                                   0
#define AVR32_PWM_VERSION_VERSION_MASK                     0x00000fff
#define AVR32_PWM_VERSION_VERSION_OFFSET                            0
#define AVR32_PWM_VERSION_VERSION_SIZE                             12




#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_pwm_mr_t {
    unsigned int                 : 4;
    unsigned int preb            : 4;
    unsigned int divb            : 8;
    unsigned int                 : 4;
    unsigned int prea            : 4;
    unsigned int diva            : 8;
} avr32_pwm_mr_t;



typedef struct avr32_pwm_ena_t {
    unsigned int                 :25;
    unsigned int chid6           : 1;
    unsigned int chid5           : 1;
    unsigned int chid4           : 1;
    unsigned int chid3           : 1;
    unsigned int chid2           : 1;
    unsigned int chid1           : 1;
    unsigned int chid0           : 1;
} avr32_pwm_ena_t;



typedef struct avr32_pwm_dis_t {
    unsigned int                 :25;
    unsigned int chid6           : 1;
    unsigned int chid5           : 1;
    unsigned int chid4           : 1;
    unsigned int chid3           : 1;
    unsigned int chid2           : 1;
    unsigned int chid1           : 1;
    unsigned int chid0           : 1;
} avr32_pwm_dis_t;



typedef struct avr32_pwm_sr_t {
    unsigned int                 :25;
    unsigned int chid6           : 1;
    unsigned int chid5           : 1;
    unsigned int chid4           : 1;
    unsigned int chid3           : 1;
    unsigned int chid2           : 1;
    unsigned int chid1           : 1;
    unsigned int chid0           : 1;
} avr32_pwm_sr_t;



typedef struct avr32_pwm_ier_t {
    unsigned int                 :25;
    unsigned int chid6           : 1;
    unsigned int chid5           : 1;
    unsigned int chid4           : 1;
    unsigned int chid3           : 1;
    unsigned int chid2           : 1;
    unsigned int chid1           : 1;
    unsigned int chid0           : 1;
} avr32_pwm_ier_t;



typedef struct avr32_pwm_idr_t {
    unsigned int                 :25;
    unsigned int chid6           : 1;
    unsigned int chid5           : 1;
    unsigned int chid4           : 1;
    unsigned int chid3           : 1;
    unsigned int chid2           : 1;
    unsigned int chid1           : 1;
    unsigned int chid0           : 1;
} avr32_pwm_idr_t;



typedef struct avr32_pwm_imr_t {
    unsigned int                 :25;
    unsigned int chid6           : 1;
    unsigned int chid5           : 1;
    unsigned int chid4           : 1;
    unsigned int chid3           : 1;
    unsigned int chid2           : 1;
    unsigned int chid1           : 1;
    unsigned int chid0           : 1;
} avr32_pwm_imr_t;



typedef struct avr32_pwm_isr_t {
    unsigned int                 :25;
    unsigned int chid6           : 1;
    unsigned int chid5           : 1;
    unsigned int chid4           : 1;
    unsigned int chid3           : 1;
    unsigned int chid2           : 1;
    unsigned int chid1           : 1;
    unsigned int chid0           : 1;
} avr32_pwm_isr_t;



typedef struct avr32_pwm_version_t {
    unsigned int                 :13;
    unsigned int variant         : 3;
    unsigned int                 : 4;
    unsigned int version         :12;
} avr32_pwm_version_t;



typedef struct avr32_pwm_cmr_t {
    unsigned int                 :21;
    unsigned int cpd             : 1;
    unsigned int cpol            : 1;
    unsigned int calg            : 1;
    unsigned int                 : 4;
    unsigned int cpre            : 4;
} avr32_pwm_cmr_t;


typedef struct avr32_pwm_channel_t {
  union {
          unsigned long                  cmr       ;//0x0000
          avr32_pwm_cmr_t                CMR       ;
  };
          unsigned long                  cdty      ;//0x0004
          unsigned long                  cprd      ;//0x0008
    const unsigned long                  ccnt      ;//0x000c
          unsigned long                  cupd      ;//0x0010
          unsigned int                   :32       ;//0x0014
          unsigned int                   :32       ;//0x0018
          unsigned int                   :32       ;//0x001c
} avr32_pwm_channel_t;


typedef struct avr32_pwm_t {
  union {
          unsigned long                  mr        ;//0x0000
          avr32_pwm_mr_t                 MR        ;
  };
  union {
          unsigned long                  ena       ;//0x0004
          avr32_pwm_ena_t                ENA       ;
  };
  union {
          unsigned long                  dis       ;//0x0008
          avr32_pwm_dis_t                DIS       ;
  };
  union {
    const unsigned long                  sr        ;//0x000c
    const avr32_pwm_sr_t                 SR        ;
  };
  union {
          unsigned long                  ier       ;//0x0010
          avr32_pwm_ier_t                IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0014
          avr32_pwm_idr_t                IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x0018
    const avr32_pwm_imr_t                IMR       ;
  };
  union {
    const unsigned long                  isr       ;//0x001c
    const avr32_pwm_isr_t                ISR       ;
  };
          unsigned int                   :32       ;//0x0020
          unsigned int                   :32       ;//0x0024
          unsigned int                   :32       ;//0x0028
          unsigned int                   :32       ;//0x002c
          unsigned int                   :32       ;//0x0030
          unsigned int                   :32       ;//0x0034
          unsigned int                   :32       ;//0x0038
          unsigned int                   :32       ;//0x003c
          unsigned int                   :32       ;//0x0040
          unsigned int                   :32       ;//0x0044
          unsigned int                   :32       ;//0x0048
          unsigned int                   :32       ;//0x004c
          unsigned int                   :32       ;//0x0050
          unsigned int                   :32       ;//0x0054
          unsigned int                   :32       ;//0x0058
          unsigned int                   :32       ;//0x005c
          unsigned int                   :32       ;//0x0060
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
  union {
    const unsigned long                  version   ;//0x00fc
    const avr32_pwm_version_t            VERSION   ;
  };
          unsigned int                   :32       ;//0x0100
          unsigned int                   :32       ;//0x0104
          unsigned int                   :32       ;//0x0108
          unsigned int                   :32       ;//0x010c
          unsigned int                   :32       ;//0x0110
          unsigned int                   :32       ;//0x0114
          unsigned int                   :32       ;//0x0118
          unsigned int                   :32       ;//0x011c
          unsigned int                   :32       ;//0x0120
          unsigned int                   :32       ;//0x0124
          unsigned int                   :32       ;//0x0128
          unsigned int                   :32       ;//0x012c
          unsigned int                   :32       ;//0x0130
          unsigned int                   :32       ;//0x0134
          unsigned int                   :32       ;//0x0138
          unsigned int                   :32       ;//0x013c
          unsigned int                   :32       ;//0x0140
          unsigned int                   :32       ;//0x0144
          unsigned int                   :32       ;//0x0148
          unsigned int                   :32       ;//0x014c
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
          unsigned int                   :32       ;//0x01fc
  avr32_pwm_channel_t channel[AVR32_PWM_CHANNEL_LENGTH];//0x200
} avr32_pwm_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif


#if !defined (DEPRECATED_DISABLE)

#define AVR32_PWM_CCNT0                                    0x0000020c
#define AVR32_PWM_CCNT0_CNT                                         0
#define AVR32_PWM_CCNT0_CNT_MASK                           0xffffffff
#define AVR32_PWM_CCNT0_CNT_OFFSET                                  0
#define AVR32_PWM_CCNT0_CNT_SIZE                                   32

#define AVR32_PWM_CDTY0                                    0x00000204
#define AVR32_PWM_CDTY0_CDTY                                        0
#define AVR32_PWM_CDTY0_CDTY_MASK                          0xffffffff
#define AVR32_PWM_CDTY0_CDTY_OFFSET                                 0
#define AVR32_PWM_CDTY0_CDTY_SIZE                                  32

#define AVR32_PWM_CMR0                                     0x00000200
#define AVR32_PWM_CMR0_CALG                                         8
#define AVR32_PWM_CMR0_CALG_MASK                           0x00000100
#define AVR32_PWM_CMR0_CALG_OFFSET                                  8
#define AVR32_PWM_CMR0_CALG_SIZE                                    1
#define AVR32_PWM_CMR0_CPD                                         10
#define AVR32_PWM_CMR0_CPD_MASK                            0x00000400
#define AVR32_PWM_CMR0_CPD_OFFSET                                  10
#define AVR32_PWM_CMR0_CPD_SIZE                                     1
#define AVR32_PWM_CMR0_CPOL                                         9
#define AVR32_PWM_CMR0_CPOL_MASK                           0x00000200
#define AVR32_PWM_CMR0_CPOL_OFFSET                                  9
#define AVR32_PWM_CMR0_CPOL_SIZE                                    1
#define AVR32_PWM_CMR0_CPRE                                         0
#define AVR32_PWM_CMR0_CPRE_CLKA                           0x0000000b
#define AVR32_PWM_CMR0_CPRE_CLKB                           0x0000000c
#define AVR32_PWM_CMR0_CPRE_MASK                           0x0000000f
#define AVR32_PWM_CMR0_CPRE_MCK                            0x00000000
#define AVR32_PWM_CMR0_CPRE_MCK_DIV_1024                   0x0000000a
#define AVR32_PWM_CMR0_CPRE_MCK_DIV_128                    0x00000007
#define AVR32_PWM_CMR0_CPRE_MCK_DIV_16                     0x00000004
#define AVR32_PWM_CMR0_CPRE_MCK_DIV_2                      0x00000001
#define AVR32_PWM_CMR0_CPRE_MCK_DIV_256                    0x00000008
#define AVR32_PWM_CMR0_CPRE_MCK_DIV_32                     0x00000005
#define AVR32_PWM_CMR0_CPRE_MCK_DIV_4                      0x00000002
#define AVR32_PWM_CMR0_CPRE_MCK_DIV_512                    0x00000009
#define AVR32_PWM_CMR0_CPRE_MCK_DIV_64                     0x00000006
#define AVR32_PWM_CMR0_CPRE_MCK_DIV_8                      0x00000003
#define AVR32_PWM_CMR0_CPRE_OFFSET                                  0
#define AVR32_PWM_CMR0_CPRE_SIZE                                    4

#define AVR32_PWM_CPRD0                                    0x00000208
#define AVR32_PWM_CPRD0_CPRD                                        0
#define AVR32_PWM_CPRD0_CPRD_MASK                          0xffffffff
#define AVR32_PWM_CPRD0_CPRD_OFFSET                                 0
#define AVR32_PWM_CPRD0_CPRD_SIZE                                  32

#define AVR32_PWM_CUPD0                                    0x00000210
#define AVR32_PWM_CUPD0_CUPD                                        0
#define AVR32_PWM_CUPD0_CUPD_MASK                          0xffffffff
#define AVR32_PWM_CUPD0_CUPD_OFFSET                                 0
#define AVR32_PWM_CUPD0_CUPD_SIZE                                  32

#endif


/*#ifdef AVR32_PWM_130_H_INCLUDED*/
#endif

