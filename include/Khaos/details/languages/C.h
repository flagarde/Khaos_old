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

/*!
* \file C.h
* \brief Detect the C standard and define some useful macros.
*/

#include "Khaos/details/languages/CStandards.h"
#include "Khaos/details/languages/Extensions.h"

#if defined(__STDC_VERSION__)
  #define KHAOS_C_STANDARD_PRIVATE() (__STDC_VERSION__) /*!< defined as __STDC_VERSION__ */
#else
  #define KHAOS_C_STANDARD_PRIVATE() KHAOS_STANDARD_C90_PRIVATE() /*!< defined as C90 */
#endif

#endif /* KHAOS_C_H_ */
