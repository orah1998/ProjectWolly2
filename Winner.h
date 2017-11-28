//
// Or Aharoni
//208250746

#ifndef UNTITLED_WINNER_H
#define UNTITLED_WINNER_H

#include <list>
#include "Player.h"
#include <iostream>
#include "CellCollection.h"
#include "Cell.h"


using namespace std;
class Winner{
public:
    Winner(Player* player11,Player* player22,Cell** cell,int size);
    bool checkWinner();
    void GetCounter(int counter);
    void deleteAll();
private:
    int counter;
    int size;
    Player* player1;
    Player* player2;
    Cell** cells;

};
#endif //UNTITLED_WINNER_H
