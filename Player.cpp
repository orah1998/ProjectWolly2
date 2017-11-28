//
// Or Aharoni
//208250746

#include "Player.h"
#include "Cell.h"

#include <iostream>
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


char Player::getSymbol(){
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

void Player::makeMove(int** offers,int size) {
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
}
