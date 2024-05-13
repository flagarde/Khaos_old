/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

#ifndef KHAOS_PREPROCESSOR_H_
#define KHAOS_PREPROCESSOR_H_

/*! \file Preprocessor.h
*  \brief Detect some preprocessor behaviors.
*/

/*!
* \hideinitializer
* Check if the preprocessor is in traditional mode.
*/
#if(defined(_MSVC_TRADITIONAL) && (_MSVC_TRADITIONAL == 1)) || (!defined(_MSVC_TRADITIONAL) && defined(_MSC_VER))
  #define KHAOS_PREPROCESSOR_Traditional_PRIVATE() (1L)
#else
  #define KHAOS_PREPROCESSOR_Traditional_PRIVATE() (0L)
#endif

/*!
* \hideinitializer
* Return the processor checked value.
*/
#define PREPROCESSOR_IS(check) KHAOS_PREPROCESSOR_##check##_PRIVATE()

#endif /* KHAOS_PROCESSOR_H_ */
