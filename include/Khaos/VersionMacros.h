/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

#ifndef KHAOS_VERSIONMACROS_H_
#define KHAOS_VERSIONMACROS_H_

/** \file VersionMacros.h
 *  \brief Define macros to set, get versions.
 *  \note Use these macros only if you need preprocessor version checking.
 *  \note For example :
 *  \code{.cpp}
 *  #if GET_VERSION_MAJOR(version1) == GET_VERSION_MAJOR(version2)
 *  ...
 *  #else
 *  ...
 *  #endif
 *  \endcode
 */

/** \hideinitializer
 *  \brief Set standard version numbers.
 *  \param[in] major The major number can be in the [0,65535] range.
 *  \param[in] minor The minor number can be in the [0,65535] range.
 *  \param[in] patch The patch number can be in the [0,65535] range.
 *  \param[in] tweak The tweak number can be in the [0,65535] range.
 *
 *  \remarks The number range is designed to allow for a (16,16,16,16) quadruplet; Which fits within a 64 bit value.
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 *  \note Values can be specified in any base. As the defined value is an constant expression.
 *  \note The implementation enforces the individual ranges for the major, minor, and patch numbers.
 *  \warning Values over the ranges are truncated (modulo).
 *  \warning The name of the macro must be of the form KHAOS_VERSION_name_PRIVATE() to be able to be parsed by the Khaos library.
 *  \code{.cpp}
 *  #define KHAOS_VERSION_myversion_PRIVATE() SET_VERSION(2,3,4,5)
 *  \endcode
 */
#define SET_VERSION(major, minor, patch, tweak) ((((major)*1ULL % 65536) << 48) + (((minor)*1ULL % 65536) << 32) + (((patch)*1ULL % 65536) << 16) + ((tweak)*1ULL % 65536))

/** \hideinitializer
 *  \brief Get standard major version numbers.
 *  \param[in] version The standard version number.
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define GET_VERSION_MAJOR(version) ((((KHAOS_VERSION_##version##_PRIVATE()) * 1ULL) >> 48) % 65536) /* //NOSONAR */

/** \hideinitializer
 *  \brief Get standard minor version numbers.
 *  \param[in] version The standard version number.
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define GET_VERSION_MINOR(version) ((((KHAOS_VERSION_##version##_PRIVATE()) * 1ULL) >> 32) % 65536) /* //NOSONAR */

/** \hideinitializer
 *  \brief Get standard patch version numbers.
 *  \param[in] version The standard version number.
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define GET_VERSION_PATCH(version) ((((KHAOS_VERSION_##version##_PRIVATE()) * 1ULL) >> 16) % 65536) /* //NOSONAR */

/** \hideinitializer
 *  \brief Get standard tweak version numbers.
 *  \param[in] version The standard version number.
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define GET_VERSION_TWEAK(version) (((KHAOS_VERSION_##version##_PRIVATE()) * 1ULL) % 65536) /* //NOSONAR */

#endif /* KHAOS_VERSIONMACROS_H_ */
