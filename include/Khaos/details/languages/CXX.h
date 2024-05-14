/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

#ifndef KHAOS_CXX_H_
#define KHAOS_CXX_H_

/*!
* \file CXX.h
* \brief Detect the C++ standard and define some useful macros.
* \warning \b CXX11 is always false for \b MSVC only c++14 and upper are considered.
*/

#include "Khaos/details/languages/CXXStandards.h"

#if defined(_MSC_VER)
  /*!
  * https://devblogs.microsoft.com/cppblog/msvc-now-correctly-reports-__cplusplus/
  *
  * Starting from Visual Studio 2017 version 15.7 the option /Zc:__cplusplus.
  *
  * Try to warn the user to do this !
  *
  */
  #if defined(_MSVC_LANG)
    #define KHAOS_CXX_STANDARD_PRIVATE() (_MSVC_LANG) /* //NOSONAR !< defined as _MSVC_LANG */
  #else
    #define KHAOS_CXX_STANDARD_PRIVATE() (__cplusplus) /* //NOSONAR !< defined as __cplusplus */
  #endif
#else
  #define KHAOS_CXX_STANDARD_PRIVATE() (__cplusplus) /* //NOSONAR !< defined as __cplusplus */
#endif

#if defined(__STRICT_ANSI__) || defined(__ANSI__) || defined(NO_EXT_KEYS)
  #define KHAOS_LANGUAGE_ISO_PRIVATE()        (1L) /* //NOSONAR !< 1 if strict ISO, 0 otherwise */
  #define KHAOS_LANGUAGE_Extensions_PRIVATE() (0L) /* //NOSONAR !< 0 if strict ISO, 1 otherwise */
#else
  #define KHAOS_LANGUAGE_ISO_PRIVATE()        (0L) /* //NOSONAR !< 1 if strict ISO, 0 otherwise */
  #define KHAOS_LANGUAGE_Extensions_PRIVATE() (1L) /* //NOSONAR !< 0 if strict ISO, 1 otherwise */
#endif

#endif /* KHAOS_CXX_H_ */
