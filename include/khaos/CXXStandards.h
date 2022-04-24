#ifndef KHAOS_CXXSTANDARDS_H_
#define KHAOS_CXXSTANDARDS_H_

/*! \file CXXStandards.h
 *  \copyright 2022 flagarde
 *  \brief Define the version of the C++ standard.
 *  Define macros that expand to the integer constant of type \b long whose value are the version of the C++ standard.
 *  Official values for the \b __cplusplus macro.
*/

#define KHAOS_STANDARD_CXX98_PRIVATE() (199711L)  //!< Value for the C++97 standard
#define KHAOS_STANDARD_CXX11_PRIVATE() (201103L)  //!< Value for the C++11 standard
#define KHAOS_STANDARD_CXX14_PRIVATE() (201402L)  //!< Value for the C++14 standard
#define KHAOS_STANDARD_CXX17_PRIVATE() (201703L)  //!< Value for the C++17 standard
#define KHAOS_STANDARD_CXX20_PRIVATE() (202002L)  //!< Value for the C++20 standard

#endif  // KHAOS_CXXSTANDARDS_H_
