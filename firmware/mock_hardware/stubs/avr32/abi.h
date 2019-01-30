/*****************************************************************************
 *
 * Copyright (C) 2008 Atmel Corporation
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
 * Revision     : $Revision: 62595 $
 * Checkin Date : $Date: 2009-10-21 13:31:31 +0200 (Wed, 21 Oct 2009) $
 *
 ****************************************************************************/
#ifndef AVR32_ABI_H_INCLUDED
#define AVR32_ABI_H_INCLUDED


/* The GNU assembler is ABI compliant*/
#ifndef __AVR32_ABI_ASSEMBLER__
# ifdef __GNUC__
#  ifdef __ASSEMBLER__
#   define __AVR32_ABI_ASSEMBLER__
#  endif
# endif
#endif

/* The GNU C/C++ compiler is ABI compliant */
#ifndef __AVR32_ABI_COMPILER__
# ifdef __GNUC__
#  ifndef __ASSEMBLER__
#   define __AVR32_ABI_COMPILER__
#  endif
# endif
#endif


/* The IAR Systems C/C++ Compiler is ABI compliant */
#ifndef __AVR32_ABI_COMPILER__
# ifdef __ICCAVR32__
#  define __AVR32_ABI_COMPILER__
# endif
#endif

/* The IAR Systems Assembler is ABI compliant */
#ifndef __AVR32_ABI_ASSEMBLER__
# ifdef __AAVR32__
#  define __AVR32_ABI_ASSEMBLER__
# endif
#endif



/*#ifndef AVR32_ABI_H_INCLUDED*/
#endif

