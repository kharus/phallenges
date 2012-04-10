#include <limits.h>
#include "10035.h"
#include "gtest/gtest.h"

TEST(CarryTest, Zero) {
  EXPECT_EQ(false, is_carry(0, 0, 0));
}

TEST(CarryTest, ZeroPlusCarry) {
  EXPECT_EQ(false, is_carry(0, 0, 1));
}

TEST(CarryTest, Nine) {
  EXPECT_EQ(false, is_carry(4, 5, 0));
}

TEST(CarryTest, NinePlusCarry) {
  EXPECT_EQ(true, is_carry(4, 5, 1));
}

TEST(CarryTest, Ten) {
  EXPECT_EQ(true, is_carry(5, 5, 0));
}

TEST(CarryTest, TenPlusCarry) {
  EXPECT_EQ(true, is_carry(5, 5, 1));
}

TEST(SplitTest, SplitZero) {
  std::vector<int> fixture = {0};
  EXPECT_EQ(fixture, split(0));
}

TEST(SplitTest, SplitFive) {
  std::vector<int> fixture = {5};
  EXPECT_EQ(fixture, split(5));
}

TEST(SplitTest, SplitSixtySix) {
  std::vector<int> fixture = {6,6};
  EXPECT_EQ(fixture, split(66));
}

TEST(SplitTest, SplitBig) {
  std::vector<int> fixture = {1,2,3,4,5,6,7,8,9};
  EXPECT_EQ(fixture, split(987654321));
}

TEST(TotalCarriesTest, OnePlusOne) {
  EXPECT_EQ(0, number_of_carries(1, 1));
}

TEST(TotalCarriesTest, 5Plus4) {
  EXPECT_EQ(0, number_of_carries(5, 4));
}

TEST(TotalCarriesTest, 5Plus6) {
  EXPECT_EQ(1, number_of_carries(5, 6));
}

TEST(TotalCarriesTest, A555) {
  EXPECT_EQ(3, number_of_carries(555, 555));
}

