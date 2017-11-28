//
// Or Aharoni
//208250746

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include <string>
#include <malloc.h>
#include <iostream>
#include "Cell.h"

using namespace std;

class Board{
public :
    Board(int x);
    void deleteAll();
    void print();
    Cell** getArrayOfCells();
    int getSizeOfArray();
private :
    int x_;
    Cell** arr_;

};

#endif //UNTITLED_BOARD_H