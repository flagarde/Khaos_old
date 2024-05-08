/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

#ifndef KHAOS_LANGUAGE_H_
#define KHAOS_LANGUAGE_H_

/*! \file Languages.h
 *  \brief Detect the languages and define some useful macros.
*/

#if defined(__CUDA__) || defined(__CUDACC__)
  /*!
  * Both clang and nvcc define __CUDACC__ during CUDA compilation.
  *
  * When clang is actually compiling CUDA code – rather than being used as a subtool of NVCC’s – it defines the __CUDA__ macro.
  */
  #define KHAOS_LANGUAGE_Cuda_PRIVATE() 1L
  #if defined(__clang__) && defined(__CUDA__)
    #define KHAOS_LANGUAGE_ClangCuda_PRIVATE() 1L
  #endif
#elif defined(__OBJC__)
  #if defined(__cplusplus)
    #define KHAOS_LANGUAGE_ObjCPP_PRIVATE() 1L
  #else
    #define KHAOS_LANGUAGE_ObjC_PRIVATE() 1L
  #endif
#elif defined(__ASSEMBLER__)
  #define KHAOS_LANGUAGE_Assembler_PRIVATE() 1L
#elif defined(__GFORTRAN__)
  #define KHAOS_LANGUAGE_Fortran_PRIVATE() 1L
#elif defined(__cplusplus)
  #define KHAOS_LANGUAGE_CXX_PRIVATE() 1L
  #include "khaos/CXX.h"
#else
  #define KHAOS_LANGUAGE_C_PRIVATE() 1L
  #include "khaos/C.h"
#endif

#if !defined(KHAOS_LANGUAGE_Cuda_PRIVATE)
  #define KHAOS_LANGUAGE_Cuda_PRIVATE() 0L
#endif
#if !defined(KHAOS_LANGUAGE_ClangCuda_PRIVATE)
  #define KHAOS_LANGUAGE_ClangCuda_PRIVATE() 0L
#endif
#if !defined(KHAOS_LANGUAGE_ObjCPP_PRIVATE)
  #define KHAOS_LANGUAGE_ObjCPP_PRIVATE() 0L
#endif
#if !defined(KHAOS_LANGUAGE_ObjC_PRIVATE)
  #define KHAOS_LANGUAGE_ObjC_PRIVATE() 0L
#endif
#if !defined(KHAOS_LANGUAGE_Assembler_PRIVATE)
  #define KHAOS_LANGUAGE_Assembler_PRIVATE() 0L
#endif
#if !defined(KHAOS_LANGUAGE_Fortran_PRIVATE)
  #define KHAOS_LANGUAGE_Fortran_PRIVATE() 0L
#endif
#if !defined(KHAOS_LANGUAGE_CXX_PRIVATE)
  #define KHAOS_LANGUAGE_CXX_PRIVATE() 0L
#endif
#if !defined(KHAOS_LANGUAGE_C_PRIVATE)
  #define KHAOS_LANGUAGE_C_PRIVATE() 0L
#endif

/** @hideinitializer
 * Check the language.
 * \param[in] language The language to test.
 *
 * Values :
 * | Macro      | (other value) |
 * | :--------: | :-----------: |
 * | Assembler  |               |
 * | C          |               |
 * | ClangCuda  | Cuda          |
 * | Cuda       |               |
 * | CXX        |               |
 * | Fortran    |               |
 * | ObjC       |               |
 * | ObjCPP     |               |
 *
 * \note Can be directly used in both preprocessor and compiler expressions.
 */

#define LANGUAGE_IS(language) (KHAOS_LANGUAGE_##language##_PRIVATE())

#if LANGUAGE_IS(C)
  /** @hideinitializer
  * Check if the C, CXX standard is greater than \b standard.
  * \param[in] standard The language to test.
  *
  * Values for C
  * | Macro      |
  * | :--------: |
  * | C90        |
  * | C95        |
  * | C99        |
  * | C11        |
  * | C17        |
  *
  * Values for CXX
  * | Macro      |
  * | :--------: |
  * | CXX97      |
  * | CXX11      |
  * | CXX14      |
  * | CXX17      |
  * | CXX20      |
  *
  * \note Can be directly used in both preprocessor and compiler expressions.
  */
  #define LANGUAGE_IS_GREATER(standard)       (KHAOS_C_STANDARD_PRIVATE() > KHAOS_STANDARD_##standard##_PRIVATE())
  /** @hideinitializer
  * Check if the C, CXX standard is greater or equal than \b standard.
  * \param[in] standard The language to test.
  *
  * Values for C and CXX : see KHAOS_LANGUAGE_IS_GREATER
  *
  * \note Can be directly used in both preprocessor and compiler expressions.
  */
  #define LANGUAGE_IS_GREATER_EQUAL(standard) (KHAOS_C_STANDARD_PRIVATE() >= KHAOS_STANDARD_##standard##_PRIVATE())
  /** @hideinitializer
  * Check if the C, CXX standard is equal than \b standard.
  * \param[in] standard The language to test.
  *
  * Values for C and CXX : see KHAOS_LANGUAGE_IS_GREATER
  *
  * \note Can be directly used in both preprocessor and compiler expressions.
  */
  #define LANGUAGE_IS_EQUAL(standard)         (KHAOS_C_STANDARD_PRIVATE() == KHAOS_STANDARD_##standard##_PRIVATE())
  /** @hideinitializer
  * Check if the C, CXX standard is lower or equal than \b standard.
  * \param[in] standard The language to test.
  *
  * Values for C and CXX : see KHAOS_LANGUAGE_IS_GREATER
  *
  * \note Can be directly used in both preprocessor and compiler expressions.
  */
  #define LANGUAGE_IS_LOWER_EQUAL(standard)   (KHAOS_C_STANDARD_PRIVATE() <= KHAOS_STANDARD_##standard##_PRIVATE())
  /** @hideinitializer
  * Check if the C, CXX standard is lower than \b standard.
  * \param[in] standard The language to test.
  *
  * Values for C and CXX : see KHAOS_LANGUAGE_IS_GREATER
  *
  * \note Can be directly used in both preprocessor and compiler expressions.
  */
  #define LANGUAGE_IS_LOWER(standard)         (KHAOS_C_STANDARD_PRIVATE() < KHAOS_STANDARD_##standard##_PRIVATE())
#elif LANGUAGE_IS(CXX)
  #define LANGUAGE_IS_GREATER(standard)       (KHAOS_CXX_STANDARD_PRIVATE() > KHAOS_STANDARD_##standard##_PRIVATE())
  #define LANGUAGE_IS_GREATER_EQUAL(standard) (KHAOS_CXX_STANDARD_PRIVATE() >= KHAOS_STANDARD_##standard##_PRIVATE())
  #define LANGUAGE_IS_EQUAL(standard)         (KHAOS_CXX_STANDARD_PRIVATE() == KHAOS_STANDARD_##standard##_PRIVATE())
  #define LANGUAGE_IS_LOWER_EQUAL(standard)   (KHAOS_CXX_STANDARD_PRIVATE() <= KHAOS_STANDARD_##standard##_PRIVATE())
  #define LANGUAGE_IS_LOWER(standard)         (KHAOS_CXX_STANDARD_PRIVATE() < KHAOS_STANDARD_##standard##_PRIVATE())
#else
  #define LANGUAGE_IS_GREATER(standard)       (0L)
  #define LANGUAGE_IS_GREATER_EQUAL(standard) (0L)
  #define LANGUAGE_IS_EQUAL(standard)         (0L)
  #define LANGUAGE_IS_LOWER_EQUAL(standard)   (0L)
  #define LANGUAGE_IS_LOWER(standard)         (0L)
#endif

#endif /* KHAOS_LANGUAGE_H_ */
