/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2025 Electronic Arts Inc.
 * Copyright 2026 OpenTS contributors
 *
 * Contains material derived from Electronic Arts source code.
 * Modified by OpenTS contributors, 2026.
 * EA's GPLv3 Section 7 additional terms and supplemental warranty
 * disclaimers apply; see LICENSE.md.
 ******************************************************************************/

#pragma once

#if defined(_WIN32) && !defined(__MINGW32__)

#include <sal.h>

#else

// SAL annotations are only needed by the MSVC analysis toolchain. MinGW's sal.h does not
// provide the same annotation surface, and Clang/GNU calling-convention support does not
// require them for these declarations.
#ifndef _Printf_format_string_
#define _Printf_format_string_
#endif
#ifndef __cdecl
#define __cdecl
#endif

#endif

void Debug_Init(void);
void Debug_Init_Console(void);
void Debug_Console_Hold(void);
char const * Debug_Log_File_Name(void);
char const * Debug_Directory(void);
bool Delete_Files_Older_Than(char const * directory, char const * pattern, unsigned days);

void __cdecl DebugString(_Printf_format_string_ char const * string, ...);
void __cdecl DebugStringNoPrefix(_Printf_format_string_ char const * string, ...);

char const * Last_Error_Text(unsigned long error);
