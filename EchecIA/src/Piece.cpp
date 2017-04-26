#include <array>
#include <iostream>
#include "../include/Piece.h"

using namespace std;

Piece::Piece()
{
    SetposX(-1);
    SetposY(-1);
    SetCouleur(0);
}

Piece::~Piece()
{
    //dtor
}

void Piece::Afficher()
{
    cout<<" _ ";
}
