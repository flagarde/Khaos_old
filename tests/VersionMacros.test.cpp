// Copyright 2022 flagarde

#include "khaos/VersionMacros.h"

#include <doctest/doctest.h>

TEST_CASE("Test KHAOS_GET_VERSION_MAJOR()") { CHECK_EQ(MAJOR, KHAOS_GET_VERSION_MAJOR(KHAOS_VERSION)); }

TEST_CASE("Test KHAOS_GET_VERSION_MINOR()") { CHECK_EQ(MINOR, KHAOS_GET_VERSION_MINOR(KHAOS_VERSION)); }

TEST_CASE("Test KHAOS_GET_VERSION_PATCH()") { CHECK_EQ(PATCH, KHAOS_GET_VERSION_PATCH(KHAOS_VERSION)); }

TEST_CASE("Test KHAOS_GET_VERSION_TWEAK()") { CHECK_EQ(TWEAK, KHAOS_GET_VERSION_TWEAK(KHAOS_VERSION)); }

#define TEST_VERSION_PRIVATE()       KHAOS_SET_VERSION(2, 3, 4)
#define TEST_VERSION_TWEAK_PRIVATE() KHAOS_SET_VERSION_TWEAK(5)

TEST_CASE("Test KHAOS_GET_VERSION_MAJOR()") { CHECK_EQ(2, KHAOS_GET_VERSION_MAJOR(TEST_VERSION)); }

TEST_CASE("Test KHAOS_GET_VERSION_MINOR()") { CHECK_EQ(3, KHAOS_GET_VERSION_MINOR(TEST_VERSION)); }

TEST_CASE("Test KHAOS_GET_VERSION_PATCH()") { CHECK_EQ(4, KHAOS_GET_VERSION_PATCH(TEST_VERSION)); }

TEST_CASE("Test KHAOS_GET_VERSION_TWEAK()") { CHECK_EQ(5, KHAOS_GET_VERSION_TWEAK(TEST_VERSION)); }

#undef TEST_VERSION
#undef TEST_VERSION_TWEAK
