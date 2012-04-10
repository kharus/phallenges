#include <limits.h>
#include "10035.cc"
#include "gtest/gtest.h"

TEST(CarryTest, Zero) {
  std::vector<int> v;
  EXPECT_EQ(-1, is_carry(0, 0, 0));
}

