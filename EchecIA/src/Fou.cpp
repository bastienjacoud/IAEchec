//
// Created by natjo on 13/04/2017.
//

#include "../include/Fou.h"

Fou::Fou()
{

}

Fou::~Fou()
{
    
}


bool Fou::DeplacementOK(int depX, int depY)
{
    for(int i=-7; i<8; i++) {
        if (((depX == i) && (depY == i)) or ((depX == i) && (depY == -i)))
            return true;
    }

    return false;
}