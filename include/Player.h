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
void makeMove(int** offers,int size);
    Player(Cell** cellArray,char symbol,string nickname);
    char getSymbol();
    bool IsFound(int** offers,int x,int y);
    string GetName();
    int getX();
    int getY();
        private:
    char symbol;
    int indexX;
    int indexY;
    string name;
    int counter;
    Cell** cells;
};
#endif //UNTITLED_PLAYER_H
