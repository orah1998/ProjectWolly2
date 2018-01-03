// or aharoni 208250746

#include <iostream>
#include "../include/Board.h"
#include "malloc.h"
#include "../include/Player.h"
#include "../include/CellCollection.h"
#include "../include/GameLogics.h"
#include "../include/Winner.h"
#include "../include/GameFlow.h"
//#include <gtest/gtest.h>
//#include <gmock/gmock.h>


using namespace std;


int main(int argc,char* argv[]) {
    try{
  GameFlow gameFlow=GameFlow();
    gameFlow.run();
}catch(const char* message){
        cout<<message<<endl;
    }

   return 0;
}
