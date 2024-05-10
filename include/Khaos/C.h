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

#include "Khaos/CStandards.h"

#if defined(__STDC__)
  #if defined(__STDC_VERSION__)
    #define KHAOS_C_STANDARD_PRIVATE() (__STDC_VERSION__) /*!< defined as __STDC_VERSION__ */
  #else
    #define KHAOS_C_STANDARD_PRIVATE() KHAOS_STANDARD_C90_PRIVATE() /*!< defined as C90 */
  #endif
#else
  /*
   * For GCC this should never happen https://gcc.gnu.org/onlinedocs/cpp/Traditional-Mode.html#Traditional-Mode
  */
  #if defined(_MSC_VER)
    /*
    * The compiler uses C compilation mode by default when a source file has a .c extension, or when the /Tc or /TC option is specified.
    * The C compiler is an C89/C90 compiler that, by default, enables Microsoft extensions to the C language. For more information about specific extensions, see Microsoft Extensions to C and C++.
    * When both C compilation and the /Za option are specified, the C compiler conforms strictly to the C89/C90 standard.
    * The compiler treats Microsoft extended keywords as simple identifiers, disables the other Microsoft extensions, and automatically defines the __STDC__ predefined macro for C programs.
    */
    #if defined(__STDC_VERSION__)
      #define KHAOS_C_STANDARD_PRIVATE() (__STDC_VERSION__) /*!< defined as __STDC_VERSION__ */
    #else
      #define KHAOS_C_STANDARD_PRIVATE() KHAOS_STANDARD_C90_PRIVATE() /*!< defined as C90 */
    #endif
  #endif
#endif

#if defined(__STRICT_ANSI__)
  #define KHAOS_LANGUAGE_ISO_PRIVATE()        (1L) /*!< 1 if strict ISO, 0 otherwise */
  #define KHAOS_LANGUAGE_Extensions_PRIVATE() (0L) /*!< 0 if strict ISO, 1 otherwise */
#else
  #define KHAOS_LANGUAGE_ISO_PRIVATE()        (0L) /*!< 1 if strict ISO, 0 otherwise */
  #define KHAOS_LANGUAGE_Extensions_PRIVATE() (1L) /*!< 0 if strict ISO, 1 otherwise */
#endif

#endif /* KHAOS_C_H_ */
