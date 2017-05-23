#include<iostream>
#include "Cavalier.h"

using namespace std;

//Constructeur par défaut
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

int Cavalier::DeplacementOK(int depX, int depY, int tab[], int* tabl)
{
    tab = NULL;
    *tabl = 0;
    if((depX == 2 && depY == 1) || (depX == 2 && depY == - 1) || (depX == -2 && depY == 1) || (depX == -2 && depY == -1))
        return 1;
    else
        return 0;
}
