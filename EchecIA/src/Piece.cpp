#include <array>
#include <iostream>
#include "../include/Piece.h"

using namespace std;

//Constructeur par défaut
Piece::Piece()
{
    SetposX(-1);
    SetposY(-1);
    SetCouleur(0);
}

//Constructeur prenant en chatge la couleur de l'équipe
Piece::Piece(int couleur)
{
    SetCouleur(couleur);
}

Piece::~Piece()
{
    //dtor
}

void Piece::SetCouleur(int couleur)
{
    if(couleur == 1 || couleur == 2)
        this->m_couleur = couleur;
}

void Piece::Afficher()
{
    cout<<" _ ";
}

