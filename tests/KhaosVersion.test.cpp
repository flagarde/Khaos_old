/* Copyright 2022 flagarde */

#include "khaos/KhaosVersion.h"

// NOLINTBEGIN
#include <doctest/doctest.h>
// NOLINTEND

TEST_CASE("Test KHAOS_VERSION") { CHECK_EQ((((MAJOR) % 100) * 10000000) + (((MINOR) % 100) * 100000) + ((PATCH) % 100000), KHAOS_VERSION_Khaos_PRIVATE()); }

TEST_CASE("Test KHAOS_VERSION_TWEAK") { CHECK_EQ(static_cast<int>(TWEAK), static_cast<int>(KHAOS_VERSION_Khaos_TWEAK_PRIVATE())); }
