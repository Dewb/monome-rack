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
#ifndef AVR32_TWI_211_H_INCLUDED
#define AVR32_TWI_211_H_INCLUDED

#define AVR32_TWI_H_VERSION 211

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_TWI_<register>
 - Bitfield mask:   AVR32_TWI_<register>_<bitfield>
 - Bitfield offset: AVR32_TWI_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_TWI_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_TWI_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_TWI_<bitfield>
 - Bitfield offset: AVR32_TWI_<bitfield>_OFFSET
 - Bitfield size:   AVR32_TWI_<bitfield>_SIZE
 - Bitfield values: AVR32_TWI_<bitfield>_<value name>
 - Bitfield values: AVR32_TWI_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_TWI_ARBLST                                            9
#define AVR32_TWI_ARBLST_MASK                              0x00000200
#define AVR32_TWI_ARBLST_OFFSET                                     9
#define AVR32_TWI_ARBLST_SIZE                                       1
#define AVR32_TWI_CHDIV                                             8
#define AVR32_TWI_CHDIV_MASK                               0x0000ff00
#define AVR32_TWI_CHDIV_OFFSET                                      8
#define AVR32_TWI_CHDIV_SIZE                                        8
#define AVR32_TWI_CKDIV                                            16
#define AVR32_TWI_CKDIV_MASK                               0x00070000
#define AVR32_TWI_CKDIV_OFFSET                                     16
#define AVR32_TWI_CKDIV_SIZE                                        3
#define AVR32_TWI_CLDIV                                             0
#define AVR32_TWI_CLDIV_MASK                               0x000000ff
#define AVR32_TWI_CLDIV_OFFSET                                      0
#define AVR32_TWI_CLDIV_SIZE                                        8
#define AVR32_TWI_CR                                       0x00000000
#define AVR32_TWI_CR_MSDIS                                          3
#define AVR32_TWI_CR_MSDIS_MASK                            0x00000008
#define AVR32_TWI_CR_MSDIS_OFFSET                                   3
#define AVR32_TWI_CR_MSDIS_SIZE                                     1
#define AVR32_TWI_CR_MSEN                                           2
#define AVR32_TWI_CR_MSEN_MASK                             0x00000004
#define AVR32_TWI_CR_MSEN_OFFSET                                    2
#define AVR32_TWI_CR_MSEN_SIZE                                      1
#define AVR32_TWI_CR_START                                          0
#define AVR32_TWI_CR_START_MASK                            0x00000001
#define AVR32_TWI_CR_START_OFFSET                                   0
#define AVR32_TWI_CR_START_SIZE                                     1
#define AVR32_TWI_CR_STOP                                           1
#define AVR32_TWI_CR_STOP_MASK                             0x00000002
#define AVR32_TWI_CR_STOP_OFFSET                                    1
#define AVR32_TWI_CR_STOP_SIZE                                      1
#define AVR32_TWI_CR_SVDIS                                          5
#define AVR32_TWI_CR_SVDIS_MASK                            0x00000020
#define AVR32_TWI_CR_SVDIS_OFFSET                                   5
#define AVR32_TWI_CR_SVDIS_SIZE                                     1
#define AVR32_TWI_CR_SVEN                                           4
#define AVR32_TWI_CR_SVEN_MASK                             0x00000010
#define AVR32_TWI_CR_SVEN_OFFSET                                    4
#define AVR32_TWI_CR_SVEN_SIZE                                      1
#define AVR32_TWI_CR_SWRST                                          7
#define AVR32_TWI_CR_SWRST_MASK                            0x00000080
#define AVR32_TWI_CR_SWRST_OFFSET                                   7
#define AVR32_TWI_CR_SWRST_SIZE                                     1
#define AVR32_TWI_CWGR                                     0x00000010
#define AVR32_TWI_CWGR_CHDIV                                        8
#define AVR32_TWI_CWGR_CHDIV_MASK                          0x0000ff00
#define AVR32_TWI_CWGR_CHDIV_OFFSET                                 8
#define AVR32_TWI_CWGR_CHDIV_SIZE                                   8
#define AVR32_TWI_CWGR_CKDIV                                       16
#define AVR32_TWI_CWGR_CKDIV_MASK                          0x00070000
#define AVR32_TWI_CWGR_CKDIV_OFFSET                                16
#define AVR32_TWI_CWGR_CKDIV_SIZE                                   3
#define AVR32_TWI_CWGR_CLDIV                                        0
#define AVR32_TWI_CWGR_CLDIV_MASK                          0x000000ff
#define AVR32_TWI_CWGR_CLDIV_OFFSET                                 0
#define AVR32_TWI_CWGR_CLDIV_SIZE                                   8
#define AVR32_TWI_DADR                                             16
#define AVR32_TWI_DADR_MASK                                0x007f0000
#define AVR32_TWI_DADR_OFFSET                                      16
#define AVR32_TWI_DADR_SIZE                                         7
#define AVR32_TWI_ENDRX                                            12
#define AVR32_TWI_ENDRX_MASK                               0x00001000
#define AVR32_TWI_ENDRX_OFFSET                                     12
#define AVR32_TWI_ENDRX_SIZE                                        1
#define AVR32_TWI_ENDTX                                            13
#define AVR32_TWI_ENDTX_MASK                               0x00002000
#define AVR32_TWI_ENDTX_OFFSET                                     13
#define AVR32_TWI_ENDTX_SIZE                                        1
#define AVR32_TWI_EOSACC                                           11
#define AVR32_TWI_EOSACC_MASK                              0x00000800
#define AVR32_TWI_EOSACC_OFFSET                                    11
#define AVR32_TWI_EOSACC_SIZE                                       1
#define AVR32_TWI_GACC                                              5
#define AVR32_TWI_GACC_MASK                                0x00000020
#define AVR32_TWI_GACC_OFFSET                                       5
#define AVR32_TWI_GACC_SIZE                                         1
#define AVR32_TWI_IADR                                     0x0000000c
#define AVR32_TWI_IADRSZ                                            8
#define AVR32_TWI_IADRSZ_MASK                              0x00000300
#define AVR32_TWI_IADRSZ_NO_ADDR                           0x00000000
#define AVR32_TWI_IADRSZ_OFFSET                                     8
#define AVR32_TWI_IADRSZ_ONE_BYTE                          0x00000001
#define AVR32_TWI_IADRSZ_SIZE                                       2
#define AVR32_TWI_IADRSZ_THREE_BYTES                       0x00000003
#define AVR32_TWI_IADRSZ_TWO_BYTES                         0x00000002
#define AVR32_TWI_IADR_IADR                                         0
#define AVR32_TWI_IADR_IADR_MASK                           0x00ffffff
#define AVR32_TWI_IADR_IADR_OFFSET                                  0
#define AVR32_TWI_IADR_IADR_SIZE                                   24
#define AVR32_TWI_IADR_MASK                                0x00ffffff
#define AVR32_TWI_IADR_OFFSET                                       0
#define AVR32_TWI_IADR_SIZE                                        24
#define AVR32_TWI_IDR                                      0x00000028
#define AVR32_TWI_IDR_ARBLST                                        9
#define AVR32_TWI_IDR_ARBLST_MASK                          0x00000200
#define AVR32_TWI_IDR_ARBLST_OFFSET                                 9
#define AVR32_TWI_IDR_ARBLST_SIZE                                   1
#define AVR32_TWI_IDR_ENDRX                                        12
#define AVR32_TWI_IDR_ENDRX_MASK                           0x00001000
#define AVR32_TWI_IDR_ENDRX_OFFSET                                 12
#define AVR32_TWI_IDR_ENDRX_SIZE                                    1
#define AVR32_TWI_IDR_ENDTX                                        13
#define AVR32_TWI_IDR_ENDTX_MASK                           0x00002000
#define AVR32_TWI_IDR_ENDTX_OFFSET                                 13
#define AVR32_TWI_IDR_ENDTX_SIZE                                    1
#define AVR32_TWI_IDR_EOSACC                                       11
#define AVR32_TWI_IDR_EOSACC_MASK                          0x00000800
#define AVR32_TWI_IDR_EOSACC_OFFSET                                11
#define AVR32_TWI_IDR_EOSACC_SIZE                                   1
#define AVR32_TWI_IDR_GACC                                          5
#define AVR32_TWI_IDR_GACC_MASK                            0x00000020
#define AVR32_TWI_IDR_GACC_OFFSET                                   5
#define AVR32_TWI_IDR_GACC_SIZE                                     1
#define AVR32_TWI_IDR_NACK                                          8
#define AVR32_TWI_IDR_NACK_MASK                            0x00000100
#define AVR32_TWI_IDR_NACK_OFFSET                                   8
#define AVR32_TWI_IDR_NACK_SIZE                                     1
#define AVR32_TWI_IDR_OVRE                                          6
#define AVR32_TWI_IDR_OVRE_MASK                            0x00000040
#define AVR32_TWI_IDR_OVRE_OFFSET                                   6
#define AVR32_TWI_IDR_OVRE_SIZE                                     1
#define AVR32_TWI_IDR_RXBUFF                                       14
#define AVR32_TWI_IDR_RXBUFF_MASK                          0x00004000
#define AVR32_TWI_IDR_RXBUFF_OFFSET                                14
#define AVR32_TWI_IDR_RXBUFF_SIZE                                   1
#define AVR32_TWI_IDR_RXRDY                                         1
#define AVR32_TWI_IDR_RXRDY_MASK                           0x00000002
#define AVR32_TWI_IDR_RXRDY_OFFSET                                  1
#define AVR32_TWI_IDR_RXRDY_SIZE                                    1
#define AVR32_TWI_IDR_SCLWS                                        10
#define AVR32_TWI_IDR_SCLWS_MASK                           0x00000400
#define AVR32_TWI_IDR_SCLWS_OFFSET                                 10
#define AVR32_TWI_IDR_SCLWS_SIZE                                    1
#define AVR32_TWI_IDR_SVACC                                         4
#define AVR32_TWI_IDR_SVACC_MASK                           0x00000010
#define AVR32_TWI_IDR_SVACC_OFFSET                                  4
#define AVR32_TWI_IDR_SVACC_SIZE                                    1
#define AVR32_TWI_IDR_TXBUFE                                       15
#define AVR32_TWI_IDR_TXBUFE_MASK                          0x00008000
#define AVR32_TWI_IDR_TXBUFE_OFFSET                                15
#define AVR32_TWI_IDR_TXBUFE_SIZE                                   1
#define AVR32_TWI_IDR_TXCOMP                                        0
#define AVR32_TWI_IDR_TXCOMP_MASK                          0x00000001
#define AVR32_TWI_IDR_TXCOMP_OFFSET                                 0
#define AVR32_TWI_IDR_TXCOMP_SIZE                                   1
#define AVR32_TWI_IDR_TXRDY                                         2
#define AVR32_TWI_IDR_TXRDY_MASK                           0x00000004
#define AVR32_TWI_IDR_TXRDY_OFFSET                                  2
#define AVR32_TWI_IDR_TXRDY_SIZE                                    1
#define AVR32_TWI_IER                                      0x00000024
#define AVR32_TWI_IER_ARBLST                                        9
#define AVR32_TWI_IER_ARBLST_MASK                          0x00000200
#define AVR32_TWI_IER_ARBLST_OFFSET                                 9
#define AVR32_TWI_IER_ARBLST_SIZE                                   1
#define AVR32_TWI_IER_ENDRX                                        12
#define AVR32_TWI_IER_ENDRX_MASK                           0x00001000
#define AVR32_TWI_IER_ENDRX_OFFSET                                 12
#define AVR32_TWI_IER_ENDRX_SIZE                                    1
#define AVR32_TWI_IER_ENDTX                                        13
#define AVR32_TWI_IER_ENDTX_MASK                           0x00002000
#define AVR32_TWI_IER_ENDTX_OFFSET                                 13
#define AVR32_TWI_IER_ENDTX_SIZE                                    1
#define AVR32_TWI_IER_EOSACC                                       11
#define AVR32_TWI_IER_EOSACC_MASK                          0x00000800
#define AVR32_TWI_IER_EOSACC_OFFSET                                11
#define AVR32_TWI_IER_EOSACC_SIZE                                   1
#define AVR32_TWI_IER_GACC                                          5
#define AVR32_TWI_IER_GACC_MASK                            0x00000020
#define AVR32_TWI_IER_GACC_OFFSET                                   5
#define AVR32_TWI_IER_GACC_SIZE                                     1
#define AVR32_TWI_IER_NACK                                          8
#define AVR32_TWI_IER_NACK_MASK                            0x00000100
#define AVR32_TWI_IER_NACK_OFFSET                                   8
#define AVR32_TWI_IER_NACK_SIZE                                     1
#define AVR32_TWI_IER_OVRE                                          6
#define AVR32_TWI_IER_OVRE_MASK                            0x00000040
#define AVR32_TWI_IER_OVRE_OFFSET                                   6
#define AVR32_TWI_IER_OVRE_SIZE                                     1
#define AVR32_TWI_IER_RXBUFF                                       14
#define AVR32_TWI_IER_RXBUFF_MASK                          0x00004000
#define AVR32_TWI_IER_RXBUFF_OFFSET                                14
#define AVR32_TWI_IER_RXBUFF_SIZE                                   1
#define AVR32_TWI_IER_RXRDY                                         1
#define AVR32_TWI_IER_RXRDY_MASK                           0x00000002
#define AVR32_TWI_IER_RXRDY_OFFSET                                  1
#define AVR32_TWI_IER_RXRDY_SIZE                                    1
#define AVR32_TWI_IER_SCLWS                                        10
#define AVR32_TWI_IER_SCLWS_MASK                           0x00000400
#define AVR32_TWI_IER_SCLWS_OFFSET                                 10
#define AVR32_TWI_IER_SCLWS_SIZE                                    1
#define AVR32_TWI_IER_SVACC                                         4
#define AVR32_TWI_IER_SVACC_MASK                           0x00000010
#define AVR32_TWI_IER_SVACC_OFFSET                                  4
#define AVR32_TWI_IER_SVACC_SIZE                                    1
#define AVR32_TWI_IER_TXBUFE                                       15
#define AVR32_TWI_IER_TXBUFE_MASK                          0x00008000
#define AVR32_TWI_IER_TXBUFE_OFFSET                                15
#define AVR32_TWI_IER_TXBUFE_SIZE                                   1
#define AVR32_TWI_IER_TXCOMP                                        0
#define AVR32_TWI_IER_TXCOMP_MASK                          0x00000001
#define AVR32_TWI_IER_TXCOMP_OFFSET                                 0
#define AVR32_TWI_IER_TXCOMP_SIZE                                   1
#define AVR32_TWI_IER_TXRDY                                         2
#define AVR32_TWI_IER_TXRDY_MASK                           0x00000004
#define AVR32_TWI_IER_TXRDY_OFFSET                                  2
#define AVR32_TWI_IER_TXRDY_SIZE                                    1
#define AVR32_TWI_IMR                                      0x0000002c
#define AVR32_TWI_IMR_ARBLST                                        9
#define AVR32_TWI_IMR_ARBLST_MASK                          0x00000200
#define AVR32_TWI_IMR_ARBLST_OFFSET                                 9
#define AVR32_TWI_IMR_ARBLST_SIZE                                   1
#define AVR32_TWI_IMR_ENDRX                                        12
#define AVR32_TWI_IMR_ENDRX_MASK                           0x00001000
#define AVR32_TWI_IMR_ENDRX_OFFSET                                 12
#define AVR32_TWI_IMR_ENDRX_SIZE                                    1
#define AVR32_TWI_IMR_ENDTX                                        13
#define AVR32_TWI_IMR_ENDTX_MASK                           0x00002000
#define AVR32_TWI_IMR_ENDTX_OFFSET                                 13
#define AVR32_TWI_IMR_ENDTX_SIZE                                    1
#define AVR32_TWI_IMR_EOSACC                                       11
#define AVR32_TWI_IMR_EOSACC_MASK                          0x00000800
#define AVR32_TWI_IMR_EOSACC_OFFSET                                11
#define AVR32_TWI_IMR_EOSACC_SIZE                                   1
#define AVR32_TWI_IMR_GACC                                          5
#define AVR32_TWI_IMR_GACC_MASK                            0x00000020
#define AVR32_TWI_IMR_GACC_OFFSET                                   5
#define AVR32_TWI_IMR_GACC_SIZE                                     1
#define AVR32_TWI_IMR_NACK                                          8
#define AVR32_TWI_IMR_NACK_MASK                            0x00000100
#define AVR32_TWI_IMR_NACK_OFFSET                                   8
#define AVR32_TWI_IMR_NACK_SIZE                                     1
#define AVR32_TWI_IMR_OVRE                                          6
#define AVR32_TWI_IMR_OVRE_MASK                            0x00000040
#define AVR32_TWI_IMR_OVRE_OFFSET                                   6
#define AVR32_TWI_IMR_OVRE_SIZE                                     1
#define AVR32_TWI_IMR_RXBUFF                                       14
#define AVR32_TWI_IMR_RXBUFF_MASK                          0x00004000
#define AVR32_TWI_IMR_RXBUFF_OFFSET                                14
#define AVR32_TWI_IMR_RXBUFF_SIZE                                   1
#define AVR32_TWI_IMR_RXRDY                                         1
#define AVR32_TWI_IMR_RXRDY_MASK                           0x00000002
#define AVR32_TWI_IMR_RXRDY_OFFSET                                  1
#define AVR32_TWI_IMR_RXRDY_SIZE                                    1
#define AVR32_TWI_IMR_SCLWS                                        10
#define AVR32_TWI_IMR_SCLWS_MASK                           0x00000400
#define AVR32_TWI_IMR_SCLWS_OFFSET                                 10
#define AVR32_TWI_IMR_SCLWS_SIZE                                    1
#define AVR32_TWI_IMR_SVACC                                         4
#define AVR32_TWI_IMR_SVACC_MASK                           0x00000010
#define AVR32_TWI_IMR_SVACC_OFFSET                                  4
#define AVR32_TWI_IMR_SVACC_SIZE                                    1
#define AVR32_TWI_IMR_TXBUFE                                       15
#define AVR32_TWI_IMR_TXBUFE_MASK                          0x00008000
#define AVR32_TWI_IMR_TXBUFE_OFFSET                                15
#define AVR32_TWI_IMR_TXBUFE_SIZE                                   1
#define AVR32_TWI_IMR_TXCOMP                                        0
#define AVR32_TWI_IMR_TXCOMP_MASK                          0x00000001
#define AVR32_TWI_IMR_TXCOMP_OFFSET                                 0
#define AVR32_TWI_IMR_TXCOMP_SIZE                                   1
#define AVR32_TWI_IMR_TXRDY                                         2
#define AVR32_TWI_IMR_TXRDY_MASK                           0x00000004
#define AVR32_TWI_IMR_TXRDY_OFFSET                                  2
#define AVR32_TWI_IMR_TXRDY_SIZE                                    1
#define AVR32_TWI_MMR                                      0x00000004
#define AVR32_TWI_MMR_DADR                                         16
#define AVR32_TWI_MMR_DADR_MASK                            0x007f0000
#define AVR32_TWI_MMR_DADR_OFFSET                                  16
#define AVR32_TWI_MMR_DADR_SIZE                                     7
#define AVR32_TWI_MMR_IADRSZ                                        8
#define AVR32_TWI_MMR_IADRSZ_MASK                          0x00000300
#define AVR32_TWI_MMR_IADRSZ_NO_ADDR                       0x00000000
#define AVR32_TWI_MMR_IADRSZ_OFFSET                                 8
#define AVR32_TWI_MMR_IADRSZ_ONE_BYTE                      0x00000001
#define AVR32_TWI_MMR_IADRSZ_SIZE                                   2
#define AVR32_TWI_MMR_IADRSZ_THREE_BYTES                   0x00000003
#define AVR32_TWI_MMR_IADRSZ_TWO_BYTES                     0x00000002
#define AVR32_TWI_MMR_MREAD                                        12
#define AVR32_TWI_MMR_MREAD_MASK                           0x00001000
#define AVR32_TWI_MMR_MREAD_OFFSET                                 12
#define AVR32_TWI_MMR_MREAD_SIZE                                    1
#define AVR32_TWI_MREAD                                            12
#define AVR32_TWI_MREAD_MASK                               0x00001000
#define AVR32_TWI_MREAD_OFFSET                                     12
#define AVR32_TWI_MREAD_SIZE                                        1
#define AVR32_TWI_MSDIS                                             3
#define AVR32_TWI_MSDIS_MASK                               0x00000008
#define AVR32_TWI_MSDIS_OFFSET                                      3
#define AVR32_TWI_MSDIS_SIZE                                        1
#define AVR32_TWI_MSEN                                              2
#define AVR32_TWI_MSEN_MASK                                0x00000004
#define AVR32_TWI_MSEN_OFFSET                                       2
#define AVR32_TWI_MSEN_SIZE                                         1
#define AVR32_TWI_NACK                                              8
#define AVR32_TWI_NACK_MASK                                0x00000100
#define AVR32_TWI_NACK_OFFSET                                       8
#define AVR32_TWI_NACK_SIZE                                         1
#define AVR32_TWI_NO_ADDR                                  0x00000000
#define AVR32_TWI_ONE_BYTE                                 0x00000001
#define AVR32_TWI_OVRE                                              6
#define AVR32_TWI_OVRE_MASK                                0x00000040
#define AVR32_TWI_OVRE_OFFSET                                       6
#define AVR32_TWI_OVRE_SIZE                                         1
#define AVR32_TWI_RHR                                      0x00000030
#define AVR32_TWI_RHR_RXDATA                                        0
#define AVR32_TWI_RHR_RXDATA_MASK                          0x000000ff
#define AVR32_TWI_RHR_RXDATA_OFFSET                                 0
#define AVR32_TWI_RHR_RXDATA_SIZE                                   8
#define AVR32_TWI_RXBUFF                                           14
#define AVR32_TWI_RXBUFF_MASK                              0x00004000
#define AVR32_TWI_RXBUFF_OFFSET                                    14
#define AVR32_TWI_RXBUFF_SIZE                                       1
#define AVR32_TWI_RXDATA                                            0
#define AVR32_TWI_RXDATA_MASK                              0x000000ff
#define AVR32_TWI_RXDATA_OFFSET                                     0
#define AVR32_TWI_RXDATA_SIZE                                       8
#define AVR32_TWI_RXRDY                                             1
#define AVR32_TWI_RXRDY_MASK                               0x00000002
#define AVR32_TWI_RXRDY_OFFSET                                      1
#define AVR32_TWI_RXRDY_SIZE                                        1
#define AVR32_TWI_SADR                                             16
#define AVR32_TWI_SADR_MASK                                0x007f0000
#define AVR32_TWI_SADR_OFFSET                                      16
#define AVR32_TWI_SADR_SIZE                                         7
#define AVR32_TWI_SCLWS                                            10
#define AVR32_TWI_SCLWS_MASK                               0x00000400
#define AVR32_TWI_SCLWS_OFFSET                                     10
#define AVR32_TWI_SCLWS_SIZE                                        1
#define AVR32_TWI_SMR                                      0x00000008
#define AVR32_TWI_SMR_SADR                                         16
#define AVR32_TWI_SMR_SADR_MASK                            0x007f0000
#define AVR32_TWI_SMR_SADR_OFFSET                                  16
#define AVR32_TWI_SMR_SADR_SIZE                                     7
#define AVR32_TWI_SR                                       0x00000020
#define AVR32_TWI_SR_ARBLST                                         9
#define AVR32_TWI_SR_ARBLST_MASK                           0x00000200
#define AVR32_TWI_SR_ARBLST_OFFSET                                  9
#define AVR32_TWI_SR_ARBLST_SIZE                                    1
#define AVR32_TWI_SR_ENDRX                                         12
#define AVR32_TWI_SR_ENDRX_MASK                            0x00001000
#define AVR32_TWI_SR_ENDRX_OFFSET                                  12
#define AVR32_TWI_SR_ENDRX_SIZE                                     1
#define AVR32_TWI_SR_ENDTX                                         13
#define AVR32_TWI_SR_ENDTX_MASK                            0x00002000
#define AVR32_TWI_SR_ENDTX_OFFSET                                  13
#define AVR32_TWI_SR_ENDTX_SIZE                                     1
#define AVR32_TWI_SR_EOSACC                                        11
#define AVR32_TWI_SR_EOSACC_MASK                           0x00000800
#define AVR32_TWI_SR_EOSACC_OFFSET                                 11
#define AVR32_TWI_SR_EOSACC_SIZE                                    1
#define AVR32_TWI_SR_GACC                                           5
#define AVR32_TWI_SR_GACC_MASK                             0x00000020
#define AVR32_TWI_SR_GACC_OFFSET                                    5
#define AVR32_TWI_SR_GACC_SIZE                                      1
#define AVR32_TWI_SR_NACK                                           8
#define AVR32_TWI_SR_NACK_MASK                             0x00000100
#define AVR32_TWI_SR_NACK_OFFSET                                    8
#define AVR32_TWI_SR_NACK_SIZE                                      1
#define AVR32_TWI_SR_OVRE                                           6
#define AVR32_TWI_SR_OVRE_MASK                             0x00000040
#define AVR32_TWI_SR_OVRE_OFFSET                                    6
#define AVR32_TWI_SR_OVRE_SIZE                                      1
#define AVR32_TWI_SR_RXBUFF                                        14
#define AVR32_TWI_SR_RXBUFF_MASK                           0x00004000
#define AVR32_TWI_SR_RXBUFF_OFFSET                                 14
#define AVR32_TWI_SR_RXBUFF_SIZE                                    1
#define AVR32_TWI_SR_RXRDY                                          1
#define AVR32_TWI_SR_RXRDY_MASK                            0x00000002
#define AVR32_TWI_SR_RXRDY_OFFSET                                   1
#define AVR32_TWI_SR_RXRDY_SIZE                                     1
#define AVR32_TWI_SR_SCLWS                                         10
#define AVR32_TWI_SR_SCLWS_MASK                            0x00000400
#define AVR32_TWI_SR_SCLWS_OFFSET                                  10
#define AVR32_TWI_SR_SCLWS_SIZE                                     1
#define AVR32_TWI_SR_SVACC                                          4
#define AVR32_TWI_SR_SVACC_MASK                            0x00000010
#define AVR32_TWI_SR_SVACC_OFFSET                                   4
#define AVR32_TWI_SR_SVACC_SIZE                                     1
#define AVR32_TWI_SR_SVREAD                                         3
#define AVR32_TWI_SR_SVREAD_MASK                           0x00000008
#define AVR32_TWI_SR_SVREAD_OFFSET                                  3
#define AVR32_TWI_SR_SVREAD_SIZE                                    1
#define AVR32_TWI_SR_TXBUFE                                        15
#define AVR32_TWI_SR_TXBUFE_MASK                           0x00008000
#define AVR32_TWI_SR_TXBUFE_OFFSET                                 15
#define AVR32_TWI_SR_TXBUFE_SIZE                                    1
#define AVR32_TWI_SR_TXCOMP                                         0
#define AVR32_TWI_SR_TXCOMP_MASK                           0x00000001
#define AVR32_TWI_SR_TXCOMP_OFFSET                                  0
#define AVR32_TWI_SR_TXCOMP_SIZE                                    1
#define AVR32_TWI_SR_TXRDY                                          2
#define AVR32_TWI_SR_TXRDY_MASK                            0x00000004
#define AVR32_TWI_SR_TXRDY_OFFSET                                   2
#define AVR32_TWI_SR_TXRDY_SIZE                                     1
#define AVR32_TWI_START                                             0
#define AVR32_TWI_START_MASK                               0x00000001
#define AVR32_TWI_START_OFFSET                                      0
#define AVR32_TWI_START_SIZE                                        1
#define AVR32_TWI_STOP                                              1
#define AVR32_TWI_STOP_MASK                                0x00000002
#define AVR32_TWI_STOP_OFFSET                                       1
#define AVR32_TWI_STOP_SIZE                                         1
#define AVR32_TWI_SVACC                                             4
#define AVR32_TWI_SVACC_MASK                               0x00000010
#define AVR32_TWI_SVACC_OFFSET                                      4
#define AVR32_TWI_SVACC_SIZE                                        1
#define AVR32_TWI_SVDIS                                             5
#define AVR32_TWI_SVDIS_MASK                               0x00000020
#define AVR32_TWI_SVDIS_OFFSET                                      5
#define AVR32_TWI_SVDIS_SIZE                                        1
#define AVR32_TWI_SVEN                                              4
#define AVR32_TWI_SVEN_MASK                                0x00000010
#define AVR32_TWI_SVEN_OFFSET                                       4
#define AVR32_TWI_SVEN_SIZE                                         1
#define AVR32_TWI_SVREAD                                            3
#define AVR32_TWI_SVREAD_MASK                              0x00000008
#define AVR32_TWI_SVREAD_OFFSET                                     3
#define AVR32_TWI_SVREAD_SIZE                                       1
#define AVR32_TWI_SWRST                                             7
#define AVR32_TWI_SWRST_MASK                               0x00000080
#define AVR32_TWI_SWRST_OFFSET                                      7
#define AVR32_TWI_SWRST_SIZE                                        1
#define AVR32_TWI_THR                                      0x00000034
#define AVR32_TWI_THREE_BYTES                              0x00000003
#define AVR32_TWI_THR_TXDATA                                        0
#define AVR32_TWI_THR_TXDATA_MASK                          0x000000ff
#define AVR32_TWI_THR_TXDATA_OFFSET                                 0
#define AVR32_TWI_THR_TXDATA_SIZE                                   8
#define AVR32_TWI_TWO_BYTES                                0x00000002
#define AVR32_TWI_TXBUFE                                           15
#define AVR32_TWI_TXBUFE_MASK                              0x00008000
#define AVR32_TWI_TXBUFE_OFFSET                                    15
#define AVR32_TWI_TXBUFE_SIZE                                       1
#define AVR32_TWI_TXCOMP                                            0
#define AVR32_TWI_TXCOMP_MASK                              0x00000001
#define AVR32_TWI_TXCOMP_OFFSET                                     0
#define AVR32_TWI_TXCOMP_SIZE                                       1
#define AVR32_TWI_TXDATA                                            0
#define AVR32_TWI_TXDATA_MASK                              0x000000ff
#define AVR32_TWI_TXDATA_OFFSET                                     0
#define AVR32_TWI_TXDATA_SIZE                                       8
#define AVR32_TWI_TXRDY                                             2
#define AVR32_TWI_TXRDY_MASK                               0x00000004
#define AVR32_TWI_TXRDY_OFFSET                                      2
#define AVR32_TWI_TXRDY_SIZE                                        1




#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_twi_cr_t {
    unsigned int                 :24;
    unsigned int swrst           : 1;
    unsigned int                 : 1;
    unsigned int svdis           : 1;
    unsigned int sven            : 1;
    unsigned int msdis           : 1;
    unsigned int msen            : 1;
    unsigned int stop            : 1;
    unsigned int start           : 1;
} avr32_twi_cr_t;



typedef struct avr32_twi_mmr_t {
    unsigned int                 : 9;
    unsigned int dadr            : 7;
    unsigned int                 : 3;
    unsigned int mread           : 1;
    unsigned int                 : 2;
    unsigned int iadrsz          : 2;
    unsigned int                 : 8;
} avr32_twi_mmr_t;



typedef struct avr32_twi_smr_t {
    unsigned int                 : 9;
    unsigned int sadr            : 7;
    unsigned int                 :16;
} avr32_twi_smr_t;



typedef struct avr32_twi_iadr_t {
    unsigned int                 : 8;
    unsigned int iadr            :24;
} avr32_twi_iadr_t;



typedef struct avr32_twi_cwgr_t {
    unsigned int                 :13;
    unsigned int ckdiv           : 3;
    unsigned int chdiv           : 8;
    unsigned int cldiv           : 8;
} avr32_twi_cwgr_t;



typedef struct avr32_twi_sr_t {
    unsigned int                 :16;
    unsigned int txbufe          : 1;
    unsigned int rxbuff          : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int eosacc          : 1;
    unsigned int sclws           : 1;
    unsigned int arblst          : 1;
    unsigned int nack            : 1;
    unsigned int                 : 1;
    unsigned int ovre            : 1;
    unsigned int gacc            : 1;
    unsigned int svacc           : 1;
    unsigned int svread          : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
    unsigned int txcomp          : 1;
} avr32_twi_sr_t;



typedef struct avr32_twi_ier_t {
    unsigned int                 :16;
    unsigned int txbufe          : 1;
    unsigned int rxbuff          : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int eosacc          : 1;
    unsigned int sclws           : 1;
    unsigned int arblst          : 1;
    unsigned int nack            : 1;
    unsigned int                 : 1;
    unsigned int ovre            : 1;
    unsigned int gacc            : 1;
    unsigned int svacc           : 1;
    unsigned int                 : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
    unsigned int txcomp          : 1;
} avr32_twi_ier_t;



typedef struct avr32_twi_idr_t {
    unsigned int                 :16;
    unsigned int txbufe          : 1;
    unsigned int rxbuff          : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int eosacc          : 1;
    unsigned int sclws           : 1;
    unsigned int arblst          : 1;
    unsigned int nack            : 1;
    unsigned int                 : 1;
    unsigned int ovre            : 1;
    unsigned int gacc            : 1;
    unsigned int svacc           : 1;
    unsigned int                 : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
    unsigned int txcomp          : 1;
} avr32_twi_idr_t;



typedef struct avr32_twi_imr_t {
    unsigned int                 :16;
    unsigned int txbufe          : 1;
    unsigned int rxbuff          : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int eosacc          : 1;
    unsigned int sclws           : 1;
    unsigned int arblst          : 1;
    unsigned int nack            : 1;
    unsigned int                 : 1;
    unsigned int ovre            : 1;
    unsigned int gacc            : 1;
    unsigned int svacc           : 1;
    unsigned int                 : 1;
    unsigned int txrdy           : 1;
    unsigned int rxrdy           : 1;
    unsigned int txcomp          : 1;
} avr32_twi_imr_t;



typedef struct avr32_twi_rhr_t {
    unsigned int                 :24;
    unsigned int rxdata          : 8;
} avr32_twi_rhr_t;



typedef struct avr32_twi_thr_t {
    unsigned int                 :24;
    unsigned int txdata          : 8;
} avr32_twi_thr_t;



typedef struct avr32_twi_t {
  union {
          unsigned long                  cr        ;//0x0000
          avr32_twi_cr_t                 CR        ;
  };
  union {
          unsigned long                  mmr       ;//0x0004
          avr32_twi_mmr_t                MMR       ;
  };
  union {
          unsigned long                  smr       ;//0x0008
          avr32_twi_smr_t                SMR       ;
  };
  union {
          unsigned long                  iadr      ;//0x000c
          avr32_twi_iadr_t               IADR      ;
  };
  union {
          unsigned long                  cwgr      ;//0x0010
          avr32_twi_cwgr_t               CWGR      ;
  };
          unsigned int                   :32       ;//0x0014
          unsigned int                   :32       ;//0x0018
          unsigned int                   :32       ;//0x001c
  union {
    const unsigned long                  sr        ;//0x0020
    const avr32_twi_sr_t                 SR        ;
  };
  union {
          unsigned long                  ier       ;//0x0024
          avr32_twi_ier_t                IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0028
          avr32_twi_idr_t                IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x002c
    const avr32_twi_imr_t                IMR       ;
  };
  union {
    const unsigned long                  rhr       ;//0x0030
    const avr32_twi_rhr_t                RHR       ;
  };
  union {
          unsigned long                  thr       ;//0x0034
          avr32_twi_thr_t                THR       ;
  };
} avr32_twi_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif

/*#ifdef AVR32_TWI_211_H_INCLUDED*/
#endif

