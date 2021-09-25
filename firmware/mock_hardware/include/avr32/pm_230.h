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
 * Revision     : $Revision: 74808 $
 * Checkin Date : $Date: 2010-05-16 22:06:32 +0200 (Sun, 16 May 2010) $ 
 *
 ****************************************************************************/
#ifndef AVR32_PM_230_H_INCLUDED
#define AVR32_PM_230_H_INCLUDED

#define AVR32_PM_H_VERSION 230

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_PM_<register>
 - Bitfield mask:   AVR32_PM_<register>_<bitfield>
 - Bitfield offset: AVR32_PM_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_PM_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_PM_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_PM_<bitfield>
 - Bitfield offset: AVR32_PM_<bitfield>_OFFSET
 - Bitfield size:   AVR32_PM_<bitfield>_SIZE
 - Bitfield values: AVR32_PM_<bitfield>_<value name>
 - Bitfield values: AVR32_PM_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_PM_AWEN                                     0x00000144
#define AVR32_PM_AWEN_USB_WAKEN                                    0
#define AVR32_PM_AWEN_USB_WAKEN_MASK                      0x00000001
#define AVR32_PM_AWEN_USB_WAKEN_OFFSET                             0
#define AVR32_PM_AWEN_USB_WAKEN_SIZE                               1
#define AVR32_PM_BGCR                                     0x000000c4
#define AVR32_PM_BGCR_CALIB                                        0
#define AVR32_PM_BGCR_CALIB_MASK                          0x00000007
#define AVR32_PM_BGCR_CALIB_OFFSET                                 0
#define AVR32_PM_BGCR_CALIB_SIZE                                   3
#define AVR32_PM_BGCR_FCD                                         16
#define AVR32_PM_BGCR_FCD_MASK                            0x00010000
#define AVR32_PM_BGCR_FCD_OFFSET                                  16
#define AVR32_PM_BGCR_FCD_SIZE                                     1
#define AVR32_PM_BGCR_KEY                                         24
#define AVR32_PM_BGCR_KEY_MASK                            0xff000000
#define AVR32_PM_BGCR_KEY_OFFSET                                  24
#define AVR32_PM_BGCR_KEY_SIZE                                     8
#define AVR32_PM_BOD                                      0x000000d0
#define AVR32_PM_BODDET                                           16
#define AVR32_PM_BODDET_MASK                              0x00010000
#define AVR32_PM_BODDET_OFFSET                                    16
#define AVR32_PM_BODDET_SIZE                                       1
#define AVR32_PM_BOD_CTRL                                          8
#define AVR32_PM_BOD_CTRL_ENABLED                         0x00000001
#define AVR32_PM_BOD_CTRL_ENABLED_NORESET                 0x00000002
#define AVR32_PM_BOD_CTRL_MASK                            0x00000300
#define AVR32_PM_BOD_CTRL_OFF1                            0x00000000
#define AVR32_PM_BOD_CTRL_OFF2                            0x00000003
#define AVR32_PM_BOD_CTRL_OFFSET                                   8
#define AVR32_PM_BOD_CTRL_SIZE                                     2
#define AVR32_PM_BOD_FCD                                          16
#define AVR32_PM_BOD_FCD_MASK                             0x00010000
#define AVR32_PM_BOD_FCD_OFFSET                                   16
#define AVR32_PM_BOD_FCD_SIZE                                      1
#define AVR32_PM_BOD_HYST                                          6
#define AVR32_PM_BOD_HYST_MASK                            0x00000040
#define AVR32_PM_BOD_HYST_OFFSET                                   6
#define AVR32_PM_BOD_HYST_SIZE                                     1
#define AVR32_PM_BOD_KEY                                          24
#define AVR32_PM_BOD_KEY_MASK                             0xff000000
#define AVR32_PM_BOD_KEY_OFFSET                                   24
#define AVR32_PM_BOD_KEY_SIZE                                      8
#define AVR32_PM_BOD_LEVEL                                         0
#define AVR32_PM_BOD_LEVEL_MASK                           0x0000003f
#define AVR32_PM_BOD_LEVEL_OFFSET                                  0
#define AVR32_PM_BOD_LEVEL_SIZE                                    6
#define AVR32_PM_BOD_MASK                                 0x00000002
#define AVR32_PM_BOD_OFFSET                                        1
#define AVR32_PM_BOD_SIZE                                          1
#define AVR32_PM_CALIB                                             0
#define AVR32_PM_CALIB_OFFSET                                      0
#define AVR32_PM_CEN                                               2
#define AVR32_PM_CEN_MASK                                 0x00000004
#define AVR32_PM_CEN_OFFSET                                        2
#define AVR32_PM_CEN_SIZE                                          1
#define AVR32_PM_CKRDY                                             5
#define AVR32_PM_CKRDY_MASK                               0x00000020
#define AVR32_PM_CKRDY_OFFSET                                      5
#define AVR32_PM_CKRDY_SIZE                                        1
#define AVR32_PM_CKSEL                                    0x00000004
#define AVR32_PM_CKSEL_CPUDIV                                      7
#define AVR32_PM_CKSEL_CPUDIV_MASK                        0x00000080
#define AVR32_PM_CKSEL_CPUDIV_OFFSET                               7
#define AVR32_PM_CKSEL_CPUDIV_SIZE                                 1
#define AVR32_PM_CKSEL_CPUSEL                                      0
#define AVR32_PM_CKSEL_CPUSEL_MASK                        0x00000007
#define AVR32_PM_CKSEL_CPUSEL_OFFSET                               0
#define AVR32_PM_CKSEL_CPUSEL_SIZE                                 3
#define AVR32_PM_CKSEL_HSBDIV                                     15
#define AVR32_PM_CKSEL_HSBDIV_MASK                        0x00008000
#define AVR32_PM_CKSEL_HSBDIV_OFFSET                              15
#define AVR32_PM_CKSEL_HSBDIV_SIZE                                 1
#define AVR32_PM_CKSEL_HSBSEL                                      8
#define AVR32_PM_CKSEL_HSBSEL_MASK                        0x00000700
#define AVR32_PM_CKSEL_HSBSEL_OFFSET                               8
#define AVR32_PM_CKSEL_HSBSEL_SIZE                                 3
#define AVR32_PM_CKSEL_PBADIV                                     23
#define AVR32_PM_CKSEL_PBADIV_MASK                        0x00800000
#define AVR32_PM_CKSEL_PBADIV_OFFSET                              23
#define AVR32_PM_CKSEL_PBADIV_SIZE                                 1
#define AVR32_PM_CKSEL_PBASEL                                     16
#define AVR32_PM_CKSEL_PBASEL_MASK                        0x00070000
#define AVR32_PM_CKSEL_PBASEL_OFFSET                              16
#define AVR32_PM_CKSEL_PBASEL_SIZE                                 3
#define AVR32_PM_CKSEL_PBBDIV                                     31
#define AVR32_PM_CKSEL_PBBDIV_MASK                        0x80000000
#define AVR32_PM_CKSEL_PBBDIV_OFFSET                              31
#define AVR32_PM_CKSEL_PBBDIV_SIZE                                 1
#define AVR32_PM_CKSEL_PBBSEL                                     24
#define AVR32_PM_CKSEL_PBBSEL_MASK                        0x07000000
#define AVR32_PM_CKSEL_PBBSEL_OFFSET                              24
#define AVR32_PM_CKSEL_PBBSEL_SIZE                                 3
#define AVR32_PM_CLKMASK                                  0x00000008
#define AVR32_PM_CPUDIV                                            7
#define AVR32_PM_CPUDIV_MASK                              0x00000080
#define AVR32_PM_CPUDIV_OFFSET                                     7
#define AVR32_PM_CPUDIV_SIZE                                       1
#define AVR32_PM_CPUERR                                            7
#define AVR32_PM_CPUERR_MASK                              0x00000080
#define AVR32_PM_CPUERR_OFFSET                                     7
#define AVR32_PM_CPUERR_SIZE                                       1
#define AVR32_PM_CPUMASK                                  0x00000008
#define AVR32_PM_CPUSEL                                            0
#define AVR32_PM_CPUSEL_MASK                              0x00000007
#define AVR32_PM_CPUSEL_OFFSET                                     0
#define AVR32_PM_CPUSEL_SIZE                                       3
#define AVR32_PM_CRYSTAL                                  0x00000001
#define AVR32_PM_CRYSTAL_G0                               0x00000004
#define AVR32_PM_CRYSTAL_G1                               0x00000005
#define AVR32_PM_CRYSTAL_G2                               0x00000006
#define AVR32_PM_CRYSTAL_G3                               0x00000007
#define AVR32_PM_CTRL                                              8
#define AVR32_PM_CTRL_ENABLED                             0x00000001
#define AVR32_PM_CTRL_ENABLED_NORESET                     0x00000002
#define AVR32_PM_CTRL_MASK                                0x00000300
#define AVR32_PM_CTRL_OFF1                                0x00000000
#define AVR32_PM_CTRL_OFF2                                0x00000003
#define AVR32_PM_CTRL_OFFSET                                       8
#define AVR32_PM_CTRL_SIZE                                         2
#define AVR32_PM_DIV                                               8
#define AVR32_PM_DIVEN                                             4
#define AVR32_PM_DIVEN_MASK                               0x00000010
#define AVR32_PM_DIVEN_OFFSET                                      4
#define AVR32_PM_DIVEN_SIZE                                        1
#define AVR32_PM_DIV_MASK                                 0x0000ff00
#define AVR32_PM_DIV_OFFSET                                        8
#define AVR32_PM_DIV_SIZE                                          8
#define AVR32_PM_ENABLED                                  0x00000001
#define AVR32_PM_ENABLED_NORESET                          0x00000002
#define AVR32_PM_EXT                                               2
#define AVR32_PM_EXT_CLOCK                                0x00000000
#define AVR32_PM_EXT_MASK                                 0x00000004
#define AVR32_PM_EXT_OFFSET                                        2
#define AVR32_PM_EXT_SIZE                                          1
#define AVR32_PM_FCD                                              16
#define AVR32_PM_FCD_MASK                                 0x00010000
#define AVR32_PM_FCD_OFFSET                                       16
#define AVR32_PM_FCD_SIZE                                          1
#define AVR32_PM_GCCTRL                                   0x00000060
#define AVR32_PM_GCCTRL_CEN                                        2
#define AVR32_PM_GCCTRL_CEN_MASK                          0x00000004
#define AVR32_PM_GCCTRL_CEN_OFFSET                                 2
#define AVR32_PM_GCCTRL_CEN_SIZE                                   1
#define AVR32_PM_GCCTRL_DIV                                        8
#define AVR32_PM_GCCTRL_DIVEN                                      4
#define AVR32_PM_GCCTRL_DIVEN_MASK                        0x00000010
#define AVR32_PM_GCCTRL_DIVEN_OFFSET                               4
#define AVR32_PM_GCCTRL_DIVEN_SIZE                                 1
#define AVR32_PM_GCCTRL_DIV_MASK                          0x0000ff00
#define AVR32_PM_GCCTRL_DIV_OFFSET                                 8
#define AVR32_PM_GCCTRL_DIV_SIZE                                   8
#define AVR32_PM_GCCTRL_OSCSEL                                     0
#define AVR32_PM_GCCTRL_OSCSEL_MASK                       0x00000001
#define AVR32_PM_GCCTRL_OSCSEL_OFFSET                              0
#define AVR32_PM_GCCTRL_OSCSEL_SIZE                                1
#define AVR32_PM_GCCTRL_PLLSEL                                     1
#define AVR32_PM_GCCTRL_PLLSEL_MASK                       0x00000002
#define AVR32_PM_GCCTRL_PLLSEL_OFFSET                              1
#define AVR32_PM_GCCTRL_PLLSEL_SIZE                                1
#define AVR32_PM_GPLP                                     0x00000200
#define AVR32_PM_HSBDIV                                           15
#define AVR32_PM_HSBDIV_MASK                              0x00008000
#define AVR32_PM_HSBDIV_OFFSET                                    15
#define AVR32_PM_HSBDIV_SIZE                                       1
#define AVR32_PM_HSBMASK                                  0x0000000c
#define AVR32_PM_HSBSEL                                            8
#define AVR32_PM_HSBSEL_MASK                              0x00000700
#define AVR32_PM_HSBSEL_OFFSET                                     8
#define AVR32_PM_HSBSEL_SIZE                                       3
#define AVR32_PM_HYST                                              6
#define AVR32_PM_HYST_MASK                                0x00000040
#define AVR32_PM_HYST_OFFSET                                       6
#define AVR32_PM_HYST_SIZE                                         1
#define AVR32_PM_ICR                                      0x00000050
#define AVR32_PM_ICR_BODDET                                       16
#define AVR32_PM_ICR_BODDET_MASK                          0x00010000
#define AVR32_PM_ICR_BODDET_OFFSET                                16
#define AVR32_PM_ICR_BODDET_SIZE                                   1
#define AVR32_PM_ICR_CKRDY                                         5
#define AVR32_PM_ICR_CKRDY_MASK                           0x00000020
#define AVR32_PM_ICR_CKRDY_OFFSET                                  5
#define AVR32_PM_ICR_CKRDY_SIZE                                    1
#define AVR32_PM_ICR_LOCK0                                         0
#define AVR32_PM_ICR_LOCK0_MASK                           0x00000001
#define AVR32_PM_ICR_LOCK0_OFFSET                                  0
#define AVR32_PM_ICR_LOCK0_SIZE                                    1
#define AVR32_PM_ICR_LOCK1                                         1
#define AVR32_PM_ICR_LOCK1_MASK                           0x00000002
#define AVR32_PM_ICR_LOCK1_OFFSET                                  1
#define AVR32_PM_ICR_LOCK1_SIZE                                    1
#define AVR32_PM_ICR_MSKRDY                                        6
#define AVR32_PM_ICR_MSKRDY_MASK                          0x00000040
#define AVR32_PM_ICR_MSKRDY_OFFSET                                 6
#define AVR32_PM_ICR_MSKRDY_SIZE                                   1
#define AVR32_PM_ICR_OSC0RDY                                       7
#define AVR32_PM_ICR_OSC0RDY_MASK                         0x00000080
#define AVR32_PM_ICR_OSC0RDY_OFFSET                                7
#define AVR32_PM_ICR_OSC0RDY_SIZE                                  1
#define AVR32_PM_ICR_OSC1RDY                                       8
#define AVR32_PM_ICR_OSC1RDY_MASK                         0x00000100
#define AVR32_PM_ICR_OSC1RDY_OFFSET                                8
#define AVR32_PM_ICR_OSC1RDY_SIZE                                  1
#define AVR32_PM_ICR_OSC32RDY                                      9
#define AVR32_PM_ICR_OSC32RDY_MASK                        0x00000200
#define AVR32_PM_ICR_OSC32RDY_OFFSET                               9
#define AVR32_PM_ICR_OSC32RDY_SIZE                                 1
#define AVR32_PM_IDR                                      0x00000044
#define AVR32_PM_IDR_BODDET                                       16
#define AVR32_PM_IDR_BODDET_MASK                          0x00010000
#define AVR32_PM_IDR_BODDET_OFFSET                                16
#define AVR32_PM_IDR_BODDET_SIZE                                   1
#define AVR32_PM_IDR_CKRDY                                         5
#define AVR32_PM_IDR_CKRDY_MASK                           0x00000020
#define AVR32_PM_IDR_CKRDY_OFFSET                                  5
#define AVR32_PM_IDR_CKRDY_SIZE                                    1
#define AVR32_PM_IDR_LOCK0                                         0
#define AVR32_PM_IDR_LOCK0_MASK                           0x00000001
#define AVR32_PM_IDR_LOCK0_OFFSET                                  0
#define AVR32_PM_IDR_LOCK0_SIZE                                    1
#define AVR32_PM_IDR_LOCK1                                         1
#define AVR32_PM_IDR_LOCK1_MASK                           0x00000002
#define AVR32_PM_IDR_LOCK1_OFFSET                                  1
#define AVR32_PM_IDR_LOCK1_SIZE                                    1
#define AVR32_PM_IDR_MSKRDY                                        6
#define AVR32_PM_IDR_MSKRDY_MASK                          0x00000040
#define AVR32_PM_IDR_MSKRDY_OFFSET                                 6
#define AVR32_PM_IDR_MSKRDY_SIZE                                   1
#define AVR32_PM_IDR_OSC0RDY                                       7
#define AVR32_PM_IDR_OSC0RDY_MASK                         0x00000080
#define AVR32_PM_IDR_OSC0RDY_OFFSET                                7
#define AVR32_PM_IDR_OSC0RDY_SIZE                                  1
#define AVR32_PM_IDR_OSC1RDY                                       8
#define AVR32_PM_IDR_OSC1RDY_MASK                         0x00000100
#define AVR32_PM_IDR_OSC1RDY_OFFSET                                8
#define AVR32_PM_IDR_OSC1RDY_SIZE                                  1
#define AVR32_PM_IDR_OSC32RDY                                      9
#define AVR32_PM_IDR_OSC32RDY_MASK                        0x00000200
#define AVR32_PM_IDR_OSC32RDY_OFFSET                               9
#define AVR32_PM_IDR_OSC32RDY_SIZE                                 1
#define AVR32_PM_IER                                      0x00000040
#define AVR32_PM_IER_BODDET                                       16
#define AVR32_PM_IER_BODDET_MASK                          0x00010000
#define AVR32_PM_IER_BODDET_OFFSET                                16
#define AVR32_PM_IER_BODDET_SIZE                                   1
#define AVR32_PM_IER_CKRDY                                         5
#define AVR32_PM_IER_CKRDY_MASK                           0x00000020
#define AVR32_PM_IER_CKRDY_OFFSET                                  5
#define AVR32_PM_IER_CKRDY_SIZE                                    1
#define AVR32_PM_IER_LOCK0                                         0
#define AVR32_PM_IER_LOCK0_MASK                           0x00000001
#define AVR32_PM_IER_LOCK0_OFFSET                                  0
#define AVR32_PM_IER_LOCK0_SIZE                                    1
#define AVR32_PM_IER_LOCK1                                         1
#define AVR32_PM_IER_LOCK1_MASK                           0x00000002
#define AVR32_PM_IER_LOCK1_OFFSET                                  1
#define AVR32_PM_IER_LOCK1_SIZE                                    1
#define AVR32_PM_IER_MSKRDY                                        6
#define AVR32_PM_IER_MSKRDY_MASK                          0x00000040
#define AVR32_PM_IER_MSKRDY_OFFSET                                 6
#define AVR32_PM_IER_MSKRDY_SIZE                                   1
#define AVR32_PM_IER_OSC0RDY                                       7
#define AVR32_PM_IER_OSC0RDY_MASK                         0x00000080
#define AVR32_PM_IER_OSC0RDY_OFFSET                                7
#define AVR32_PM_IER_OSC0RDY_SIZE                                  1
#define AVR32_PM_IER_OSC1RDY                                       8
#define AVR32_PM_IER_OSC1RDY_MASK                         0x00000100
#define AVR32_PM_IER_OSC1RDY_OFFSET                                8
#define AVR32_PM_IER_OSC1RDY_SIZE                                  1
#define AVR32_PM_IER_OSC32RDY                                      9
#define AVR32_PM_IER_OSC32RDY_MASK                        0x00000200
#define AVR32_PM_IER_OSC32RDY_OFFSET                               9
#define AVR32_PM_IER_OSC32RDY_SIZE                                 1
#define AVR32_PM_IMR                                      0x00000048
#define AVR32_PM_IMR_BODDET                                       16
#define AVR32_PM_IMR_BODDET_MASK                          0x00010000
#define AVR32_PM_IMR_BODDET_OFFSET                                16
#define AVR32_PM_IMR_BODDET_SIZE                                   1
#define AVR32_PM_IMR_CKRDY                                         5
#define AVR32_PM_IMR_CKRDY_MASK                           0x00000020
#define AVR32_PM_IMR_CKRDY_OFFSET                                  5
#define AVR32_PM_IMR_CKRDY_SIZE                                    1
#define AVR32_PM_IMR_LOCK0                                         0
#define AVR32_PM_IMR_LOCK0_MASK                           0x00000001
#define AVR32_PM_IMR_LOCK0_OFFSET                                  0
#define AVR32_PM_IMR_LOCK0_SIZE                                    1
#define AVR32_PM_IMR_LOCK1                                         1
#define AVR32_PM_IMR_LOCK1_MASK                           0x00000002
#define AVR32_PM_IMR_LOCK1_OFFSET                                  1
#define AVR32_PM_IMR_LOCK1_SIZE                                    1
#define AVR32_PM_IMR_MSKRDY                                        6
#define AVR32_PM_IMR_MSKRDY_MASK                          0x00000040
#define AVR32_PM_IMR_MSKRDY_OFFSET                                 6
#define AVR32_PM_IMR_MSKRDY_SIZE                                   1
#define AVR32_PM_IMR_OSC0RDY                                       7
#define AVR32_PM_IMR_OSC0RDY_MASK                         0x00000080
#define AVR32_PM_IMR_OSC0RDY_OFFSET                                7
#define AVR32_PM_IMR_OSC0RDY_SIZE                                  1
#define AVR32_PM_IMR_OSC1RDY                                       8
#define AVR32_PM_IMR_OSC1RDY_MASK                         0x00000100
#define AVR32_PM_IMR_OSC1RDY_OFFSET                                8
#define AVR32_PM_IMR_OSC1RDY_SIZE                                  1
#define AVR32_PM_IMR_OSC32RDY                                      9
#define AVR32_PM_IMR_OSC32RDY_MASK                        0x00000200
#define AVR32_PM_IMR_OSC32RDY_OFFSET                               9
#define AVR32_PM_IMR_OSC32RDY_SIZE                                 1
#define AVR32_PM_ISR                                      0x0000004c
#define AVR32_PM_ISR_BODDET                                       16
#define AVR32_PM_ISR_BODDET_MASK                          0x00010000
#define AVR32_PM_ISR_BODDET_OFFSET                                16
#define AVR32_PM_ISR_BODDET_SIZE                                   1
#define AVR32_PM_ISR_CKRDY                                         5
#define AVR32_PM_ISR_CKRDY_MASK                           0x00000020
#define AVR32_PM_ISR_CKRDY_OFFSET                                  5
#define AVR32_PM_ISR_CKRDY_SIZE                                    1
#define AVR32_PM_ISR_LOCK0                                         0
#define AVR32_PM_ISR_LOCK0_MASK                           0x00000001
#define AVR32_PM_ISR_LOCK0_OFFSET                                  0
#define AVR32_PM_ISR_LOCK0_SIZE                                    1
#define AVR32_PM_ISR_LOCK1                                         1
#define AVR32_PM_ISR_LOCK1_MASK                           0x00000002
#define AVR32_PM_ISR_LOCK1_OFFSET                                  1
#define AVR32_PM_ISR_LOCK1_SIZE                                    1
#define AVR32_PM_ISR_MSKRDY                                        6
#define AVR32_PM_ISR_MSKRDY_MASK                          0x00000040
#define AVR32_PM_ISR_MSKRDY_OFFSET                                 6
#define AVR32_PM_ISR_MSKRDY_SIZE                                   1
#define AVR32_PM_ISR_OSC0RDY                                       7
#define AVR32_PM_ISR_OSC0RDY_MASK                         0x00000080
#define AVR32_PM_ISR_OSC0RDY_OFFSET                                7
#define AVR32_PM_ISR_OSC0RDY_SIZE                                  1
#define AVR32_PM_ISR_OSC1RDY                                       8
#define AVR32_PM_ISR_OSC1RDY_MASK                         0x00000100
#define AVR32_PM_ISR_OSC1RDY_OFFSET                                8
#define AVR32_PM_ISR_OSC1RDY_SIZE                                  1
#define AVR32_PM_ISR_OSC32RDY                                      9
#define AVR32_PM_ISR_OSC32RDY_MASK                        0x00000200
#define AVR32_PM_ISR_OSC32RDY_OFFSET                               9
#define AVR32_PM_ISR_OSC32RDY_SIZE                                 1
#define AVR32_PM_JTAG                                              4
#define AVR32_PM_JTAGHARD                                          9
#define AVR32_PM_JTAGHARD_MASK                            0x00000200
#define AVR32_PM_JTAGHARD_OFFSET                                   9
#define AVR32_PM_JTAGHARD_SIZE                                     1
#define AVR32_PM_JTAG_MASK                                0x00000010
#define AVR32_PM_JTAG_OFFSET                                       4
#define AVR32_PM_JTAG_SIZE                                         1
#define AVR32_PM_KEY                                              24
#define AVR32_PM_KEY_MASK                                 0xff000000
#define AVR32_PM_KEY_OFFSET                                       24
#define AVR32_PM_KEY_SIZE                                          8
#define AVR32_PM_LEVEL                                             0
#define AVR32_PM_LEVEL_MASK                               0x0000003f
#define AVR32_PM_LEVEL_OFFSET                                      0
#define AVR32_PM_LEVEL_SIZE                                        6
#define AVR32_PM_LOCK0                                             0
#define AVR32_PM_LOCK0_MASK                               0x00000001
#define AVR32_PM_LOCK0_OFFSET                                      0
#define AVR32_PM_LOCK0_SIZE                                        1
#define AVR32_PM_LOCK1                                             1
#define AVR32_PM_LOCK1_MASK                               0x00000002
#define AVR32_PM_LOCK1_OFFSET                                      1
#define AVR32_PM_LOCK1_SIZE                                        1
#define AVR32_PM_MCCTRL                                   0x00000000
#define AVR32_PM_MCCTRL_MCSEL                                      0
#define AVR32_PM_MCCTRL_MCSEL_MASK                        0x00000003
#define AVR32_PM_MCCTRL_MCSEL_OFFSET                               0
#define AVR32_PM_MCCTRL_MCSEL_OSC0                        0x00000001
#define AVR32_PM_MCCTRL_MCSEL_PLL0                        0x00000002
#define AVR32_PM_MCCTRL_MCSEL_SIZE                                 2
#define AVR32_PM_MCCTRL_MCSEL_SLOW                        0x00000000
#define AVR32_PM_MCCTRL_OSC0EN                                     2
#define AVR32_PM_MCCTRL_OSC0EN_MASK                       0x00000004
#define AVR32_PM_MCCTRL_OSC0EN_OFFSET                              2
#define AVR32_PM_MCCTRL_OSC0EN_SIZE                                1
#define AVR32_PM_MCCTRL_OSC1EN                                     3
#define AVR32_PM_MCCTRL_OSC1EN_MASK                       0x00000008
#define AVR32_PM_MCCTRL_OSC1EN_OFFSET                              3
#define AVR32_PM_MCCTRL_OSC1EN_SIZE                                1
#define AVR32_PM_MCSEL                                             0
#define AVR32_PM_MCSEL_MASK                               0x00000003
#define AVR32_PM_MCSEL_OFFSET                                      0
#define AVR32_PM_MCSEL_OSC0                               0x00000001
#define AVR32_PM_MCSEL_PLL0                               0x00000002
#define AVR32_PM_MCSEL_SIZE                                        2
#define AVR32_PM_MCSEL_SLOW                               0x00000000
#define AVR32_PM_MODE_CRYSTAL                             0x00000001
#define AVR32_PM_MODE_CRYSTAL_G0                          0x00000004
#define AVR32_PM_MODE_CRYSTAL_G1                          0x00000005
#define AVR32_PM_MODE_CRYSTAL_G2                          0x00000006
#define AVR32_PM_MODE_CRYSTAL_G3                          0x00000007
#define AVR32_PM_MODE_EXT_CLOCK                           0x00000000
#define AVR32_PM_MODE_SIZE                                         3
#define AVR32_PM_MSKRDY                                            6
#define AVR32_PM_MSKRDY_MASK                              0x00000040
#define AVR32_PM_MSKRDY_OFFSET                                     6
#define AVR32_PM_MSKRDY_SIZE                                       1
#define AVR32_PM_OCDRST                                            8
#define AVR32_PM_OCDRST_MASK                              0x00000100
#define AVR32_PM_OCDRST_OFFSET                                     8
#define AVR32_PM_OCDRST_SIZE                                       1
#define AVR32_PM_OFF1                                     0x00000000
#define AVR32_PM_OFF2                                     0x00000003
#define AVR32_PM_OSC0                                     0x00000001
#define AVR32_PM_OSC0EN                                            2
#define AVR32_PM_OSC0EN_MASK                              0x00000004
#define AVR32_PM_OSC0EN_OFFSET                                     2
#define AVR32_PM_OSC0EN_SIZE                                       1
#define AVR32_PM_OSC0RDY                                           7
#define AVR32_PM_OSC0RDY_MASK                             0x00000080
#define AVR32_PM_OSC0RDY_OFFSET                                    7
#define AVR32_PM_OSC0RDY_SIZE                                      1
#define AVR32_PM_OSC1EN                                            3
#define AVR32_PM_OSC1EN_MASK                              0x00000008
#define AVR32_PM_OSC1EN_OFFSET                                     3
#define AVR32_PM_OSC1EN_SIZE                                       1
#define AVR32_PM_OSC1RDY                                           8
#define AVR32_PM_OSC1RDY_MASK                             0x00000100
#define AVR32_PM_OSC1RDY_OFFSET                                    8
#define AVR32_PM_OSC1RDY_SIZE                                      1
#define AVR32_PM_OSC32EN                                           0
#define AVR32_PM_OSC32EN_MASK                             0x00000001
#define AVR32_PM_OSC32EN_OFFSET                                    0
#define AVR32_PM_OSC32EN_SIZE                                      1
#define AVR32_PM_OSC32RDY                                          9
#define AVR32_PM_OSC32RDY_MASK                            0x00000200
#define AVR32_PM_OSC32RDY_OFFSET                                   9
#define AVR32_PM_OSC32RDY_SIZE                                     1
#define AVR32_PM_OSCCTRL0                                 0x00000028
#define AVR32_PM_OSCCTRL0_MODE                                     0
#define AVR32_PM_OSCCTRL0_MODE_CRYSTAL_G0                 0x00000004
#define AVR32_PM_OSCCTRL0_MODE_CRYSTAL_G1                 0x00000005
#define AVR32_PM_OSCCTRL0_MODE_CRYSTAL_G2                 0x00000006
#define AVR32_PM_OSCCTRL0_MODE_CRYSTAL_G3                 0x00000007
#define AVR32_PM_OSCCTRL0_MODE_EXT_CLOCK                  0x00000000
#define AVR32_PM_OSCCTRL0_MODE_MASK                       0x00000007
#define AVR32_PM_OSCCTRL0_MODE_OFFSET                              0
#define AVR32_PM_OSCCTRL0_MODE_SIZE                                3
#define AVR32_PM_OSCCTRL0_STARTUP                                  8
#define AVR32_PM_OSCCTRL0_STARTUP_0_RCOSC                 0x00000000
#define AVR32_PM_OSCCTRL0_STARTUP_128_RCOSC               0x00000002
#define AVR32_PM_OSCCTRL0_STARTUP_16384_RCOSC             0x00000006
#define AVR32_PM_OSCCTRL0_STARTUP_2048_RCOSC              0x00000003
#define AVR32_PM_OSCCTRL0_STARTUP_4096_RCOSC              0x00000004
#define AVR32_PM_OSCCTRL0_STARTUP_64_RCOSC                0x00000001
#define AVR32_PM_OSCCTRL0_STARTUP_8192_RCOSC              0x00000005
#define AVR32_PM_OSCCTRL0_STARTUP_MASK                    0x00000700
#define AVR32_PM_OSCCTRL0_STARTUP_OFFSET                           8
#define AVR32_PM_OSCCTRL0_STARTUP_SIZE                             3
#define AVR32_PM_OSCCTRL1                                 0x0000002c
#define AVR32_PM_OSCCTRL1_MODE                                     0
#define AVR32_PM_OSCCTRL1_MODE_CRYSTAL_G0                 0x00000004
#define AVR32_PM_OSCCTRL1_MODE_CRYSTAL_G1                 0x00000005
#define AVR32_PM_OSCCTRL1_MODE_CRYSTAL_G2                 0x00000006
#define AVR32_PM_OSCCTRL1_MODE_CRYSTAL_G3                 0x00000007
#define AVR32_PM_OSCCTRL1_MODE_EXT_CLOCK                  0x00000000
#define AVR32_PM_OSCCTRL1_MODE_MASK                       0x00000007
#define AVR32_PM_OSCCTRL1_MODE_OFFSET                              0
#define AVR32_PM_OSCCTRL1_MODE_SIZE                                3
#define AVR32_PM_OSCCTRL1_STARTUP                                  8
#define AVR32_PM_OSCCTRL1_STARTUP_0_RCOSC                 0x00000000
#define AVR32_PM_OSCCTRL1_STARTUP_128_RCOSC               0x00000002
#define AVR32_PM_OSCCTRL1_STARTUP_16384_RCOSC             0x00000006
#define AVR32_PM_OSCCTRL1_STARTUP_2048_RCOSC              0x00000003
#define AVR32_PM_OSCCTRL1_STARTUP_4096_RCOSC              0x00000004
#define AVR32_PM_OSCCTRL1_STARTUP_64_RCOSC                0x00000001
#define AVR32_PM_OSCCTRL1_STARTUP_8192_RCOSC              0x00000005
#define AVR32_PM_OSCCTRL1_STARTUP_MASK                    0x00000700
#define AVR32_PM_OSCCTRL1_STARTUP_OFFSET                           8
#define AVR32_PM_OSCCTRL1_STARTUP_SIZE                             3
#define AVR32_PM_OSCCTRL32                                0x00000030
#define AVR32_PM_OSCCTRL32_MODE                                    8
#define AVR32_PM_OSCCTRL32_MODE_CRYSTAL                   0x00000001
#define AVR32_PM_OSCCTRL32_MODE_EXT_CLOCK                 0x00000000
#define AVR32_PM_OSCCTRL32_MODE_MASK                      0x00000700
#define AVR32_PM_OSCCTRL32_MODE_OFFSET                             8
#define AVR32_PM_OSCCTRL32_MODE_SIZE                               3
#define AVR32_PM_OSCCTRL32_OSC32EN                                 0
#define AVR32_PM_OSCCTRL32_OSC32EN_MASK                   0x00000001
#define AVR32_PM_OSCCTRL32_OSC32EN_OFFSET                          0
#define AVR32_PM_OSCCTRL32_OSC32EN_SIZE                            1
#define AVR32_PM_OSCCTRL32_STARTUP                                16
#define AVR32_PM_OSCCTRL32_STARTUP_0_RCOSC                0x00000000
#define AVR32_PM_OSCCTRL32_STARTUP_128_RCOSC              0x00000001
#define AVR32_PM_OSCCTRL32_STARTUP_131072_RCOSC           0x00000005
#define AVR32_PM_OSCCTRL32_STARTUP_16384_RCOSC            0x00000003
#define AVR32_PM_OSCCTRL32_STARTUP_262144_RCOSC           0x00000006
#define AVR32_PM_OSCCTRL32_STARTUP_524288_RCOSC           0x00000007
#define AVR32_PM_OSCCTRL32_STARTUP_65536_RCOSC            0x00000004
#define AVR32_PM_OSCCTRL32_STARTUP_8192_RCOSC             0x00000002
#define AVR32_PM_OSCCTRL32_STARTUP_MASK                   0x00070000
#define AVR32_PM_OSCCTRL32_STARTUP_OFFSET                         16
#define AVR32_PM_OSCCTRL32_STARTUP_SIZE                            3
#define AVR32_PM_OSCSEL                                            0
#define AVR32_PM_OSCSEL_MASK                              0x00000001
#define AVR32_PM_OSCSEL_OFFSET                                     0
#define AVR32_PM_OSCSEL_SIZE                                       1
#define AVR32_PM_PBADIV                                           23
#define AVR32_PM_PBADIV_MASK                              0x00800000
#define AVR32_PM_PBADIV_OFFSET                                    23
#define AVR32_PM_PBADIV_SIZE                                       1
#define AVR32_PM_PBAMASK                                  0x00000010
#define AVR32_PM_PBASEL                                           16
#define AVR32_PM_PBASEL_MASK                              0x00070000
#define AVR32_PM_PBASEL_OFFSET                                    16
#define AVR32_PM_PBASEL_SIZE                                       3
#define AVR32_PM_PBBDIV                                           31
#define AVR32_PM_PBBDIV_MASK                              0x80000000
#define AVR32_PM_PBBDIV_OFFSET                                    31
#define AVR32_PM_PBBDIV_SIZE                                       1
#define AVR32_PM_PBBMASK                                  0x00000014
#define AVR32_PM_PBBSEL                                           24
#define AVR32_PM_PBBSEL_MASK                              0x07000000
#define AVR32_PM_PBBSEL_OFFSET                                    24
#define AVR32_PM_PBBSEL_SIZE                                       3
#define AVR32_PM_PLL0                                     0x00000020
#define AVR32_PM_PLL0_PLLBPL                                       7
#define AVR32_PM_PLL0_PLLBPL_MASK                         0x00000080
#define AVR32_PM_PLL0_PLLBPL_OFFSET                                7
#define AVR32_PM_PLL0_PLLBPL_SIZE                                  1
#define AVR32_PM_PLL0_PLLCOUNT                                    24
#define AVR32_PM_PLL0_PLLCOUNT_MASK                       0x3f000000
#define AVR32_PM_PLL0_PLLCOUNT_OFFSET                             24
#define AVR32_PM_PLL0_PLLCOUNT_SIZE                                6
#define AVR32_PM_PLL0_PLLDIV                                       8
#define AVR32_PM_PLL0_PLLDIV_MASK                         0x00000f00
#define AVR32_PM_PLL0_PLLDIV_OFFSET                                8
#define AVR32_PM_PLL0_PLLDIV_SIZE                                  4
#define AVR32_PM_PLL0_PLLEN                                        0
#define AVR32_PM_PLL0_PLLEN_MASK                          0x00000001
#define AVR32_PM_PLL0_PLLEN_OFFSET                                 0
#define AVR32_PM_PLL0_PLLEN_SIZE                                   1
#define AVR32_PM_PLL0_PLLIOTESTEN                                 30
#define AVR32_PM_PLL0_PLLIOTESTEN_MASK                    0x40000000
#define AVR32_PM_PLL0_PLLIOTESTEN_OFFSET                          30
#define AVR32_PM_PLL0_PLLIOTESTEN_SIZE                             1
#define AVR32_PM_PLL0_PLLMUL                                      16
#define AVR32_PM_PLL0_PLLMUL_MASK                         0x000f0000
#define AVR32_PM_PLL0_PLLMUL_OFFSET                               16
#define AVR32_PM_PLL0_PLLMUL_SIZE                                  4
#define AVR32_PM_PLL0_PLLOPT                                       2
#define AVR32_PM_PLL0_PLLOPT_MASK                         0x0000001c
#define AVR32_PM_PLL0_PLLOPT_OFFSET                                2
#define AVR32_PM_PLL0_PLLOPT_SIZE                                  3
#define AVR32_PM_PLL0_PLLOSC                                       1
#define AVR32_PM_PLL0_PLLOSC_MASK                         0x00000002
#define AVR32_PM_PLL0_PLLOSC_OFFSET                                1
#define AVR32_PM_PLL0_PLLOSC_SIZE                                  1
#define AVR32_PM_PLL0_PLLTEST                                     31
#define AVR32_PM_PLL0_PLLTEST_MASK                        0x80000000
#define AVR32_PM_PLL0_PLLTEST_OFFSET                              31
#define AVR32_PM_PLL0_PLLTEST_SIZE                                 1
#define AVR32_PM_PLL1                                     0x00000024
#define AVR32_PM_PLL1_PLLBPL                                       7
#define AVR32_PM_PLL1_PLLBPL_MASK                         0x00000080
#define AVR32_PM_PLL1_PLLBPL_OFFSET                                7
#define AVR32_PM_PLL1_PLLBPL_SIZE                                  1
#define AVR32_PM_PLL1_PLLCOUNT                                    24
#define AVR32_PM_PLL1_PLLCOUNT_MASK                       0x3f000000
#define AVR32_PM_PLL1_PLLCOUNT_OFFSET                             24
#define AVR32_PM_PLL1_PLLCOUNT_SIZE                                6
#define AVR32_PM_PLL1_PLLDIV                                       8
#define AVR32_PM_PLL1_PLLDIV_MASK                         0x00000f00
#define AVR32_PM_PLL1_PLLDIV_OFFSET                                8
#define AVR32_PM_PLL1_PLLDIV_SIZE                                  4
#define AVR32_PM_PLL1_PLLEN                                        0
#define AVR32_PM_PLL1_PLLEN_MASK                          0x00000001
#define AVR32_PM_PLL1_PLLEN_OFFSET                                 0
#define AVR32_PM_PLL1_PLLEN_SIZE                                   1
#define AVR32_PM_PLL1_PLLIOTESTEN                                 30
#define AVR32_PM_PLL1_PLLIOTESTEN_MASK                    0x40000000
#define AVR32_PM_PLL1_PLLIOTESTEN_OFFSET                          30
#define AVR32_PM_PLL1_PLLIOTESTEN_SIZE                             1
#define AVR32_PM_PLL1_PLLMUL                                      16
#define AVR32_PM_PLL1_PLLMUL_MASK                         0x000f0000
#define AVR32_PM_PLL1_PLLMUL_OFFSET                               16
#define AVR32_PM_PLL1_PLLMUL_SIZE                                  4
#define AVR32_PM_PLL1_PLLOPT                                       2
#define AVR32_PM_PLL1_PLLOPT_MASK                         0x0000001c
#define AVR32_PM_PLL1_PLLOPT_OFFSET                                2
#define AVR32_PM_PLL1_PLLOPT_SIZE                                  3
#define AVR32_PM_PLL1_PLLOSC                                       1
#define AVR32_PM_PLL1_PLLOSC_MASK                         0x00000002
#define AVR32_PM_PLL1_PLLOSC_OFFSET                                1
#define AVR32_PM_PLL1_PLLOSC_SIZE                                  1
#define AVR32_PM_PLL1_PLLTEST                                     31
#define AVR32_PM_PLL1_PLLTEST_MASK                        0x80000000
#define AVR32_PM_PLL1_PLLTEST_OFFSET                              31
#define AVR32_PM_PLL1_PLLTEST_SIZE                                 1
#define AVR32_PM_PLLBPL                                            7
#define AVR32_PM_PLLBPL_MASK                              0x00000080
#define AVR32_PM_PLLBPL_OFFSET                                     7
#define AVR32_PM_PLLBPL_SIZE                                       1
#define AVR32_PM_PLLCOUNT                                         24
#define AVR32_PM_PLLCOUNT_MASK                            0x3f000000
#define AVR32_PM_PLLCOUNT_OFFSET                                  24
#define AVR32_PM_PLLCOUNT_SIZE                                     6
#define AVR32_PM_PLLDIV                                            8
#define AVR32_PM_PLLDIV_MASK                              0x00000f00
#define AVR32_PM_PLLDIV_OFFSET                                     8
#define AVR32_PM_PLLDIV_SIZE                                       4
#define AVR32_PM_PLLEN                                             0
#define AVR32_PM_PLLEN_MASK                               0x00000001
#define AVR32_PM_PLLEN_OFFSET                                      0
#define AVR32_PM_PLLEN_SIZE                                        1
#define AVR32_PM_PLLIOTESTEN                                      30
#define AVR32_PM_PLLIOTESTEN_MASK                         0x40000000
#define AVR32_PM_PLLIOTESTEN_OFFSET                               30
#define AVR32_PM_PLLIOTESTEN_SIZE                                  1
#define AVR32_PM_PLLMUL                                           16
#define AVR32_PM_PLLMUL_MASK                              0x000f0000
#define AVR32_PM_PLLMUL_OFFSET                                    16
#define AVR32_PM_PLLMUL_SIZE                                       4
#define AVR32_PM_PLLOPT                                            2
#define AVR32_PM_PLLOPT_MASK                              0x0000001c
#define AVR32_PM_PLLOPT_OFFSET                                     2
#define AVR32_PM_PLLOPT_SIZE                                       3
#define AVR32_PM_PLLOSC                                            1
#define AVR32_PM_PLLOSC_MASK                              0x00000002
#define AVR32_PM_PLLOSC_OFFSET                                     1
#define AVR32_PM_PLLOSC_SIZE                                       1
#define AVR32_PM_PLLSEL                                            1
#define AVR32_PM_PLLSEL_MASK                              0x00000002
#define AVR32_PM_PLLSEL_OFFSET                                     1
#define AVR32_PM_PLLSEL_SIZE                                       1
#define AVR32_PM_PLLTEST                                          31
#define AVR32_PM_PLLTEST_MASK                             0x80000000
#define AVR32_PM_PLLTEST_OFFSET                                   31
#define AVR32_PM_PLLTEST_SIZE                                      1
#define AVR32_PM_POR                                               0
#define AVR32_PM_POR_MASK                                 0x00000001
#define AVR32_PM_POR_OFFSET                                        0
#define AVR32_PM_POR_SIZE                                          1
#define AVR32_PM_POSCSR                                   0x00000054
#define AVR32_PM_POSCSR_BODDET                                    16
#define AVR32_PM_POSCSR_BODDET_MASK                       0x00010000
#define AVR32_PM_POSCSR_BODDET_OFFSET                             16
#define AVR32_PM_POSCSR_BODDET_SIZE                                1
#define AVR32_PM_POSCSR_CKRDY                                      5
#define AVR32_PM_POSCSR_CKRDY_MASK                        0x00000020
#define AVR32_PM_POSCSR_CKRDY_OFFSET                               5
#define AVR32_PM_POSCSR_CKRDY_SIZE                                 1
#define AVR32_PM_POSCSR_LOCK0                                      0
#define AVR32_PM_POSCSR_LOCK0_MASK                        0x00000001
#define AVR32_PM_POSCSR_LOCK0_OFFSET                               0
#define AVR32_PM_POSCSR_LOCK0_SIZE                                 1
#define AVR32_PM_POSCSR_LOCK1                                      1
#define AVR32_PM_POSCSR_LOCK1_MASK                        0x00000002
#define AVR32_PM_POSCSR_LOCK1_OFFSET                               1
#define AVR32_PM_POSCSR_LOCK1_SIZE                                 1
#define AVR32_PM_POSCSR_MSKRDY                                     6
#define AVR32_PM_POSCSR_MSKRDY_MASK                       0x00000040
#define AVR32_PM_POSCSR_MSKRDY_OFFSET                              6
#define AVR32_PM_POSCSR_MSKRDY_SIZE                                1
#define AVR32_PM_POSCSR_OSC0RDY                                    7
#define AVR32_PM_POSCSR_OSC0RDY_MASK                      0x00000080
#define AVR32_PM_POSCSR_OSC0RDY_OFFSET                             7
#define AVR32_PM_POSCSR_OSC0RDY_SIZE                               1
#define AVR32_PM_POSCSR_OSC1RDY                                    8
#define AVR32_PM_POSCSR_OSC1RDY_MASK                      0x00000100
#define AVR32_PM_POSCSR_OSC1RDY_OFFSET                             8
#define AVR32_PM_POSCSR_OSC1RDY_SIZE                               1
#define AVR32_PM_POSCSR_OSC32RDY                                   9
#define AVR32_PM_POSCSR_OSC32RDY_MASK                     0x00000200
#define AVR32_PM_POSCSR_OSC32RDY_OFFSET                            9
#define AVR32_PM_POSCSR_OSC32RDY_SIZE                              1
#define AVR32_PM_POSCSR_VMRDY                                      4
#define AVR32_PM_POSCSR_VMRDY_MASK                        0x00000010
#define AVR32_PM_POSCSR_VMRDY_OFFSET                               4
#define AVR32_PM_POSCSR_VMRDY_SIZE                                 1
#define AVR32_PM_POSCSR_VOK                                        3
#define AVR32_PM_POSCSR_VOK_MASK                          0x00000008
#define AVR32_PM_POSCSR_VOK_OFFSET                                 3
#define AVR32_PM_POSCSR_VOK_SIZE                                   1
#define AVR32_PM_POSCSR_WAKE                                       2
#define AVR32_PM_POSCSR_WAKE_MASK                         0x00000004
#define AVR32_PM_POSCSR_WAKE_OFFSET                                2
#define AVR32_PM_POSCSR_WAKE_SIZE                                  1
#define AVR32_PM_RCAUSE                                   0x00000140
#define AVR32_PM_RCAUSE_BOD                                        1
#define AVR32_PM_RCAUSE_BOD_MASK                          0x00000002
#define AVR32_PM_RCAUSE_BOD_OFFSET                                 1
#define AVR32_PM_RCAUSE_BOD_SIZE                                   1
#define AVR32_PM_RCAUSE_CPUERR                                     7
#define AVR32_PM_RCAUSE_CPUERR_MASK                       0x00000080
#define AVR32_PM_RCAUSE_CPUERR_OFFSET                              7
#define AVR32_PM_RCAUSE_CPUERR_SIZE                                1
#define AVR32_PM_RCAUSE_EXT                                        2
#define AVR32_PM_RCAUSE_EXT_MASK                          0x00000004
#define AVR32_PM_RCAUSE_EXT_OFFSET                                 2
#define AVR32_PM_RCAUSE_EXT_SIZE                                   1
#define AVR32_PM_RCAUSE_JTAG                                       4
#define AVR32_PM_RCAUSE_JTAGHARD                                   9
#define AVR32_PM_RCAUSE_JTAGHARD_MASK                     0x00000200
#define AVR32_PM_RCAUSE_JTAGHARD_OFFSET                            9
#define AVR32_PM_RCAUSE_JTAGHARD_SIZE                              1
#define AVR32_PM_RCAUSE_JTAG_MASK                         0x00000010
#define AVR32_PM_RCAUSE_JTAG_OFFSET                                4
#define AVR32_PM_RCAUSE_JTAG_SIZE                                  1
#define AVR32_PM_RCAUSE_OCDRST                                     8
#define AVR32_PM_RCAUSE_OCDRST_MASK                       0x00000100
#define AVR32_PM_RCAUSE_OCDRST_OFFSET                              8
#define AVR32_PM_RCAUSE_OCDRST_SIZE                                1
#define AVR32_PM_RCAUSE_POR                                        0
#define AVR32_PM_RCAUSE_POR_MASK                          0x00000001
#define AVR32_PM_RCAUSE_POR_OFFSET                                 0
#define AVR32_PM_RCAUSE_POR_SIZE                                   1
#define AVR32_PM_RCAUSE_SLEEP                                      6
#define AVR32_PM_RCAUSE_SLEEP_MASK                        0x00000040
#define AVR32_PM_RCAUSE_SLEEP_OFFSET                               6
#define AVR32_PM_RCAUSE_SLEEP_SIZE                                 1
#define AVR32_PM_RCAUSE_WDT                                        3
#define AVR32_PM_RCAUSE_WDT_MASK                          0x00000008
#define AVR32_PM_RCAUSE_WDT_OFFSET                                 3
#define AVR32_PM_RCAUSE_WDT_SIZE                                   1
#define AVR32_PM_RCCR                                     0x000000c0
#define AVR32_PM_RCCR_CALIB                                        0
#define AVR32_PM_RCCR_CALIB_MASK                          0x000003ff
#define AVR32_PM_RCCR_CALIB_OFFSET                                 0
#define AVR32_PM_RCCR_CALIB_SIZE                                  10
#define AVR32_PM_RCCR_FCD                                         16
#define AVR32_PM_RCCR_FCD_MASK                            0x00010000
#define AVR32_PM_RCCR_FCD_OFFSET                                  16
#define AVR32_PM_RCCR_FCD_SIZE                                     1
#define AVR32_PM_RCCR_KEY                                         24
#define AVR32_PM_RCCR_KEY_MASK                            0xff000000
#define AVR32_PM_RCCR_KEY_OFFSET                                  24
#define AVR32_PM_RCCR_KEY_SIZE                                     8
#define AVR32_PM_SLEEP                                             6
#define AVR32_PM_SLEEP_MASK                               0x00000040
#define AVR32_PM_SLEEP_OFFSET                                      6
#define AVR32_PM_SLEEP_SIZE                                        1
#define AVR32_PM_SLOW                                     0x00000000
#define AVR32_PM_STARTUP_SIZE                                      3
#define AVR32_PM_USB_WAKEN                                         0
#define AVR32_PM_USB_WAKEN_MASK                           0x00000001
#define AVR32_PM_USB_WAKEN_OFFSET                                  0
#define AVR32_PM_USB_WAKEN_SIZE                                    1
#define AVR32_PM_VMRDY                                             4
#define AVR32_PM_VMRDY_MASK                               0x00000010
#define AVR32_PM_VMRDY_OFFSET                                      4
#define AVR32_PM_VMRDY_SIZE                                        1
#define AVR32_PM_VOK                                               3
#define AVR32_PM_VOK_MASK                                 0x00000008
#define AVR32_PM_VOK_OFFSET                                        3
#define AVR32_PM_VOK_SIZE                                          1
#define AVR32_PM_VREGCR                                   0x000000c8
#define AVR32_PM_VREGCR_CALIB                                      0
#define AVR32_PM_VREGCR_CALIB_MASK                        0x00000007
#define AVR32_PM_VREGCR_CALIB_OFFSET                               0
#define AVR32_PM_VREGCR_CALIB_SIZE                                 3
#define AVR32_PM_VREGCR_FCD                                       16
#define AVR32_PM_VREGCR_FCD_MASK                          0x00010000
#define AVR32_PM_VREGCR_FCD_OFFSET                                16
#define AVR32_PM_VREGCR_FCD_SIZE                                   1
#define AVR32_PM_VREGCR_KEY                                       24
#define AVR32_PM_VREGCR_KEY_MASK                          0xff000000
#define AVR32_PM_VREGCR_KEY_OFFSET                                24
#define AVR32_PM_VREGCR_KEY_SIZE                                   8
#define AVR32_PM_WAKE                                              2
#define AVR32_PM_WAKE_MASK                                0x00000004
#define AVR32_PM_WAKE_OFFSET                                       2
#define AVR32_PM_WAKE_SIZE                                         1
#define AVR32_PM_WDT                                               3
#define AVR32_PM_WDT_MASK                                 0x00000008
#define AVR32_PM_WDT_OFFSET                                        3
#define AVR32_PM_WDT_SIZE                                          1

#define AVR32_BGCR_KEY                                 0x00000055
#define AVR32_BOD_KEY                                  0x00000055
#define AVR32_BOD_OFF                                  0x00000000
#define AVR32_BOD_ON                                   0x00000001
#define AVR32_BOD_ON_NORESET                           0x00000002
#define AVR32_GC_DIV_CLOCK                             0x00000001
#define AVR32_GC_NO_DIV_CLOCK                          0x00000000
#define AVR32_GC_USES_OSC                              0x00000000
#define AVR32_GC_USES_OSC0                             0x00000000
#define AVR32_GC_USES_OSC1                             0x00000001
#define AVR32_GC_USES_PLL                              0x00000001
#define AVR32_GC_USES_PLL0                             0x00000000
#define AVR32_GC_USES_PLL1                             0x00000001
#define AVR32_PLL_USES_OSC0                            0x00000000
#define AVR32_PLL_USES_OSC1                            0x00000001
#define AVR32_PM_SMODE_DEEPSTOP                        0x00000004
#define AVR32_PM_SMODE_FROZEN                          0x00000001
#define AVR32_PM_SMODE_IDLE                            0x00000000
#define AVR32_PM_SMODE_STANDBY                         0x00000002
#define AVR32_PM_SMODE_STATIC                          0x00000005
#define AVR32_PM_SMODE_STOP                            0x00000003
#define AVR32_RCCR_KEY                                 0x00000055
#define AVR32_VREGCR_KEY                               0x00000055



#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_pm_mcctrl_t {
    unsigned int                 :28;
    unsigned int osc1en          : 1;
    unsigned int osc0en          : 1;
    unsigned int mcsel           : 2;
} avr32_pm_mcctrl_t;



typedef struct avr32_pm_cksel_t {
    unsigned int pbbdiv          : 1;
    unsigned int                 : 4;
    unsigned int pbbsel          : 3;
    unsigned int pbadiv          : 1;
    unsigned int                 : 4;
    unsigned int pbasel          : 3;
    unsigned int hsbdiv          : 1;
    unsigned int                 : 4;
    unsigned int hsbsel          : 3;
    unsigned int cpudiv          : 1;
    unsigned int                 : 4;
    unsigned int cpusel          : 3;
} avr32_pm_cksel_t;



typedef struct avr32_pm_pll_t {
    unsigned int plltest         : 1;
    unsigned int plliotesten     : 1;
    unsigned int pllcount        : 6;
    unsigned int                 : 4;
    unsigned int pllmul          : 4;
    unsigned int                 : 4;
    unsigned int plldiv          : 4;
    unsigned int pllbpl          : 1;
    unsigned int                 : 2;
    unsigned int pllopt          : 3;
    unsigned int pllosc          : 1;
    unsigned int pllen           : 1;
} avr32_pm_pll_t;



typedef struct avr32_pm_oscctrl0_t {
    unsigned int                 :21;
    unsigned int startup         : 3;
    unsigned int                 : 5;
    unsigned int mode            : 3;
} avr32_pm_oscctrl0_t;



typedef struct avr32_pm_oscctrl1_t {
    unsigned int                 :21;
    unsigned int startup         : 3;
    unsigned int                 : 5;
    unsigned int mode            : 3;
} avr32_pm_oscctrl1_t;



typedef struct avr32_pm_oscctrl32_t {
    unsigned int                 :13;
    unsigned int startup         : 3;
    unsigned int                 : 5;
    unsigned int mode            : 3;
    unsigned int                 : 7;
    unsigned int osc32en         : 1;
} avr32_pm_oscctrl32_t;



typedef struct avr32_pm_ier_t {
    unsigned int                 :15;
    unsigned int boddet          : 1;
    unsigned int                 : 6;
    unsigned int osc32rdy        : 1;
    unsigned int osc1rdy         : 1;
    unsigned int osc0rdy         : 1;
    unsigned int mskrdy          : 1;
    unsigned int ckrdy           : 1;
    unsigned int                 : 3;
    unsigned int lock1           : 1;
    unsigned int lock0           : 1;
} avr32_pm_ier_t;



typedef struct avr32_pm_idr_t {
    unsigned int                 :15;
    unsigned int boddet          : 1;
    unsigned int                 : 6;
    unsigned int osc32rdy        : 1;
    unsigned int osc1rdy         : 1;
    unsigned int osc0rdy         : 1;
    unsigned int mskrdy          : 1;
    unsigned int ckrdy           : 1;
    unsigned int                 : 3;
    unsigned int lock1           : 1;
    unsigned int lock0           : 1;
} avr32_pm_idr_t;



typedef struct avr32_pm_imr_t {
    unsigned int                 :15;
    unsigned int boddet          : 1;
    unsigned int                 : 6;
    unsigned int osc32rdy        : 1;
    unsigned int osc1rdy         : 1;
    unsigned int osc0rdy         : 1;
    unsigned int mskrdy          : 1;
    unsigned int ckrdy           : 1;
    unsigned int                 : 3;
    unsigned int lock1           : 1;
    unsigned int lock0           : 1;
} avr32_pm_imr_t;



typedef struct avr32_pm_isr_t {
    unsigned int                 :15;
    unsigned int boddet          : 1;
    unsigned int                 : 6;
    unsigned int osc32rdy        : 1;
    unsigned int osc1rdy         : 1;
    unsigned int osc0rdy         : 1;
    unsigned int mskrdy          : 1;
    unsigned int ckrdy           : 1;
    unsigned int                 : 3;
    unsigned int lock1           : 1;
    unsigned int lock0           : 1;
} avr32_pm_isr_t;



typedef struct avr32_pm_icr_t {
    unsigned int                 :15;
    unsigned int boddet          : 1;
    unsigned int                 : 6;
    unsigned int osc32rdy        : 1;
    unsigned int osc1rdy         : 1;
    unsigned int osc0rdy         : 1;
    unsigned int mskrdy          : 1;
    unsigned int ckrdy           : 1;
    unsigned int                 : 3;
    unsigned int lock1           : 1;
    unsigned int lock0           : 1;
} avr32_pm_icr_t;



typedef struct avr32_pm_poscsr_t {
    unsigned int                 :15;
    unsigned int boddet          : 1;
    unsigned int                 : 6;
    unsigned int osc32rdy        : 1;
    unsigned int osc1rdy         : 1;
    unsigned int osc0rdy         : 1;
    unsigned int mskrdy          : 1;
    unsigned int ckrdy           : 1;
    unsigned int vmrdy           : 1;
    unsigned int vok             : 1;
    unsigned int wake            : 1;
    unsigned int lock1           : 1;
    unsigned int lock0           : 1;
} avr32_pm_poscsr_t;



typedef struct avr32_pm_gcctrl_t {
    unsigned int                 :16;
    unsigned int div             : 8;
    unsigned int                 : 3;
    unsigned int diven           : 1;
    unsigned int                 : 1;
    unsigned int cen             : 1;
    unsigned int pllsel          : 1;
    unsigned int oscsel          : 1;
} avr32_pm_gcctrl_t;



typedef struct avr32_pm_rccr_t {
    unsigned int key             : 8;
    unsigned int                 : 7;
    unsigned int fcd             : 1;
    unsigned int                 : 6;
    unsigned int calib           :10;
} avr32_pm_rccr_t;



typedef struct avr32_pm_bgcr_t {
    unsigned int key             : 8;
    unsigned int                 : 7;
    unsigned int fcd             : 1;
    unsigned int                 :13;
    unsigned int calib           : 3;
} avr32_pm_bgcr_t;



typedef struct avr32_pm_vregcr_t {
    unsigned int key             : 8;
    unsigned int                 : 7;
    unsigned int fcd             : 1;
    unsigned int                 :13;
    unsigned int calib           : 3;
} avr32_pm_vregcr_t;



typedef struct avr32_pm_bod_t {
    unsigned int key             : 8;
    unsigned int                 : 7;
    unsigned int fcd             : 1;
    unsigned int                 : 6;
    unsigned int ctrl            : 2;
    unsigned int                 : 1;
    unsigned int hyst            : 1;
    unsigned int level           : 6;
} avr32_pm_bod_t;



typedef struct avr32_pm_rcause_t {
    unsigned int                 :22;
    unsigned int jtaghard        : 1;
    unsigned int ocdrst          : 1;
    unsigned int cpuerr          : 1;
    unsigned int sleep           : 1;
    unsigned int                 : 1;
    unsigned int jtag            : 1;
    unsigned int wdt             : 1;
    unsigned int ext             : 1;
    unsigned int bod             : 1;
    unsigned int por             : 1;
} avr32_pm_rcause_t;



typedef struct avr32_pm_awen_t {
    unsigned int                 :31;
    unsigned int usb_waken       : 1;
} avr32_pm_awen_t;



typedef struct avr32_pm_t {
  union {
          unsigned long                  mcctrl    ;//0x0000
          avr32_pm_mcctrl_t              MCCTRL    ;
  };
  union {
          unsigned long                  cksel     ;//0x0004
          avr32_pm_cksel_t               CKSEL     ;
  };
  union {
          unsigned long                  clkmask   [4];//0x0008
    struct {
          unsigned long                  cpumask   ;//0x0008
          unsigned long                  hsbmask   ;//0x000c
          unsigned long                  pbamask   ;//0x0010
          unsigned long                  pbbmask   ;//0x0014
    };
  };
          unsigned int                   :32       ;//0x0018
          unsigned int                   :32       ;//0x001c
  union {
          unsigned long                  pll       [2];//0x0020
          avr32_pm_pll_t                 PLL       [2];
  };
  union {
          unsigned long                  oscctrl0  ;//0x0028
          avr32_pm_oscctrl0_t            OSCCTRL0  ;
  };
  union {
          unsigned long                  oscctrl1  ;//0x002c
          avr32_pm_oscctrl1_t            OSCCTRL1  ;
  };
  union {
          unsigned long                  oscctrl32 ;//0x0030
          avr32_pm_oscctrl32_t           OSCCTRL32 ;
  };
          unsigned int                   :32       ;//0x0034
          unsigned int                   :32       ;//0x0038
          unsigned int                   :32       ;//0x003c
  union {
          unsigned long                  ier       ;//0x0040
          avr32_pm_ier_t                 IER       ;
  };
  union {
          unsigned long                  idr       ;//0x0044
          avr32_pm_idr_t                 IDR       ;
  };
  union {
    const unsigned long                  imr       ;//0x0048
    const avr32_pm_imr_t                 IMR       ;
  };
  union {
    const unsigned long                  isr       ;//0x004c
    const avr32_pm_isr_t                 ISR       ;
  };
  union {
          unsigned long                  icr       ;//0x0050
          avr32_pm_icr_t                 ICR       ;
  };
  union {
          unsigned long                  poscsr    ;//0x0054
          avr32_pm_poscsr_t              POSCSR    ;
  };
          unsigned int                   :32       ;//0x0058
          unsigned int                   :32       ;//0x005c
  union {
          unsigned long                  gcctrl    [6];//0x0060
          avr32_pm_gcctrl_t              GCCTRL    [6];
  };
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
  union {
          unsigned long                  rccr      ;//0x00c0
          avr32_pm_rccr_t                RCCR      ;
  };
  union {
          unsigned long                  bgcr      ;//0x00c4
          avr32_pm_bgcr_t                BGCR      ;
  };
  union {
          unsigned long                  vregcr    ;//0x00c8
          avr32_pm_vregcr_t              VREGCR    ;
  };
          unsigned int                   :32       ;//0x00cc
  union {
          unsigned long                  bod       ;//0x00d0
          avr32_pm_bod_t                 BOD       ;
  };
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
          unsigned int                   :32       ;//0x00fc
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
  union {
    const unsigned long                  rcause    ;//0x0140
    const avr32_pm_rcause_t              RCAUSE    ;
  };
  union {
          unsigned long                  awen      ;//0x0144
          avr32_pm_awen_t                AWEN      ;
  };
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
          unsigned long                  gplp      [2];//0x0200
} avr32_pm_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif


#if !defined (DEPRECATED_DISABLE)

#define AVR32_PM_SMODE_DEEP_STOP                       0x00000004
#define AVR32_PM_SMODE_SHUTDOWN                        0x00000004

#endif


/*#ifdef AVR32_PM_230_H_INCLUDED*/
#endif

