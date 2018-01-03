//
// Or Aharoni
//208250746

#include <iostream>
#include <fstream>
#include "../include/Board.h"
#include "malloc.h"
#include "../include/Player.h"
#include "../include/CellCollection.h"
#include "../include/GameLogics.h"
#include "../include/Winner.h"
#include "../include/GameFlow.h"
#include "../include/AI.h"
#include "../include/ServerPlayer.h"


GameFlow::GameFlow(){

    }

int GameFlow::selection(){
    cout<<"Choose an opponent type:"<<endl;
    cout<<"1. a human local player"<<endl;
    cout<<"2. an AI player"<<endl;
    cout<<"3. a remote player"<<endl;
    int choose;
    cin>>choose;
    if(choose==1){return 1;}
    if(choose==2){return 2;}
    if(choose==3){return 3;}
    else{
        cout<<"invalid input"<<endl;
        return this->selection();
    }
}



void GameFlow::deleteAll(Board b,GameLogics logic) {
    b.deleteAll();
    logic.deleteAll();
}

void GameFlow::run() {
    int x;
    cout << "Choose size : " << endl;
    cin >> x;
    Board b(x);
    CellCollection cellCollection = CellCollection(b.getArrayOfCells(), b.getSizeOfArray());
    GameLogics logic = GameLogics(b.getArrayOfCells(), b.getSizeOfArray());
    Player *player1;

    Player *player2;
    int choose = this->selection();
    if (choose == 1) {
        player1=new Player(b.getArrayOfCells(), 'O',"Oi");
        player2 = new Player(b.getArrayOfCells(), 'X', "Xi");

    }
    if (choose == 2) {
        player1=new Player(b.getArrayOfCells(), 'O',"Oi");
        player2 = new AI(b.getSizeOfArray(), b.getArrayOfCells(), 'X', "comp");
    }


    Winner checker = Winner(player1, player2, b.getArrayOfCells(), b.getSizeOfArray());
    b.print();


    if (choose == 1 || choose == 2) {


//flag is which player is currently playing
        int flag = 1;
        //if flag==2 it means that the ganme has ended
        while (flag != 2) {
            if (flag == 1) {
                logic.NextMove(player1->getSymbol());
                checker.GetCounter(logic.GetSizeOfOffers());
                if (checker.checkWinner() == true) {
                    flag = 2;
                } else {
                    logic.PrintOffers();
                    player1->makeMove(logic.GetOffers(), logic.GetSizeOfOffers());
                    logic.clean();
                    flag = 0;
                    cellCollection.RunChecks(player1->getSymbol(), player1->getX(), player1->getY());
                }
            } else {
                logic.NextMove(player2->getSymbol());

                checker.GetCounter(logic.GetSizeOfOffers());
                if (checker.checkWinner() == true) {
                    flag = 2;
                } else {
                    logic.PrintOffers();
                    player2->makeMove(logic.GetOffers(), logic.GetSizeOfOffers());
                    logic.clean();
                    flag = 1;
                    cellCollection.RunChecks(player2->getSymbol(), player2->getX(), player2->getY());
                }
            }

            b.print();

        }

        deleteAll(b, logic);
        delete player2;
    } else {

        //defining a new client
        std::ifstream file("../src/client_definitions");
        string ip;
        int port;
        file >> ip;
        file >> port;

        const char* ip2=ip.c_str();
        Client client=Client(ip2,port);
        ServerPlayer splayer =ServerPlayer(b.getArrayOfCells(), 'X', "Xi",client);
        int flag=splayer.firstReadFromServer();
        if(flag==0){
            player1 =new Player(b.getArrayOfCells(), 'O',"Oi");
        }
        if(flag==1){
            player1 =new Player(b.getArrayOfCells(), 'X',"Xi");
            splayer.changeFacts('O',"Oi");
        }


        Winner checker = Winner(player1, &splayer, b.getArrayOfCells(), b.getSizeOfArray());
//flag is which player is currently playing
//if flag==2 it means that the game has ended
        while (flag != 2) {
            if (flag == 0) {
                logic.NextMove(player1->getSymbol());
                checker.GetCounter(logic.GetSizeOfOffers());
                if (checker.checkWinner() == true) {
                    flag = 2;
                    splayer.sendToServer(-1,-1);
                } else {
                    logic.PrintOffers();
                    if (logic.GetSizeOfOffers() != 0) {
                        player1->makeMove(logic.GetOffers(), logic.GetSizeOfOffers());
                        logic.clean();
                        flag = 1;
                        cellCollection.RunChecks(player1->getSymbol(), player1->getX(), player1->getY());
                        //sends the last move to the other player(through the server)
                        splayer.sendToServer(player1->getX(), player1->getY());
                    }else{
                        //tells the server that this player has no available moves!
                        splayer.sendToServer(-2, -2);
                        flag=1;
                    }
                }

            }
            else{

                logic.NextMove(splayer.getSymbol());
                checker.GetCounter(logic.GetSizeOfOffers());
                if (checker.checkWinner() == true) {
                    flag = 2;
                    splayer.sendToServer(-1,-1);
                } else {
                    //reads the remote player's move
                    splayer.readFromServer();
                    if(splayer.getX()==-2&& splayer.getY()==-2){
                        cout<<splayer.getSymbol()<<" played no moves!"<<endl;
                        flag=0;
                    }else{
                    cout<<splayer.getSymbol()<<" played: ("<<splayer.getX()<<","<<splayer.getY()<<")"<<endl;
                    logic.clean();
                    flag = 0;
                    //changes the board according to the player's move
                    cellCollection.RunChecks(splayer.getSymbol(), splayer.getX(), splayer.getY());
                    }
                }
            }
            b.print();

        }

    }
}