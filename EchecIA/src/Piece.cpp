#include <array>
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
