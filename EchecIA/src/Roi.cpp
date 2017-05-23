//
// Created by natjo on 23/05/2017.
//

#include<iostream>
#include "../include/Roi.h"

using namespace std;

Roi::Roi()
{
    //ctor
}

Roi::Roi(int couleur) : Piece(couleur)
{

}

Roi::~Roi()
{
    //dtor
}

void Roi::Afficher()
{
    cout<<" R"<<GetCouleur()<<" ";
}

int Roi::DeplacementOK(int depX, int depY, int tab[], int* tabl)
{
    if(((depX == 1) || (depX == 0)) && ((depY == 1) || (depY == 0)))
        return 1;
    else
        return 0;
}



