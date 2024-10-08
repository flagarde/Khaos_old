/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

#ifndef KHAOS_VERSION_H_
#define KHAOS_VERSION_H_

/*!
* \file Version.h
* \brief Define macros to set, get versions.
* \note Use these macros only if you need preprocessor version checking.
* \note For example :
* \code{.cpp}
* #if GET_VERSION_MAJOR(version1) == GET_VERSION_MAJOR(version2)
* ...
* #else
* ...
* #endif
* \endcode
*/

#if defined(__clang__)
  #define KHAOS_PUSH_CXX98_COMPAT_PEDANTIC() _Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored \"-Wc++98-compat-pedantic\"") /* //NOSONAR */
  #define KHAOS_POP_CXX98_COMPAT_PEDANTIC()  _Pragma("clang diagnostic pop")                                                                  /* //NOSONAR */
#else
  #define KHAOS_PUSH_CXX98_COMPAT_PEDANTIC() /* //NOSONAR */
  #define KHAOS_POP_CXX98_COMPAT_PEDANTIC()  /* //NOSONAR */
#endif

/*!
* \hideinitializer
* \brief Set standard version numbers.
* \param[in] major The major number can be in the [0,65535] range.
* \param[in] minor The minor number can be in the [0,65535] range.
* \param[in] patch The patch number can be in the [0,65535] range.
* \param[in] tweak The tweak number can be in the [0,65535] range.
*
* \remarks The number range is designed to allow for a (16,16,16,16) quadruplet; Which fits within a 64 bit value.
*
* \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
* \note Values can be specified in any base. As the defined value is an constant expression.
* \note The implementation enforces the individual ranges for the major, minor, and patch numbers.
* \warning Values over the ranges are truncated (modulo).
* \warning The name of the macro must be of the form KHAOS_DEFINE_name_VERSION_PRIVATE() to be able to be parsed by the Khaos library.
* \code{.cpp}
* #define KHAOS_DEFINE_name_VERSION_PRIVATE() SET_VERSION(2,3,4,5)
* \endcode
*/
#define SET_VERSION(major, minor, patch, tweak)                                                                                                                                                                           /* //NOSONAR */ \
  (KHAOS_PUSH_CXX98_COMPAT_PEDANTIC()(((major) * 1ULL % (1 << 16)) << 48) + (((minor) * 1ULL % (1 << 16)) << 32) + (((patch) * 1ULL % (1 << 16)) << 16) + ((tweak) * 1ULL % (1 << 16)) KHAOS_POP_CXX98_COMPAT_PEDANTIC()) /* //NOSONAR */

/*!
* \hideinitializer
* \brief Get the major version numbers.
* \param[in] name The name for which to return the corresponding major version number.
*
* \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
*/
#define GET_VERSION_MAJOR(name) (KHAOS_PUSH_CXX98_COMPAT_PEDANTIC()((KHAOS_DEFINE_##name##_VERSION_PRIVATE()) >> 48) % (1 << 16) KHAOS_POP_CXX98_COMPAT_PEDANTIC()) /* //NOSONAR */

/*!
* \hideinitializer
* \brief Get the minor version numbers.
* \param[in] name The name for which to return the corresponding minor version number.
*
* \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
*/
#define GET_VERSION_MINOR(name) (KHAOS_PUSH_CXX98_COMPAT_PEDANTIC()((KHAOS_DEFINE_##name##_VERSION_PRIVATE()) >> 32) % (1 << 16) KHAOS_POP_CXX98_COMPAT_PEDANTIC()) /* //NOSONAR */

/*!
* \hideinitializer
* \brief Get the patch version numbers.
* \param[in]name The name for which to return the corresponding patch version number.
*
* \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
*/
#define GET_VERSION_PATCH(name) (KHAOS_PUSH_CXX98_COMPAT_PEDANTIC()((KHAOS_DEFINE_##name##_VERSION_PRIVATE()) >> 16) % (1 << 16) KHAOS_POP_CXX98_COMPAT_PEDANTIC()) /* //NOSONAR */

/*!
* \hideinitializer
* \brief Get the tweak version numbers.
* \param[in] name The name for which to return the corresponding tweak version number.
*
* \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
*/
#define GET_VERSION_TWEAK(name) (KHAOS_PUSH_CXX98_COMPAT_PEDANTIC()(KHAOS_DEFINE_##name##_VERSION_PRIVATE()) % (1 << 16) KHAOS_POP_CXX98_COMPAT_PEDANTIC()) /* //NOSONAR */

#endif /* KHAOS_VERSION_H_ */
