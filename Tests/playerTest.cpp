//
// Created by yair on 28/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Board.h"
#include "../include/Player.h"
#include "../include/GameLogics.h"
/*
TEST(ClassDeclaration,CellTestValue) {
    Board b=Board(8);
    int sizeOfBoard=b.getSizeOfArray();
    Cell** board = b.getArrayOfCells();
    char symbol = 'X';
    string name="comp";
    GameLogics logic=GameLogics(b.getArrayOfCells(),b.getSizeOfArray());
    logic.NextMove('X');
    Player p = Player(b.getArrayOfCells(),'X',"bob");

}
*/
TEST(ClassDeclaration,PlyerValueChange) {
    Cell c = Cell(0,0);
    c.ChangeValue('x');
    EXPECT_TRUE(c.GetValue() == 'x');
}
