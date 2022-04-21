// Copyright 2022 flagarde

#include "khaos/KhaosVersion.h"

#include <doctest/doctest.h>

TEST_CASE("Test KHAOS_VERSION") { CHECK_EQ((((MAJOR) % 100) * 10000000) + (((MINOR) % 100) * 100000) + ((PATCH) % 100000), KHAOS_VERSION_PRIVATE()); }

TEST_CASE("Test KHAOS_VERSION_TWEAK") { CHECK_EQ(static_cast<int>(TWEAK), static_cast<int>(KHAOS_VERSION_TWEAK_PRIVATE())); }
