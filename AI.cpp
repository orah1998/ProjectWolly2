//
// Created by or on 23/11/17.
//

#include "AI.h"


AI::AI(int sizeOfBoard,Cell** board,char symbol,string name){
this->board=board;
    this->name=name;
    this->sizeOfBoard=sizeOfBoard;
    this->symbol=symbol;

};


 void AI::makeMove(int **offers,int size) {
    int sizeOfOffers=size;
     int minScore=sizeOfBoard*sizeOfBoard;
     for (int i = 0; i < sizeOfOffers; i++) {
         if(minScore>ScoreOfNextPlay(offers[i][0],offers[i][1])){
         minScore=ScoreOfNextPlay(offers[i][0],offers[i][1]);
             lastPlayedX=offers[i][0];
             lastPlayedY=offers[i][1];
         }
     }
board[lastPlayedX][lastPlayedY].ChangeValue(this->symbol);


}

//checking the score on a play from offers.
int AI::ScoreOfNextPlay(int x,int y){

    Cell** boardCopy=copyBoard(this->board);
    CellCollection cellCollection=CellCollection(boardCopy,sizeOfBoard);
    boardCopy[x][y].ChangeValue(symbol);
    //changing the board according to the move
    cellCollection.RunChecks(symbol,x,y);
    //getting the new offers
    GameLogics logic=GameLogics(boardCopy,sizeOfBoard);
    logic.NextMove(symbol);
    int** tempOffers=logic.GetOffers();
    int maxScore=-sizeOfBoard*sizeOfBoard;
    for (int i = 0; i <logic.GetSizeOfOffers(); i++) {
    if(maxScore<calculateScore(tempOffers[i][0],tempOffers[i][0],boardCopy)){
        maxScore=calculateScore(tempOffers[i][0],tempOffers[i][0],boardCopy);
    }
    }
deleteAll(boardCopy);
return maxScore;



}

int AI::calculateScore(int x,int y, Cell** board){
    char other;
    if(symbol=='O'){
        other='X';
    }
    else{
        other='O';
    }
    Cell** boardCopy=copyBoard(board);
    CellCollection cellCollection=CellCollection(board,sizeOfBoard);
    board[x][y].ChangeValue(other);
    //changing the board according to the move
    cellCollection.RunChecks(other,x,y);
    //getting the new offers
    int scoreOfAI=0,scoreOfPlayer=0;
    for (int i = 0; i < sizeOfBoard; i++) {
        for (int j = 0; j < sizeOfBoard; j++) {
            if (board[i][j].GetValue() == symbol) {
                scoreOfAI++;
            } else {
                scoreOfPlayer++;
            }
        }
    }
    deleteAll(boardCopy);
    return scoreOfPlayer-scoreOfAI;
};




//copying the private 'board' to a new board to make calculations on it
Cell** AI::copyBoard(Cell** board) {

    Cell** boardCopy=new Cell *[sizeOfBoard];
    for (int k = 0; k < sizeOfBoard; k++) {
        boardCopy[k]=(Cell *)malloc(sizeof(Cell) *(sizeOfBoard));
    }


    for (int i = 0; i <sizeOfBoard;i++) {
        for (int j = 0; j < sizeOfBoard; j++) {
            boardCopy[i][j]=Cell(i,j);
            boardCopy[i][j].ChangeValue(board[i][j].GetValue());
        }
    }

return boardCopy;

}



void AI::deleteAll(Cell** board){
    for (int i = 0; i <sizeOfBoard; i++) {
        delete[] board[i];
    }
    delete[] board;

}


int AI::getY() {
    return this->lastPlayedY;

}


int AI::getX() {
    return this->lastPlayedX;

}

char AI::getSymbol(){
    return this->symbol;
}

string AI::GetName(){
    return this->name;
}