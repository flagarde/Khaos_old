#ifndef KHAOS_CXX_H_
#define KHAOS_CXX_H_

/*! \file CXX.h
 *  \copyright 2022 flagarde
 *  \brief Detect the C++ standard and define some useful macros.
 *  \warning \b CXX11 is always false for \b MSVC only c++14 and upper are considered.
*/

#include "CXXStandards.h"

#if defined(_MSC_VER)
  /*!
   * https://devblogs.microsoft.com/cppblog/msvc-now-correctly-reports-__cplusplus/
   *
   * Starting from Visual Studio 2017 version 15.7 the option /Zc:__cplusplus.
   *
   * Try to warn the user to do this !
   *
   */
  #if defined(_MSVC_LANG)
    #define KHAOS_CXX_STANDARD_PRIVATE() (_MSVC_LANG) /*!< defined as _MSVC_LANG */
    #if __cplusplus != _MSVC_LANG
      #if _MSC_VER >= 1914
        #pragma message("[Khaos] : MSVC doesn't set the correct value for __cplusplus (cf. https://devblogs.microsoft.com/cppblog/msvc-now-correctly-reports-__cplusplus/). Use /Zc:__cplusplus option to activate it !")
      #else
        #pragma message("[Khaos] : MSVC doesn't set the correct value for __cplusplus (cf. https://devblogs.microsoft.com/cppblog/msvc-now-correctly-reports-__cplusplus/) !")
      #endif
    #endif
  #else
    #define KHAOS_CXX_STANDARD_PRIVATE() (__cplusplus) /*!< defined as __cplusplus */
  #endif
#else
  #define KHAOS_CXX_STANDARD_PRIVATE() (__cplusplus) /*!< defined as __cplusplus */
#endif

#if defined(__STRICT_ANSI__) || (defined(_MSC_VER) && !defined(_MSC_EXTENSIONS))
  #define KHAOS_LANGUAGE_ISO_PRIVATE()        (1L) /*!< 1 if strict ISO, 0 otherwise */
  #define KHAOS_LANGUAGE_Extensions_PRIVATE() (0L) /*!< 0 if strict ISO, 1 otherwise */
#else
  #define KHAOS_LANGUAGE_ISO_PRIVATE()        (0L) /*!< 1 if strict ISO, 0 otherwise */
  #define KHAOS_LANGUAGE_Extensions_PRIVATE() (1L) /*!< 0 if strict ISO, 1 otherwise */
#endif

#if defined(__embedded_cplusplus)
  #define KHAOS_LANGUAGE_Embedded_PRIVATE() (1L) /*!< 1 if CPP Embedded */
#else
  #define KHAOS_LANGUAGE_Embedded_PRIVATE() (0L) /*!< 0 if CPP Embedded */
#endif

#endif /* KHAOS_CXX_H_ */
