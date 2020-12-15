#include "food.h"

Food::Food () : food (0), nx (50), ny (25){}

void Food::newFood (){
    // rand initialisé dans main 
    if (food == 0){
        food = (1 + rand()%(nx - 2)) + nx*(1 + rand()%(ny - 2));
    }
}

void Food::nonFood(){
    food = 0;
}

bool Food::eatFood (Snake *ps){
    const int* snake = ps->getSnake();
    const int head [2] = {snake [0], snake [1]};
    if (food == head[0] + nx*head [1]){
        nonFood();
        return true;
    }
    return false;
}

const int Food::getFood (){
    return food;
}