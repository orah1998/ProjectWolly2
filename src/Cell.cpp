//
// Or Aharoni
//208250746


#include "../include/Cell.h"


#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;


Cell::Cell(int x,int y){
    x_=x;
    y_=y;
    value=' ';
}
char Cell::GetValue() {
    return value;
}

void Cell::ChangeValue(char symbol) {
    value=symbol;
}

int Cell::getX(){
    return x_;
}

int Cell::getY(){
    return y_;
}


char* Cell::cellToString(){
    char* ret;
    ret="%d %d",this->x_,this->y_;

    return ret;
}

void Cell::StringToCell(string answer){
    int index;
    for (int i = 0; i <answer.length(); ++i) {
    if(answer[i]==' '){
        index=i;
    }
    }
    this->x_=atoi(answer.substr(0, index));
    this->y_=atoi(answer.substr(++index, answer.length() - (index-1)));
}