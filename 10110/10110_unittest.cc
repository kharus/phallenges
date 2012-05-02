#include <limits.h>
#include "10110.h"
#include "gtest/gtest.h"

TEST(CheckBulb, UVATests) {
  EXPECT_EQ(false, check_bulb(3));
  EXPECT_EQ(true, check_bulb(6241));
  EXPECT_EQ(false, check_bulb(8191));
}
