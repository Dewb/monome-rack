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
#ifndef AVR32_TC_222_H_INCLUDED
#define AVR32_TC_222_H_INCLUDED

#define AVR32_TC_H_VERSION 222

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_TC_<register>
 - Bitfield mask:   AVR32_TC_<register>_<bitfield>
 - Bitfield offset: AVR32_TC_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_TC_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_TC_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_TC_<bitfield>
 - Bitfield offset: AVR32_TC_<bitfield>_OFFSET
 - Bitfield size:   AVR32_TC_<bitfield>_SIZE
 - Bitfield values: AVR32_TC_<bitfield>_<value name>
 - Bitfield values: AVR32_TC_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_TC_ABETRG                                           10
#define AVR32_TC_ABETRG_MASK                              0x00000400
#define AVR32_TC_ABETRG_OFFSET                                    10
#define AVR32_TC_ABETRG_SIZE                                       1
#define AVR32_TC_ACPA                                             16
#define AVR32_TC_ACPA_CLEAR                               0x00000002
#define AVR32_TC_ACPA_MASK                                0x00030000
#define AVR32_TC_ACPA_NONE                                0x00000000
#define AVR32_TC_ACPA_OFFSET                                      16
#define AVR32_TC_ACPA_SET                                 0x00000001
#define AVR32_TC_ACPA_SIZE                                         2
#define AVR32_TC_ACPA_TOGGLE                              0x00000003
#define AVR32_TC_ACPC                                             18
#define AVR32_TC_ACPC_CLEAR                               0x00000002
#define AVR32_TC_ACPC_MASK                                0x000c0000
#define AVR32_TC_ACPC_NONE                                0x00000000
#define AVR32_TC_ACPC_OFFSET                                      18
#define AVR32_TC_ACPC_SET                                 0x00000001
#define AVR32_TC_ACPC_SIZE                                         2
#define AVR32_TC_ACPC_TOGGLE                              0x00000003
#define AVR32_TC_AEEVT                                            20
#define AVR32_TC_AEEVT_CLEAR                              0x00000002
#define AVR32_TC_AEEVT_MASK                               0x00300000
#define AVR32_TC_AEEVT_NONE                               0x00000000
#define AVR32_TC_AEEVT_OFFSET                                     20
#define AVR32_TC_AEEVT_SET                                0x00000001
#define AVR32_TC_AEEVT_SIZE                                        2
#define AVR32_TC_AEEVT_TOGGLE                             0x00000003
#define AVR32_TC_ASWTRG                                           22
#define AVR32_TC_ASWTRG_CLEAR                             0x00000002
#define AVR32_TC_ASWTRG_MASK                              0x00c00000
#define AVR32_TC_ASWTRG_NONE                              0x00000000
#define AVR32_TC_ASWTRG_OFFSET                                    22
#define AVR32_TC_ASWTRG_SET                               0x00000001
#define AVR32_TC_ASWTRG_SIZE                                       2
#define AVR32_TC_ASWTRG_TOGGLE                            0x00000003
#define AVR32_TC_BCPB                                             24
#define AVR32_TC_BCPB_CLEAR                               0x00000002
#define AVR32_TC_BCPB_MASK                                0x03000000
#define AVR32_TC_BCPB_NONE                                0x00000000
#define AVR32_TC_BCPB_OFFSET                                      24
#define AVR32_TC_BCPB_SET                                 0x00000001
#define AVR32_TC_BCPB_SIZE                                         2
#define AVR32_TC_BCPB_TOGGLE                              0x00000003
#define AVR32_TC_BCPC                                             26
#define AVR32_TC_BCPC_CLEAR                               0x00000002
#define AVR32_TC_BCPC_MASK                                0x0c000000
#define AVR32_TC_BCPC_NONE                                0x00000000
#define AVR32_TC_BCPC_OFFSET                                      26
#define AVR32_TC_BCPC_SET                                 0x00000001
#define AVR32_TC_BCPC_SIZE                                         2
#define AVR32_TC_BCPC_TOGGLE                              0x00000003
#define AVR32_TC_BCR                                      0x000000c0
#define AVR32_TC_BCR_SYNC                                          0
#define AVR32_TC_BCR_SYNC_MASK                            0x00000001
#define AVR32_TC_BCR_SYNC_OFFSET                                   0
#define AVR32_TC_BCR_SYNC_SIZE                                     1
#define AVR32_TC_BEEVT                                            28
#define AVR32_TC_BEEVT_CLEAR                              0x00000002
#define AVR32_TC_BEEVT_MASK                               0x30000000
#define AVR32_TC_BEEVT_NONE                               0x00000000
#define AVR32_TC_BEEVT_OFFSET                                     28
#define AVR32_TC_BEEVT_SET                                0x00000001
#define AVR32_TC_BEEVT_SIZE                                        2
#define AVR32_TC_BEEVT_TOGGLE                             0x00000003
#define AVR32_TC_BIOTH_EDGES_TIOA                         0x00000003
#define AVR32_TC_BMR                                      0x000000c4
#define AVR32_TC_BMR_TC0XC0S                                       0
#define AVR32_TC_BMR_TC0XC0S_MASK                         0x00000003
#define AVR32_TC_BMR_TC0XC0S_NO_CLK                       0x00000001
#define AVR32_TC_BMR_TC0XC0S_OFFSET                                0
#define AVR32_TC_BMR_TC0XC0S_SIZE                                  2
#define AVR32_TC_BMR_TC0XC0S_TCLK0                        0x00000000
#define AVR32_TC_BMR_TC0XC0S_TIOA1                        0x00000002
#define AVR32_TC_BMR_TC0XC0S_TIOA2                        0x00000003
#define AVR32_TC_BMR_TC1XC1S                                       2
#define AVR32_TC_BMR_TC1XC1S_MASK                         0x0000000c
#define AVR32_TC_BMR_TC1XC1S_NO_CLK                       0x00000001
#define AVR32_TC_BMR_TC1XC1S_OFFSET                                2
#define AVR32_TC_BMR_TC1XC1S_SIZE                                  2
#define AVR32_TC_BMR_TC1XC1S_TCLK1                        0x00000000
#define AVR32_TC_BMR_TC1XC1S_TIOA0                        0x00000002
#define AVR32_TC_BMR_TC1XC1S_TIOA2                        0x00000003
#define AVR32_TC_BMR_TC2XC2S                                       4
#define AVR32_TC_BMR_TC2XC2S_MASK                         0x00000030
#define AVR32_TC_BMR_TC2XC2S_NO_CLK                       0x00000001
#define AVR32_TC_BMR_TC2XC2S_OFFSET                                4
#define AVR32_TC_BMR_TC2XC2S_SIZE                                  2
#define AVR32_TC_BMR_TC2XC2S_TCLK2                        0x00000000
#define AVR32_TC_BMR_TC2XC2S_TIOA0                        0x00000002
#define AVR32_TC_BMR_TC2XC2S_TIOA1                        0x00000003
#define AVR32_TC_BOTH_EDGES                               0x00000003
#define AVR32_TC_BSWTRG                                           30
#define AVR32_TC_BSWTRG_CLEAR                             0x00000002
#define AVR32_TC_BSWTRG_MASK                              0xc0000000
#define AVR32_TC_BSWTRG_NONE                              0x00000000
#define AVR32_TC_BSWTRG_OFFSET                                    30
#define AVR32_TC_BSWTRG_SET                               0x00000001
#define AVR32_TC_BSWTRG_SIZE                                       2
#define AVR32_TC_BSWTRG_TOGGLE                            0x00000003
#define AVR32_TC_BURST                                             4
#define AVR32_TC_BURST_CLK_AND_XC0                        0x00000001
#define AVR32_TC_BURST_CLK_AND_XC1                        0x00000002
#define AVR32_TC_BURST_CLK_AND_XC2                        0x00000003
#define AVR32_TC_BURST_MASK                               0x00000030
#define AVR32_TC_BURST_NOT_GATED                          0x00000000
#define AVR32_TC_BURST_OFFSET                                      4
#define AVR32_TC_BURST_SIZE                                        2
#define AVR32_TC_CCR0                                     0x00000000
#define AVR32_TC_CCR0_CLKDIS                                       1
#define AVR32_TC_CCR0_CLKDIS_MASK                         0x00000002
#define AVR32_TC_CCR0_CLKDIS_OFFSET                                1
#define AVR32_TC_CCR0_CLKDIS_SIZE                                  1
#define AVR32_TC_CCR0_CLKEN                                        0
#define AVR32_TC_CCR0_CLKEN_MASK                          0x00000001
#define AVR32_TC_CCR0_CLKEN_OFFSET                                 0
#define AVR32_TC_CCR0_CLKEN_SIZE                                   1
#define AVR32_TC_CCR0_SWTRG                                        2
#define AVR32_TC_CCR0_SWTRG_MASK                          0x00000004
#define AVR32_TC_CCR0_SWTRG_OFFSET                                 2
#define AVR32_TC_CCR0_SWTRG_SIZE                                   1
#define AVR32_TC_CCR1                                     0x00000040
#define AVR32_TC_CCR1_CLKDIS                                       1
#define AVR32_TC_CCR1_CLKDIS_MASK                         0x00000002
#define AVR32_TC_CCR1_CLKDIS_OFFSET                                1
#define AVR32_TC_CCR1_CLKDIS_SIZE                                  1
#define AVR32_TC_CCR1_CLKEN                                        0
#define AVR32_TC_CCR1_CLKEN_MASK                          0x00000001
#define AVR32_TC_CCR1_CLKEN_OFFSET                                 0
#define AVR32_TC_CCR1_CLKEN_SIZE                                   1
#define AVR32_TC_CCR1_SWTRG                                        2
#define AVR32_TC_CCR1_SWTRG_MASK                          0x00000004
#define AVR32_TC_CCR1_SWTRG_OFFSET                                 2
#define AVR32_TC_CCR1_SWTRG_SIZE                                   1
#define AVR32_TC_CCR2                                     0x00000080
#define AVR32_TC_CCR2_CLKDIS                                       1
#define AVR32_TC_CCR2_CLKDIS_MASK                         0x00000002
#define AVR32_TC_CCR2_CLKDIS_OFFSET                                1
#define AVR32_TC_CCR2_CLKDIS_SIZE                                  1
#define AVR32_TC_CCR2_CLKEN                                        0
#define AVR32_TC_CCR2_CLKEN_MASK                          0x00000001
#define AVR32_TC_CCR2_CLKEN_OFFSET                                 0
#define AVR32_TC_CCR2_CLKEN_SIZE                                   1
#define AVR32_TC_CCR2_SWTRG                                        2
#define AVR32_TC_CCR2_SWTRG_MASK                          0x00000004
#define AVR32_TC_CCR2_SWTRG_OFFSET                                 2
#define AVR32_TC_CCR2_SWTRG_SIZE                                   1
#define AVR32_TC_CLEAR                                    0x00000002
#define AVR32_TC_CLKDIS                                            1
#define AVR32_TC_CLKDIS_MASK                              0x00000002
#define AVR32_TC_CLKDIS_OFFSET                                     1
#define AVR32_TC_CLKDIS_SIZE                                       1
#define AVR32_TC_CLKEN                                             0
#define AVR32_TC_CLKEN_MASK                               0x00000001
#define AVR32_TC_CLKEN_OFFSET                                      0
#define AVR32_TC_CLKEN_SIZE                                        1
#define AVR32_TC_CLKI                                              3
#define AVR32_TC_CLKI_MASK                                0x00000008
#define AVR32_TC_CLKI_OFFSET                                       3
#define AVR32_TC_CLKI_SIZE                                         1
#define AVR32_TC_CLKSTA                                           16
#define AVR32_TC_CLKSTA_MASK                              0x00010000
#define AVR32_TC_CLKSTA_OFFSET                                    16
#define AVR32_TC_CLKSTA_SIZE                                       1
#define AVR32_TC_CLK_AND_XC0                              0x00000001
#define AVR32_TC_CLK_AND_XC1                              0x00000002
#define AVR32_TC_CLK_AND_XC2                              0x00000003
#define AVR32_TC_CMR0                                     0x00000004
#define AVR32_TC_CMR0_ABETRG                                      10
#define AVR32_TC_CMR0_ABETRG_MASK                         0x00000400
#define AVR32_TC_CMR0_ABETRG_OFFSET                               10
#define AVR32_TC_CMR0_ABETRG_SIZE                                  1
#define AVR32_TC_CMR0_ACPA                                        16
#define AVR32_TC_CMR0_ACPA_CLEAR                          0x00000002
#define AVR32_TC_CMR0_ACPA_MASK                           0x00030000
#define AVR32_TC_CMR0_ACPA_NONE                           0x00000000
#define AVR32_TC_CMR0_ACPA_OFFSET                                 16
#define AVR32_TC_CMR0_ACPA_SET                            0x00000001
#define AVR32_TC_CMR0_ACPA_SIZE                                    2
#define AVR32_TC_CMR0_ACPA_TOGGLE                         0x00000003
#define AVR32_TC_CMR0_ACPC                                        18
#define AVR32_TC_CMR0_ACPC_CLEAR                          0x00000002
#define AVR32_TC_CMR0_ACPC_MASK                           0x000c0000
#define AVR32_TC_CMR0_ACPC_NONE                           0x00000000
#define AVR32_TC_CMR0_ACPC_OFFSET                                 18
#define AVR32_TC_CMR0_ACPC_SET                            0x00000001
#define AVR32_TC_CMR0_ACPC_SIZE                                    2
#define AVR32_TC_CMR0_ACPC_TOGGLE                         0x00000003
#define AVR32_TC_CMR0_AEEVT                                       20
#define AVR32_TC_CMR0_AEEVT_CLEAR                         0x00000002
#define AVR32_TC_CMR0_AEEVT_MASK                          0x00300000
#define AVR32_TC_CMR0_AEEVT_NONE                          0x00000000
#define AVR32_TC_CMR0_AEEVT_OFFSET                                20
#define AVR32_TC_CMR0_AEEVT_SET                           0x00000001
#define AVR32_TC_CMR0_AEEVT_SIZE                                   2
#define AVR32_TC_CMR0_AEEVT_TOGGLE                        0x00000003
#define AVR32_TC_CMR0_ASWTRG                                      22
#define AVR32_TC_CMR0_ASWTRG_CLEAR                        0x00000002
#define AVR32_TC_CMR0_ASWTRG_MASK                         0x00c00000
#define AVR32_TC_CMR0_ASWTRG_NONE                         0x00000000
#define AVR32_TC_CMR0_ASWTRG_OFFSET                               22
#define AVR32_TC_CMR0_ASWTRG_SET                          0x00000001
#define AVR32_TC_CMR0_ASWTRG_SIZE                                  2
#define AVR32_TC_CMR0_ASWTRG_TOGGLE                       0x00000003
#define AVR32_TC_CMR0_BCPB                                        24
#define AVR32_TC_CMR0_BCPB_CLEAR                          0x00000002
#define AVR32_TC_CMR0_BCPB_MASK                           0x03000000
#define AVR32_TC_CMR0_BCPB_NONE                           0x00000000
#define AVR32_TC_CMR0_BCPB_OFFSET                                 24
#define AVR32_TC_CMR0_BCPB_SET                            0x00000001
#define AVR32_TC_CMR0_BCPB_SIZE                                    2
#define AVR32_TC_CMR0_BCPB_TOGGLE                         0x00000003
#define AVR32_TC_CMR0_BCPC                                        26
#define AVR32_TC_CMR0_BCPC_CLEAR                          0x00000002
#define AVR32_TC_CMR0_BCPC_MASK                           0x0c000000
#define AVR32_TC_CMR0_BCPC_NONE                           0x00000000
#define AVR32_TC_CMR0_BCPC_OFFSET                                 26
#define AVR32_TC_CMR0_BCPC_SET                            0x00000001
#define AVR32_TC_CMR0_BCPC_SIZE                                    2
#define AVR32_TC_CMR0_BCPC_TOGGLE                         0x00000003
#define AVR32_TC_CMR0_BEEVT                                       28
#define AVR32_TC_CMR0_BEEVT_CLEAR                         0x00000002
#define AVR32_TC_CMR0_BEEVT_MASK                          0x30000000
#define AVR32_TC_CMR0_BEEVT_NONE                          0x00000000
#define AVR32_TC_CMR0_BEEVT_OFFSET                                28
#define AVR32_TC_CMR0_BEEVT_SET                           0x00000001
#define AVR32_TC_CMR0_BEEVT_SIZE                                   2
#define AVR32_TC_CMR0_BEEVT_TOGGLE                        0x00000003
#define AVR32_TC_CMR0_BSWTRG                                      30
#define AVR32_TC_CMR0_BSWTRG_CLEAR                        0x00000002
#define AVR32_TC_CMR0_BSWTRG_MASK                         0xc0000000
#define AVR32_TC_CMR0_BSWTRG_NONE                         0x00000000
#define AVR32_TC_CMR0_BSWTRG_OFFSET                               30
#define AVR32_TC_CMR0_BSWTRG_SET                          0x00000001
#define AVR32_TC_CMR0_BSWTRG_SIZE                                  2
#define AVR32_TC_CMR0_BSWTRG_TOGGLE                       0x00000003
#define AVR32_TC_CMR0_BURST                                        4
#define AVR32_TC_CMR0_BURST_CLK_AND_XC0                   0x00000001
#define AVR32_TC_CMR0_BURST_CLK_AND_XC1                   0x00000002
#define AVR32_TC_CMR0_BURST_CLK_AND_XC2                   0x00000003
#define AVR32_TC_CMR0_BURST_MASK                          0x00000030
#define AVR32_TC_CMR0_BURST_NOT_GATED                     0x00000000
#define AVR32_TC_CMR0_BURST_OFFSET                                 4
#define AVR32_TC_CMR0_BURST_SIZE                                   2
#define AVR32_TC_CMR0_CLKI                                         3
#define AVR32_TC_CMR0_CLKI_MASK                           0x00000008
#define AVR32_TC_CMR0_CLKI_OFFSET                                  3
#define AVR32_TC_CMR0_CLKI_SIZE                                    1
#define AVR32_TC_CMR0_CPCDIS                                       7
#define AVR32_TC_CMR0_CPCDIS_MASK                         0x00000080
#define AVR32_TC_CMR0_CPCDIS_OFFSET                                7
#define AVR32_TC_CMR0_CPCDIS_SIZE                                  1
#define AVR32_TC_CMR0_CPCSTOP                                      6
#define AVR32_TC_CMR0_CPCSTOP_MASK                        0x00000040
#define AVR32_TC_CMR0_CPCSTOP_OFFSET                               6
#define AVR32_TC_CMR0_CPCSTOP_SIZE                                 1
#define AVR32_TC_CMR0_CPCTRG                                      14
#define AVR32_TC_CMR0_CPCTRG_MASK                         0x00004000
#define AVR32_TC_CMR0_CPCTRG_OFFSET                               14
#define AVR32_TC_CMR0_CPCTRG_SIZE                                  1
#define AVR32_TC_CMR0_EEVT                                        10
#define AVR32_TC_CMR0_EEVTEDG                                      8
#define AVR32_TC_CMR0_EEVTEDG_BOTH_EDGES                  0x00000003
#define AVR32_TC_CMR0_EEVTEDG_MASK                        0x00000300
#define AVR32_TC_CMR0_EEVTEDG_NEG_EDGE                    0x00000002
#define AVR32_TC_CMR0_EEVTEDG_NO_EDGE                     0x00000000
#define AVR32_TC_CMR0_EEVTEDG_OFFSET                               8
#define AVR32_TC_CMR0_EEVTEDG_POS_EDGE                    0x00000001
#define AVR32_TC_CMR0_EEVTEDG_SIZE                                 2
#define AVR32_TC_CMR0_EEVT_MASK                           0x00000c00
#define AVR32_TC_CMR0_EEVT_OFFSET                                 10
#define AVR32_TC_CMR0_EEVT_SIZE                                    2
#define AVR32_TC_CMR0_EEVT_TIOB_INPUT                     0x00000000
#define AVR32_TC_CMR0_EEVT_XC0_OUTPUT                     0x00000001
#define AVR32_TC_CMR0_EEVT_XC1_OUTPUT                     0x00000002
#define AVR32_TC_CMR0_EEVT_XC2_OUTPUT                     0x00000003
#define AVR32_TC_CMR0_ENETRG                                      12
#define AVR32_TC_CMR0_ENETRG_MASK                         0x00001000
#define AVR32_TC_CMR0_ENETRG_OFFSET                               12
#define AVR32_TC_CMR0_ENETRG_SIZE                                  1
#define AVR32_TC_CMR0_ETRGEDG                                      8
#define AVR32_TC_CMR0_ETRGEDG_BOTH_EDGES                  0x00000003
#define AVR32_TC_CMR0_ETRGEDG_MASK                        0x00000300
#define AVR32_TC_CMR0_ETRGEDG_NEG_EDGE                    0x00000002
#define AVR32_TC_CMR0_ETRGEDG_NO_EDGE                     0x00000000
#define AVR32_TC_CMR0_ETRGEDG_OFFSET                               8
#define AVR32_TC_CMR0_ETRGEDG_POS_EDGE                    0x00000001
#define AVR32_TC_CMR0_ETRGEDG_SIZE                                 2
#define AVR32_TC_CMR0_LDBDIS                                       7
#define AVR32_TC_CMR0_LDBDIS_MASK                         0x00000080
#define AVR32_TC_CMR0_LDBDIS_OFFSET                                7
#define AVR32_TC_CMR0_LDBDIS_SIZE                                  1
#define AVR32_TC_CMR0_LDBSTOP                                      6
#define AVR32_TC_CMR0_LDBSTOP_MASK                        0x00000040
#define AVR32_TC_CMR0_LDBSTOP_OFFSET                               6
#define AVR32_TC_CMR0_LDBSTOP_SIZE                                 1
#define AVR32_TC_CMR0_LDRA                                        16
#define AVR32_TC_CMR0_LDRA_BIOTH_EDGES_TIOA               0x00000003
#define AVR32_TC_CMR0_LDRA_MASK                           0x00030000
#define AVR32_TC_CMR0_LDRA_NEG_EDGE_TIOA                  0x00000002
#define AVR32_TC_CMR0_LDRA_NO_EDGE                        0x00000000
#define AVR32_TC_CMR0_LDRA_OFFSET                                 16
#define AVR32_TC_CMR0_LDRA_POS_EDGE_TIOA                  0x00000001
#define AVR32_TC_CMR0_LDRA_SIZE                                    2
#define AVR32_TC_CMR0_LDRB                                        18
#define AVR32_TC_CMR0_LDRB_BIOTH_EDGES_TIOA               0x00000003
#define AVR32_TC_CMR0_LDRB_MASK                           0x000c0000
#define AVR32_TC_CMR0_LDRB_NEG_EDGE_TIOA                  0x00000002
#define AVR32_TC_CMR0_LDRB_NO_EDGE                        0x00000000
#define AVR32_TC_CMR0_LDRB_OFFSET                                 18
#define AVR32_TC_CMR0_LDRB_POS_EDGE_TIOA                  0x00000001
#define AVR32_TC_CMR0_LDRB_SIZE                                    2
#define AVR32_TC_CMR0_TCCLKS                                       0
#define AVR32_TC_CMR0_TCCLKS_MASK                         0x00000007
#define AVR32_TC_CMR0_TCCLKS_OFFSET                                0
#define AVR32_TC_CMR0_TCCLKS_SIZE                                  3
#define AVR32_TC_CMR0_TCCLKS_TIMER_CLOCK1                 0x00000000
#define AVR32_TC_CMR0_TCCLKS_TIMER_CLOCK2                 0x00000001
#define AVR32_TC_CMR0_TCCLKS_TIMER_CLOCK3                 0x00000002
#define AVR32_TC_CMR0_TCCLKS_TIMER_CLOCK4                 0x00000003
#define AVR32_TC_CMR0_TCCLKS_TIMER_CLOCK5                 0x00000004
#define AVR32_TC_CMR0_TCCLKS_XC0                          0x00000005
#define AVR32_TC_CMR0_TCCLKS_XC1                          0x00000006
#define AVR32_TC_CMR0_TCCLKS_XC2                          0x00000007
#define AVR32_TC_CMR0_WAVE                                        15
#define AVR32_TC_CMR0_WAVE_MASK                           0x00008000
#define AVR32_TC_CMR0_WAVE_OFFSET                                 15
#define AVR32_TC_CMR0_WAVE_SIZE                                    1
#define AVR32_TC_CMR0_WAVSEL                                      13
#define AVR32_TC_CMR0_WAVSEL_MASK                         0x00006000
#define AVR32_TC_CMR0_WAVSEL_OFFSET                               13
#define AVR32_TC_CMR0_WAVSEL_SIZE                                  2
#define AVR32_TC_CMR0_WAVSEL_UPDOWN_AUTO                  0x00000003
#define AVR32_TC_CMR0_WAVSEL_UPDOWN_NO_AUTO               0x00000001
#define AVR32_TC_CMR0_WAVSEL_UP_AUTO                      0x00000002
#define AVR32_TC_CMR0_WAVSEL_UP_NO_AUTO                   0x00000000
#define AVR32_TC_CMR1                                     0x00000044
#define AVR32_TC_CMR1_ABETRG                                      10
#define AVR32_TC_CMR1_ABETRG_MASK                         0x00000400
#define AVR32_TC_CMR1_ABETRG_OFFSET                               10
#define AVR32_TC_CMR1_ABETRG_SIZE                                  1
#define AVR32_TC_CMR1_ACPA                                        16
#define AVR32_TC_CMR1_ACPA_CLEAR                          0x00000002
#define AVR32_TC_CMR1_ACPA_MASK                           0x00030000
#define AVR32_TC_CMR1_ACPA_NONE                           0x00000000
#define AVR32_TC_CMR1_ACPA_OFFSET                                 16
#define AVR32_TC_CMR1_ACPA_SET                            0x00000001
#define AVR32_TC_CMR1_ACPA_SIZE                                    2
#define AVR32_TC_CMR1_ACPA_TOGGLE                         0x00000003
#define AVR32_TC_CMR1_ACPC                                        18
#define AVR32_TC_CMR1_ACPC_CLEAR                          0x00000002
#define AVR32_TC_CMR1_ACPC_MASK                           0x000c0000
#define AVR32_TC_CMR1_ACPC_NONE                           0x00000000
#define AVR32_TC_CMR1_ACPC_OFFSET                                 18
#define AVR32_TC_CMR1_ACPC_SET                            0x00000001
#define AVR32_TC_CMR1_ACPC_SIZE                                    2
#define AVR32_TC_CMR1_ACPC_TOGGLE                         0x00000003
#define AVR32_TC_CMR1_AEEVT                                       20
#define AVR32_TC_CMR1_AEEVT_CLEAR                         0x00000002
#define AVR32_TC_CMR1_AEEVT_MASK                          0x00300000
#define AVR32_TC_CMR1_AEEVT_NONE                          0x00000000
#define AVR32_TC_CMR1_AEEVT_OFFSET                                20
#define AVR32_TC_CMR1_AEEVT_SET                           0x00000001
#define AVR32_TC_CMR1_AEEVT_SIZE                                   2
#define AVR32_TC_CMR1_AEEVT_TOGGLE                        0x00000003
#define AVR32_TC_CMR1_ASWTRG                                      22
#define AVR32_TC_CMR1_ASWTRG_CLEAR                        0x00000002
#define AVR32_TC_CMR1_ASWTRG_MASK                         0x00c00000
#define AVR32_TC_CMR1_ASWTRG_NONE                         0x00000000
#define AVR32_TC_CMR1_ASWTRG_OFFSET                               22
#define AVR32_TC_CMR1_ASWTRG_SET                          0x00000001
#define AVR32_TC_CMR1_ASWTRG_SIZE                                  2
#define AVR32_TC_CMR1_ASWTRG_TOGGLE                       0x00000003
#define AVR32_TC_CMR1_BCPB                                        24
#define AVR32_TC_CMR1_BCPB_CLEAR                          0x00000002
#define AVR32_TC_CMR1_BCPB_MASK                           0x03000000
#define AVR32_TC_CMR1_BCPB_NONE                           0x00000000
#define AVR32_TC_CMR1_BCPB_OFFSET                                 24
#define AVR32_TC_CMR1_BCPB_SET                            0x00000001
#define AVR32_TC_CMR1_BCPB_SIZE                                    2
#define AVR32_TC_CMR1_BCPB_TOGGLE                         0x00000003
#define AVR32_TC_CMR1_BCPC                                        26
#define AVR32_TC_CMR1_BCPC_CLEAR                          0x00000002
#define AVR32_TC_CMR1_BCPC_MASK                           0x0c000000
#define AVR32_TC_CMR1_BCPC_NONE                           0x00000000
#define AVR32_TC_CMR1_BCPC_OFFSET                                 26
#define AVR32_TC_CMR1_BCPC_SET                            0x00000001
#define AVR32_TC_CMR1_BCPC_SIZE                                    2
#define AVR32_TC_CMR1_BCPC_TOGGLE                         0x00000003
#define AVR32_TC_CMR1_BEEVT                                       28
#define AVR32_TC_CMR1_BEEVT_CLEAR                         0x00000002
#define AVR32_TC_CMR1_BEEVT_MASK                          0x30000000
#define AVR32_TC_CMR1_BEEVT_NONE                          0x00000000
#define AVR32_TC_CMR1_BEEVT_OFFSET                                28
#define AVR32_TC_CMR1_BEEVT_SET                           0x00000001
#define AVR32_TC_CMR1_BEEVT_SIZE                                   2
#define AVR32_TC_CMR1_BEEVT_TOGGLE                        0x00000003
#define AVR32_TC_CMR1_BSWTRG                                      30
#define AVR32_TC_CMR1_BSWTRG_CLEAR                        0x00000002
#define AVR32_TC_CMR1_BSWTRG_MASK                         0xc0000000
#define AVR32_TC_CMR1_BSWTRG_NONE                         0x00000000
#define AVR32_TC_CMR1_BSWTRG_OFFSET                               30
#define AVR32_TC_CMR1_BSWTRG_SET                          0x00000001
#define AVR32_TC_CMR1_BSWTRG_SIZE                                  2
#define AVR32_TC_CMR1_BSWTRG_TOGGLE                       0x00000003
#define AVR32_TC_CMR1_BURST                                        4
#define AVR32_TC_CMR1_BURST_CLK_AND_XC0                   0x00000001
#define AVR32_TC_CMR1_BURST_CLK_AND_XC1                   0x00000002
#define AVR32_TC_CMR1_BURST_CLK_AND_XC2                   0x00000003
#define AVR32_TC_CMR1_BURST_MASK                          0x00000030
#define AVR32_TC_CMR1_BURST_NOT_GATED                     0x00000000
#define AVR32_TC_CMR1_BURST_OFFSET                                 4
#define AVR32_TC_CMR1_BURST_SIZE                                   2
#define AVR32_TC_CMR1_CLKI                                         3
#define AVR32_TC_CMR1_CLKI_MASK                           0x00000008
#define AVR32_TC_CMR1_CLKI_OFFSET                                  3
#define AVR32_TC_CMR1_CLKI_SIZE                                    1
#define AVR32_TC_CMR1_CPCDIS                                       7
#define AVR32_TC_CMR1_CPCDIS_MASK                         0x00000080
#define AVR32_TC_CMR1_CPCDIS_OFFSET                                7
#define AVR32_TC_CMR1_CPCDIS_SIZE                                  1
#define AVR32_TC_CMR1_CPCSTOP                                      6
#define AVR32_TC_CMR1_CPCSTOP_MASK                        0x00000040
#define AVR32_TC_CMR1_CPCSTOP_OFFSET                               6
#define AVR32_TC_CMR1_CPCSTOP_SIZE                                 1
#define AVR32_TC_CMR1_CPCTRG                                      14
#define AVR32_TC_CMR1_CPCTRG_MASK                         0x00004000
#define AVR32_TC_CMR1_CPCTRG_OFFSET                               14
#define AVR32_TC_CMR1_CPCTRG_SIZE                                  1
#define AVR32_TC_CMR1_EEVT                                        10
#define AVR32_TC_CMR1_EEVTEDG                                      8
#define AVR32_TC_CMR1_EEVTEDG_BOTH_EDGES                  0x00000003
#define AVR32_TC_CMR1_EEVTEDG_MASK                        0x00000300
#define AVR32_TC_CMR1_EEVTEDG_NEG_EDGE                    0x00000002
#define AVR32_TC_CMR1_EEVTEDG_NO_EDGE                     0x00000000
#define AVR32_TC_CMR1_EEVTEDG_OFFSET                               8
#define AVR32_TC_CMR1_EEVTEDG_POS_EDGE                    0x00000001
#define AVR32_TC_CMR1_EEVTEDG_SIZE                                 2
#define AVR32_TC_CMR1_EEVT_MASK                           0x00000c00
#define AVR32_TC_CMR1_EEVT_OFFSET                                 10
#define AVR32_TC_CMR1_EEVT_SIZE                                    2
#define AVR32_TC_CMR1_EEVT_TIOB_INPUT                     0x00000000
#define AVR32_TC_CMR1_EEVT_XC0_OUTPUT                     0x00000001
#define AVR32_TC_CMR1_EEVT_XC1_OUTPUT                     0x00000002
#define AVR32_TC_CMR1_EEVT_XC2_OUTPUT                     0x00000003
#define AVR32_TC_CMR1_ENETRG                                      12
#define AVR32_TC_CMR1_ENETRG_MASK                         0x00001000
#define AVR32_TC_CMR1_ENETRG_OFFSET                               12
#define AVR32_TC_CMR1_ENETRG_SIZE                                  1
#define AVR32_TC_CMR1_ETRGEDG                                      8
#define AVR32_TC_CMR1_ETRGEDG_BOTH_EDGES                  0x00000003
#define AVR32_TC_CMR1_ETRGEDG_MASK                        0x00000300
#define AVR32_TC_CMR1_ETRGEDG_NEG_EDGE                    0x00000002
#define AVR32_TC_CMR1_ETRGEDG_NO_EDGE                     0x00000000
#define AVR32_TC_CMR1_ETRGEDG_OFFSET                               8
#define AVR32_TC_CMR1_ETRGEDG_POS_EDGE                    0x00000001
#define AVR32_TC_CMR1_ETRGEDG_SIZE                                 2
#define AVR32_TC_CMR1_LDBDIS                                       7
#define AVR32_TC_CMR1_LDBDIS_MASK                         0x00000080
#define AVR32_TC_CMR1_LDBDIS_OFFSET                                7
#define AVR32_TC_CMR1_LDBDIS_SIZE                                  1
#define AVR32_TC_CMR1_LDBSTOP                                      6
#define AVR32_TC_CMR1_LDBSTOP_MASK                        0x00000040
#define AVR32_TC_CMR1_LDBSTOP_OFFSET                               6
#define AVR32_TC_CMR1_LDBSTOP_SIZE                                 1
#define AVR32_TC_CMR1_LDRA                                        16
#define AVR32_TC_CMR1_LDRA_BIOTH_EDGES_TIOA               0x00000003
#define AVR32_TC_CMR1_LDRA_MASK                           0x00030000
#define AVR32_TC_CMR1_LDRA_NEG_EDGE_TIOA                  0x00000002
#define AVR32_TC_CMR1_LDRA_NO_EDGE                        0x00000000
#define AVR32_TC_CMR1_LDRA_OFFSET                                 16
#define AVR32_TC_CMR1_LDRA_POS_EDGE_TIOA                  0x00000001
#define AVR32_TC_CMR1_LDRA_SIZE                                    2
#define AVR32_TC_CMR1_LDRB                                        18
#define AVR32_TC_CMR1_LDRB_BIOTH_EDGES_TIOA               0x00000003
#define AVR32_TC_CMR1_LDRB_MASK                           0x000c0000
#define AVR32_TC_CMR1_LDRB_NEG_EDGE_TIOA                  0x00000002
#define AVR32_TC_CMR1_LDRB_NO_EDGE                        0x00000000
#define AVR32_TC_CMR1_LDRB_OFFSET                                 18
#define AVR32_TC_CMR1_LDRB_POS_EDGE_TIOA                  0x00000001
#define AVR32_TC_CMR1_LDRB_SIZE                                    2
#define AVR32_TC_CMR1_TCCLKS                                       0
#define AVR32_TC_CMR1_TCCLKS_MASK                         0x00000007
#define AVR32_TC_CMR1_TCCLKS_OFFSET                                0
#define AVR32_TC_CMR1_TCCLKS_SIZE                                  3
#define AVR32_TC_CMR1_TCCLKS_TIMER_CLOCK1                 0x00000000
#define AVR32_TC_CMR1_TCCLKS_TIMER_CLOCK2                 0x00000001
#define AVR32_TC_CMR1_TCCLKS_TIMER_CLOCK3                 0x00000002
#define AVR32_TC_CMR1_TCCLKS_TIMER_CLOCK4                 0x00000003
#define AVR32_TC_CMR1_TCCLKS_TIMER_CLOCK5                 0x00000004
#define AVR32_TC_CMR1_TCCLKS_XC0                          0x00000005
#define AVR32_TC_CMR1_TCCLKS_XC1                          0x00000006
#define AVR32_TC_CMR1_TCCLKS_XC2                          0x00000007
#define AVR32_TC_CMR1_WAVE                                        15
#define AVR32_TC_CMR1_WAVE_MASK                           0x00008000
#define AVR32_TC_CMR1_WAVE_OFFSET                                 15
#define AVR32_TC_CMR1_WAVE_SIZE                                    1
#define AVR32_TC_CMR1_WAVSEL                                      13
#define AVR32_TC_CMR1_WAVSEL_MASK                         0x00006000
#define AVR32_TC_CMR1_WAVSEL_OFFSET                               13
#define AVR32_TC_CMR1_WAVSEL_SIZE                                  2
#define AVR32_TC_CMR1_WAVSEL_UPDOWN_AUTO                  0x00000003
#define AVR32_TC_CMR1_WAVSEL_UPDOWN_NO_AUTO               0x00000001
#define AVR32_TC_CMR1_WAVSEL_UP_AUTO                      0x00000002
#define AVR32_TC_CMR1_WAVSEL_UP_NO_AUTO                   0x00000000
#define AVR32_TC_CMR2                                     0x00000084
#define AVR32_TC_CMR2_ABETRG                                      10
#define AVR32_TC_CMR2_ABETRG_MASK                         0x00000400
#define AVR32_TC_CMR2_ABETRG_OFFSET                               10
#define AVR32_TC_CMR2_ABETRG_SIZE                                  1
#define AVR32_TC_CMR2_ACPA                                        16
#define AVR32_TC_CMR2_ACPA_CLEAR                          0x00000002
#define AVR32_TC_CMR2_ACPA_MASK                           0x00030000
#define AVR32_TC_CMR2_ACPA_NONE                           0x00000000
#define AVR32_TC_CMR2_ACPA_OFFSET                                 16
#define AVR32_TC_CMR2_ACPA_SET                            0x00000001
#define AVR32_TC_CMR2_ACPA_SIZE                                    2
#define AVR32_TC_CMR2_ACPA_TOGGLE                         0x00000003
#define AVR32_TC_CMR2_ACPC                                        18
#define AVR32_TC_CMR2_ACPC_CLEAR                          0x00000002
#define AVR32_TC_CMR2_ACPC_MASK                           0x000c0000
#define AVR32_TC_CMR2_ACPC_NONE                           0x00000000
#define AVR32_TC_CMR2_ACPC_OFFSET                                 18
#define AVR32_TC_CMR2_ACPC_SET                            0x00000001
#define AVR32_TC_CMR2_ACPC_SIZE                                    2
#define AVR32_TC_CMR2_ACPC_TOGGLE                         0x00000003
#define AVR32_TC_CMR2_AEEVT                                       20
#define AVR32_TC_CMR2_AEEVT_CLEAR                         0x00000002
#define AVR32_TC_CMR2_AEEVT_MASK                          0x00300000
#define AVR32_TC_CMR2_AEEVT_NONE                          0x00000000
#define AVR32_TC_CMR2_AEEVT_OFFSET                                20
#define AVR32_TC_CMR2_AEEVT_SET                           0x00000001
#define AVR32_TC_CMR2_AEEVT_SIZE                                   2
#define AVR32_TC_CMR2_AEEVT_TOGGLE                        0x00000003
#define AVR32_TC_CMR2_ASWTRG                                      22
#define AVR32_TC_CMR2_ASWTRG_CLEAR                        0x00000002
#define AVR32_TC_CMR2_ASWTRG_MASK                         0x00c00000
#define AVR32_TC_CMR2_ASWTRG_NONE                         0x00000000
#define AVR32_TC_CMR2_ASWTRG_OFFSET                               22
#define AVR32_TC_CMR2_ASWTRG_SET                          0x00000001
#define AVR32_TC_CMR2_ASWTRG_SIZE                                  2
#define AVR32_TC_CMR2_ASWTRG_TOGGLE                       0x00000003
#define AVR32_TC_CMR2_BCPB                                        24
#define AVR32_TC_CMR2_BCPB_CLEAR                          0x00000002
#define AVR32_TC_CMR2_BCPB_MASK                           0x03000000
#define AVR32_TC_CMR2_BCPB_NONE                           0x00000000
#define AVR32_TC_CMR2_BCPB_OFFSET                                 24
#define AVR32_TC_CMR2_BCPB_SET                            0x00000001
#define AVR32_TC_CMR2_BCPB_SIZE                                    2
#define AVR32_TC_CMR2_BCPB_TOGGLE                         0x00000003
#define AVR32_TC_CMR2_BCPC                                        26
#define AVR32_TC_CMR2_BCPC_CLEAR                          0x00000002
#define AVR32_TC_CMR2_BCPC_MASK                           0x0c000000
#define AVR32_TC_CMR2_BCPC_NONE                           0x00000000
#define AVR32_TC_CMR2_BCPC_OFFSET                                 26
#define AVR32_TC_CMR2_BCPC_SET                            0x00000001
#define AVR32_TC_CMR2_BCPC_SIZE                                    2
#define AVR32_TC_CMR2_BCPC_TOGGLE                         0x00000003
#define AVR32_TC_CMR2_BEEVT                                       28
#define AVR32_TC_CMR2_BEEVT_CLEAR                         0x00000002
#define AVR32_TC_CMR2_BEEVT_MASK                          0x30000000
#define AVR32_TC_CMR2_BEEVT_NONE                          0x00000000
#define AVR32_TC_CMR2_BEEVT_OFFSET                                28
#define AVR32_TC_CMR2_BEEVT_SET                           0x00000001
#define AVR32_TC_CMR2_BEEVT_SIZE                                   2
#define AVR32_TC_CMR2_BEEVT_TOGGLE                        0x00000003
#define AVR32_TC_CMR2_BSWTRG                                      30
#define AVR32_TC_CMR2_BSWTRG_CLEAR                        0x00000002
#define AVR32_TC_CMR2_BSWTRG_MASK                         0xc0000000
#define AVR32_TC_CMR2_BSWTRG_NONE                         0x00000000
#define AVR32_TC_CMR2_BSWTRG_OFFSET                               30
#define AVR32_TC_CMR2_BSWTRG_SET                          0x00000001
#define AVR32_TC_CMR2_BSWTRG_SIZE                                  2
#define AVR32_TC_CMR2_BSWTRG_TOGGLE                       0x00000003
#define AVR32_TC_CMR2_BURST                                        4
#define AVR32_TC_CMR2_BURST_CLK_AND_XC0                   0x00000001
#define AVR32_TC_CMR2_BURST_CLK_AND_XC1                   0x00000002
#define AVR32_TC_CMR2_BURST_CLK_AND_XC2                   0x00000003
#define AVR32_TC_CMR2_BURST_MASK                          0x00000030
#define AVR32_TC_CMR2_BURST_NOT_GATED                     0x00000000
#define AVR32_TC_CMR2_BURST_OFFSET                                 4
#define AVR32_TC_CMR2_BURST_SIZE                                   2
#define AVR32_TC_CMR2_CLKI                                         3
#define AVR32_TC_CMR2_CLKI_MASK                           0x00000008
#define AVR32_TC_CMR2_CLKI_OFFSET                                  3
#define AVR32_TC_CMR2_CLKI_SIZE                                    1
#define AVR32_TC_CMR2_CPCDIS                                       7
#define AVR32_TC_CMR2_CPCDIS_MASK                         0x00000080
#define AVR32_TC_CMR2_CPCDIS_OFFSET                                7
#define AVR32_TC_CMR2_CPCDIS_SIZE                                  1
#define AVR32_TC_CMR2_CPCSTOP                                      6
#define AVR32_TC_CMR2_CPCSTOP_MASK                        0x00000040
#define AVR32_TC_CMR2_CPCSTOP_OFFSET                               6
#define AVR32_TC_CMR2_CPCSTOP_SIZE                                 1
#define AVR32_TC_CMR2_CPCTRG                                      14
#define AVR32_TC_CMR2_CPCTRG_MASK                         0x00004000
#define AVR32_TC_CMR2_CPCTRG_OFFSET                               14
#define AVR32_TC_CMR2_CPCTRG_SIZE                                  1
#define AVR32_TC_CMR2_EEVT                                        10
#define AVR32_TC_CMR2_EEVTEDG                                      8
#define AVR32_TC_CMR2_EEVTEDG_BOTH_EDGES                  0x00000003
#define AVR32_TC_CMR2_EEVTEDG_MASK                        0x00000300
#define AVR32_TC_CMR2_EEVTEDG_NEG_EDGE                    0x00000002
#define AVR32_TC_CMR2_EEVTEDG_NO_EDGE                     0x00000000
#define AVR32_TC_CMR2_EEVTEDG_OFFSET                               8
#define AVR32_TC_CMR2_EEVTEDG_POS_EDGE                    0x00000001
#define AVR32_TC_CMR2_EEVTEDG_SIZE                                 2
#define AVR32_TC_CMR2_EEVT_MASK                           0x00000c00
#define AVR32_TC_CMR2_EEVT_OFFSET                                 10
#define AVR32_TC_CMR2_EEVT_SIZE                                    2
#define AVR32_TC_CMR2_EEVT_TIOB_INPUT                     0x00000000
#define AVR32_TC_CMR2_EEVT_XC0_OUTPUT                     0x00000001
#define AVR32_TC_CMR2_EEVT_XC1_OUTPUT                     0x00000002
#define AVR32_TC_CMR2_EEVT_XC2_OUTPUT                     0x00000003
#define AVR32_TC_CMR2_ENETRG                                      12
#define AVR32_TC_CMR2_ENETRG_MASK                         0x00001000
#define AVR32_TC_CMR2_ENETRG_OFFSET                               12
#define AVR32_TC_CMR2_ENETRG_SIZE                                  1
#define AVR32_TC_CMR2_ETRGEDG                                      8
#define AVR32_TC_CMR2_ETRGEDG_BOTH_EDGES                  0x00000003
#define AVR32_TC_CMR2_ETRGEDG_MASK                        0x00000300
#define AVR32_TC_CMR2_ETRGEDG_NEG_EDGE                    0x00000002
#define AVR32_TC_CMR2_ETRGEDG_NO_EDGE                     0x00000000
#define AVR32_TC_CMR2_ETRGEDG_OFFSET                               8
#define AVR32_TC_CMR2_ETRGEDG_POS_EDGE                    0x00000001
#define AVR32_TC_CMR2_ETRGEDG_SIZE                                 2
#define AVR32_TC_CMR2_LDBDIS                                       7
#define AVR32_TC_CMR2_LDBDIS_MASK                         0x00000080
#define AVR32_TC_CMR2_LDBDIS_OFFSET                                7
#define AVR32_TC_CMR2_LDBDIS_SIZE                                  1
#define AVR32_TC_CMR2_LDBSTOP                                      6
#define AVR32_TC_CMR2_LDBSTOP_MASK                        0x00000040
#define AVR32_TC_CMR2_LDBSTOP_OFFSET                               6
#define AVR32_TC_CMR2_LDBSTOP_SIZE                                 1
#define AVR32_TC_CMR2_LDRA                                        16
#define AVR32_TC_CMR2_LDRA_BIOTH_EDGES_TIOA               0x00000003
#define AVR32_TC_CMR2_LDRA_MASK                           0x00030000
#define AVR32_TC_CMR2_LDRA_NEG_EDGE_TIOA                  0x00000002
#define AVR32_TC_CMR2_LDRA_NO_EDGE                        0x00000000
#define AVR32_TC_CMR2_LDRA_OFFSET                                 16
#define AVR32_TC_CMR2_LDRA_POS_EDGE_TIOA                  0x00000001
#define AVR32_TC_CMR2_LDRA_SIZE                                    2
#define AVR32_TC_CMR2_LDRB                                        18
#define AVR32_TC_CMR2_LDRB_BIOTH_EDGES_TIOA               0x00000003
#define AVR32_TC_CMR2_LDRB_MASK                           0x000c0000
#define AVR32_TC_CMR2_LDRB_NEG_EDGE_TIOA                  0x00000002
#define AVR32_TC_CMR2_LDRB_NO_EDGE                        0x00000000
#define AVR32_TC_CMR2_LDRB_OFFSET                                 18
#define AVR32_TC_CMR2_LDRB_POS_EDGE_TIOA                  0x00000001
#define AVR32_TC_CMR2_LDRB_SIZE                                    2
#define AVR32_TC_CMR2_TCCLKS                                       0
#define AVR32_TC_CMR2_TCCLKS_MASK                         0x00000007
#define AVR32_TC_CMR2_TCCLKS_OFFSET                                0
#define AVR32_TC_CMR2_TCCLKS_SIZE                                  3
#define AVR32_TC_CMR2_TCCLKS_TIMER_CLOCK1                 0x00000000
#define AVR32_TC_CMR2_TCCLKS_TIMER_CLOCK2                 0x00000001
#define AVR32_TC_CMR2_TCCLKS_TIMER_CLOCK3                 0x00000002
#define AVR32_TC_CMR2_TCCLKS_TIMER_CLOCK4                 0x00000003
#define AVR32_TC_CMR2_TCCLKS_TIMER_CLOCK5                 0x00000004
#define AVR32_TC_CMR2_TCCLKS_XC0                          0x00000005
#define AVR32_TC_CMR2_TCCLKS_XC1                          0x00000006
#define AVR32_TC_CMR2_TCCLKS_XC2                          0x00000007
#define AVR32_TC_CMR2_WAVE                                        15
#define AVR32_TC_CMR2_WAVE_MASK                           0x00008000
#define AVR32_TC_CMR2_WAVE_OFFSET                                 15
#define AVR32_TC_CMR2_WAVE_SIZE                                    1
#define AVR32_TC_CMR2_WAVSEL                                      13
#define AVR32_TC_CMR2_WAVSEL_MASK                         0x00006000
#define AVR32_TC_CMR2_WAVSEL_OFFSET                               13
#define AVR32_TC_CMR2_WAVSEL_SIZE                                  2
#define AVR32_TC_CMR2_WAVSEL_UPDOWN_AUTO                  0x00000003
#define AVR32_TC_CMR2_WAVSEL_UPDOWN_NO_AUTO               0x00000001
#define AVR32_TC_CMR2_WAVSEL_UP_AUTO                      0x00000002
#define AVR32_TC_CMR2_WAVSEL_UP_NO_AUTO                   0x00000000
#define AVR32_TC_COVFS                                             0
#define AVR32_TC_COVFS_MASK                               0x00000001
#define AVR32_TC_COVFS_OFFSET                                      0
#define AVR32_TC_COVFS_SIZE                                        1
#define AVR32_TC_CPAS                                              2
#define AVR32_TC_CPAS_MASK                                0x00000004
#define AVR32_TC_CPAS_OFFSET                                       2
#define AVR32_TC_CPAS_SIZE                                         1
#define AVR32_TC_CPBS                                              3
#define AVR32_TC_CPBS_MASK                                0x00000008
#define AVR32_TC_CPBS_OFFSET                                       3
#define AVR32_TC_CPBS_SIZE                                         1
#define AVR32_TC_CPCDIS                                            7
#define AVR32_TC_CPCDIS_MASK                              0x00000080
#define AVR32_TC_CPCDIS_OFFSET                                     7
#define AVR32_TC_CPCDIS_SIZE                                       1
#define AVR32_TC_CPCS                                              4
#define AVR32_TC_CPCSTOP                                           6
#define AVR32_TC_CPCSTOP_MASK                             0x00000040
#define AVR32_TC_CPCSTOP_OFFSET                                    6
#define AVR32_TC_CPCSTOP_SIZE                                      1
#define AVR32_TC_CPCS_MASK                                0x00000010
#define AVR32_TC_CPCS_OFFSET                                       4
#define AVR32_TC_CPCS_SIZE                                         1
#define AVR32_TC_CPCTRG                                           14
#define AVR32_TC_CPCTRG_MASK                              0x00004000
#define AVR32_TC_CPCTRG_OFFSET                                    14
#define AVR32_TC_CPCTRG_SIZE                                       1
#define AVR32_TC_CV                                                0
#define AVR32_TC_CV0                                      0x00000010
#define AVR32_TC_CV0_CV                                            0
#define AVR32_TC_CV0_CV_MASK                              0x0000ffff
#define AVR32_TC_CV0_CV_OFFSET                                     0
#define AVR32_TC_CV0_CV_SIZE                                      16
#define AVR32_TC_CV1                                      0x00000050
#define AVR32_TC_CV1_CV                                            0
#define AVR32_TC_CV1_CV_MASK                              0x0000ffff
#define AVR32_TC_CV1_CV_OFFSET                                     0
#define AVR32_TC_CV1_CV_SIZE                                      16
#define AVR32_TC_CV2                                      0x00000090
#define AVR32_TC_CV2_CV                                            0
#define AVR32_TC_CV2_CV_MASK                              0x0000ffff
#define AVR32_TC_CV2_CV_OFFSET                                     0
#define AVR32_TC_CV2_CV_SIZE                                      16
#define AVR32_TC_CV_MASK                                  0x0000ffff
#define AVR32_TC_CV_OFFSET                                         0
#define AVR32_TC_CV_SIZE                                          16
#define AVR32_TC_EEVT                                             10
#define AVR32_TC_EEVTEDG                                           8
#define AVR32_TC_EEVTEDG_BOTH_EDGES                       0x00000003
#define AVR32_TC_EEVTEDG_MASK                             0x00000300
#define AVR32_TC_EEVTEDG_NEG_EDGE                         0x00000002
#define AVR32_TC_EEVTEDG_NO_EDGE                          0x00000000
#define AVR32_TC_EEVTEDG_OFFSET                                    8
#define AVR32_TC_EEVTEDG_POS_EDGE                         0x00000001
#define AVR32_TC_EEVTEDG_SIZE                                      2
#define AVR32_TC_EEVT_MASK                                0x00000c00
#define AVR32_TC_EEVT_OFFSET                                      10
#define AVR32_TC_EEVT_SIZE                                         2
#define AVR32_TC_EEVT_TIOB_INPUT                          0x00000000
#define AVR32_TC_EEVT_XC0_OUTPUT                          0x00000001
#define AVR32_TC_EEVT_XC1_OUTPUT                          0x00000002
#define AVR32_TC_EEVT_XC2_OUTPUT                          0x00000003
#define AVR32_TC_ENETRG                                           12
#define AVR32_TC_ENETRG_MASK                              0x00001000
#define AVR32_TC_ENETRG_OFFSET                                    12
#define AVR32_TC_ENETRG_SIZE                                       1
#define AVR32_TC_ETRGEDG                                           8
#define AVR32_TC_ETRGEDG_BOTH_EDGES                       0x00000003
#define AVR32_TC_ETRGEDG_MASK                             0x00000300
#define AVR32_TC_ETRGEDG_NEG_EDGE                         0x00000002
#define AVR32_TC_ETRGEDG_NO_EDGE                          0x00000000
#define AVR32_TC_ETRGEDG_OFFSET                                    8
#define AVR32_TC_ETRGEDG_POS_EDGE                         0x00000001
#define AVR32_TC_ETRGEDG_SIZE                                      2
#define AVR32_TC_ETRGS                                             7
#define AVR32_TC_ETRGS_MASK                               0x00000080
#define AVR32_TC_ETRGS_OFFSET                                      7
#define AVR32_TC_ETRGS_SIZE                                        1
#define AVR32_TC_IDR0                                     0x00000028
#define AVR32_TC_IDR0_COVFS                                        0
#define AVR32_TC_IDR0_COVFS_MASK                          0x00000001
#define AVR32_TC_IDR0_COVFS_OFFSET                                 0
#define AVR32_TC_IDR0_COVFS_SIZE                                   1
#define AVR32_TC_IDR0_CPAS                                         2
#define AVR32_TC_IDR0_CPAS_MASK                           0x00000004
#define AVR32_TC_IDR0_CPAS_OFFSET                                  2
#define AVR32_TC_IDR0_CPAS_SIZE                                    1
#define AVR32_TC_IDR0_CPBS                                         3
#define AVR32_TC_IDR0_CPBS_MASK                           0x00000008
#define AVR32_TC_IDR0_CPBS_OFFSET                                  3
#define AVR32_TC_IDR0_CPBS_SIZE                                    1
#define AVR32_TC_IDR0_CPCS                                         4
#define AVR32_TC_IDR0_CPCS_MASK                           0x00000010
#define AVR32_TC_IDR0_CPCS_OFFSET                                  4
#define AVR32_TC_IDR0_CPCS_SIZE                                    1
#define AVR32_TC_IDR0_ETRGS                                        7
#define AVR32_TC_IDR0_ETRGS_MASK                          0x00000080
#define AVR32_TC_IDR0_ETRGS_OFFSET                                 7
#define AVR32_TC_IDR0_ETRGS_SIZE                                   1
#define AVR32_TC_IDR0_LDRAS                                        5
#define AVR32_TC_IDR0_LDRAS_MASK                          0x00000020
#define AVR32_TC_IDR0_LDRAS_OFFSET                                 5
#define AVR32_TC_IDR0_LDRAS_SIZE                                   1
#define AVR32_TC_IDR0_LDRBS                                        6
#define AVR32_TC_IDR0_LDRBS_MASK                          0x00000040
#define AVR32_TC_IDR0_LDRBS_OFFSET                                 6
#define AVR32_TC_IDR0_LDRBS_SIZE                                   1
#define AVR32_TC_IDR0_LOVRS                                        1
#define AVR32_TC_IDR0_LOVRS_MASK                          0x00000002
#define AVR32_TC_IDR0_LOVRS_OFFSET                                 1
#define AVR32_TC_IDR0_LOVRS_SIZE                                   1
#define AVR32_TC_IDR1                                     0x00000068
#define AVR32_TC_IDR1_COVFS                                        0
#define AVR32_TC_IDR1_COVFS_MASK                          0x00000001
#define AVR32_TC_IDR1_COVFS_OFFSET                                 0
#define AVR32_TC_IDR1_COVFS_SIZE                                   1
#define AVR32_TC_IDR1_CPAS                                         2
#define AVR32_TC_IDR1_CPAS_MASK                           0x00000004
#define AVR32_TC_IDR1_CPAS_OFFSET                                  2
#define AVR32_TC_IDR1_CPAS_SIZE                                    1
#define AVR32_TC_IDR1_CPBS                                         3
#define AVR32_TC_IDR1_CPBS_MASK                           0x00000008
#define AVR32_TC_IDR1_CPBS_OFFSET                                  3
#define AVR32_TC_IDR1_CPBS_SIZE                                    1
#define AVR32_TC_IDR1_CPCS                                         4
#define AVR32_TC_IDR1_CPCS_MASK                           0x00000010
#define AVR32_TC_IDR1_CPCS_OFFSET                                  4
#define AVR32_TC_IDR1_CPCS_SIZE                                    1
#define AVR32_TC_IDR1_ETRGS                                        7
#define AVR32_TC_IDR1_ETRGS_MASK                          0x00000080
#define AVR32_TC_IDR1_ETRGS_OFFSET                                 7
#define AVR32_TC_IDR1_ETRGS_SIZE                                   1
#define AVR32_TC_IDR1_LDRAS                                        5
#define AVR32_TC_IDR1_LDRAS_MASK                          0x00000020
#define AVR32_TC_IDR1_LDRAS_OFFSET                                 5
#define AVR32_TC_IDR1_LDRAS_SIZE                                   1
#define AVR32_TC_IDR1_LDRBS                                        6
#define AVR32_TC_IDR1_LDRBS_MASK                          0x00000040
#define AVR32_TC_IDR1_LDRBS_OFFSET                                 6
#define AVR32_TC_IDR1_LDRBS_SIZE                                   1
#define AVR32_TC_IDR1_LOVRS                                        1
#define AVR32_TC_IDR1_LOVRS_MASK                          0x00000002
#define AVR32_TC_IDR1_LOVRS_OFFSET                                 1
#define AVR32_TC_IDR1_LOVRS_SIZE                                   1
#define AVR32_TC_IDR2                                     0x000000a8
#define AVR32_TC_IDR2_COVFS                                        0
#define AVR32_TC_IDR2_COVFS_MASK                          0x00000001
#define AVR32_TC_IDR2_COVFS_OFFSET                                 0
#define AVR32_TC_IDR2_COVFS_SIZE                                   1
#define AVR32_TC_IDR2_CPAS                                         2
#define AVR32_TC_IDR2_CPAS_MASK                           0x00000004
#define AVR32_TC_IDR2_CPAS_OFFSET                                  2
#define AVR32_TC_IDR2_CPAS_SIZE                                    1
#define AVR32_TC_IDR2_CPBS                                         3
#define AVR32_TC_IDR2_CPBS_MASK                           0x00000008
#define AVR32_TC_IDR2_CPBS_OFFSET                                  3
#define AVR32_TC_IDR2_CPBS_SIZE                                    1
#define AVR32_TC_IDR2_CPCS                                         4
#define AVR32_TC_IDR2_CPCS_MASK                           0x00000010
#define AVR32_TC_IDR2_CPCS_OFFSET                                  4
#define AVR32_TC_IDR2_CPCS_SIZE                                    1
#define AVR32_TC_IDR2_ETRGS                                        7
#define AVR32_TC_IDR2_ETRGS_MASK                          0x00000080
#define AVR32_TC_IDR2_ETRGS_OFFSET                                 7
#define AVR32_TC_IDR2_ETRGS_SIZE                                   1
#define AVR32_TC_IDR2_LDRAS                                        5
#define AVR32_TC_IDR2_LDRAS_MASK                          0x00000020
#define AVR32_TC_IDR2_LDRAS_OFFSET                                 5
#define AVR32_TC_IDR2_LDRAS_SIZE                                   1
#define AVR32_TC_IDR2_LDRBS                                        6
#define AVR32_TC_IDR2_LDRBS_MASK                          0x00000040
#define AVR32_TC_IDR2_LDRBS_OFFSET                                 6
#define AVR32_TC_IDR2_LDRBS_SIZE                                   1
#define AVR32_TC_IDR2_LOVRS                                        1
#define AVR32_TC_IDR2_LOVRS_MASK                          0x00000002
#define AVR32_TC_IDR2_LOVRS_OFFSET                                 1
#define AVR32_TC_IDR2_LOVRS_SIZE                                   1
#define AVR32_TC_IER0                                     0x00000024
#define AVR32_TC_IER0_COVFS                                        0
#define AVR32_TC_IER0_COVFS_MASK                          0x00000001
#define AVR32_TC_IER0_COVFS_OFFSET                                 0
#define AVR32_TC_IER0_COVFS_SIZE                                   1
#define AVR32_TC_IER0_CPAS                                         2
#define AVR32_TC_IER0_CPAS_MASK                           0x00000004
#define AVR32_TC_IER0_CPAS_OFFSET                                  2
#define AVR32_TC_IER0_CPAS_SIZE                                    1
#define AVR32_TC_IER0_CPBS                                         3
#define AVR32_TC_IER0_CPBS_MASK                           0x00000008
#define AVR32_TC_IER0_CPBS_OFFSET                                  3
#define AVR32_TC_IER0_CPBS_SIZE                                    1
#define AVR32_TC_IER0_CPCS                                         4
#define AVR32_TC_IER0_CPCS_MASK                           0x00000010
#define AVR32_TC_IER0_CPCS_OFFSET                                  4
#define AVR32_TC_IER0_CPCS_SIZE                                    1
#define AVR32_TC_IER0_ETRGS                                        7
#define AVR32_TC_IER0_ETRGS_MASK                          0x00000080
#define AVR32_TC_IER0_ETRGS_OFFSET                                 7
#define AVR32_TC_IER0_ETRGS_SIZE                                   1
#define AVR32_TC_IER0_LDRAS                                        5
#define AVR32_TC_IER0_LDRAS_MASK                          0x00000020
#define AVR32_TC_IER0_LDRAS_OFFSET                                 5
#define AVR32_TC_IER0_LDRAS_SIZE                                   1
#define AVR32_TC_IER0_LDRBS                                        6
#define AVR32_TC_IER0_LDRBS_MASK                          0x00000040
#define AVR32_TC_IER0_LDRBS_OFFSET                                 6
#define AVR32_TC_IER0_LDRBS_SIZE                                   1
#define AVR32_TC_IER0_LOVRS                                        1
#define AVR32_TC_IER0_LOVRS_MASK                          0x00000002
#define AVR32_TC_IER0_LOVRS_OFFSET                                 1
#define AVR32_TC_IER0_LOVRS_SIZE                                   1
#define AVR32_TC_IER1                                     0x00000064
#define AVR32_TC_IER1_COVFS                                        0
#define AVR32_TC_IER1_COVFS_MASK                          0x00000001
#define AVR32_TC_IER1_COVFS_OFFSET                                 0
#define AVR32_TC_IER1_COVFS_SIZE                                   1
#define AVR32_TC_IER1_CPAS                                         2
#define AVR32_TC_IER1_CPAS_MASK                           0x00000004
#define AVR32_TC_IER1_CPAS_OFFSET                                  2
#define AVR32_TC_IER1_CPAS_SIZE                                    1
#define AVR32_TC_IER1_CPBS                                         3
#define AVR32_TC_IER1_CPBS_MASK                           0x00000008
#define AVR32_TC_IER1_CPBS_OFFSET                                  3
#define AVR32_TC_IER1_CPBS_SIZE                                    1
#define AVR32_TC_IER1_CPCS                                         4
#define AVR32_TC_IER1_CPCS_MASK                           0x00000010
#define AVR32_TC_IER1_CPCS_OFFSET                                  4
#define AVR32_TC_IER1_CPCS_SIZE                                    1
#define AVR32_TC_IER1_ETRGS                                        7
#define AVR32_TC_IER1_ETRGS_MASK                          0x00000080
#define AVR32_TC_IER1_ETRGS_OFFSET                                 7
#define AVR32_TC_IER1_ETRGS_SIZE                                   1
#define AVR32_TC_IER1_LDRAS                                        5
#define AVR32_TC_IER1_LDRAS_MASK                          0x00000020
#define AVR32_TC_IER1_LDRAS_OFFSET                                 5
#define AVR32_TC_IER1_LDRAS_SIZE                                   1
#define AVR32_TC_IER1_LDRBS                                        6
#define AVR32_TC_IER1_LDRBS_MASK                          0x00000040
#define AVR32_TC_IER1_LDRBS_OFFSET                                 6
#define AVR32_TC_IER1_LDRBS_SIZE                                   1
#define AVR32_TC_IER1_LOVRS                                        1
#define AVR32_TC_IER1_LOVRS_MASK                          0x00000002
#define AVR32_TC_IER1_LOVRS_OFFSET                                 1
#define AVR32_TC_IER1_LOVRS_SIZE                                   1
#define AVR32_TC_IER2                                     0x000000a4
#define AVR32_TC_IER2_COVFS                                        0
#define AVR32_TC_IER2_COVFS_MASK                          0x00000001
#define AVR32_TC_IER2_COVFS_OFFSET                                 0
#define AVR32_TC_IER2_COVFS_SIZE                                   1
#define AVR32_TC_IER2_CPAS                                         2
#define AVR32_TC_IER2_CPAS_MASK                           0x00000004
#define AVR32_TC_IER2_CPAS_OFFSET                                  2
#define AVR32_TC_IER2_CPAS_SIZE                                    1
#define AVR32_TC_IER2_CPBS                                         3
#define AVR32_TC_IER2_CPBS_MASK                           0x00000008
#define AVR32_TC_IER2_CPBS_OFFSET                                  3
#define AVR32_TC_IER2_CPBS_SIZE                                    1
#define AVR32_TC_IER2_CPCS                                         4
#define AVR32_TC_IER2_CPCS_MASK                           0x00000010
#define AVR32_TC_IER2_CPCS_OFFSET                                  4
#define AVR32_TC_IER2_CPCS_SIZE                                    1
#define AVR32_TC_IER2_ETRGS                                        7
#define AVR32_TC_IER2_ETRGS_MASK                          0x00000080
#define AVR32_TC_IER2_ETRGS_OFFSET                                 7
#define AVR32_TC_IER2_ETRGS_SIZE                                   1
#define AVR32_TC_IER2_LDRAS                                        5
#define AVR32_TC_IER2_LDRAS_MASK                          0x00000020
#define AVR32_TC_IER2_LDRAS_OFFSET                                 5
#define AVR32_TC_IER2_LDRAS_SIZE                                   1
#define AVR32_TC_IER2_LDRBS                                        6
#define AVR32_TC_IER2_LDRBS_MASK                          0x00000040
#define AVR32_TC_IER2_LDRBS_OFFSET                                 6
#define AVR32_TC_IER2_LDRBS_SIZE                                   1
#define AVR32_TC_IER2_LOVRS                                        1
#define AVR32_TC_IER2_LOVRS_MASK                          0x00000002
#define AVR32_TC_IER2_LOVRS_OFFSET                                 1
#define AVR32_TC_IER2_LOVRS_SIZE                                   1
#define AVR32_TC_IMR0                                     0x0000002c
#define AVR32_TC_IMR0_COVFS                                        0
#define AVR32_TC_IMR0_COVFS_MASK                          0x00000001
#define AVR32_TC_IMR0_COVFS_OFFSET                                 0
#define AVR32_TC_IMR0_COVFS_SIZE                                   1
#define AVR32_TC_IMR0_CPAS                                         2
#define AVR32_TC_IMR0_CPAS_MASK                           0x00000004
#define AVR32_TC_IMR0_CPAS_OFFSET                                  2
#define AVR32_TC_IMR0_CPAS_SIZE                                    1
#define AVR32_TC_IMR0_CPBS                                         3
#define AVR32_TC_IMR0_CPBS_MASK                           0x00000008
#define AVR32_TC_IMR0_CPBS_OFFSET                                  3
#define AVR32_TC_IMR0_CPBS_SIZE                                    1
#define AVR32_TC_IMR0_CPCS                                         4
#define AVR32_TC_IMR0_CPCS_MASK                           0x00000010
#define AVR32_TC_IMR0_CPCS_OFFSET                                  4
#define AVR32_TC_IMR0_CPCS_SIZE                                    1
#define AVR32_TC_IMR0_ETRGS                                        7
#define AVR32_TC_IMR0_ETRGS_MASK                          0x00000080
#define AVR32_TC_IMR0_ETRGS_OFFSET                                 7
#define AVR32_TC_IMR0_ETRGS_SIZE                                   1
#define AVR32_TC_IMR0_LDRAS                                        5
#define AVR32_TC_IMR0_LDRAS_MASK                          0x00000020
#define AVR32_TC_IMR0_LDRAS_OFFSET                                 5
#define AVR32_TC_IMR0_LDRAS_SIZE                                   1
#define AVR32_TC_IMR0_LDRBS                                        6
#define AVR32_TC_IMR0_LDRBS_MASK                          0x00000040
#define AVR32_TC_IMR0_LDRBS_OFFSET                                 6
#define AVR32_TC_IMR0_LDRBS_SIZE                                   1
#define AVR32_TC_IMR0_LOVRS                                        1
#define AVR32_TC_IMR0_LOVRS_MASK                          0x00000002
#define AVR32_TC_IMR0_LOVRS_OFFSET                                 1
#define AVR32_TC_IMR0_LOVRS_SIZE                                   1
#define AVR32_TC_IMR1                                     0x0000006c
#define AVR32_TC_IMR1_COVFS                                        0
#define AVR32_TC_IMR1_COVFS_MASK                          0x00000001
#define AVR32_TC_IMR1_COVFS_OFFSET                                 0
#define AVR32_TC_IMR1_COVFS_SIZE                                   1
#define AVR32_TC_IMR1_CPAS                                         2
#define AVR32_TC_IMR1_CPAS_MASK                           0x00000004
#define AVR32_TC_IMR1_CPAS_OFFSET                                  2
#define AVR32_TC_IMR1_CPAS_SIZE                                    1
#define AVR32_TC_IMR1_CPBS                                         3
#define AVR32_TC_IMR1_CPBS_MASK                           0x00000008
#define AVR32_TC_IMR1_CPBS_OFFSET                                  3
#define AVR32_TC_IMR1_CPBS_SIZE                                    1
#define AVR32_TC_IMR1_CPCS                                         4
#define AVR32_TC_IMR1_CPCS_MASK                           0x00000010
#define AVR32_TC_IMR1_CPCS_OFFSET                                  4
#define AVR32_TC_IMR1_CPCS_SIZE                                    1
#define AVR32_TC_IMR1_ETRGS                                        7
#define AVR32_TC_IMR1_ETRGS_MASK                          0x00000080
#define AVR32_TC_IMR1_ETRGS_OFFSET                                 7
#define AVR32_TC_IMR1_ETRGS_SIZE                                   1
#define AVR32_TC_IMR1_LDRAS                                        5
#define AVR32_TC_IMR1_LDRAS_MASK                          0x00000020
#define AVR32_TC_IMR1_LDRAS_OFFSET                                 5
#define AVR32_TC_IMR1_LDRAS_SIZE                                   1
#define AVR32_TC_IMR1_LDRBS                                        6
#define AVR32_TC_IMR1_LDRBS_MASK                          0x00000040
#define AVR32_TC_IMR1_LDRBS_OFFSET                                 6
#define AVR32_TC_IMR1_LDRBS_SIZE                                   1
#define AVR32_TC_IMR1_LOVRS                                        1
#define AVR32_TC_IMR1_LOVRS_MASK                          0x00000002
#define AVR32_TC_IMR1_LOVRS_OFFSET                                 1
#define AVR32_TC_IMR1_LOVRS_SIZE                                   1
#define AVR32_TC_IMR2                                     0x000000ac
#define AVR32_TC_IMR2_COVFS                                        0
#define AVR32_TC_IMR2_COVFS_MASK                          0x00000001
#define AVR32_TC_IMR2_COVFS_OFFSET                                 0
#define AVR32_TC_IMR2_COVFS_SIZE                                   1
#define AVR32_TC_IMR2_CPAS                                         2
#define AVR32_TC_IMR2_CPAS_MASK                           0x00000004
#define AVR32_TC_IMR2_CPAS_OFFSET                                  2
#define AVR32_TC_IMR2_CPAS_SIZE                                    1
#define AVR32_TC_IMR2_CPBS                                         3
#define AVR32_TC_IMR2_CPBS_MASK                           0x00000008
#define AVR32_TC_IMR2_CPBS_OFFSET                                  3
#define AVR32_TC_IMR2_CPBS_SIZE                                    1
#define AVR32_TC_IMR2_CPCS                                         4
#define AVR32_TC_IMR2_CPCS_MASK                           0x00000010
#define AVR32_TC_IMR2_CPCS_OFFSET                                  4
#define AVR32_TC_IMR2_CPCS_SIZE                                    1
#define AVR32_TC_IMR2_ETRGS                                        7
#define AVR32_TC_IMR2_ETRGS_MASK                          0x00000080
#define AVR32_TC_IMR2_ETRGS_OFFSET                                 7
#define AVR32_TC_IMR2_ETRGS_SIZE                                   1
#define AVR32_TC_IMR2_LDRAS                                        5
#define AVR32_TC_IMR2_LDRAS_MASK                          0x00000020
#define AVR32_TC_IMR2_LDRAS_OFFSET                                 5
#define AVR32_TC_IMR2_LDRAS_SIZE                                   1
#define AVR32_TC_IMR2_LDRBS                                        6
#define AVR32_TC_IMR2_LDRBS_MASK                          0x00000040
#define AVR32_TC_IMR2_LDRBS_OFFSET                                 6
#define AVR32_TC_IMR2_LDRBS_SIZE                                   1
#define AVR32_TC_IMR2_LOVRS                                        1
#define AVR32_TC_IMR2_LOVRS_MASK                          0x00000002
#define AVR32_TC_IMR2_LOVRS_OFFSET                                 1
#define AVR32_TC_IMR2_LOVRS_SIZE                                   1
#define AVR32_TC_LDBDIS                                            7
#define AVR32_TC_LDBDIS_MASK                              0x00000080
#define AVR32_TC_LDBDIS_OFFSET                                     7
#define AVR32_TC_LDBDIS_SIZE                                       1
#define AVR32_TC_LDBSTOP                                           6
#define AVR32_TC_LDBSTOP_MASK                             0x00000040
#define AVR32_TC_LDBSTOP_OFFSET                                    6
#define AVR32_TC_LDBSTOP_SIZE                                      1
#define AVR32_TC_LDRA                                             16
#define AVR32_TC_LDRAS                                             5
#define AVR32_TC_LDRAS_MASK                               0x00000020
#define AVR32_TC_LDRAS_OFFSET                                      5
#define AVR32_TC_LDRAS_SIZE                                        1
#define AVR32_TC_LDRA_BIOTH_EDGES_TIOA                    0x00000003
#define AVR32_TC_LDRA_MASK                                0x00030000
#define AVR32_TC_LDRA_NEG_EDGE_TIOA                       0x00000002
#define AVR32_TC_LDRA_NO_EDGE                             0x00000000
#define AVR32_TC_LDRA_OFFSET                                      16
#define AVR32_TC_LDRA_POS_EDGE_TIOA                       0x00000001
#define AVR32_TC_LDRA_SIZE                                         2
#define AVR32_TC_LDRB                                             18
#define AVR32_TC_LDRBS                                             6
#define AVR32_TC_LDRBS_MASK                               0x00000040
#define AVR32_TC_LDRBS_OFFSET                                      6
#define AVR32_TC_LDRBS_SIZE                                        1
#define AVR32_TC_LDRB_BIOTH_EDGES_TIOA                    0x00000003
#define AVR32_TC_LDRB_MASK                                0x000c0000
#define AVR32_TC_LDRB_NEG_EDGE_TIOA                       0x00000002
#define AVR32_TC_LDRB_NO_EDGE                             0x00000000
#define AVR32_TC_LDRB_OFFSET                                      18
#define AVR32_TC_LDRB_POS_EDGE_TIOA                       0x00000001
#define AVR32_TC_LDRB_SIZE                                         2
#define AVR32_TC_LOVRS                                             1
#define AVR32_TC_LOVRS_MASK                               0x00000002
#define AVR32_TC_LOVRS_OFFSET                                      1
#define AVR32_TC_LOVRS_SIZE                                        1
#define AVR32_TC_MTIOA                                            17
#define AVR32_TC_MTIOA_MASK                               0x00020000
#define AVR32_TC_MTIOA_OFFSET                                     17
#define AVR32_TC_MTIOA_SIZE                                        1
#define AVR32_TC_MTIOB                                            18
#define AVR32_TC_MTIOB_MASK                               0x00040000
#define AVR32_TC_MTIOB_OFFSET                                     18
#define AVR32_TC_MTIOB_SIZE                                        1
#define AVR32_TC_NEG_EDGE                                 0x00000002
#define AVR32_TC_NEG_EDGE_TIOA                            0x00000002
#define AVR32_TC_NONE                                     0x00000000
#define AVR32_TC_NOT_GATED                                0x00000000
#define AVR32_TC_NO_CLK                                   0x00000001
#define AVR32_TC_NO_EDGE                                  0x00000000
#define AVR32_TC_POS_EDGE                                 0x00000001
#define AVR32_TC_POS_EDGE_TIOA                            0x00000001
#define AVR32_TC_RA                                                0
#define AVR32_TC_RA0                                      0x00000014
#define AVR32_TC_RA0_RA                                            0
#define AVR32_TC_RA0_RA_MASK                              0x0000ffff
#define AVR32_TC_RA0_RA_OFFSET                                     0
#define AVR32_TC_RA0_RA_SIZE                                      16
#define AVR32_TC_RA1                                      0x00000054
#define AVR32_TC_RA1_RA                                            0
#define AVR32_TC_RA1_RA_MASK                              0x0000ffff
#define AVR32_TC_RA1_RA_OFFSET                                     0
#define AVR32_TC_RA1_RA_SIZE                                      16
#define AVR32_TC_RA2                                      0x00000094
#define AVR32_TC_RA2_RA                                            0
#define AVR32_TC_RA2_RA_MASK                              0x0000ffff
#define AVR32_TC_RA2_RA_OFFSET                                     0
#define AVR32_TC_RA2_RA_SIZE                                      16
#define AVR32_TC_RA_MASK                                  0x0000ffff
#define AVR32_TC_RA_OFFSET                                         0
#define AVR32_TC_RA_SIZE                                          16
#define AVR32_TC_RB                                                0
#define AVR32_TC_RB0                                      0x00000018
#define AVR32_TC_RB0_RB                                            0
#define AVR32_TC_RB0_RB_MASK                              0x0000ffff
#define AVR32_TC_RB0_RB_OFFSET                                     0
#define AVR32_TC_RB0_RB_SIZE                                      16
#define AVR32_TC_RB1                                      0x00000058
#define AVR32_TC_RB1_RB                                            0
#define AVR32_TC_RB1_RB_MASK                              0x0000ffff
#define AVR32_TC_RB1_RB_OFFSET                                     0
#define AVR32_TC_RB1_RB_SIZE                                      16
#define AVR32_TC_RB2                                      0x00000098
#define AVR32_TC_RB2_RB                                            0
#define AVR32_TC_RB2_RB_MASK                              0x0000ffff
#define AVR32_TC_RB2_RB_OFFSET                                     0
#define AVR32_TC_RB2_RB_SIZE                                      16
#define AVR32_TC_RB_MASK                                  0x0000ffff
#define AVR32_TC_RB_OFFSET                                         0
#define AVR32_TC_RB_SIZE                                          16
#define AVR32_TC_RC                                                0
#define AVR32_TC_RC0                                      0x0000001c
#define AVR32_TC_RC0_RC                                            0
#define AVR32_TC_RC0_RC_MASK                              0x0000ffff
#define AVR32_TC_RC0_RC_OFFSET                                     0
#define AVR32_TC_RC0_RC_SIZE                                      16
#define AVR32_TC_RC1                                      0x0000005c
#define AVR32_TC_RC1_RC                                            0
#define AVR32_TC_RC1_RC_MASK                              0x0000ffff
#define AVR32_TC_RC1_RC_OFFSET                                     0
#define AVR32_TC_RC1_RC_SIZE                                      16
#define AVR32_TC_RC2                                      0x0000009c
#define AVR32_TC_RC2_RC                                            0
#define AVR32_TC_RC2_RC_MASK                              0x0000ffff
#define AVR32_TC_RC2_RC_OFFSET                                     0
#define AVR32_TC_RC2_RC_SIZE                                      16
#define AVR32_TC_RC_MASK                                  0x0000ffff
#define AVR32_TC_RC_OFFSET                                         0
#define AVR32_TC_RC_SIZE                                          16
#define AVR32_TC_SET                                      0x00000001
#define AVR32_TC_SR0                                      0x00000020
#define AVR32_TC_SR0_CLKSTA                                       16
#define AVR32_TC_SR0_CLKSTA_MASK                          0x00010000
#define AVR32_TC_SR0_CLKSTA_OFFSET                                16
#define AVR32_TC_SR0_CLKSTA_SIZE                                   1
#define AVR32_TC_SR0_COVFS                                         0
#define AVR32_TC_SR0_COVFS_MASK                           0x00000001
#define AVR32_TC_SR0_COVFS_OFFSET                                  0
#define AVR32_TC_SR0_COVFS_SIZE                                    1
#define AVR32_TC_SR0_CPAS                                          2
#define AVR32_TC_SR0_CPAS_MASK                            0x00000004
#define AVR32_TC_SR0_CPAS_OFFSET                                   2
#define AVR32_TC_SR0_CPAS_SIZE                                     1
#define AVR32_TC_SR0_CPBS                                          3
#define AVR32_TC_SR0_CPBS_MASK                            0x00000008
#define AVR32_TC_SR0_CPBS_OFFSET                                   3
#define AVR32_TC_SR0_CPBS_SIZE                                     1
#define AVR32_TC_SR0_CPCS                                          4
#define AVR32_TC_SR0_CPCS_MASK                            0x00000010
#define AVR32_TC_SR0_CPCS_OFFSET                                   4
#define AVR32_TC_SR0_CPCS_SIZE                                     1
#define AVR32_TC_SR0_ETRGS                                         7
#define AVR32_TC_SR0_ETRGS_MASK                           0x00000080
#define AVR32_TC_SR0_ETRGS_OFFSET                                  7
#define AVR32_TC_SR0_ETRGS_SIZE                                    1
#define AVR32_TC_SR0_LDRAS                                         5
#define AVR32_TC_SR0_LDRAS_MASK                           0x00000020
#define AVR32_TC_SR0_LDRAS_OFFSET                                  5
#define AVR32_TC_SR0_LDRAS_SIZE                                    1
#define AVR32_TC_SR0_LDRBS                                         6
#define AVR32_TC_SR0_LDRBS_MASK                           0x00000040
#define AVR32_TC_SR0_LDRBS_OFFSET                                  6
#define AVR32_TC_SR0_LDRBS_SIZE                                    1
#define AVR32_TC_SR0_LOVRS                                         1
#define AVR32_TC_SR0_LOVRS_MASK                           0x00000002
#define AVR32_TC_SR0_LOVRS_OFFSET                                  1
#define AVR32_TC_SR0_LOVRS_SIZE                                    1
#define AVR32_TC_SR0_MTIOA                                        17
#define AVR32_TC_SR0_MTIOA_MASK                           0x00020000
#define AVR32_TC_SR0_MTIOA_OFFSET                                 17
#define AVR32_TC_SR0_MTIOA_SIZE                                    1
#define AVR32_TC_SR0_MTIOB                                        18
#define AVR32_TC_SR0_MTIOB_MASK                           0x00040000
#define AVR32_TC_SR0_MTIOB_OFFSET                                 18
#define AVR32_TC_SR0_MTIOB_SIZE                                    1
#define AVR32_TC_SR1                                      0x00000060
#define AVR32_TC_SR1_CLKSTA                                       16
#define AVR32_TC_SR1_CLKSTA_MASK                          0x00010000
#define AVR32_TC_SR1_CLKSTA_OFFSET                                16
#define AVR32_TC_SR1_CLKSTA_SIZE                                   1
#define AVR32_TC_SR1_COVFS                                         0
#define AVR32_TC_SR1_COVFS_MASK                           0x00000001
#define AVR32_TC_SR1_COVFS_OFFSET                                  0
#define AVR32_TC_SR1_COVFS_SIZE                                    1
#define AVR32_TC_SR1_CPAS                                          2
#define AVR32_TC_SR1_CPAS_MASK                            0x00000004
#define AVR32_TC_SR1_CPAS_OFFSET                                   2
#define AVR32_TC_SR1_CPAS_SIZE                                     1
#define AVR32_TC_SR1_CPBS                                          3
#define AVR32_TC_SR1_CPBS_MASK                            0x00000008
#define AVR32_TC_SR1_CPBS_OFFSET                                   3
#define AVR32_TC_SR1_CPBS_SIZE                                     1
#define AVR32_TC_SR1_CPCS                                          4
#define AVR32_TC_SR1_CPCS_MASK                            0x00000010
#define AVR32_TC_SR1_CPCS_OFFSET                                   4
#define AVR32_TC_SR1_CPCS_SIZE                                     1
#define AVR32_TC_SR1_ETRGS                                         7
#define AVR32_TC_SR1_ETRGS_MASK                           0x00000080
#define AVR32_TC_SR1_ETRGS_OFFSET                                  7
#define AVR32_TC_SR1_ETRGS_SIZE                                    1
#define AVR32_TC_SR1_LDRAS                                         5
#define AVR32_TC_SR1_LDRAS_MASK                           0x00000020
#define AVR32_TC_SR1_LDRAS_OFFSET                                  5
#define AVR32_TC_SR1_LDRAS_SIZE                                    1
#define AVR32_TC_SR1_LDRBS                                         6
#define AVR32_TC_SR1_LDRBS_MASK                           0x00000040
#define AVR32_TC_SR1_LDRBS_OFFSET                                  6
#define AVR32_TC_SR1_LDRBS_SIZE                                    1
#define AVR32_TC_SR1_LOVRS                                         1
#define AVR32_TC_SR1_LOVRS_MASK                           0x00000002
#define AVR32_TC_SR1_LOVRS_OFFSET                                  1
#define AVR32_TC_SR1_LOVRS_SIZE                                    1
#define AVR32_TC_SR1_MTIOA                                        17
#define AVR32_TC_SR1_MTIOA_MASK                           0x00020000
#define AVR32_TC_SR1_MTIOA_OFFSET                                 17
#define AVR32_TC_SR1_MTIOA_SIZE                                    1
#define AVR32_TC_SR1_MTIOB                                        18
#define AVR32_TC_SR1_MTIOB_MASK                           0x00040000
#define AVR32_TC_SR1_MTIOB_OFFSET                                 18
#define AVR32_TC_SR1_MTIOB_SIZE                                    1
#define AVR32_TC_SR2                                      0x000000a0
#define AVR32_TC_SR2_CLKSTA                                       16
#define AVR32_TC_SR2_CLKSTA_MASK                          0x00010000
#define AVR32_TC_SR2_CLKSTA_OFFSET                                16
#define AVR32_TC_SR2_CLKSTA_SIZE                                   1
#define AVR32_TC_SR2_COVFS                                         0
#define AVR32_TC_SR2_COVFS_MASK                           0x00000001
#define AVR32_TC_SR2_COVFS_OFFSET                                  0
#define AVR32_TC_SR2_COVFS_SIZE                                    1
#define AVR32_TC_SR2_CPAS                                          2
#define AVR32_TC_SR2_CPAS_MASK                            0x00000004
#define AVR32_TC_SR2_CPAS_OFFSET                                   2
#define AVR32_TC_SR2_CPAS_SIZE                                     1
#define AVR32_TC_SR2_CPBS                                          3
#define AVR32_TC_SR2_CPBS_MASK                            0x00000008
#define AVR32_TC_SR2_CPBS_OFFSET                                   3
#define AVR32_TC_SR2_CPBS_SIZE                                     1
#define AVR32_TC_SR2_CPCS                                          4
#define AVR32_TC_SR2_CPCS_MASK                            0x00000010
#define AVR32_TC_SR2_CPCS_OFFSET                                   4
#define AVR32_TC_SR2_CPCS_SIZE                                     1
#define AVR32_TC_SR2_ETRGS                                         7
#define AVR32_TC_SR2_ETRGS_MASK                           0x00000080
#define AVR32_TC_SR2_ETRGS_OFFSET                                  7
#define AVR32_TC_SR2_ETRGS_SIZE                                    1
#define AVR32_TC_SR2_LDRAS                                         5
#define AVR32_TC_SR2_LDRAS_MASK                           0x00000020
#define AVR32_TC_SR2_LDRAS_OFFSET                                  5
#define AVR32_TC_SR2_LDRAS_SIZE                                    1
#define AVR32_TC_SR2_LDRBS                                         6
#define AVR32_TC_SR2_LDRBS_MASK                           0x00000040
#define AVR32_TC_SR2_LDRBS_OFFSET                                  6
#define AVR32_TC_SR2_LDRBS_SIZE                                    1
#define AVR32_TC_SR2_LOVRS                                         1
#define AVR32_TC_SR2_LOVRS_MASK                           0x00000002
#define AVR32_TC_SR2_LOVRS_OFFSET                                  1
#define AVR32_TC_SR2_LOVRS_SIZE                                    1
#define AVR32_TC_SR2_MTIOA                                        17
#define AVR32_TC_SR2_MTIOA_MASK                           0x00020000
#define AVR32_TC_SR2_MTIOA_OFFSET                                 17
#define AVR32_TC_SR2_MTIOA_SIZE                                    1
#define AVR32_TC_SR2_MTIOB                                        18
#define AVR32_TC_SR2_MTIOB_MASK                           0x00040000
#define AVR32_TC_SR2_MTIOB_OFFSET                                 18
#define AVR32_TC_SR2_MTIOB_SIZE                                    1
#define AVR32_TC_SWTRG                                             2
#define AVR32_TC_SWTRG_MASK                               0x00000004
#define AVR32_TC_SWTRG_OFFSET                                      2
#define AVR32_TC_SWTRG_SIZE                                        1
#define AVR32_TC_SYNC                                              0
#define AVR32_TC_SYNC_MASK                                0x00000001
#define AVR32_TC_SYNC_OFFSET                                       0
#define AVR32_TC_SYNC_SIZE                                         1
#define AVR32_TC_TC0XC0S                                           0
#define AVR32_TC_TC0XC0S_MASK                             0x00000003
#define AVR32_TC_TC0XC0S_NO_CLK                           0x00000001
#define AVR32_TC_TC0XC0S_OFFSET                                    0
#define AVR32_TC_TC0XC0S_SIZE                                      2
#define AVR32_TC_TC0XC0S_TCLK0                            0x00000000
#define AVR32_TC_TC0XC0S_TIOA1                            0x00000002
#define AVR32_TC_TC0XC0S_TIOA2                            0x00000003
#define AVR32_TC_TC1XC1S                                           2
#define AVR32_TC_TC1XC1S_MASK                             0x0000000c
#define AVR32_TC_TC1XC1S_NO_CLK                           0x00000001
#define AVR32_TC_TC1XC1S_OFFSET                                    2
#define AVR32_TC_TC1XC1S_SIZE                                      2
#define AVR32_TC_TC1XC1S_TCLK1                            0x00000000
#define AVR32_TC_TC1XC1S_TIOA0                            0x00000002
#define AVR32_TC_TC1XC1S_TIOA2                            0x00000003
#define AVR32_TC_TC2XC2S                                           4
#define AVR32_TC_TC2XC2S_MASK                             0x00000030
#define AVR32_TC_TC2XC2S_NO_CLK                           0x00000001
#define AVR32_TC_TC2XC2S_OFFSET                                    4
#define AVR32_TC_TC2XC2S_SIZE                                      2
#define AVR32_TC_TC2XC2S_TCLK2                            0x00000000
#define AVR32_TC_TC2XC2S_TIOA0                            0x00000002
#define AVR32_TC_TC2XC2S_TIOA1                            0x00000003
#define AVR32_TC_TCCLKS                                            0
#define AVR32_TC_TCCLKS_MASK                              0x00000007
#define AVR32_TC_TCCLKS_OFFSET                                     0
#define AVR32_TC_TCCLKS_SIZE                                       3
#define AVR32_TC_TCCLKS_TIMER_CLOCK1                      0x00000000
#define AVR32_TC_TCCLKS_TIMER_CLOCK2                      0x00000001
#define AVR32_TC_TCCLKS_TIMER_CLOCK3                      0x00000002
#define AVR32_TC_TCCLKS_TIMER_CLOCK4                      0x00000003
#define AVR32_TC_TCCLKS_TIMER_CLOCK5                      0x00000004
#define AVR32_TC_TCCLKS_XC0                               0x00000005
#define AVR32_TC_TCCLKS_XC1                               0x00000006
#define AVR32_TC_TCCLKS_XC2                               0x00000007
#define AVR32_TC_TCLK0                                    0x00000000
#define AVR32_TC_TCLK1                                    0x00000000
#define AVR32_TC_TCLK2                                    0x00000000
#define AVR32_TC_TIMER_CLOCK1                             0x00000000
#define AVR32_TC_TIMER_CLOCK2                             0x00000001
#define AVR32_TC_TIMER_CLOCK3                             0x00000002
#define AVR32_TC_TIMER_CLOCK4                             0x00000003
#define AVR32_TC_TIMER_CLOCK5                             0x00000004
#define AVR32_TC_TIOA0                                    0x00000002
#define AVR32_TC_TIOA2                                    0x00000003
#define AVR32_TC_TIOB_INPUT                               0x00000000
#define AVR32_TC_TOGGLE                                   0x00000003
#define AVR32_TC_UPDOWN_AUTO                              0x00000003
#define AVR32_TC_UPDOWN_NO_AUTO                           0x00000001
#define AVR32_TC_UP_AUTO                                  0x00000002
#define AVR32_TC_UP_NO_AUTO                               0x00000000
#define AVR32_TC_WAVE                                             15
#define AVR32_TC_WAVE_MASK                                0x00008000
#define AVR32_TC_WAVE_OFFSET                                      15
#define AVR32_TC_WAVE_SIZE                                         1
#define AVR32_TC_WAVSEL                                           13
#define AVR32_TC_WAVSEL_MASK                              0x00006000
#define AVR32_TC_WAVSEL_OFFSET                                    13
#define AVR32_TC_WAVSEL_SIZE                                       2
#define AVR32_TC_WAVSEL_UPDOWN_AUTO                       0x00000003
#define AVR32_TC_WAVSEL_UPDOWN_NO_AUTO                    0x00000001
#define AVR32_TC_WAVSEL_UP_AUTO                           0x00000002
#define AVR32_TC_WAVSEL_UP_NO_AUTO                        0x00000000
#define AVR32_TC_XC0                                      0x00000005
#define AVR32_TC_XC0_OUTPUT                               0x00000001
#define AVR32_TC_XC1                                      0x00000006
#define AVR32_TC_XC1_OUTPUT                               0x00000002
#define AVR32_TC_XC2                                      0x00000007
#define AVR32_TC_XC2_OUTPUT                               0x00000003
#define AVR32_TC_VARIANT                                          16
#define AVR32_TC_VARIANT_MASK                             0x00070000
#define AVR32_TC_VARIANT_OFFSET                                   16
#define AVR32_TC_VARIANT_SIZE                                      3
#define AVR32_TC_VERSION                                  0x000000fc
#define AVR32_TC_VERSION_MASK                             0x00000fff
#define AVR32_TC_VERSION_OFFSET                                    0
#define AVR32_TC_VERSION_SIZE                                     12
#define AVR32_TC_VERSION_VARIANT                                  16
#define AVR32_TC_VERSION_VARIANT_MASK                     0x00070000
#define AVR32_TC_VERSION_VARIANT_OFFSET                           16
#define AVR32_TC_VERSION_VARIANT_SIZE                              3
#define AVR32_TC_VERSION_VERSION                                   0
#define AVR32_TC_VERSION_VERSION_MASK                     0x00000fff
#define AVR32_TC_VERSION_VERSION_OFFSET                            0
#define AVR32_TC_VERSION_VERSION_SIZE                             12




#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_tc_ccr_t {
    unsigned int                 :29;
    unsigned int swtrg           : 1;
    unsigned int clkdis          : 1;
    unsigned int clken           : 1;
} avr32_tc_ccr_t;



typedef union avr32_tc_cmr_t {
  struct {
    unsigned int                 :12;
    unsigned int ldrb            : 2;
    unsigned int ldra            : 2;
    unsigned int wave            : 1;
    unsigned int cpctrg          : 1;
    unsigned int                 : 3;
    unsigned int abetrg          : 1;
    unsigned int etrgedg         : 2;
    unsigned int ldbdis          : 1;
    unsigned int ldbstop         : 1;
    unsigned int burst           : 2;
    unsigned int clki            : 1;
    unsigned int tcclks          : 3;
  } capture;
  struct {
    unsigned int bswtrg          : 2;
    unsigned int beevt           : 2;
    unsigned int bcpc            : 2;
    unsigned int bcpb            : 2;
    unsigned int aswtrg          : 2;
    unsigned int aeevt           : 2;
    unsigned int acpc            : 2;
    unsigned int acpa            : 2;
    unsigned int wave            : 1;
    unsigned int wavsel          : 2;
    unsigned int enetrg          : 1;
    unsigned int eevt            : 2;
    unsigned int eevtedg         : 2;
    unsigned int cpcdis          : 1;
    unsigned int cpcstop         : 1;
    unsigned int burst           : 2;
    unsigned int clki            : 1;
    unsigned int tcclks          : 3;
  } waveform;
} avr32_tc_cmr_t;



typedef struct avr32_tc_cv_t {
    unsigned int                 :16;
    unsigned int cv              :16;
} avr32_tc_cv_t;



typedef struct avr32_tc_ra_t {
    unsigned int                 :16;
    unsigned int ra              :16;
} avr32_tc_ra_t;



typedef struct avr32_tc_rb_t {
    unsigned int                 :16;
    unsigned int rb              :16;
} avr32_tc_rb_t;



typedef struct avr32_tc_rc_t {
    unsigned int                 :16;
    unsigned int rc              :16;
} avr32_tc_rc_t;



typedef struct avr32_tc_sr_t {
    unsigned int                 :13;
    unsigned int mtiob           : 1;
    unsigned int mtioa           : 1;
    unsigned int clksta          : 1;
    unsigned int                 : 8;
    unsigned int etrgs           : 1;
    unsigned int ldrbs           : 1;
    unsigned int ldras           : 1;
    unsigned int cpcs            : 1;
    unsigned int cpbs            : 1;
    unsigned int cpas            : 1;
    unsigned int lovrs           : 1;
    unsigned int covfs           : 1;
} avr32_tc_sr_t;



typedef struct avr32_tc_ier_t {
    unsigned int                 :24;
    unsigned int etrgs           : 1;
    unsigned int ldrbs           : 1;
    unsigned int ldras           : 1;
    unsigned int cpcs            : 1;
    unsigned int cpbs            : 1;
    unsigned int cpas            : 1;
    unsigned int lovrs           : 1;
    unsigned int covfs           : 1;
} avr32_tc_ier_t;



typedef struct avr32_tc_idr_t {
    unsigned int                 :24;
    unsigned int etrgs           : 1;
    unsigned int ldrbs           : 1;
    unsigned int ldras           : 1;
    unsigned int cpcs            : 1;
    unsigned int cpbs            : 1;
    unsigned int cpas            : 1;
    unsigned int lovrs           : 1;
    unsigned int covfs           : 1;
} avr32_tc_idr_t;



typedef struct avr32_tc_imr_t {
    unsigned int                 :24;
    unsigned int etrgs           : 1;
    unsigned int ldrbs           : 1;
    unsigned int ldras           : 1;
    unsigned int cpcs            : 1;
    unsigned int cpbs            : 1;
    unsigned int cpas            : 1;
    unsigned int lovrs           : 1;
    unsigned int covfs           : 1;
} avr32_tc_imr_t;



typedef struct avr32_tc_bcr_t {
    unsigned int                 :31;
    unsigned int sync            : 1;
} avr32_tc_bcr_t;



typedef struct avr32_tc_bmr_t {
    unsigned int                 :26;
    unsigned int tc2xc2s         : 2;
    unsigned int tc1xc1s         : 2;
    unsigned int tc0xc0s         : 2;
} avr32_tc_bmr_t;



typedef struct avr32_tc_version_t {
    unsigned int                 :13;
    unsigned int variant         : 3;
    unsigned int                 : 4;
    unsigned int version         :12;
} avr32_tc_version_t;


typedef struct avr32_tc_channel_t {
  union {
          unsigned long                  ccr       ;//0x0000
          avr32_tc_ccr_t                 CCR       ;
  };
  union {
          unsigned long                  cmr       ;//0x0004
          avr32_tc_cmr_t                 CMR       ;
  };
          unsigned int                   :32       ;//0x0008
          unsigned int                   :32       ;//0x000c
  union {
    const unsigned long                  cv        ;//0x0010
    const avr32_tc_cv_t                  CV        ;
  };
  union {
          unsigned long                  ra        ;//0x0014
          avr32_tc_ra_t                  RA        ;
  };
  union {
          unsigned long                  rb        ;//0x0018
          avr32_tc_rb_t                  RB        ;
  };
  union {
          unsigned long                  rc        ;//0x001c
          avr32_tc_rc_t                  RC        ;
  };
  union {
    const unsigned long                  sr        ;//0x0020
    const avr32_tc_sr_t                  SR        ;
  };
  union {
          unsigned long                  ier       ;//0x0024
          avr32_tc_ier_t                 IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0028
          avr32_tc_idr_t                 IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x002c
    const avr32_tc_imr_t                 IMR       ;
  };
          unsigned int                   :32       ;//0x0030
          unsigned int                   :32       ;//0x0034
          unsigned int                   :32       ;//0x0038
          unsigned int                   :32       ;//0x003c
} avr32_tc_channel_t;


typedef struct avr32_tc_t {
  avr32_tc_channel_t channel[3];//0x0
  union {
          unsigned long                  bcr       ;//0x00c0
          avr32_tc_bcr_t                 BCR       ;
  };
  union {
          unsigned long                  bmr       ;//0x00c4
          avr32_tc_bmr_t                 BMR       ;
  };
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
    const avr32_tc_version_t             VERSION   ;
  };
} avr32_tc_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif


#if !defined (DEPRECATED_DISABLE)

#define AVR32_TC_CMR0_TCCLKS_TIMER_DIV1_CLOCK             0x00000000
#define AVR32_TC_CMR0_TCCLKS_TIMER_DIV2_CLOCK             0x00000001
#define AVR32_TC_CMR0_TCCLKS_TIMER_DIV3_CLOCK             0x00000002
#define AVR32_TC_CMR0_TCCLKS_TIMER_DIV4_CLOCK             0x00000003
#define AVR32_TC_CMR0_TCCLKS_TIMER_DIV5_CLOCK             0x00000004

#define AVR32_TC_CMR1_TCCLKS_TIMER_DIV1_CLOCK             0x00000000
#define AVR32_TC_CMR1_TCCLKS_TIMER_DIV2_CLOCK             0x00000001
#define AVR32_TC_CMR1_TCCLKS_TIMER_DIV3_CLOCK             0x00000002
#define AVR32_TC_CMR1_TCCLKS_TIMER_DIV4_CLOCK             0x00000003
#define AVR32_TC_CMR1_TCCLKS_TIMER_DIV5_CLOCK             0x00000004

#define AVR32_TC_CMR2_TCCLKS_TIMER_DIV1_CLOCK             0x00000000
#define AVR32_TC_CMR2_TCCLKS_TIMER_DIV2_CLOCK             0x00000001
#define AVR32_TC_CMR2_TCCLKS_TIMER_DIV3_CLOCK             0x00000002
#define AVR32_TC_CMR2_TCCLKS_TIMER_DIV4_CLOCK             0x00000003
#define AVR32_TC_CMR2_TCCLKS_TIMER_DIV5_CLOCK             0x00000004

#define AVR32_TC_TCCLKS_TIMER_DIV1_CLOCK                  0x00000000
#define AVR32_TC_TCCLKS_TIMER_DIV2_CLOCK                  0x00000001
#define AVR32_TC_TCCLKS_TIMER_DIV3_CLOCK                  0x00000002
#define AVR32_TC_TCCLKS_TIMER_DIV4_CLOCK                  0x00000003
#define AVR32_TC_TCCLKS_TIMER_DIV5_CLOCK                  0x00000004

#define AVR32_TC_TIMER_DIV1_CLOCK                         0x00000000
#define AVR32_TC_TIMER_DIV2_CLOCK                         0x00000001
#define AVR32_TC_TIMER_DIV3_CLOCK                         0x00000002
#define AVR32_TC_TIMER_DIV4_CLOCK                         0x00000003
#define AVR32_TC_TIMER_DIV5_CLOCK                         0x00000004

#endif


/*#ifdef AVR32_TC_222_H_INCLUDED*/
#endif

