#ifndef DEF_MOVE 
#define DEF_MOVE

class Move{

    public:
        Move ();

    public:
        void movement (char mov); // modifie dxdy

    public:
        const int* getMove (); // renvoie la tableau codant la direction du mouvement

    private:
        int* dxdy;
};

#endif