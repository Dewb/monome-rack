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
#ifndef AVR32_USART_400_H_INCLUDED
#define AVR32_USART_400_H_INCLUDED

#define AVR32_USART_H_VERSION 400

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_USART_<register>
 - Bitfield mask:   AVR32_USART_<register>_<bitfield>
 - Bitfield offset: AVR32_USART_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_USART_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_USART_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_USART_<bitfield>
 - Bitfield offset: AVR32_USART_<bitfield>_OFFSET
 - Bitfield size:   AVR32_USART_<bitfield>_SIZE
 - Bitfield values: AVR32_USART_<bitfield>_<value name>
 - Bitfield values: AVR32_USART_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_USART_1                                        0x00000000
#define AVR32_USART_1_5                                      0x00000001
#define AVR32_USART_2                                        0x00000002
#define AVR32_USART_5                                        0x00000000
#define AVR32_USART_6                                        0x00000001
#define AVR32_USART_7                                        0x00000002
#define AVR32_USART_8                                        0x00000003
#define AVR32_USART_BRGR                                     0x00000020
#define AVR32_USART_BRGR_CD                                           0
#define AVR32_USART_BRGR_CD_BYPASS                           0x00000001
#define AVR32_USART_BRGR_CD_DISABLE                          0x00000000
#define AVR32_USART_BRGR_CD_MASK                             0x0000ffff
#define AVR32_USART_BRGR_CD_OFFSET                                    0
#define AVR32_USART_BRGR_CD_SIZE                                     16
#define AVR32_USART_BRGR_FP                                          16
#define AVR32_USART_BRGR_FP_MASK                             0x00070000
#define AVR32_USART_BRGR_FP_OFFSET                                   16
#define AVR32_USART_BRGR_FP_SIZE                                      3
#define AVR32_USART_BYPASS                                   0x00000001
#define AVR32_USART_CD                                                0
#define AVR32_USART_CD_BYPASS                                0x00000001
#define AVR32_USART_CD_DISABLE                               0x00000000
#define AVR32_USART_CD_MASK                                  0x0000ffff
#define AVR32_USART_CD_OFFSET                                         0
#define AVR32_USART_CD_SIZE                                          16
#define AVR32_USART_CHKDIS                                            3
#define AVR32_USART_CHKDIS_MASK                              0x00000008
#define AVR32_USART_CHKDIS_OFFSET                                     3
#define AVR32_USART_CHKDIS_SIZE                                       1
#define AVR32_USART_CHKTYP                                            4
#define AVR32_USART_CHKTYP_MASK                              0x00000010
#define AVR32_USART_CHKTYP_OFFSET                                     4
#define AVR32_USART_CHKTYP_SIZE                                       1
#define AVR32_USART_CHMODE                                           14
#define AVR32_USART_CHMODE_ECHO                              0x00000001
#define AVR32_USART_CHMODE_LOCAL_LOOP                        0x00000002
#define AVR32_USART_CHMODE_MASK                              0x0000c000
#define AVR32_USART_CHMODE_NORMAL                            0x00000000
#define AVR32_USART_CHMODE_OFFSET                                    14
#define AVR32_USART_CHMODE_REMOTE_LOOP                       0x00000003
#define AVR32_USART_CHMODE_SIZE                                       2
#define AVR32_USART_CHRL                                              6
#define AVR32_USART_CHRL_5                                   0x00000000
#define AVR32_USART_CHRL_6                                   0x00000001
#define AVR32_USART_CHRL_7                                   0x00000002
#define AVR32_USART_CHRL_8                                   0x00000003
#define AVR32_USART_CHRL_MASK                                0x000000c0
#define AVR32_USART_CHRL_OFFSET                                       6
#define AVR32_USART_CHRL_SIZE                                         2
#define AVR32_USART_CLKO                                             18
#define AVR32_USART_CLKO_MASK                                0x00040000
#define AVR32_USART_CLKO_OFFSET                                      18
#define AVR32_USART_CLKO_SIZE                                         1
#define AVR32_USART_COMM_RX                                          31
#define AVR32_USART_COMM_RX_MASK                             0x80000000
#define AVR32_USART_COMM_RX_OFFSET                                   31
#define AVR32_USART_COMM_RX_SIZE                                      1
#define AVR32_USART_COMM_TX                                          30
#define AVR32_USART_COMM_TX_MASK                             0x40000000
#define AVR32_USART_COMM_TX_OFFSET                                   30
#define AVR32_USART_COMM_TX_SIZE                                      1
#define AVR32_USART_CR                                       0x00000000
#define AVR32_USART_CR_COMM_RX                                       31
#define AVR32_USART_CR_COMM_RX_MASK                          0x80000000
#define AVR32_USART_CR_COMM_RX_OFFSET                                31
#define AVR32_USART_CR_COMM_RX_SIZE                                   1
#define AVR32_USART_CR_COMM_TX                                       30
#define AVR32_USART_CR_COMM_TX_MASK                          0x40000000
#define AVR32_USART_CR_COMM_TX_OFFSET                                30
#define AVR32_USART_CR_COMM_TX_SIZE                                   1
#define AVR32_USART_CR_DTRDIS                                        17
#define AVR32_USART_CR_DTRDIS_MASK                           0x00020000
#define AVR32_USART_CR_DTRDIS_OFFSET                                 17
#define AVR32_USART_CR_DTRDIS_SIZE                                    1
#define AVR32_USART_CR_DTREN                                         16
#define AVR32_USART_CR_DTREN_MASK                            0x00010000
#define AVR32_USART_CR_DTREN_OFFSET                                  16
#define AVR32_USART_CR_DTREN_SIZE                                     1
#define AVR32_USART_CR_LINABT                                        20
#define AVR32_USART_CR_LINABT_MASK                           0x00100000
#define AVR32_USART_CR_LINABT_OFFSET                                 20
#define AVR32_USART_CR_LINABT_SIZE                                    1
#define AVR32_USART_CR_LINWKUP                                       21
#define AVR32_USART_CR_LINWKUP_MASK                          0x00200000
#define AVR32_USART_CR_LINWKUP_OFFSET                                21
#define AVR32_USART_CR_LINWKUP_SIZE                                   1
#define AVR32_USART_CR_RETTO                                         15
#define AVR32_USART_CR_RETTO_MASK                            0x00008000
#define AVR32_USART_CR_RETTO_OFFSET                                  15
#define AVR32_USART_CR_RETTO_SIZE                                     1
#define AVR32_USART_CR_RSTIT                                         13
#define AVR32_USART_CR_RSTIT_MASK                            0x00002000
#define AVR32_USART_CR_RSTIT_OFFSET                                  13
#define AVR32_USART_CR_RSTIT_SIZE                                     1
#define AVR32_USART_CR_RSTNACK                                       14
#define AVR32_USART_CR_RSTNACK_MASK                          0x00004000
#define AVR32_USART_CR_RSTNACK_OFFSET                                14
#define AVR32_USART_CR_RSTNACK_SIZE                                   1
#define AVR32_USART_CR_RSTRX                                          2
#define AVR32_USART_CR_RSTRX_MASK                            0x00000004
#define AVR32_USART_CR_RSTRX_OFFSET                                   2
#define AVR32_USART_CR_RSTRX_SIZE                                     1
#define AVR32_USART_CR_RSTSTA                                         8
#define AVR32_USART_CR_RSTSTA_MASK                           0x00000100
#define AVR32_USART_CR_RSTSTA_OFFSET                                  8
#define AVR32_USART_CR_RSTSTA_SIZE                                    1
#define AVR32_USART_CR_RSTTX                                          3
#define AVR32_USART_CR_RSTTX_MASK                            0x00000008
#define AVR32_USART_CR_RSTTX_OFFSET                                   3
#define AVR32_USART_CR_RSTTX_SIZE                                     1
#define AVR32_USART_CR_RTSDIS                                        19
#define AVR32_USART_CR_RTSDIS_MASK                           0x00080000
#define AVR32_USART_CR_RTSDIS_OFFSET                                 19
#define AVR32_USART_CR_RTSDIS_SIZE                                    1
#define AVR32_USART_CR_RTSEN                                         18
#define AVR32_USART_CR_RTSEN_MASK                            0x00040000
#define AVR32_USART_CR_RTSEN_OFFSET                                  18
#define AVR32_USART_CR_RTSEN_SIZE                                     1
#define AVR32_USART_CR_RXDIS                                          5
#define AVR32_USART_CR_RXDIS_MASK                            0x00000020
#define AVR32_USART_CR_RXDIS_OFFSET                                   5
#define AVR32_USART_CR_RXDIS_SIZE                                     1
#define AVR32_USART_CR_RXEN                                           4
#define AVR32_USART_CR_RXEN_MASK                             0x00000010
#define AVR32_USART_CR_RXEN_OFFSET                                    4
#define AVR32_USART_CR_RXEN_SIZE                                      1
#define AVR32_USART_CR_SENDA                                         12
#define AVR32_USART_CR_SENDA_MASK                            0x00001000
#define AVR32_USART_CR_SENDA_OFFSET                                  12
#define AVR32_USART_CR_SENDA_SIZE                                     1
#define AVR32_USART_CR_STPBRK                                        10
#define AVR32_USART_CR_STPBRK_MASK                           0x00000400
#define AVR32_USART_CR_STPBRK_OFFSET                                 10
#define AVR32_USART_CR_STPBRK_SIZE                                    1
#define AVR32_USART_CR_STTBRK                                         9
#define AVR32_USART_CR_STTBRK_MASK                           0x00000200
#define AVR32_USART_CR_STTBRK_OFFSET                                  9
#define AVR32_USART_CR_STTBRK_SIZE                                    1
#define AVR32_USART_CR_STTTO                                         11
#define AVR32_USART_CR_STTTO_MASK                            0x00000800
#define AVR32_USART_CR_STTTO_OFFSET                                  11
#define AVR32_USART_CR_STTTO_SIZE                                     1
#define AVR32_USART_CR_TXDIS                                          7
#define AVR32_USART_CR_TXDIS_MASK                            0x00000080
#define AVR32_USART_CR_TXDIS_OFFSET                                   7
#define AVR32_USART_CR_TXDIS_SIZE                                     1
#define AVR32_USART_CR_TXEN                                           6
#define AVR32_USART_CR_TXEN_MASK                             0x00000040
#define AVR32_USART_CR_TXEN_OFFSET                                    6
#define AVR32_USART_CR_TXEN_SIZE                                      1
#define AVR32_USART_CSR                                      0x00000014
#define AVR32_USART_CSR_COMM_RX                                      31
#define AVR32_USART_CSR_COMM_RX_MASK                         0x80000000
#define AVR32_USART_CSR_COMM_RX_OFFSET                               31
#define AVR32_USART_CSR_COMM_RX_SIZE                                  1
#define AVR32_USART_CSR_COMM_TX                                      30
#define AVR32_USART_CSR_COMM_TX_MASK                         0x40000000
#define AVR32_USART_CSR_COMM_TX_OFFSET                               30
#define AVR32_USART_CSR_COMM_TX_SIZE                                  1
#define AVR32_USART_CSR_CTS                                          23
#define AVR32_USART_CSR_CTSIC                                        19
#define AVR32_USART_CSR_CTSIC_MASK                           0x00080000
#define AVR32_USART_CSR_CTSIC_OFFSET                                 19
#define AVR32_USART_CSR_CTSIC_SIZE                                    1
#define AVR32_USART_CSR_CTS_MASK                             0x00800000
#define AVR32_USART_CSR_CTS_OFFSET                                   23
#define AVR32_USART_CSR_CTS_SIZE                                      1
#define AVR32_USART_CSR_DCD                                          22
#define AVR32_USART_CSR_DCDIC                                        18
#define AVR32_USART_CSR_DCDIC_MASK                           0x00040000
#define AVR32_USART_CSR_DCDIC_OFFSET                                 18
#define AVR32_USART_CSR_DCDIC_SIZE                                    1
#define AVR32_USART_CSR_DCD_MASK                             0x00400000
#define AVR32_USART_CSR_DCD_OFFSET                                   22
#define AVR32_USART_CSR_DCD_SIZE                                      1
#define AVR32_USART_CSR_DSR                                          21
#define AVR32_USART_CSR_DSRIC                                        17
#define AVR32_USART_CSR_DSRIC_MASK                           0x00020000
#define AVR32_USART_CSR_DSRIC_OFFSET                                 17
#define AVR32_USART_CSR_DSRIC_SIZE                                    1
#define AVR32_USART_CSR_DSR_MASK                             0x00200000
#define AVR32_USART_CSR_DSR_OFFSET                                   21
#define AVR32_USART_CSR_DSR_SIZE                                      1
#define AVR32_USART_CSR_ENDRX                                         3
#define AVR32_USART_CSR_ENDRX_MASK                           0x00000008
#define AVR32_USART_CSR_ENDRX_OFFSET                                  3
#define AVR32_USART_CSR_ENDRX_SIZE                                    1
#define AVR32_USART_CSR_ENDTX                                         4
#define AVR32_USART_CSR_ENDTX_MASK                           0x00000010
#define AVR32_USART_CSR_ENDTX_OFFSET                                  4
#define AVR32_USART_CSR_ENDTX_SIZE                                    1
#define AVR32_USART_CSR_FRAME                                         6
#define AVR32_USART_CSR_FRAME_MASK                           0x00000040
#define AVR32_USART_CSR_FRAME_OFFSET                                  6
#define AVR32_USART_CSR_FRAME_SIZE                                    1
#define AVR32_USART_CSR_ITERATION                                    10
#define AVR32_USART_CSR_ITERATION_MASK                       0x00000400
#define AVR32_USART_CSR_ITERATION_OFFSET                             10
#define AVR32_USART_CSR_ITERATION_SIZE                                1
#define AVR32_USART_CSR_LINBE                                        25
#define AVR32_USART_CSR_LINBE_MASK                           0x02000000
#define AVR32_USART_CSR_LINBE_OFFSET                                 25
#define AVR32_USART_CSR_LINBE_SIZE                                    1
#define AVR32_USART_CSR_LINCE                                        28
#define AVR32_USART_CSR_LINCE_MASK                           0x10000000
#define AVR32_USART_CSR_LINCE_OFFSET                                 28
#define AVR32_USART_CSR_LINCE_SIZE                                    1
#define AVR32_USART_CSR_LINIPE                                       27
#define AVR32_USART_CSR_LINIPE_MASK                          0x08000000
#define AVR32_USART_CSR_LINIPE_OFFSET                                27
#define AVR32_USART_CSR_LINIPE_SIZE                                   1
#define AVR32_USART_CSR_LINIR                                        14
#define AVR32_USART_CSR_LINIR_MASK                           0x00004000
#define AVR32_USART_CSR_LINIR_OFFSET                                 14
#define AVR32_USART_CSR_LINIR_SIZE                                    1
#define AVR32_USART_CSR_LINISFE                                      26
#define AVR32_USART_CSR_LINISFE_MASK                         0x04000000
#define AVR32_USART_CSR_LINISFE_OFFSET                               26
#define AVR32_USART_CSR_LINISFE_SIZE                                  1
#define AVR32_USART_CSR_LINSNRE                                      29
#define AVR32_USART_CSR_LINSNRE_MASK                         0x20000000
#define AVR32_USART_CSR_LINSNRE_OFFSET                               29
#define AVR32_USART_CSR_LINSNRE_SIZE                                  1
#define AVR32_USART_CSR_LINTC                                        15
#define AVR32_USART_CSR_LINTC_MASK                           0x00008000
#define AVR32_USART_CSR_LINTC_OFFSET                                 15
#define AVR32_USART_CSR_LINTC_SIZE                                    1
#define AVR32_USART_CSR_MANERR                                       24
#define AVR32_USART_CSR_MANERR_MASK                          0x01000000
#define AVR32_USART_CSR_MANERR_OFFSET                                24
#define AVR32_USART_CSR_MANERR_SIZE                                   1
#define AVR32_USART_CSR_NACK                                         13
#define AVR32_USART_CSR_NACK_MASK                            0x00002000
#define AVR32_USART_CSR_NACK_OFFSET                                  13
#define AVR32_USART_CSR_NACK_SIZE                                     1
#define AVR32_USART_CSR_OVRE                                          5
#define AVR32_USART_CSR_OVRE_MASK                            0x00000020
#define AVR32_USART_CSR_OVRE_OFFSET                                   5
#define AVR32_USART_CSR_OVRE_SIZE                                     1
#define AVR32_USART_CSR_PARE                                          7
#define AVR32_USART_CSR_PARE_MASK                            0x00000080
#define AVR32_USART_CSR_PARE_OFFSET                                   7
#define AVR32_USART_CSR_PARE_SIZE                                     1
#define AVR32_USART_CSR_RI                                           20
#define AVR32_USART_CSR_RIIC                                         16
#define AVR32_USART_CSR_RIIC_MASK                            0x00010000
#define AVR32_USART_CSR_RIIC_OFFSET                                  16
#define AVR32_USART_CSR_RIIC_SIZE                                     1
#define AVR32_USART_CSR_RI_MASK                              0x00100000
#define AVR32_USART_CSR_RI_OFFSET                                    20
#define AVR32_USART_CSR_RI_SIZE                                       1
#define AVR32_USART_CSR_RXBRK                                         2
#define AVR32_USART_CSR_RXBRK_MASK                           0x00000004
#define AVR32_USART_CSR_RXBRK_OFFSET                                  2
#define AVR32_USART_CSR_RXBRK_SIZE                                    1
#define AVR32_USART_CSR_RXBUFF                                       12
#define AVR32_USART_CSR_RXBUFF_MASK                          0x00001000
#define AVR32_USART_CSR_RXBUFF_OFFSET                                12
#define AVR32_USART_CSR_RXBUFF_SIZE                                   1
#define AVR32_USART_CSR_RXRDY                                         0
#define AVR32_USART_CSR_RXRDY_MASK                           0x00000001
#define AVR32_USART_CSR_RXRDY_OFFSET                                  0
#define AVR32_USART_CSR_RXRDY_SIZE                                    1
#define AVR32_USART_CSR_TIMEOUT                                       8
#define AVR32_USART_CSR_TIMEOUT_MASK                         0x00000100
#define AVR32_USART_CSR_TIMEOUT_OFFSET                                8
#define AVR32_USART_CSR_TIMEOUT_SIZE                                  1
#define AVR32_USART_CSR_TXBUFE                                       11
#define AVR32_USART_CSR_TXBUFE_MASK                          0x00000800
#define AVR32_USART_CSR_TXBUFE_OFFSET                                11
#define AVR32_USART_CSR_TXBUFE_SIZE                                   1
#define AVR32_USART_CSR_TXEMPTY                                       9
#define AVR32_USART_CSR_TXEMPTY_MASK                         0x00000200
#define AVR32_USART_CSR_TXEMPTY_OFFSET                                9
#define AVR32_USART_CSR_TXEMPTY_SIZE                                  1
#define AVR32_USART_CSR_TXRDY                                         1
#define AVR32_USART_CSR_TXRDY_MASK                           0x00000002
#define AVR32_USART_CSR_TXRDY_OFFSET                                  1
#define AVR32_USART_CSR_TXRDY_SIZE                                    1
#define AVR32_USART_CTS                                              23
#define AVR32_USART_CTSIC                                            19
#define AVR32_USART_CTSIC_MASK                               0x00080000
#define AVR32_USART_CTSIC_OFFSET                                     19
#define AVR32_USART_CTSIC_SIZE                                        1
#define AVR32_USART_CTS_MASK                                 0x00800000
#define AVR32_USART_CTS_OFFSET                                       23
#define AVR32_USART_CTS_SIZE                                          1
#define AVR32_USART_DCD                                              22
#define AVR32_USART_DCDIC                                            18
#define AVR32_USART_DCDIC_MASK                               0x00040000
#define AVR32_USART_DCDIC_OFFSET                                     18
#define AVR32_USART_DCDIC_SIZE                                        1
#define AVR32_USART_DCD_MASK                                 0x00400000
#define AVR32_USART_DCD_OFFSET                                       22
#define AVR32_USART_DCD_SIZE                                          1
#define AVR32_USART_DISABLE                                  0x00000000
#define AVR32_USART_DLC                                               8
#define AVR32_USART_DLC_MASK                                 0x0000ff00
#define AVR32_USART_DLC_OFFSET                                        8
#define AVR32_USART_DLC_SIZE                                          8
#define AVR32_USART_DLM                                               5
#define AVR32_USART_DLM_MASK                                 0x00000020
#define AVR32_USART_DLM_OFFSET                                        5
#define AVR32_USART_DLM_SIZE                                          1
#define AVR32_USART_DRIFT                                            30
#define AVR32_USART_DRIFT_MASK                               0x40000000
#define AVR32_USART_DRIFT_OFFSET                                     30
#define AVR32_USART_DRIFT_SIZE                                        1
#define AVR32_USART_DSNACK                                           21
#define AVR32_USART_DSNACK_MASK                              0x00200000
#define AVR32_USART_DSNACK_OFFSET                                    21
#define AVR32_USART_DSNACK_SIZE                                       1
#define AVR32_USART_DSR                                              21
#define AVR32_USART_DSRIC                                            17
#define AVR32_USART_DSRIC_MASK                               0x00020000
#define AVR32_USART_DSRIC_OFFSET                                     17
#define AVR32_USART_DSRIC_SIZE                                        1
#define AVR32_USART_DSR_MASK                                 0x00200000
#define AVR32_USART_DSR_OFFSET                                       21
#define AVR32_USART_DSR_SIZE                                          1
#define AVR32_USART_DTRDIS                                           17
#define AVR32_USART_DTRDIS_MASK                              0x00020000
#define AVR32_USART_DTRDIS_OFFSET                                    17
#define AVR32_USART_DTRDIS_SIZE                                       1
#define AVR32_USART_DTREN                                            16
#define AVR32_USART_DTREN_MASK                               0x00010000
#define AVR32_USART_DTREN_OFFSET                                     16
#define AVR32_USART_DTREN_SIZE                                        1
#define AVR32_USART_ECHO                                     0x00000001
#define AVR32_USART_ENDRX                                             3
#define AVR32_USART_ENDRX_MASK                               0x00000008
#define AVR32_USART_ENDRX_OFFSET                                      3
#define AVR32_USART_ENDRX_SIZE                                        1
#define AVR32_USART_ENDTX                                             4
#define AVR32_USART_ENDTX_MASK                               0x00000010
#define AVR32_USART_ENDTX_OFFSET                                      4
#define AVR32_USART_ENDTX_SIZE                                        1
#define AVR32_USART_EVEN                                     0x00000000
#define AVR32_USART_FIDI                                     0x00000040
#define AVR32_USART_FIDI_FI_DI_RATIO                                  0
#define AVR32_USART_FIDI_FI_DI_RATIO_DISABLE                 0x00000000
#define AVR32_USART_FIDI_FI_DI_RATIO_MASK                    0x000007ff
#define AVR32_USART_FIDI_FI_DI_RATIO_OFFSET                           0
#define AVR32_USART_FIDI_FI_DI_RATIO_SIZE                            11
#define AVR32_USART_FILTER                                           28
#define AVR32_USART_FILTER_MASK                              0x10000000
#define AVR32_USART_FILTER_OFFSET                                    28
#define AVR32_USART_FILTER_SIZE                                       1
#define AVR32_USART_FI_DI_RATIO                                       0
#define AVR32_USART_FI_DI_RATIO_DISABLE                      0x00000000
#define AVR32_USART_FI_DI_RATIO_MASK                         0x000007ff
#define AVR32_USART_FI_DI_RATIO_OFFSET                                0
#define AVR32_USART_FI_DI_RATIO_SIZE                                 11
#define AVR32_USART_FP                                               16
#define AVR32_USART_FP_MASK                                  0x00070000
#define AVR32_USART_FP_OFFSET                                        16
#define AVR32_USART_FP_SIZE                                           3
#define AVR32_USART_FRAME                                             6
#define AVR32_USART_FRAME_MASK                               0x00000040
#define AVR32_USART_FRAME_OFFSET                                      6
#define AVR32_USART_FRAME_SIZE                                        1
#define AVR32_USART_FSDIS                                             6
#define AVR32_USART_FSDIS_MASK                               0x00000040
#define AVR32_USART_FSDIS_OFFSET                                      6
#define AVR32_USART_FSDIS_SIZE                                        1
#define AVR32_USART_HARDWARE                                 0x00000002
#define AVR32_USART_IDCHR                                             0
#define AVR32_USART_IDCHR_MASK                               0x000000ff
#define AVR32_USART_IDCHR_OFFSET                                      0
#define AVR32_USART_IDCHR_SIZE                                        8
#define AVR32_USART_IDR                                      0x0000000c
#define AVR32_USART_IDR_COMM_RX                                      31
#define AVR32_USART_IDR_COMM_RX_MASK                         0x80000000
#define AVR32_USART_IDR_COMM_RX_OFFSET                               31
#define AVR32_USART_IDR_COMM_RX_SIZE                                  1
#define AVR32_USART_IDR_COMM_TX                                      30
#define AVR32_USART_IDR_COMM_TX_MASK                         0x40000000
#define AVR32_USART_IDR_COMM_TX_OFFSET                               30
#define AVR32_USART_IDR_COMM_TX_SIZE                                  1
#define AVR32_USART_IDR_CTSIC                                        19
#define AVR32_USART_IDR_CTSIC_MASK                           0x00080000
#define AVR32_USART_IDR_CTSIC_OFFSET                                 19
#define AVR32_USART_IDR_CTSIC_SIZE                                    1
#define AVR32_USART_IDR_DCDIC                                        18
#define AVR32_USART_IDR_DCDIC_MASK                           0x00040000
#define AVR32_USART_IDR_DCDIC_OFFSET                                 18
#define AVR32_USART_IDR_DCDIC_SIZE                                    1
#define AVR32_USART_IDR_DSRIC                                        17
#define AVR32_USART_IDR_DSRIC_MASK                           0x00020000
#define AVR32_USART_IDR_DSRIC_OFFSET                                 17
#define AVR32_USART_IDR_DSRIC_SIZE                                    1
#define AVR32_USART_IDR_ENDRX                                         3
#define AVR32_USART_IDR_ENDRX_MASK                           0x00000008
#define AVR32_USART_IDR_ENDRX_OFFSET                                  3
#define AVR32_USART_IDR_ENDRX_SIZE                                    1
#define AVR32_USART_IDR_ENDTX                                         4
#define AVR32_USART_IDR_ENDTX_MASK                           0x00000010
#define AVR32_USART_IDR_ENDTX_OFFSET                                  4
#define AVR32_USART_IDR_ENDTX_SIZE                                    1
#define AVR32_USART_IDR_FRAME                                         6
#define AVR32_USART_IDR_FRAME_MASK                           0x00000040
#define AVR32_USART_IDR_FRAME_OFFSET                                  6
#define AVR32_USART_IDR_FRAME_SIZE                                    1
#define AVR32_USART_IDR_ITERATION                                    10
#define AVR32_USART_IDR_ITERATION_MASK                       0x00000400
#define AVR32_USART_IDR_ITERATION_OFFSET                             10
#define AVR32_USART_IDR_ITERATION_SIZE                                1
#define AVR32_USART_IDR_LINBE                                        25
#define AVR32_USART_IDR_LINBE_MASK                           0x02000000
#define AVR32_USART_IDR_LINBE_OFFSET                                 25
#define AVR32_USART_IDR_LINBE_SIZE                                    1
#define AVR32_USART_IDR_LINCE                                        28
#define AVR32_USART_IDR_LINCE_MASK                           0x10000000
#define AVR32_USART_IDR_LINCE_OFFSET                                 28
#define AVR32_USART_IDR_LINCE_SIZE                                    1
#define AVR32_USART_IDR_LINIPE                                       27
#define AVR32_USART_IDR_LINIPE_MASK                          0x08000000
#define AVR32_USART_IDR_LINIPE_OFFSET                                27
#define AVR32_USART_IDR_LINIPE_SIZE                                   1
#define AVR32_USART_IDR_LINIR                                        14
#define AVR32_USART_IDR_LINIR_MASK                           0x00004000
#define AVR32_USART_IDR_LINIR_OFFSET                                 14
#define AVR32_USART_IDR_LINIR_SIZE                                    1
#define AVR32_USART_IDR_LINISFE                                      26
#define AVR32_USART_IDR_LINISFE_MASK                         0x04000000
#define AVR32_USART_IDR_LINISFE_OFFSET                               26
#define AVR32_USART_IDR_LINISFE_SIZE                                  1
#define AVR32_USART_IDR_LINSNRE                                      29
#define AVR32_USART_IDR_LINSNRE_MASK                         0x20000000
#define AVR32_USART_IDR_LINSNRE_OFFSET                               29
#define AVR32_USART_IDR_LINSNRE_SIZE                                  1
#define AVR32_USART_IDR_LINTC                                        15
#define AVR32_USART_IDR_LINTC_MASK                           0x00008000
#define AVR32_USART_IDR_LINTC_OFFSET                                 15
#define AVR32_USART_IDR_LINTC_SIZE                                    1
#define AVR32_USART_IDR_MANE                                         24
#define AVR32_USART_IDR_MANE_MASK                            0x01000000
#define AVR32_USART_IDR_MANE_OFFSET                                  24
#define AVR32_USART_IDR_MANE_SIZE                                     1
#define AVR32_USART_IDR_NACK                                         13
#define AVR32_USART_IDR_NACK_MASK                            0x00002000
#define AVR32_USART_IDR_NACK_OFFSET                                  13
#define AVR32_USART_IDR_NACK_SIZE                                     1
#define AVR32_USART_IDR_OVRE                                          5
#define AVR32_USART_IDR_OVRE_MASK                            0x00000020
#define AVR32_USART_IDR_OVRE_OFFSET                                   5
#define AVR32_USART_IDR_OVRE_SIZE                                     1
#define AVR32_USART_IDR_PARE                                          7
#define AVR32_USART_IDR_PARE_MASK                            0x00000080
#define AVR32_USART_IDR_PARE_OFFSET                                   7
#define AVR32_USART_IDR_PARE_SIZE                                     1
#define AVR32_USART_IDR_RIIC                                         16
#define AVR32_USART_IDR_RIIC_MASK                            0x00010000
#define AVR32_USART_IDR_RIIC_OFFSET                                  16
#define AVR32_USART_IDR_RIIC_SIZE                                     1
#define AVR32_USART_IDR_RXBRK                                         2
#define AVR32_USART_IDR_RXBRK_MASK                           0x00000004
#define AVR32_USART_IDR_RXBRK_OFFSET                                  2
#define AVR32_USART_IDR_RXBRK_SIZE                                    1
#define AVR32_USART_IDR_RXBUFF                                       12
#define AVR32_USART_IDR_RXBUFF_MASK                          0x00001000
#define AVR32_USART_IDR_RXBUFF_OFFSET                                12
#define AVR32_USART_IDR_RXBUFF_SIZE                                   1
#define AVR32_USART_IDR_RXRDY                                         0
#define AVR32_USART_IDR_RXRDY_MASK                           0x00000001
#define AVR32_USART_IDR_RXRDY_OFFSET                                  0
#define AVR32_USART_IDR_RXRDY_SIZE                                    1
#define AVR32_USART_IDR_TIMEOUT                                       8
#define AVR32_USART_IDR_TIMEOUT_MASK                         0x00000100
#define AVR32_USART_IDR_TIMEOUT_OFFSET                                8
#define AVR32_USART_IDR_TIMEOUT_SIZE                                  1
#define AVR32_USART_IDR_TXBUFE                                       11
#define AVR32_USART_IDR_TXBUFE_MASK                          0x00000800
#define AVR32_USART_IDR_TXBUFE_OFFSET                                11
#define AVR32_USART_IDR_TXBUFE_SIZE                                   1
#define AVR32_USART_IDR_TXEMPTY                                       9
#define AVR32_USART_IDR_TXEMPTY_MASK                         0x00000200
#define AVR32_USART_IDR_TXEMPTY_OFFSET                                9
#define AVR32_USART_IDR_TXEMPTY_SIZE                                  1
#define AVR32_USART_IDR_TXRDY                                         1
#define AVR32_USART_IDR_TXRDY_MASK                           0x00000002
#define AVR32_USART_IDR_TXRDY_OFFSET                                  1
#define AVR32_USART_IDR_TXRDY_SIZE                                    1
#define AVR32_USART_IER                                      0x00000008
#define AVR32_USART_IER_COMM_RX                                      31
#define AVR32_USART_IER_COMM_RX_MASK                         0x80000000
#define AVR32_USART_IER_COMM_RX_OFFSET                               31
#define AVR32_USART_IER_COMM_RX_SIZE                                  1
#define AVR32_USART_IER_COMM_TX                                      30
#define AVR32_USART_IER_COMM_TX_MASK                         0x40000000
#define AVR32_USART_IER_COMM_TX_OFFSET                               30
#define AVR32_USART_IER_COMM_TX_SIZE                                  1
#define AVR32_USART_IER_CTSIC                                        19
#define AVR32_USART_IER_CTSIC_MASK                           0x00080000
#define AVR32_USART_IER_CTSIC_OFFSET                                 19
#define AVR32_USART_IER_CTSIC_SIZE                                    1
#define AVR32_USART_IER_DCDIC                                        18
#define AVR32_USART_IER_DCDIC_MASK                           0x00040000
#define AVR32_USART_IER_DCDIC_OFFSET                                 18
#define AVR32_USART_IER_DCDIC_SIZE                                    1
#define AVR32_USART_IER_DSRIC                                        17
#define AVR32_USART_IER_DSRIC_MASK                           0x00020000
#define AVR32_USART_IER_DSRIC_OFFSET                                 17
#define AVR32_USART_IER_DSRIC_SIZE                                    1
#define AVR32_USART_IER_ENDRX                                         3
#define AVR32_USART_IER_ENDRX_MASK                           0x00000008
#define AVR32_USART_IER_ENDRX_OFFSET                                  3
#define AVR32_USART_IER_ENDRX_SIZE                                    1
#define AVR32_USART_IER_ENDTX                                         4
#define AVR32_USART_IER_ENDTX_MASK                           0x00000010
#define AVR32_USART_IER_ENDTX_OFFSET                                  4
#define AVR32_USART_IER_ENDTX_SIZE                                    1
#define AVR32_USART_IER_FRAME                                         6
#define AVR32_USART_IER_FRAME_MASK                           0x00000040
#define AVR32_USART_IER_FRAME_OFFSET                                  6
#define AVR32_USART_IER_FRAME_SIZE                                    1
#define AVR32_USART_IER_ITERATION                                    10
#define AVR32_USART_IER_ITERATION_MASK                       0x00000400
#define AVR32_USART_IER_ITERATION_OFFSET                             10
#define AVR32_USART_IER_ITERATION_SIZE                                1
#define AVR32_USART_IER_LINBE                                        25
#define AVR32_USART_IER_LINBE_MASK                           0x02000000
#define AVR32_USART_IER_LINBE_OFFSET                                 25
#define AVR32_USART_IER_LINBE_SIZE                                    1
#define AVR32_USART_IER_LINCE                                        28
#define AVR32_USART_IER_LINCE_MASK                           0x10000000
#define AVR32_USART_IER_LINCE_OFFSET                                 28
#define AVR32_USART_IER_LINCE_SIZE                                    1
#define AVR32_USART_IER_LINIPE                                       27
#define AVR32_USART_IER_LINIPE_MASK                          0x08000000
#define AVR32_USART_IER_LINIPE_OFFSET                                27
#define AVR32_USART_IER_LINIPE_SIZE                                   1
#define AVR32_USART_IER_LINIR                                        14
#define AVR32_USART_IER_LINIR_MASK                           0x00004000
#define AVR32_USART_IER_LINIR_OFFSET                                 14
#define AVR32_USART_IER_LINIR_SIZE                                    1
#define AVR32_USART_IER_LINISFE                                      26
#define AVR32_USART_IER_LINISFE_MASK                         0x04000000
#define AVR32_USART_IER_LINISFE_OFFSET                               26
#define AVR32_USART_IER_LINISFE_SIZE                                  1
#define AVR32_USART_IER_LINSNRE                                      29
#define AVR32_USART_IER_LINSNRE_MASK                         0x20000000
#define AVR32_USART_IER_LINSNRE_OFFSET                               29
#define AVR32_USART_IER_LINSNRE_SIZE                                  1
#define AVR32_USART_IER_LINTC                                        15
#define AVR32_USART_IER_LINTC_MASK                           0x00008000
#define AVR32_USART_IER_LINTC_OFFSET                                 15
#define AVR32_USART_IER_LINTC_SIZE                                    1
#define AVR32_USART_IER_MANE                                         24
#define AVR32_USART_IER_MANE_MASK                            0x01000000
#define AVR32_USART_IER_MANE_OFFSET                                  24
#define AVR32_USART_IER_MANE_SIZE                                     1
#define AVR32_USART_IER_NACK                                         13
#define AVR32_USART_IER_NACK_MASK                            0x00002000
#define AVR32_USART_IER_NACK_OFFSET                                  13
#define AVR32_USART_IER_NACK_SIZE                                     1
#define AVR32_USART_IER_OVRE                                          5
#define AVR32_USART_IER_OVRE_MASK                            0x00000020
#define AVR32_USART_IER_OVRE_OFFSET                                   5
#define AVR32_USART_IER_OVRE_SIZE                                     1
#define AVR32_USART_IER_PARE                                          7
#define AVR32_USART_IER_PARE_MASK                            0x00000080
#define AVR32_USART_IER_PARE_OFFSET                                   7
#define AVR32_USART_IER_PARE_SIZE                                     1
#define AVR32_USART_IER_RIIC                                         16
#define AVR32_USART_IER_RIIC_MASK                            0x00010000
#define AVR32_USART_IER_RIIC_OFFSET                                  16
#define AVR32_USART_IER_RIIC_SIZE                                     1
#define AVR32_USART_IER_RXBRK                                         2
#define AVR32_USART_IER_RXBRK_MASK                           0x00000004
#define AVR32_USART_IER_RXBRK_OFFSET                                  2
#define AVR32_USART_IER_RXBRK_SIZE                                    1
#define AVR32_USART_IER_RXBUFF                                       12
#define AVR32_USART_IER_RXBUFF_MASK                          0x00001000
#define AVR32_USART_IER_RXBUFF_OFFSET                                12
#define AVR32_USART_IER_RXBUFF_SIZE                                   1
#define AVR32_USART_IER_RXRDY                                         0
#define AVR32_USART_IER_RXRDY_MASK                           0x00000001
#define AVR32_USART_IER_RXRDY_OFFSET                                  0
#define AVR32_USART_IER_RXRDY_SIZE                                    1
#define AVR32_USART_IER_TIMEOUT                                       8
#define AVR32_USART_IER_TIMEOUT_MASK                         0x00000100
#define AVR32_USART_IER_TIMEOUT_OFFSET                                8
#define AVR32_USART_IER_TIMEOUT_SIZE                                  1
#define AVR32_USART_IER_TXBUFE                                       11
#define AVR32_USART_IER_TXBUFE_MASK                          0x00000800
#define AVR32_USART_IER_TXBUFE_OFFSET                                11
#define AVR32_USART_IER_TXBUFE_SIZE                                   1
#define AVR32_USART_IER_TXEMPTY                                       9
#define AVR32_USART_IER_TXEMPTY_MASK                         0x00000200
#define AVR32_USART_IER_TXEMPTY_OFFSET                                9
#define AVR32_USART_IER_TXEMPTY_SIZE                                  1
#define AVR32_USART_IER_TXRDY                                         1
#define AVR32_USART_IER_TXRDY_MASK                           0x00000002
#define AVR32_USART_IER_TXRDY_OFFSET                                  1
#define AVR32_USART_IER_TXRDY_SIZE                                    1
#define AVR32_USART_IFR                                      0x0000004c
#define AVR32_USART_IFR_IRDA_FILTER                                   0
#define AVR32_USART_IFR_IRDA_FILTER_MASK                     0x000000ff
#define AVR32_USART_IFR_IRDA_FILTER_OFFSET                            0
#define AVR32_USART_IFR_IRDA_FILTER_SIZE                              8
#define AVR32_USART_IGNORE                                   0x00000002
#define AVR32_USART_IMR                                      0x00000010
#define AVR32_USART_IMR_COMM_RX                                      31
#define AVR32_USART_IMR_COMM_RX_MASK                         0x80000000
#define AVR32_USART_IMR_COMM_RX_OFFSET                               31
#define AVR32_USART_IMR_COMM_RX_SIZE                                  1
#define AVR32_USART_IMR_COMM_TX                                      30
#define AVR32_USART_IMR_COMM_TX_MASK                         0x40000000
#define AVR32_USART_IMR_COMM_TX_OFFSET                               30
#define AVR32_USART_IMR_COMM_TX_SIZE                                  1
#define AVR32_USART_IMR_CTSIC                                        19
#define AVR32_USART_IMR_CTSIC_MASK                           0x00080000
#define AVR32_USART_IMR_CTSIC_OFFSET                                 19
#define AVR32_USART_IMR_CTSIC_SIZE                                    1
#define AVR32_USART_IMR_DCDIC                                        18
#define AVR32_USART_IMR_DCDIC_MASK                           0x00040000
#define AVR32_USART_IMR_DCDIC_OFFSET                                 18
#define AVR32_USART_IMR_DCDIC_SIZE                                    1
#define AVR32_USART_IMR_DSRIC                                        17
#define AVR32_USART_IMR_DSRIC_MASK                           0x00020000
#define AVR32_USART_IMR_DSRIC_OFFSET                                 17
#define AVR32_USART_IMR_DSRIC_SIZE                                    1
#define AVR32_USART_IMR_ENDRX                                         3
#define AVR32_USART_IMR_ENDRX_MASK                           0x00000008
#define AVR32_USART_IMR_ENDRX_OFFSET                                  3
#define AVR32_USART_IMR_ENDRX_SIZE                                    1
#define AVR32_USART_IMR_ENDTX                                         4
#define AVR32_USART_IMR_ENDTX_MASK                           0x00000010
#define AVR32_USART_IMR_ENDTX_OFFSET                                  4
#define AVR32_USART_IMR_ENDTX_SIZE                                    1
#define AVR32_USART_IMR_FRAME                                         6
#define AVR32_USART_IMR_FRAME_MASK                           0x00000040
#define AVR32_USART_IMR_FRAME_OFFSET                                  6
#define AVR32_USART_IMR_FRAME_SIZE                                    1
#define AVR32_USART_IMR_ITERATION                                    10
#define AVR32_USART_IMR_ITERATION_MASK                       0x00000400
#define AVR32_USART_IMR_ITERATION_OFFSET                             10
#define AVR32_USART_IMR_ITERATION_SIZE                                1
#define AVR32_USART_IMR_LINBE                                        25
#define AVR32_USART_IMR_LINBE_MASK                           0x02000000
#define AVR32_USART_IMR_LINBE_OFFSET                                 25
#define AVR32_USART_IMR_LINBE_SIZE                                    1
#define AVR32_USART_IMR_LINCE                                        28
#define AVR32_USART_IMR_LINCE_MASK                           0x10000000
#define AVR32_USART_IMR_LINCE_OFFSET                                 28
#define AVR32_USART_IMR_LINCE_SIZE                                    1
#define AVR32_USART_IMR_LINIPE                                       27
#define AVR32_USART_IMR_LINIPE_MASK                          0x08000000
#define AVR32_USART_IMR_LINIPE_OFFSET                                27
#define AVR32_USART_IMR_LINIPE_SIZE                                   1
#define AVR32_USART_IMR_LINIR                                        14
#define AVR32_USART_IMR_LINIR_MASK                           0x00004000
#define AVR32_USART_IMR_LINIR_OFFSET                                 14
#define AVR32_USART_IMR_LINIR_SIZE                                    1
#define AVR32_USART_IMR_LINISFE                                      26
#define AVR32_USART_IMR_LINISFE_MASK                         0x04000000
#define AVR32_USART_IMR_LINISFE_OFFSET                               26
#define AVR32_USART_IMR_LINISFE_SIZE                                  1
#define AVR32_USART_IMR_LINSNRE                                      29
#define AVR32_USART_IMR_LINSNRE_MASK                         0x20000000
#define AVR32_USART_IMR_LINSNRE_OFFSET                               29
#define AVR32_USART_IMR_LINSNRE_SIZE                                  1
#define AVR32_USART_IMR_LINTC                                        15
#define AVR32_USART_IMR_LINTC_MASK                           0x00008000
#define AVR32_USART_IMR_LINTC_OFFSET                                 15
#define AVR32_USART_IMR_LINTC_SIZE                                    1
#define AVR32_USART_IMR_MANE                                         24
#define AVR32_USART_IMR_MANE_MASK                            0x01000000
#define AVR32_USART_IMR_MANE_OFFSET                                  24
#define AVR32_USART_IMR_MANE_SIZE                                     1
#define AVR32_USART_IMR_NACK                                         13
#define AVR32_USART_IMR_NACK_MASK                            0x00002000
#define AVR32_USART_IMR_NACK_OFFSET                                  13
#define AVR32_USART_IMR_NACK_SIZE                                     1
#define AVR32_USART_IMR_OVRE                                          5
#define AVR32_USART_IMR_OVRE_MASK                            0x00000020
#define AVR32_USART_IMR_OVRE_OFFSET                                   5
#define AVR32_USART_IMR_OVRE_SIZE                                     1
#define AVR32_USART_IMR_PARE                                          7
#define AVR32_USART_IMR_PARE_MASK                            0x00000080
#define AVR32_USART_IMR_PARE_OFFSET                                   7
#define AVR32_USART_IMR_PARE_SIZE                                     1
#define AVR32_USART_IMR_RIIC                                         16
#define AVR32_USART_IMR_RIIC_MASK                            0x00010000
#define AVR32_USART_IMR_RIIC_OFFSET                                  16
#define AVR32_USART_IMR_RIIC_SIZE                                     1
#define AVR32_USART_IMR_RXBRK                                         2
#define AVR32_USART_IMR_RXBRK_MASK                           0x00000004
#define AVR32_USART_IMR_RXBRK_OFFSET                                  2
#define AVR32_USART_IMR_RXBRK_SIZE                                    1
#define AVR32_USART_IMR_RXBUFF                                       12
#define AVR32_USART_IMR_RXBUFF_MASK                          0x00001000
#define AVR32_USART_IMR_RXBUFF_OFFSET                                12
#define AVR32_USART_IMR_RXBUFF_SIZE                                   1
#define AVR32_USART_IMR_RXRDY                                         0
#define AVR32_USART_IMR_RXRDY_MASK                           0x00000001
#define AVR32_USART_IMR_RXRDY_OFFSET                                  0
#define AVR32_USART_IMR_RXRDY_SIZE                                    1
#define AVR32_USART_IMR_TIMEOUT                                       8
#define AVR32_USART_IMR_TIMEOUT_MASK                         0x00000100
#define AVR32_USART_IMR_TIMEOUT_OFFSET                                8
#define AVR32_USART_IMR_TIMEOUT_SIZE                                  1
#define AVR32_USART_IMR_TXBUFE                                       11
#define AVR32_USART_IMR_TXBUFE_MASK                          0x00000800
#define AVR32_USART_IMR_TXBUFE_OFFSET                                11
#define AVR32_USART_IMR_TXBUFE_SIZE                                   1
#define AVR32_USART_IMR_TXEMPTY                                       9
#define AVR32_USART_IMR_TXEMPTY_MASK                         0x00000200
#define AVR32_USART_IMR_TXEMPTY_OFFSET                                9
#define AVR32_USART_IMR_TXEMPTY_SIZE                                  1
#define AVR32_USART_IMR_TXRDY                                         1
#define AVR32_USART_IMR_TXRDY_MASK                           0x00000002
#define AVR32_USART_IMR_TXRDY_OFFSET                                  1
#define AVR32_USART_IMR_TXRDY_SIZE                                    1
#define AVR32_USART_INACK                                            20
#define AVR32_USART_INACK_MASK                               0x00100000
#define AVR32_USART_INACK_OFFSET                                     20
#define AVR32_USART_INACK_SIZE                                        1
#define AVR32_USART_IRDA                                     0x00000008
#define AVR32_USART_IRDA_FILTER                                       0
#define AVR32_USART_IRDA_FILTER_MASK                         0x000000ff
#define AVR32_USART_IRDA_FILTER_OFFSET                                0
#define AVR32_USART_IRDA_FILTER_SIZE                                  8
#define AVR32_USART_ISO7816_T0                               0x00000004
#define AVR32_USART_ISO7816_T1                               0x00000006
#define AVR32_USART_ITERATION                                        10
#define AVR32_USART_ITERATION_MASK                           0x00000400
#define AVR32_USART_ITERATION_OFFSET                                 10
#define AVR32_USART_ITERATION_SIZE                                    1
#define AVR32_USART_LINABT                                           20
#define AVR32_USART_LINABT_MASK                              0x00100000
#define AVR32_USART_LINABT_OFFSET                                    20
#define AVR32_USART_LINABT_SIZE                                       1
#define AVR32_USART_LINBE                                            25
#define AVR32_USART_LINBE_MASK                               0x02000000
#define AVR32_USART_LINBE_OFFSET                                     25
#define AVR32_USART_LINBE_SIZE                                        1
#define AVR32_USART_LINCE                                            28
#define AVR32_USART_LINCE_MASK                               0x10000000
#define AVR32_USART_LINCE_OFFSET                                     28
#define AVR32_USART_LINCE_SIZE                                        1
#define AVR32_USART_LINIPE                                           27
#define AVR32_USART_LINIPE_MASK                              0x08000000
#define AVR32_USART_LINIPE_OFFSET                                    27
#define AVR32_USART_LINIPE_SIZE                                       1
#define AVR32_USART_LINIR                                    0x00000058
#define AVR32_USART_LINIR_IDCHR                                       0
#define AVR32_USART_LINIR_IDCHR_MASK                         0x000000ff
#define AVR32_USART_LINIR_IDCHR_OFFSET                                0
#define AVR32_USART_LINIR_IDCHR_SIZE                                  8
#define AVR32_USART_LINIR_MASK                               0x00004000
#define AVR32_USART_LINIR_OFFSET                                     14
#define AVR32_USART_LINIR_SIZE                                        1
#define AVR32_USART_LINISFE                                          26
#define AVR32_USART_LINISFE_MASK                             0x04000000
#define AVR32_USART_LINISFE_OFFSET                                   26
#define AVR32_USART_LINISFE_SIZE                                      1
#define AVR32_USART_LINMR                                    0x00000054
#define AVR32_USART_LINMR_CHKDIS                                      3
#define AVR32_USART_LINMR_CHKDIS_MASK                        0x00000008
#define AVR32_USART_LINMR_CHKDIS_OFFSET                               3
#define AVR32_USART_LINMR_CHKDIS_SIZE                                 1
#define AVR32_USART_LINMR_CHKTYP                                      4
#define AVR32_USART_LINMR_CHKTYP_MASK                        0x00000010
#define AVR32_USART_LINMR_CHKTYP_OFFSET                               4
#define AVR32_USART_LINMR_CHKTYP_SIZE                                 1
#define AVR32_USART_LINMR_DLC                                         8
#define AVR32_USART_LINMR_DLC_MASK                           0x0000ff00
#define AVR32_USART_LINMR_DLC_OFFSET                                  8
#define AVR32_USART_LINMR_DLC_SIZE                                    8
#define AVR32_USART_LINMR_DLM                                         5
#define AVR32_USART_LINMR_DLM_MASK                           0x00000020
#define AVR32_USART_LINMR_DLM_OFFSET                                  5
#define AVR32_USART_LINMR_DLM_SIZE                                    1
#define AVR32_USART_LINMR_FSDIS                                       6
#define AVR32_USART_LINMR_FSDIS_MASK                         0x00000040
#define AVR32_USART_LINMR_FSDIS_OFFSET                                6
#define AVR32_USART_LINMR_FSDIS_SIZE                                  1
#define AVR32_USART_LINMR_NACT                                        0
#define AVR32_USART_LINMR_NACT_IGNORE                        0x00000002
#define AVR32_USART_LINMR_NACT_MASK                          0x00000003
#define AVR32_USART_LINMR_NACT_OFFSET                                 0
#define AVR32_USART_LINMR_NACT_PUBLISH                       0x00000000
#define AVR32_USART_LINMR_NACT_SIZE                                   2
#define AVR32_USART_LINMR_NACT_SUBSCRIBE                     0x00000001
#define AVR32_USART_LINMR_PARDIS                                      2
#define AVR32_USART_LINMR_PARDIS_MASK                        0x00000004
#define AVR32_USART_LINMR_PARDIS_OFFSET                               2
#define AVR32_USART_LINMR_PARDIS_SIZE                                 1
#define AVR32_USART_LINMR_PDCM                                       16
#define AVR32_USART_LINMR_PDCM_MASK                          0x00010000
#define AVR32_USART_LINMR_PDCM_OFFSET                                16
#define AVR32_USART_LINMR_PDCM_SIZE                                   1
#define AVR32_USART_LINMR_WKUPTYP                                     7
#define AVR32_USART_LINMR_WKUPTYP_MASK                       0x00000080
#define AVR32_USART_LINMR_WKUPTYP_OFFSET                              7
#define AVR32_USART_LINMR_WKUPTYP_SIZE                                1
#define AVR32_USART_LINSNRE                                          29
#define AVR32_USART_LINSNRE_MASK                             0x20000000
#define AVR32_USART_LINSNRE_OFFSET                                   29
#define AVR32_USART_LINSNRE_SIZE                                      1
#define AVR32_USART_LINTC                                            15
#define AVR32_USART_LINTC_MASK                               0x00008000
#define AVR32_USART_LINTC_OFFSET                                     15
#define AVR32_USART_LINTC_SIZE                                        1
#define AVR32_USART_LINWKUP                                          21
#define AVR32_USART_LINWKUP_MASK                             0x00200000
#define AVR32_USART_LINWKUP_OFFSET                                   21
#define AVR32_USART_LINWKUP_SIZE                                      1
#define AVR32_USART_LIN_MASTER                               0x0000000a
#define AVR32_USART_LIN_SLAVE                                0x0000000b
#define AVR32_USART_LOCAL_LOOP                               0x00000002
#define AVR32_USART_LSBF                                     0x00000000
#define AVR32_USART_MAN                                      0x00000050
#define AVR32_USART_MANE                                             24
#define AVR32_USART_MANERR                                           24
#define AVR32_USART_MANERR_MASK                              0x01000000
#define AVR32_USART_MANERR_OFFSET                                    24
#define AVR32_USART_MANERR_SIZE                                       1
#define AVR32_USART_MANE_MASK                                0x01000000
#define AVR32_USART_MANE_OFFSET                                      24
#define AVR32_USART_MANE_SIZE                                         1
#define AVR32_USART_MAN_DRIFT                                        30
#define AVR32_USART_MAN_DRIFT_MASK                           0x40000000
#define AVR32_USART_MAN_DRIFT_OFFSET                                 30
#define AVR32_USART_MAN_DRIFT_SIZE                                    1
#define AVR32_USART_MAN_MASK                                 0x20000000
#define AVR32_USART_MAN_OFFSET                                       29
#define AVR32_USART_MAN_RX_MPOL                                      28
#define AVR32_USART_MAN_RX_MPOL_MASK                         0x10000000
#define AVR32_USART_MAN_RX_MPOL_OFFSET                               28
#define AVR32_USART_MAN_RX_MPOL_SIZE                                  1
#define AVR32_USART_MAN_RX_PL                                        16
#define AVR32_USART_MAN_RX_PL_MASK                           0x000f0000
#define AVR32_USART_MAN_RX_PL_OFFSET                                 16
#define AVR32_USART_MAN_RX_PL_SIZE                                    4
#define AVR32_USART_MAN_RX_PP                                        24
#define AVR32_USART_MAN_RX_PP_MASK                           0x03000000
#define AVR32_USART_MAN_RX_PP_OFFSET                                 24
#define AVR32_USART_MAN_RX_PP_SIZE                                    2
#define AVR32_USART_MAN_SIZE                                          1
#define AVR32_USART_MAN_TX_MPOL                                      12
#define AVR32_USART_MAN_TX_MPOL_MASK                         0x00001000
#define AVR32_USART_MAN_TX_MPOL_OFFSET                               12
#define AVR32_USART_MAN_TX_MPOL_SIZE                                  1
#define AVR32_USART_MAN_TX_PL                                         0
#define AVR32_USART_MAN_TX_PL_MASK                           0x0000000f
#define AVR32_USART_MAN_TX_PL_OFFSET                                  0
#define AVR32_USART_MAN_TX_PL_SIZE                                    4
#define AVR32_USART_MAN_TX_PP                                         8
#define AVR32_USART_MAN_TX_PP_MASK                           0x00000300
#define AVR32_USART_MAN_TX_PP_OFFSET                                  8
#define AVR32_USART_MAN_TX_PP_SIZE                                    2
#define AVR32_USART_MARK                                     0x00000003
#define AVR32_USART_MAX_ITERATION                                    24
#define AVR32_USART_MAX_ITERATION_MASK                       0x07000000
#define AVR32_USART_MAX_ITERATION_OFFSET                             24
#define AVR32_USART_MAX_ITERATION_SIZE                                3
#define AVR32_USART_MCK                                      0x00000000
#define AVR32_USART_MCK_DIV                                  0x00000001
#define AVR32_USART_MODE                                              0
#define AVR32_USART_MODE9                                            17
#define AVR32_USART_MODE9_MASK                               0x00020000
#define AVR32_USART_MODE9_OFFSET                                     17
#define AVR32_USART_MODE9_SIZE                                        1
#define AVR32_USART_MODEM                                    0x00000003
#define AVR32_USART_MODE_HARDWARE                            0x00000002
#define AVR32_USART_MODE_IRDA                                0x00000008
#define AVR32_USART_MODE_ISO7816_T0                          0x00000004
#define AVR32_USART_MODE_ISO7816_T1                          0x00000006
#define AVR32_USART_MODE_LIN_MASTER                          0x0000000a
#define AVR32_USART_MODE_LIN_SLAVE                           0x0000000b
#define AVR32_USART_MODE_MASK                                0x0000000f
#define AVR32_USART_MODE_MODEM                               0x00000003
#define AVR32_USART_MODE_NORMAL                              0x00000000
#define AVR32_USART_MODE_OFFSET                                       0
#define AVR32_USART_MODE_RS485                               0x00000001
#define AVR32_USART_MODE_SIZE                                         4
#define AVR32_USART_MODE_SPI_MASTER                          0x0000000e
#define AVR32_USART_MODE_SPI_SLAVE                           0x0000000f
#define AVR32_USART_MODSYNC                                          30
#define AVR32_USART_MODSYNC_MASK                             0x40000000
#define AVR32_USART_MODSYNC_OFFSET                                   30
#define AVR32_USART_MODSYNC_SIZE                                      1
#define AVR32_USART_MR                                       0x00000004
#define AVR32_USART_MR_CHMODE                                        14
#define AVR32_USART_MR_CHMODE_ECHO                           0x00000001
#define AVR32_USART_MR_CHMODE_LOCAL_LOOP                     0x00000002
#define AVR32_USART_MR_CHMODE_MASK                           0x0000c000
#define AVR32_USART_MR_CHMODE_NORMAL                         0x00000000
#define AVR32_USART_MR_CHMODE_OFFSET                                 14
#define AVR32_USART_MR_CHMODE_REMOTE_LOOP                    0x00000003
#define AVR32_USART_MR_CHMODE_SIZE                                    2
#define AVR32_USART_MR_CHRL                                           6
#define AVR32_USART_MR_CHRL_5                                0x00000000
#define AVR32_USART_MR_CHRL_6                                0x00000001
#define AVR32_USART_MR_CHRL_7                                0x00000002
#define AVR32_USART_MR_CHRL_8                                0x00000003
#define AVR32_USART_MR_CHRL_MASK                             0x000000c0
#define AVR32_USART_MR_CHRL_OFFSET                                    6
#define AVR32_USART_MR_CHRL_SIZE                                      2
#define AVR32_USART_MR_CLKO                                          18
#define AVR32_USART_MR_CLKO_MASK                             0x00040000
#define AVR32_USART_MR_CLKO_OFFSET                                   18
#define AVR32_USART_MR_CLKO_SIZE                                      1
#define AVR32_USART_MR_DSNACK                                        21
#define AVR32_USART_MR_DSNACK_MASK                           0x00200000
#define AVR32_USART_MR_DSNACK_OFFSET                                 21
#define AVR32_USART_MR_DSNACK_SIZE                                    1
#define AVR32_USART_MR_FILTER                                        28
#define AVR32_USART_MR_FILTER_MASK                           0x10000000
#define AVR32_USART_MR_FILTER_OFFSET                                 28
#define AVR32_USART_MR_FILTER_SIZE                                    1
#define AVR32_USART_MR_INACK                                         20
#define AVR32_USART_MR_INACK_MASK                            0x00100000
#define AVR32_USART_MR_INACK_OFFSET                                  20
#define AVR32_USART_MR_INACK_SIZE                                     1
#define AVR32_USART_MR_MAN                                           29
#define AVR32_USART_MR_MAN_MASK                              0x20000000
#define AVR32_USART_MR_MAN_OFFSET                                    29
#define AVR32_USART_MR_MAN_SIZE                                       1
#define AVR32_USART_MR_MAX_ITERATION                                 24
#define AVR32_USART_MR_MAX_ITERATION_MASK                    0x07000000
#define AVR32_USART_MR_MAX_ITERATION_OFFSET                          24
#define AVR32_USART_MR_MAX_ITERATION_SIZE                             3
#define AVR32_USART_MR_MODE                                           0
#define AVR32_USART_MR_MODE9                                         17
#define AVR32_USART_MR_MODE9_MASK                            0x00020000
#define AVR32_USART_MR_MODE9_OFFSET                                  17
#define AVR32_USART_MR_MODE9_SIZE                                     1
#define AVR32_USART_MR_MODE_HARDWARE                         0x00000002
#define AVR32_USART_MR_MODE_IRDA                             0x00000008
#define AVR32_USART_MR_MODE_ISO7816_T0                       0x00000004
#define AVR32_USART_MR_MODE_ISO7816_T1                       0x00000006
#define AVR32_USART_MR_MODE_LIN_MASTER                       0x0000000a
#define AVR32_USART_MR_MODE_LIN_SLAVE                        0x0000000b
#define AVR32_USART_MR_MODE_MASK                             0x0000000f
#define AVR32_USART_MR_MODE_MODEM                            0x00000003
#define AVR32_USART_MR_MODE_NORMAL                           0x00000000
#define AVR32_USART_MR_MODE_OFFSET                                    0
#define AVR32_USART_MR_MODE_RS485                            0x00000001
#define AVR32_USART_MR_MODE_SIZE                                      4
#define AVR32_USART_MR_MODE_SPI_MASTER                       0x0000000e
#define AVR32_USART_MR_MODE_SPI_SLAVE                        0x0000000f
#define AVR32_USART_MR_MODSYNC                                       30
#define AVR32_USART_MR_MODSYNC_MASK                          0x40000000
#define AVR32_USART_MR_MODSYNC_OFFSET                                30
#define AVR32_USART_MR_MODSYNC_SIZE                                   1
#define AVR32_USART_MR_MSBF                                          16
#define AVR32_USART_MR_MSBF_LSBF                             0x00000000
#define AVR32_USART_MR_MSBF_MASK                             0x00010000
#define AVR32_USART_MR_MSBF_MSBF                             0x00000001
#define AVR32_USART_MR_MSBF_OFFSET                                   16
#define AVR32_USART_MR_MSBF_SIZE                                      1
#define AVR32_USART_MR_NBSTOP                                        12
#define AVR32_USART_MR_NBSTOP_1                              0x00000000
#define AVR32_USART_MR_NBSTOP_1_5                            0x00000001
#define AVR32_USART_MR_NBSTOP_2                              0x00000002
#define AVR32_USART_MR_NBSTOP_MASK                           0x00003000
#define AVR32_USART_MR_NBSTOP_OFFSET                                 12
#define AVR32_USART_MR_NBSTOP_SIZE                                    2
#define AVR32_USART_MR_ONEBIT                                        31
#define AVR32_USART_MR_ONEBIT_MASK                           0x80000000
#define AVR32_USART_MR_ONEBIT_OFFSET                                 31
#define AVR32_USART_MR_ONEBIT_SIZE                                    1
#define AVR32_USART_MR_OVER                                          19
#define AVR32_USART_MR_OVER_MASK                             0x00080000
#define AVR32_USART_MR_OVER_OFFSET                                   19
#define AVR32_USART_MR_OVER_SIZE                                      1
#define AVR32_USART_MR_OVER_X16                              0x00000000
#define AVR32_USART_MR_OVER_X8                               0x00000001
#define AVR32_USART_MR_PAR                                            9
#define AVR32_USART_MR_PAR_EVEN                              0x00000000
#define AVR32_USART_MR_PAR_MARK                              0x00000003
#define AVR32_USART_MR_PAR_MASK                              0x00000e00
#define AVR32_USART_MR_PAR_MULTI                             0x00000006
#define AVR32_USART_MR_PAR_NONE                              0x00000004
#define AVR32_USART_MR_PAR_ODD                               0x00000001
#define AVR32_USART_MR_PAR_OFFSET                                     9
#define AVR32_USART_MR_PAR_SIZE                                       3
#define AVR32_USART_MR_PAR_SPACE                             0x00000002
#define AVR32_USART_MR_SYNC                                           8
#define AVR32_USART_MR_SYNC_MASK                             0x00000100
#define AVR32_USART_MR_SYNC_OFFSET                                    8
#define AVR32_USART_MR_SYNC_SIZE                                      1
#define AVR32_USART_MR_USCLKS                                         4
#define AVR32_USART_MR_USCLKS_MASK                           0x00000030
#define AVR32_USART_MR_USCLKS_MCK                            0x00000000
#define AVR32_USART_MR_USCLKS_MCK_DIV                        0x00000001
#define AVR32_USART_MR_USCLKS_OFFSET                                  4
#define AVR32_USART_MR_USCLKS_SCK                            0x00000003
#define AVR32_USART_MR_USCLKS_SIZE                                    2
#define AVR32_USART_MR_VAR_SYNC                                      22
#define AVR32_USART_MR_VAR_SYNC_MASK                         0x00400000
#define AVR32_USART_MR_VAR_SYNC_OFFSET                               22
#define AVR32_USART_MR_VAR_SYNC_SIZE                                  1
#define AVR32_USART_MSBF_LSBF                                0x00000000
#define AVR32_USART_MSBF_MASK                                0x00010000
#define AVR32_USART_MSBF_MSBF                                0x00000001
#define AVR32_USART_MSBF_OFFSET                                      16
#define AVR32_USART_MSBF_SIZE                                         1
#define AVR32_USART_MULTI                                    0x00000006
#define AVR32_USART_NACK                                             13
#define AVR32_USART_NACK_MASK                                0x00002000
#define AVR32_USART_NACK_OFFSET                                      13
#define AVR32_USART_NACK_SIZE                                         1
#define AVR32_USART_NACT                                              0
#define AVR32_USART_NACT_IGNORE                              0x00000002
#define AVR32_USART_NACT_MASK                                0x00000003
#define AVR32_USART_NACT_OFFSET                                       0
#define AVR32_USART_NACT_PUBLISH                             0x00000000
#define AVR32_USART_NACT_SIZE                                         2
#define AVR32_USART_NACT_SUBSCRIBE                           0x00000001
#define AVR32_USART_NBSTOP                                           12
#define AVR32_USART_NBSTOP_1                                 0x00000000
#define AVR32_USART_NBSTOP_1_5                               0x00000001
#define AVR32_USART_NBSTOP_2                                 0x00000002
#define AVR32_USART_NBSTOP_MASK                              0x00003000
#define AVR32_USART_NBSTOP_OFFSET                                    12
#define AVR32_USART_NBSTOP_SIZE                                       2
#define AVR32_USART_NB_ERRORS                                         0
#define AVR32_USART_NB_ERRORS_MASK                           0x000000ff
#define AVR32_USART_NB_ERRORS_OFFSET                                  0
#define AVR32_USART_NB_ERRORS_SIZE                                    8
#define AVR32_USART_NER                                      0x00000044
#define AVR32_USART_NER_NB_ERRORS                                     0
#define AVR32_USART_NER_NB_ERRORS_MASK                       0x000000ff
#define AVR32_USART_NER_NB_ERRORS_OFFSET                              0
#define AVR32_USART_NER_NB_ERRORS_SIZE                                8
#define AVR32_USART_NONE                                     0x00000004
#define AVR32_USART_NORMAL                                   0x00000000
#define AVR32_USART_ODD                                      0x00000001
#define AVR32_USART_ONEBIT                                           31
#define AVR32_USART_ONEBIT_MASK                              0x80000000
#define AVR32_USART_ONEBIT_OFFSET                                    31
#define AVR32_USART_ONEBIT_SIZE                                       1
#define AVR32_USART_OVER                                             19
#define AVR32_USART_OVER_MASK                                0x00080000
#define AVR32_USART_OVER_OFFSET                                      19
#define AVR32_USART_OVER_SIZE                                         1
#define AVR32_USART_OVER_X16                                 0x00000000
#define AVR32_USART_OVER_X8                                  0x00000001
#define AVR32_USART_OVRE                                              5
#define AVR32_USART_OVRE_MASK                                0x00000020
#define AVR32_USART_OVRE_OFFSET                                       5
#define AVR32_USART_OVRE_SIZE                                         1
#define AVR32_USART_PAR                                               9
#define AVR32_USART_PARDIS                                            2
#define AVR32_USART_PARDIS_MASK                              0x00000004
#define AVR32_USART_PARDIS_OFFSET                                     2
#define AVR32_USART_PARDIS_SIZE                                       1
#define AVR32_USART_PARE                                              7
#define AVR32_USART_PARE_MASK                                0x00000080
#define AVR32_USART_PARE_OFFSET                                       7
#define AVR32_USART_PARE_SIZE                                         1
#define AVR32_USART_PAR_EVEN                                 0x00000000
#define AVR32_USART_PAR_MARK                                 0x00000003
#define AVR32_USART_PAR_MASK                                 0x00000e00
#define AVR32_USART_PAR_MULTI                                0x00000006
#define AVR32_USART_PAR_NONE                                 0x00000004
#define AVR32_USART_PAR_ODD                                  0x00000001
#define AVR32_USART_PAR_OFFSET                                        9
#define AVR32_USART_PAR_SIZE                                          3
#define AVR32_USART_PAR_SPACE                                0x00000002
#define AVR32_USART_PDCM                                             16
#define AVR32_USART_PDCM_MASK                                0x00010000
#define AVR32_USART_PDCM_OFFSET                                      16
#define AVR32_USART_PDCM_SIZE                                         1
#define AVR32_USART_PUBLISH                                  0x00000000
#define AVR32_USART_REMOTE_LOOP                              0x00000003
#define AVR32_USART_RETTO                                            15
#define AVR32_USART_RETTO_MASK                               0x00008000
#define AVR32_USART_RETTO_OFFSET                                     15
#define AVR32_USART_RETTO_SIZE                                        1
#define AVR32_USART_RHR                                      0x00000018
#define AVR32_USART_RHR_RXCHR                                         0
#define AVR32_USART_RHR_RXCHR_MASK                           0x000001ff
#define AVR32_USART_RHR_RXCHR_OFFSET                                  0
#define AVR32_USART_RHR_RXCHR_SIZE                                    9
#define AVR32_USART_RHR_RXSYNH                                       15
#define AVR32_USART_RHR_RXSYNH_MASK                          0x00008000
#define AVR32_USART_RHR_RXSYNH_OFFSET                                15
#define AVR32_USART_RHR_RXSYNH_SIZE                                   1
#define AVR32_USART_RI                                               20
#define AVR32_USART_RIIC                                             16
#define AVR32_USART_RIIC_MASK                                0x00010000
#define AVR32_USART_RIIC_OFFSET                                      16
#define AVR32_USART_RIIC_SIZE                                         1
#define AVR32_USART_RI_MASK                                  0x00100000
#define AVR32_USART_RI_OFFSET                                        20
#define AVR32_USART_RI_SIZE                                           1
#define AVR32_USART_RS485                                    0x00000001
#define AVR32_USART_RSTIT                                            13
#define AVR32_USART_RSTIT_MASK                               0x00002000
#define AVR32_USART_RSTIT_OFFSET                                     13
#define AVR32_USART_RSTIT_SIZE                                        1
#define AVR32_USART_RSTNACK                                          14
#define AVR32_USART_RSTNACK_MASK                             0x00004000
#define AVR32_USART_RSTNACK_OFFSET                                   14
#define AVR32_USART_RSTNACK_SIZE                                      1
#define AVR32_USART_RSTRX                                             2
#define AVR32_USART_RSTRX_MASK                               0x00000004
#define AVR32_USART_RSTRX_OFFSET                                      2
#define AVR32_USART_RSTRX_SIZE                                        1
#define AVR32_USART_RSTSTA                                            8
#define AVR32_USART_RSTSTA_MASK                              0x00000100
#define AVR32_USART_RSTSTA_OFFSET                                     8
#define AVR32_USART_RSTSTA_SIZE                                       1
#define AVR32_USART_RSTTX                                             3
#define AVR32_USART_RSTTX_MASK                               0x00000008
#define AVR32_USART_RSTTX_OFFSET                                      3
#define AVR32_USART_RSTTX_SIZE                                        1
#define AVR32_USART_RTOR                                     0x00000024
#define AVR32_USART_RTOR_TO                                           0
#define AVR32_USART_RTOR_TO_DISABLE                          0x00000000
#define AVR32_USART_RTOR_TO_MASK                             0x0000ffff
#define AVR32_USART_RTOR_TO_OFFSET                                    0
#define AVR32_USART_RTOR_TO_SIZE                                     16
#define AVR32_USART_RTSDIS                                           19
#define AVR32_USART_RTSDIS_MASK                              0x00080000
#define AVR32_USART_RTSDIS_OFFSET                                    19
#define AVR32_USART_RTSDIS_SIZE                                       1
#define AVR32_USART_RTSEN                                            18
#define AVR32_USART_RTSEN_MASK                               0x00040000
#define AVR32_USART_RTSEN_OFFSET                                     18
#define AVR32_USART_RTSEN_SIZE                                        1
#define AVR32_USART_RXBRK                                             2
#define AVR32_USART_RXBRK_MASK                               0x00000004
#define AVR32_USART_RXBRK_OFFSET                                      2
#define AVR32_USART_RXBRK_SIZE                                        1
#define AVR32_USART_RXBUFF                                           12
#define AVR32_USART_RXBUFF_MASK                              0x00001000
#define AVR32_USART_RXBUFF_OFFSET                                    12
#define AVR32_USART_RXBUFF_SIZE                                       1
#define AVR32_USART_RXCHR                                             0
#define AVR32_USART_RXCHR_MASK                               0x000001ff
#define AVR32_USART_RXCHR_OFFSET                                      0
#define AVR32_USART_RXCHR_SIZE                                        9
#define AVR32_USART_RXDIS                                             5
#define AVR32_USART_RXDIS_MASK                               0x00000020
#define AVR32_USART_RXDIS_OFFSET                                      5
#define AVR32_USART_RXDIS_SIZE                                        1
#define AVR32_USART_RXEN                                              4
#define AVR32_USART_RXEN_MASK                                0x00000010
#define AVR32_USART_RXEN_OFFSET                                       4
#define AVR32_USART_RXEN_SIZE                                         1
#define AVR32_USART_RXRDY                                             0
#define AVR32_USART_RXRDY_MASK                               0x00000001
#define AVR32_USART_RXRDY_OFFSET                                      0
#define AVR32_USART_RXRDY_SIZE                                        1
#define AVR32_USART_RXSYNH                                           15
#define AVR32_USART_RXSYNH_MASK                              0x00008000
#define AVR32_USART_RXSYNH_OFFSET                                    15
#define AVR32_USART_RXSYNH_SIZE                                       1
#define AVR32_USART_RX_MPOL                                          28
#define AVR32_USART_RX_MPOL_MASK                             0x10000000
#define AVR32_USART_RX_MPOL_OFFSET                                   28
#define AVR32_USART_RX_MPOL_SIZE                                      1
#define AVR32_USART_RX_PL                                            16
#define AVR32_USART_RX_PL_MASK                               0x000f0000
#define AVR32_USART_RX_PL_OFFSET                                     16
#define AVR32_USART_RX_PL_SIZE                                        4
#define AVR32_USART_RX_PP                                            24
#define AVR32_USART_RX_PP_MASK                               0x03000000
#define AVR32_USART_RX_PP_OFFSET                                     24
#define AVR32_USART_RX_PP_SIZE                                        2
#define AVR32_USART_SCK                                      0x00000003
#define AVR32_USART_SENDA                                            12
#define AVR32_USART_SENDA_MASK                               0x00001000
#define AVR32_USART_SENDA_OFFSET                                     12
#define AVR32_USART_SENDA_SIZE                                        1
#define AVR32_USART_SPACE                                    0x00000002
#define AVR32_USART_SPI_MASTER                               0x0000000e
#define AVR32_USART_SPI_SLAVE                                0x0000000f
#define AVR32_USART_STPBRK                                           10
#define AVR32_USART_STPBRK_MASK                              0x00000400
#define AVR32_USART_STPBRK_OFFSET                                    10
#define AVR32_USART_STPBRK_SIZE                                       1
#define AVR32_USART_STTBRK                                            9
#define AVR32_USART_STTBRK_MASK                              0x00000200
#define AVR32_USART_STTBRK_OFFSET                                     9
#define AVR32_USART_STTBRK_SIZE                                       1
#define AVR32_USART_STTTO                                            11
#define AVR32_USART_STTTO_MASK                               0x00000800
#define AVR32_USART_STTTO_OFFSET                                     11
#define AVR32_USART_STTTO_SIZE                                        1
#define AVR32_USART_SUBSCRIBE                                0x00000001
#define AVR32_USART_SYNC                                              8
#define AVR32_USART_SYNC_MASK                                0x00000100
#define AVR32_USART_SYNC_OFFSET                                       8
#define AVR32_USART_SYNC_SIZE                                         1
#define AVR32_USART_TG                                                0
#define AVR32_USART_TG_DISABLE                               0x00000000
#define AVR32_USART_TG_MASK                                  0x000000ff
#define AVR32_USART_TG_OFFSET                                         0
#define AVR32_USART_TG_SIZE                                           8
#define AVR32_USART_THR                                      0x0000001c
#define AVR32_USART_THR_TXCHR                                         0
#define AVR32_USART_THR_TXCHR_MASK                           0x000001ff
#define AVR32_USART_THR_TXCHR_OFFSET                                  0
#define AVR32_USART_THR_TXCHR_SIZE                                    9
#define AVR32_USART_THR_TXSYNH                                       15
#define AVR32_USART_THR_TXSYNH_MASK                          0x00008000
#define AVR32_USART_THR_TXSYNH_OFFSET                                15
#define AVR32_USART_THR_TXSYNH_SIZE                                   1
#define AVR32_USART_TIMEOUT                                           8
#define AVR32_USART_TIMEOUT_MASK                             0x00000100
#define AVR32_USART_TIMEOUT_OFFSET                                    8
#define AVR32_USART_TIMEOUT_SIZE                                      1
#define AVR32_USART_TO                                                0
#define AVR32_USART_TO_DISABLE                               0x00000000
#define AVR32_USART_TO_MASK                                  0x0000ffff
#define AVR32_USART_TO_OFFSET                                         0
#define AVR32_USART_TO_SIZE                                          16
#define AVR32_USART_TTGR                                     0x00000028
#define AVR32_USART_TTGR_TG                                           0
#define AVR32_USART_TTGR_TG_DISABLE                          0x00000000
#define AVR32_USART_TTGR_TG_MASK                             0x000000ff
#define AVR32_USART_TTGR_TG_OFFSET                                    0
#define AVR32_USART_TTGR_TG_SIZE                                      8
#define AVR32_USART_TXBUFE                                           11
#define AVR32_USART_TXBUFE_MASK                              0x00000800
#define AVR32_USART_TXBUFE_OFFSET                                    11
#define AVR32_USART_TXBUFE_SIZE                                       1
#define AVR32_USART_TXCHR                                             0
#define AVR32_USART_TXCHR_MASK                               0x000001ff
#define AVR32_USART_TXCHR_OFFSET                                      0
#define AVR32_USART_TXCHR_SIZE                                        9
#define AVR32_USART_TXDIS                                             7
#define AVR32_USART_TXDIS_MASK                               0x00000080
#define AVR32_USART_TXDIS_OFFSET                                      7
#define AVR32_USART_TXDIS_SIZE                                        1
#define AVR32_USART_TXEMPTY                                           9
#define AVR32_USART_TXEMPTY_MASK                             0x00000200
#define AVR32_USART_TXEMPTY_OFFSET                                    9
#define AVR32_USART_TXEMPTY_SIZE                                      1
#define AVR32_USART_TXEN                                              6
#define AVR32_USART_TXEN_MASK                                0x00000040
#define AVR32_USART_TXEN_OFFSET                                       6
#define AVR32_USART_TXEN_SIZE                                         1
#define AVR32_USART_TXRDY                                             1
#define AVR32_USART_TXRDY_MASK                               0x00000002
#define AVR32_USART_TXRDY_OFFSET                                      1
#define AVR32_USART_TXRDY_SIZE                                        1
#define AVR32_USART_TXSYNH                                           15
#define AVR32_USART_TXSYNH_MASK                              0x00008000
#define AVR32_USART_TXSYNH_OFFSET                                    15
#define AVR32_USART_TXSYNH_SIZE                                       1
#define AVR32_USART_TX_MPOL                                          12
#define AVR32_USART_TX_MPOL_MASK                             0x00001000
#define AVR32_USART_TX_MPOL_OFFSET                                   12
#define AVR32_USART_TX_MPOL_SIZE                                      1
#define AVR32_USART_TX_PL                                             0
#define AVR32_USART_TX_PL_MASK                               0x0000000f
#define AVR32_USART_TX_PL_OFFSET                                      0
#define AVR32_USART_TX_PL_SIZE                                        4
#define AVR32_USART_TX_PP                                             8
#define AVR32_USART_TX_PP_MASK                               0x00000300
#define AVR32_USART_TX_PP_OFFSET                                      8
#define AVR32_USART_TX_PP_SIZE                                        2
#define AVR32_USART_USCLKS                                            4
#define AVR32_USART_USCLKS_MASK                              0x00000030
#define AVR32_USART_USCLKS_MCK                               0x00000000
#define AVR32_USART_USCLKS_MCK_DIV                           0x00000001
#define AVR32_USART_USCLKS_OFFSET                                     4
#define AVR32_USART_USCLKS_SCK                               0x00000003
#define AVR32_USART_USCLKS_SIZE                                       2
#define AVR32_USART_VAR_SYNC                                         22
#define AVR32_USART_VAR_SYNC_MASK                            0x00400000
#define AVR32_USART_VAR_SYNC_OFFSET                                  22
#define AVR32_USART_VAR_SYNC_SIZE                                     1
#define AVR32_USART_VERSION                                  0x000000fc
#define AVR32_USART_WKUPTYP                                           7
#define AVR32_USART_WKUPTYP_MASK                             0x00000080
#define AVR32_USART_WKUPTYP_OFFSET                                    7
#define AVR32_USART_WKUPTYP_SIZE                                      1
#define AVR32_USART_X16                                      0x00000000
#define AVR32_USART_X8                                       0x00000001




#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_usart_cr_t {
    unsigned int comm_rx         : 1;
    unsigned int comm_tx         : 1;
    unsigned int                 : 8;
    unsigned int linwkup         : 1;
    unsigned int linabt          : 1;
    unsigned int rtsdis          : 1;
    unsigned int rtsen           : 1;
    unsigned int dtrdis          : 1;
    unsigned int dtren           : 1;
    unsigned int retto           : 1;
    unsigned int rstnack         : 1;
    unsigned int rstit           : 1;
    unsigned int senda           : 1;
    unsigned int sttto           : 1;
    unsigned int stpbrk          : 1;
    unsigned int sttbrk          : 1;
    unsigned int rststa          : 1;
    unsigned int txdis           : 1;
    unsigned int txen            : 1;
    unsigned int rxdis           : 1;
    unsigned int rxen            : 1;
    unsigned int rsttx           : 1;
    unsigned int rstrx           : 1;
    unsigned int                 : 2;
} avr32_usart_cr_t;



typedef struct avr32_usart_mr_t {
    unsigned int onebit          : 1;
    unsigned int modsync         : 1;
    unsigned int man             : 1;
    unsigned int filter          : 1;
    unsigned int                 : 1;
    unsigned int max_iteration   : 3;
    unsigned int                 : 1;
    unsigned int var_sync        : 1;
    unsigned int dsnack          : 1;
    unsigned int inack           : 1;
    unsigned int over            : 1;
    unsigned int clko            : 1;
    unsigned int mode9           : 1;
    unsigned int msbf            : 1;
    unsigned int chmode          : 2;
    unsigned int nbstop          : 2;
    unsigned int par             : 3;
    unsigned int sync            : 1;
    unsigned int chrl            : 2;
    unsigned int usclks          : 2;
    unsigned int mode            : 4;
} avr32_usart_mr_t;



typedef struct avr32_usart_ier_t {
    unsigned int comm_rx         : 1;
    unsigned int comm_tx         : 1;
    unsigned int linsnre         : 1;
    unsigned int lince           : 1;
    unsigned int linipe          : 1;
    unsigned int linisfe         : 1;
    unsigned int linbe           : 1;
    unsigned int mane            : 1;
    unsigned int                 : 4;
    unsigned int ctsic           : 1;
    unsigned int dcdic           : 1;
    unsigned int dsric           : 1;
    unsigned int riic            : 1;
    unsigned int lintc           : 1;
    unsigned int linir           : 1;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iteration       : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
} avr32_usart_ier_t;



typedef struct avr32_usart_idr_t {
    unsigned int comm_rx         : 1;
    unsigned int comm_tx         : 1;
    unsigned int linsnre         : 1;
    unsigned int lince           : 1;
    unsigned int linipe          : 1;
    unsigned int linisfe         : 1;
    unsigned int linbe           : 1;
    unsigned int mane            : 1;
    unsigned int                 : 4;
    unsigned int ctsic           : 1;
    unsigned int dcdic           : 1;
    unsigned int dsric           : 1;
    unsigned int riic            : 1;
    unsigned int lintc           : 1;
    unsigned int linir           : 1;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iteration       : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
} avr32_usart_idr_t;



typedef struct avr32_usart_imr_t {
    unsigned int comm_rx         : 1;
    unsigned int comm_tx         : 1;
    unsigned int linsnre         : 1;
    unsigned int lince           : 1;
    unsigned int linipe          : 1;
    unsigned int linisfe         : 1;
    unsigned int linbe           : 1;
    unsigned int mane            : 1;
    unsigned int                 : 4;
    unsigned int ctsic           : 1;
    unsigned int dcdic           : 1;
    unsigned int dsric           : 1;
    unsigned int riic            : 1;
    unsigned int lintc           : 1;
    unsigned int linir           : 1;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iteration       : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
} avr32_usart_imr_t;



typedef struct avr32_usart_csr_t {
    unsigned int comm_rx         : 1;
    unsigned int comm_tx         : 1;
    unsigned int linsnre         : 1;
    unsigned int lince           : 1;
    unsigned int linipe          : 1;
    unsigned int linisfe         : 1;
    unsigned int linbe           : 1;
    unsigned int manerr          : 1;
    unsigned int cts             : 1;
    unsigned int dcd             : 1;
    unsigned int dsr             : 1;
    unsigned int ri              : 1;
    unsigned int ctsic           : 1;
    unsigned int dcdic           : 1;
    unsigned int dsric           : 1;
    unsigned int riic            : 1;
    unsigned int lintc           : 1;
    unsigned int linir           : 1;
    unsigned int nack            : 1;
    unsigned int rxbuff          : 1;
    unsigned int txbufe          : 1;
    unsigned int iteration       : 1;
    unsigned int txempty         : 1;
    unsigned int timeout         : 1;
    unsigned int pare            : 1;
    unsigned int frame           : 1;
    unsigned int ovre            : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int rxbrk           : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
} avr32_usart_csr_t;



typedef struct avr32_usart_rhr_t {
    unsigned int                 :16;
    unsigned int rxsynh          : 1;
    unsigned int                 : 6;
    unsigned int rxchr           : 9;
} avr32_usart_rhr_t;



typedef struct avr32_usart_thr_t {
    unsigned int                 :16;
    unsigned int txsynh          : 1;
    unsigned int                 : 6;
    unsigned int txchr           : 9;
} avr32_usart_thr_t;



typedef struct avr32_usart_brgr_t {
    unsigned int                 :13;
    unsigned int fp              : 3;
    unsigned int cd              :16;
} avr32_usart_brgr_t;



typedef struct avr32_usart_rtor_t {
    unsigned int                 :16;
    unsigned int to              :16;
} avr32_usart_rtor_t;



typedef struct avr32_usart_ttgr_t {
    unsigned int                 :24;
    unsigned int tg              : 8;
} avr32_usart_ttgr_t;



typedef struct avr32_usart_fidi_t {
    unsigned int                 :21;
    unsigned int fi_di_ratio     :11;
} avr32_usart_fidi_t;



typedef struct avr32_usart_ner_t {
    unsigned int                 :24;
    unsigned int nb_errors       : 8;
} avr32_usart_ner_t;



typedef struct avr32_usart_ifr_t {
    unsigned int                 :24;
    unsigned int irda_filter     : 8;
} avr32_usart_ifr_t;



typedef struct avr32_usart_man_t {
    unsigned int                 : 1;
    unsigned int drift           : 1;
    unsigned int                 : 1;
    unsigned int rx_mpol         : 1;
    unsigned int                 : 2;
    unsigned int rx_pp           : 2;
    unsigned int                 : 4;
    unsigned int rx_pl           : 4;
    unsigned int                 : 3;
    unsigned int tx_mpol         : 1;
    unsigned int                 : 2;
    unsigned int tx_pp           : 2;
    unsigned int                 : 4;
    unsigned int tx_pl           : 4;
} avr32_usart_man_t;



typedef struct avr32_usart_linmr_t {
    unsigned int                 :15;
    unsigned int pdcm            : 1;
    unsigned int dlc             : 8;
    unsigned int wkuptyp         : 1;
    unsigned int fsdis           : 1;
    unsigned int dlm             : 1;
    unsigned int chktyp          : 1;
    unsigned int chkdis          : 1;
    unsigned int pardis          : 1;
    unsigned int nact            : 2;
} avr32_usart_linmr_t;



typedef struct avr32_usart_linir_t {
    unsigned int                 :24;
    unsigned int idchr           : 8;
} avr32_usart_linir_t;



typedef struct avr32_usart_t {
  union {
          unsigned long                  cr        ;//0x0000
          avr32_usart_cr_t               CR        ;
  };
  union {
          unsigned long                  mr        ;//0x0004
          avr32_usart_mr_t               MR        ;
  };
  union {
          unsigned long                  ier       ;//0x0008
          avr32_usart_ier_t              IER       ;
  };
  union {
          unsigned long                  idr       ;//0x000c
          avr32_usart_idr_t              IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x0010
    const avr32_usart_imr_t              IMR       ;
  };
  union {
    const unsigned long                  csr       ;//0x0014
    const avr32_usart_csr_t              CSR       ;
  };
  union {
    const unsigned long                  rhr       ;//0x0018
    const avr32_usart_rhr_t              RHR       ;
  };
  union {
          unsigned long                  thr       ;//0x001c
          avr32_usart_thr_t              THR       ;
  };
  union {
          unsigned long                  brgr      ;//0x0020
          avr32_usart_brgr_t             BRGR      ;
  };
  union {
          unsigned long                  rtor      ;//0x0024
          avr32_usart_rtor_t             RTOR      ;
  };
  union {
          unsigned long                  ttgr      ;//0x0028
          avr32_usart_ttgr_t             TTGR      ;
  };
          unsigned int                   :32       ;//0x002c
          unsigned int                   :32       ;//0x0030
          unsigned int                   :32       ;//0x0034
          unsigned int                   :32       ;//0x0038
          unsigned int                   :32       ;//0x003c
  union {
          unsigned long                  fidi      ;//0x0040
          avr32_usart_fidi_t             FIDI      ;
  };
  union {
    const unsigned long                  ner       ;//0x0044
    const avr32_usart_ner_t              NER       ;
  };
          unsigned int                   :32       ;//0x0048
  union {
          unsigned long                  ifr       ;//0x004c
          avr32_usart_ifr_t              IFR       ;
  };
  union {
          unsigned long                  man       ;//0x0050
          avr32_usart_man_t              MAN       ;
  };
  union {
          unsigned long                  linmr     ;//0x0054
          avr32_usart_linmr_t            LINMR     ;
  };
  union {
          unsigned long                  linir     ;//0x0058
          avr32_usart_linir_t            LINIR     ;
  };
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
    const unsigned long                  version   ;//0x00fc
} avr32_usart_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif

/*#ifdef AVR32_USART_400_H_INCLUDED*/
#endif

