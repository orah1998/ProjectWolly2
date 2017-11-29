//
// Created by yair on 28/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Board.h"
#include "../AI.h"


TEST(ClassDeclaration,BoardTestOperator) {
   Board b=Board(8);
    EXPECT_TRUE(b.operator==(b));
    b.deleteAll();
}
TEST(ClassDeclaration,SizeOfBoard) {
    Board b=Board(8);
    EXPECT_EQ(b.getSizeOfArray() - 1,8);
    b.deleteAll();
}
TEST(ClassDeclaration,BoardInitilaizeTest) {
    Board b=Board(8);
    Cell** board = b.getArrayOfCells();
    bool check = true;
    int xCount = 0,oCount = 0;
    for (int i = 0; i < b.getSizeOfArray(); ++i) {
        for (int j = 0; j < b.getSizeOfArray(); ++j) {
            if(board[i][j].GetValue() != ' '){
                if(board[i][j].GetValue() == 'X'){
                    xCount++;
                }else if(board[i][j].GetValue() == 'O'){
                    oCount++;
                }else{
                    check = false;
                }
            }
        }
    }
    if(xCount != 2 || oCount != 2){
        check = false;
    }
    EXPECT_TRUE(check);
    b.deleteAll();
}