//
// Or Aharoni
//208250746

#include "GameLogics.h"
#include <iostream>
#include "Board.h"
#include "malloc.h"
#include "Player.h"
#include "CellCollection.h"

 GameLogics::GameLogics(Cell **cells,int size) {
    this->cells=cells;
    this->size=size;
    offers=(int **)malloc(sizeof(int*)*size*size);
    this->counter=0;

}

void GameLogics::deleteAll() {
    for (int i = 0; i < counter; i++) {
        delete[] offers[i];
    }
    delete[] offers;


}

int GameLogics::GetSizeOfOffers(){
    return counter;
}

int** GameLogics::GetOffers() {
    return this->offers;
}



void GameLogics::clean(){
    for (int i = 0; i < counter; ++i) {
        delete(offers[i]);
    }
    delete(offers);
    counter=0;
    offers=(int **)malloc(sizeof(int*)*size*size);
}


void GameLogics::NextMove(char symbol) {



    findHorizenal(symbol);
    findHorizenalOpposite(symbol);

    findVertical(symbol);
     findVerticalOpposite(symbol);



    findSlide(symbol);
    findSlideOpposite(symbol);



    findSlide2(symbol);
    findSlideOpposite2(symbol);
}

void GameLogics::PrintOffers(){
    for (int i = 0; i <counter; i++) {
            cout << "(" << offers[i][0] << " , " << offers[i][1] << ")  " ;

    }
    cout <<endl;
}


void GameLogics::addOffer(int x,int y){
    offers[counter]=(int *)malloc(sizeof(int)*2);
    offers[counter][0]=x;
    offers[counter][1]=y;
    counter++;
}


void GameLogics::findHorizenal(char symbol){
    int flag=0;
    int goodX;
    int goodY;
    char other;
    if(symbol=='O'){
        other='X';

    }else{
        other='O';
    }


    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (cells[i][j].GetValue() == ' ') {
                flag = 1;
                goodX=i;
                goodY=j;
            }
            if(flag==1 && cells[i][j].GetValue()==symbol){
                flag=0;
            }

            if (cells[i][j].GetValue() != ' '&&cells[i][j].GetValue() ==other && flag == 1) {
                flag = 2;
            }
            if (flag == 2) {
            if (cells[i][j].GetValue() ==symbol&&cells[i][j].GetValue() !=' ') {
                addOffer(goodX,goodY);
                flag=0;
            }
                if(cells[i][j].GetValue()==' '){
                    flag=1;
                    goodX=i;
                    goodY=j;
                }
        }


        }
        flag=0;
    }


}



void GameLogics::findHorizenalOpposite(char symbol){
    int flag=0;
    int goodX;
    int goodY;
    char other;
    if(symbol=='O'){
        other='X';

    }else{
        other='O';
    }
    for (int i = 1; i < size; i++) {
        for (int j = size-1; j >=1; j--) {
            if (cells[i][j].GetValue() == ' ') {
                flag = 1;
                goodX=i;
                goodY=j;
            }
            if(flag==1 && cells[i][j].GetValue()==symbol){
                flag=0;
            }

            if (cells[i][j].GetValue() != ' '&&cells[i][j].GetValue() ==other && flag == 1) {
                flag = 2;
            }

            if (flag == 2) {
                if (cells[i][j].GetValue() ==symbol&&cells[i][j].GetValue() !=' ') {
                    addOffer(goodX,goodY);
                    flag=0;
                }
                if(cells[i][j].GetValue()==' '){
                    flag=1;
                    goodX=i;
                    goodY=j;
                }
            }


        }
        flag=0;
    }


}






void GameLogics::findVertical(char symbol){
    int flag=0;
    int goodX;
    int goodY;
    char other;
    if(symbol=='O'){
        other='X';

    }else{
        other='O';
    }

    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (cells[j][i].GetValue() == ' ') {
                flag = 1;
                goodX=j;
                goodY=i;
            }
            if(flag==1 && cells[j][i].GetValue()==symbol){
                flag=0;
            }

            if (cells[j][i].GetValue() != ' '&&cells[j][i].GetValue() ==other && flag == 1) {
                flag = 2;
            }
            if (flag == 2) {
                if (cells[j][i].GetValue() ==symbol&&cells[j][i].GetValue() !=' ') {
                    addOffer(goodX,goodY);
                    flag=0;
                }
                if(cells[j][i].GetValue()==' '){
                    flag=1;
                    goodX=i;
                    goodY=j;
                }
            }


        }
        flag=0;
    }


}





void GameLogics::findVerticalOpposite(char symbol){
    int flag=0;
    int goodX;
    int goodY;
    char other;
    if(symbol=='O'){
        other='X';

    }else{
        other='O';
    }
    for (int i = 1; i < size; i++) {
        for (int j = size-1; j > 1; j--) {
            if (cells[j][i].GetValue() == ' ') {
                flag = 1;
                goodX=j;
                goodY=i;
            }
            if(flag==1 && cells[j][i].GetValue()==symbol){
                flag=0;
            }

            if (cells[j][i].GetValue() != ' '&&cells[j][i].GetValue() ==other && flag == 1) {
                flag = 2;
            }
            if (flag == 2) {
                if (cells[j][i].GetValue() ==symbol&&cells[j][i].GetValue() !=' ') {
                    addOffer(goodX,goodY);
                    flag=0;
                }
                if(cells[j][i].GetValue()==' '){
                    flag=1;
                    goodX=i;
                    goodY=j;
                }
            }


        }
        flag=0;
    }
}



void GameLogics::findSlide(char symbol){
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if(cells[i][j].GetValue()==' '){
               if(SlideScan(i,j,symbol)==true){
                addOffer(i,j);
               }
            }
        }
    }
}

bool GameLogics::SlideScan(int x, int y,char symbol) {
    int j=y;
    int flag=0;
    char other;
    if(symbol=='O'){
        other='X';

    }else{
        other='O';
    }
    for (int i =x; i <size; i++) {
        if(j<size){
            if (cells[i][j].GetValue() == ' '&&flag==1) {
                return false;
            }
            if (cells[i][j].GetValue() == ' ') {
                flag = 1;
            }
            if(flag==1 && cells[i][j].GetValue()==symbol){
                flag=0;
            }

            if (cells[i][j].GetValue() != ' '&&cells[i][j].GetValue() ==other && flag == 1) {
                flag = 2;
            }
            if (flag == 2) {
                if (cells[i][j].GetValue() == symbol) {
                    return true;
                }
                if(cells[i][j].GetValue()==' '){
                    return false;
                }
            }
            j=j+1;
        }
    }
    return false;
}





void GameLogics::findSlideOpposite(char symbol){
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if(cells[i][j].GetValue()==' '){
                if(SlideScanOpposite(i,j,symbol)==true){
                    addOffer(i,j);
                }
            }
        }
    }
}





bool GameLogics::SlideScanOpposite(int x, int y,char symbol) {
    int j=y;
    int flag=0;
    char other;
    if(symbol=='O'){
        other='X';

    }else{
        other='O';
    }
    for (int i =x; i <size; i++) {
        if(j>0){
            if (cells[i][j].GetValue() == ' '&&flag==1) {
                return false;
            }
            if (cells[i][j].GetValue() == ' ') {
                flag = 1;
            }
            if(flag==1 && cells[i][j].GetValue()==symbol){
                flag=0;
            }

            if (cells[i][j].GetValue() != ' '&&cells[i][j].GetValue() ==other && flag == 1) {
                flag = 2;
            }
            if (flag == 2) {
                if (cells[i][j].GetValue() == symbol) {
                    return true;
                }
                if(cells[i][j].GetValue()==' '){
                    return false;
                }
            }
            j=j-1;
        }
    }
    return false;
}






void GameLogics::findSlide2(char symbol){
    for (int i = size-1; i > 0; i--) {
        for (int j = 1; j < size; j++) {
            if(cells[i][j].GetValue()==' '){
                if(SlideScan2(i,j,symbol)==true){
                    addOffer(i,j);
                }
            }
        }
    }
}



bool GameLogics::SlideScan2(int x, int y,char symbol) {
    int j=y;
    int flag=0;
    char other;
    if(symbol=='O'){
        other='X';

    }else{
        other='O';
    }
    for (int i =x; i >0; i--) {
        if(j<size){
            if (cells[i][j].GetValue() == ' '&&flag==1) {
                return false;
            }
            if (cells[i][j].GetValue() == ' ') {
                flag = 1;
            }
            if(flag==1 && cells[i][j].GetValue()==symbol){
                flag=0;
            }

            if (cells[i][j].GetValue() != ' '&&cells[i][j].GetValue() ==other && flag == 1) {
                flag = 2;
            }
            if (flag == 2) {
                if (cells[i][j].GetValue() == symbol) {
                    return true;
                }
                if(cells[i][j].GetValue()==' '){
                    return false;
                }
            }
            j=j+1;
        }
    }
    return false;
}





void GameLogics::findSlideOpposite2(char symbol){
    for (int i = size-1; i > 0; i--) {
        for (int j = 1; j < size; j++) {
            if(cells[i][j].GetValue()==' '){
                if(SlideScanOpposite2(i,j,symbol)==true){
                    addOffer(i,j);
                }
            }
        }
    }
}



bool GameLogics::SlideScanOpposite2(int x, int y,char symbol) {
    int j=y;
    int flag=0;
    char other;
    if(symbol=='O'){
        other='X';

    }else{
        other='O';
    }
    for (int i =x; i >0; i--) {
        if(j<size && j>0){
            if (cells[i][j].GetValue() == ' '&&flag==1) {
                return false;
            }
            if (cells[i][j].GetValue() == ' ') {
                flag = 1;
            }
            if(flag==1 && cells[i][j].GetValue()==symbol){
                flag=0;
            }

            if (cells[i][j].GetValue() != ' '&&cells[i][j].GetValue() ==other && flag == 1) {
                flag = 2;
            }
            if (flag == 2) {
                if (cells[i][j].GetValue() == symbol) {
                    return true;
                }
                if(cells[i][j].GetValue()==' '){
                    return false;
                }
            }
            j=j-1;
        }
    }
    return false;
}
