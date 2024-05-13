/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

#ifndef KHAOS_C_STANDARDS_H_
#define KHAOS_C_STANDARDS_H_

/*! \file CStandards.h
*  \brief Define the values of the official C standard.
*   Define macros that expand to the integer constant of type \b long whose value are the version of the C standard.
*   Official values for the \b __STDC_VERSION__ macro.
*/

#define KHAOS_STANDARD_C90_PRIVATE() (1L)      /*!< Value for the C90 standard (no value defined by the standard) */
#define KHAOS_STANDARD_C95_PRIVATE() (199409L) /*!< Value for the C95 standard */
#define KHAOS_STANDARD_C99_PRIVATE() (199901L) /*!< Value for the C99 standard */
#define KHAOS_STANDARD_C11_PRIVATE() (201112L) /*!< Value for the C11 standard */
#define KHAOS_STANDARD_C17_PRIVATE() (201710L) /*!< Value for the C17 standard */
#define KHAOS_STANDARD_C23_PRIVATE() (202311L) /*!< Value for the C23 standard */

#endif /* KHAOS_C_STANDARDS_H_ */
