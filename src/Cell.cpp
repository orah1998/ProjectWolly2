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

    int index=0;
    for (int i = 0; i < answer.length(); i++) {
        if(answer[i]==' '){
            index=i;
            break;
        }
    }



    char* fnum=new char[index+1];
    char* snum=new char[answer.length()-index];
    copy(answer.begin(),answer.end()-index,fnum);
    printf("%s",fnum);
    copy(answer.end()-index,answer.end(),snum);
    printf("%s",snum);

    this->x_=atoi(fnum);
    this->y_=atoi(snum);
    delete(fnum);
    delete(snum);
}