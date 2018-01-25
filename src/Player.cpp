
//
// Or Aharoni
//208250746

#include "../include/Player.h"
#include "../include/Cell.h"

#include <iostream>
#include <cstring>
#include <sstream>

#define SIZEOF 2000
using namespace std;


Player::Player(){

}

Player::Player(Cell** cellArray ,char symbol,string nickname){
    cells=cellArray;
    this->name=nickname;
    this->symbol=symbol;
}

string Player::GetName(){
    return name;
}


char Player::getSymbol()
{
    return this->symbol;
}

bool Player::IsFound(int** offers,int x,int y){
    for (int i = 0; i <counter; i++) {
        if(offers[i][0]==x&&offers[i][1]==y){ ;
        return true;
        }
    }
    return false;

}

int Player::getX(){
    return indexX;
}

int Player::getY(){
    return indexY;
}

char* Player::makeMove(int** offers,int size) {
    this->counter = size;
    cout << this->name << "'s turn : " << endl;


    char* command;
    command = (char*)calloc(1,SIZEOF);
//cmd is the command
    char cmd[SIZEOF];
    cin >> cmd;

    //x is the x index
    char xvalue[SIZEOF];
    cin >> xvalue;

    //x is the y index
    char yvalue[SIZEOF];
    cin >> yvalue;
    strcat(command, cmd);
    strcat(command, " ");
    strcat(command, xvalue);
    strcat(command, " ");
    strcat(command, yvalue);

    stringstream geek;
    geek << xvalue;
    int x = 0;
    geek >> x;

    stringstream geek2;
    geek2 << yvalue;
    int y = 0;
    geek2 >> y;

    while (IsFound(offers, x, y) == false || this->cells[x][y].GetValue() == 'O' ||
           this->cells[x][y].GetValue() == 'X' || x == 0 || y == 0||(strcmp(cmd,"play") != 0)) {
        cout << this->name << ":invalid choice , choose again : " << endl;


        char command[SIZEOF];

        stringstream str(command);
        //cmd is the command
        char cmd[SIZEOF];
        cin >> cmd;

        //x is the x index
        char xvalue[SIZEOF];
        cin >> xvalue;

        //x is the y index
        char yvalue[SIZEOF];
        cin >> yvalue;

        strcpy(command, cmd);
        strcat(command, " ");
        strcat(command, xvalue);
        strcat(command, " ");
        strcat(command, yvalue);

        stringstream geek(xvalue);
        int x = 0;
        geek >> x;

        stringstream geek2(yvalue);
        int y = 0;
        geek2 >> y;


    }
    this->cells[x][y].ChangeValue(symbol);
    indexX = x;
    indexY = y;

    return command;
}
