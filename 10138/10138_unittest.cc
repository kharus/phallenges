#include <limits.h>
#include "10138.h"
#include "gtest/gtest.h"

TEST(ConverTest, Zero) {
  std::vector<int> fixture = {2,1};
  EXPECT_EQ(fixture, convert("12"));
}

TEST(AddTest, Zero) {
  std::vector<int> ninety_nine = {9,9};
  std::vector<int> one = {1};
  std::vector<int> hundred = {0, 0, 1};
  EXPECT_EQ(hundred, add(ninety_nine, one));
}

TEST(CompareTest, Zero) {
  std::vector<int> ninety_eight = {8,9};
  std::vector<int> eighty_nine = {9,8};
  std::vector<int> eighty_nine2 = {9,8};
  std::vector<int> hundred = {0, 0, 1};
  EXPECT_LT(0, comp(hundred, ninety_eight));
  EXPECT_LT(0, comp(ninety_eight, eighty_nine));
  EXPECT_EQ(0, comp(eighty_nine, eighty_nine2));
}

TEST(Fib, Ten){
  std::vector< std::vector<int> > fibs = fib_table(15);
  std::vector<int> fifty_five = {5,5};
  EXPECT_EQ(fifty_five, fibs[8]);
}

TEST(FindBelow, Ten){
  std::vector< std::vector<int> > fibs = fib_table(15);
  std::vector<int> fifty_three = {3,5};
  std::vector<int> fifty_five = {5,5};
  EXPECT_EQ(7, find_below_index(fibs, fifty_three));
  EXPECT_EQ(8, find_below_index(fibs, fifty_five));
}

TEST(FindAbove, Ten){
  std::vector< std::vector<int> > fibs = fib_table(15);
  std::vector<int> fifty_eight = {8,5};
  std::vector<int> fifty_five = {5,5};
  EXPECT_EQ(9, find_above_index(fibs, fifty_eight));
  EXPECT_EQ(8, find_above_index(fibs, fifty_five));
}

TEST(FindNumbers, Ten){
  std::vector< std::vector<int> > fibs = fib_table(481);
  EXPECT_EQ(5, numbers_in_interval(fibs, convert("10"), convert("100")));
  EXPECT_EQ(4, numbers_in_interval(fibs, convert("1234567890"), convert("9876543210")));
}
