//
// Created by natjo on 23/05/2017.
//

#include<iostream>
#include "../include/Cavalier.h"

using namespace std;

//Constructeur par d�faut
Cavalier::Cavalier()
{
    //ctor
}

//Constructeur avec la couleur
Cavalier::Cavalier(int couleur) : Piece(couleur)
{

}

Cavalier::~Cavalier()
{
    //dtor
}

void Cavalier::Afficher()
{
    cout<<" C"<<GetCouleur()<<" ";
}

int Cavalier::DeplacementOK(int depX, int depY, int tab[], int& tabl)
{
    tab = NULL;
    tabl = 0;
    if((depX == 2 && depY == 1) || (depX == 2 && depY == - 1) || (depX == -2 && depY == 1) || (depX == -2 && depY == -1)
            || (depX == 1 && depY == 2) || (depX == 1 && depY == -2) || (depX == -1 && depY == 2) || (depX == -1 && depY == -2))
        return 1;
    else
        return 0;
}

int Cavalier::PriseOK(int depX, int depY, int tab[], int& tabl)
{
    return Cavalier::DeplacementOK(depX, depY, tab, tabl);
}
