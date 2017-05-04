#include <array>
#include<iostream>
#include "../include/Pion.h"

using namespace std;

Pion::Pion()
{

}

Pion::Pion(int couleur) : Piece(couleur)
{

}

Pion::~Pion()
{

}

bool Pion::DeplacementOK(int depX, int depY)
{
    if(GetCouleur() == 1)
    {
        if((depX==1) && (depY==0))
            return true;
    }
    else
    {
        if((depX==-1) && (depY==0))
            return true;
    }
    return false;
}

void Pion::Afficher()
{
    cout<<" P ";
}
