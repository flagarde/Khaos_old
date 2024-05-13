/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

#ifndef KHAOS_COMPARE_VERSIONS_H_
#define KHAOS_COMPARE_VERSIONS_H_

#include "Khaos/Version.h"

/** \file CompareVersion.h
*  \brief Define macros to compare versions.
*  \note Use these macros only if you need preprocessor version checking.
*  \note For example :
*  \code{.cpp}
*  #if CHECK_VERSIONS(version1,==,version2)
*  ...
*  #else
*  ...
*  #endif
*  \endcode
*/

/** \hideinitializer
*  \brief Check the \b version with \b major, \b minor, \b patch, \b tweak using the operator \b op
*  \param[in] version version to compare.
*  \param[in] op operator =, !=, >=, <= >, < .
*  \param[in] major major part.
*  \param[in] minor minor part.
*  \param[in] patch patch part.
*  \param[in] tweak tweak part.
*
*  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
*/
#define CHECK_VERSION(version, op, major, minor, patch, tweak) ((KHAOS_DEFINE_##version##_VERSION_PRIVATE())op(SET_VERSION(major, minor, patch, tweak)))

/** \hideinitializer
*  \brief Check the \b versiona with \b versionb using the operator \b op
*  \param[in] versiona version to compare.
*  \param[in] op operator =, !=, >=, <= >, < .
*  \param[in] versionb version to compare.
*
*  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
*/

#define CHECK_VERSIONS(a, op, b) ((KHAOS_DEFINE_##a##_VERSION_PRIVATE())op(KHAOS_DEFINE_##b##_VERSION_PRIVATE()))

#endif /* KHAOS_COMPARE_VERSIONS_H_ */
