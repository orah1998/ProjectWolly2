//
// Created by or on 07/12/17.
//

#include "../include/ServerPlayer.h"
//
// Or Aharoni
//208250746

#include "../include/Player.h"
#include "../include/Cell.h"

#include <iostream>
using namespace std;


ServerPlayer::ServerPlayer(){

}

ServerPlayer::ServerPlayer(Cell** cellArray ,char symbol,string nickname){
    cells=cellArray;
    this->name=nickname;
    this->symbol=symbol;
    this->client.connectToServer();
}

string ServerPlayer::GetName(){
    return name;
}


char ServerPlayer::getSymbol()
{
    return this->symbol;
}

bool ServerPlayer::IsFound(int** offers,int x,int y){
    for (int i = 0; i <counter; i++) {
        if(offers[i][0]==x&&offers[i][1]==y){ ;
            return true;
        }
    }
    return false;

}

int ServerPlayer::getX(){
    return indexX;
}

int ServerPlayer::getY(){
    return indexY;
}

void ServerPlayer::makeMove(int** offers,int size) {
    this->counter=size;
    cout <<this->name <<"'s turn : "<< endl ;
    int x,y;
    cin >> x ;
    cin >> y ;
    while(IsFound(offers,x,y)==false||this->cells[x][y].GetValue()=='O' ||this->cells[x][y].GetValue()=='X'||x==0||y==0 ){
        cout <<this->name <<":invalid choice , choose again : "<< endl ;
        cin >> x ;
        cin >> y ;
    }
    this->cells[x][y].ChangeValue(symbol);
    indexX=x;
    indexY=y;
    //now to server side
}



void ServerPlayer::sendToServer(int x,int y) {
 client.sendExercise(x,y);
}

Cell ServerPlayer::readFromServer() {
    Cell c=client.readFromServer();
    cout<<c.getY()<<"  "<<c.getX()<<endl;
    this->cells[c.getX()][c.getY()].ChangeValue(symbol);
    indexX=c.getX();
    indexY=c.getY();
}


int ServerPlayer::firstReadFromServer(){
    return this->client.firstReadFromServer();
}