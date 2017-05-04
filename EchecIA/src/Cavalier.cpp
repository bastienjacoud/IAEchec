#include "Cavalier.h"

Cavalier::Cavalier()
{
    //ctor
}

Cavalier::~Cavalier()
{
    //dtor
}

bool Cavalier::DeplacementOK(int depX, int depY)
{
    if((depX == 1 && (depY == 2 || depY == -2)) || (depX == -1 && (depY == 2 || depY == -2)) || (depY == 1 && (depX == 2 || depY == -2)) || (depY == -1 && (depX == 2 || depX == -2))) {
        return true;
    }

    return false;
}
