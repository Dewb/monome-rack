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
#ifndef AVR32_CORE_SC0_130_H_INCLUDED
#define AVR32_CORE_SC0_130_H_INCLUDED

#define AVR32_CORE_SC0_H_VERSION 130

#include "avr32/abi.h"

#define AVR32_CORE_ID                                  "SC0"

#define AVR32_ACBA                                     0x00000008
#define AVR32_BEAR                                     0x0000013c
#define AVR32_COMPARE                                  0x0000010c
#define AVR32_CONFIG0                                  0x00000100
#define AVR32_CONFIG0_AR                                       10
#define AVR32_CONFIG0_AR_MASK                          0x00001c00
#define AVR32_CONFIG0_AR_OFFSET                                10
#define AVR32_CONFIG0_AR_SIZE                                   3
#define AVR32_CONFIG0_AT                                       13
#define AVR32_CONFIG0_AT_AVR32A                        0x00000000
#define AVR32_CONFIG0_AT_AVR32B                        0x00000001
#define AVR32_CONFIG0_AT_MASK                          0x0000e000
#define AVR32_CONFIG0_AT_OFFSET                                13
#define AVR32_CONFIG0_AT_SIZE                                   3
#define AVR32_CONFIG0_D                                         1
#define AVR32_CONFIG0_D_MASK                           0x00000002
#define AVR32_CONFIG0_D_OFFSET                                  1
#define AVR32_CONFIG0_D_SIZE                                    1
#define AVR32_CONFIG0_F                                         6
#define AVR32_CONFIG0_F_MASK                           0x00000040
#define AVR32_CONFIG0_F_OFFSET                                  6
#define AVR32_CONFIG0_F_SIZE                                    1
#define AVR32_CONFIG0_J                                         5
#define AVR32_CONFIG0_J_MASK                           0x00000020
#define AVR32_CONFIG0_J_OFFSET                                  5
#define AVR32_CONFIG0_J_SIZE                                    1
#define AVR32_CONFIG0_MMUT                                      7
#define AVR32_CONFIG0_MMUT_ITLB_DTLB                   0x00000001
#define AVR32_CONFIG0_MMUT_MASK                        0x00000380
#define AVR32_CONFIG0_MMUT_MPU                         0x00000003
#define AVR32_CONFIG0_MMUT_NONE                        0x00000000
#define AVR32_CONFIG0_MMUT_OFFSET                               7
#define AVR32_CONFIG0_MMUT_SHARED_TLB                  0x00000002
#define AVR32_CONFIG0_MMUT_SIZE                                 3
#define AVR32_CONFIG0_O                                         3
#define AVR32_CONFIG0_O_MASK                           0x00000008
#define AVR32_CONFIG0_O_OFFSET                                  3
#define AVR32_CONFIG0_O_SIZE                                    1
#define AVR32_CONFIG0_P                                         4
#define AVR32_CONFIG0_PROCESSORID                              24
#define AVR32_CONFIG0_PROCESSORID_AP7                  0x00000001
#define AVR32_CONFIG0_PROCESSORID_MASK                 0xff000000
#define AVR32_CONFIG0_PROCESSORID_OFFSET                       24
#define AVR32_CONFIG0_PROCESSORID_SIZE                          8
#define AVR32_CONFIG0_PROCESSORID_UC3                  0x00000002
#define AVR32_CONFIG0_PROCESSORREVISION                        16
#define AVR32_CONFIG0_PROCESSORREVISION_MASK           0x000f0000
#define AVR32_CONFIG0_PROCESSORREVISION_OFFSET                 16
#define AVR32_CONFIG0_PROCESSORREVISION_SIZE                    4
#define AVR32_CONFIG0_P_MASK                           0x00000010
#define AVR32_CONFIG0_P_OFFSET                                  4
#define AVR32_CONFIG0_P_SIZE                                    1
#define AVR32_CONFIG0_R                                         0
#define AVR32_CONFIG0_R_MASK                           0x00000001
#define AVR32_CONFIG0_R_OFFSET                                  0
#define AVR32_CONFIG0_R_SIZE                                    1
#define AVR32_CONFIG0_S                                         2
#define AVR32_CONFIG0_S_MASK                           0x00000004
#define AVR32_CONFIG0_S_OFFSET                                  2
#define AVR32_CONFIG0_S_SIZE                                    1
#define AVR32_CONFIG1                                  0x00000104
#define AVR32_CONFIG1_DASS                                      0
#define AVR32_CONFIG1_DASS_MASK                        0x00000007
#define AVR32_CONFIG1_DASS_OFFSET                               0
#define AVR32_CONFIG1_DASS_SIZE                                 3
#define AVR32_CONFIG1_DLSZ                                      3
#define AVR32_CONFIG1_DLSZ_MASK                        0x00000038
#define AVR32_CONFIG1_DLSZ_OFFSET                               3
#define AVR32_CONFIG1_DLSZ_SIZE                                 3
#define AVR32_CONFIG1_DMMUSZ                                   20
#define AVR32_CONFIG1_DMMUSZ_MASK                      0x03f00000
#define AVR32_CONFIG1_DMMUSZ_OFFSET                            20
#define AVR32_CONFIG1_DMMUSZ_SIZE                               6
#define AVR32_CONFIG1_DSET                                      6
#define AVR32_CONFIG1_DSET_MASK                        0x000003c0
#define AVR32_CONFIG1_DSET_OFFSET                               6
#define AVR32_CONFIG1_DSET_SIZE                                 4
#define AVR32_CONFIG1_IASS                                     10
#define AVR32_CONFIG1_IASS_MASK                        0x00001c00
#define AVR32_CONFIG1_IASS_OFFSET                              10
#define AVR32_CONFIG1_IASS_SIZE                                 3
#define AVR32_CONFIG1_ILSZ                                     13
#define AVR32_CONFIG1_ILSZ_MASK                        0x0000e000
#define AVR32_CONFIG1_ILSZ_OFFSET                              13
#define AVR32_CONFIG1_ILSZ_SIZE                                 3
#define AVR32_CONFIG1_IMMUSZ                                   26
#define AVR32_CONFIG1_IMMUSZ_MASK                      0xfc000000
#define AVR32_CONFIG1_IMMUSZ_OFFSET                            26
#define AVR32_CONFIG1_IMMUSZ_SIZE                               6
#define AVR32_CONFIG1_ISET                                     16
#define AVR32_CONFIG1_ISET_MASK                        0x000f0000
#define AVR32_CONFIG1_ISET_OFFSET                              16
#define AVR32_CONFIG1_ISET_SIZE                                 4
#define AVR32_COUNT                                    0x00000108
#define AVR32_CPUCR                                    0x0000000c
#define AVR32_CPUCR_COP                                         1
#define AVR32_CPUCR_COP_MASK                           0x0000003e
#define AVR32_CPUCR_COP_OFFSET                                  1
#define AVR32_CPUCR_COP_SIZE                                    5
#define AVR32_CPUCR_CPL                                         6
#define AVR32_CPUCR_CPL_MASK                           0x000007c0
#define AVR32_CPUCR_CPL_OFFSET                                  6
#define AVR32_CPUCR_CPL_SIZE                                    5
#define AVR32_CPUCR_LOCEN                                      16
#define AVR32_CPUCR_LOCEN_MASK                         0x00010000
#define AVR32_CPUCR_LOCEN_OFFSET                               16
#define AVR32_CPUCR_LOCEN_SIZE                                  1
#define AVR32_CPUCR_SIE                                         0
#define AVR32_CPUCR_SIE_MASK                           0x00000001
#define AVR32_CPUCR_SIE_OFFSET                                  0
#define AVR32_CPUCR_SIE_SIZE                                    1
#define AVR32_CPUCR_SPL                                        11
#define AVR32_CPUCR_SPL_MASK                           0x0000f800
#define AVR32_CPUCR_SPL_OFFSET                                 11
#define AVR32_CPUCR_SPL_SIZE                                    5
#define AVR32_ECR                                      0x00000010
#define AVR32_ECR_ECR                                           0
#define AVR32_ECR_ECR_ADDR_ALIGN_R                     0x0000000d
#define AVR32_ECR_ECR_ADDR_ALIGN_W                     0x0000000e
#define AVR32_ECR_ECR_ADDR_ALIGN_X                     0x00000005
#define AVR32_ECR_ECR_BUS_ERROR_READ                   0x00000003
#define AVR32_ECR_ECR_BUS_ERROR_WRITE                  0x00000002
#define AVR32_ECR_ECR_COPROC_ABSENT                    0x0000000c
#define AVR32_ECR_ECR_DEBUG                            0x00000007
#define AVR32_ECR_ECR_DTLB_MODIFIED                    0x00000011
#define AVR32_ECR_ECR_FPE                              0x0000000b
#define AVR32_ECR_ECR_ILLEGAL_OPCODE                   0x00000008
#define AVR32_ECR_ECR_MASK                             0xffffffff
#define AVR32_ECR_ECR_NMI                              0x00000004
#define AVR32_ECR_ECR_OFFSET                                    0
#define AVR32_ECR_ECR_PRIVILEGE_VIOLATION              0x0000000a
#define AVR32_ECR_ECR_PROTECTION_R                     0x0000000f
#define AVR32_ECR_ECR_PROTECTION_W                     0x00000010
#define AVR32_ECR_ECR_PROTECTION_X                     0x00000006
#define AVR32_ECR_ECR_SIZE                                     32
#define AVR32_ECR_ECR_TLB_MISS_R                       0x00000018
#define AVR32_ECR_ECR_TLB_MISS_W                       0x0000001c
#define AVR32_ECR_ECR_TLB_MISS_X                       0x00000014
#define AVR32_ECR_ECR_TLB_MULTIPLE                     0x00000001
#define AVR32_ECR_ECR_UNIMPL_INSTRUCTION               0x00000009
#define AVR32_ECR_ECR_UNRECOVERABLE                    0x00000000
#define AVR32_EVBA                                     0x00000004
#define AVR32_MPUAPRA                                  0x00000190
#define AVR32_MPUAPRA_AP0                                       0
#define AVR32_MPUAPRA_AP0_MASK                         0x0000000f
#define AVR32_MPUAPRA_AP0_OFFSET                                0
#define AVR32_MPUAPRA_AP0_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRA_AP0_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRA_AP0_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRA_AP0_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRA_AP0_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRA_AP0_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRA_AP0_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRA_AP0_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRA_AP0_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRA_AP0_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRA_AP0_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRA_AP0_SIZE                                  4
#define AVR32_MPUAPRA_AP1                                       4
#define AVR32_MPUAPRA_AP1_MASK                         0x000000f0
#define AVR32_MPUAPRA_AP1_OFFSET                                4
#define AVR32_MPUAPRA_AP1_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRA_AP1_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRA_AP1_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRA_AP1_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRA_AP1_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRA_AP1_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRA_AP1_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRA_AP1_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRA_AP1_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRA_AP1_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRA_AP1_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRA_AP1_SIZE                                  4
#define AVR32_MPUAPRA_AP2                                       8
#define AVR32_MPUAPRA_AP2_MASK                         0x00000f00
#define AVR32_MPUAPRA_AP2_OFFSET                                8
#define AVR32_MPUAPRA_AP2_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRA_AP2_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRA_AP2_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRA_AP2_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRA_AP2_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRA_AP2_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRA_AP2_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRA_AP2_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRA_AP2_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRA_AP2_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRA_AP2_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRA_AP2_SIZE                                  4
#define AVR32_MPUAPRA_AP3                                      12
#define AVR32_MPUAPRA_AP3_MASK                         0x0000f000
#define AVR32_MPUAPRA_AP3_OFFSET                               12
#define AVR32_MPUAPRA_AP3_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRA_AP3_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRA_AP3_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRA_AP3_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRA_AP3_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRA_AP3_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRA_AP3_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRA_AP3_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRA_AP3_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRA_AP3_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRA_AP3_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRA_AP3_SIZE                                  4
#define AVR32_MPUAPRA_AP4                                      16
#define AVR32_MPUAPRA_AP4_MASK                         0x000f0000
#define AVR32_MPUAPRA_AP4_OFFSET                               16
#define AVR32_MPUAPRA_AP4_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRA_AP4_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRA_AP4_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRA_AP4_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRA_AP4_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRA_AP4_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRA_AP4_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRA_AP4_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRA_AP4_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRA_AP4_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRA_AP4_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRA_AP4_SIZE                                  4
#define AVR32_MPUAPRA_AP5                                      20
#define AVR32_MPUAPRA_AP5_MASK                         0x00f00000
#define AVR32_MPUAPRA_AP5_OFFSET                               20
#define AVR32_MPUAPRA_AP5_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRA_AP5_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRA_AP5_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRA_AP5_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRA_AP5_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRA_AP5_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRA_AP5_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRA_AP5_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRA_AP5_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRA_AP5_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRA_AP5_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRA_AP5_SIZE                                  4
#define AVR32_MPUAPRA_AP6                                      24
#define AVR32_MPUAPRA_AP6_MASK                         0x0f000000
#define AVR32_MPUAPRA_AP6_OFFSET                               24
#define AVR32_MPUAPRA_AP6_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRA_AP6_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRA_AP6_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRA_AP6_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRA_AP6_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRA_AP6_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRA_AP6_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRA_AP6_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRA_AP6_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRA_AP6_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRA_AP6_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRA_AP6_SIZE                                  4
#define AVR32_MPUAPRA_AP7                                      28
#define AVR32_MPUAPRA_AP7_MASK                         0xf0000000
#define AVR32_MPUAPRA_AP7_OFFSET                               28
#define AVR32_MPUAPRA_AP7_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRA_AP7_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRA_AP7_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRA_AP7_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRA_AP7_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRA_AP7_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRA_AP7_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRA_AP7_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRA_AP7_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRA_AP7_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRA_AP7_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRA_AP7_SIZE                                  4
#define AVR32_MPUAPRB                                  0x00000194
#define AVR32_MPUAPRB_AP0                                       0
#define AVR32_MPUAPRB_AP0_MASK                         0x0000000f
#define AVR32_MPUAPRB_AP0_OFFSET                                0
#define AVR32_MPUAPRB_AP0_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRB_AP0_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRB_AP0_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRB_AP0_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRB_AP0_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRB_AP0_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRB_AP0_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRB_AP0_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRB_AP0_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRB_AP0_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRB_AP0_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRB_AP0_SIZE                                  4
#define AVR32_MPUAPRB_AP1                                       4
#define AVR32_MPUAPRB_AP1_MASK                         0x000000f0
#define AVR32_MPUAPRB_AP1_OFFSET                                4
#define AVR32_MPUAPRB_AP1_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRB_AP1_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRB_AP1_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRB_AP1_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRB_AP1_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRB_AP1_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRB_AP1_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRB_AP1_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRB_AP1_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRB_AP1_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRB_AP1_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRB_AP1_SIZE                                  4
#define AVR32_MPUAPRB_AP2                                       8
#define AVR32_MPUAPRB_AP2_MASK                         0x00000f00
#define AVR32_MPUAPRB_AP2_OFFSET                                8
#define AVR32_MPUAPRB_AP2_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRB_AP2_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRB_AP2_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRB_AP2_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRB_AP2_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRB_AP2_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRB_AP2_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRB_AP2_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRB_AP2_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRB_AP2_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRB_AP2_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRB_AP2_SIZE                                  4
#define AVR32_MPUAPRB_AP3                                      12
#define AVR32_MPUAPRB_AP3_MASK                         0x0000f000
#define AVR32_MPUAPRB_AP3_OFFSET                               12
#define AVR32_MPUAPRB_AP3_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRB_AP3_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRB_AP3_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRB_AP3_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRB_AP3_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRB_AP3_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRB_AP3_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRB_AP3_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRB_AP3_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRB_AP3_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRB_AP3_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRB_AP3_SIZE                                  4
#define AVR32_MPUAPRB_AP4                                      16
#define AVR32_MPUAPRB_AP4_MASK                         0x000f0000
#define AVR32_MPUAPRB_AP4_OFFSET                               16
#define AVR32_MPUAPRB_AP4_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRB_AP4_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRB_AP4_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRB_AP4_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRB_AP4_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRB_AP4_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRB_AP4_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRB_AP4_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRB_AP4_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRB_AP4_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRB_AP4_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRB_AP4_SIZE                                  4
#define AVR32_MPUAPRB_AP5                                      20
#define AVR32_MPUAPRB_AP5_MASK                         0x00f00000
#define AVR32_MPUAPRB_AP5_OFFSET                               20
#define AVR32_MPUAPRB_AP5_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRB_AP5_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRB_AP5_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRB_AP5_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRB_AP5_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRB_AP5_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRB_AP5_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRB_AP5_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRB_AP5_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRB_AP5_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRB_AP5_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRB_AP5_SIZE                                  4
#define AVR32_MPUAPRB_AP6                                      24
#define AVR32_MPUAPRB_AP6_MASK                         0x0f000000
#define AVR32_MPUAPRB_AP6_OFFSET                               24
#define AVR32_MPUAPRB_AP6_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRB_AP6_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRB_AP6_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRB_AP6_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRB_AP6_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRB_AP6_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRB_AP6_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRB_AP6_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRB_AP6_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRB_AP6_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRB_AP6_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRB_AP6_SIZE                                  4
#define AVR32_MPUAPRB_AP7                                      28
#define AVR32_MPUAPRB_AP7_MASK                         0xf0000000
#define AVR32_MPUAPRB_AP7_OFFSET                               28
#define AVR32_MPUAPRB_AP7_PRIV_NONE_UNPRIV_NONE        0x0000000a
#define AVR32_MPUAPRB_AP7_PRIV_RWX_UNPRIV_NONE         0x00000003
#define AVR32_MPUAPRB_AP7_PRIV_RWX_UNPRIV_RWX          0x00000007
#define AVR32_MPUAPRB_AP7_PRIV_RW_UNPRIV_NONE          0x00000002
#define AVR32_MPUAPRB_AP7_PRIV_RW_UNPRIV_R             0x00000008
#define AVR32_MPUAPRB_AP7_PRIV_RW_UNPRIV_RW            0x00000006
#define AVR32_MPUAPRB_AP7_PRIV_RW_UNPRIV_RX            0x00000009
#define AVR32_MPUAPRB_AP7_PRIV_RX_UNPRIV_NONE          0x00000001
#define AVR32_MPUAPRB_AP7_PRIV_RX_UNPRIV_RX            0x00000005
#define AVR32_MPUAPRB_AP7_PRIV_R_UNPRIV_NONE           0x00000000
#define AVR32_MPUAPRB_AP7_PRIV_R_UNPRIV_R              0x00000004
#define AVR32_MPUAPRB_AP7_SIZE                                  4
#define AVR32_MPUAR0                                   0x00000140
#define AVR32_MPUAR0_BASE                                      12
#define AVR32_MPUAR0_BASE_MASK                         0xfffff000
#define AVR32_MPUAR0_BASE_OFFSET                               12
#define AVR32_MPUAR0_BASE_SIZE                                 20
#define AVR32_MPUAR0_SIZE                                       1
#define AVR32_MPUAR0_SIZE_MASK                         0x0000003e
#define AVR32_MPUAR0_SIZE_OFFSET                                1
#define AVR32_MPUAR0_SIZE_SIZE                                  5
#define AVR32_MPUAR0_V                                          0
#define AVR32_MPUAR0_V_MASK                            0x00000001
#define AVR32_MPUAR0_V_OFFSET                                   0
#define AVR32_MPUAR0_V_SIZE                                     1
#define AVR32_MPUAR1                                   0x00000144
#define AVR32_MPUAR1_BASE                                      12
#define AVR32_MPUAR1_BASE_MASK                         0xfffff000
#define AVR32_MPUAR1_BASE_OFFSET                               12
#define AVR32_MPUAR1_BASE_SIZE                                 20
#define AVR32_MPUAR1_SIZE                                       1
#define AVR32_MPUAR1_SIZE_MASK                         0x0000003e
#define AVR32_MPUAR1_SIZE_OFFSET                                1
#define AVR32_MPUAR1_SIZE_SIZE                                  5
#define AVR32_MPUAR1_V                                          0
#define AVR32_MPUAR1_V_MASK                            0x00000001
#define AVR32_MPUAR1_V_OFFSET                                   0
#define AVR32_MPUAR1_V_SIZE                                     1
#define AVR32_MPUAR2                                   0x00000148
#define AVR32_MPUAR2_BASE                                      12
#define AVR32_MPUAR2_BASE_MASK                         0xfffff000
#define AVR32_MPUAR2_BASE_OFFSET                               12
#define AVR32_MPUAR2_BASE_SIZE                                 20
#define AVR32_MPUAR2_SIZE                                       1
#define AVR32_MPUAR2_SIZE_MASK                         0x0000003e
#define AVR32_MPUAR2_SIZE_OFFSET                                1
#define AVR32_MPUAR2_SIZE_SIZE                                  5
#define AVR32_MPUAR2_V                                          0
#define AVR32_MPUAR2_V_MASK                            0x00000001
#define AVR32_MPUAR2_V_OFFSET                                   0
#define AVR32_MPUAR2_V_SIZE                                     1
#define AVR32_MPUAR3                                   0x0000014c
#define AVR32_MPUAR3_BASE                                      12
#define AVR32_MPUAR3_BASE_MASK                         0xfffff000
#define AVR32_MPUAR3_BASE_OFFSET                               12
#define AVR32_MPUAR3_BASE_SIZE                                 20
#define AVR32_MPUAR3_SIZE                                       1
#define AVR32_MPUAR3_SIZE_MASK                         0x0000003e
#define AVR32_MPUAR3_SIZE_OFFSET                                1
#define AVR32_MPUAR3_SIZE_SIZE                                  5
#define AVR32_MPUAR3_V                                          0
#define AVR32_MPUAR3_V_MASK                            0x00000001
#define AVR32_MPUAR3_V_OFFSET                                   0
#define AVR32_MPUAR3_V_SIZE                                     1
#define AVR32_MPUAR4                                   0x00000150
#define AVR32_MPUAR4_BASE                                      12
#define AVR32_MPUAR4_BASE_MASK                         0xfffff000
#define AVR32_MPUAR4_BASE_OFFSET                               12
#define AVR32_MPUAR4_BASE_SIZE                                 20
#define AVR32_MPUAR4_SIZE                                       1
#define AVR32_MPUAR4_SIZE_MASK                         0x0000003e
#define AVR32_MPUAR4_SIZE_OFFSET                                1
#define AVR32_MPUAR4_SIZE_SIZE                                  5
#define AVR32_MPUAR4_V                                          0
#define AVR32_MPUAR4_V_MASK                            0x00000001
#define AVR32_MPUAR4_V_OFFSET                                   0
#define AVR32_MPUAR4_V_SIZE                                     1
#define AVR32_MPUAR5                                   0x00000154
#define AVR32_MPUAR5_BASE                                      12
#define AVR32_MPUAR5_BASE_MASK                         0xfffff000
#define AVR32_MPUAR5_BASE_OFFSET                               12
#define AVR32_MPUAR5_BASE_SIZE                                 20
#define AVR32_MPUAR5_SIZE                                       1
#define AVR32_MPUAR5_SIZE_MASK                         0x0000003e
#define AVR32_MPUAR5_SIZE_OFFSET                                1
#define AVR32_MPUAR5_SIZE_SIZE                                  5
#define AVR32_MPUAR5_V                                          0
#define AVR32_MPUAR5_V_MASK                            0x00000001
#define AVR32_MPUAR5_V_OFFSET                                   0
#define AVR32_MPUAR5_V_SIZE                                     1
#define AVR32_MPUAR6                                   0x00000158
#define AVR32_MPUAR6_BASE                                      12
#define AVR32_MPUAR6_BASE_MASK                         0xfffff000
#define AVR32_MPUAR6_BASE_OFFSET                               12
#define AVR32_MPUAR6_BASE_SIZE                                 20
#define AVR32_MPUAR6_SIZE                                       1
#define AVR32_MPUAR6_SIZE_MASK                         0x0000003e
#define AVR32_MPUAR6_SIZE_OFFSET                                1
#define AVR32_MPUAR6_SIZE_SIZE                                  5
#define AVR32_MPUAR6_V                                          0
#define AVR32_MPUAR6_V_MASK                            0x00000001
#define AVR32_MPUAR6_V_OFFSET                                   0
#define AVR32_MPUAR6_V_SIZE                                     1
#define AVR32_MPUAR7                                   0x0000015c
#define AVR32_MPUAR7_BASE                                      12
#define AVR32_MPUAR7_BASE_MASK                         0xfffff000
#define AVR32_MPUAR7_BASE_OFFSET                               12
#define AVR32_MPUAR7_BASE_SIZE                                 20
#define AVR32_MPUAR7_SIZE                                       1
#define AVR32_MPUAR7_SIZE_MASK                         0x0000003e
#define AVR32_MPUAR7_SIZE_OFFSET                                1
#define AVR32_MPUAR7_SIZE_SIZE                                  5
#define AVR32_MPUAR7_V                                          0
#define AVR32_MPUAR7_V_MASK                            0x00000001
#define AVR32_MPUAR7_V_OFFSET                                   0
#define AVR32_MPUAR7_V_SIZE                                     1
#define AVR32_MPUBRA                                   0x00000188
#define AVR32_MPUBRA_B0                                         0
#define AVR32_MPUBRA_B0_MASK                           0x00000001
#define AVR32_MPUBRA_B0_OFFSET                                  0
#define AVR32_MPUBRA_B0_SIZE                                    1
#define AVR32_MPUBRA_B1                                         1
#define AVR32_MPUBRA_B1_MASK                           0x00000002
#define AVR32_MPUBRA_B1_OFFSET                                  1
#define AVR32_MPUBRA_B1_SIZE                                    1
#define AVR32_MPUBRA_B2                                         2
#define AVR32_MPUBRA_B2_MASK                           0x00000004
#define AVR32_MPUBRA_B2_OFFSET                                  2
#define AVR32_MPUBRA_B2_SIZE                                    1
#define AVR32_MPUBRA_B3                                         3
#define AVR32_MPUBRA_B3_MASK                           0x00000008
#define AVR32_MPUBRA_B3_OFFSET                                  3
#define AVR32_MPUBRA_B3_SIZE                                    1
#define AVR32_MPUBRA_B4                                         4
#define AVR32_MPUBRA_B4_MASK                           0x00000010
#define AVR32_MPUBRA_B4_OFFSET                                  4
#define AVR32_MPUBRA_B4_SIZE                                    1
#define AVR32_MPUBRA_B5                                         5
#define AVR32_MPUBRA_B5_MASK                           0x00000020
#define AVR32_MPUBRA_B5_OFFSET                                  5
#define AVR32_MPUBRA_B5_SIZE                                    1
#define AVR32_MPUBRA_B6                                         6
#define AVR32_MPUBRA_B6_MASK                           0x00000040
#define AVR32_MPUBRA_B6_OFFSET                                  6
#define AVR32_MPUBRA_B6_SIZE                                    1
#define AVR32_MPUBRA_B7                                         7
#define AVR32_MPUBRA_B7_MASK                           0x00000080
#define AVR32_MPUBRA_B7_OFFSET                                  7
#define AVR32_MPUBRA_B7_SIZE                                    1
#define AVR32_MPUBRB                                   0x0000018c
#define AVR32_MPUBRB_B0                                         0
#define AVR32_MPUBRB_B0_MASK                           0x00000001
#define AVR32_MPUBRB_B0_OFFSET                                  0
#define AVR32_MPUBRB_B0_SIZE                                    1
#define AVR32_MPUBRB_B1                                         1
#define AVR32_MPUBRB_B1_MASK                           0x00000002
#define AVR32_MPUBRB_B1_OFFSET                                  1
#define AVR32_MPUBRB_B1_SIZE                                    1
#define AVR32_MPUBRB_B2                                         2
#define AVR32_MPUBRB_B2_MASK                           0x00000004
#define AVR32_MPUBRB_B2_OFFSET                                  2
#define AVR32_MPUBRB_B2_SIZE                                    1
#define AVR32_MPUBRB_B3                                         3
#define AVR32_MPUBRB_B3_MASK                           0x00000008
#define AVR32_MPUBRB_B3_OFFSET                                  3
#define AVR32_MPUBRB_B3_SIZE                                    1
#define AVR32_MPUBRB_B4                                         4
#define AVR32_MPUBRB_B4_MASK                           0x00000010
#define AVR32_MPUBRB_B4_OFFSET                                  4
#define AVR32_MPUBRB_B4_SIZE                                    1
#define AVR32_MPUBRB_B5                                         5
#define AVR32_MPUBRB_B5_MASK                           0x00000020
#define AVR32_MPUBRB_B5_OFFSET                                  5
#define AVR32_MPUBRB_B5_SIZE                                    1
#define AVR32_MPUBRB_B6                                         6
#define AVR32_MPUBRB_B6_MASK                           0x00000040
#define AVR32_MPUBRB_B6_OFFSET                                  6
#define AVR32_MPUBRB_B6_SIZE                                    1
#define AVR32_MPUBRB_B7                                         7
#define AVR32_MPUBRB_B7_MASK                           0x00000080
#define AVR32_MPUBRB_B7_OFFSET                                  7
#define AVR32_MPUBRB_B7_SIZE                                    1
#define AVR32_MPUCR                                    0x00000198
#define AVR32_MPUCRA                                   0x00000180
#define AVR32_MPUCRA_C0                                         0
#define AVR32_MPUCRA_C0_MASK                           0x00000001
#define AVR32_MPUCRA_C0_OFFSET                                  0
#define AVR32_MPUCRA_C0_SIZE                                    1
#define AVR32_MPUCRA_C1                                         1
#define AVR32_MPUCRA_C1_MASK                           0x00000002
#define AVR32_MPUCRA_C1_OFFSET                                  1
#define AVR32_MPUCRA_C1_SIZE                                    1
#define AVR32_MPUCRA_C2                                         2
#define AVR32_MPUCRA_C2_MASK                           0x00000004
#define AVR32_MPUCRA_C2_OFFSET                                  2
#define AVR32_MPUCRA_C2_SIZE                                    1
#define AVR32_MPUCRA_C3                                         3
#define AVR32_MPUCRA_C3_MASK                           0x00000008
#define AVR32_MPUCRA_C3_OFFSET                                  3
#define AVR32_MPUCRA_C3_SIZE                                    1
#define AVR32_MPUCRA_C4                                         4
#define AVR32_MPUCRA_C4_MASK                           0x00000010
#define AVR32_MPUCRA_C4_OFFSET                                  4
#define AVR32_MPUCRA_C4_SIZE                                    1
#define AVR32_MPUCRA_C5                                         5
#define AVR32_MPUCRA_C5_MASK                           0x00000020
#define AVR32_MPUCRA_C5_OFFSET                                  5
#define AVR32_MPUCRA_C5_SIZE                                    1
#define AVR32_MPUCRA_C6                                         6
#define AVR32_MPUCRA_C6_MASK                           0x00000040
#define AVR32_MPUCRA_C6_OFFSET                                  6
#define AVR32_MPUCRA_C6_SIZE                                    1
#define AVR32_MPUCRA_C7                                         7
#define AVR32_MPUCRA_C7_MASK                           0x00000080
#define AVR32_MPUCRA_C7_OFFSET                                  7
#define AVR32_MPUCRA_C7_SIZE                                    1
#define AVR32_MPUCRB                                   0x00000184
#define AVR32_MPUCRB_C0                                         0
#define AVR32_MPUCRB_C0_MASK                           0x00000001
#define AVR32_MPUCRB_C0_OFFSET                                  0
#define AVR32_MPUCRB_C0_SIZE                                    1
#define AVR32_MPUCRB_C1                                         1
#define AVR32_MPUCRB_C1_MASK                           0x00000002
#define AVR32_MPUCRB_C1_OFFSET                                  1
#define AVR32_MPUCRB_C1_SIZE                                    1
#define AVR32_MPUCRB_C2                                         2
#define AVR32_MPUCRB_C2_MASK                           0x00000004
#define AVR32_MPUCRB_C2_OFFSET                                  2
#define AVR32_MPUCRB_C2_SIZE                                    1
#define AVR32_MPUCRB_C3                                         3
#define AVR32_MPUCRB_C3_MASK                           0x00000008
#define AVR32_MPUCRB_C3_OFFSET                                  3
#define AVR32_MPUCRB_C3_SIZE                                    1
#define AVR32_MPUCRB_C4                                         4
#define AVR32_MPUCRB_C4_MASK                           0x00000010
#define AVR32_MPUCRB_C4_OFFSET                                  4
#define AVR32_MPUCRB_C4_SIZE                                    1
#define AVR32_MPUCRB_C5                                         5
#define AVR32_MPUCRB_C5_MASK                           0x00000020
#define AVR32_MPUCRB_C5_OFFSET                                  5
#define AVR32_MPUCRB_C5_SIZE                                    1
#define AVR32_MPUCRB_C6                                         6
#define AVR32_MPUCRB_C6_MASK                           0x00000040
#define AVR32_MPUCRB_C6_OFFSET                                  6
#define AVR32_MPUCRB_C6_SIZE                                    1
#define AVR32_MPUCRB_C7                                         7
#define AVR32_MPUCRB_C7_MASK                           0x00000080
#define AVR32_MPUCRB_C7_OFFSET                                  7
#define AVR32_MPUCRB_C7_SIZE                                    1
#define AVR32_MPUCR_E                                           0
#define AVR32_MPUCR_E_MASK                             0x00000001
#define AVR32_MPUCR_E_OFFSET                                    0
#define AVR32_MPUCR_E_SIZE                                      1
#define AVR32_MPUPSR0                                  0x00000160
#define AVR32_MPUPSR0_P0                                        0
#define AVR32_MPUPSR0_P0_MASK                          0x00000001
#define AVR32_MPUPSR0_P0_OFFSET                                 0
#define AVR32_MPUPSR0_P0_SIZE                                   1
#define AVR32_MPUPSR0_P1                                        1
#define AVR32_MPUPSR0_P10                                      10
#define AVR32_MPUPSR0_P10_MASK                         0x00000400
#define AVR32_MPUPSR0_P10_OFFSET                               10
#define AVR32_MPUPSR0_P10_SIZE                                  1
#define AVR32_MPUPSR0_P11                                      11
#define AVR32_MPUPSR0_P11_MASK                         0x00000800
#define AVR32_MPUPSR0_P11_OFFSET                               11
#define AVR32_MPUPSR0_P11_SIZE                                  1
#define AVR32_MPUPSR0_P12                                      12
#define AVR32_MPUPSR0_P12_MASK                         0x00001000
#define AVR32_MPUPSR0_P12_OFFSET                               12
#define AVR32_MPUPSR0_P12_SIZE                                  1
#define AVR32_MPUPSR0_P13                                      13
#define AVR32_MPUPSR0_P13_MASK                         0x00002000
#define AVR32_MPUPSR0_P13_OFFSET                               13
#define AVR32_MPUPSR0_P13_SIZE                                  1
#define AVR32_MPUPSR0_P14                                      14
#define AVR32_MPUPSR0_P14_MASK                         0x00004000
#define AVR32_MPUPSR0_P14_OFFSET                               14
#define AVR32_MPUPSR0_P14_SIZE                                  1
#define AVR32_MPUPSR0_P15                                      15
#define AVR32_MPUPSR0_P15_MASK                         0x00008000
#define AVR32_MPUPSR0_P15_OFFSET                               15
#define AVR32_MPUPSR0_P15_SIZE                                  1
#define AVR32_MPUPSR0_P1_MASK                          0x00000002
#define AVR32_MPUPSR0_P1_OFFSET                                 1
#define AVR32_MPUPSR0_P1_SIZE                                   1
#define AVR32_MPUPSR0_P2                                        2
#define AVR32_MPUPSR0_P2_MASK                          0x00000004
#define AVR32_MPUPSR0_P2_OFFSET                                 2
#define AVR32_MPUPSR0_P2_SIZE                                   1
#define AVR32_MPUPSR0_P3                                        3
#define AVR32_MPUPSR0_P3_MASK                          0x00000008
#define AVR32_MPUPSR0_P3_OFFSET                                 3
#define AVR32_MPUPSR0_P3_SIZE                                   1
#define AVR32_MPUPSR0_P4                                        4
#define AVR32_MPUPSR0_P4_MASK                          0x00000010
#define AVR32_MPUPSR0_P4_OFFSET                                 4
#define AVR32_MPUPSR0_P4_SIZE                                   1
#define AVR32_MPUPSR0_P5                                        5
#define AVR32_MPUPSR0_P5_MASK                          0x00000020
#define AVR32_MPUPSR0_P5_OFFSET                                 5
#define AVR32_MPUPSR0_P5_SIZE                                   1
#define AVR32_MPUPSR0_P6                                        6
#define AVR32_MPUPSR0_P6_MASK                          0x00000040
#define AVR32_MPUPSR0_P6_OFFSET                                 6
#define AVR32_MPUPSR0_P6_SIZE                                   1
#define AVR32_MPUPSR0_P7                                        7
#define AVR32_MPUPSR0_P7_MASK                          0x00000080
#define AVR32_MPUPSR0_P7_OFFSET                                 7
#define AVR32_MPUPSR0_P7_SIZE                                   1
#define AVR32_MPUPSR0_P8                                        8
#define AVR32_MPUPSR0_P8_MASK                          0x00000100
#define AVR32_MPUPSR0_P8_OFFSET                                 8
#define AVR32_MPUPSR0_P8_SIZE                                   1
#define AVR32_MPUPSR0_P9                                        9
#define AVR32_MPUPSR0_P9_MASK                          0x00000200
#define AVR32_MPUPSR0_P9_OFFSET                                 9
#define AVR32_MPUPSR0_P9_SIZE                                   1
#define AVR32_MPUPSR1                                  0x00000164
#define AVR32_MPUPSR1_P0                                        0
#define AVR32_MPUPSR1_P0_MASK                          0x00000001
#define AVR32_MPUPSR1_P0_OFFSET                                 0
#define AVR32_MPUPSR1_P0_SIZE                                   1
#define AVR32_MPUPSR1_P1                                        1
#define AVR32_MPUPSR1_P10                                      10
#define AVR32_MPUPSR1_P10_MASK                         0x00000400
#define AVR32_MPUPSR1_P10_OFFSET                               10
#define AVR32_MPUPSR1_P10_SIZE                                  1
#define AVR32_MPUPSR1_P11                                      11
#define AVR32_MPUPSR1_P11_MASK                         0x00000800
#define AVR32_MPUPSR1_P11_OFFSET                               11
#define AVR32_MPUPSR1_P11_SIZE                                  1
#define AVR32_MPUPSR1_P12                                      12
#define AVR32_MPUPSR1_P12_MASK                         0x00001000
#define AVR32_MPUPSR1_P12_OFFSET                               12
#define AVR32_MPUPSR1_P12_SIZE                                  1
#define AVR32_MPUPSR1_P13                                      13
#define AVR32_MPUPSR1_P13_MASK                         0x00002000
#define AVR32_MPUPSR1_P13_OFFSET                               13
#define AVR32_MPUPSR1_P13_SIZE                                  1
#define AVR32_MPUPSR1_P14                                      14
#define AVR32_MPUPSR1_P14_MASK                         0x00004000
#define AVR32_MPUPSR1_P14_OFFSET                               14
#define AVR32_MPUPSR1_P14_SIZE                                  1
#define AVR32_MPUPSR1_P15                                      15
#define AVR32_MPUPSR1_P15_MASK                         0x00008000
#define AVR32_MPUPSR1_P15_OFFSET                               15
#define AVR32_MPUPSR1_P15_SIZE                                  1
#define AVR32_MPUPSR1_P1_MASK                          0x00000002
#define AVR32_MPUPSR1_P1_OFFSET                                 1
#define AVR32_MPUPSR1_P1_SIZE                                   1
#define AVR32_MPUPSR1_P2                                        2
#define AVR32_MPUPSR1_P2_MASK                          0x00000004
#define AVR32_MPUPSR1_P2_OFFSET                                 2
#define AVR32_MPUPSR1_P2_SIZE                                   1
#define AVR32_MPUPSR1_P3                                        3
#define AVR32_MPUPSR1_P3_MASK                          0x00000008
#define AVR32_MPUPSR1_P3_OFFSET                                 3
#define AVR32_MPUPSR1_P3_SIZE                                   1
#define AVR32_MPUPSR1_P4                                        4
#define AVR32_MPUPSR1_P4_MASK                          0x00000010
#define AVR32_MPUPSR1_P4_OFFSET                                 4
#define AVR32_MPUPSR1_P4_SIZE                                   1
#define AVR32_MPUPSR1_P5                                        5
#define AVR32_MPUPSR1_P5_MASK                          0x00000020
#define AVR32_MPUPSR1_P5_OFFSET                                 5
#define AVR32_MPUPSR1_P5_SIZE                                   1
#define AVR32_MPUPSR1_P6                                        6
#define AVR32_MPUPSR1_P6_MASK                          0x00000040
#define AVR32_MPUPSR1_P6_OFFSET                                 6
#define AVR32_MPUPSR1_P6_SIZE                                   1
#define AVR32_MPUPSR1_P7                                        7
#define AVR32_MPUPSR1_P7_MASK                          0x00000080
#define AVR32_MPUPSR1_P7_OFFSET                                 7
#define AVR32_MPUPSR1_P7_SIZE                                   1
#define AVR32_MPUPSR1_P8                                        8
#define AVR32_MPUPSR1_P8_MASK                          0x00000100
#define AVR32_MPUPSR1_P8_OFFSET                                 8
#define AVR32_MPUPSR1_P8_SIZE                                   1
#define AVR32_MPUPSR1_P9                                        9
#define AVR32_MPUPSR1_P9_MASK                          0x00000200
#define AVR32_MPUPSR1_P9_OFFSET                                 9
#define AVR32_MPUPSR1_P9_SIZE                                   1
#define AVR32_MPUPSR2                                  0x00000168
#define AVR32_MPUPSR2_P0                                        0
#define AVR32_MPUPSR2_P0_MASK                          0x00000001
#define AVR32_MPUPSR2_P0_OFFSET                                 0
#define AVR32_MPUPSR2_P0_SIZE                                   1
#define AVR32_MPUPSR2_P1                                        1
#define AVR32_MPUPSR2_P10                                      10
#define AVR32_MPUPSR2_P10_MASK                         0x00000400
#define AVR32_MPUPSR2_P10_OFFSET                               10
#define AVR32_MPUPSR2_P10_SIZE                                  1
#define AVR32_MPUPSR2_P11                                      11
#define AVR32_MPUPSR2_P11_MASK                         0x00000800
#define AVR32_MPUPSR2_P11_OFFSET                               11
#define AVR32_MPUPSR2_P11_SIZE                                  1
#define AVR32_MPUPSR2_P12                                      12
#define AVR32_MPUPSR2_P12_MASK                         0x00001000
#define AVR32_MPUPSR2_P12_OFFSET                               12
#define AVR32_MPUPSR2_P12_SIZE                                  1
#define AVR32_MPUPSR2_P13                                      13
#define AVR32_MPUPSR2_P13_MASK                         0x00002000
#define AVR32_MPUPSR2_P13_OFFSET                               13
#define AVR32_MPUPSR2_P13_SIZE                                  1
#define AVR32_MPUPSR2_P14                                      14
#define AVR32_MPUPSR2_P14_MASK                         0x00004000
#define AVR32_MPUPSR2_P14_OFFSET                               14
#define AVR32_MPUPSR2_P14_SIZE                                  1
#define AVR32_MPUPSR2_P15                                      15
#define AVR32_MPUPSR2_P15_MASK                         0x00008000
#define AVR32_MPUPSR2_P15_OFFSET                               15
#define AVR32_MPUPSR2_P15_SIZE                                  1
#define AVR32_MPUPSR2_P1_MASK                          0x00000002
#define AVR32_MPUPSR2_P1_OFFSET                                 1
#define AVR32_MPUPSR2_P1_SIZE                                   1
#define AVR32_MPUPSR2_P2                                        2
#define AVR32_MPUPSR2_P2_MASK                          0x00000004
#define AVR32_MPUPSR2_P2_OFFSET                                 2
#define AVR32_MPUPSR2_P2_SIZE                                   1
#define AVR32_MPUPSR2_P3                                        3
#define AVR32_MPUPSR2_P3_MASK                          0x00000008
#define AVR32_MPUPSR2_P3_OFFSET                                 3
#define AVR32_MPUPSR2_P3_SIZE                                   1
#define AVR32_MPUPSR2_P4                                        4
#define AVR32_MPUPSR2_P4_MASK                          0x00000010
#define AVR32_MPUPSR2_P4_OFFSET                                 4
#define AVR32_MPUPSR2_P4_SIZE                                   1
#define AVR32_MPUPSR2_P5                                        5
#define AVR32_MPUPSR2_P5_MASK                          0x00000020
#define AVR32_MPUPSR2_P5_OFFSET                                 5
#define AVR32_MPUPSR2_P5_SIZE                                   1
#define AVR32_MPUPSR2_P6                                        6
#define AVR32_MPUPSR2_P6_MASK                          0x00000040
#define AVR32_MPUPSR2_P6_OFFSET                                 6
#define AVR32_MPUPSR2_P6_SIZE                                   1
#define AVR32_MPUPSR2_P7                                        7
#define AVR32_MPUPSR2_P7_MASK                          0x00000080
#define AVR32_MPUPSR2_P7_OFFSET                                 7
#define AVR32_MPUPSR2_P7_SIZE                                   1
#define AVR32_MPUPSR2_P8                                        8
#define AVR32_MPUPSR2_P8_MASK                          0x00000100
#define AVR32_MPUPSR2_P8_OFFSET                                 8
#define AVR32_MPUPSR2_P8_SIZE                                   1
#define AVR32_MPUPSR2_P9                                        9
#define AVR32_MPUPSR2_P9_MASK                          0x00000200
#define AVR32_MPUPSR2_P9_OFFSET                                 9
#define AVR32_MPUPSR2_P9_SIZE                                   1
#define AVR32_MPUPSR3                                  0x0000016c
#define AVR32_MPUPSR3_P0                                        0
#define AVR32_MPUPSR3_P0_MASK                          0x00000001
#define AVR32_MPUPSR3_P0_OFFSET                                 0
#define AVR32_MPUPSR3_P0_SIZE                                   1
#define AVR32_MPUPSR3_P1                                        1
#define AVR32_MPUPSR3_P10                                      10
#define AVR32_MPUPSR3_P10_MASK                         0x00000400
#define AVR32_MPUPSR3_P10_OFFSET                               10
#define AVR32_MPUPSR3_P10_SIZE                                  1
#define AVR32_MPUPSR3_P11                                      11
#define AVR32_MPUPSR3_P11_MASK                         0x00000800
#define AVR32_MPUPSR3_P11_OFFSET                               11
#define AVR32_MPUPSR3_P11_SIZE                                  1
#define AVR32_MPUPSR3_P12                                      12
#define AVR32_MPUPSR3_P12_MASK                         0x00001000
#define AVR32_MPUPSR3_P12_OFFSET                               12
#define AVR32_MPUPSR3_P12_SIZE                                  1
#define AVR32_MPUPSR3_P13                                      13
#define AVR32_MPUPSR3_P13_MASK                         0x00002000
#define AVR32_MPUPSR3_P13_OFFSET                               13
#define AVR32_MPUPSR3_P13_SIZE                                  1
#define AVR32_MPUPSR3_P14                                      14
#define AVR32_MPUPSR3_P14_MASK                         0x00004000
#define AVR32_MPUPSR3_P14_OFFSET                               14
#define AVR32_MPUPSR3_P14_SIZE                                  1
#define AVR32_MPUPSR3_P15                                      15
#define AVR32_MPUPSR3_P15_MASK                         0x00008000
#define AVR32_MPUPSR3_P15_OFFSET                               15
#define AVR32_MPUPSR3_P15_SIZE                                  1
#define AVR32_MPUPSR3_P1_MASK                          0x00000002
#define AVR32_MPUPSR3_P1_OFFSET                                 1
#define AVR32_MPUPSR3_P1_SIZE                                   1
#define AVR32_MPUPSR3_P2                                        2
#define AVR32_MPUPSR3_P2_MASK                          0x00000004
#define AVR32_MPUPSR3_P2_OFFSET                                 2
#define AVR32_MPUPSR3_P2_SIZE                                   1
#define AVR32_MPUPSR3_P3                                        3
#define AVR32_MPUPSR3_P3_MASK                          0x00000008
#define AVR32_MPUPSR3_P3_OFFSET                                 3
#define AVR32_MPUPSR3_P3_SIZE                                   1
#define AVR32_MPUPSR3_P4                                        4
#define AVR32_MPUPSR3_P4_MASK                          0x00000010
#define AVR32_MPUPSR3_P4_OFFSET                                 4
#define AVR32_MPUPSR3_P4_SIZE                                   1
#define AVR32_MPUPSR3_P5                                        5
#define AVR32_MPUPSR3_P5_MASK                          0x00000020
#define AVR32_MPUPSR3_P5_OFFSET                                 5
#define AVR32_MPUPSR3_P5_SIZE                                   1
#define AVR32_MPUPSR3_P6                                        6
#define AVR32_MPUPSR3_P6_MASK                          0x00000040
#define AVR32_MPUPSR3_P6_OFFSET                                 6
#define AVR32_MPUPSR3_P6_SIZE                                   1
#define AVR32_MPUPSR3_P7                                        7
#define AVR32_MPUPSR3_P7_MASK                          0x00000080
#define AVR32_MPUPSR3_P7_OFFSET                                 7
#define AVR32_MPUPSR3_P7_SIZE                                   1
#define AVR32_MPUPSR3_P8                                        8
#define AVR32_MPUPSR3_P8_MASK                          0x00000100
#define AVR32_MPUPSR3_P8_OFFSET                                 8
#define AVR32_MPUPSR3_P8_SIZE                                   1
#define AVR32_MPUPSR3_P9                                        9
#define AVR32_MPUPSR3_P9_MASK                          0x00000200
#define AVR32_MPUPSR3_P9_OFFSET                                 9
#define AVR32_MPUPSR3_P9_SIZE                                   1
#define AVR32_MPUPSR4                                  0x00000170
#define AVR32_MPUPSR4_P0                                        0
#define AVR32_MPUPSR4_P0_MASK                          0x00000001
#define AVR32_MPUPSR4_P0_OFFSET                                 0
#define AVR32_MPUPSR4_P0_SIZE                                   1
#define AVR32_MPUPSR4_P1                                        1
#define AVR32_MPUPSR4_P10                                      10
#define AVR32_MPUPSR4_P10_MASK                         0x00000400
#define AVR32_MPUPSR4_P10_OFFSET                               10
#define AVR32_MPUPSR4_P10_SIZE                                  1
#define AVR32_MPUPSR4_P11                                      11
#define AVR32_MPUPSR4_P11_MASK                         0x00000800
#define AVR32_MPUPSR4_P11_OFFSET                               11
#define AVR32_MPUPSR4_P11_SIZE                                  1
#define AVR32_MPUPSR4_P12                                      12
#define AVR32_MPUPSR4_P12_MASK                         0x00001000
#define AVR32_MPUPSR4_P12_OFFSET                               12
#define AVR32_MPUPSR4_P12_SIZE                                  1
#define AVR32_MPUPSR4_P13                                      13
#define AVR32_MPUPSR4_P13_MASK                         0x00002000
#define AVR32_MPUPSR4_P13_OFFSET                               13
#define AVR32_MPUPSR4_P13_SIZE                                  1
#define AVR32_MPUPSR4_P14                                      14
#define AVR32_MPUPSR4_P14_MASK                         0x00004000
#define AVR32_MPUPSR4_P14_OFFSET                               14
#define AVR32_MPUPSR4_P14_SIZE                                  1
#define AVR32_MPUPSR4_P15                                      15
#define AVR32_MPUPSR4_P15_MASK                         0x00008000
#define AVR32_MPUPSR4_P15_OFFSET                               15
#define AVR32_MPUPSR4_P15_SIZE                                  1
#define AVR32_MPUPSR4_P1_MASK                          0x00000002
#define AVR32_MPUPSR4_P1_OFFSET                                 1
#define AVR32_MPUPSR4_P1_SIZE                                   1
#define AVR32_MPUPSR4_P2                                        2
#define AVR32_MPUPSR4_P2_MASK                          0x00000004
#define AVR32_MPUPSR4_P2_OFFSET                                 2
#define AVR32_MPUPSR4_P2_SIZE                                   1
#define AVR32_MPUPSR4_P3                                        3
#define AVR32_MPUPSR4_P3_MASK                          0x00000008
#define AVR32_MPUPSR4_P3_OFFSET                                 3
#define AVR32_MPUPSR4_P3_SIZE                                   1
#define AVR32_MPUPSR4_P4                                        4
#define AVR32_MPUPSR4_P4_MASK                          0x00000010
#define AVR32_MPUPSR4_P4_OFFSET                                 4
#define AVR32_MPUPSR4_P4_SIZE                                   1
#define AVR32_MPUPSR4_P5                                        5
#define AVR32_MPUPSR4_P5_MASK                          0x00000020
#define AVR32_MPUPSR4_P5_OFFSET                                 5
#define AVR32_MPUPSR4_P5_SIZE                                   1
#define AVR32_MPUPSR4_P6                                        6
#define AVR32_MPUPSR4_P6_MASK                          0x00000040
#define AVR32_MPUPSR4_P6_OFFSET                                 6
#define AVR32_MPUPSR4_P6_SIZE                                   1
#define AVR32_MPUPSR4_P7                                        7
#define AVR32_MPUPSR4_P7_MASK                          0x00000080
#define AVR32_MPUPSR4_P7_OFFSET                                 7
#define AVR32_MPUPSR4_P7_SIZE                                   1
#define AVR32_MPUPSR4_P8                                        8
#define AVR32_MPUPSR4_P8_MASK                          0x00000100
#define AVR32_MPUPSR4_P8_OFFSET                                 8
#define AVR32_MPUPSR4_P8_SIZE                                   1
#define AVR32_MPUPSR4_P9                                        9
#define AVR32_MPUPSR4_P9_MASK                          0x00000200
#define AVR32_MPUPSR4_P9_OFFSET                                 9
#define AVR32_MPUPSR4_P9_SIZE                                   1
#define AVR32_MPUPSR5                                  0x00000174
#define AVR32_MPUPSR5_P0                                        0
#define AVR32_MPUPSR5_P0_MASK                          0x00000001
#define AVR32_MPUPSR5_P0_OFFSET                                 0
#define AVR32_MPUPSR5_P0_SIZE                                   1
#define AVR32_MPUPSR5_P1                                        1
#define AVR32_MPUPSR5_P10                                      10
#define AVR32_MPUPSR5_P10_MASK                         0x00000400
#define AVR32_MPUPSR5_P10_OFFSET                               10
#define AVR32_MPUPSR5_P10_SIZE                                  1
#define AVR32_MPUPSR5_P11                                      11
#define AVR32_MPUPSR5_P11_MASK                         0x00000800
#define AVR32_MPUPSR5_P11_OFFSET                               11
#define AVR32_MPUPSR5_P11_SIZE                                  1
#define AVR32_MPUPSR5_P12                                      12
#define AVR32_MPUPSR5_P12_MASK                         0x00001000
#define AVR32_MPUPSR5_P12_OFFSET                               12
#define AVR32_MPUPSR5_P12_SIZE                                  1
#define AVR32_MPUPSR5_P13                                      13
#define AVR32_MPUPSR5_P13_MASK                         0x00002000
#define AVR32_MPUPSR5_P13_OFFSET                               13
#define AVR32_MPUPSR5_P13_SIZE                                  1
#define AVR32_MPUPSR5_P14                                      14
#define AVR32_MPUPSR5_P14_MASK                         0x00004000
#define AVR32_MPUPSR5_P14_OFFSET                               14
#define AVR32_MPUPSR5_P14_SIZE                                  1
#define AVR32_MPUPSR5_P15                                      15
#define AVR32_MPUPSR5_P15_MASK                         0x00008000
#define AVR32_MPUPSR5_P15_OFFSET                               15
#define AVR32_MPUPSR5_P15_SIZE                                  1
#define AVR32_MPUPSR5_P1_MASK                          0x00000002
#define AVR32_MPUPSR5_P1_OFFSET                                 1
#define AVR32_MPUPSR5_P1_SIZE                                   1
#define AVR32_MPUPSR5_P2                                        2
#define AVR32_MPUPSR5_P2_MASK                          0x00000004
#define AVR32_MPUPSR5_P2_OFFSET                                 2
#define AVR32_MPUPSR5_P2_SIZE                                   1
#define AVR32_MPUPSR5_P3                                        3
#define AVR32_MPUPSR5_P3_MASK                          0x00000008
#define AVR32_MPUPSR5_P3_OFFSET                                 3
#define AVR32_MPUPSR5_P3_SIZE                                   1
#define AVR32_MPUPSR5_P4                                        4
#define AVR32_MPUPSR5_P4_MASK                          0x00000010
#define AVR32_MPUPSR5_P4_OFFSET                                 4
#define AVR32_MPUPSR5_P4_SIZE                                   1
#define AVR32_MPUPSR5_P5                                        5
#define AVR32_MPUPSR5_P5_MASK                          0x00000020
#define AVR32_MPUPSR5_P5_OFFSET                                 5
#define AVR32_MPUPSR5_P5_SIZE                                   1
#define AVR32_MPUPSR5_P6                                        6
#define AVR32_MPUPSR5_P6_MASK                          0x00000040
#define AVR32_MPUPSR5_P6_OFFSET                                 6
#define AVR32_MPUPSR5_P6_SIZE                                   1
#define AVR32_MPUPSR5_P7                                        7
#define AVR32_MPUPSR5_P7_MASK                          0x00000080
#define AVR32_MPUPSR5_P7_OFFSET                                 7
#define AVR32_MPUPSR5_P7_SIZE                                   1
#define AVR32_MPUPSR5_P8                                        8
#define AVR32_MPUPSR5_P8_MASK                          0x00000100
#define AVR32_MPUPSR5_P8_OFFSET                                 8
#define AVR32_MPUPSR5_P8_SIZE                                   1
#define AVR32_MPUPSR5_P9                                        9
#define AVR32_MPUPSR5_P9_MASK                          0x00000200
#define AVR32_MPUPSR5_P9_OFFSET                                 9
#define AVR32_MPUPSR5_P9_SIZE                                   1
#define AVR32_MPUPSR6                                  0x00000178
#define AVR32_MPUPSR6_P0                                        0
#define AVR32_MPUPSR6_P0_MASK                          0x00000001
#define AVR32_MPUPSR6_P0_OFFSET                                 0
#define AVR32_MPUPSR6_P0_SIZE                                   1
#define AVR32_MPUPSR6_P1                                        1
#define AVR32_MPUPSR6_P10                                      10
#define AVR32_MPUPSR6_P10_MASK                         0x00000400
#define AVR32_MPUPSR6_P10_OFFSET                               10
#define AVR32_MPUPSR6_P10_SIZE                                  1
#define AVR32_MPUPSR6_P11                                      11
#define AVR32_MPUPSR6_P11_MASK                         0x00000800
#define AVR32_MPUPSR6_P11_OFFSET                               11
#define AVR32_MPUPSR6_P11_SIZE                                  1
#define AVR32_MPUPSR6_P12                                      12
#define AVR32_MPUPSR6_P12_MASK                         0x00001000
#define AVR32_MPUPSR6_P12_OFFSET                               12
#define AVR32_MPUPSR6_P12_SIZE                                  1
#define AVR32_MPUPSR6_P13                                      13
#define AVR32_MPUPSR6_P13_MASK                         0x00002000
#define AVR32_MPUPSR6_P13_OFFSET                               13
#define AVR32_MPUPSR6_P13_SIZE                                  1
#define AVR32_MPUPSR6_P14                                      14
#define AVR32_MPUPSR6_P14_MASK                         0x00004000
#define AVR32_MPUPSR6_P14_OFFSET                               14
#define AVR32_MPUPSR6_P14_SIZE                                  1
#define AVR32_MPUPSR6_P15                                      15
#define AVR32_MPUPSR6_P15_MASK                         0x00008000
#define AVR32_MPUPSR6_P15_OFFSET                               15
#define AVR32_MPUPSR6_P15_SIZE                                  1
#define AVR32_MPUPSR6_P1_MASK                          0x00000002
#define AVR32_MPUPSR6_P1_OFFSET                                 1
#define AVR32_MPUPSR6_P1_SIZE                                   1
#define AVR32_MPUPSR6_P2                                        2
#define AVR32_MPUPSR6_P2_MASK                          0x00000004
#define AVR32_MPUPSR6_P2_OFFSET                                 2
#define AVR32_MPUPSR6_P2_SIZE                                   1
#define AVR32_MPUPSR6_P3                                        3
#define AVR32_MPUPSR6_P3_MASK                          0x00000008
#define AVR32_MPUPSR6_P3_OFFSET                                 3
#define AVR32_MPUPSR6_P3_SIZE                                   1
#define AVR32_MPUPSR6_P4                                        4
#define AVR32_MPUPSR6_P4_MASK                          0x00000010
#define AVR32_MPUPSR6_P4_OFFSET                                 4
#define AVR32_MPUPSR6_P4_SIZE                                   1
#define AVR32_MPUPSR6_P5                                        5
#define AVR32_MPUPSR6_P5_MASK                          0x00000020
#define AVR32_MPUPSR6_P5_OFFSET                                 5
#define AVR32_MPUPSR6_P5_SIZE                                   1
#define AVR32_MPUPSR6_P6                                        6
#define AVR32_MPUPSR6_P6_MASK                          0x00000040
#define AVR32_MPUPSR6_P6_OFFSET                                 6
#define AVR32_MPUPSR6_P6_SIZE                                   1
#define AVR32_MPUPSR6_P7                                        7
#define AVR32_MPUPSR6_P7_MASK                          0x00000080
#define AVR32_MPUPSR6_P7_OFFSET                                 7
#define AVR32_MPUPSR6_P7_SIZE                                   1
#define AVR32_MPUPSR6_P8                                        8
#define AVR32_MPUPSR6_P8_MASK                          0x00000100
#define AVR32_MPUPSR6_P8_OFFSET                                 8
#define AVR32_MPUPSR6_P8_SIZE                                   1
#define AVR32_MPUPSR6_P9                                        9
#define AVR32_MPUPSR6_P9_MASK                          0x00000200
#define AVR32_MPUPSR6_P9_OFFSET                                 9
#define AVR32_MPUPSR6_P9_SIZE                                   1
#define AVR32_MPUPSR7                                  0x0000017c
#define AVR32_MPUPSR7_P0                                        0
#define AVR32_MPUPSR7_P0_MASK                          0x00000001
#define AVR32_MPUPSR7_P0_OFFSET                                 0
#define AVR32_MPUPSR7_P0_SIZE                                   1
#define AVR32_MPUPSR7_P1                                        1
#define AVR32_MPUPSR7_P10                                      10
#define AVR32_MPUPSR7_P10_MASK                         0x00000400
#define AVR32_MPUPSR7_P10_OFFSET                               10
#define AVR32_MPUPSR7_P10_SIZE                                  1
#define AVR32_MPUPSR7_P11                                      11
#define AVR32_MPUPSR7_P11_MASK                         0x00000800
#define AVR32_MPUPSR7_P11_OFFSET                               11
#define AVR32_MPUPSR7_P11_SIZE                                  1
#define AVR32_MPUPSR7_P12                                      12
#define AVR32_MPUPSR7_P12_MASK                         0x00001000
#define AVR32_MPUPSR7_P12_OFFSET                               12
#define AVR32_MPUPSR7_P12_SIZE                                  1
#define AVR32_MPUPSR7_P13                                      13
#define AVR32_MPUPSR7_P13_MASK                         0x00002000
#define AVR32_MPUPSR7_P13_OFFSET                               13
#define AVR32_MPUPSR7_P13_SIZE                                  1
#define AVR32_MPUPSR7_P14                                      14
#define AVR32_MPUPSR7_P14_MASK                         0x00004000
#define AVR32_MPUPSR7_P14_OFFSET                               14
#define AVR32_MPUPSR7_P14_SIZE                                  1
#define AVR32_MPUPSR7_P15                                      15
#define AVR32_MPUPSR7_P15_MASK                         0x00008000
#define AVR32_MPUPSR7_P15_OFFSET                               15
#define AVR32_MPUPSR7_P15_SIZE                                  1
#define AVR32_MPUPSR7_P1_MASK                          0x00000002
#define AVR32_MPUPSR7_P1_OFFSET                                 1
#define AVR32_MPUPSR7_P1_SIZE                                   1
#define AVR32_MPUPSR7_P2                                        2
#define AVR32_MPUPSR7_P2_MASK                          0x00000004
#define AVR32_MPUPSR7_P2_OFFSET                                 2
#define AVR32_MPUPSR7_P2_SIZE                                   1
#define AVR32_MPUPSR7_P3                                        3
#define AVR32_MPUPSR7_P3_MASK                          0x00000008
#define AVR32_MPUPSR7_P3_OFFSET                                 3
#define AVR32_MPUPSR7_P3_SIZE                                   1
#define AVR32_MPUPSR7_P4                                        4
#define AVR32_MPUPSR7_P4_MASK                          0x00000010
#define AVR32_MPUPSR7_P4_OFFSET                                 4
#define AVR32_MPUPSR7_P4_SIZE                                   1
#define AVR32_MPUPSR7_P5                                        5
#define AVR32_MPUPSR7_P5_MASK                          0x00000020
#define AVR32_MPUPSR7_P5_OFFSET                                 5
#define AVR32_MPUPSR7_P5_SIZE                                   1
#define AVR32_MPUPSR7_P6                                        6
#define AVR32_MPUPSR7_P6_MASK                          0x00000040
#define AVR32_MPUPSR7_P6_OFFSET                                 6
#define AVR32_MPUPSR7_P6_SIZE                                   1
#define AVR32_MPUPSR7_P7                                        7
#define AVR32_MPUPSR7_P7_MASK                          0x00000080
#define AVR32_MPUPSR7_P7_OFFSET                                 7
#define AVR32_MPUPSR7_P7_SIZE                                   1
#define AVR32_MPUPSR7_P8                                        8
#define AVR32_MPUPSR7_P8_MASK                          0x00000100
#define AVR32_MPUPSR7_P8_OFFSET                                 8
#define AVR32_MPUPSR7_P8_SIZE                                   1
#define AVR32_MPUPSR7_P9                                        9
#define AVR32_MPUPSR7_P9_MASK                          0x00000200
#define AVR32_MPUPSR7_P9_OFFSET                                 9
#define AVR32_MPUPSR7_P9_SIZE                                   1

#define AVR32_MSU_ADDRHI                               0x000003E0
#define AVR32_MSU_ADDRHI_MASK                          0x0000000F
#define AVR32_MSU_ADDRHI_RESETVALUE                    0x00000000
#define AVR32_MSU_ADDRLO                               0x000003E4
#define AVR32_MSU_ADDRLO_MASK                          0xFFFFFFFC
#define AVR32_MSU_ADDRLO_RESETVALUE                    0x00000000
#define AVR32_MSU_LENGTH                               0x000003E8
#define AVR32_MSU_LENGTH_MASK                          0xFFFFFFFC
#define AVR32_MSU_LENGTH_RESETVALUE                    0x00000000
#define AVR32_MSU_CTRL                                 0x000003EC
#define AVR32_MSU_CTRL_OP_MASK                         0x0000000F
#define AVR32_MSU_CTRL_NTBC_MASK                       0x00000030
#define AVR32_MSU_CTRL_RESETVALUE                      0x00000000
#define AVR32_MSU_STATUS                               0x000003F0
#define AVR32_MSU_STATUS_RESULT_MASK                   0x00000007
#define AVR32_MSU_STATUS_WRAP_MASK                     0x00000008
#define AVR32_MSU_STATUS_RESETVALUE                    0x00000000
#define AVR32_MSU_DATA                                 0x000003F4
#define AVR32_MSU_DATA_MASK                            0xFFFFFFFF
#define AVR32_MSU_DATA_RESETVALUE                      0x00000000
#define AVR32_MSU_TAIL                                 0x000003F8
#define AVR32_MSU_TAIL_MASK                            0xFFFFFFFC
#define AVR32_MSU_TAIL_RESETVALUE                      0x00000000

#define AVR32_RAR_DBG                                  0x00000050
#define AVR32_RSR_DBG                                  0x00000030
#define AVR32_SR                                       0x00000000
#define AVR32_SR_C                                              0
#define AVR32_SR_C_MASK                                0x00000001
#define AVR32_SR_C_OFFSET                                       0
#define AVR32_SR_C_SIZE                                         1
#define AVR32_SR_D                                             26
#define AVR32_SR_DM                                            27
#define AVR32_SR_DM_MASK                               0x08000000
#define AVR32_SR_DM_OFFSET                                     27
#define AVR32_SR_DM_SIZE                                        1
#define AVR32_SR_D_MASK                                0x04000000
#define AVR32_SR_D_OFFSET                                      26
#define AVR32_SR_D_SIZE                                         1
#define AVR32_SR_EM                                            21
#define AVR32_SR_EM_MASK                               0x00200000
#define AVR32_SR_EM_OFFSET                                     21
#define AVR32_SR_EM_SIZE                                        1
#define AVR32_SR_GM                                            16
#define AVR32_SR_GM_MASK                               0x00010000
#define AVR32_SR_GM_OFFSET                                     16
#define AVR32_SR_GM_SIZE                                        1
#define AVR32_SR_I0M                                           17
#define AVR32_SR_I0M_MASK                              0x00020000
#define AVR32_SR_I0M_OFFSET                                    17
#define AVR32_SR_I0M_SIZE                                       1
#define AVR32_SR_I1M                                           18
#define AVR32_SR_I1M_MASK                              0x00040000
#define AVR32_SR_I1M_OFFSET                                    18
#define AVR32_SR_I1M_SIZE                                       1
#define AVR32_SR_I2M                                           19
#define AVR32_SR_I2M_MASK                              0x00080000
#define AVR32_SR_I2M_OFFSET                                    19
#define AVR32_SR_I2M_SIZE                                       1
#define AVR32_SR_I3M                                           20
#define AVR32_SR_I3M_MASK                              0x00100000
#define AVR32_SR_I3M_OFFSET                                    20
#define AVR32_SR_I3M_SIZE                                       1
#define AVR32_SR_L                                              5
#define AVR32_SR_L_MASK                                0x00000020
#define AVR32_SR_L_OFFSET                                       5
#define AVR32_SR_L_SIZE                                         1
#define AVR32_SR_M0                                            22
#define AVR32_SR_M0_MASK                               0x00400000
#define AVR32_SR_M0_OFFSET                                     22
#define AVR32_SR_M0_SIZE                                        1
#define AVR32_SR_M1                                            23
#define AVR32_SR_M1_MASK                               0x00800000
#define AVR32_SR_M1_OFFSET                                     23
#define AVR32_SR_M1_SIZE                                        1
#define AVR32_SR_M2                                            24
#define AVR32_SR_M2_MASK                               0x01000000
#define AVR32_SR_M2_OFFSET                                     24
#define AVR32_SR_M2_SIZE                                        1
#define AVR32_SR_M                                             22
#define AVR32_SR_M_APP                                 0x00000000
#define AVR32_SR_M_EX                                  0x00000006
#define AVR32_SR_M_INT0                                0x00000002
#define AVR32_SR_M_INT1                                0x00000003
#define AVR32_SR_M_INT2                                0x00000004
#define AVR32_SR_M_INT3                                0x00000005
#define AVR32_SR_M_MASK                                0x01c00000
#define AVR32_SR_M_NMI                                 0x00000007
#define AVR32_SR_M_OFFSET                                      22
#define AVR32_SR_M_SIZE                                         3
#define AVR32_SR_M_SUP                                 0x00000001
#define AVR32_SR_N                                              2
#define AVR32_SR_N_MASK                                0x00000004
#define AVR32_SR_N_OFFSET                                       2
#define AVR32_SR_N_SIZE                                         1
#define AVR32_SR_Q                                              4
#define AVR32_SR_Q_MASK                                0x00000010
#define AVR32_SR_Q_OFFSET                                       4
#define AVR32_SR_Q_SIZE                                         1
#define AVR32_SR_T                                             14
#define AVR32_SR_T_MASK                                0x00004000
#define AVR32_SR_T_OFFSET                                      14
#define AVR32_SR_T_SIZE                                         1
#define AVR32_SR_V                                              3
#define AVR32_SR_V_MASK                                0x00000008
#define AVR32_SR_V_OFFSET                                       3
#define AVR32_SR_V_SIZE                                         1
#define AVR32_SR_Z                                              1
#define AVR32_SR_Z_MASK                                0x00000002
#define AVR32_SR_Z_OFFSET                                       1
#define AVR32_SR_Z_SIZE                                         1

#define AVR32_EVBA_OFFSET_BREAKPOINT                   0x0000001c
#define AVR32_EVBA_OFFSET_BUS_ERROR_DATA               0x00000008
#define AVR32_EVBA_OFFSET_BUS_ERROR_INSTR              0x0000000c
#define AVR32_EVBA_OFFSET_COP_ABSENT                   0x00000030
#define AVR32_EVBA_OFFSET_DATA_ADDR_R                  0x00000034
#define AVR32_EVBA_OFFSET_DATA_ADDR_W                  0x00000038
#define AVR32_EVBA_OFFSET_DTLB_MISS_R                  0x00000060
#define AVR32_EVBA_OFFSET_DTLB_MISS_W                  0x00000070
#define AVR32_EVBA_OFFSET_DTLB_MODIFIED                0x00000044
#define AVR32_EVBA_OFFSET_DTLB_PROT_R                  0x0000003c
#define AVR32_EVBA_OFFSET_DTLB_PROT_W                  0x00000040
#define AVR32_EVBA_OFFSET_FLOATING_POINT               0x0000002c
#define AVR32_EVBA_OFFSET_ILLEGAL_OPCODE               0x00000020
#define AVR32_EVBA_OFFSET_INSTR_ADDR                   0x00000014
#define AVR32_EVBA_OFFSET_ITLB_MISS                    0x00000050
#define AVR32_EVBA_OFFSET_ITLB_PROT                    0x00000018
#define AVR32_EVBA_OFFSET_NMI                          0x00000010
#define AVR32_EVBA_OFFSET_PRIVILEGE_VIOL               0x00000028
#define AVR32_EVBA_OFFSET_SCALL                        0x00000100
#define AVR32_EVBA_OFFSET_TLB_MULTIPLE                 0x00000004
#define AVR32_EVBA_OFFSET_UNIMPLEMENTED                0x00000024
#define AVR32_EVBA_OFFSET_UNRECOVERABLE                0x00000000
#define AVR32_RESET_VECTOR                             0x80000000



#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_sr_t {
    unsigned int                 : 4;
    unsigned int dm              : 1;
    unsigned int d               : 1;
    unsigned int                 : 1;
    unsigned int m2              : 1;
    unsigned int m1              : 1;
    unsigned int m0              : 1;
    unsigned int em              : 1;
    unsigned int i3m             : 1;
    unsigned int i2m             : 1;
    unsigned int i1m             : 1;
    unsigned int i0m             : 1;
    unsigned int gm              : 1;
    unsigned int                 : 1;
    unsigned int t               : 1;
    unsigned int                 : 8;
    unsigned int l               : 1;
    unsigned int q               : 1;
    unsigned int v               : 1;
    unsigned int n               : 1;
    unsigned int z               : 1;
    unsigned int c               : 1;
} avr32_sr_t;



typedef struct avr32_cpucr_t {
    unsigned int                 :15;
    unsigned int locen           : 1;
    unsigned int spl             : 5;
    unsigned int cpl             : 5;
    unsigned int cop             : 5;
    unsigned int sie             : 1;
} avr32_cpucr_t;



typedef struct avr32_config0_t {
    unsigned int processorid     : 8;
    unsigned int                 : 4;
    unsigned int processorrevision : 4;
    unsigned int at              : 3;
    unsigned int ar              : 3;
    unsigned int mmut            : 3;
    unsigned int f               : 1;
    unsigned int j               : 1;
    unsigned int p               : 1;
    unsigned int o               : 1;
    unsigned int s               : 1;
    unsigned int d               : 1;
    unsigned int r               : 1;
} avr32_config0_t;



typedef struct avr32_config1_t {
    unsigned int immusz          : 6;
    unsigned int dmmusz          : 6;
    unsigned int iset            : 4;
    unsigned int ilsz            : 3;
    unsigned int iass            : 3;
    unsigned int dset            : 4;
    unsigned int dlsz            : 3;
    unsigned int dass            : 3;
} avr32_config1_t;



typedef struct avr32_mpuar0_t {
    unsigned int base            :20;
    unsigned int                 : 6;
    unsigned int size            : 5;
    unsigned int v               : 1;
} avr32_mpuar0_t;



typedef struct avr32_mpuar1_t {
    unsigned int base            :20;
    unsigned int                 : 6;
    unsigned int size            : 5;
    unsigned int v               : 1;
} avr32_mpuar1_t;



typedef struct avr32_mpuar2_t {
    unsigned int base            :20;
    unsigned int                 : 6;
    unsigned int size            : 5;
    unsigned int v               : 1;
} avr32_mpuar2_t;



typedef struct avr32_mpuar3_t {
    unsigned int base            :20;
    unsigned int                 : 6;
    unsigned int size            : 5;
    unsigned int v               : 1;
} avr32_mpuar3_t;



typedef struct avr32_mpuar4_t {
    unsigned int base            :20;
    unsigned int                 : 6;
    unsigned int size            : 5;
    unsigned int v               : 1;
} avr32_mpuar4_t;



typedef struct avr32_mpuar5_t {
    unsigned int base            :20;
    unsigned int                 : 6;
    unsigned int size            : 5;
    unsigned int v               : 1;
} avr32_mpuar5_t;



typedef struct avr32_mpuar6_t {
    unsigned int base            :20;
    unsigned int                 : 6;
    unsigned int size            : 5;
    unsigned int v               : 1;
} avr32_mpuar6_t;



typedef struct avr32_mpuar7_t {
    unsigned int base            :20;
    unsigned int                 : 6;
    unsigned int size            : 5;
    unsigned int v               : 1;
} avr32_mpuar7_t;



typedef struct avr32_mpupsr0_t {
    unsigned int                 :16;
    unsigned int p15             : 1;
    unsigned int p14             : 1;
    unsigned int p13             : 1;
    unsigned int p12             : 1;
    unsigned int p11             : 1;
    unsigned int p10             : 1;
    unsigned int p9              : 1;
    unsigned int p8              : 1;
    unsigned int p7              : 1;
    unsigned int p6              : 1;
    unsigned int p5              : 1;
    unsigned int p4              : 1;
    unsigned int p3              : 1;
    unsigned int p2              : 1;
    unsigned int p1              : 1;
    unsigned int p0              : 1;
} avr32_mpupsr0_t;



typedef struct avr32_mpupsr1_t {
    unsigned int                 :16;
    unsigned int p15             : 1;
    unsigned int p14             : 1;
    unsigned int p13             : 1;
    unsigned int p12             : 1;
    unsigned int p11             : 1;
    unsigned int p10             : 1;
    unsigned int p9              : 1;
    unsigned int p8              : 1;
    unsigned int p7              : 1;
    unsigned int p6              : 1;
    unsigned int p5              : 1;
    unsigned int p4              : 1;
    unsigned int p3              : 1;
    unsigned int p2              : 1;
    unsigned int p1              : 1;
    unsigned int p0              : 1;
} avr32_mpupsr1_t;



typedef struct avr32_mpupsr2_t {
    unsigned int                 :16;
    unsigned int p15             : 1;
    unsigned int p14             : 1;
    unsigned int p13             : 1;
    unsigned int p12             : 1;
    unsigned int p11             : 1;
    unsigned int p10             : 1;
    unsigned int p9              : 1;
    unsigned int p8              : 1;
    unsigned int p7              : 1;
    unsigned int p6              : 1;
    unsigned int p5              : 1;
    unsigned int p4              : 1;
    unsigned int p3              : 1;
    unsigned int p2              : 1;
    unsigned int p1              : 1;
    unsigned int p0              : 1;
} avr32_mpupsr2_t;



typedef struct avr32_mpupsr3_t {
    unsigned int                 :16;
    unsigned int p15             : 1;
    unsigned int p14             : 1;
    unsigned int p13             : 1;
    unsigned int p12             : 1;
    unsigned int p11             : 1;
    unsigned int p10             : 1;
    unsigned int p9              : 1;
    unsigned int p8              : 1;
    unsigned int p7              : 1;
    unsigned int p6              : 1;
    unsigned int p5              : 1;
    unsigned int p4              : 1;
    unsigned int p3              : 1;
    unsigned int p2              : 1;
    unsigned int p1              : 1;
    unsigned int p0              : 1;
} avr32_mpupsr3_t;



typedef struct avr32_mpupsr4_t {
    unsigned int                 :16;
    unsigned int p15             : 1;
    unsigned int p14             : 1;
    unsigned int p13             : 1;
    unsigned int p12             : 1;
    unsigned int p11             : 1;
    unsigned int p10             : 1;
    unsigned int p9              : 1;
    unsigned int p8              : 1;
    unsigned int p7              : 1;
    unsigned int p6              : 1;
    unsigned int p5              : 1;
    unsigned int p4              : 1;
    unsigned int p3              : 1;
    unsigned int p2              : 1;
    unsigned int p1              : 1;
    unsigned int p0              : 1;
} avr32_mpupsr4_t;



typedef struct avr32_mpupsr5_t {
    unsigned int                 :16;
    unsigned int p15             : 1;
    unsigned int p14             : 1;
    unsigned int p13             : 1;
    unsigned int p12             : 1;
    unsigned int p11             : 1;
    unsigned int p10             : 1;
    unsigned int p9              : 1;
    unsigned int p8              : 1;
    unsigned int p7              : 1;
    unsigned int p6              : 1;
    unsigned int p5              : 1;
    unsigned int p4              : 1;
    unsigned int p3              : 1;
    unsigned int p2              : 1;
    unsigned int p1              : 1;
    unsigned int p0              : 1;
} avr32_mpupsr5_t;



typedef struct avr32_mpupsr6_t {
    unsigned int                 :16;
    unsigned int p15             : 1;
    unsigned int p14             : 1;
    unsigned int p13             : 1;
    unsigned int p12             : 1;
    unsigned int p11             : 1;
    unsigned int p10             : 1;
    unsigned int p9              : 1;
    unsigned int p8              : 1;
    unsigned int p7              : 1;
    unsigned int p6              : 1;
    unsigned int p5              : 1;
    unsigned int p4              : 1;
    unsigned int p3              : 1;
    unsigned int p2              : 1;
    unsigned int p1              : 1;
    unsigned int p0              : 1;
} avr32_mpupsr6_t;



typedef struct avr32_mpupsr7_t {
    unsigned int                 :16;
    unsigned int p15             : 1;
    unsigned int p14             : 1;
    unsigned int p13             : 1;
    unsigned int p12             : 1;
    unsigned int p11             : 1;
    unsigned int p10             : 1;
    unsigned int p9              : 1;
    unsigned int p8              : 1;
    unsigned int p7              : 1;
    unsigned int p6              : 1;
    unsigned int p5              : 1;
    unsigned int p4              : 1;
    unsigned int p3              : 1;
    unsigned int p2              : 1;
    unsigned int p1              : 1;
    unsigned int p0              : 1;
} avr32_mpupsr7_t;



typedef struct avr32_mpucra_t {
    unsigned int                 :24;
    unsigned int c7              : 1;
    unsigned int c6              : 1;
    unsigned int c5              : 1;
    unsigned int c4              : 1;
    unsigned int c3              : 1;
    unsigned int c2              : 1;
    unsigned int c1              : 1;
    unsigned int c0              : 1;
} avr32_mpucra_t;



typedef struct avr32_mpucrb_t {
    unsigned int                 :24;
    unsigned int c7              : 1;
    unsigned int c6              : 1;
    unsigned int c5              : 1;
    unsigned int c4              : 1;
    unsigned int c3              : 1;
    unsigned int c2              : 1;
    unsigned int c1              : 1;
    unsigned int c0              : 1;
} avr32_mpucrb_t;



typedef struct avr32_mpubra_t {
    unsigned int                 :24;
    unsigned int b7              : 1;
    unsigned int b6              : 1;
    unsigned int b5              : 1;
    unsigned int b4              : 1;
    unsigned int b3              : 1;
    unsigned int b2              : 1;
    unsigned int b1              : 1;
    unsigned int b0              : 1;
} avr32_mpubra_t;



typedef struct avr32_mpubrb_t {
    unsigned int                 :24;
    unsigned int b7              : 1;
    unsigned int b6              : 1;
    unsigned int b5              : 1;
    unsigned int b4              : 1;
    unsigned int b3              : 1;
    unsigned int b2              : 1;
    unsigned int b1              : 1;
    unsigned int b0              : 1;
} avr32_mpubrb_t;



typedef struct avr32_mpuapra_t {
    unsigned int ap7             : 4;
    unsigned int ap6             : 4;
    unsigned int ap5             : 4;
    unsigned int ap4             : 4;
    unsigned int ap3             : 4;
    unsigned int ap2             : 4;
    unsigned int ap1             : 4;
    unsigned int ap0             : 4;
} avr32_mpuapra_t;



typedef struct avr32_mpuaprb_t {
    unsigned int ap7             : 4;
    unsigned int ap6             : 4;
    unsigned int ap5             : 4;
    unsigned int ap4             : 4;
    unsigned int ap3             : 4;
    unsigned int ap2             : 4;
    unsigned int ap1             : 4;
    unsigned int ap0             : 4;
} avr32_mpuaprb_t;



typedef struct avr32_mpucr_t {
    unsigned int                 :31;
    unsigned int e               : 1;
} avr32_mpucr_t;




/*#ifdef __AVR32_ABI_COMPILER__*/
#endif


#if !defined (DEPRECATED_DISABLE)

#define AVR32_MPUAPRA_AP0_EXECUTE                      0x00000001
#define AVR32_MPUAPRA_AP0_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRA_AP0_USER                         0x00000004
#define AVR32_MPUAPRA_AP0_WRITE                        0x00000002

#define AVR32_MPUAPRA_AP1_EXECUTE                      0x00000001
#define AVR32_MPUAPRA_AP1_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRA_AP1_USER                         0x00000004
#define AVR32_MPUAPRA_AP1_WRITE                        0x00000002

#define AVR32_MPUAPRA_AP2_EXECUTE                      0x00000001
#define AVR32_MPUAPRA_AP2_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRA_AP2_USER                         0x00000004
#define AVR32_MPUAPRA_AP2_WRITE                        0x00000002

#define AVR32_MPUAPRA_AP3_EXECUTE                      0x00000001
#define AVR32_MPUAPRA_AP3_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRA_AP3_USER                         0x00000004
#define AVR32_MPUAPRA_AP3_WRITE                        0x00000002

#define AVR32_MPUAPRA_AP4_EXECUTE                      0x00000001
#define AVR32_MPUAPRA_AP4_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRA_AP4_USER                         0x00000004
#define AVR32_MPUAPRA_AP4_WRITE                        0x00000002

#define AVR32_MPUAPRA_AP5_EXECUTE                      0x00000001
#define AVR32_MPUAPRA_AP5_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRA_AP5_USER                         0x00000004
#define AVR32_MPUAPRA_AP5_WRITE                        0x00000002

#define AVR32_MPUAPRA_AP6_EXECUTE                      0x00000001
#define AVR32_MPUAPRA_AP6_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRA_AP6_USER                         0x00000004
#define AVR32_MPUAPRA_AP6_WRITE                        0x00000002

#define AVR32_MPUAPRA_AP7_EXECUTE                      0x00000001
#define AVR32_MPUAPRA_AP7_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRA_AP7_USER                         0x00000004
#define AVR32_MPUAPRA_AP7_WRITE                        0x00000002

#define AVR32_MPUAPRB_AP0_EXECUTE                      0x00000001
#define AVR32_MPUAPRB_AP0_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRB_AP0_USER                         0x00000004
#define AVR32_MPUAPRB_AP0_WRITE                        0x00000002

#define AVR32_MPUAPRB_AP1_EXECUTE                      0x00000001
#define AVR32_MPUAPRB_AP1_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRB_AP1_USER                         0x00000004
#define AVR32_MPUAPRB_AP1_WRITE                        0x00000002

#define AVR32_MPUAPRB_AP2_EXECUTE                      0x00000001
#define AVR32_MPUAPRB_AP2_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRB_AP2_USER                         0x00000004
#define AVR32_MPUAPRB_AP2_WRITE                        0x00000002

#define AVR32_MPUAPRB_AP3_EXECUTE                      0x00000001
#define AVR32_MPUAPRB_AP3_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRB_AP3_USER                         0x00000004
#define AVR32_MPUAPRB_AP3_WRITE                        0x00000002

#define AVR32_MPUAPRB_AP4_EXECUTE                      0x00000001
#define AVR32_MPUAPRB_AP4_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRB_AP4_USER                         0x00000004
#define AVR32_MPUAPRB_AP4_WRITE                        0x00000002

#define AVR32_MPUAPRB_AP5_EXECUTE                      0x00000001
#define AVR32_MPUAPRB_AP5_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRB_AP5_USER                         0x00000004
#define AVR32_MPUAPRB_AP5_WRITE                        0x00000002

#define AVR32_MPUAPRB_AP6_EXECUTE                      0x00000001
#define AVR32_MPUAPRB_AP6_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRB_AP6_USER                         0x00000004
#define AVR32_MPUAPRB_AP6_WRITE                        0x00000002

#define AVR32_MPUAPRB_AP7_EXECUTE                      0x00000001
#define AVR32_MPUAPRB_AP7_SUP_WRITE                    0x00000008
#define AVR32_MPUAPRB_AP7_USER                         0x00000004
#define AVR32_MPUAPRB_AP7_WRITE                        0x00000002


#endif


/*#ifdef AVR32_CORE_SC0_130_H_INCLUDED*/
#endif

