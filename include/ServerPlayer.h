//
// Created by or on 07/12/17.
//

#include <string>
#include <malloc.h>
#include <iostream>
#include "Cell.h"
#include "Client.h"
#include "Player.h"

#ifndef UNTITLED_SERVERPLAYER_H
#define UNTITLED_SERVERPLAYER_H

using namespace std;
//here im handeling each player.
class ServerPlayer : public Player{
public :
    ServerPlayer();
    void makeMove(int** offers,int size);
    ServerPlayer(Cell** cellArray,char symbol,string nickname);
    char getSymbol();
    bool IsFound(int** offers,int x,int y);
    string GetName();
    int getX();
    int getY();
    void sendToServer(int x,int y);
    Cell readFromServer();
    int firstReadFromServer();

private:
    int indexX;
    int indexY;
    string name;
    int counter;
    Cell** cells;
protected:
    char symbol;
    Client client=Client("127.0.0.1",8792);

};
#endif //UNTITLED_SERVERPLAYER_H
