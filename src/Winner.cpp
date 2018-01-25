//
// Or Aharoni
//208250746

#include <list>
#include "../include/Player.h"
#include <iostream>
#include "../include/CellCollection.h"
#include "../include/Cell.h"
#include "../include/Winner.h"


Winner::Winner(Player* player11, Player* player22,Cell** cells,int size) {

    player1 = player11;
    player2 = player22;
    this->cells=cells;
    this->size=size;
}

void Winner::deleteAll() {
    delete(player1);
    delete(player2);
}



void Winner::GetCounter(int counter){
this->counter=counter;
}


bool Winner::checkWinner() {
    int xCount=0;
    int oCount=0;
if(counter==0){
    for (int i = 0; i < size; i++) {
        for (int j =0 ; j < size; j++) {
            if(cells[i][j].GetValue()=='O'){
                oCount++;
            }
            else{
                xCount++;
            }
        }
    }

    if(oCount>xCount){
        cout<<"Oi has won !"<<endl;
    }
    if(oCount<xCount){
        cout<<"Xi has won !"<<endl;
    }
    if(oCount==xCount){
        cout<<" its a TIE !"<<endl;
    }
return true;
}
    return false;
}
