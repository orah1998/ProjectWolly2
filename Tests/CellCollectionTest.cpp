//
// Created by or on 27/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/CellCollection.h"
#include "../include/Player.h"
#include "../include/GameLogics.h"



TEST(ClassDeclaration,CellCollectionTest){
    Board b=Board(8);
CellCollection cellCollection=CellCollection(b.getArrayOfCells(),b.getSizeOfArray());
    b.getArrayOfCells()[4][3].ChangeValue('X');
    cellCollection.RunChecks('X',4,3);
    //expected to tell us that [4,3],[4,4],[4,5] are X and the rest are NOT!(blanks)
     for (int i = 3; i < 6; i++) {
        EXPECT_EQ(b.getArrayOfCells()[4][i].GetValue(),'X');
    }

   Board b1=Board(8);
    cellCollection=CellCollection(b1.getArrayOfCells(),b1.getSizeOfArray());
    b1.getArrayOfCells()[3][4].ChangeValue('X');
    cellCollection.RunChecks('X',3,4);
    //expected to tell us that [3,4],[4,4],[5,4] are X and the rest are NOT!(blanks)
    for (int j  = 3; j < 6; j++) {
        EXPECT_EQ(b1.getArrayOfCells()[j][4].GetValue(),'X');
    }


    Board b2=Board(8);
    cellCollection=CellCollection(b2.getArrayOfCells(),b2.getSizeOfArray());
    b2.getArrayOfCells()[4][3].ChangeValue('X');
    cellCollection.RunChecks('X',4,3);
    b2.getArrayOfCells()[3][3].ChangeValue('O');
    cellCollection.RunChecks('O',3,3);
    for (int j  = 3; j < 6; j++) {
        EXPECT_EQ(b2.getArrayOfCells()[j][j].GetValue(),'O');
    }


    b.deleteAll();
    b1.deleteAll();
    b2.deleteAll();

}


TEST(ClassDeclaration,CellCollectionTestReverse){
    //now we will check what happens when it is placed on the opposite side
    Board b=Board(8);
    CellCollection cellCollection=CellCollection(b.getArrayOfCells(),b.getSizeOfArray());
    b.getArrayOfCells()[5][6].ChangeValue('X');
    cellCollection.RunChecks('X',5,6);
    //expected to tell us that [4,3],[4,4],[4,5] are X and the rest are NOT!(blanks)
    for (int i = 4; i < 7; i++) {
        EXPECT_EQ(b.getArrayOfCells()[5][i].GetValue(),'X');
    }

    Board b1=Board(8);
    cellCollection=CellCollection(b1.getArrayOfCells(),b1.getSizeOfArray());
    b1.getArrayOfCells()[6][5].ChangeValue('X');
    cellCollection.RunChecks('X',6,5);
    //expected to tell us that [3,4],[4,4],[5,4] are X and the rest are NOT!(blanks)
    for (int j  = 4; j < 7; j++) {
        EXPECT_EQ(b1.getArrayOfCells()[j][5].GetValue(),'X');
    }


    Board b2=Board(8);
    cellCollection=CellCollection(b2.getArrayOfCells(),b2.getSizeOfArray());
    b2.getArrayOfCells()[5][6].ChangeValue('X');
    cellCollection.RunChecks('X',5,6);
    b2.getArrayOfCells()[6][6].ChangeValue('O');
    cellCollection.RunChecks('O',6,6);
    for (int j  = 4; j < 7; j++) {
        EXPECT_EQ(b2.getArrayOfCells()[j][j].GetValue(),'O');
    }


    b.deleteAll();
    b1.deleteAll();
    b2.deleteAll();

}