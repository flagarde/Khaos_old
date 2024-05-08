/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

/* Copyright 2022 flagarde */

#include "khaos/VersionMacros.h"

#include "khaos/KhaosVersion.h"

// NOLINTBEGIN
#include "doctest/doctest.h"
// NOLINTEND

#define KHAOS_VERSION_Test_PRIVATE()  SET_VERSION(2, 3, 4, 5)
#define KHAOS_VERSION_Test2_PRIVATE() SET_VERSION(65536, 65536, 65536, 65536) /* Should be seen as 0.0.0.0 */

TEST_CASE("Test GET_VERSION_MAJOR(x)")
{
  CHECK_EQ(MAJOR, GET_VERSION_MAJOR(Khaos));
  CHECK_EQ(2, GET_VERSION_MAJOR(Test));
  CHECK_EQ(0, GET_VERSION_MAJOR(Test2));
}

TEST_CASE("Test GET_VERSION_MINOR(x)")
{
  CHECK_EQ(MINOR, GET_VERSION_MINOR(Khaos));
  CHECK_EQ(3, GET_VERSION_MINOR(Test));
  CHECK_EQ(0, GET_VERSION_MINOR(Test2));
}

TEST_CASE("Test GET_VERSION_PATCH(x)")
{
  CHECK_EQ(PATCH, GET_VERSION_PATCH(Khaos));
  CHECK_EQ(4, GET_VERSION_PATCH(Test));
  CHECK_EQ(0, GET_VERSION_PATCH(Test2));
}

TEST_CASE("Test GET_VERSION_TWEAK(x)")
{
  CHECK_EQ(TWEAK, GET_VERSION_TWEAK(Khaos));
  CHECK_EQ(5, GET_VERSION_TWEAK(Test));
  CHECK_EQ(0, GET_VERSION_TWEAK(Test2));
}

#undef KHAOS_VERSION_Test_PRIVATE
#undef KHAOS_VERSION_Test_PRIVATE2
