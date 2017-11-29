//
// Created by or on 29/11/17.
//

#include <gtest/gtest.h>
#include "../Board.h"
#include "../CellCollection.h"
#include "../GameLogics.h"

//a test to check the offers that we should get after playing the first turn.
TEST(ClassDeclaration,GameLogicsTest) {
    Board b = Board(8);
    CellCollection cellCollection = CellCollection(b.getArrayOfCells(), b.getSizeOfArray());
    b.getArrayOfCells()[5][3].ChangeValue('O');
    cellCollection.RunChecks('O', 5, 3);
    GameLogics logic=GameLogics(b.getArrayOfCells(),b.getSizeOfArray());
    logic.NextMove('X');
    EXPECT_TRUE(logic.GetOffers()[0][0]==4&&logic.GetOffers()[0][1]==3);
    EXPECT_TRUE(logic.GetOffers()[1][0]==6&&logic.GetOffers()[1][1]==5);
    EXPECT_TRUE(logic.GetOffers()[2][0]==6&&logic.GetOffers()[2][1]==3);
}
