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
 * Model        : UC3A3128
 * Revision     : $Revision: 74772 $
 * Checkin Date : $Date: 2010-05-14 06:51:12 +0200 (Fri, 14 May 2010) $ 
 *
 ****************************************************************************/
#ifndef AVR32_ADC_200_H_INCLUDED
#define AVR32_ADC_200_H_INCLUDED

#define AVR32_ADC_H_VERSION 200

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_ADC_<register>
 - Bitfield mask:   AVR32_ADC_<register>_<bitfield>
 - Bitfield offset: AVR32_ADC_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_ADC_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_ADC_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_ADC_<bitfield>
 - Bitfield offset: AVR32_ADC_<bitfield>_OFFSET
 - Bitfield size:   AVR32_ADC_<bitfield>_SIZE
 - Bitfield values: AVR32_ADC_<bitfield>_<value name>
 - Bitfield values: AVR32_ADC_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_ADC_CDR0                                     0x00000030
#define AVR32_ADC_CDR0_DATA                                         0
#define AVR32_ADC_CDR0_DATA_MASK                           0x000003ff
#define AVR32_ADC_CDR0_DATA_OFFSET                                  0
#define AVR32_ADC_CDR0_DATA_SIZE                                   10
#define AVR32_ADC_CDR1                                     0x00000034
#define AVR32_ADC_CDR1_DATA                                         0
#define AVR32_ADC_CDR1_DATA_MASK                           0x000003ff
#define AVR32_ADC_CDR1_DATA_OFFSET                                  0
#define AVR32_ADC_CDR1_DATA_SIZE                                   10
#define AVR32_ADC_CDR2                                     0x00000038
#define AVR32_ADC_CDR2_DATA                                         0
#define AVR32_ADC_CDR2_DATA_MASK                           0x000003ff
#define AVR32_ADC_CDR2_DATA_OFFSET                                  0
#define AVR32_ADC_CDR2_DATA_SIZE                                   10
#define AVR32_ADC_CDR3                                     0x0000003c
#define AVR32_ADC_CDR3_DATA                                         0
#define AVR32_ADC_CDR3_DATA_MASK                           0x000003ff
#define AVR32_ADC_CDR3_DATA_OFFSET                                  0
#define AVR32_ADC_CDR3_DATA_SIZE                                   10
#define AVR32_ADC_CDR4                                     0x00000040
#define AVR32_ADC_CDR4_DATA                                         0
#define AVR32_ADC_CDR4_DATA_MASK                           0x000003ff
#define AVR32_ADC_CDR4_DATA_OFFSET                                  0
#define AVR32_ADC_CDR4_DATA_SIZE                                   10
#define AVR32_ADC_CDR5                                     0x00000044
#define AVR32_ADC_CDR5_DATA                                         0
#define AVR32_ADC_CDR5_DATA_MASK                           0x000003ff
#define AVR32_ADC_CDR5_DATA_OFFSET                                  0
#define AVR32_ADC_CDR5_DATA_SIZE                                   10
#define AVR32_ADC_CDR6                                     0x00000048
#define AVR32_ADC_CDR6_DATA                                         0
#define AVR32_ADC_CDR6_DATA_MASK                           0x000003ff
#define AVR32_ADC_CDR6_DATA_OFFSET                                  0
#define AVR32_ADC_CDR6_DATA_SIZE                                   10
#define AVR32_ADC_CDR7                                     0x0000004c
#define AVR32_ADC_CDR7_DATA                                         0
#define AVR32_ADC_CDR7_DATA_MASK                           0x000003ff
#define AVR32_ADC_CDR7_DATA_OFFSET                                  0
#define AVR32_ADC_CDR7_DATA_SIZE                                   10
#define AVR32_ADC_CH0                                               0
#define AVR32_ADC_CH0_MASK                                 0x00000001
#define AVR32_ADC_CH0_OFFSET                                        0
#define AVR32_ADC_CH0_SIZE                                          1
#define AVR32_ADC_CH1                                               1
#define AVR32_ADC_CH1_MASK                                 0x00000002
#define AVR32_ADC_CH1_OFFSET                                        1
#define AVR32_ADC_CH1_SIZE                                          1
#define AVR32_ADC_CH2                                               2
#define AVR32_ADC_CH2_MASK                                 0x00000004
#define AVR32_ADC_CH2_OFFSET                                        2
#define AVR32_ADC_CH2_SIZE                                          1
#define AVR32_ADC_CH3                                               3
#define AVR32_ADC_CH3_MASK                                 0x00000008
#define AVR32_ADC_CH3_OFFSET                                        3
#define AVR32_ADC_CH3_SIZE                                          1
#define AVR32_ADC_CH4                                               4
#define AVR32_ADC_CH4_MASK                                 0x00000010
#define AVR32_ADC_CH4_OFFSET                                        4
#define AVR32_ADC_CH4_SIZE                                          1
#define AVR32_ADC_CH5                                               5
#define AVR32_ADC_CH5_MASK                                 0x00000020
#define AVR32_ADC_CH5_OFFSET                                        5
#define AVR32_ADC_CH5_SIZE                                          1
#define AVR32_ADC_CH6                                               6
#define AVR32_ADC_CH6_MASK                                 0x00000040
#define AVR32_ADC_CH6_OFFSET                                        6
#define AVR32_ADC_CH6_SIZE                                          1
#define AVR32_ADC_CH7                                               7
#define AVR32_ADC_CH7_MASK                                 0x00000080
#define AVR32_ADC_CH7_OFFSET                                        7
#define AVR32_ADC_CH7_SIZE                                          1
#define AVR32_ADC_CHDR                                     0x00000014
#define AVR32_ADC_CHDR_CH0                                          0
#define AVR32_ADC_CHDR_CH0_MASK                            0x00000001
#define AVR32_ADC_CHDR_CH0_OFFSET                                   0
#define AVR32_ADC_CHDR_CH0_SIZE                                     1
#define AVR32_ADC_CHDR_CH1                                          1
#define AVR32_ADC_CHDR_CH1_MASK                            0x00000002
#define AVR32_ADC_CHDR_CH1_OFFSET                                   1
#define AVR32_ADC_CHDR_CH1_SIZE                                     1
#define AVR32_ADC_CHDR_CH2                                          2
#define AVR32_ADC_CHDR_CH2_MASK                            0x00000004
#define AVR32_ADC_CHDR_CH2_OFFSET                                   2
#define AVR32_ADC_CHDR_CH2_SIZE                                     1
#define AVR32_ADC_CHDR_CH3                                          3
#define AVR32_ADC_CHDR_CH3_MASK                            0x00000008
#define AVR32_ADC_CHDR_CH3_OFFSET                                   3
#define AVR32_ADC_CHDR_CH3_SIZE                                     1
#define AVR32_ADC_CHDR_CH4                                          4
#define AVR32_ADC_CHDR_CH4_MASK                            0x00000010
#define AVR32_ADC_CHDR_CH4_OFFSET                                   4
#define AVR32_ADC_CHDR_CH4_SIZE                                     1
#define AVR32_ADC_CHDR_CH5                                          5
#define AVR32_ADC_CHDR_CH5_MASK                            0x00000020
#define AVR32_ADC_CHDR_CH5_OFFSET                                   5
#define AVR32_ADC_CHDR_CH5_SIZE                                     1
#define AVR32_ADC_CHDR_CH6                                          6
#define AVR32_ADC_CHDR_CH6_MASK                            0x00000040
#define AVR32_ADC_CHDR_CH6_OFFSET                                   6
#define AVR32_ADC_CHDR_CH6_SIZE                                     1
#define AVR32_ADC_CHDR_CH7                                          7
#define AVR32_ADC_CHDR_CH7_MASK                            0x00000080
#define AVR32_ADC_CHDR_CH7_OFFSET                                   7
#define AVR32_ADC_CHDR_CH7_SIZE                                     1
#define AVR32_ADC_CHER                                     0x00000010
#define AVR32_ADC_CHER_CH0                                          0
#define AVR32_ADC_CHER_CH0_MASK                            0x00000001
#define AVR32_ADC_CHER_CH0_OFFSET                                   0
#define AVR32_ADC_CHER_CH0_SIZE                                     1
#define AVR32_ADC_CHER_CH1                                          1
#define AVR32_ADC_CHER_CH1_MASK                            0x00000002
#define AVR32_ADC_CHER_CH1_OFFSET                                   1
#define AVR32_ADC_CHER_CH1_SIZE                                     1
#define AVR32_ADC_CHER_CH2                                          2
#define AVR32_ADC_CHER_CH2_MASK                            0x00000004
#define AVR32_ADC_CHER_CH2_OFFSET                                   2
#define AVR32_ADC_CHER_CH2_SIZE                                     1
#define AVR32_ADC_CHER_CH3                                          3
#define AVR32_ADC_CHER_CH3_MASK                            0x00000008
#define AVR32_ADC_CHER_CH3_OFFSET                                   3
#define AVR32_ADC_CHER_CH3_SIZE                                     1
#define AVR32_ADC_CHER_CH4                                          4
#define AVR32_ADC_CHER_CH4_MASK                            0x00000010
#define AVR32_ADC_CHER_CH4_OFFSET                                   4
#define AVR32_ADC_CHER_CH4_SIZE                                     1
#define AVR32_ADC_CHER_CH5                                          5
#define AVR32_ADC_CHER_CH5_MASK                            0x00000020
#define AVR32_ADC_CHER_CH5_OFFSET                                   5
#define AVR32_ADC_CHER_CH5_SIZE                                     1
#define AVR32_ADC_CHER_CH6                                          6
#define AVR32_ADC_CHER_CH6_MASK                            0x00000040
#define AVR32_ADC_CHER_CH6_OFFSET                                   6
#define AVR32_ADC_CHER_CH6_SIZE                                     1
#define AVR32_ADC_CHER_CH7                                          7
#define AVR32_ADC_CHER_CH7_MASK                            0x00000080
#define AVR32_ADC_CHER_CH7_OFFSET                                   7
#define AVR32_ADC_CHER_CH7_SIZE                                     1
#define AVR32_ADC_CHSR                                     0x00000018
#define AVR32_ADC_CHSR_CH0                                          0
#define AVR32_ADC_CHSR_CH0_MASK                            0x00000001
#define AVR32_ADC_CHSR_CH0_OFFSET                                   0
#define AVR32_ADC_CHSR_CH0_SIZE                                     1
#define AVR32_ADC_CHSR_CH1                                          1
#define AVR32_ADC_CHSR_CH1_MASK                            0x00000002
#define AVR32_ADC_CHSR_CH1_OFFSET                                   1
#define AVR32_ADC_CHSR_CH1_SIZE                                     1
#define AVR32_ADC_CHSR_CH2                                          2
#define AVR32_ADC_CHSR_CH2_MASK                            0x00000004
#define AVR32_ADC_CHSR_CH2_OFFSET                                   2
#define AVR32_ADC_CHSR_CH2_SIZE                                     1
#define AVR32_ADC_CHSR_CH3                                          3
#define AVR32_ADC_CHSR_CH3_MASK                            0x00000008
#define AVR32_ADC_CHSR_CH3_OFFSET                                   3
#define AVR32_ADC_CHSR_CH3_SIZE                                     1
#define AVR32_ADC_CHSR_CH4                                          4
#define AVR32_ADC_CHSR_CH4_MASK                            0x00000010
#define AVR32_ADC_CHSR_CH4_OFFSET                                   4
#define AVR32_ADC_CHSR_CH4_SIZE                                     1
#define AVR32_ADC_CHSR_CH5                                          5
#define AVR32_ADC_CHSR_CH5_MASK                            0x00000020
#define AVR32_ADC_CHSR_CH5_OFFSET                                   5
#define AVR32_ADC_CHSR_CH5_SIZE                                     1
#define AVR32_ADC_CHSR_CH6                                          6
#define AVR32_ADC_CHSR_CH6_MASK                            0x00000040
#define AVR32_ADC_CHSR_CH6_OFFSET                                   6
#define AVR32_ADC_CHSR_CH6_SIZE                                     1
#define AVR32_ADC_CHSR_CH7                                          7
#define AVR32_ADC_CHSR_CH7_MASK                            0x00000080
#define AVR32_ADC_CHSR_CH7_OFFSET                                   7
#define AVR32_ADC_CHSR_CH7_SIZE                                     1
#define AVR32_ADC_CR                                       0x00000000
#define AVR32_ADC_CR_START                                          1
#define AVR32_ADC_CR_START_MASK                            0x00000002
#define AVR32_ADC_CR_START_OFFSET                                   1
#define AVR32_ADC_CR_START_SIZE                                     1
#define AVR32_ADC_CR_SWRST                                          0
#define AVR32_ADC_CR_SWRST_MASK                            0x00000001
#define AVR32_ADC_CR_SWRST_OFFSET                                   0
#define AVR32_ADC_CR_SWRST_SIZE                                     1
#define AVR32_ADC_DATA                                              0
#define AVR32_ADC_DATA_MASK                                0x000003ff
#define AVR32_ADC_DATA_OFFSET                                       0
#define AVR32_ADC_DATA_SIZE                                        10
#define AVR32_ADC_DRDY                                             16
#define AVR32_ADC_DRDY_MASK                                0x00010000
#define AVR32_ADC_DRDY_OFFSET                                      16
#define AVR32_ADC_DRDY_SIZE                                         1
#define AVR32_ADC_ENDRX                                            18
#define AVR32_ADC_ENDRX_MASK                               0x00040000
#define AVR32_ADC_ENDRX_OFFSET                                     18
#define AVR32_ADC_ENDRX_SIZE                                        1
#define AVR32_ADC_EOC0                                              0
#define AVR32_ADC_EOC0_MASK                                0x00000001
#define AVR32_ADC_EOC0_OFFSET                                       0
#define AVR32_ADC_EOC0_SIZE                                         1
#define AVR32_ADC_EOC1                                              1
#define AVR32_ADC_EOC1_MASK                                0x00000002
#define AVR32_ADC_EOC1_OFFSET                                       1
#define AVR32_ADC_EOC1_SIZE                                         1
#define AVR32_ADC_EOC2                                              2
#define AVR32_ADC_EOC2_MASK                                0x00000004
#define AVR32_ADC_EOC2_OFFSET                                       2
#define AVR32_ADC_EOC2_SIZE                                         1
#define AVR32_ADC_EOC3                                              3
#define AVR32_ADC_EOC3_MASK                                0x00000008
#define AVR32_ADC_EOC3_OFFSET                                       3
#define AVR32_ADC_EOC3_SIZE                                         1
#define AVR32_ADC_EOC4                                              4
#define AVR32_ADC_EOC4_MASK                                0x00000010
#define AVR32_ADC_EOC4_OFFSET                                       4
#define AVR32_ADC_EOC4_SIZE                                         1
#define AVR32_ADC_EOC5                                              5
#define AVR32_ADC_EOC5_MASK                                0x00000020
#define AVR32_ADC_EOC5_OFFSET                                       5
#define AVR32_ADC_EOC5_SIZE                                         1
#define AVR32_ADC_EOC6                                              6
#define AVR32_ADC_EOC6_MASK                                0x00000040
#define AVR32_ADC_EOC6_OFFSET                                       6
#define AVR32_ADC_EOC6_SIZE                                         1
#define AVR32_ADC_EOC7                                              7
#define AVR32_ADC_EOC7_MASK                                0x00000080
#define AVR32_ADC_EOC7_OFFSET                                       7
#define AVR32_ADC_EOC7_SIZE                                         1
#define AVR32_ADC_GOVRE                                            17
#define AVR32_ADC_GOVRE_MASK                               0x00020000
#define AVR32_ADC_GOVRE_OFFSET                                     17
#define AVR32_ADC_GOVRE_SIZE                                        1
#define AVR32_ADC_IDR                                      0x00000028
#define AVR32_ADC_IDR_DRDY                                         16
#define AVR32_ADC_IDR_DRDY_MASK                            0x00010000
#define AVR32_ADC_IDR_DRDY_OFFSET                                  16
#define AVR32_ADC_IDR_DRDY_SIZE                                     1
#define AVR32_ADC_IDR_ENDRX                                        18
#define AVR32_ADC_IDR_ENDRX_MASK                           0x00040000
#define AVR32_ADC_IDR_ENDRX_OFFSET                                 18
#define AVR32_ADC_IDR_ENDRX_SIZE                                    1
#define AVR32_ADC_IDR_EOC0                                          0
#define AVR32_ADC_IDR_EOC0_MASK                            0x00000001
#define AVR32_ADC_IDR_EOC0_OFFSET                                   0
#define AVR32_ADC_IDR_EOC0_SIZE                                     1
#define AVR32_ADC_IDR_EOC1                                          1
#define AVR32_ADC_IDR_EOC1_MASK                            0x00000002
#define AVR32_ADC_IDR_EOC1_OFFSET                                   1
#define AVR32_ADC_IDR_EOC1_SIZE                                     1
#define AVR32_ADC_IDR_EOC2                                          2
#define AVR32_ADC_IDR_EOC2_MASK                            0x00000004
#define AVR32_ADC_IDR_EOC2_OFFSET                                   2
#define AVR32_ADC_IDR_EOC2_SIZE                                     1
#define AVR32_ADC_IDR_EOC3                                          3
#define AVR32_ADC_IDR_EOC3_MASK                            0x00000008
#define AVR32_ADC_IDR_EOC3_OFFSET                                   3
#define AVR32_ADC_IDR_EOC3_SIZE                                     1
#define AVR32_ADC_IDR_EOC4                                          4
#define AVR32_ADC_IDR_EOC4_MASK                            0x00000010
#define AVR32_ADC_IDR_EOC4_OFFSET                                   4
#define AVR32_ADC_IDR_EOC4_SIZE                                     1
#define AVR32_ADC_IDR_EOC5                                          5
#define AVR32_ADC_IDR_EOC5_MASK                            0x00000020
#define AVR32_ADC_IDR_EOC5_OFFSET                                   5
#define AVR32_ADC_IDR_EOC5_SIZE                                     1
#define AVR32_ADC_IDR_EOC6                                          6
#define AVR32_ADC_IDR_EOC6_MASK                            0x00000040
#define AVR32_ADC_IDR_EOC6_OFFSET                                   6
#define AVR32_ADC_IDR_EOC6_SIZE                                     1
#define AVR32_ADC_IDR_EOC7                                          7
#define AVR32_ADC_IDR_EOC7_MASK                            0x00000080
#define AVR32_ADC_IDR_EOC7_OFFSET                                   7
#define AVR32_ADC_IDR_EOC7_SIZE                                     1
#define AVR32_ADC_IDR_GOVRE                                        17
#define AVR32_ADC_IDR_GOVRE_MASK                           0x00020000
#define AVR32_ADC_IDR_GOVRE_OFFSET                                 17
#define AVR32_ADC_IDR_GOVRE_SIZE                                    1
#define AVR32_ADC_IDR_OVRE0                                         8
#define AVR32_ADC_IDR_OVRE0_MASK                           0x00000100
#define AVR32_ADC_IDR_OVRE0_OFFSET                                  8
#define AVR32_ADC_IDR_OVRE0_SIZE                                    1
#define AVR32_ADC_IDR_OVRE1                                         9
#define AVR32_ADC_IDR_OVRE1_MASK                           0x00000200
#define AVR32_ADC_IDR_OVRE1_OFFSET                                  9
#define AVR32_ADC_IDR_OVRE1_SIZE                                    1
#define AVR32_ADC_IDR_OVRE2                                        10
#define AVR32_ADC_IDR_OVRE2_MASK                           0x00000400
#define AVR32_ADC_IDR_OVRE2_OFFSET                                 10
#define AVR32_ADC_IDR_OVRE2_SIZE                                    1
#define AVR32_ADC_IDR_OVRE3                                        11
#define AVR32_ADC_IDR_OVRE3_MASK                           0x00000800
#define AVR32_ADC_IDR_OVRE3_OFFSET                                 11
#define AVR32_ADC_IDR_OVRE3_SIZE                                    1
#define AVR32_ADC_IDR_OVRE4                                        12
#define AVR32_ADC_IDR_OVRE4_MASK                           0x00001000
#define AVR32_ADC_IDR_OVRE4_OFFSET                                 12
#define AVR32_ADC_IDR_OVRE4_SIZE                                    1
#define AVR32_ADC_IDR_OVRE5                                        13
#define AVR32_ADC_IDR_OVRE5_MASK                           0x00002000
#define AVR32_ADC_IDR_OVRE5_OFFSET                                 13
#define AVR32_ADC_IDR_OVRE5_SIZE                                    1
#define AVR32_ADC_IDR_OVRE6                                        14
#define AVR32_ADC_IDR_OVRE6_MASK                           0x00004000
#define AVR32_ADC_IDR_OVRE6_OFFSET                                 14
#define AVR32_ADC_IDR_OVRE6_SIZE                                    1
#define AVR32_ADC_IDR_OVRE7                                        15
#define AVR32_ADC_IDR_OVRE7_MASK                           0x00008000
#define AVR32_ADC_IDR_OVRE7_OFFSET                                 15
#define AVR32_ADC_IDR_OVRE7_SIZE                                    1
#define AVR32_ADC_IDR_RXBUFF                                       19
#define AVR32_ADC_IDR_RXBUFF_MASK                          0x00080000
#define AVR32_ADC_IDR_RXBUFF_OFFSET                                19
#define AVR32_ADC_IDR_RXBUFF_SIZE                                   1
#define AVR32_ADC_IER                                      0x00000024
#define AVR32_ADC_IER_DRDY                                         16
#define AVR32_ADC_IER_DRDY_MASK                            0x00010000
#define AVR32_ADC_IER_DRDY_OFFSET                                  16
#define AVR32_ADC_IER_DRDY_SIZE                                     1
#define AVR32_ADC_IER_ENDRX                                        18
#define AVR32_ADC_IER_ENDRX_MASK                           0x00040000
#define AVR32_ADC_IER_ENDRX_OFFSET                                 18
#define AVR32_ADC_IER_ENDRX_SIZE                                    1
#define AVR32_ADC_IER_EOC0                                          0
#define AVR32_ADC_IER_EOC0_MASK                            0x00000001
#define AVR32_ADC_IER_EOC0_OFFSET                                   0
#define AVR32_ADC_IER_EOC0_SIZE                                     1
#define AVR32_ADC_IER_EOC1                                          1
#define AVR32_ADC_IER_EOC1_MASK                            0x00000002
#define AVR32_ADC_IER_EOC1_OFFSET                                   1
#define AVR32_ADC_IER_EOC1_SIZE                                     1
#define AVR32_ADC_IER_EOC2                                          2
#define AVR32_ADC_IER_EOC2_MASK                            0x00000004
#define AVR32_ADC_IER_EOC2_OFFSET                                   2
#define AVR32_ADC_IER_EOC2_SIZE                                     1
#define AVR32_ADC_IER_EOC3                                          3
#define AVR32_ADC_IER_EOC3_MASK                            0x00000008
#define AVR32_ADC_IER_EOC3_OFFSET                                   3
#define AVR32_ADC_IER_EOC3_SIZE                                     1
#define AVR32_ADC_IER_EOC4                                          4
#define AVR32_ADC_IER_EOC4_MASK                            0x00000010
#define AVR32_ADC_IER_EOC4_OFFSET                                   4
#define AVR32_ADC_IER_EOC4_SIZE                                     1
#define AVR32_ADC_IER_EOC5                                          5
#define AVR32_ADC_IER_EOC5_MASK                            0x00000020
#define AVR32_ADC_IER_EOC5_OFFSET                                   5
#define AVR32_ADC_IER_EOC5_SIZE                                     1
#define AVR32_ADC_IER_EOC6                                          6
#define AVR32_ADC_IER_EOC6_MASK                            0x00000040
#define AVR32_ADC_IER_EOC6_OFFSET                                   6
#define AVR32_ADC_IER_EOC6_SIZE                                     1
#define AVR32_ADC_IER_EOC7                                          7
#define AVR32_ADC_IER_EOC7_MASK                            0x00000080
#define AVR32_ADC_IER_EOC7_OFFSET                                   7
#define AVR32_ADC_IER_EOC7_SIZE                                     1
#define AVR32_ADC_IER_GOVRE                                        17
#define AVR32_ADC_IER_GOVRE_MASK                           0x00020000
#define AVR32_ADC_IER_GOVRE_OFFSET                                 17
#define AVR32_ADC_IER_GOVRE_SIZE                                    1
#define AVR32_ADC_IER_OVRE0                                         8
#define AVR32_ADC_IER_OVRE0_MASK                           0x00000100
#define AVR32_ADC_IER_OVRE0_OFFSET                                  8
#define AVR32_ADC_IER_OVRE0_SIZE                                    1
#define AVR32_ADC_IER_OVRE1                                         9
#define AVR32_ADC_IER_OVRE1_MASK                           0x00000200
#define AVR32_ADC_IER_OVRE1_OFFSET                                  9
#define AVR32_ADC_IER_OVRE1_SIZE                                    1
#define AVR32_ADC_IER_OVRE2                                        10
#define AVR32_ADC_IER_OVRE2_MASK                           0x00000400
#define AVR32_ADC_IER_OVRE2_OFFSET                                 10
#define AVR32_ADC_IER_OVRE2_SIZE                                    1
#define AVR32_ADC_IER_OVRE3                                        11
#define AVR32_ADC_IER_OVRE3_MASK                           0x00000800
#define AVR32_ADC_IER_OVRE3_OFFSET                                 11
#define AVR32_ADC_IER_OVRE3_SIZE                                    1
#define AVR32_ADC_IER_OVRE4                                        12
#define AVR32_ADC_IER_OVRE4_MASK                           0x00001000
#define AVR32_ADC_IER_OVRE4_OFFSET                                 12
#define AVR32_ADC_IER_OVRE4_SIZE                                    1
#define AVR32_ADC_IER_OVRE5                                        13
#define AVR32_ADC_IER_OVRE5_MASK                           0x00002000
#define AVR32_ADC_IER_OVRE5_OFFSET                                 13
#define AVR32_ADC_IER_OVRE5_SIZE                                    1
#define AVR32_ADC_IER_OVRE6                                        14
#define AVR32_ADC_IER_OVRE6_MASK                           0x00004000
#define AVR32_ADC_IER_OVRE6_OFFSET                                 14
#define AVR32_ADC_IER_OVRE6_SIZE                                    1
#define AVR32_ADC_IER_OVRE7                                        15
#define AVR32_ADC_IER_OVRE7_MASK                           0x00008000
#define AVR32_ADC_IER_OVRE7_OFFSET                                 15
#define AVR32_ADC_IER_OVRE7_SIZE                                    1
#define AVR32_ADC_IER_RXBUFF                                       19
#define AVR32_ADC_IER_RXBUFF_MASK                          0x00080000
#define AVR32_ADC_IER_RXBUFF_OFFSET                                19
#define AVR32_ADC_IER_RXBUFF_SIZE                                   1
#define AVR32_ADC_IMR                                      0x0000002c
#define AVR32_ADC_IMR_DRDY                                         16
#define AVR32_ADC_IMR_DRDY_MASK                            0x00010000
#define AVR32_ADC_IMR_DRDY_OFFSET                                  16
#define AVR32_ADC_IMR_DRDY_SIZE                                     1
#define AVR32_ADC_IMR_ENDRX                                        18
#define AVR32_ADC_IMR_ENDRX_MASK                           0x00040000
#define AVR32_ADC_IMR_ENDRX_OFFSET                                 18
#define AVR32_ADC_IMR_ENDRX_SIZE                                    1
#define AVR32_ADC_IMR_EOC0                                          0
#define AVR32_ADC_IMR_EOC0_MASK                            0x00000001
#define AVR32_ADC_IMR_EOC0_OFFSET                                   0
#define AVR32_ADC_IMR_EOC0_SIZE                                     1
#define AVR32_ADC_IMR_EOC1                                          1
#define AVR32_ADC_IMR_EOC1_MASK                            0x00000002
#define AVR32_ADC_IMR_EOC1_OFFSET                                   1
#define AVR32_ADC_IMR_EOC1_SIZE                                     1
#define AVR32_ADC_IMR_EOC2                                          2
#define AVR32_ADC_IMR_EOC2_MASK                            0x00000004
#define AVR32_ADC_IMR_EOC2_OFFSET                                   2
#define AVR32_ADC_IMR_EOC2_SIZE                                     1
#define AVR32_ADC_IMR_EOC3                                          3
#define AVR32_ADC_IMR_EOC3_MASK                            0x00000008
#define AVR32_ADC_IMR_EOC3_OFFSET                                   3
#define AVR32_ADC_IMR_EOC3_SIZE                                     1
#define AVR32_ADC_IMR_EOC4                                          4
#define AVR32_ADC_IMR_EOC4_MASK                            0x00000010
#define AVR32_ADC_IMR_EOC4_OFFSET                                   4
#define AVR32_ADC_IMR_EOC4_SIZE                                     1
#define AVR32_ADC_IMR_EOC5                                          5
#define AVR32_ADC_IMR_EOC5_MASK                            0x00000020
#define AVR32_ADC_IMR_EOC5_OFFSET                                   5
#define AVR32_ADC_IMR_EOC5_SIZE                                     1
#define AVR32_ADC_IMR_EOC6                                          6
#define AVR32_ADC_IMR_EOC6_MASK                            0x00000040
#define AVR32_ADC_IMR_EOC6_OFFSET                                   6
#define AVR32_ADC_IMR_EOC6_SIZE                                     1
#define AVR32_ADC_IMR_EOC7                                          7
#define AVR32_ADC_IMR_EOC7_MASK                            0x00000080
#define AVR32_ADC_IMR_EOC7_OFFSET                                   7
#define AVR32_ADC_IMR_EOC7_SIZE                                     1
#define AVR32_ADC_IMR_GOVRE                                        17
#define AVR32_ADC_IMR_GOVRE_MASK                           0x00020000
#define AVR32_ADC_IMR_GOVRE_OFFSET                                 17
#define AVR32_ADC_IMR_GOVRE_SIZE                                    1
#define AVR32_ADC_IMR_OVRE0                                         8
#define AVR32_ADC_IMR_OVRE0_MASK                           0x00000100
#define AVR32_ADC_IMR_OVRE0_OFFSET                                  8
#define AVR32_ADC_IMR_OVRE0_SIZE                                    1
#define AVR32_ADC_IMR_OVRE1                                         9
#define AVR32_ADC_IMR_OVRE1_MASK                           0x00000200
#define AVR32_ADC_IMR_OVRE1_OFFSET                                  9
#define AVR32_ADC_IMR_OVRE1_SIZE                                    1
#define AVR32_ADC_IMR_OVRE2                                        10
#define AVR32_ADC_IMR_OVRE2_MASK                           0x00000400
#define AVR32_ADC_IMR_OVRE2_OFFSET                                 10
#define AVR32_ADC_IMR_OVRE2_SIZE                                    1
#define AVR32_ADC_IMR_OVRE3                                        11
#define AVR32_ADC_IMR_OVRE3_MASK                           0x00000800
#define AVR32_ADC_IMR_OVRE3_OFFSET                                 11
#define AVR32_ADC_IMR_OVRE3_SIZE                                    1
#define AVR32_ADC_IMR_OVRE4                                        12
#define AVR32_ADC_IMR_OVRE4_MASK                           0x00001000
#define AVR32_ADC_IMR_OVRE4_OFFSET                                 12
#define AVR32_ADC_IMR_OVRE4_SIZE                                    1
#define AVR32_ADC_IMR_OVRE5                                        13
#define AVR32_ADC_IMR_OVRE5_MASK                           0x00002000
#define AVR32_ADC_IMR_OVRE5_OFFSET                                 13
#define AVR32_ADC_IMR_OVRE5_SIZE                                    1
#define AVR32_ADC_IMR_OVRE6                                        14
#define AVR32_ADC_IMR_OVRE6_MASK                           0x00004000
#define AVR32_ADC_IMR_OVRE6_OFFSET                                 14
#define AVR32_ADC_IMR_OVRE6_SIZE                                    1
#define AVR32_ADC_IMR_OVRE7                                        15
#define AVR32_ADC_IMR_OVRE7_MASK                           0x00008000
#define AVR32_ADC_IMR_OVRE7_OFFSET                                 15
#define AVR32_ADC_IMR_OVRE7_SIZE                                    1
#define AVR32_ADC_IMR_RXBUFF                                       19
#define AVR32_ADC_IMR_RXBUFF_MASK                          0x00080000
#define AVR32_ADC_IMR_RXBUFF_OFFSET                                19
#define AVR32_ADC_IMR_RXBUFF_SIZE                                   1
#define AVR32_ADC_LCDR                                     0x00000020
#define AVR32_ADC_LCDR_LDATA                                        0
#define AVR32_ADC_LCDR_LDATA_MASK                          0x000003ff
#define AVR32_ADC_LCDR_LDATA_OFFSET                                 0
#define AVR32_ADC_LCDR_LDATA_SIZE                                  10
#define AVR32_ADC_LDATA                                             0
#define AVR32_ADC_LDATA_MASK                               0x000003ff
#define AVR32_ADC_LDATA_OFFSET                                      0
#define AVR32_ADC_LDATA_SIZE                                       10
#define AVR32_ADC_LOWRES                                            4
#define AVR32_ADC_LOWRES_MASK                              0x00000010
#define AVR32_ADC_LOWRES_OFFSET                                     4
#define AVR32_ADC_LOWRES_SIZE                                       1
#define AVR32_ADC_MR                                       0x00000004
#define AVR32_ADC_MR_LOWRES                                         4
#define AVR32_ADC_MR_LOWRES_MASK                           0x00000010
#define AVR32_ADC_MR_LOWRES_OFFSET                                  4
#define AVR32_ADC_MR_LOWRES_SIZE                                    1
#define AVR32_ADC_MR_PRESCAL                                        8
#define AVR32_ADC_MR_PRESCAL_MASK                          0x0000ff00
#define AVR32_ADC_MR_PRESCAL_OFFSET                                 8
#define AVR32_ADC_MR_PRESCAL_SIZE                                   8
#define AVR32_ADC_MR_SHTIM                                         24
#define AVR32_ADC_MR_SHTIM_MASK                            0x0f000000
#define AVR32_ADC_MR_SHTIM_OFFSET                                  24
#define AVR32_ADC_MR_SHTIM_SIZE                                     4
#define AVR32_ADC_MR_SLEEP                                          5
#define AVR32_ADC_MR_SLEEP_MASK                            0x00000020
#define AVR32_ADC_MR_SLEEP_OFFSET                                   5
#define AVR32_ADC_MR_SLEEP_SIZE                                     1
#define AVR32_ADC_MR_STARTUP                                       16
#define AVR32_ADC_MR_STARTUP_MASK                          0x007f0000
#define AVR32_ADC_MR_STARTUP_OFFSET                                16
#define AVR32_ADC_MR_STARTUP_SIZE                                   7
#define AVR32_ADC_MR_TRGEN                                          0
#define AVR32_ADC_MR_TRGEN_MASK                            0x00000001
#define AVR32_ADC_MR_TRGEN_OFFSET                                   0
#define AVR32_ADC_MR_TRGEN_SIZE                                     1
#define AVR32_ADC_MR_TRGSEL                                         1
#define AVR32_ADC_MR_TRGSEL_MASK                           0x0000000e
#define AVR32_ADC_MR_TRGSEL_OFFSET                                  1
#define AVR32_ADC_MR_TRGSEL_SIZE                                    3
#define AVR32_ADC_OVRE0                                             8
#define AVR32_ADC_OVRE0_MASK                               0x00000100
#define AVR32_ADC_OVRE0_OFFSET                                      8
#define AVR32_ADC_OVRE0_SIZE                                        1
#define AVR32_ADC_OVRE1                                             9
#define AVR32_ADC_OVRE1_MASK                               0x00000200
#define AVR32_ADC_OVRE1_OFFSET                                      9
#define AVR32_ADC_OVRE1_SIZE                                        1
#define AVR32_ADC_OVRE2                                            10
#define AVR32_ADC_OVRE2_MASK                               0x00000400
#define AVR32_ADC_OVRE2_OFFSET                                     10
#define AVR32_ADC_OVRE2_SIZE                                        1
#define AVR32_ADC_OVRE3                                            11
#define AVR32_ADC_OVRE3_MASK                               0x00000800
#define AVR32_ADC_OVRE3_OFFSET                                     11
#define AVR32_ADC_OVRE3_SIZE                                        1
#define AVR32_ADC_OVRE4                                            12
#define AVR32_ADC_OVRE4_MASK                               0x00001000
#define AVR32_ADC_OVRE4_OFFSET                                     12
#define AVR32_ADC_OVRE4_SIZE                                        1
#define AVR32_ADC_OVRE5                                            13
#define AVR32_ADC_OVRE5_MASK                               0x00002000
#define AVR32_ADC_OVRE5_OFFSET                                     13
#define AVR32_ADC_OVRE5_SIZE                                        1
#define AVR32_ADC_OVRE6                                            14
#define AVR32_ADC_OVRE6_MASK                               0x00004000
#define AVR32_ADC_OVRE6_OFFSET                                     14
#define AVR32_ADC_OVRE6_SIZE                                        1
#define AVR32_ADC_OVRE7                                            15
#define AVR32_ADC_OVRE7_MASK                               0x00008000
#define AVR32_ADC_OVRE7_OFFSET                                     15
#define AVR32_ADC_OVRE7_SIZE                                        1
#define AVR32_ADC_PRESCAL                                           8
#define AVR32_ADC_PRESCAL_MASK                             0x0000ff00
#define AVR32_ADC_PRESCAL_OFFSET                                    8
#define AVR32_ADC_PRESCAL_SIZE                                      8
#define AVR32_ADC_RXBUFF                                           19
#define AVR32_ADC_RXBUFF_MASK                              0x00080000
#define AVR32_ADC_RXBUFF_OFFSET                                    19
#define AVR32_ADC_RXBUFF_SIZE                                       1
#define AVR32_ADC_SHTIM                                            24
#define AVR32_ADC_SHTIM_MASK                               0x0f000000
#define AVR32_ADC_SHTIM_OFFSET                                     24
#define AVR32_ADC_SHTIM_SIZE                                        4
#define AVR32_ADC_SLEEP                                             5
#define AVR32_ADC_SLEEP_MASK                               0x00000020
#define AVR32_ADC_SLEEP_OFFSET                                      5
#define AVR32_ADC_SLEEP_SIZE                                        1
#define AVR32_ADC_SR                                       0x0000001c
#define AVR32_ADC_SR_DRDY                                          16
#define AVR32_ADC_SR_DRDY_MASK                             0x00010000
#define AVR32_ADC_SR_DRDY_OFFSET                                   16
#define AVR32_ADC_SR_DRDY_SIZE                                      1
#define AVR32_ADC_SR_ENDRX                                         18
#define AVR32_ADC_SR_ENDRX_MASK                            0x00040000
#define AVR32_ADC_SR_ENDRX_OFFSET                                  18
#define AVR32_ADC_SR_ENDRX_SIZE                                     1
#define AVR32_ADC_SR_EOC0                                           0
#define AVR32_ADC_SR_EOC0_MASK                             0x00000001
#define AVR32_ADC_SR_EOC0_OFFSET                                    0
#define AVR32_ADC_SR_EOC0_SIZE                                      1
#define AVR32_ADC_SR_EOC1                                           1
#define AVR32_ADC_SR_EOC1_MASK                             0x00000002
#define AVR32_ADC_SR_EOC1_OFFSET                                    1
#define AVR32_ADC_SR_EOC1_SIZE                                      1
#define AVR32_ADC_SR_EOC2                                           2
#define AVR32_ADC_SR_EOC2_MASK                             0x00000004
#define AVR32_ADC_SR_EOC2_OFFSET                                    2
#define AVR32_ADC_SR_EOC2_SIZE                                      1
#define AVR32_ADC_SR_EOC3                                           3
#define AVR32_ADC_SR_EOC3_MASK                             0x00000008
#define AVR32_ADC_SR_EOC3_OFFSET                                    3
#define AVR32_ADC_SR_EOC3_SIZE                                      1
#define AVR32_ADC_SR_EOC4                                           4
#define AVR32_ADC_SR_EOC4_MASK                             0x00000010
#define AVR32_ADC_SR_EOC4_OFFSET                                    4
#define AVR32_ADC_SR_EOC4_SIZE                                      1
#define AVR32_ADC_SR_EOC5                                           5
#define AVR32_ADC_SR_EOC5_MASK                             0x00000020
#define AVR32_ADC_SR_EOC5_OFFSET                                    5
#define AVR32_ADC_SR_EOC5_SIZE                                      1
#define AVR32_ADC_SR_EOC6                                           6
#define AVR32_ADC_SR_EOC6_MASK                             0x00000040
#define AVR32_ADC_SR_EOC6_OFFSET                                    6
#define AVR32_ADC_SR_EOC6_SIZE                                      1
#define AVR32_ADC_SR_EOC7                                           7
#define AVR32_ADC_SR_EOC7_MASK                             0x00000080
#define AVR32_ADC_SR_EOC7_OFFSET                                    7
#define AVR32_ADC_SR_EOC7_SIZE                                      1
#define AVR32_ADC_SR_GOVRE                                         17
#define AVR32_ADC_SR_GOVRE_MASK                            0x00020000
#define AVR32_ADC_SR_GOVRE_OFFSET                                  17
#define AVR32_ADC_SR_GOVRE_SIZE                                     1
#define AVR32_ADC_SR_OVRE0                                          8
#define AVR32_ADC_SR_OVRE0_MASK                            0x00000100
#define AVR32_ADC_SR_OVRE0_OFFSET                                   8
#define AVR32_ADC_SR_OVRE0_SIZE                                     1
#define AVR32_ADC_SR_OVRE1                                          9
#define AVR32_ADC_SR_OVRE1_MASK                            0x00000200
#define AVR32_ADC_SR_OVRE1_OFFSET                                   9
#define AVR32_ADC_SR_OVRE1_SIZE                                     1
#define AVR32_ADC_SR_OVRE2                                         10
#define AVR32_ADC_SR_OVRE2_MASK                            0x00000400
#define AVR32_ADC_SR_OVRE2_OFFSET                                  10
#define AVR32_ADC_SR_OVRE2_SIZE                                     1
#define AVR32_ADC_SR_OVRE3                                         11
#define AVR32_ADC_SR_OVRE3_MASK                            0x00000800
#define AVR32_ADC_SR_OVRE3_OFFSET                                  11
#define AVR32_ADC_SR_OVRE3_SIZE                                     1
#define AVR32_ADC_SR_OVRE4                                         12
#define AVR32_ADC_SR_OVRE4_MASK                            0x00001000
#define AVR32_ADC_SR_OVRE4_OFFSET                                  12
#define AVR32_ADC_SR_OVRE4_SIZE                                     1
#define AVR32_ADC_SR_OVRE5                                         13
#define AVR32_ADC_SR_OVRE5_MASK                            0x00002000
#define AVR32_ADC_SR_OVRE5_OFFSET                                  13
#define AVR32_ADC_SR_OVRE5_SIZE                                     1
#define AVR32_ADC_SR_OVRE6                                         14
#define AVR32_ADC_SR_OVRE6_MASK                            0x00004000
#define AVR32_ADC_SR_OVRE6_OFFSET                                  14
#define AVR32_ADC_SR_OVRE6_SIZE                                     1
#define AVR32_ADC_SR_OVRE7                                         15
#define AVR32_ADC_SR_OVRE7_MASK                            0x00008000
#define AVR32_ADC_SR_OVRE7_OFFSET                                  15
#define AVR32_ADC_SR_OVRE7_SIZE                                     1
#define AVR32_ADC_SR_RXBUFF                                        19
#define AVR32_ADC_SR_RXBUFF_MASK                           0x00080000
#define AVR32_ADC_SR_RXBUFF_OFFSET                                 19
#define AVR32_ADC_SR_RXBUFF_SIZE                                    1
#define AVR32_ADC_START                                             1
#define AVR32_ADC_STARTUP                                          16
#define AVR32_ADC_STARTUP_MASK                             0x007f0000
#define AVR32_ADC_STARTUP_OFFSET                                   16
#define AVR32_ADC_STARTUP_SIZE                                      7
#define AVR32_ADC_START_MASK                               0x00000002
#define AVR32_ADC_START_OFFSET                                      1
#define AVR32_ADC_START_SIZE                                        1
#define AVR32_ADC_SWRST                                             0
#define AVR32_ADC_SWRST_MASK                               0x00000001
#define AVR32_ADC_SWRST_OFFSET                                      0
#define AVR32_ADC_SWRST_SIZE                                        1
#define AVR32_ADC_TRGEN                                             0
#define AVR32_ADC_TRGEN_MASK                               0x00000001
#define AVR32_ADC_TRGEN_OFFSET                                      0
#define AVR32_ADC_TRGEN_SIZE                                        1
#define AVR32_ADC_TRGSEL                                            1
#define AVR32_ADC_TRGSEL_MASK                              0x0000000e
#define AVR32_ADC_TRGSEL_OFFSET                                     1
#define AVR32_ADC_TRGSEL_SIZE                                       3
#define AVR32_ADC_VARIANT                                          16
#define AVR32_ADC_VARIANT_MASK                             0x00070000
#define AVR32_ADC_VARIANT_OFFSET                                   16
#define AVR32_ADC_VARIANT_SIZE                                      3
#define AVR32_ADC_VERSION                                  0x000000fc
#define AVR32_ADC_VERSION_MASK                             0x00000fff
#define AVR32_ADC_VERSION_OFFSET                                    0
#define AVR32_ADC_VERSION_SIZE                                     12
#define AVR32_ADC_VERSION_VARIANT                                  16
#define AVR32_ADC_VERSION_VARIANT_MASK                     0x00070000
#define AVR32_ADC_VERSION_VARIANT_OFFSET                           16
#define AVR32_ADC_VERSION_VARIANT_SIZE                              3
#define AVR32_ADC_VERSION_VERSION                                   0
#define AVR32_ADC_VERSION_VERSION_MASK                     0x00000fff
#define AVR32_ADC_VERSION_VERSION_OFFSET                            0
#define AVR32_ADC_VERSION_VERSION_SIZE                             12




#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_adc_cr_t {
    unsigned int                 :30;
    unsigned int start           : 1;
    unsigned int swrst           : 1;
} avr32_adc_cr_t;



typedef struct avr32_adc_mr_t {
    unsigned int                 : 4;
    unsigned int shtim           : 4;
    unsigned int                 : 1;
    unsigned int startup         : 7;
    unsigned int prescal         : 8;
    unsigned int                 : 2;
    unsigned int sleep           : 1;
    unsigned int lowres          : 1;
    unsigned int trgsel          : 3;
    unsigned int trgen           : 1;
} avr32_adc_mr_t;



typedef struct avr32_adc_cher_t {
    unsigned int                 :24;
    unsigned int ch7             : 1;
    unsigned int ch6             : 1;
    unsigned int ch5             : 1;
    unsigned int ch4             : 1;
    unsigned int ch3             : 1;
    unsigned int ch2             : 1;
    unsigned int ch1             : 1;
    unsigned int ch0             : 1;
} avr32_adc_cher_t;



typedef struct avr32_adc_chdr_t {
    unsigned int                 :24;
    unsigned int ch7             : 1;
    unsigned int ch6             : 1;
    unsigned int ch5             : 1;
    unsigned int ch4             : 1;
    unsigned int ch3             : 1;
    unsigned int ch2             : 1;
    unsigned int ch1             : 1;
    unsigned int ch0             : 1;
} avr32_adc_chdr_t;



typedef struct avr32_adc_chsr_t {
    unsigned int                 :24;
    unsigned int ch7             : 1;
    unsigned int ch6             : 1;
    unsigned int ch5             : 1;
    unsigned int ch4             : 1;
    unsigned int ch3             : 1;
    unsigned int ch2             : 1;
    unsigned int ch1             : 1;
    unsigned int ch0             : 1;
} avr32_adc_chsr_t;



typedef struct avr32_adc_sr_t {
    unsigned int                 :12;
    unsigned int rxbuff          : 1;
    unsigned int endrx           : 1;
    unsigned int govre           : 1;
    unsigned int drdy            : 1;
    unsigned int ovre7           : 1;
    unsigned int ovre6           : 1;
    unsigned int ovre5           : 1;
    unsigned int ovre4           : 1;
    unsigned int ovre3           : 1;
    unsigned int ovre2           : 1;
    unsigned int ovre1           : 1;
    unsigned int ovre0           : 1;
    unsigned int eoc7            : 1;
    unsigned int eoc6            : 1;
    unsigned int eoc5            : 1;
    unsigned int eoc4            : 1;
    unsigned int eoc3            : 1;
    unsigned int eoc2            : 1;
    unsigned int eoc1            : 1;
    unsigned int eoc0            : 1;
} avr32_adc_sr_t;



typedef struct avr32_adc_lcdr_t {
    unsigned int                 :22;
    unsigned int ldata           :10;
} avr32_adc_lcdr_t;



typedef struct avr32_adc_ier_t {
    unsigned int                 :12;
    unsigned int rxbuff          : 1;
    unsigned int endrx           : 1;
    unsigned int govre           : 1;
    unsigned int drdy            : 1;
    unsigned int ovre7           : 1;
    unsigned int ovre6           : 1;
    unsigned int ovre5           : 1;
    unsigned int ovre4           : 1;
    unsigned int ovre3           : 1;
    unsigned int ovre2           : 1;
    unsigned int ovre1           : 1;
    unsigned int ovre0           : 1;
    unsigned int eoc7            : 1;
    unsigned int eoc6            : 1;
    unsigned int eoc5            : 1;
    unsigned int eoc4            : 1;
    unsigned int eoc3            : 1;
    unsigned int eoc2            : 1;
    unsigned int eoc1            : 1;
    unsigned int eoc0            : 1;
} avr32_adc_ier_t;



typedef struct avr32_adc_idr_t {
    unsigned int                 :12;
    unsigned int rxbuff          : 1;
    unsigned int endrx           : 1;
    unsigned int govre           : 1;
    unsigned int drdy            : 1;
    unsigned int ovre7           : 1;
    unsigned int ovre6           : 1;
    unsigned int ovre5           : 1;
    unsigned int ovre4           : 1;
    unsigned int ovre3           : 1;
    unsigned int ovre2           : 1;
    unsigned int ovre1           : 1;
    unsigned int ovre0           : 1;
    unsigned int eoc7            : 1;
    unsigned int eoc6            : 1;
    unsigned int eoc5            : 1;
    unsigned int eoc4            : 1;
    unsigned int eoc3            : 1;
    unsigned int eoc2            : 1;
    unsigned int eoc1            : 1;
    unsigned int eoc0            : 1;
} avr32_adc_idr_t;



typedef struct avr32_adc_imr_t {
    unsigned int                 :12;
    unsigned int rxbuff          : 1;
    unsigned int endrx           : 1;
    unsigned int govre           : 1;
    unsigned int drdy            : 1;
    unsigned int ovre7           : 1;
    unsigned int ovre6           : 1;
    unsigned int ovre5           : 1;
    unsigned int ovre4           : 1;
    unsigned int ovre3           : 1;
    unsigned int ovre2           : 1;
    unsigned int ovre1           : 1;
    unsigned int ovre0           : 1;
    unsigned int eoc7            : 1;
    unsigned int eoc6            : 1;
    unsigned int eoc5            : 1;
    unsigned int eoc4            : 1;
    unsigned int eoc3            : 1;
    unsigned int eoc2            : 1;
    unsigned int eoc1            : 1;
    unsigned int eoc0            : 1;
} avr32_adc_imr_t;



typedef struct avr32_adc_cdr0_t {
    unsigned int                 :22;
    unsigned int data            :10;
} avr32_adc_cdr0_t;



typedef struct avr32_adc_cdr1_t {
    unsigned int                 :22;
    unsigned int data            :10;
} avr32_adc_cdr1_t;



typedef struct avr32_adc_cdr2_t {
    unsigned int                 :22;
    unsigned int data            :10;
} avr32_adc_cdr2_t;



typedef struct avr32_adc_cdr3_t {
    unsigned int                 :22;
    unsigned int data            :10;
} avr32_adc_cdr3_t;



typedef struct avr32_adc_cdr4_t {
    unsigned int                 :22;
    unsigned int data            :10;
} avr32_adc_cdr4_t;



typedef struct avr32_adc_cdr5_t {
    unsigned int                 :22;
    unsigned int data            :10;
} avr32_adc_cdr5_t;



typedef struct avr32_adc_cdr6_t {
    unsigned int                 :22;
    unsigned int data            :10;
} avr32_adc_cdr6_t;



typedef struct avr32_adc_cdr7_t {
    unsigned int                 :22;
    unsigned int data            :10;
} avr32_adc_cdr7_t;



typedef struct avr32_adc_version_t {
    unsigned int                 :13;
    unsigned int variant         : 3;
    unsigned int                 : 4;
    unsigned int version         :12;
} avr32_adc_version_t;



typedef struct avr32_adc_t {
  union {
          unsigned long                  cr        ;//0x0000
          avr32_adc_cr_t                 CR        ;
  };
  union {
          unsigned long                  mr        ;//0x0004
          avr32_adc_mr_t                 MR        ;
  };
          unsigned int                   :32       ;//0x0008
          unsigned int                   :32       ;//0x000c
  union {
          unsigned long                  cher      ;//0x0010
          avr32_adc_cher_t               CHER      ;
  };
  union {
          unsigned long                  chdr      ;//0x0014
          avr32_adc_chdr_t               CHDR      ;
  };
  union {
    const unsigned long                  chsr      ;//0x0018
    const avr32_adc_chsr_t               CHSR      ;
  };
  union {
    const unsigned long                  sr        ;//0x001c
    const avr32_adc_sr_t                 SR        ;
  };
  union {
    const unsigned long                  lcdr      ;//0x0020
    const avr32_adc_lcdr_t               LCDR      ;
  };
  union {
          unsigned long                  ier       ;//0x0024
          avr32_adc_ier_t                IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0028
          avr32_adc_idr_t                IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x002c
    const avr32_adc_imr_t                IMR       ;
  };
  union {
    const unsigned long                  cdr0      ;//0x0030
    const avr32_adc_cdr0_t               CDR0      ;
  };
  union {
    const unsigned long                  cdr1      ;//0x0034
    const avr32_adc_cdr1_t               CDR1      ;
  };
  union {
    const unsigned long                  cdr2      ;//0x0038
    const avr32_adc_cdr2_t               CDR2      ;
  };
  union {
    const unsigned long                  cdr3      ;//0x003c
    const avr32_adc_cdr3_t               CDR3      ;
  };
  union {
    const unsigned long                  cdr4      ;//0x0040
    const avr32_adc_cdr4_t               CDR4      ;
  };
  union {
    const unsigned long                  cdr5      ;//0x0044
    const avr32_adc_cdr5_t               CDR5      ;
  };
  union {
    const unsigned long                  cdr6      ;//0x0048
    const avr32_adc_cdr6_t               CDR6      ;
  };
  union {
    const unsigned long                  cdr7      ;//0x004c
    const avr32_adc_cdr7_t               CDR7      ;
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
    const avr32_adc_version_t            VERSION   ;
  };
} avr32_adc_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif

/*#ifdef AVR32_ADC_200_H_INCLUDED*/
#endif

