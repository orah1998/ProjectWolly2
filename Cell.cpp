//
// Or Aharoni
//208250746


#include "Cell.h"



#include <iostream>
using namespace std;


Cell::Cell(int x,int y){
    x_=x;
    y_=y;
    value=' ';
}
char Cell::GetValue() {
    return value;
}

void Cell::ChangeValue(char symbol) {
    value=symbol;
}