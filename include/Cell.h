//
// Or Aharoni
//208250746

#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H
#include <string>
#include <malloc.h>
#include <iostream>
using namespace std;

class Cell{
public :
    Cell(int x ,int y);
    void ChangeValue(char symbol);
    char GetValue();
private :
    int x_;
    int y_;
    char value;

};
#endif //UNTITLED_CELL_H
