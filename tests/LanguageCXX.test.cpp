/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

/* doctest need c++11 so disable it to test C++98*/

#include "Khaos/Language.h"

#if defined(_WIN32) && !defined(__MINGW32__) && !defined(__MINGW64__)
  #pragma warning(disable : 4702 4805)
#endif

#if CPP_STANDARD == 98
const int  standard       = 8;  //HACK to simplify he check
const char standard_str[] = "C++98";
static int CXX98()
{
  #if LANGUAGE_IS_GREATER(CXX98)
  return -1;
  #endif

  #if !LANGUAGE_IS_GREATER_EQUAL(CXX98)
  return -1;
  #endif

  #if !LANGUAGE_IS_EQUAL(CXX98)
  return -1;
  #endif

  #if !LANGUAGE_IS_LOWER_EQUAL(CXX98)
  return -1;
  #endif

  #if LANGUAGE_IS_LOWER(CXX98)
  return -1;
  #endif

  #if LANGUAGE_IS(C) || LANGUAGE_IS(Cuda) || LANGUAGE_IS(ClangCuda) || LANGUAGE_IS(ObjCPP) || LANGUAGE_IS(ObjC) || LANGUAGE_IS(Assembler) || LANGUAGE_IS(Fortran)
  return -1;
  #endif

  #if !LANGUAGE_IS(CXX)
  return -1;
  #endif

  #if CPP_EXTENSIONS == 0
    #if !LANGUAGE_IS(ISO)
  return -1;
    #endif

    #if LANGUAGE_IS(Extensions)
  return -1;
    #endif
  #else
    #if LANGUAGE_IS(ISO)
  return -1;
    #endif
    #if !LANGUAGE_IS(Extensions)
  return -1;
    #endif
  #endif
  return 0;
}
#elif CPP_STANDARD == 11
const int  standard       = 11;
const char standard_str[] = "C++11";
#elif CPP_STANDARD == 14
const int  standard       = 14;
const char standard_str[] = "C++14";
#elif CPP_STANDARD == 17
const int  standard       = 17;
const char standard_str[] = "C++17";
#elif CPP_STANDARD == 20
const int  standard       = 20;
const char standard_str[] = "C++20";
#elif CPP_STANDARD == 23
const int  standard       = 23;
const char standard_str[] = "C++23";
#else
  #error Standard not yet implemented !
#endif

#if CPP_EXTENSIONS == 0
const char str[] = "";
#else
const char str[] = "(Extension)";
#endif

#if CPP_STANDARD == 98
int main() { return CXX98(); }
#else
  #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
  // NOLINTBEGIN
  #include "doctest/doctest.h"
// NOLINTEND
TEST_CASE(standard_str) { CHECK(true); }
TEST_CASE(str) { CHECK(true); }
TEST_CASE("LANGUAGE_IS(C)")
{
  #if LANGUAGE_IS(C)
  CHECK(false);
  #else
  CHECK(true);
  #endif
}

TEST_CASE("LANGUAGE_IS(Cuda)")
{
  #if LANGUAGE_IS(Cuda)
  CHECK(false);
  #else
  CHECK(true);
  #endif
}

TEST_CASE("LANGUAGE_IS(ClangCuda)")
{
  #if LANGUAGE_IS(ClangCuda)
  CHECK(false);
  #else
  CHECK(true);
  #endif
}

TEST_CASE("LANGUAGE_IS(ObjCPP)")
{
  #if LANGUAGE_IS(ObjCPP)
  CHECK(false);
  #else
  CHECK(true);
  #endif
}

TEST_CASE("LANGUAGE_IS(Assembler)")
{
  #if LANGUAGE_IS(Assembler)
  CHECK(false);
  #else
  CHECK(true);
  #endif
}

TEST_CASE("LANGUAGE_IS(Fortran)")
{
  #if LANGUAGE_IS(Fortran)
  CHECK(false);
  #else
  CHECK(true);
  #endif
}

TEST_CASE("LANGUAGE_IS(CXX)")
{
  #if LANGUAGE_IS(CXX)
  CHECK(true);
  #else
  CHECK(false);
  #endif
}

TEST_CASE("LANGUAGE_IS(ISO)")
{
  #if CPP_EXTENSIONS == 0
    #if LANGUAGE_IS(ISO)
  CHECK(true);
    #else
  CHECK(false);
    #endif
  #else
    #if LANGUAGE_IS(ISO)
  CHECK(false);
    #else
  CHECK(true);
    #endif
  #endif
}

TEST_CASE("LANGUAGE_IS(Extensions)")
{
  #if CPP_EXTENSIONS == 0
    #if LANGUAGE_IS(Extensions)
  CHECK(false);
    #else
  CHECK(true);
    #endif
  #else
    #if LANGUAGE_IS(Extensions)
  CHECK(true);
    #else
  CHECK(false);
    #endif
  #endif
}

TEST_CASE("LANGUAGE_IS_GREATER(...)")
{
  #if LANGUAGE_IS_GREATER(CXX98)
  CHECK_GT(standard, 8);
  #endif
  #if LANGUAGE_IS_GREATER(CXX11)
  CHECK_GT(standard, 11);
  #endif
  #if LANGUAGE_IS_GREATER(CXX14)
  CHECK_GT(standard, 14);
  #endif
  #if LANGUAGE_IS_GREATER(CXX17)
  CHECK_GT(standard, 17);
  #endif
  #if LANGUAGE_IS_GREATER(CXX20)
  CHECK_GT(standard, 20);
  #endif
  #if LANGUAGE_IS_GREATER(CXX23)
  CHECK_GT(standard, 23);
  #endif
}

TEST_CASE("LANGUAGE_IS_GREATER_EQUAL(...)")
{
  #if LANGUAGE_IS_GREATER_EQUAL(CXX98)
  CHECK_GE(standard, 8);
  #endif
  #if LANGUAGE_IS_GREATER_EQUAL(CXX11)
  CHECK_GE(standard, 11);
  #endif
  #if LANGUAGE_IS_GREATER_EQUAL(CXX14)
  CHECK_GE(standard, 14);
  #endif
  #if LANGUAGE_IS_GREATER_EQUAL(CXX17)
  CHECK_GE(standard, 17);
  #endif
  #if LANGUAGE_IS_GREATER_EQUAL(CXX20)
  CHECK_GE(standard, 20);
  #endif
  #if LANGUAGE_IS_GREATER_EQUAL(CXX23)
  CHECK_GE(standard, 23);
  #endif
}

TEST_CASE("LANGUAGE_IS_EQUAL(...)")
{
  #if LANGUAGE_IS_EQUAL(CXX98)
  CHECK_EQ(standard, 8);
  #endif
  #if LANGUAGE_IS_EQUAL(CXX11)
  CHECK_EQ(standard, 11);
  #endif
  #if LANGUAGE_IS_EQUAL(CXX14)
  CHECK_EQ(standard, 14);
  #endif
  #if LANGUAGE_IS_EQUAL(CXX17)
  CHECK_EQ(standard, 17);
  #endif
  #if LANGUAGE_IS_EQUAL(CXX20)
  CHECK_EQ(standard, 20);
  #endif
  #if LANGUAGE_IS_EQUAL(CXX23)
  CHECK_EQ(standard, 23);
  #endif
}

TEST_CASE("LANGUAGE_IS_LOWER_EQUAL(...)")
{
  #if LANGUAGE_IS_LOWER_EQUAL(CXX98)
  CHECK_LE(standard, 8);
  #endif
  #if LANGUAGE_IS_LOWER_EQUAL(CXX11)
  CHECK_LE(standard, 11);
  #endif
  #if LANGUAGE_IS_LOWER_EQUAL(CXX14)
  CHECK_LE(standard, 14);
  #endif
  #if LANGUAGE_IS_LOWER_EQUAL(CXX17)
  CHECK_LE(standard, 17);
  #endif
  #if LANGUAGE_IS_LOWER_EQUAL(CXX20)
  CHECK_LE(standard, 20);
  #endif
  #if LANGUAGE_IS_LOWER_EQUAL(CXX23)
  CHECK_LE(standard, 23);
  #endif
}

TEST_CASE("LANGUAGE_IS_LOWER(...)")
{
  #if LANGUAGE_IS_LOWER(CXX98)
  CHECK_LT(standard, 8);
  #endif
  #if LANGUAGE_IS_LOWER(CXX11)
  CHECK_LT(standard, 11);
  #endif
  #if LANGUAGE_IS_LOWER(CXX14)
  CHECK_LT(standard, 14);
  #endif
  #if LANGUAGE_IS_LOWER(CXX17)
  CHECK_LT(standard, 17);
  #endif
  #if LANGUAGE_IS_LOWER(CXX20)
  CHECK_LT(standard, 20);
  #endif
  #if LANGUAGE_IS_LOWER(CXX23)
  CHECK_LT(standard, 23);
  #endif
}

#endif  // CPP_STANDARD == 98
