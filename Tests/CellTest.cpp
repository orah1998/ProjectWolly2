//
// Created by yair on 28/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Board.h"

TEST(ClassDeclaration,CellTestValue) {
    Cell c = Cell(0,0);
    EXPECT_TRUE(c.GetValue() == ' ');
}
TEST(ClassDeclaration,CellValueChange) {
    Cell c = Cell(0,0);
    c.ChangeValue('x');
    EXPECT_TRUE(c.GetValue() == 'x');
}