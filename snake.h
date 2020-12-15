#ifndef DEF_SNAKE
#define DEF_SNAKE

#include <iostream>
#include "move.h"

class Snake{

    public:
        Snake ();
        
    public:
        void incr ();
            // augmente la longueur du serpent
        bool auto_croisement ();
            // renvoie true ssi la tête du serpent rencontre une autre case de son corps
        void update_coordinates (Move *pm);
            // modifie le tableau du SERPENT avec ses nouvelles coordonnées
            // la tête du snake est fixée au premier point du tableau snake et la tête au snl-ième
            // cela facilite les choses pour augmenter la longueur du snake lorsqu'il mange un fruit

    public:
        int getLength (); // renvoie la longueur du serpent
        const int* getSnake (); // renvoie le tableau du serpent
        void showSnake (); // fonction test

    private:
        int snl;
        int* snake;
};

#endif