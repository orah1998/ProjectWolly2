//
// Or Aharoni
//208250746

#include "CellCollection.h"

using namespace std;

 CellCollection::CellCollection(Cell** arr,int size){
     cells=arr;
     this->size=size;
}

void CellCollection::RunChecks(char symbol,int x,int y){
    HorizenalCheck(symbol,x,y,-1);
    HorizenalCheck(symbol,x,y,1);
    VerticalCheck(symbol,x,y,-1);
    VerticalCheck(symbol,x,y,1);
    SlideScan(symbol,x,y,1,1);
    SlideScan(symbol,x,y,1,-1);
    SlideScan(symbol,x,y,-1,1);
    SlideScan(symbol,x,y,-1,-1);
}


void CellCollection::HorizenalChange(int x, int y, int x2, int y2) {

    char symbol;
    if (this->cells[x][y].GetValue() == 'O') {
        symbol = 'O';
    } else { symbol = 'X'; }
    if (y < y2) {

    for (int i = y; i <= y2; i++) {
        this->cells[x][i].ChangeValue(symbol);
    }
}
if(y2<y){
    for (int i = y2; i <= y; i++) {
        this->cells[x][i].ChangeValue(symbol);
    }


}


}

//checks the board to right and to the left
bool CellCollection::HorizenalCheck(char symbol,int x,int y,int dir){
    int flag=0;
    char other;
    if(symbol=='O'){
        other='X';
    }
    else{
        other='O';
    }

    int j=y;
        while(j>0 && j<size){

            if(cells[x][j].GetValue()==other){
                flag=1;
            }
            if(cells[x][j].GetValue()==' '){
                flag=0;
                return false;
            }
            if(cells[x][j].GetValue()==symbol&&flag==1) {
                    HorizenalChange(x,y,x,j);
                    flag=1;
                }
            j+=dir;
            }
    }











void CellCollection::VerticalChange(int x, int y, int x2, int y2) {

    char symbol;
    if(this->cells[x][y].GetValue()=='O'){
        symbol='O';
    } else{ symbol='X';}

    if(x<x2) {
        for (int i = x; i <= x2; i++) {
            this->cells[i][y].ChangeValue(symbol);
        }
    }
    if(x2<x) {
        for (int i = x2; i <= x; i++) {
            this->cells[i][y].ChangeValue(symbol);
        }
    }

}


bool CellCollection::VerticalCheck(char symbol,int x,int y,int dir){
    int flag=0;
    int indexX;
    int indexY;
    char other;
    if(symbol=='O'){
        other='X';
    }
    else{
        other='O';
    }

    int j=x;
    while(j>0 && j<size){

        if(cells[j][y].GetValue()==other){
            flag=1;
        }
        if(cells[j][y].GetValue()==' '){
            flag=0;
            return false;
        }
        if(cells[j][y].GetValue()==symbol&&flag==1) {
            VerticalChange(x,y,j,y);
            flag=1;
        }
        j+=dir;
    }
}
//**********************************SLIDES ***********************************

void CellCollection::SlideScan(char symbol,int x,int y,int dirI,int dirJ){
    int j=y;
    int i =x;
    int flag=0;
    int indexX;
    int indexY;
    char other;
    if(symbol=='O'){
        other='X';
    }
    else{
        other='O';
    }

    while(j>0 && j<size && i>0 && i<size){

        if(cells[i][j].GetValue()==other){
            flag=1;
        }
        if(cells[i][j].GetValue()==' '){
            flag=0;
            return;
        }
        if(cells[i][j].GetValue()==symbol&&flag==1) {
            SlideChange(symbol,x,y,i,j);
            flag=1;
        }
        j+=dirJ;
        i+=dirI;
    }

}

void CellCollection::SlideChange(char symbol,int x,int y,int x2,int y2) {

    if(x2>x&&y2>y) {
        int j=y+1;
        for (int i = x + 1; i <= x2; i++) {
            cells[i][j].ChangeValue(symbol);
            if(j<size){
            j++;
            }
        }
    }

    if(x>x2 && y2>y) {
        int j=y+1;
        for (int i = x-1; i > x2; i--) {
            cells[i][j].ChangeValue(symbol);
            if(j<size) {
                j++;
            }
        }
    }

    if(x2>x && y2<y) {
        int j=y-1;
        for (int i = x + 1; i <= x2; i++) {
            cells[i][j].ChangeValue(symbol);
            if(j>0) {
                j--;
            }
        }
    }

    if(x>x2 && y2<y) {
        int j=y-1;
        for (int i = x-1; i > x2; i--) {
            cells[i][j].ChangeValue(symbol);
            if(j>0) {
                j--;
            }
        }
    }



}


