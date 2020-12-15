#include "snake.h"

Snake::Snake () : snl (3), snake (new int [100]){
    int w = 10;
    for(int k = 0; k < snl; k++){
        snake [2*k] = w;
        snake [2*k + 1] = k + 3;
    }
}

void Snake::incr (){
    snl++;
}

bool Snake::auto_croisement (){
    for(int k = 1; k < snl; k++){
        if (snake [0] == snake [2*k] and snake [1] == snake [2*k + 1]){
            return true;
        }
    }
    return false;
}

void Snake::update_coordinates (Move *pm){
    const int* dir = pm->getMove();
    if (snl > 1){
        for(int k = snl - 1; k > 0 ; k--){
            snake [2*k] = snake [2*k - 2];
            snake [2*k + 1] = snake [2*k - 1];
        }
        snake [0] += dir [0]; 
        snake [1] += dir [1];
    }
}

int Snake::getLength (){
    return snl;
}

const int* Snake::getSnake (){
    return snake;
}

/* Pour alléger les choses dans food (mais bloque la compilation, mystère !)
const int* getHead (){
    int head [2] = {snake [0], snake [1]};
    return head;
}
*/

void Snake::showSnake (){ // fonction test
    for (int k = 0; k < snl; k ++){
        std::cout << '(' << snake [2*k] << ',' << ' ' << snake [2*k + 1] << ')' << ' ';
    }
    std::cout << std::endl;
}