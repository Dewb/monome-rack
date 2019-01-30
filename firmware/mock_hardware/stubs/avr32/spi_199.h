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
#ifndef AVR32_SPI_199_H_INCLUDED
#define AVR32_SPI_199_H_INCLUDED

#define AVR32_SPI_H_VERSION 199

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_SPI_<register>
 - Bitfield mask:   AVR32_SPI_<register>_<bitfield>
 - Bitfield offset: AVR32_SPI_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_SPI_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_SPI_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_SPI_<bitfield>
 - Bitfield offset: AVR32_SPI_<bitfield>_OFFSET
 - Bitfield size:   AVR32_SPI_<bitfield>_SIZE
 - Bitfield values: AVR32_SPI_<bitfield>_<value name>
 - Bitfield values: AVR32_SPI_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_SPI_10_BPT                                   0x00000002
#define AVR32_SPI_11_BPT                                   0x00000003
#define AVR32_SPI_12_BPT                                   0x00000004
#define AVR32_SPI_13_BPT                                   0x00000005
#define AVR32_SPI_14_BPT                                   0x00000006
#define AVR32_SPI_15_BPT                                   0x00000007
#define AVR32_SPI_16_BPT                                   0x00000008
#define AVR32_SPI_8_BPT                                    0x00000000
#define AVR32_SPI_9_BPT                                    0x00000001
#define AVR32_SPI_BITS                                              4
#define AVR32_SPI_BITS_10_BPT                              0x00000002
#define AVR32_SPI_BITS_11_BPT                              0x00000003
#define AVR32_SPI_BITS_12_BPT                              0x00000004
#define AVR32_SPI_BITS_13_BPT                              0x00000005
#define AVR32_SPI_BITS_14_BPT                              0x00000006
#define AVR32_SPI_BITS_15_BPT                              0x00000007
#define AVR32_SPI_BITS_16_BPT                              0x00000008
#define AVR32_SPI_BITS_8_BPT                               0x00000000
#define AVR32_SPI_BITS_9_BPT                               0x00000001
#define AVR32_SPI_BITS_MASK                                0x000000f0
#define AVR32_SPI_BITS_OFFSET                                       4
#define AVR32_SPI_BITS_SIZE                                         4
#define AVR32_SPI_CPOL                                              0
#define AVR32_SPI_CPOL_MASK                                0x00000001
#define AVR32_SPI_CPOL_OFFSET                                       0
#define AVR32_SPI_CPOL_SIZE                                         1
#define AVR32_SPI_CR                                       0x00000000
#define AVR32_SPI_CR_LASTXFER                                      24
#define AVR32_SPI_CR_LASTXFER_MASK                         0x01000000
#define AVR32_SPI_CR_LASTXFER_OFFSET                               24
#define AVR32_SPI_CR_LASTXFER_SIZE                                  1
#define AVR32_SPI_CR_SPIDIS                                         1
#define AVR32_SPI_CR_SPIDIS_MASK                           0x00000002
#define AVR32_SPI_CR_SPIDIS_OFFSET                                  1
#define AVR32_SPI_CR_SPIDIS_SIZE                                    1
#define AVR32_SPI_CR_SPIEN                                          0
#define AVR32_SPI_CR_SPIEN_MASK                            0x00000001
#define AVR32_SPI_CR_SPIEN_OFFSET                                   0
#define AVR32_SPI_CR_SPIEN_SIZE                                     1
#define AVR32_SPI_CR_SWRST                                          7
#define AVR32_SPI_CR_SWRST_MASK                            0x00000080
#define AVR32_SPI_CR_SWRST_OFFSET                                   7
#define AVR32_SPI_CR_SWRST_SIZE                                     1
#define AVR32_SPI_CSAAT                                             3
#define AVR32_SPI_CSAAT_MASK                               0x00000008
#define AVR32_SPI_CSAAT_OFFSET                                      3
#define AVR32_SPI_CSAAT_SIZE                                        1
#define AVR32_SPI_CSNAAT                                            2
#define AVR32_SPI_CSNAAT_MASK                              0x00000004
#define AVR32_SPI_CSNAAT_OFFSET                                     2
#define AVR32_SPI_CSNAAT_SIZE                                       1
#define AVR32_SPI_CSR0                                     0x00000030
#define AVR32_SPI_CSR0_BITS                                         4
#define AVR32_SPI_CSR0_BITS_10_BPT                         0x00000002
#define AVR32_SPI_CSR0_BITS_11_BPT                         0x00000003
#define AVR32_SPI_CSR0_BITS_12_BPT                         0x00000004
#define AVR32_SPI_CSR0_BITS_13_BPT                         0x00000005
#define AVR32_SPI_CSR0_BITS_14_BPT                         0x00000006
#define AVR32_SPI_CSR0_BITS_15_BPT                         0x00000007
#define AVR32_SPI_CSR0_BITS_16_BPT                         0x00000008
#define AVR32_SPI_CSR0_BITS_8_BPT                          0x00000000
#define AVR32_SPI_CSR0_BITS_9_BPT                          0x00000001
#define AVR32_SPI_CSR0_BITS_MASK                           0x000000f0
#define AVR32_SPI_CSR0_BITS_OFFSET                                  4
#define AVR32_SPI_CSR0_BITS_SIZE                                    4
#define AVR32_SPI_CSR0_CPOL                                         0
#define AVR32_SPI_CSR0_CPOL_MASK                           0x00000001
#define AVR32_SPI_CSR0_CPOL_OFFSET                                  0
#define AVR32_SPI_CSR0_CPOL_SIZE                                    1
#define AVR32_SPI_CSR0_CSAAT                                        3
#define AVR32_SPI_CSR0_CSAAT_MASK                          0x00000008
#define AVR32_SPI_CSR0_CSAAT_OFFSET                                 3
#define AVR32_SPI_CSR0_CSAAT_SIZE                                   1
#define AVR32_SPI_CSR0_CSNAAT                                       2
#define AVR32_SPI_CSR0_CSNAAT_MASK                         0x00000004
#define AVR32_SPI_CSR0_CSNAAT_OFFSET                                2
#define AVR32_SPI_CSR0_CSNAAT_SIZE                                  1
#define AVR32_SPI_CSR0_DLYBCT                                      24
#define AVR32_SPI_CSR0_DLYBCT_MASK                         0xff000000
#define AVR32_SPI_CSR0_DLYBCT_OFFSET                               24
#define AVR32_SPI_CSR0_DLYBCT_SIZE                                  8
#define AVR32_SPI_CSR0_DLYBS                                       16
#define AVR32_SPI_CSR0_DLYBS_MASK                          0x00ff0000
#define AVR32_SPI_CSR0_DLYBS_OFFSET                                16
#define AVR32_SPI_CSR0_DLYBS_SIZE                                   8
#define AVR32_SPI_CSR0_NCPHA                                        1
#define AVR32_SPI_CSR0_NCPHA_MASK                          0x00000002
#define AVR32_SPI_CSR0_NCPHA_OFFSET                                 1
#define AVR32_SPI_CSR0_NCPHA_SIZE                                   1
#define AVR32_SPI_CSR0_SCBR                                         8
#define AVR32_SPI_CSR0_SCBR_MASK                           0x0000ff00
#define AVR32_SPI_CSR0_SCBR_OFFSET                                  8
#define AVR32_SPI_CSR0_SCBR_SIZE                                    8
#define AVR32_SPI_CSR1                                     0x00000034
#define AVR32_SPI_CSR1_BITS                                         4
#define AVR32_SPI_CSR1_BITS_10_BPT                         0x00000002
#define AVR32_SPI_CSR1_BITS_11_BPT                         0x00000003
#define AVR32_SPI_CSR1_BITS_12_BPT                         0x00000004
#define AVR32_SPI_CSR1_BITS_13_BPT                         0x00000005
#define AVR32_SPI_CSR1_BITS_14_BPT                         0x00000006
#define AVR32_SPI_CSR1_BITS_15_BPT                         0x00000007
#define AVR32_SPI_CSR1_BITS_16_BPT                         0x00000008
#define AVR32_SPI_CSR1_BITS_8_BPT                          0x00000000
#define AVR32_SPI_CSR1_BITS_9_BPT                          0x00000001
#define AVR32_SPI_CSR1_BITS_MASK                           0x000000f0
#define AVR32_SPI_CSR1_BITS_OFFSET                                  4
#define AVR32_SPI_CSR1_BITS_SIZE                                    4
#define AVR32_SPI_CSR1_CPOL                                         0
#define AVR32_SPI_CSR1_CPOL_MASK                           0x00000001
#define AVR32_SPI_CSR1_CPOL_OFFSET                                  0
#define AVR32_SPI_CSR1_CPOL_SIZE                                    1
#define AVR32_SPI_CSR1_CSAAT                                        3
#define AVR32_SPI_CSR1_CSAAT_MASK                          0x00000008
#define AVR32_SPI_CSR1_CSAAT_OFFSET                                 3
#define AVR32_SPI_CSR1_CSAAT_SIZE                                   1
#define AVR32_SPI_CSR1_CSNAAT                                       2
#define AVR32_SPI_CSR1_CSNAAT_MASK                         0x00000004
#define AVR32_SPI_CSR1_CSNAAT_OFFSET                                2
#define AVR32_SPI_CSR1_CSNAAT_SIZE                                  1
#define AVR32_SPI_CSR1_DLYBCT                                      24
#define AVR32_SPI_CSR1_DLYBCT_MASK                         0xff000000
#define AVR32_SPI_CSR1_DLYBCT_OFFSET                               24
#define AVR32_SPI_CSR1_DLYBCT_SIZE                                  8
#define AVR32_SPI_CSR1_DLYBS                                       16
#define AVR32_SPI_CSR1_DLYBS_MASK                          0x00ff0000
#define AVR32_SPI_CSR1_DLYBS_OFFSET                                16
#define AVR32_SPI_CSR1_DLYBS_SIZE                                   8
#define AVR32_SPI_CSR1_NCPHA                                        1
#define AVR32_SPI_CSR1_NCPHA_MASK                          0x00000002
#define AVR32_SPI_CSR1_NCPHA_OFFSET                                 1
#define AVR32_SPI_CSR1_NCPHA_SIZE                                   1
#define AVR32_SPI_CSR1_SCBR                                         8
#define AVR32_SPI_CSR1_SCBR_MASK                           0x0000ff00
#define AVR32_SPI_CSR1_SCBR_OFFSET                                  8
#define AVR32_SPI_CSR1_SCBR_SIZE                                    8
#define AVR32_SPI_CSR2                                     0x00000038
#define AVR32_SPI_CSR2_BITS                                         4
#define AVR32_SPI_CSR2_BITS_10_BPT                         0x00000002
#define AVR32_SPI_CSR2_BITS_11_BPT                         0x00000003
#define AVR32_SPI_CSR2_BITS_12_BPT                         0x00000004
#define AVR32_SPI_CSR2_BITS_13_BPT                         0x00000005
#define AVR32_SPI_CSR2_BITS_14_BPT                         0x00000006
#define AVR32_SPI_CSR2_BITS_15_BPT                         0x00000007
#define AVR32_SPI_CSR2_BITS_16_BPT                         0x00000008
#define AVR32_SPI_CSR2_BITS_8_BPT                          0x00000000
#define AVR32_SPI_CSR2_BITS_9_BPT                          0x00000001
#define AVR32_SPI_CSR2_BITS_MASK                           0x000000f0
#define AVR32_SPI_CSR2_BITS_OFFSET                                  4
#define AVR32_SPI_CSR2_BITS_SIZE                                    4
#define AVR32_SPI_CSR2_CPOL                                         0
#define AVR32_SPI_CSR2_CPOL_MASK                           0x00000001
#define AVR32_SPI_CSR2_CPOL_OFFSET                                  0
#define AVR32_SPI_CSR2_CPOL_SIZE                                    1
#define AVR32_SPI_CSR2_CSAAT                                        3
#define AVR32_SPI_CSR2_CSAAT_MASK                          0x00000008
#define AVR32_SPI_CSR2_CSAAT_OFFSET                                 3
#define AVR32_SPI_CSR2_CSAAT_SIZE                                   1
#define AVR32_SPI_CSR2_CSNAAT                                       2
#define AVR32_SPI_CSR2_CSNAAT_MASK                         0x00000004
#define AVR32_SPI_CSR2_CSNAAT_OFFSET                                2
#define AVR32_SPI_CSR2_CSNAAT_SIZE                                  1
#define AVR32_SPI_CSR2_DLYBCT                                      24
#define AVR32_SPI_CSR2_DLYBCT_MASK                         0xff000000
#define AVR32_SPI_CSR2_DLYBCT_OFFSET                               24
#define AVR32_SPI_CSR2_DLYBCT_SIZE                                  8
#define AVR32_SPI_CSR2_DLYBS                                       16
#define AVR32_SPI_CSR2_DLYBS_MASK                          0x00ff0000
#define AVR32_SPI_CSR2_DLYBS_OFFSET                                16
#define AVR32_SPI_CSR2_DLYBS_SIZE                                   8
#define AVR32_SPI_CSR2_NCPHA                                        1
#define AVR32_SPI_CSR2_NCPHA_MASK                          0x00000002
#define AVR32_SPI_CSR2_NCPHA_OFFSET                                 1
#define AVR32_SPI_CSR2_NCPHA_SIZE                                   1
#define AVR32_SPI_CSR2_SCBR                                         8
#define AVR32_SPI_CSR2_SCBR_MASK                           0x0000ff00
#define AVR32_SPI_CSR2_SCBR_OFFSET                                  8
#define AVR32_SPI_CSR2_SCBR_SIZE                                    8
#define AVR32_SPI_CSR3                                     0x0000003c
#define AVR32_SPI_CSR3_BITS                                         4
#define AVR32_SPI_CSR3_BITS_10_BPT                         0x00000002
#define AVR32_SPI_CSR3_BITS_11_BPT                         0x00000003
#define AVR32_SPI_CSR3_BITS_12_BPT                         0x00000004
#define AVR32_SPI_CSR3_BITS_13_BPT                         0x00000005
#define AVR32_SPI_CSR3_BITS_14_BPT                         0x00000006
#define AVR32_SPI_CSR3_BITS_15_BPT                         0x00000007
#define AVR32_SPI_CSR3_BITS_16_BPT                         0x00000008
#define AVR32_SPI_CSR3_BITS_8_BPT                          0x00000000
#define AVR32_SPI_CSR3_BITS_9_BPT                          0x00000001
#define AVR32_SPI_CSR3_BITS_MASK                           0x000000f0
#define AVR32_SPI_CSR3_BITS_OFFSET                                  4
#define AVR32_SPI_CSR3_BITS_SIZE                                    4
#define AVR32_SPI_CSR3_CPOL                                         0
#define AVR32_SPI_CSR3_CPOL_MASK                           0x00000001
#define AVR32_SPI_CSR3_CPOL_OFFSET                                  0
#define AVR32_SPI_CSR3_CPOL_SIZE                                    1
#define AVR32_SPI_CSR3_CSAAT                                        3
#define AVR32_SPI_CSR3_CSAAT_MASK                          0x00000008
#define AVR32_SPI_CSR3_CSAAT_OFFSET                                 3
#define AVR32_SPI_CSR3_CSAAT_SIZE                                   1
#define AVR32_SPI_CSR3_CSNAAT                                       2
#define AVR32_SPI_CSR3_CSNAAT_MASK                         0x00000004
#define AVR32_SPI_CSR3_CSNAAT_OFFSET                                2
#define AVR32_SPI_CSR3_CSNAAT_SIZE                                  1
#define AVR32_SPI_CSR3_DLYBCT                                      24
#define AVR32_SPI_CSR3_DLYBCT_MASK                         0xff000000
#define AVR32_SPI_CSR3_DLYBCT_OFFSET                               24
#define AVR32_SPI_CSR3_DLYBCT_SIZE                                  8
#define AVR32_SPI_CSR3_DLYBS                                       16
#define AVR32_SPI_CSR3_DLYBS_MASK                          0x00ff0000
#define AVR32_SPI_CSR3_DLYBS_OFFSET                                16
#define AVR32_SPI_CSR3_DLYBS_SIZE                                   8
#define AVR32_SPI_CSR3_NCPHA                                        1
#define AVR32_SPI_CSR3_NCPHA_MASK                          0x00000002
#define AVR32_SPI_CSR3_NCPHA_OFFSET                                 1
#define AVR32_SPI_CSR3_NCPHA_SIZE                                   1
#define AVR32_SPI_CSR3_SCBR                                         8
#define AVR32_SPI_CSR3_SCBR_MASK                           0x0000ff00
#define AVR32_SPI_CSR3_SCBR_OFFSET                                  8
#define AVR32_SPI_CSR3_SCBR_SIZE                                    8
#define AVR32_SPI_DLYBCS                                           24
#define AVR32_SPI_DLYBCS_MASK                              0xff000000
#define AVR32_SPI_DLYBCS_OFFSET                                    24
#define AVR32_SPI_DLYBCS_SIZE                                       8
#define AVR32_SPI_DLYBCT                                           24
#define AVR32_SPI_DLYBCT_MASK                              0xff000000
#define AVR32_SPI_DLYBCT_OFFSET                                    24
#define AVR32_SPI_DLYBCT_SIZE                                       8
#define AVR32_SPI_DLYBS                                            16
#define AVR32_SPI_DLYBS_MASK                               0x00ff0000
#define AVR32_SPI_DLYBS_OFFSET                                     16
#define AVR32_SPI_DLYBS_SIZE                                        8
#define AVR32_SPI_ENDRX                                             4
#define AVR32_SPI_ENDRX_MASK                               0x00000010
#define AVR32_SPI_ENDRX_OFFSET                                      4
#define AVR32_SPI_ENDRX_SIZE                                        1
#define AVR32_SPI_ENDTX                                             5
#define AVR32_SPI_ENDTX_MASK                               0x00000020
#define AVR32_SPI_ENDTX_OFFSET                                      5
#define AVR32_SPI_ENDTX_SIZE                                        1
#define AVR32_SPI_IDR                                      0x00000018
#define AVR32_SPI_IDR_ENDRX                                         4
#define AVR32_SPI_IDR_ENDRX_MASK                           0x00000010
#define AVR32_SPI_IDR_ENDRX_OFFSET                                  4
#define AVR32_SPI_IDR_ENDRX_SIZE                                    1
#define AVR32_SPI_IDR_ENDTX                                         5
#define AVR32_SPI_IDR_ENDTX_MASK                           0x00000020
#define AVR32_SPI_IDR_ENDTX_OFFSET                                  5
#define AVR32_SPI_IDR_ENDTX_SIZE                                    1
#define AVR32_SPI_IDR_MODF                                          2
#define AVR32_SPI_IDR_MODF_MASK                            0x00000004
#define AVR32_SPI_IDR_MODF_OFFSET                                   2
#define AVR32_SPI_IDR_MODF_SIZE                                     1
#define AVR32_SPI_IDR_NSSR                                          8
#define AVR32_SPI_IDR_NSSR_MASK                            0x00000100
#define AVR32_SPI_IDR_NSSR_OFFSET                                   8
#define AVR32_SPI_IDR_NSSR_SIZE                                     1
#define AVR32_SPI_IDR_OVRES                                         3
#define AVR32_SPI_IDR_OVRES_MASK                           0x00000008
#define AVR32_SPI_IDR_OVRES_OFFSET                                  3
#define AVR32_SPI_IDR_OVRES_SIZE                                    1
#define AVR32_SPI_IDR_RDRF                                          0
#define AVR32_SPI_IDR_RDRF_MASK                            0x00000001
#define AVR32_SPI_IDR_RDRF_OFFSET                                   0
#define AVR32_SPI_IDR_RDRF_SIZE                                     1
#define AVR32_SPI_IDR_RXBUFF                                        6
#define AVR32_SPI_IDR_RXBUFF_MASK                          0x00000040
#define AVR32_SPI_IDR_RXBUFF_OFFSET                                 6
#define AVR32_SPI_IDR_RXBUFF_SIZE                                   1
#define AVR32_SPI_IDR_TDRE                                          1
#define AVR32_SPI_IDR_TDRE_MASK                            0x00000002
#define AVR32_SPI_IDR_TDRE_OFFSET                                   1
#define AVR32_SPI_IDR_TDRE_SIZE                                     1
#define AVR32_SPI_IDR_TXBUFE                                        7
#define AVR32_SPI_IDR_TXBUFE_MASK                          0x00000080
#define AVR32_SPI_IDR_TXBUFE_OFFSET                                 7
#define AVR32_SPI_IDR_TXBUFE_SIZE                                   1
#define AVR32_SPI_IDR_TXEMPTY                                       9
#define AVR32_SPI_IDR_TXEMPTY_MASK                         0x00000200
#define AVR32_SPI_IDR_TXEMPTY_OFFSET                                9
#define AVR32_SPI_IDR_TXEMPTY_SIZE                                  1
#define AVR32_SPI_IER                                      0x00000014
#define AVR32_SPI_IER_ENDRX                                         4
#define AVR32_SPI_IER_ENDRX_MASK                           0x00000010
#define AVR32_SPI_IER_ENDRX_OFFSET                                  4
#define AVR32_SPI_IER_ENDRX_SIZE                                    1
#define AVR32_SPI_IER_ENDTX                                         5
#define AVR32_SPI_IER_ENDTX_MASK                           0x00000020
#define AVR32_SPI_IER_ENDTX_OFFSET                                  5
#define AVR32_SPI_IER_ENDTX_SIZE                                    1
#define AVR32_SPI_IER_MODF                                          2
#define AVR32_SPI_IER_MODF_MASK                            0x00000004
#define AVR32_SPI_IER_MODF_OFFSET                                   2
#define AVR32_SPI_IER_MODF_SIZE                                     1
#define AVR32_SPI_IER_NSSR                                          8
#define AVR32_SPI_IER_NSSR_MASK                            0x00000100
#define AVR32_SPI_IER_NSSR_OFFSET                                   8
#define AVR32_SPI_IER_NSSR_SIZE                                     1
#define AVR32_SPI_IER_OVRES                                         3
#define AVR32_SPI_IER_OVRES_MASK                           0x00000008
#define AVR32_SPI_IER_OVRES_OFFSET                                  3
#define AVR32_SPI_IER_OVRES_SIZE                                    1
#define AVR32_SPI_IER_RDRF                                          0
#define AVR32_SPI_IER_RDRF_MASK                            0x00000001
#define AVR32_SPI_IER_RDRF_OFFSET                                   0
#define AVR32_SPI_IER_RDRF_SIZE                                     1
#define AVR32_SPI_IER_RXBUFF                                        6
#define AVR32_SPI_IER_RXBUFF_MASK                          0x00000040
#define AVR32_SPI_IER_RXBUFF_OFFSET                                 6
#define AVR32_SPI_IER_RXBUFF_SIZE                                   1
#define AVR32_SPI_IER_TDRE                                          1
#define AVR32_SPI_IER_TDRE_MASK                            0x00000002
#define AVR32_SPI_IER_TDRE_OFFSET                                   1
#define AVR32_SPI_IER_TDRE_SIZE                                     1
#define AVR32_SPI_IER_TXBUFE                                        7
#define AVR32_SPI_IER_TXBUFE_MASK                          0x00000080
#define AVR32_SPI_IER_TXBUFE_OFFSET                                 7
#define AVR32_SPI_IER_TXBUFE_SIZE                                   1
#define AVR32_SPI_IER_TXEMPTY                                       9
#define AVR32_SPI_IER_TXEMPTY_MASK                         0x00000200
#define AVR32_SPI_IER_TXEMPTY_OFFSET                                9
#define AVR32_SPI_IER_TXEMPTY_SIZE                                  1
#define AVR32_SPI_IMR                                      0x0000001c
#define AVR32_SPI_IMR_ENDRX                                         4
#define AVR32_SPI_IMR_ENDRX_MASK                           0x00000010
#define AVR32_SPI_IMR_ENDRX_OFFSET                                  4
#define AVR32_SPI_IMR_ENDRX_SIZE                                    1
#define AVR32_SPI_IMR_ENDTX                                         5
#define AVR32_SPI_IMR_ENDTX_MASK                           0x00000020
#define AVR32_SPI_IMR_ENDTX_OFFSET                                  5
#define AVR32_SPI_IMR_ENDTX_SIZE                                    1
#define AVR32_SPI_IMR_MODF                                          2
#define AVR32_SPI_IMR_MODF_MASK                            0x00000004
#define AVR32_SPI_IMR_MODF_OFFSET                                   2
#define AVR32_SPI_IMR_MODF_SIZE                                     1
#define AVR32_SPI_IMR_NSSR                                          8
#define AVR32_SPI_IMR_NSSR_MASK                            0x00000100
#define AVR32_SPI_IMR_NSSR_OFFSET                                   8
#define AVR32_SPI_IMR_NSSR_SIZE                                     1
#define AVR32_SPI_IMR_OVRES                                         3
#define AVR32_SPI_IMR_OVRES_MASK                           0x00000008
#define AVR32_SPI_IMR_OVRES_OFFSET                                  3
#define AVR32_SPI_IMR_OVRES_SIZE                                    1
#define AVR32_SPI_IMR_RDRF                                          0
#define AVR32_SPI_IMR_RDRF_MASK                            0x00000001
#define AVR32_SPI_IMR_RDRF_OFFSET                                   0
#define AVR32_SPI_IMR_RDRF_SIZE                                     1
#define AVR32_SPI_IMR_RXBUFF                                        6
#define AVR32_SPI_IMR_RXBUFF_MASK                          0x00000040
#define AVR32_SPI_IMR_RXBUFF_OFFSET                                 6
#define AVR32_SPI_IMR_RXBUFF_SIZE                                   1
#define AVR32_SPI_IMR_TDRE                                          1
#define AVR32_SPI_IMR_TDRE_MASK                            0x00000002
#define AVR32_SPI_IMR_TDRE_OFFSET                                   1
#define AVR32_SPI_IMR_TDRE_SIZE                                     1
#define AVR32_SPI_IMR_TXBUFE                                        7
#define AVR32_SPI_IMR_TXBUFE_MASK                          0x00000080
#define AVR32_SPI_IMR_TXBUFE_OFFSET                                 7
#define AVR32_SPI_IMR_TXBUFE_SIZE                                   1
#define AVR32_SPI_IMR_TXEMPTY                                       9
#define AVR32_SPI_IMR_TXEMPTY_MASK                         0x00000200
#define AVR32_SPI_IMR_TXEMPTY_OFFSET                                9
#define AVR32_SPI_IMR_TXEMPTY_SIZE                                  1
#define AVR32_SPI_LASTXFER                                         24
#define AVR32_SPI_LASTXFER_MASK                            0x01000000
#define AVR32_SPI_LASTXFER_OFFSET                                  24
#define AVR32_SPI_LASTXFER_SIZE                                     1
#define AVR32_SPI_LLB                                               7
#define AVR32_SPI_LLB_MASK                                 0x00000080
#define AVR32_SPI_LLB_OFFSET                                        7
#define AVR32_SPI_LLB_SIZE                                          1
#define AVR32_SPI_MODF                                              2
#define AVR32_SPI_MODFDIS                                           4
#define AVR32_SPI_MODFDIS_MASK                             0x00000010
#define AVR32_SPI_MODFDIS_OFFSET                                    4
#define AVR32_SPI_MODFDIS_SIZE                                      1
#define AVR32_SPI_MODF_MASK                                0x00000004
#define AVR32_SPI_MODF_OFFSET                                       2
#define AVR32_SPI_MODF_SIZE                                         1
#define AVR32_SPI_MR                                       0x00000004
#define AVR32_SPI_MR_DLYBCS                                        24
#define AVR32_SPI_MR_DLYBCS_MASK                           0xff000000
#define AVR32_SPI_MR_DLYBCS_OFFSET                                 24
#define AVR32_SPI_MR_DLYBCS_SIZE                                    8
#define AVR32_SPI_MR_LLB                                            7
#define AVR32_SPI_MR_LLB_MASK                              0x00000080
#define AVR32_SPI_MR_LLB_OFFSET                                     7
#define AVR32_SPI_MR_LLB_SIZE                                       1
#define AVR32_SPI_MR_MODFDIS                                        4
#define AVR32_SPI_MR_MODFDIS_MASK                          0x00000010
#define AVR32_SPI_MR_MODFDIS_OFFSET                                 4
#define AVR32_SPI_MR_MODFDIS_SIZE                                   1
#define AVR32_SPI_MR_MSTR                                           0
#define AVR32_SPI_MR_MSTR_MASK                             0x00000001
#define AVR32_SPI_MR_MSTR_OFFSET                                    0
#define AVR32_SPI_MR_MSTR_SIZE                                      1
#define AVR32_SPI_MR_PCS                                           16
#define AVR32_SPI_MR_PCSDEC                                         2
#define AVR32_SPI_MR_PCSDEC_MASK                           0x00000004
#define AVR32_SPI_MR_PCSDEC_OFFSET                                  2
#define AVR32_SPI_MR_PCSDEC_SIZE                                    1
#define AVR32_SPI_MR_PCS_MASK                              0x000f0000
#define AVR32_SPI_MR_PCS_OFFSET                                    16
#define AVR32_SPI_MR_PCS_SIZE                                       4
#define AVR32_SPI_MR_PS                                             1
#define AVR32_SPI_MR_PS_MASK                               0x00000002
#define AVR32_SPI_MR_PS_OFFSET                                      1
#define AVR32_SPI_MR_PS_SIZE                                        1
#define AVR32_SPI_MSTR                                              0
#define AVR32_SPI_MSTR_MASK                                0x00000001
#define AVR32_SPI_MSTR_OFFSET                                       0
#define AVR32_SPI_MSTR_SIZE                                         1
#define AVR32_SPI_NCPHA                                             1
#define AVR32_SPI_NCPHA_MASK                               0x00000002
#define AVR32_SPI_NCPHA_OFFSET                                      1
#define AVR32_SPI_NCPHA_SIZE                                        1
#define AVR32_SPI_NSSR                                              8
#define AVR32_SPI_NSSR_MASK                                0x00000100
#define AVR32_SPI_NSSR_OFFSET                                       8
#define AVR32_SPI_NSSR_SIZE                                         1
#define AVR32_SPI_OVRES                                             3
#define AVR32_SPI_OVRES_MASK                               0x00000008
#define AVR32_SPI_OVRES_OFFSET                                      3
#define AVR32_SPI_OVRES_SIZE                                        1
#define AVR32_SPI_PCS                                              16
#define AVR32_SPI_PCSDEC                                            2
#define AVR32_SPI_PCSDEC_MASK                              0x00000004
#define AVR32_SPI_PCSDEC_OFFSET                                     2
#define AVR32_SPI_PCSDEC_SIZE                                       1
#define AVR32_SPI_PCS_MASK                                 0x000f0000
#define AVR32_SPI_PCS_OFFSET                                       16
#define AVR32_SPI_PCS_SIZE                                          4
#define AVR32_SPI_PS                                                1
#define AVR32_SPI_PS_MASK                                  0x00000002
#define AVR32_SPI_PS_OFFSET                                         1
#define AVR32_SPI_PS_SIZE                                           1
#define AVR32_SPI_RD                                                0
#define AVR32_SPI_RDR                                      0x00000008
#define AVR32_SPI_RDRF                                              0
#define AVR32_SPI_RDRF_MASK                                0x00000001
#define AVR32_SPI_RDRF_OFFSET                                       0
#define AVR32_SPI_RDRF_SIZE                                         1
#define AVR32_SPI_RDR_PCS                                          16
#define AVR32_SPI_RDR_PCS_MASK                             0x000f0000
#define AVR32_SPI_RDR_PCS_OFFSET                                   16
#define AVR32_SPI_RDR_PCS_SIZE                                      4
#define AVR32_SPI_RDR_RD                                            0
#define AVR32_SPI_RDR_RD_MASK                              0x0000ffff
#define AVR32_SPI_RDR_RD_OFFSET                                     0
#define AVR32_SPI_RDR_RD_SIZE                                      16
#define AVR32_SPI_RD_MASK                                  0x0000ffff
#define AVR32_SPI_RD_OFFSET                                         0
#define AVR32_SPI_RD_SIZE                                          16
#define AVR32_SPI_RXBUFF                                            6
#define AVR32_SPI_RXBUFF_MASK                              0x00000040
#define AVR32_SPI_RXBUFF_OFFSET                                     6
#define AVR32_SPI_RXBUFF_SIZE                                       1
#define AVR32_SPI_SCBR                                              8
#define AVR32_SPI_SCBR_MASK                                0x0000ff00
#define AVR32_SPI_SCBR_OFFSET                                       8
#define AVR32_SPI_SCBR_SIZE                                         8
#define AVR32_SPI_SPIDIS                                            1
#define AVR32_SPI_SPIDIS_MASK                              0x00000002
#define AVR32_SPI_SPIDIS_OFFSET                                     1
#define AVR32_SPI_SPIDIS_SIZE                                       1
#define AVR32_SPI_SPIEN                                             0
#define AVR32_SPI_SPIENS                                           16
#define AVR32_SPI_SPIENS_MASK                              0x00010000
#define AVR32_SPI_SPIENS_OFFSET                                    16
#define AVR32_SPI_SPIENS_SIZE                                       1
#define AVR32_SPI_SPIEN_MASK                               0x00000001
#define AVR32_SPI_SPIEN_OFFSET                                      0
#define AVR32_SPI_SPIEN_SIZE                                        1
#define AVR32_SPI_SR                                       0x00000010
#define AVR32_SPI_SR_ENDRX                                          4
#define AVR32_SPI_SR_ENDRX_MASK                            0x00000010
#define AVR32_SPI_SR_ENDRX_OFFSET                                   4
#define AVR32_SPI_SR_ENDRX_SIZE                                     1
#define AVR32_SPI_SR_ENDTX                                          5
#define AVR32_SPI_SR_ENDTX_MASK                            0x00000020
#define AVR32_SPI_SR_ENDTX_OFFSET                                   5
#define AVR32_SPI_SR_ENDTX_SIZE                                     1
#define AVR32_SPI_SR_MODF                                           2
#define AVR32_SPI_SR_MODF_MASK                             0x00000004
#define AVR32_SPI_SR_MODF_OFFSET                                    2
#define AVR32_SPI_SR_MODF_SIZE                                      1
#define AVR32_SPI_SR_NSSR                                           8
#define AVR32_SPI_SR_NSSR_MASK                             0x00000100
#define AVR32_SPI_SR_NSSR_OFFSET                                    8
#define AVR32_SPI_SR_NSSR_SIZE                                      1
#define AVR32_SPI_SR_OVRES                                          3
#define AVR32_SPI_SR_OVRES_MASK                            0x00000008
#define AVR32_SPI_SR_OVRES_OFFSET                                   3
#define AVR32_SPI_SR_OVRES_SIZE                                     1
#define AVR32_SPI_SR_RDRF                                           0
#define AVR32_SPI_SR_RDRF_MASK                             0x00000001
#define AVR32_SPI_SR_RDRF_OFFSET                                    0
#define AVR32_SPI_SR_RDRF_SIZE                                      1
#define AVR32_SPI_SR_RXBUFF                                         6
#define AVR32_SPI_SR_RXBUFF_MASK                           0x00000040
#define AVR32_SPI_SR_RXBUFF_OFFSET                                  6
#define AVR32_SPI_SR_RXBUFF_SIZE                                    1
#define AVR32_SPI_SR_SPIENS                                        16
#define AVR32_SPI_SR_SPIENS_MASK                           0x00010000
#define AVR32_SPI_SR_SPIENS_OFFSET                                 16
#define AVR32_SPI_SR_SPIENS_SIZE                                    1
#define AVR32_SPI_SR_TDRE                                           1
#define AVR32_SPI_SR_TDRE_MASK                             0x00000002
#define AVR32_SPI_SR_TDRE_OFFSET                                    1
#define AVR32_SPI_SR_TDRE_SIZE                                      1
#define AVR32_SPI_SR_TXBUFE                                         7
#define AVR32_SPI_SR_TXBUFE_MASK                           0x00000080
#define AVR32_SPI_SR_TXBUFE_OFFSET                                  7
#define AVR32_SPI_SR_TXBUFE_SIZE                                    1
#define AVR32_SPI_SR_TXEMPTY                                        9
#define AVR32_SPI_SR_TXEMPTY_MASK                          0x00000200
#define AVR32_SPI_SR_TXEMPTY_OFFSET                                 9
#define AVR32_SPI_SR_TXEMPTY_SIZE                                   1
#define AVR32_SPI_SWRST                                             7
#define AVR32_SPI_SWRST_MASK                               0x00000080
#define AVR32_SPI_SWRST_OFFSET                                      7
#define AVR32_SPI_SWRST_SIZE                                        1
#define AVR32_SPI_TD                                                0
#define AVR32_SPI_TDR                                      0x0000000c
#define AVR32_SPI_TDRE                                              1
#define AVR32_SPI_TDRE_MASK                                0x00000002
#define AVR32_SPI_TDRE_OFFSET                                       1
#define AVR32_SPI_TDRE_SIZE                                         1
#define AVR32_SPI_TDR_LASTXFER                                     24
#define AVR32_SPI_TDR_LASTXFER_MASK                        0x01000000
#define AVR32_SPI_TDR_LASTXFER_OFFSET                              24
#define AVR32_SPI_TDR_LASTXFER_SIZE                                 1
#define AVR32_SPI_TDR_PCS                                          16
#define AVR32_SPI_TDR_PCS_MASK                             0x000f0000
#define AVR32_SPI_TDR_PCS_OFFSET                                   16
#define AVR32_SPI_TDR_PCS_SIZE                                      4
#define AVR32_SPI_TDR_TD                                            0
#define AVR32_SPI_TDR_TD_MASK                              0x0000ffff
#define AVR32_SPI_TDR_TD_OFFSET                                     0
#define AVR32_SPI_TDR_TD_SIZE                                      16
#define AVR32_SPI_TD_MASK                                  0x0000ffff
#define AVR32_SPI_TD_OFFSET                                         0
#define AVR32_SPI_TD_SIZE                                          16
#define AVR32_SPI_TXBUFE                                            7
#define AVR32_SPI_TXBUFE_MASK                              0x00000080
#define AVR32_SPI_TXBUFE_OFFSET                                     7
#define AVR32_SPI_TXBUFE_SIZE                                       1
#define AVR32_SPI_TXEMPTY                                           9
#define AVR32_SPI_TXEMPTY_MASK                             0x00000200
#define AVR32_SPI_TXEMPTY_OFFSET                                    9
#define AVR32_SPI_TXEMPTY_SIZE                                      1
#define AVR32_SPI_VARIANT                                          16
#define AVR32_SPI_VARIANT_MASK                             0x00070000
#define AVR32_SPI_VARIANT_OFFSET                                   16
#define AVR32_SPI_VARIANT_SIZE                                      3
#define AVR32_SPI_VERSION                                  0x000000fc
#define AVR32_SPI_VERSION_MASK                             0x00000fff
#define AVR32_SPI_VERSION_OFFSET                                    0
#define AVR32_SPI_VERSION_SIZE                                     12
#define AVR32_SPI_VERSION_VARIANT                                  16
#define AVR32_SPI_VERSION_VARIANT_MASK                     0x00070000
#define AVR32_SPI_VERSION_VARIANT_OFFSET                           16
#define AVR32_SPI_VERSION_VARIANT_SIZE                              3
#define AVR32_SPI_VERSION_VERSION                                   0
#define AVR32_SPI_VERSION_VERSION_MASK                     0x00000fff
#define AVR32_SPI_VERSION_VERSION_OFFSET                            0
#define AVR32_SPI_VERSION_VERSION_SIZE                             12




#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_spi_cr_t {
    unsigned int                 : 7;
    unsigned int lastxfer        : 1;
    unsigned int                 :16;
    unsigned int swrst           : 1;
    unsigned int                 : 5;
    unsigned int spidis          : 1;
    unsigned int spien           : 1;
} avr32_spi_cr_t;



typedef struct avr32_spi_mr_t {
    unsigned int dlybcs          : 8;
    unsigned int                 : 4;
    unsigned int pcs             : 4;
    unsigned int                 : 8;
    unsigned int llb             : 1;
    unsigned int                 : 2;
    unsigned int modfdis         : 1;
    unsigned int                 : 1;
    unsigned int pcsdec          : 1;
    unsigned int ps              : 1;
    unsigned int mstr            : 1;
} avr32_spi_mr_t;



typedef struct avr32_spi_rdr_t {
    unsigned int                 :12;
    unsigned int pcs             : 4;
    unsigned int rd              :16;
} avr32_spi_rdr_t;



typedef struct avr32_spi_tdr_t {
    unsigned int                 : 7;
    unsigned int lastxfer        : 1;
    unsigned int                 : 4;
    unsigned int pcs             : 4;
    unsigned int td              :16;
} avr32_spi_tdr_t;



typedef struct avr32_spi_sr_t {
    unsigned int                 :15;
    unsigned int spiens          : 1;
    unsigned int                 : 6;
    unsigned int txempty         : 1;
    unsigned int nssr            : 1;
    unsigned int txbufe          : 1;
    unsigned int rxbuff          : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int ovres           : 1;
    unsigned int modf            : 1;
    unsigned int tdre            : 1;
    unsigned int rdrf            : 1;
} avr32_spi_sr_t;



typedef struct avr32_spi_ier_t {
    unsigned int                 :22;
    unsigned int txempty         : 1;
    unsigned int nssr            : 1;
    unsigned int txbufe          : 1;
    unsigned int rxbuff          : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int ovres           : 1;
    unsigned int modf            : 1;
    unsigned int tdre            : 1;
    unsigned int rdrf            : 1;
} avr32_spi_ier_t;



typedef struct avr32_spi_idr_t {
    unsigned int                 :22;
    unsigned int txempty         : 1;
    unsigned int nssr            : 1;
    unsigned int txbufe          : 1;
    unsigned int rxbuff          : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int ovres           : 1;
    unsigned int modf            : 1;
    unsigned int tdre            : 1;
    unsigned int rdrf            : 1;
} avr32_spi_idr_t;



typedef struct avr32_spi_imr_t {
    unsigned int                 :22;
    unsigned int txempty         : 1;
    unsigned int nssr            : 1;
    unsigned int txbufe          : 1;
    unsigned int rxbuff          : 1;
    unsigned int endtx           : 1;
    unsigned int endrx           : 1;
    unsigned int ovres           : 1;
    unsigned int modf            : 1;
    unsigned int tdre            : 1;
    unsigned int rdrf            : 1;
} avr32_spi_imr_t;



typedef struct avr32_spi_csr0_t {
    unsigned int dlybct          : 8;
    unsigned int dlybs           : 8;
    unsigned int scbr            : 8;
    unsigned int bits            : 4;
    unsigned int csaat           : 1;
    unsigned int csnaat          : 1;
    unsigned int ncpha           : 1;
    unsigned int cpol            : 1;
} avr32_spi_csr0_t;



typedef struct avr32_spi_csr1_t {
    unsigned int dlybct          : 8;
    unsigned int dlybs           : 8;
    unsigned int scbr            : 8;
    unsigned int bits            : 4;
    unsigned int csaat           : 1;
    unsigned int csnaat          : 1;
    unsigned int ncpha           : 1;
    unsigned int cpol            : 1;
} avr32_spi_csr1_t;



typedef struct avr32_spi_csr2_t {
    unsigned int dlybct          : 8;
    unsigned int dlybs           : 8;
    unsigned int scbr            : 8;
    unsigned int bits            : 4;
    unsigned int csaat           : 1;
    unsigned int csnaat          : 1;
    unsigned int ncpha           : 1;
    unsigned int cpol            : 1;
} avr32_spi_csr2_t;



typedef struct avr32_spi_csr3_t {
    unsigned int dlybct          : 8;
    unsigned int dlybs           : 8;
    unsigned int scbr            : 8;
    unsigned int bits            : 4;
    unsigned int csaat           : 1;
    unsigned int csnaat          : 1;
    unsigned int ncpha           : 1;
    unsigned int cpol            : 1;
} avr32_spi_csr3_t;



typedef struct avr32_spi_version_t {
    unsigned int                 :13;
    unsigned int variant         : 3;
    unsigned int                 : 4;
    unsigned int version         :12;
} avr32_spi_version_t;



typedef struct avr32_spi_t {
  union {
          unsigned long                  cr        ;//0x0000
          avr32_spi_cr_t                 CR        ;
  };
  union {
          unsigned long                  mr        ;//0x0004
          avr32_spi_mr_t                 MR        ;
  };
  union {
    const unsigned long                  rdr       ;//0x0008
    const avr32_spi_rdr_t                RDR       ;
  };
  union {
          unsigned long                  tdr       ;//0x000c
          avr32_spi_tdr_t                TDR       ;
  };
  union {
    const unsigned long                  sr        ;//0x0010
    const avr32_spi_sr_t                 SR        ;
  };
  union {
          unsigned long                  ier       ;//0x0014
          avr32_spi_ier_t                IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0018
          avr32_spi_idr_t                IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x001c
    const avr32_spi_imr_t                IMR       ;
  };
          unsigned int                   :32       ;//0x0020
          unsigned int                   :32       ;//0x0024
          unsigned int                   :32       ;//0x0028
          unsigned int                   :32       ;//0x002c
  union {
          unsigned long                  csr0      ;//0x0030
          avr32_spi_csr0_t               CSR0      ;
  };
  union {
          unsigned long                  csr1      ;//0x0034
          avr32_spi_csr1_t               CSR1      ;
  };
  union {
          unsigned long                  csr2      ;//0x0038
          avr32_spi_csr2_t               CSR2      ;
  };
  union {
          unsigned long                  csr3      ;//0x003c
          avr32_spi_csr3_t               CSR3      ;
  };
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
    const avr32_spi_version_t            VERSION   ;
  };
} avr32_spi_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif


#if !defined (DEPRECATED_DISABLE)

#define AVR32_SPI_MFN                                              16
#define AVR32_SPI_MFN_MASK                                 0x00070000
#define AVR32_SPI_MFN_OFFSET                                       16
#define AVR32_SPI_MFN_SIZE                                          3

#define AVR32_SPI_VERSION_MFN                                      16
#define AVR32_SPI_VERSION_MFN_MASK                         0x00070000
#define AVR32_SPI_VERSION_MFN_OFFSET                               16
#define AVR32_SPI_VERSION_MFN_SIZE                                  3

#endif


/*#ifdef AVR32_SPI_199_H_INCLUDED*/
#endif

