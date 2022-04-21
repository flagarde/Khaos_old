#ifndef KHAOS_COMPAREVERSIONMACROS_H_
#define KHAOS_COMPAREVERSIONMACROS_H_

#include "khaos/KhaosVersion.h"
#include "khaos/VersionMacros.h"

/** \file CompareVersionMacros.h
 *  \copyright 2022 flagarde
 *  \brief Define macros to compare versions.
 *  \note Use these macros only if you need preprocessor version checking.
 *  \note For example :
 *  \code{.cpp}
 *  #if KHAOS_VERSION_GREATER(version1,version2)
 *   //...
 *  #else
 *   //...
 *  #endif
 *  \endcode
 */

/** \hideinitializer
 *  \brief Check if version is greater than the major, minor, patch .
 *  \param[in] version .
 *  \param[in] major .
 *  \param[in] minor .
 *  \param[in] patch .
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define KHAOS_VERSION_GREATER(version, major, minor, patch) (version##_PRIVATE() > KHAOS_SET_VERSION(major, minor, patch))

/** \hideinitializer
 *  \brief Check if version is greater or equal than major, minor, patch .
 *  \param[in] version .
 *  \param[in] major .
 *  \param[in] minor .
 *  \param[in] patch .
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define KHAOS_VERSION_GREATER_EQUAL(version, major, minor, patch) (version##_PRIVATE() >= KHAOS_SET_VERSION(major, minor, patch))

/** \hideinitializer
 *  \brief Check if version is equal than major, minor, patch .
 *  \param[in] version .
 *  \param[in] major .
 *  \param[in] minor .
 *  \param[in] patch .
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define KHAOS_VERSION_EQUAL(version, major, minor, patch) (version##_PRIVATE() == KHAOS_SET_VERSION(major, minor, patch))

/** \hideinitializer
 *  \brief Check if version is lower or equal than major, minor, patch .
 *  \param[in] version .
 *  \param[in] major .
 *  \param[in] minor .
 *  \param[in] patch .
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define KHAOS_VERSION_LOWER_EQUAL(version, major, minor, patch) (version##_PRIVATE() <= KHAOS_SET_VERSION(major, minor, patch))

/** \hideinitializer
 *  \brief Check if version is lower than major, minor, patch .
 *  \param[in] version .
 *  \param[in] major .
 *  \param[in] minor .
 *  \param[in] patch .
 *
 *  \note Value can be directly used in both preprocessor and compiler expressions for comparison to other similarly defined values.
 */
#define KHAOS_VERSION_LOWER(version, major, minor, patch) (version##_PRIVATE() < KHAOS_SET_VERSION(major, minor, patch))

#endif  // KHAOS_COMPAREVERSIONMACROS_H_
