#include "Roi.h"

Roi::Roi()
{
    //ctor
}

Roi::~Roi()
{
    //dtor
}

bool Roi::DeplacementOK(int depX, int depY){
    if((depX == 1 && (depY == 1 || depY == 0 || depY == -1)) || (depX == -1 && (depY == 1 || depY == 0 || depY == -1)) || (depX == 0 && (depY == 1 || depY == -1))){
        return true;
    }
    return false;
}
