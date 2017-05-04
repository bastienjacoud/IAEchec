#include <array>
#include <iostream>
#include "../include/Tour.h"

using namespace std;

Tour::Tour()
{
    //ctor
}

Tour::Tour(int couleur) : Piece(couleur)
{

}

Tour::~Tour()
{
    //dtor
}

bool Tour::DeplacementOK(int depX, int depY)
{
    for(int i=-7; i<8; i++) {
        if (((depX == i) && (depY == 0)) or ((depX == 0) && (depY == i)))
            return true;
    }

    return false;
}

void Tour::Afficher()
{
    cout<<" T ";
}
