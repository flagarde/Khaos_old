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
#include "Khaos/details/languages/Extensions.h"

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
    #define KHAOS_CXX_STANDARD_PRIVATE() (_MSVC_LANG) /*!< defined as _MSVC_LANG */
  #else
    #define KHAOS_CXX_STANDARD_PRIVATE() (__cplusplus) /*!< defined as __cplusplus */
  #endif
#else
  #define KHAOS_CXX_STANDARD_PRIVATE() (__cplusplus) /*!< defined as __cplusplus */
#endif

#endif /* KHAOS_CXX_H_ */
