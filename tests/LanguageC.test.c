/* Copyright 2022 flagarde */

#include "khaos/Language.h"

int main()
{
#if !LANGUAGE_IS(C)
  return -1;
#endif

#if LANGUAGE_IS(CXX) || LANGUAGE_IS(Cuda) || LANGUAGE_IS(ClangCuda) || LANGUAGE_IS(ObjCPP) || LANGUAGE_IS(ObjC) || LANGUAGE_IS(Assembler) || LANGUAGE_IS(Fortran)
  return -1;
#endif

#if C_EXTENSIONS == 0

  #if !LANGUAGE_IS(ISO)
  return -1;
  #endif

  #if LANGUAGE_IS(Extensions)
  return -1;
  #endif

#elif C_EXTENSIONS == 1

  #if LANGUAGE_IS(ISO)
    #error 145
  return -1;
  #endif

  #if !LANGUAGE_IS(Extensions)
  return -1;
  #endif

#endif

#if C_STANDARD == 90

  #if LANGUAGE_IS_GREATER(C90)
  return -1;
  #endif

  #if !LANGUAGE_IS_GREATER_EQUAL(C90)
  return -1;
  #endif

  #if !LANGUAGE_IS_EQUAL(C90)
  return -1;
  #endif

  #if !LANGUAGE_IS_LOWER_EQUAL(C90)
  return -1;
  #endif

  #if LANGUAGE_IS_LOWER(C90)
  return -1;
  #endif

#elif C_STANDARD == 95

  #if LANGUAGE_IS_GREATER(C95)
  return -1;
  #endif

  #if !LANGUAGE_IS_GREATER_EQUAL(C95)
  return -1;
  #endif

  #if !LANGUAGE_IS_EQUAL(C95)
  return -1;
  #endif

  #if !LANGUAGE_IS_LOWER_EQUAL(C95)
  return -1;
  #endif

  #if LANGUAGE_IS_LOWER(C95)
  return -1;
  #endif

#elif C_STANDARD == 99

  #if LANGUAGE_IS_GREATER(C99)
  return -1;
  #endif

  #if !LANGUAGE_IS_GREATER_EQUAL(C99)
  return -1;
  #endif

  #if !LANGUAGE_IS_EQUAL(C99)
  return -1;
  #endif

  #if !LANGUAGE_IS_LOWER_EQUAL(C99)
  return -1;
  #endif

  #if LANGUAGE_IS_LOWER(C99)
  return -1;
  #endif

#elif C_STANDARD == 11

  #if LANGUAGE_IS_GREATER(C11)
  return -1;
  #endif

  #if !LANGUAGE_IS_GREATER_EQUAL(C11)
  return -1;
  #endif

  #if !LANGUAGE_IS_EQUAL(C11)
  return -1;
  #endif

  #if !LANGUAGE_IS_LOWER_EQUAL(C11)
  return -1;
  #endif

  #if LANGUAGE_IS_LOWER(C11)
  return -1;
  #endif

#elif C_STANDARD == 17

  #if LANGUAGE_IS_GREATER(C17)
  return -1;
  #endif

  #if !LANGUAGE_IS_GREATER_EQUAL(C17)
  return -1;
  #endif

  #if !LANGUAGE_IS_EQUAL(C17)
  return -1;
  #endif

  #if !LANGUAGE_IS_LOWER_EQUAL(C17)
  return -1;
  #endif

  #if LANGUAGE_IS_LOWER(C17)
  return -1;
  #endif

#endif
}
