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
    cout<<" C ";
}
