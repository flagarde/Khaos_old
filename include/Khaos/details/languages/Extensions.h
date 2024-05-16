/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

#ifndef KHAOS_EXTENSIONS_H_
#define KHAOS_EXTENSIONS_H_

#if defined(__STRICT_ANSI__) || defined(__ANSI__) || defined(NO_EXT_KEYS)
  #define KHAOS_LANGUAGE_ISO_PRIVATE()        (1L) /*!< 1 if strict ISO, 0 otherwise */
  #define KHAOS_LANGUAGE_Extensions_PRIVATE() (0L) /*!< 0 if strict ISO, 1 otherwise */
#else
  #define KHAOS_LANGUAGE_ISO_PRIVATE()        (0L) /*!< 1 if strict ISO, 0 otherwise */
  #define KHAOS_LANGUAGE_Extensions_PRIVATE() (1L) /*!< 0 if strict ISO, 1 otherwise */
#endif

#endif /* KHAOS_EXTENSIONS_H_ */
