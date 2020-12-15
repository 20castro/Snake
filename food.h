#ifndef DEF_FOOD
#define DEF_FOOD

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "snake.h"

class Food{

    public:
        Food ();

    public:
        void newFood ();
            // génère aléatoirement la position d'un fruit (codée par un entier)
        void nonFood ();
            // réinitialise la position du fruit 
        bool eatFood (Snake *ps);
            // renvoie true ssi la tête du snake se situe sur la case du fruit

    public:
        const int getFood ();

    private:
        int food;
        int nx;
        int ny;
};

#endif