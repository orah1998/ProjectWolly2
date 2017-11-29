//
// Or Aharoni
//208250746

#include <iostream>
#include "../include/Board.h"
#include "malloc.h"
#include "../include/Player.h"
#include "../include/CellCollection.h"
#include "../include/GameLogics.h"
#include "../include/Winner.h"
#include "../include/GameFlow.h"
#include "../include/AI.h"


GameFlow::GameFlow(){

    }

void GameFlow::deleteAll(Board b,GameLogics logic) {
    b.deleteAll();
    logic.deleteAll();
}

void GameFlow::run() {
    int x;
    cout <<"Choose size : "<< endl ;
    cin >> x;
    string name;
    string name2;
    Board b(x);
    CellCollection cellCollection=CellCollection(b.getArrayOfCells(),b.getSizeOfArray());
    GameLogics logic=GameLogics(b.getArrayOfCells(),b.getSizeOfArray());
    cout<<"choose player1's name:"<<endl;
    cin >>name;
    Player player1=Player(b.getArrayOfCells(),'O',name);

    cout<<"choose player2's name:"<<endl;
    cin >>name2;
    Player player2=Player(b.getArrayOfCells(),'X',name2);
    //Player player2=Player(b.getArrayOfCells(),'X',name2);
    Winner checker=Winner(&player1,&player2,b.getArrayOfCells(),b.getSizeOfArray());
    b.print();

//flag is which player is currently playing
    int flag=1;
    //if flag==2 it means that the ganme has ended
    while(flag!=2){
        if(flag==1) {
            logic.NextMove(player1.getSymbol());
            checker.GetCounter(logic.GetSizeOfOffers());
            if (checker.checkWinner() == true) {
                flag = 2;
            } else {
                logic.PrintOffers();
                player1.makeMove(logic.GetOffers(),logic.GetSizeOfOffers());
                logic.clean();
                flag = 0;
                cellCollection.RunChecks(player1.getSymbol(),player1.getX(),player1.getY());
            }
        }
        else{
            logic.NextMove(player2.getSymbol());
            checker.GetCounter(logic.GetSizeOfOffers());
            if (checker.checkWinner() == true) {
                flag = 2;
            } else {
                logic.PrintOffers();
                player2.makeMove(logic.GetOffers(),logic.GetSizeOfOffers());
                logic.clean();
                flag = 1;
                cellCollection.RunChecks(player2.getSymbol(),player2.getX(),player2.getY());
            }
        }

        b.print();

    }

deleteAll(b,logic);
}
