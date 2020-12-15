#include "game.h"
#include "food.h"
#include "move.h"
#include "snake.h"
#include "background.h"
#include "timetime.h"

void game (){
    char key;
    Move m;
    Move *pm = &m;
    Food f;
    Food *pf = &f;
    Snake s;
    Snake *ps = &s;
    Background b;
    Background *pb = &b;
    pf->newFood ();

    while (true){
        const int *dxdy = pm->getMove();
        {
            if (dxdy [0] == 0){
                frameSleep(2*lap); // échelles verticale et horizontale différentes
            }
            else{
                frameSleep(lap);
            }
        } 
        if (keyEvent()){
            std::cin >> key;
            pm->movement(key);
        }
        pb->clear();
        pb->addSnake (ps);
        pb->addFood (pf);
        pb->printBoard ();
        pb->removeSnake (ps);
        if (pb->verifyBorder(ps)){
            std::cerr << "" << std::endl;
            exit(1);
        }
        if (pf->eatFood(ps)){
            pf->nonFood();
            pf->newFood();
            ps->incr();
        }
        ps->update_coordinates(pm);
    }
}