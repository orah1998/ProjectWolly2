//
// Or Aharoni
//208250746

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include <string>
#include <malloc.h>
#include <iostream>
#include "Cell.h"
using namespace std;
//here im handeling each player.
class Player {
public :
    Player();
    virtual void makeMove(int** offers,int size);
    Player(Cell** cellArray,char symbol,string nickname);
    virtual char getSymbol();
    bool IsFound(int** offers,int x,int y);
    virtual string GetName();
    virtual int getX();
    virtual int getY();
        private:
    int indexX;
    int indexY;
    string name;
    int counter;
    Cell** cells;
protected:
    char symbol;

};
#endif //UNTITLED_PLAYER_H
