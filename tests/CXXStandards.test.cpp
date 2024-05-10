/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

/* Copyright 2022 flagarde */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Khaos/CXXStandards.h"

// NOLINTBEGIN
#include "doctest/doctest.h"
// NOLINTEND

TEST_CASE("Test the CXXStandards values")
{
  CHECK_EQ(KHAOS_STANDARD_CXX98_PRIVATE(), 199711L);
  CHECK_EQ(KHAOS_STANDARD_CXX11_PRIVATE(), 201103L);
  CHECK_EQ(KHAOS_STANDARD_CXX14_PRIVATE(), 201402L);
  CHECK_EQ(KHAOS_STANDARD_CXX17_PRIVATE(), 201703L);
  CHECK_EQ(KHAOS_STANDARD_CXX20_PRIVATE(), 202002L);
}
