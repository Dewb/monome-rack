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
#ifndef AVR32_SSC_310_H_INCLUDED
#define AVR32_SSC_310_H_INCLUDED

#define AVR32_SSC_H_VERSION 310

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_SSC_<register>
 - Bitfield mask:   AVR32_SSC_<register>_<bitfield>
 - Bitfield offset: AVR32_SSC_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_SSC_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_SSC_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_SSC_<bitfield>
 - Bitfield offset: AVR32_SSC_<bitfield>_OFFSET
 - Bitfield size:   AVR32_SSC_<bitfield>_SIZE
 - Bitfield values: AVR32_SSC_<bitfield>_<value name>
 - Bitfield values: AVR32_SSC_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_SSC_CKG                                               6
#define AVR32_SSC_CKG_HIGH                                 0x00000002
#define AVR32_SSC_CKG_LOW                                  0x00000001
#define AVR32_SSC_CKG_MASK                                 0x000000c0
#define AVR32_SSC_CKG_NONE                                 0x00000000
#define AVR32_SSC_CKG_OFFSET                                        6
#define AVR32_SSC_CKG_SIZE                                          2
#define AVR32_SSC_CKI                                               5
#define AVR32_SSC_CKI_MASK                                 0x00000020
#define AVR32_SSC_CKI_OFFSET                                        5
#define AVR32_SSC_CKI_SIZE                                          1
#define AVR32_SSC_CKO                                               2
#define AVR32_SSC_CKO_CONTINOUS_CLOCK_OUTPUT               0x00000001
#define AVR32_SSC_CKO_INPUT_ONLY                           0x00000000
#define AVR32_SSC_CKO_MASK                                 0x0000001c
#define AVR32_SSC_CKO_OFFSET                                        2
#define AVR32_SSC_CKO_SIZE                                          3
#define AVR32_SSC_CKS                                               0
#define AVR32_SSC_CKS_DIV_CLOCK                            0x00000000
#define AVR32_SSC_CKS_MASK                                 0x00000003
#define AVR32_SSC_CKS_OFFSET                                        0
#define AVR32_SSC_CKS_RK_CLOCK                             0x00000001
#define AVR32_SSC_CKS_RK_PIN                               0x00000002
#define AVR32_SSC_CKS_SIZE                                          2
#define AVR32_SSC_CKS_TK_CLOCK                             0x00000001
#define AVR32_SSC_CKS_TK_PIN                               0x00000002
#define AVR32_SSC_CMR                                      0x00000004
#define AVR32_SSC_CMR_DIV                                           0
#define AVR32_SSC_CMR_DIV_MASK                             0x00000fff
#define AVR32_SSC_CMR_DIV_NOT_ACTIVE                       0x00000000
#define AVR32_SSC_CMR_DIV_OFFSET                                    0
#define AVR32_SSC_CMR_DIV_SIZE                                     12
#define AVR32_SSC_COMPARE_0                                0x00000008
#define AVR32_SSC_CONTINOUS                                0x00000000
#define AVR32_SSC_CONTINOUS_CLOCK_OUTPUT                   0x00000001
#define AVR32_SSC_CR                                       0x00000000
#define AVR32_SSC_CR_RXDIS                                          1
#define AVR32_SSC_CR_RXDIS_MASK                            0x00000002
#define AVR32_SSC_CR_RXDIS_OFFSET                                   1
#define AVR32_SSC_CR_RXDIS_SIZE                                     1
#define AVR32_SSC_CR_RXEN                                           0
#define AVR32_SSC_CR_RXEN_MASK                             0x00000001
#define AVR32_SSC_CR_RXEN_OFFSET                                    0
#define AVR32_SSC_CR_RXEN_SIZE                                      1
#define AVR32_SSC_CR_SWRST                                         15
#define AVR32_SSC_CR_SWRST_MASK                            0x00008000
#define AVR32_SSC_CR_SWRST_OFFSET                                  15
#define AVR32_SSC_CR_SWRST_SIZE                                     1
#define AVR32_SSC_CR_TXDIS                                          9
#define AVR32_SSC_CR_TXDIS_MASK                            0x00000200
#define AVR32_SSC_CR_TXDIS_OFFSET                                   9
#define AVR32_SSC_CR_TXDIS_SIZE                                     1
#define AVR32_SSC_CR_TXEN                                           8
#define AVR32_SSC_CR_TXEN_MASK                             0x00000100
#define AVR32_SSC_CR_TXEN_OFFSET                                    8
#define AVR32_SSC_CR_TXEN_SIZE                                      1
#define AVR32_SSC_DATDEF                                            5
#define AVR32_SSC_DATDEF_MASK                              0x00000020
#define AVR32_SSC_DATDEF_OFFSET                                     5
#define AVR32_SSC_DATDEF_SIZE                                       1
#define AVR32_SSC_DATLEN                                            0
#define AVR32_SSC_DATLEN_MASK                              0x0000001f
#define AVR32_SSC_DATLEN_OFFSET                                     0
#define AVR32_SSC_DATLEN_SIZE                                       5
#define AVR32_SSC_DATNB                                             8
#define AVR32_SSC_DATNB_MASK                               0x00000f00
#define AVR32_SSC_DATNB_OFFSET                                      8
#define AVR32_SSC_DATNB_SIZE                                        4
#define AVR32_SSC_DETECT_ANY_EDGE_RF                       0x00000007
#define AVR32_SSC_DETECT_ANY_EDGE_TF                       0x00000007
#define AVR32_SSC_DETECT_FALLING_RF                        0x00000004
#define AVR32_SSC_DETECT_FALLING_TF                        0x00000004
#define AVR32_SSC_DETECT_HIGH_RF                           0x00000003
#define AVR32_SSC_DETECT_HIGH_TF                           0x00000003
#define AVR32_SSC_DETECT_LEVEL_CHANGE_RF                   0x00000006
#define AVR32_SSC_DETECT_LEVEL_CHANGE_TF                   0x00000006
#define AVR32_SSC_DETECT_LOW_RF                            0x00000002
#define AVR32_SSC_DETECT_LOW_TF                            0x00000002
#define AVR32_SSC_DETECT_RISING_RF                         0x00000005
#define AVR32_SSC_DETECT_RISING_TF                         0x00000005
#define AVR32_SSC_DIV                                               0
#define AVR32_SSC_DIV_CLOCK                                0x00000000
#define AVR32_SSC_DIV_MASK                                 0x00000fff
#define AVR32_SSC_DIV_NOT_ACTIVE                           0x00000000
#define AVR32_SSC_DIV_OFFSET                                        0
#define AVR32_SSC_DIV_SIZE                                         12
#define AVR32_SSC_ENDRX                                             6
#define AVR32_SSC_ENDRX_MASK                               0x00000040
#define AVR32_SSC_ENDRX_OFFSET                                      6
#define AVR32_SSC_ENDRX_SIZE                                        1
#define AVR32_SSC_ENDTX                                             2
#define AVR32_SSC_ENDTX_MASK                               0x00000004
#define AVR32_SSC_ENDTX_OFFSET                                      2
#define AVR32_SSC_ENDTX_SIZE                                        1
#define AVR32_SSC_FSDEN                                            23
#define AVR32_SSC_FSDEN_MASK                               0x00800000
#define AVR32_SSC_FSDEN_OFFSET                                     23
#define AVR32_SSC_FSDEN_SIZE                                        1
#define AVR32_SSC_FSEDGE                                           24
#define AVR32_SSC_FSEDGE_MASK                              0x01000000
#define AVR32_SSC_FSEDGE_OFFSET                                    24
#define AVR32_SSC_FSEDGE_SIZE                                       1
#define AVR32_SSC_FSLEN                                            16
#define AVR32_SSC_FSLENHI                                          28
#define AVR32_SSC_FSLENHI_MASK                             0xf0000000
#define AVR32_SSC_FSLENHI_OFFSET                                   28
#define AVR32_SSC_FSLENHI_SIZE                                      4
#define AVR32_SSC_FSLEN_MASK                               0x000f0000
#define AVR32_SSC_FSLEN_OFFSET                                     16
#define AVR32_SSC_FSLEN_SIZE                                        4
#define AVR32_SSC_FSOS                                             20
#define AVR32_SSC_FSOS_HIGH_DURING_DATA                    0x00000004
#define AVR32_SSC_FSOS_INPUT_ONLY                          0x00000000
#define AVR32_SSC_FSOS_LOW_DURING_DATA                     0x00000003
#define AVR32_SSC_FSOS_MASK                                0x00700000
#define AVR32_SSC_FSOS_NEG_PULSE                           0x00000001
#define AVR32_SSC_FSOS_OFFSET                                      20
#define AVR32_SSC_FSOS_POS_PULSE                           0x00000002
#define AVR32_SSC_FSOS_SIZE                                         3
#define AVR32_SSC_FSOS_TOGGLE_DATA_START                   0x00000005
#define AVR32_SSC_HIGH                                     0x00000002
#define AVR32_SSC_HIGH_DURING_DATA                         0x00000004
#define AVR32_SSC_IDR                                      0x00000048
#define AVR32_SSC_IDR_CP0                                           8
#define AVR32_SSC_IDR_CP0_MASK                             0x00000100
#define AVR32_SSC_IDR_CP0_OFFSET                                    8
#define AVR32_SSC_IDR_CP0_SIZE                                      1
#define AVR32_SSC_IDR_CP1                                           9
#define AVR32_SSC_IDR_CP1_MASK                             0x00000200
#define AVR32_SSC_IDR_CP1_OFFSET                                    9
#define AVR32_SSC_IDR_CP1_SIZE                                      1
#define AVR32_SSC_IDR_ENDRX                                         6
#define AVR32_SSC_IDR_ENDRX_MASK                           0x00000040
#define AVR32_SSC_IDR_ENDRX_OFFSET                                  6
#define AVR32_SSC_IDR_ENDRX_SIZE                                    1
#define AVR32_SSC_IDR_ENDTX                                         2
#define AVR32_SSC_IDR_ENDTX_MASK                           0x00000004
#define AVR32_SSC_IDR_ENDTX_OFFSET                                  2
#define AVR32_SSC_IDR_ENDTX_SIZE                                    1
#define AVR32_SSC_IDR_OVRUN                                         5
#define AVR32_SSC_IDR_OVRUN_MASK                           0x00000020
#define AVR32_SSC_IDR_OVRUN_OFFSET                                  5
#define AVR32_SSC_IDR_OVRUN_SIZE                                    1
#define AVR32_SSC_IDR_RXBUFF                                        7
#define AVR32_SSC_IDR_RXBUFF_MASK                          0x00000080
#define AVR32_SSC_IDR_RXBUFF_OFFSET                                 7
#define AVR32_SSC_IDR_RXBUFF_SIZE                                   1
#define AVR32_SSC_IDR_RXRDY                                         4
#define AVR32_SSC_IDR_RXRDY_MASK                           0x00000010
#define AVR32_SSC_IDR_RXRDY_OFFSET                                  4
#define AVR32_SSC_IDR_RXRDY_SIZE                                    1
#define AVR32_SSC_IDR_RXSYN                                        11
#define AVR32_SSC_IDR_RXSYN_MASK                           0x00000800
#define AVR32_SSC_IDR_RXSYN_OFFSET                                 11
#define AVR32_SSC_IDR_RXSYN_SIZE                                    1
#define AVR32_SSC_IDR_TXBUFE                                        3
#define AVR32_SSC_IDR_TXBUFE_MASK                          0x00000008
#define AVR32_SSC_IDR_TXBUFE_OFFSET                                 3
#define AVR32_SSC_IDR_TXBUFE_SIZE                                   1
#define AVR32_SSC_IDR_TXEMPTY                                       1
#define AVR32_SSC_IDR_TXEMPTY_MASK                         0x00000002
#define AVR32_SSC_IDR_TXEMPTY_OFFSET                                1
#define AVR32_SSC_IDR_TXEMPTY_SIZE                                  1
#define AVR32_SSC_IDR_TXRDY                                         0
#define AVR32_SSC_IDR_TXRDY_MASK                           0x00000001
#define AVR32_SSC_IDR_TXRDY_OFFSET                                  0
#define AVR32_SSC_IDR_TXRDY_SIZE                                    1
#define AVR32_SSC_IDR_TXSYN                                        10
#define AVR32_SSC_IDR_TXSYN_MASK                           0x00000400
#define AVR32_SSC_IDR_TXSYN_OFFSET                                 10
#define AVR32_SSC_IDR_TXSYN_SIZE                                    1
#define AVR32_SSC_IER                                      0x00000044
#define AVR32_SSC_IER_CP0                                           8
#define AVR32_SSC_IER_CP0_MASK                             0x00000100
#define AVR32_SSC_IER_CP0_OFFSET                                    8
#define AVR32_SSC_IER_CP0_SIZE                                      1
#define AVR32_SSC_IER_CP1                                           9
#define AVR32_SSC_IER_CP1_MASK                             0x00000200
#define AVR32_SSC_IER_CP1_OFFSET                                    9
#define AVR32_SSC_IER_CP1_SIZE                                      1
#define AVR32_SSC_IER_ENDRX                                         6
#define AVR32_SSC_IER_ENDRX_MASK                           0x00000040
#define AVR32_SSC_IER_ENDRX_OFFSET                                  6
#define AVR32_SSC_IER_ENDRX_SIZE                                    1
#define AVR32_SSC_IER_ENDTX                                         2
#define AVR32_SSC_IER_ENDTX_MASK                           0x00000004
#define AVR32_SSC_IER_ENDTX_OFFSET                                  2
#define AVR32_SSC_IER_ENDTX_SIZE                                    1
#define AVR32_SSC_IER_OVRUN                                         5
#define AVR32_SSC_IER_OVRUN_MASK                           0x00000020
#define AVR32_SSC_IER_OVRUN_OFFSET                                  5
#define AVR32_SSC_IER_OVRUN_SIZE                                    1
#define AVR32_SSC_IER_RXBUFF                                        7
#define AVR32_SSC_IER_RXBUFF_MASK                          0x00000080
#define AVR32_SSC_IER_RXBUFF_OFFSET                                 7
#define AVR32_SSC_IER_RXBUFF_SIZE                                   1
#define AVR32_SSC_IER_RXRDY                                         4
#define AVR32_SSC_IER_RXRDY_MASK                           0x00000010
#define AVR32_SSC_IER_RXRDY_OFFSET                                  4
#define AVR32_SSC_IER_RXRDY_SIZE                                    1
#define AVR32_SSC_IER_RXSYN                                        11
#define AVR32_SSC_IER_RXSYN_MASK                           0x00000800
#define AVR32_SSC_IER_RXSYN_OFFSET                                 11
#define AVR32_SSC_IER_RXSYN_SIZE                                    1
#define AVR32_SSC_IER_TXBUFE                                        3
#define AVR32_SSC_IER_TXBUFE_MASK                          0x00000008
#define AVR32_SSC_IER_TXBUFE_OFFSET                                 3
#define AVR32_SSC_IER_TXBUFE_SIZE                                   1
#define AVR32_SSC_IER_TXEMPTY                                       1
#define AVR32_SSC_IER_TXEMPTY_MASK                         0x00000002
#define AVR32_SSC_IER_TXEMPTY_OFFSET                                1
#define AVR32_SSC_IER_TXEMPTY_SIZE                                  1
#define AVR32_SSC_IER_TXRDY                                         0
#define AVR32_SSC_IER_TXRDY_MASK                           0x00000001
#define AVR32_SSC_IER_TXRDY_OFFSET                                  0
#define AVR32_SSC_IER_TXRDY_SIZE                                    1
#define AVR32_SSC_IER_TXSYN                                        10
#define AVR32_SSC_IER_TXSYN_MASK                           0x00000400
#define AVR32_SSC_IER_TXSYN_OFFSET                                 10
#define AVR32_SSC_IER_TXSYN_SIZE                                    1
#define AVR32_SSC_IMR                                      0x0000004c
#define AVR32_SSC_IMR_CP0                                           8
#define AVR32_SSC_IMR_CP0_MASK                             0x00000100
#define AVR32_SSC_IMR_CP0_OFFSET                                    8
#define AVR32_SSC_IMR_CP0_SIZE                                      1
#define AVR32_SSC_IMR_CP1                                           9
#define AVR32_SSC_IMR_CP1_MASK                             0x00000200
#define AVR32_SSC_IMR_CP1_OFFSET                                    9
#define AVR32_SSC_IMR_CP1_SIZE                                      1
#define AVR32_SSC_IMR_ENDRX                                         6
#define AVR32_SSC_IMR_ENDRX_MASK                           0x00000040
#define AVR32_SSC_IMR_ENDRX_OFFSET                                  6
#define AVR32_SSC_IMR_ENDRX_SIZE                                    1
#define AVR32_SSC_IMR_ENDTX                                         2
#define AVR32_SSC_IMR_ENDTX_MASK                           0x00000004
#define AVR32_SSC_IMR_ENDTX_OFFSET                                  2
#define AVR32_SSC_IMR_ENDTX_SIZE                                    1
#define AVR32_SSC_IMR_OVRUN                                         5
#define AVR32_SSC_IMR_OVRUN_MASK                           0x00000020
#define AVR32_SSC_IMR_OVRUN_OFFSET                                  5
#define AVR32_SSC_IMR_OVRUN_SIZE                                    1
#define AVR32_SSC_IMR_RXBUFF                                        7
#define AVR32_SSC_IMR_RXBUFF_MASK                          0x00000080
#define AVR32_SSC_IMR_RXBUFF_OFFSET                                 7
#define AVR32_SSC_IMR_RXBUFF_SIZE                                   1
#define AVR32_SSC_IMR_RXRDY                                         4
#define AVR32_SSC_IMR_RXRDY_MASK                           0x00000010
#define AVR32_SSC_IMR_RXRDY_OFFSET                                  4
#define AVR32_SSC_IMR_RXRDY_SIZE                                    1
#define AVR32_SSC_IMR_RXSYN                                        11
#define AVR32_SSC_IMR_RXSYN_MASK                           0x00000800
#define AVR32_SSC_IMR_RXSYN_OFFSET                                 11
#define AVR32_SSC_IMR_RXSYN_SIZE                                    1
#define AVR32_SSC_IMR_TXBUFE                                        3
#define AVR32_SSC_IMR_TXBUFE_MASK                          0x00000008
#define AVR32_SSC_IMR_TXBUFE_OFFSET                                 3
#define AVR32_SSC_IMR_TXBUFE_SIZE                                   1
#define AVR32_SSC_IMR_TXEMPTY                                       1
#define AVR32_SSC_IMR_TXEMPTY_MASK                         0x00000002
#define AVR32_SSC_IMR_TXEMPTY_OFFSET                                1
#define AVR32_SSC_IMR_TXEMPTY_SIZE                                  1
#define AVR32_SSC_IMR_TXRDY                                         0
#define AVR32_SSC_IMR_TXRDY_MASK                           0x00000001
#define AVR32_SSC_IMR_TXRDY_OFFSET                                  0
#define AVR32_SSC_IMR_TXRDY_SIZE                                    1
#define AVR32_SSC_IMR_TXSYN                                        10
#define AVR32_SSC_IMR_TXSYN_MASK                           0x00000400
#define AVR32_SSC_IMR_TXSYN_OFFSET                                 10
#define AVR32_SSC_IMR_TXSYN_SIZE                                    1
#define AVR32_SSC_INPUT_ONLY                               0x00000000
#define AVR32_SSC_LOOP                                              5
#define AVR32_SSC_LOOP_MASK                                0x00000020
#define AVR32_SSC_LOOP_OFFSET                                       5
#define AVR32_SSC_LOOP_SIZE                                         1
#define AVR32_SSC_LOW                                      0x00000001
#define AVR32_SSC_LOW_DURING_DATA                          0x00000003
#define AVR32_SSC_MSBF                                              7
#define AVR32_SSC_MSBF_MASK                                0x00000080
#define AVR32_SSC_MSBF_OFFSET                                       7
#define AVR32_SSC_MSBF_SIZE                                         1
#define AVR32_SSC_NEG_PULSE                                0x00000001
#define AVR32_SSC_NONE                                     0x00000000
#define AVR32_SSC_NOT_ACTIVE                               0x00000000
#define AVR32_SSC_OVRUN                                             5
#define AVR32_SSC_OVRUN_MASK                               0x00000020
#define AVR32_SSC_OVRUN_OFFSET                                      5
#define AVR32_SSC_OVRUN_SIZE                                        1
#define AVR32_SSC_PERIOD                                           24
#define AVR32_SSC_PERIOD_MASK                              0xff000000
#define AVR32_SSC_PERIOD_OFFSET                                    24
#define AVR32_SSC_PERIOD_SIZE                                       8
#define AVR32_SSC_POS_PULSE                                0x00000002
#define AVR32_SSC_RC0R                                     0x00000038
#define AVR32_SSC_RC0R_CP0                                          0
#define AVR32_SSC_RC0R_CP0_MASK                            0x0000ffff
#define AVR32_SSC_RC0R_CP0_OFFSET                                   0
#define AVR32_SSC_RC0R_CP0_SIZE                                    16
#define AVR32_SSC_RC1R                                     0x0000003c
#define AVR32_SSC_RC1R_CP1                                          0
#define AVR32_SSC_RC1R_CP1_MASK                            0x0000ffff
#define AVR32_SSC_RC1R_CP1_OFFSET                                   0
#define AVR32_SSC_RC1R_CP1_SIZE                                    16
#define AVR32_SSC_RCMR                                     0x00000010
#define AVR32_SSC_RCMR_CKG                                          6
#define AVR32_SSC_RCMR_CKG_HIGH                            0x00000002
#define AVR32_SSC_RCMR_CKG_LOW                             0x00000001
#define AVR32_SSC_RCMR_CKG_MASK                            0x000000c0
#define AVR32_SSC_RCMR_CKG_NONE                            0x00000000
#define AVR32_SSC_RCMR_CKG_OFFSET                                   6
#define AVR32_SSC_RCMR_CKG_SIZE                                     2
#define AVR32_SSC_RCMR_CKI                                          5
#define AVR32_SSC_RCMR_CKI_MASK                            0x00000020
#define AVR32_SSC_RCMR_CKI_OFFSET                                   5
#define AVR32_SSC_RCMR_CKI_SIZE                                     1
#define AVR32_SSC_RCMR_CKO                                          2
#define AVR32_SSC_RCMR_CKO_CONTINOUS_CLOCK_OUTPUT          0x00000001
#define AVR32_SSC_RCMR_CKO_INPUT_ONLY                      0x00000000
#define AVR32_SSC_RCMR_CKO_MASK                            0x0000001c
#define AVR32_SSC_RCMR_CKO_OFFSET                                   2
#define AVR32_SSC_RCMR_CKO_SIZE                                     3
#define AVR32_SSC_RCMR_CKS                                          0
#define AVR32_SSC_RCMR_CKS_DIV_CLOCK                       0x00000000
#define AVR32_SSC_RCMR_CKS_MASK                            0x00000003
#define AVR32_SSC_RCMR_CKS_OFFSET                                   0
#define AVR32_SSC_RCMR_CKS_RK_PIN                          0x00000002
#define AVR32_SSC_RCMR_CKS_SIZE                                     2
#define AVR32_SSC_RCMR_CKS_TK_CLOCK                        0x00000001
#define AVR32_SSC_RCMR_PERIOD                                      24
#define AVR32_SSC_RCMR_PERIOD_MASK                         0xff000000
#define AVR32_SSC_RCMR_PERIOD_OFFSET                               24
#define AVR32_SSC_RCMR_PERIOD_SIZE                                  8
#define AVR32_SSC_RCMR_START                                        8
#define AVR32_SSC_RCMR_START_COMPARE_0                     0x00000008
#define AVR32_SSC_RCMR_START_CONTINOUS                     0x00000000
#define AVR32_SSC_RCMR_START_DETECT_ANY_EDGE_RF            0x00000007
#define AVR32_SSC_RCMR_START_DETECT_FALLING_RF             0x00000004
#define AVR32_SSC_RCMR_START_DETECT_HIGH_RF                0x00000003
#define AVR32_SSC_RCMR_START_DETECT_LEVEL_CHANGE_RF        0x00000006
#define AVR32_SSC_RCMR_START_DETECT_LOW_RF                 0x00000002
#define AVR32_SSC_RCMR_START_DETECT_RISING_RF              0x00000005
#define AVR32_SSC_RCMR_START_MASK                          0x00000f00
#define AVR32_SSC_RCMR_START_OFFSET                                 8
#define AVR32_SSC_RCMR_START_SIZE                                   4
#define AVR32_SSC_RCMR_START_TRANSMIT_START                0x00000001
#define AVR32_SSC_RCMR_STOP                                        12
#define AVR32_SSC_RCMR_STOP_MASK                           0x00001000
#define AVR32_SSC_RCMR_STOP_OFFSET                                 12
#define AVR32_SSC_RCMR_STOP_SIZE                                    1
#define AVR32_SSC_RCMR_STTDLY                                      16
#define AVR32_SSC_RCMR_STTDLY_MASK                         0x00ff0000
#define AVR32_SSC_RCMR_STTDLY_OFFSET                               16
#define AVR32_SSC_RCMR_STTDLY_SIZE                                  8
#define AVR32_SSC_RDAT                                              0
#define AVR32_SSC_RDAT_MASK                                0xffffffff
#define AVR32_SSC_RDAT_OFFSET                                       0
#define AVR32_SSC_RDAT_SIZE                                        32
#define AVR32_SSC_RECEIVE_START                            0x00000001
#define AVR32_SSC_RFMR                                     0x00000014
#define AVR32_SSC_RFMR_DATLEN                                       0
#define AVR32_SSC_RFMR_DATLEN_MASK                         0x0000001f
#define AVR32_SSC_RFMR_DATLEN_OFFSET                                0
#define AVR32_SSC_RFMR_DATLEN_SIZE                                  5
#define AVR32_SSC_RFMR_DATNB                                        8
#define AVR32_SSC_RFMR_DATNB_MASK                          0x00000f00
#define AVR32_SSC_RFMR_DATNB_OFFSET                                 8
#define AVR32_SSC_RFMR_DATNB_SIZE                                   4
#define AVR32_SSC_RFMR_FSEDGE                                      24
#define AVR32_SSC_RFMR_FSEDGE_MASK                         0x01000000
#define AVR32_SSC_RFMR_FSEDGE_OFFSET                               24
#define AVR32_SSC_RFMR_FSEDGE_SIZE                                  1
#define AVR32_SSC_RFMR_FSLEN                                       16
#define AVR32_SSC_RFMR_FSLENHI                                     28
#define AVR32_SSC_RFMR_FSLENHI_MASK                        0xf0000000
#define AVR32_SSC_RFMR_FSLENHI_OFFSET                              28
#define AVR32_SSC_RFMR_FSLENHI_SIZE                                 4
#define AVR32_SSC_RFMR_FSLEN_MASK                          0x000f0000
#define AVR32_SSC_RFMR_FSLEN_OFFSET                                16
#define AVR32_SSC_RFMR_FSLEN_SIZE                                   4
#define AVR32_SSC_RFMR_FSOS                                        20
#define AVR32_SSC_RFMR_FSOS_HIGH_DURING_DATA               0x00000004
#define AVR32_SSC_RFMR_FSOS_INPUT_ONLY                     0x00000000
#define AVR32_SSC_RFMR_FSOS_LOW_DURING_DATA                0x00000003
#define AVR32_SSC_RFMR_FSOS_MASK                           0x00700000
#define AVR32_SSC_RFMR_FSOS_NEG_PULSE                      0x00000001
#define AVR32_SSC_RFMR_FSOS_OFFSET                                 20
#define AVR32_SSC_RFMR_FSOS_POS_PULSE                      0x00000002
#define AVR32_SSC_RFMR_FSOS_SIZE                                    3
#define AVR32_SSC_RFMR_FSOS_TOGGLE_DATA_START              0x00000005
#define AVR32_SSC_RFMR_LOOP                                         5
#define AVR32_SSC_RFMR_LOOP_MASK                           0x00000020
#define AVR32_SSC_RFMR_LOOP_OFFSET                                  5
#define AVR32_SSC_RFMR_LOOP_SIZE                                    1
#define AVR32_SSC_RFMR_MSBF                                         7
#define AVR32_SSC_RFMR_MSBF_MASK                           0x00000080
#define AVR32_SSC_RFMR_MSBF_OFFSET                                  7
#define AVR32_SSC_RFMR_MSBF_SIZE                                    1
#define AVR32_SSC_RHR                                      0x00000020
#define AVR32_SSC_RHR_RDAT                                          0
#define AVR32_SSC_RHR_RDAT_MASK                            0xffffffff
#define AVR32_SSC_RHR_RDAT_OFFSET                                   0
#define AVR32_SSC_RHR_RDAT_SIZE                                    32
#define AVR32_SSC_RK_CLOCK                                 0x00000001
#define AVR32_SSC_RK_PIN                                   0x00000002
#define AVR32_SSC_RSDAT                                             0
#define AVR32_SSC_RSDAT_MASK                               0x0000ffff
#define AVR32_SSC_RSDAT_OFFSET                                      0
#define AVR32_SSC_RSDAT_SIZE                                       16
#define AVR32_SSC_RSHR                                     0x00000030
#define AVR32_SSC_RSHR_RSDAT                                        0
#define AVR32_SSC_RSHR_RSDAT_MASK                          0x0000ffff
#define AVR32_SSC_RSHR_RSDAT_OFFSET                                 0
#define AVR32_SSC_RSHR_RSDAT_SIZE                                  16
#define AVR32_SSC_RXBUFF                                            7
#define AVR32_SSC_RXBUFF_MASK                              0x00000080
#define AVR32_SSC_RXBUFF_OFFSET                                     7
#define AVR32_SSC_RXBUFF_SIZE                                       1
#define AVR32_SSC_RXDIS                                             1
#define AVR32_SSC_RXDIS_MASK                               0x00000002
#define AVR32_SSC_RXDIS_OFFSET                                      1
#define AVR32_SSC_RXDIS_SIZE                                        1
#define AVR32_SSC_RXEN_SIZE                                         1
#define AVR32_SSC_RXRDY                                             4
#define AVR32_SSC_RXRDY_MASK                               0x00000010
#define AVR32_SSC_RXRDY_OFFSET                                      4
#define AVR32_SSC_RXRDY_SIZE                                        1
#define AVR32_SSC_RXSYN                                            11
#define AVR32_SSC_RXSYN_MASK                               0x00000800
#define AVR32_SSC_RXSYN_OFFSET                                     11
#define AVR32_SSC_RXSYN_SIZE                                        1
#define AVR32_SSC_SR                                       0x00000040
#define AVR32_SSC_SR_CP0                                            8
#define AVR32_SSC_SR_CP0_MASK                              0x00000100
#define AVR32_SSC_SR_CP0_OFFSET                                     8
#define AVR32_SSC_SR_CP0_SIZE                                       1
#define AVR32_SSC_SR_CP1                                            9
#define AVR32_SSC_SR_CP1_MASK                              0x00000200
#define AVR32_SSC_SR_CP1_OFFSET                                     9
#define AVR32_SSC_SR_CP1_SIZE                                       1
#define AVR32_SSC_SR_ENDRX                                          6
#define AVR32_SSC_SR_ENDRX_MASK                            0x00000040
#define AVR32_SSC_SR_ENDRX_OFFSET                                   6
#define AVR32_SSC_SR_ENDRX_SIZE                                     1
#define AVR32_SSC_SR_ENDTX                                          2
#define AVR32_SSC_SR_ENDTX_MASK                            0x00000004
#define AVR32_SSC_SR_ENDTX_OFFSET                                   2
#define AVR32_SSC_SR_ENDTX_SIZE                                     1
#define AVR32_SSC_SR_OVRUN                                          5
#define AVR32_SSC_SR_OVRUN_MASK                            0x00000020
#define AVR32_SSC_SR_OVRUN_OFFSET                                   5
#define AVR32_SSC_SR_OVRUN_SIZE                                     1
#define AVR32_SSC_SR_RXBUFF                                         7
#define AVR32_SSC_SR_RXBUFF_MASK                           0x00000080
#define AVR32_SSC_SR_RXBUFF_OFFSET                                  7
#define AVR32_SSC_SR_RXBUFF_SIZE                                    1
#define AVR32_SSC_SR_RXEN                                          17
#define AVR32_SSC_SR_RXEN_MASK                             0x00020000
#define AVR32_SSC_SR_RXEN_OFFSET                                   17
#define AVR32_SSC_SR_RXEN_SIZE                                      1
#define AVR32_SSC_SR_RXRDY                                          4
#define AVR32_SSC_SR_RXRDY_MASK                            0x00000010
#define AVR32_SSC_SR_RXRDY_OFFSET                                   4
#define AVR32_SSC_SR_RXRDY_SIZE                                     1
#define AVR32_SSC_SR_RXSYN                                         11
#define AVR32_SSC_SR_RXSYN_MASK                            0x00000800
#define AVR32_SSC_SR_RXSYN_OFFSET                                  11
#define AVR32_SSC_SR_RXSYN_SIZE                                     1
#define AVR32_SSC_SR_TXBUFE                                         3
#define AVR32_SSC_SR_TXBUFE_MASK                           0x00000008
#define AVR32_SSC_SR_TXBUFE_OFFSET                                  3
#define AVR32_SSC_SR_TXBUFE_SIZE                                    1
#define AVR32_SSC_SR_TXEMPTY                                        1
#define AVR32_SSC_SR_TXEMPTY_MASK                          0x00000002
#define AVR32_SSC_SR_TXEMPTY_OFFSET                                 1
#define AVR32_SSC_SR_TXEMPTY_SIZE                                   1
#define AVR32_SSC_SR_TXEN                                          16
#define AVR32_SSC_SR_TXEN_MASK                             0x00010000
#define AVR32_SSC_SR_TXEN_OFFSET                                   16
#define AVR32_SSC_SR_TXEN_SIZE                                      1
#define AVR32_SSC_SR_TXRDY                                          0
#define AVR32_SSC_SR_TXRDY_MASK                            0x00000001
#define AVR32_SSC_SR_TXRDY_OFFSET                                   0
#define AVR32_SSC_SR_TXRDY_SIZE                                     1
#define AVR32_SSC_SR_TXSYN                                         10
#define AVR32_SSC_SR_TXSYN_MASK                            0x00000400
#define AVR32_SSC_SR_TXSYN_OFFSET                                  10
#define AVR32_SSC_SR_TXSYN_SIZE                                     1
#define AVR32_SSC_START                                             8
#define AVR32_SSC_START_COMPARE_0                          0x00000008
#define AVR32_SSC_START_CONTINOUS                          0x00000000
#define AVR32_SSC_START_DETECT_ANY_EDGE_RF                 0x00000007
#define AVR32_SSC_START_DETECT_ANY_EDGE_TF                 0x00000007
#define AVR32_SSC_START_DETECT_FALLING_RF                  0x00000004
#define AVR32_SSC_START_DETECT_FALLING_TF                  0x00000004
#define AVR32_SSC_START_DETECT_HIGH_RF                     0x00000003
#define AVR32_SSC_START_DETECT_HIGH_TF                     0x00000003
#define AVR32_SSC_START_DETECT_LEVEL_CHANGE_RF             0x00000006
#define AVR32_SSC_START_DETECT_LEVEL_CHANGE_TF             0x00000006
#define AVR32_SSC_START_DETECT_LOW_RF                      0x00000002
#define AVR32_SSC_START_DETECT_LOW_TF                      0x00000002
#define AVR32_SSC_START_DETECT_RISING_RF                   0x00000005
#define AVR32_SSC_START_DETECT_RISING_TF                   0x00000005
#define AVR32_SSC_START_MASK                               0x00000f00
#define AVR32_SSC_START_OFFSET                                      8
#define AVR32_SSC_START_RECEIVE_START                      0x00000001
#define AVR32_SSC_START_SIZE                                        4
#define AVR32_SSC_START_TRANSMIT_START                     0x00000001
#define AVR32_SSC_STOP                                             12
#define AVR32_SSC_STOP_MASK                                0x00001000
#define AVR32_SSC_STOP_OFFSET                                      12
#define AVR32_SSC_STOP_SIZE                                         1
#define AVR32_SSC_STTDLY                                           16
#define AVR32_SSC_STTDLY_MASK                              0x00ff0000
#define AVR32_SSC_STTDLY_OFFSET                                    16
#define AVR32_SSC_STTDLY_SIZE                                       8
#define AVR32_SSC_SWRST                                            15
#define AVR32_SSC_SWRST_MASK                               0x00008000
#define AVR32_SSC_SWRST_OFFSET                                     15
#define AVR32_SSC_SWRST_SIZE                                        1
#define AVR32_SSC_TCMR                                     0x00000018
#define AVR32_SSC_TCMR_CKG                                          6
#define AVR32_SSC_TCMR_CKG_HIGH                            0x00000002
#define AVR32_SSC_TCMR_CKG_LOW                             0x00000001
#define AVR32_SSC_TCMR_CKG_MASK                            0x000000c0
#define AVR32_SSC_TCMR_CKG_NONE                            0x00000000
#define AVR32_SSC_TCMR_CKG_OFFSET                                   6
#define AVR32_SSC_TCMR_CKG_SIZE                                     2
#define AVR32_SSC_TCMR_CKI                                          5
#define AVR32_SSC_TCMR_CKI_MASK                            0x00000020
#define AVR32_SSC_TCMR_CKI_OFFSET                                   5
#define AVR32_SSC_TCMR_CKI_SIZE                                     1
#define AVR32_SSC_TCMR_CKO                                          2
#define AVR32_SSC_TCMR_CKO_CONTINOUS_CLOCK_OUTPUT          0x00000001
#define AVR32_SSC_TCMR_CKO_INPUT_ONLY                      0x00000000
#define AVR32_SSC_TCMR_CKO_MASK                            0x0000001c
#define AVR32_SSC_TCMR_CKO_OFFSET                                   2
#define AVR32_SSC_TCMR_CKO_SIZE                                     3
#define AVR32_SSC_TCMR_CKS                                          0
#define AVR32_SSC_TCMR_CKS_DIV_CLOCK                       0x00000000
#define AVR32_SSC_TCMR_CKS_MASK                            0x00000003
#define AVR32_SSC_TCMR_CKS_OFFSET                                   0
#define AVR32_SSC_TCMR_CKS_RK_CLOCK                        0x00000001
#define AVR32_SSC_TCMR_CKS_SIZE                                     2
#define AVR32_SSC_TCMR_CKS_TK_PIN                          0x00000002
#define AVR32_SSC_TCMR_PERIOD                                      24
#define AVR32_SSC_TCMR_PERIOD_MASK                         0xff000000
#define AVR32_SSC_TCMR_PERIOD_OFFSET                               24
#define AVR32_SSC_TCMR_PERIOD_SIZE                                  8
#define AVR32_SSC_TCMR_START                                        8
#define AVR32_SSC_TCMR_START_CONTINOUS                     0x00000000
#define AVR32_SSC_TCMR_START_DETECT_ANY_EDGE_TF            0x00000007
#define AVR32_SSC_TCMR_START_DETECT_FALLING_TF             0x00000004
#define AVR32_SSC_TCMR_START_DETECT_HIGH_TF                0x00000003
#define AVR32_SSC_TCMR_START_DETECT_LEVEL_CHANGE_TF        0x00000006
#define AVR32_SSC_TCMR_START_DETECT_LOW_TF                 0x00000002
#define AVR32_SSC_TCMR_START_DETECT_RISING_TF              0x00000005
#define AVR32_SSC_TCMR_START_MASK                          0x00000f00
#define AVR32_SSC_TCMR_START_OFFSET                                 8
#define AVR32_SSC_TCMR_START_RECEIVE_START                 0x00000001
#define AVR32_SSC_TCMR_START_SIZE                                   4
#define AVR32_SSC_TCMR_STTDLY                                      16
#define AVR32_SSC_TCMR_STTDLY_MASK                         0x00ff0000
#define AVR32_SSC_TCMR_STTDLY_OFFSET                               16
#define AVR32_SSC_TCMR_STTDLY_SIZE                                  8
#define AVR32_SSC_TDAT                                              0
#define AVR32_SSC_TDAT_MASK                                0xffffffff
#define AVR32_SSC_TDAT_OFFSET                                       0
#define AVR32_SSC_TDAT_SIZE                                        32
#define AVR32_SSC_TFMR                                     0x0000001c
#define AVR32_SSC_TFMR_DATDEF                                       5
#define AVR32_SSC_TFMR_DATDEF_MASK                         0x00000020
#define AVR32_SSC_TFMR_DATDEF_OFFSET                                5
#define AVR32_SSC_TFMR_DATDEF_SIZE                                  1
#define AVR32_SSC_TFMR_DATLEN                                       0
#define AVR32_SSC_TFMR_DATLEN_MASK                         0x0000001f
#define AVR32_SSC_TFMR_DATLEN_OFFSET                                0
#define AVR32_SSC_TFMR_DATLEN_SIZE                                  5
#define AVR32_SSC_TFMR_DATNB                                        8
#define AVR32_SSC_TFMR_DATNB_MASK                          0x00000f00
#define AVR32_SSC_TFMR_DATNB_OFFSET                                 8
#define AVR32_SSC_TFMR_DATNB_SIZE                                   4
#define AVR32_SSC_TFMR_FSDEN                                       23
#define AVR32_SSC_TFMR_FSDEN_MASK                          0x00800000
#define AVR32_SSC_TFMR_FSDEN_OFFSET                                23
#define AVR32_SSC_TFMR_FSDEN_SIZE                                   1
#define AVR32_SSC_TFMR_FSEDGE                                      24
#define AVR32_SSC_TFMR_FSEDGE_MASK                         0x01000000
#define AVR32_SSC_TFMR_FSEDGE_OFFSET                               24
#define AVR32_SSC_TFMR_FSEDGE_SIZE                                  1
#define AVR32_SSC_TFMR_FSLEN                                       16
#define AVR32_SSC_TFMR_FSLENHI                                     28
#define AVR32_SSC_TFMR_FSLENHI_MASK                        0xf0000000
#define AVR32_SSC_TFMR_FSLENHI_OFFSET                              28
#define AVR32_SSC_TFMR_FSLENHI_SIZE                                 4
#define AVR32_SSC_TFMR_FSLEN_MASK                          0x000f0000
#define AVR32_SSC_TFMR_FSLEN_OFFSET                                16
#define AVR32_SSC_TFMR_FSLEN_SIZE                                   4
#define AVR32_SSC_TFMR_FSOS                                        20
#define AVR32_SSC_TFMR_FSOS_HIGH_DURING_DATA               0x00000004
#define AVR32_SSC_TFMR_FSOS_INPUT_ONLY                     0x00000000
#define AVR32_SSC_TFMR_FSOS_LOW_DURING_DATA                0x00000003
#define AVR32_SSC_TFMR_FSOS_MASK                           0x00700000
#define AVR32_SSC_TFMR_FSOS_NEG_PULSE                      0x00000001
#define AVR32_SSC_TFMR_FSOS_OFFSET                                 20
#define AVR32_SSC_TFMR_FSOS_POS_PULSE                      0x00000002
#define AVR32_SSC_TFMR_FSOS_SIZE                                    3
#define AVR32_SSC_TFMR_FSOS_TOGGLE_DATA_START              0x00000005
#define AVR32_SSC_TFMR_MSBF                                         7
#define AVR32_SSC_TFMR_MSBF_MASK                           0x00000080
#define AVR32_SSC_TFMR_MSBF_OFFSET                                  7
#define AVR32_SSC_TFMR_MSBF_SIZE                                    1
#define AVR32_SSC_THR                                      0x00000024
#define AVR32_SSC_THR_TDAT                                          0
#define AVR32_SSC_THR_TDAT_MASK                            0xffffffff
#define AVR32_SSC_THR_TDAT_OFFSET                                   0
#define AVR32_SSC_THR_TDAT_SIZE                                    32
#define AVR32_SSC_TK_CLOCK                                 0x00000001
#define AVR32_SSC_TK_PIN                                   0x00000002
#define AVR32_SSC_TOGGLE_DATA_START                        0x00000005
#define AVR32_SSC_TRANSMIT_START                           0x00000001
#define AVR32_SSC_TSDAT                                             0
#define AVR32_SSC_TSDAT_MASK                               0x0000ffff
#define AVR32_SSC_TSDAT_OFFSET                                      0
#define AVR32_SSC_TSDAT_SIZE                                       16
#define AVR32_SSC_TSHR                                     0x00000034
#define AVR32_SSC_TSHR_TSDAT                                        0
#define AVR32_SSC_TSHR_TSDAT_MASK                          0x0000ffff
#define AVR32_SSC_TSHR_TSDAT_OFFSET                                 0
#define AVR32_SSC_TSHR_TSDAT_SIZE                                  16
#define AVR32_SSC_TXBUFE                                            3
#define AVR32_SSC_TXBUFE_MASK                              0x00000008
#define AVR32_SSC_TXBUFE_OFFSET                                     3
#define AVR32_SSC_TXBUFE_SIZE                                       1
#define AVR32_SSC_TXDIS                                             9
#define AVR32_SSC_TXDIS_MASK                               0x00000200
#define AVR32_SSC_TXDIS_OFFSET                                      9
#define AVR32_SSC_TXDIS_SIZE                                        1
#define AVR32_SSC_TXEMPTY                                           1
#define AVR32_SSC_TXEMPTY_MASK                             0x00000002
#define AVR32_SSC_TXEMPTY_OFFSET                                    1
#define AVR32_SSC_TXEMPTY_SIZE                                      1
#define AVR32_SSC_TXEN_SIZE                                         1
#define AVR32_SSC_TXRDY                                             0
#define AVR32_SSC_TXRDY_MASK                               0x00000001
#define AVR32_SSC_TXRDY_OFFSET                                      0
#define AVR32_SSC_TXRDY_SIZE                                        1
#define AVR32_SSC_TXSYN                                            10
#define AVR32_SSC_TXSYN_MASK                               0x00000400
#define AVR32_SSC_TXSYN_OFFSET                                     10
#define AVR32_SSC_TXSYN_SIZE                                        1
#define AVR32_SSC_VARIANT                                          16
#define AVR32_SSC_VARIANT_MASK                             0x00070000
#define AVR32_SSC_VARIANT_OFFSET                                   16
#define AVR32_SSC_VARIANT_SIZE                                      3
#define AVR32_SSC_VERSION                                  0x000000fc
#define AVR32_SSC_VERSION_MASK                             0x00000fff
#define AVR32_SSC_VERSION_OFFSET                                    0
#define AVR32_SSC_VERSION_SIZE                                     12
#define AVR32_SSC_VERSION_VARIANT                                  16
#define AVR32_SSC_VERSION_VARIANT_MASK                     0x00070000
#define AVR32_SSC_VERSION_VARIANT_OFFSET                           16
#define AVR32_SSC_VERSION_VARIANT_SIZE                              3
#define AVR32_SSC_VERSION_VERSION                                   0
#define AVR32_SSC_VERSION_VERSION_MASK                     0x00000fff
#define AVR32_SSC_VERSION_VERSION_OFFSET                            0
#define AVR32_SSC_VERSION_VERSION_SIZE                             12




#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_ssc_cr_t {
    unsigned int                 :16;
    unsigned int swrst           : 1;
    unsigned int                 : 5;
    unsigned int txdis           : 1;
    unsigned int txen            : 1;
    unsigned int                 : 6;
    unsigned int rxdis           : 1;
    unsigned int rxen            : 1;
} avr32_ssc_cr_t;



typedef struct avr32_ssc_cmr_t {
    unsigned int                 :20;
    unsigned int div             :12;
} avr32_ssc_cmr_t;



typedef struct avr32_ssc_rcmr_t {
    unsigned int period          : 8;
    unsigned int sttdly          : 8;
    unsigned int                 : 3;
    unsigned int stop            : 1;
    unsigned int start           : 4;
    unsigned int ckg             : 2;
    unsigned int cki             : 1;
    unsigned int cko             : 3;
    unsigned int cks             : 2;
} avr32_ssc_rcmr_t;



typedef struct avr32_ssc_rfmr_t {
    unsigned int fslenhi         : 4;
    unsigned int                 : 3;
    unsigned int fsedge          : 1;
    unsigned int                 : 1;
    unsigned int fsos            : 3;
    unsigned int fslen           : 4;
    unsigned int                 : 4;
    unsigned int datnb           : 4;
    unsigned int msbf            : 1;
    unsigned int                 : 1;
    unsigned int loop            : 1;
    unsigned int datlen          : 5;
} avr32_ssc_rfmr_t;



typedef struct avr32_ssc_tcmr_t {
    unsigned int period          : 8;
    unsigned int sttdly          : 8;
    unsigned int                 : 4;
    unsigned int start           : 4;
    unsigned int ckg             : 2;
    unsigned int cki             : 1;
    unsigned int cko             : 3;
    unsigned int cks             : 2;
} avr32_ssc_tcmr_t;



typedef struct avr32_ssc_tfmr_t {
    unsigned int fslenhi         : 4;
    unsigned int                 : 3;
    unsigned int fsedge          : 1;
    unsigned int fsden           : 1;
    unsigned int fsos            : 3;
    unsigned int fslen           : 4;
    unsigned int                 : 4;
    unsigned int datnb           : 4;
    unsigned int msbf            : 1;
    unsigned int                 : 1;
    unsigned int datdef          : 1;
    unsigned int datlen          : 5;
} avr32_ssc_tfmr_t;



typedef struct avr32_ssc_rshr_t {
    unsigned int                 :16;
    unsigned int rsdat           :16;
} avr32_ssc_rshr_t;



typedef struct avr32_ssc_tshr_t {
    unsigned int                 :16;
    unsigned int tsdat           :16;
} avr32_ssc_tshr_t;



typedef struct avr32_ssc_rc0r_t {
    unsigned int                 :16;
    unsigned int cp0             :16;
} avr32_ssc_rc0r_t;



typedef struct avr32_ssc_rc1r_t {
    unsigned int                 :16;
    unsigned int cp1             :16;
} avr32_ssc_rc1r_t;



typedef struct avr32_ssc_sr_t {
    unsigned int                 :14;
    unsigned int rxen            : 1;
    unsigned int txen            : 1;
    unsigned int                 : 4;
    unsigned int rxsyn           : 1;
    unsigned int txsyn           : 1;
    unsigned int cp1             : 1;
    unsigned int cp0             : 1;
    unsigned int rxbuff          : 1;
    unsigned int endrx           : 1;
    unsigned int ovrun           : 1;
    unsigned int rxrdy           : 1;
    unsigned int txbufe          : 1;
    unsigned int endtx           : 1;
    unsigned int txempty         : 1;
    unsigned int txrdy           : 1;
} avr32_ssc_sr_t;



typedef struct avr32_ssc_ier_t {
    unsigned int                 :20;
    unsigned int rxsyn           : 1;
    unsigned int txsyn           : 1;
    unsigned int cp1             : 1;
    unsigned int cp0             : 1;
    unsigned int rxbuff          : 1;
    unsigned int endrx           : 1;
    unsigned int ovrun           : 1;
    unsigned int rxrdy           : 1;
    unsigned int txbufe          : 1;
    unsigned int endtx           : 1;
    unsigned int txempty         : 1;
    unsigned int txrdy           : 1;
} avr32_ssc_ier_t;



typedef struct avr32_ssc_idr_t {
    unsigned int                 :20;
    unsigned int rxsyn           : 1;
    unsigned int txsyn           : 1;
    unsigned int cp1             : 1;
    unsigned int cp0             : 1;
    unsigned int rxbuff          : 1;
    unsigned int endrx           : 1;
    unsigned int ovrun           : 1;
    unsigned int rxrdy           : 1;
    unsigned int txbufe          : 1;
    unsigned int endtx           : 1;
    unsigned int txempty         : 1;
    unsigned int txrdy           : 1;
} avr32_ssc_idr_t;



typedef struct avr32_ssc_imr_t {
    unsigned int                 :20;
    unsigned int rxsyn           : 1;
    unsigned int txsyn           : 1;
    unsigned int cp1             : 1;
    unsigned int cp0             : 1;
    unsigned int rxbuff          : 1;
    unsigned int endrx           : 1;
    unsigned int ovrun           : 1;
    unsigned int rxrdy           : 1;
    unsigned int txbufe          : 1;
    unsigned int endtx           : 1;
    unsigned int txempty         : 1;
    unsigned int txrdy           : 1;
} avr32_ssc_imr_t;



typedef struct avr32_ssc_version_t {
    unsigned int                 :13;
    unsigned int variant         : 3;
    unsigned int                 : 4;
    unsigned int version         :12;
} avr32_ssc_version_t;



typedef struct avr32_ssc_t {
  union {
          unsigned long                  cr        ;//0x0000
          avr32_ssc_cr_t                 CR        ;
  };
  union {
          unsigned long                  cmr       ;//0x0004
          avr32_ssc_cmr_t                CMR       ;
  };
          unsigned int                   :32       ;//0x0008
          unsigned int                   :32       ;//0x000c
  union {
          unsigned long                  rcmr      ;//0x0010
          avr32_ssc_rcmr_t               RCMR      ;
  };
  union {
          unsigned long                  rfmr      ;//0x0014
          avr32_ssc_rfmr_t               RFMR      ;
  };
  union {
          unsigned long                  tcmr      ;//0x0018
          avr32_ssc_tcmr_t               TCMR      ;
  };
  union {
          unsigned long                  tfmr      ;//0x001c
          avr32_ssc_tfmr_t               TFMR      ;
  };
    const unsigned long                  rhr       ;//0x0020
          unsigned long                  thr       ;//0x0024
          unsigned int                   :32       ;//0x0028
          unsigned int                   :32       ;//0x002c
  union {
    const unsigned long                  rshr      ;//0x0030
    const avr32_ssc_rshr_t               RSHR      ;
  };
  union {
          unsigned long                  tshr      ;//0x0034
          avr32_ssc_tshr_t               TSHR      ;
  };
  union {
          unsigned long                  rc0r      ;//0x0038
          avr32_ssc_rc0r_t               RC0R      ;
  };
  union {
          unsigned long                  rc1r      ;//0x003c
          avr32_ssc_rc1r_t               RC1R      ;
  };
  union {
    const unsigned long                  sr        ;//0x0040
    const avr32_ssc_sr_t                 SR        ;
  };
  union {
          unsigned long                  ier       ;//0x0044
          avr32_ssc_ier_t                IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0048
          avr32_ssc_idr_t                IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x004c
    const avr32_ssc_imr_t                IMR       ;
  };
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
    const avr32_ssc_version_t            VERSION   ;
  };
} avr32_ssc_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif


#if !defined (DEPRECATED_DISABLE)

#define AVR32_SSC_DETECT_ANY_EGDE_RF                       0x00000007

#define AVR32_SSC_RCMR_START_DETECT_ANY_EGDE_RF            0x00000007

#define AVR32_SSC_START_DETECT_ANY_EGDE_RF                 0x00000007

#define AVR32_SSC_TCMR_START_DETECT_ANY_EGDE_RF            0x00000007
#define AVR32_SSC_TCMR_START_DETECT_FALLING_RF             0x00000004
#define AVR32_SSC_TCMR_START_DETECT_HIGH_RF                0x00000003
#define AVR32_SSC_TCMR_START_DETECT_LEVEL_CHANGE_RF        0x00000006
#define AVR32_SSC_TCMR_START_DETECT_LOW_RF                 0x00000002
#define AVR32_SSC_TCMR_START_DETECT_RISING_RF              0x00000005

#endif


/*#ifdef AVR32_SSC_310_H_INCLUDED*/
#endif

