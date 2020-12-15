#include "board.h"

Board::Board () : bg (new int [50*25]), nx (50), ny (25){
    for(int i = 0; i < nx; i++){
        bg [i] = 1;
        bg [i + nx*(ny - 1)] = 1;
    }
    for(int j = 0; j < ny; j++){
        bg [nx*j] = 1;
        bg [nx*(j + 1) - 1] = 1;
    }
}

void Board::clear (){
    int out = system(cmd_clear);
    if (out != 0){
        std::cerr << "Clear command failed" << std::endl;
        exit(1);
    }
}

void Board::printBoard (){
    for (int j = 0; j < ny; j++){
        for (int i = 0; i < nx; i++){
            if (bg [i + j*nx] == 1){
                std::cout << "#";
            }
            else if (bg[i + j*nx] == 2){
                std::cout << "@"; 
            }    
            else{
                std::cout << " ";
            }
        }
    std::cout << std::endl;
    }
}

void Board::addValue (const int loc, const int val){
    bg [loc] = val;
}

void Board::addTab (const int* tab, const int npt){
    for (int k = 0; k < npt; k++){
        int i = tab [2*k];
        {
            int j = tab [2*k + 1];
            {
                Board::addValue (i + j*nx, 1);
            }
        }
    }
}

void Board::removeTab (const int* tab, const int npt){
    for (int k = 0; k < npt; k++){
        int i = tab [2*k];
        {
            int j = tab [2*k + 1];
            {
                Board::addValue (i + j*nx, 0);
            }
        }
    }
    std::cout << npt << std::endl;
}

bool Board::onBorder (const int* point){
    return point [0] == 0 or point [0] == nx - 1 or point [1] == 0 or point [1] == ny - 1;
}