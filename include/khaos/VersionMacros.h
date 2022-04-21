#ifndef KHAOS_VERSIONMACROS_H_
#define KHAOS_VERSIONMACROS_H_

#include "khaos/CompareVersionMacros.h"
#include "khaos/KhaosVersion.h"

/** \file VersionMacros.h
 *  \copyright 2022 flagarde
 *  \brief Define macros to set, get versions.
 *  \note Use these macros only if you need preprocessor version checking.
 *  \note For example :
 *  \code{.cpp}
 *  #if KHAOS_GET_VERSION_MAJOR(version1) == KHAOS_GET_VERSION_MAJOR(version2)
 *   //...
 *  #else
 *   //...
 *  #endif
 *  \endcode
 */

/** \hideinitializer
 *  \brief Set standard version numbers.
 *  \param[in] major The major number can be in the [0,99] range.
 *  \param[in] minor The minor number can be in the [0,99] range.
 *  \param[in] patch The patch number can be in the [0,99999] range.
 *
 *  \remark Decimal base whole numbers in the range [0,1000000000).
 *  \remarks The number range is designed to allow for a (2,2,5) triplet; Which fits within a 32 bit value.
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 *  \note Values can be specified in any base. As the defined value is an constant expression.
 *  \note The implementation enforces the individual ranges for the major, minor, and patch numbers.
 *  \warning Values over the ranges are truncated (modulo).
 */
#define KHAOS_SET_VERSION(major, minor, patch) ((((major)*1UL % 100) * 10000000) + (((minor)*1UL % 100) * 100000) + ((patch)*1UL % 100000))

/** \hideinitializer
 *  \brief Set standard tweak (build) numbers.
 *  \param[in] tweak The tweak number can be in the [0,9999] range.
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 *  \note Values can be specified in any base. As the defined value is an constant expression.
 *  \note The implementation enforces the individual ranges for the major, minor, and patch numbers.
 *  \warning Values over the ranges are truncated (modulo).
 */
#define KHAOS_SET_VERSION_TWEAK(tweak) ((tweak)*1UL % 100000)

/** \hideinitializer
 *  \brief Get standard major version numbers.
 *  \param[in] version The standard version number.
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define KHAOS_GET_VERSION_MAJOR(version) (((version##_PRIVATE()) * 1UL / 10000000) % 100)

/** \hideinitializer
 *  \bried Get standard minor version numbers.
 *  \param[in] version The standard version number.
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define KHAOS_GET_VERSION_MINOR(version) (((version##_PRIVATE()) * 1UL / 100000) % 100)

/** \hideinitializer
 *  \brief Get standard patch version numbers.
 *  \param[in] version The standard version number.
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define KHAOS_GET_VERSION_PATCH(version) ((version##_PRIVATE()) * 1UL % 100000)

/** \hideinitializer
 *  \brief Get standard tweak version numbers.
 *  \param[in] version The standard version number.
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define KHAOS_GET_VERSION_TWEAK(version) ((version##_TWEAK_PRIVATE()) * 1UL % 100000)

#endif  // KHAOS_VERSIONMACROS_H_