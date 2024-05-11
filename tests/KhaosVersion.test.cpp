/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

/* Copyright 2022 flagarde */
#include "Khaos/KhaosVersion.h"

#include <cmath>

// NOLINTBEGIN
#include "doctest/doctest.h"
// NOLINTEND

TEST_CASE("Test KHAOS_VERSION") { CHECK_EQ((((MAJOR) % 65536) * pow(2, 48)) + (((MINOR) % 65536) * pow(2, 32)) + (((PATCH) % 65536) * pow(2, 16)) + ((TWEAK) % 65536), KHAOS_DEFINE_Khaos_VERSION_PRIVATE()); }
