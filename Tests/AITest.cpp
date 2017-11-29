//
// Created by yair on 28/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Board.h"
#include "../AI.h"


TEST(ClassDeclaration,TestOfAIMoves) {
    /*
     * this test check if the AI choose the same step in the same looking board
     */

    //initialize AI
    Board b=Board(8);
    int sizeOfBoard=b.getSizeOfArray();
    Cell** board = b.getArrayOfCells();
    char symbol = 'x';
    string name="comp";
    GameLogics logic=GameLogics(b.getArrayOfCells(),b.getSizeOfArray());
    AI comp = AI(sizeOfBoard,board,symbol,name);
    comp.makeMove(logic.GetOffers(),logic.GetSizeOfOffers());

    //initialize AI_check
    Board b_check=Board(8);
    int sizeOfBoard_check=b_check.getSizeOfArray();
    Cell** board_check=b_check.getArrayOfCells();
    char symbol_check = 'x';
    string name_check = "comp";
    GameLogics logic_check=GameLogics(b_check.getArrayOfCells(),b_check.getSizeOfArray());
    AI comp_check = AI(sizeOfBoard_check,board_check,symbol_check,name_check);
    comp_check.makeMove(logic_check.GetOffers(),logic_check.GetSizeOfOffers());

    //check if the AI and he AI_check are did the same smart step
    EXPECT_EQ(board,board_check);

    b.deleteAll();
    b_check.deleteAll();
    logic.deleteAll();
    logic_check.deleteAll();
    comp.deleteAll(board);
    comp_check.deleteAll(board_check);
}

TEST(ClassDeclaration,TestOfAIScore) {
    /*
     * this test check if the AI function calculate score is good
     */

    //initialize AI
    Board b=Board(8);
    int sizeOfBoard=b.getSizeOfArray();
    Cell** board = b.getArrayOfCells();
    char symbol = 'x';
    string name="comp";
    GameLogics logic=GameLogics(b.getArrayOfCells(),b.getSizeOfArray());
    AI comp = AI(sizeOfBoard,board,symbol,name);
    comp.makeMove(logic.GetOffers(),logic.GetSizeOfOffers());

    //initialize AI_check
    Board b_check=Board(8);
    int sizeOfBoard_check=b_check.getSizeOfArray();
    Cell** board_check=b_check.getArrayOfCells();
    char symbol_check = 'x';
    string name_check = "comp";
    GameLogics logic_check=GameLogics(b_check.getArrayOfCells(),b_check.getSizeOfArray());
    AI comp_check = AI(sizeOfBoard_check,board_check,symbol_check,name_check);
    comp_check.makeMove(logic_check.GetOffers(),logic_check.GetSizeOfOffers());

    //check if the AI and he AI_check are did the same smart step
    EXPECT_EQ(board,board_check);

    b.deleteAll();
    b_check.deleteAll();
    logic.deleteAll();
    logic_check.deleteAll();
    comp.deleteAll(board);
    comp_check.deleteAll(board_check);
}