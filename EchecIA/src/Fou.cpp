//
// Created by natjo on 13/04/2017.
//
#include <iostream>
#include "../include/Fou.h"

using namespace std;

//Constructeur par défaut
Fou::Fou()
{

}

//Constructeur avec couleur
Fou::Fou(int couleur) : Piece(couleur)
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

void Fou::Afficher()
{
    cout<<" F ";
}
