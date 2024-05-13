/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

#ifndef KHAOS_C_H_
#define KHAOS_C_H_

/** \file C.h
*  \brief Detect the C standard and define some useful macros.
*/

#include "Khaos/details/languages/CStandards.h"

#if defined(__STDC_VERSION__)
  #define KHAOS_C_STANDARD_PRIVATE() (__STDC_VERSION__) /* //NOSONAR */ /*!< defined as __STDC_VERSION__ */
#else
  #define KHAOS_C_STANDARD_PRIVATE() KHAOS_STANDARD_C90_PRIVATE() /* //NOSONAR */ /*!< defined as C90 */
#endif

/*
  The compiler uses C compilation mode by default when a source file has a .c extension, or when the /Tc or /TC option is specified.
  The C compiler is an C89/C90 compiler that, by default, enables Microsoft extensions to the C language.
  For more information about specific extensions, see Microsoft Extensions to C and C++.
  When both C compilation and the /Za option are specified, the C compiler conforms strictly to the C89/C90 standard.
  The compiler treats Microsoft extended keywords as simple identifiers, disables the other Microsoft extensions, and automatically defines the __STDC__ predefined macro for C programs.

  The default C compiler (that is, the compiler when /std:c11 or /std:c17 isn't specified) implements ANSI C89, but includes several Microsoft extensions, some of which are part of ISO C99.
  Some Microsoft extensions to C89 can be disabled by using the /Za compiler option, but others remain in effect. It isn't possible to specify strict C89 conformance.
  The compiler doesn't implement several required features of C99, so it isn't possible to specify C99 conformance, either.
  The /std:c11 option enables ISO C11 conformance. It's available starting in Visual Studio 2019 version 16.8.
  The /std:c17 option enables ISO C17 conformance. It's available starting in Visual Studio 2019 version 16.8.
  Because the new preprocessor is needed to support these standards, the /std:c11 and /std:c17 compiler options set the /Zc:preprocessor option automatically.
  If you want to use the traditional (legacy) preprocessor for C11 or C17, you must set the /Zc:preprocessor- compiler option explicitly.
  Setting the /Zc:preprocessor- option may lead to unexpected behavior, and isn't recommended.
*/

#if defined(__STRICT_ANSI__) || (defined(_MSC_VER) && (defined(__STDC__) || defined(__STDC_VERSION__)))
  #define KHAOS_LANGUAGE_ISO_PRIVATE()        (1L) /* //NOSONAR */ /*!< 1 if strict ISO, 0 otherwise */
  #define KHAOS_LANGUAGE_Extensions_PRIVATE() (0L) /* //NOSONAR */ /*!< 0 if strict ISO, 1 otherwise */
#else
  #define KHAOS_LANGUAGE_ISO_PRIVATE()        (0L) /* //NOSONAR */ /*!< 1 if strict ISO, 0 otherwise */
  #define KHAOS_LANGUAGE_Extensions_PRIVATE() (1L) /* //NOSONAR */ /*!< 0 if strict ISO, 1 otherwise */
#endif

#endif /* KHAOS_C_H_ */
