//
// Or Aharoni
//208250746

#ifndef UNTITLED_GAMEFLOW_H
#define UNTITLED_GAMEFLOW_H

#include <iostream>
#include "Board.h"
#include "malloc.h"
#include "Player.h"
#include "CellCollection.h"
#include "GameLogics.h"
#include "Winner.h"

class GameFlow{
public:
    GameFlow();
    void run();
    void deleteAll(Board b,GameLogics logic);
private:
};
#endif //UNTITLED_GAMEFLOW_H
