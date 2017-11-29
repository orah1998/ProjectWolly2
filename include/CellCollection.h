//
// Or Aharoni
//208250746

#ifndef UNTITLED_CELLCOLLECTION_H
#define UNTITLED_CELLCOLLECTION_H

#include <list>

#include <iostream>
#include "Cell.h"
#include "Board.h"
//here im handeling everything changing the cells.
//this class changes the required cells according to the player's move.

using namespace std;
class CellCollection {
public :
    CellCollection(Cell** arr,int size);
    void RunChecks(char symbol,int x,int y);

    void HorizenalChange(int x,int y,int x2,int y2);
    bool HorizenalCheck(char symbol,int x,int y,int dir);

    void VerticalChange(int x,int y,int x2,int y2);
    bool VerticalCheck(char symbol,int x,int y,int dir);


    void   SlideScan(char symbol,int x,int y,int dirI,int dirJ);
    void   SlideChange(char symbol,int x,int y,int x2,int y2);


private :
    int size;
    Cell** cells;
};



#endif //UNTITLED_CELLCOLLECTION_H
