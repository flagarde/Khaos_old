/* Copyright 2022 flagarde */
/* doctest need c++11 so disable it to test C++98 */

#include "khaos/Language.h"

#if CPP_STANDARD == 98

int main()
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
}

#else
  #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
  // NOLINTBEGIN
  #include <doctest/doctest.h>
// NOLINTEND
TEST_CASE("Test LANGUAGE_IS(x)")
{
  #if LANGUAGE_IS(C) || LANGUAGE_IS(Cuda) || LANGUAGE_IS(ClangCuda) || LANGUAGE_IS(ObjCPP) || LANGUAGE_IS(ObjC) || LANGUAGE_IS(Assembler) || LANGUAGE_IS(Fortran)
  CHECK(false);
  #else
  CHECK(true);
  #endif

  #if LANGUAGE_IS(CXX)
  CHECK(true);
  #else
  CHECK(false);
  #endif

  #if CPP_EXTENSIONS == 0

    #if LANGUAGE_IS(ISO)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS(Extensions)
  CHECK(false);
    #else
  CHECK(true);
    #endif

  #else

    #if LANGUAGE_IS(ISO)
  CHECK(false);
    #else
  CHECK(true);
    #endif

    #if LANGUAGE_IS(Extensions)
  CHECK(true);
    #else
  CHECK(false);
    #endif

  #endif
}

  #if CPP_STANDARD == 11 && !defined(_MSC_VER) && !defined(__clang__) /* MSV will never been c++11 only */
    #if CPP_EXTENSIONS == 0
TEST_CASE("Test the language CXX11 extensions OFF")
    #else
TEST_CASE("Test the language CXX11 extensions ON")
    #endif
{
    #if LANGUAGE_IS_GREATER(CXX11)
  CHECK(false);
    #else
  CHECK(true);
    #endif

    #if LANGUAGE_IS_GREATER_EQUAL(CXX11)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_EQUAL(CXX11)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_LOWER_EQUAL(CXX11)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_LOWER(CXX11)
  CHECK(false);
    #else
  CHECK(true);
    #endif
}

  #elif CPP_STANDARD == 14

    #if CPP_EXTENSIONS == 0
TEST_CASE("Test the language CXX14 extensions OFF")
    #else
TEST_CASE("Test the language CXX14 extensions ON")
    #endif
{
    #if LANGUAGE_IS_GREATER(CXX14)
  CHECK(false);
    #else
  CHECK(true);
    #endif

    #if LANGUAGE_IS_GREATER_EQUAL(CXX14)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_EQUAL(CXX14)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_LOWER_EQUAL(CXX14)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_LOWER(CXX14)
  CHECK(false);
    #else
  CHECK(true);
    #endif
}

  #elif CPP_STANDARD == 17

    #if CPP_EXTENSIONS == 0
TEST_CASE("Test the language CXX17 extensions OFF")
    #else
TEST_CASE("Test the language CXX17 extensions ON")
    #endif
{
    #if LANGUAGE_IS_GREATER(CXX17)
  CHECK(false);
    #else
  CHECK(true);
    #endif

    #if LANGUAGE_IS_GREATER_EQUAL(CXX17)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_EQUAL(CXX17)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_LOWER_EQUAL(CXX17)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_LOWER(CXX17)
  CHECK(false);
    #else
  CHECK(true);
    #endif
}

  #elif CPP_STANDARD == 20

    #if CPP_EXTENSIONS == 0
TEST_CASE("Test the language CXX20 extensions OFF")
    #else
TEST_CASE("Test the language CXX20 extensions ON")
    #endif
{
    #if LANGUAGE_IS_GREATER(CXX20)
  CHECK(false);
    #else
  CHECK(true);
    #endif

    #if LANGUAGE_IS_GREATER_EQUAL(CXX20)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_EQUAL(CXX20)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_LOWER_EQUAL(CXX20)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_LOWER(CXX20)
  CHECK(false);
    #else
  CHECK(true);
    #endif
}

  #elif CPP_STANDARD == 23

    #if CPP_EXTENSIONS == 0
TEST_CASE("Test the language CXX23 extensions OFF")
    #else
TEST_CASE("Test the language CXX23 extensions ON")
    #endif
{
    #if LANGUAGE_IS_GREATER(CXX20)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_GREATER_EQUAL(CXX20)
  CHECK(true);
    #else
  CHECK(false);
    #endif

    #if LANGUAGE_IS_EQUAL(CXX20)
  CHECK(false);
    #else
  CHECK(true);
    #endif

    #if LANGUAGE_IS_LOWER_EQUAL(CXX20)
  CHECK(false);
    #else
  CHECK(true);
    #endif

    #if LANGUAGE_IS_LOWER(CXX20)
  CHECK(false);
    #else
  CHECK(true);
    #endif
}

  #endif

#endif  // CPP_STANDARD == 98
