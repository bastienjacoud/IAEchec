#include<iostream>
#include "Roi.h"

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
    cout<<" R ";
}
