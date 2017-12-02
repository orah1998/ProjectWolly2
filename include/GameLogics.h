//
// Or Aharoni
//208250746

#ifndef UNTITLED_GAMELOGICS_H
#define UNTITLED_GAMELOGICS_H

#include <list>

#include <iostream>
#include "CellCollection.h"
#include "Cell.h"

//here is the game logic , here im checking for the next moves and returns
//them to the player to choose from.
using namespace std;
class GameLogics {
public :
    GameLogics(Cell** cells,int size);
    void deleteAll();

void NextMove(char symbol);
  void  addOffer(int x,int y);
    int** GetOffers();
    int GetSizeOfOffers();
    void PrintOffers();
    void clean();


    void findVertical(char symbol);
    void findVerticalOpposite(char symbol);

    void findHorizenal(char symbol);
    void findHorizenalOpposite(char symbol);

    void findSlide(char symbol);
    bool SlideScan(int x,int y,char symbol);
    void findSlideOpposite(char symbol);
  bool SlideScanOpposite(int x,int y,char symbol);


    void findSlide2(char symbol);
    bool SlideScan2(int x,int y,char symbol);
    void findSlideOpposite2(char symbol);
    bool SlideScanOpposite2(int x,int y,char symbol);
private:
Cell** cells;
    int size;
    int ** offers;
    int counter;
};

#endif //UNTITLED_GAMELOGICS_H
