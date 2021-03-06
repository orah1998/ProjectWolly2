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
    char* makeMove(int** offers,int size);
    ServerPlayer(Cell** cellArray,char symbol,string nickname,Client client);
    char getSymbol();
    bool IsFound(int** offers,int x,int y);
    string GetName();
    int getX();
    int getY();
    int startGame();
        void sendToServer(char move[]);
    Cell readFromServer();
    int firstReadFromServer();
    void changeFacts(char symbol,string name);

private:
    int indexX;
    int indexY;
    string name;
    int counter;
    Cell** cells;
protected:
    char symbol;
    Client client=Client();

};
#endif //UNTITLED_SERVERPLAYER_H
