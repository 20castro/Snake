#ifndef DEF_BOARD
#define DEF_BOARD

#include <iostream>
#include "stdlib.h"

static const char* cmd_clear = "clear";

class Board{

    public:
        Board ();

    public:
        void clear ();
            // efface l'écran du terminal
        void printBoard ();
            // affiche le plateau dans le terminal

    public:
        void addValue (const int loc, const int val = 1);
            // ajoute une valeur dans le plateau
        void addTab (const int* tab, const int npt);
            // attribue aux npt premiers points contenus dans le tableau la valeur 1 sur le plateau
        void removeTab (const int* tab, const int npt);
            // pareil mais leur attribue 0 (valeur par défaut)
        bool onBorder (const int* point);
            // renvoie true ssi le point est la frontière du plateau de jeu

    protected:
        int* bg;
        int nx;
        int ny;
};

#endif