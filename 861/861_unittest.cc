#include <limits.h>
#include "861.cc"
#include "gtest/gtest.h"

TEST(Board, CheckSquares) {
  EXPECT_TRUE(is_square_in_board(square(1,1),1));
  EXPECT_TRUE(is_square_in_board(square(3,4),8));
  EXPECT_FALSE(is_square_in_board(square(0,1),8));
  EXPECT_FALSE(is_square_in_board(square(1,0),8));
  EXPECT_FALSE(is_square_in_board(square(9,1),8));
  EXPECT_FALSE(is_square_in_board(square(1,9),8));
}

TEST(Board, Attack) {
  square_set fixture = {square(1,1), square(2,2)};
  EXPECT_EQ(fixture, attacked_squares(square(2,2), 2));
}

TEST(Board, Attack3) {
  square_set fixture = {square(1,2), square(3,2), square(2,1)};
  EXPECT_EQ(fixture, attacked_squares(square(2,1), 3));
}

TEST(Board, AttackAscFull) {
  square_set fixture = {square(1,1), square(2,2), square(3,3)};
  EXPECT_EQ(fixture, attacked_diagonal(square(1,1),1, 3));
  EXPECT_EQ(fixture, attacked_diagonal(square(2,2),1, 3));
  EXPECT_EQ(fixture, attacked_diagonal(square(3,3),1, 3));
}

TEST(Board, AttackDescFull) {
  square_set fixture = {square(1,3), square(2,2), square(3,1)};
  EXPECT_EQ(fixture, attacked_diagonal(square(1,3), -1, 3));
  EXPECT_EQ(fixture, attacked_diagonal(square(2,2), -1, 3));
  EXPECT_EQ(fixture, attacked_diagonal(square(3,1), -1, 3));
}

TEST(Board, AttackAscOne) {
  EXPECT_EQ(square_set({square(1,3)}), attacked_diagonal(square(1,3),1, 3));
  EXPECT_EQ(square_set({square(3,1)}), attacked_diagonal(square(3,1),1, 3));
}

TEST(Board, AttackDescOne) {
  EXPECT_EQ(square_set({square(1,1)}), attacked_diagonal(square(1,1), -1, 3));
  EXPECT_EQ(square_set({square(3,3)}), attacked_diagonal(square(3,3), -1, 3));
}

TEST(Board, InitialZero) {
  EXPECT_EQ(0,  initial_d(square(1,1),1, 3));
  EXPECT_EQ(0,  initial_d(square(1,1),-1, 3));
  EXPECT_EQ(0,  initial_d(square(3,1),1, 3));
  EXPECT_EQ(0,  initial_d(square(1,3),-1, 3));
}

TEST(Board, Initial2) {
  EXPECT_EQ(2,  initial_d(square(3,3), 1, 3));
  EXPECT_EQ(2,  initial_d(square(3,1), -1, 3));
}

TEST(Board, Initial1) {
  EXPECT_EQ(1,  initial_d(square(3,2), 1, 3));
  EXPECT_EQ(1,  initial_d(square(3,2), -1, 3));
}

TEST(Board, ClearBoard) {
  EXPECT_EQ(square_set({square(1,1), square(2,2)}),  clear_board(0,2));
  EXPECT_EQ(square_set({square(1,2), square(2,1)}),  clear_board(1,2));
  EXPECT_EQ(square_set({square(1,1), square(1,3), square(2,2), square(3,1), square(3,3)}),  clear_board(0,3));
  EXPECT_EQ(square_set({square(1,2), square(2,1), square(2,3), square(3,2)}),  clear_board(1,3));
}

TEST(Board, UnattackedBoard) {
  EXPECT_EQ(square_set({square(1,1), square(2,2)}),  unattacked_board(square_set(), 0, 2));
  EXPECT_EQ(square_set({square(1,3), square(3,1)}),  
	    unattacked_board(square_set({square(1,1)}), 0, 3));
  EXPECT_EQ(square_set(),  
	    unattacked_board(square_set({square(2,2)}), 0, 3));
  EXPECT_EQ(square_set({square(2,4)}),  unattacked_board(square_set({square(2,2), square(3,1)}), 0, 4));
}
