//
// Created by or on 23/11/17.
//

#ifndef UNTITLED_AI_H
#define UNTITLED_AI_H

#include <iostream>
#include "Board.h"
#include "malloc.h"
#include "Player.h"
#include "CellCollection.h"
#include "GameLogics.h"
#include "Winner.h"
#include "GameFlow.h"
class AI : public Player {
public:
AI(int sizeOfBoard, Cell** board,char symbol,string name);
    Cell** copyBoard(Cell** board);
    int ScoreOfNextPlay(int x,int y);
    void makeMove(int** offers,int size);
    int calculateScore(int x,int y, Cell** board);
    void deleteAll(Cell** board);
    int getX();
    int getY();
    char getSymbol();
    string GetName();
private:
    string name;
    int sizeOfBoard;
    Cell** board;
    int lastPlayedX;
    int lastPlayedY;
    char symbol;
};
#endif //UNTITLED_AI_H
