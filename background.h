#ifndef DEF_BG
#define DEF_BG

#include <iostream>
#include "stdlib.h"

#include "board.h"
#include "snake.h"
#include "food.h"

class Background : public Board{

    public:
        Background ();

    public:  // prend en argument le tableau du snake ou du fruit mais s'applique à l'objet bg
        void addFood (Food *pf);
            // ajoute un fruit au plateau
            /* On n'a pas besoin de faire une fonction pour l'enlever car on souhaite l'enlever au moment
            où il est mangé, c'est-à-dire lorsque le fruit se situe au niveau d'une case (la tête) du
            snake. Du coup, l'appel à removeSnake dans game () s'occupe de l'enlever. */
        void addSnake (Snake *ps);
            // ajoute au plateau les points du snake contenu dans le tableau snake
        void removeSnake (Snake *ps);
            // enlève le snake du plateau
        bool verifyBorder (Snake *ps);
            // vérifie que le serpent est toujours dans une position valide
};

#endif