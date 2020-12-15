#include "move.h"

Move::Move () : dxdy (new int [2]){
    dxdy [0] = 1;
    dxdy [1] = 0;
}

void Move::movement (char mov){
    switch (mov)
    {
    case 'l':
        dxdy [0] = 0;
        dxdy [1] = 1;
        break;
    case 'm':
        dxdy [0] = 1;
        dxdy [1] = 0;
        break;
    case 'k':
        dxdy [0] = -1;
        dxdy [1] = 0;
        break;
    case 'o':
        dxdy [0] = 0;
        dxdy [1] = -1;
        break;
    default:
        break;
    }
}

const int* Move::getMove (){
    return dxdy;
}
