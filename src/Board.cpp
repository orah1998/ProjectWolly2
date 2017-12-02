//
// Or Aharoni
//208250746


#include "../include/Board.h"
#include "../include/Cell.h"
#include <iostream>
using namespace std;

void Board::deleteAll(){
    for (int i = 0; i < x_; i++) {
        delete[] arr_[i];
    }
    delete[] arr_;

}

int Board::getSizeOfArray(){
    return x_;
}

Cell** Board::getArrayOfCells(){
    return this->arr_;
}



Board::Board(int y){
    x_=y+1;

    arr_=new Cell *[y];
    for (int k = 0; k < x_; k++) {
        arr_[k]=(Cell *)malloc(sizeof(Cell) *(x_));
    }


    for (int i = 0; i < x_;i++) {

        for (int j = 0; j <x_ ; j++) {
            arr_[i][j]=Cell(i,j);
        }
    }


    arr_[x_/2][x_/2].ChangeValue('O');
    arr_[1+(x_/2)][x_/2].ChangeValue('X');
    arr_[1+(x_/2)][1+(x_/2)].ChangeValue('O');
    arr_[x_/2][1+(x_/2)].ChangeValue('X');

}





void Board::print(){
    for (int i = 0; i <x_ ; i++) {
        if(i==0){
            for (int j = 0; j <x_ ;j++) {
                cout << "| "<< j << " | " ;

            }
            cout << endl;
            cout <<"-----------------------------------------------------"<< endl ;
        }
        else{
            for (int j = 0; j <x_ ;j++) {
                if(j!=0){
                    cout << "| "<< arr_[i][j].GetValue() << " | " ;
                } else {
                    cout << "| "<< i << " | " ;
                }

            }
            cout << endl;
            cout <<"-----------------------------------------------------"<< endl ;
        }
    }

}


bool Board::operator==(const Board &board) const {
    for (int i = 0; i < this->x_; ++i) {
        for (int j = 0; j < this->x_; ++j) {
            if(this->arr_[i][j].GetValue() != board.arr_[i][j].GetValue()){
                return false;
            }
        }
    }
    return true;
}