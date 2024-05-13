/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2024-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

#include <Khaos/Compiler.h>
#include <iostream>

int main()
{
#if COMPILER_IS(Clang)
  std::cout << "I'm Clang" << std::endl;
#elif COMPILER_IS(GCC)
  std::cout << "I'm GCC" << std::endl;
#elif COMPILER_IS(MSVC)
  std::cout << "I'm MSVC" << std::endl;
#endif

  std::cout << "Compiler version : " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
}
