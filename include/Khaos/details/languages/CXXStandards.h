/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

#ifndef KHAOS_CXX_STANDARDS_H_
#define KHAOS_CXX_STANDARDS_H_

/*!
* \file CXXStandards.h
* \brief Define the version of the C++ standard.
* Define macros that expand to the integer constant of type \b long whose value are the version of the C++ standard.
* Official values for the \b __cplusplus macro.
*/

#define KHAOS_STANDARD_CXX98_PRIVATE() (199711L) /* //NOSONAR !< Value for the C++97 standard */
#define KHAOS_STANDARD_CXX11_PRIVATE() (201103L) /* //NOSONAR !< Value for the C++11 standard */
#define KHAOS_STANDARD_CXX14_PRIVATE() (201402L) /* //NOSONAR !< Value for the C++14 standard */
#define KHAOS_STANDARD_CXX17_PRIVATE() (201703L) /* //NOSONAR !< Value for the C++17 standard */
#define KHAOS_STANDARD_CXX20_PRIVATE() (202002L) /* //NOSONAR !< Value for the C++20 standard */
#define KHAOS_STANDARD_CXX23_PRIVATE() (202302L) /* //NOSONAR !< Value for the C++23 standard */

#endif /* KHAOS_CXX_STANDARDS_H_ */
