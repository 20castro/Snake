#include "background.h"

Background::Background () : Board (){}

void Background::addFood (Food *pf){
    const int place = pf->getFood();
    Board::addValue (place, 2);
}

void Background::addSnake (Snake *ps){
    const int* snake = ps->getSnake();
    {
        int snl = ps->getLength();
        {
            Board::addTab (snake, snl);
        }
    }
}

void Background::removeSnake (Snake *ps){
    const int* snake = ps->getSnake();
    {
        const int snl = ps->getLength();
        {
            Board::removeTab (snake, snl);
        }
    }
}

bool Background::verifyBorder (Snake *ps){
    const int* snake = ps->getSnake();
    {
        const int head [2] = {snake [0], snake [1]};
        return Board::onBorder(head) or ps->auto_croisement();
    }
}