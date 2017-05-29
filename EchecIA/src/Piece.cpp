#include <array>
#include <iostream>
#include "../include/Piece.h"

using namespace std;

//Constructeur par d�faut
Piece::Piece()
{
    SetposX(-1);
    SetposY(-1);
    SetCouleur(0);
}

//Constructeur prenant en chatge la couleur de l'�quipe
Piece::Piece(int couleur)
{
    SetCouleur(couleur);
}

Piece::~Piece()
{
    //dtor
}

Piece Piece::CopiePiece()
{
    Piece p;
    p.m_couleur = this->m_couleur;
    p.m_posX = this->m_posX;
    p.m_posY = this->m_posY;
    return p;
}

void Piece::SetCouleur(int couleur)
{
    if(couleur == 1 || couleur == 2)
        this->m_couleur = couleur;
}

void Piece::Afficher()
{
    cout<<" __ ";
}

int Piece::DeplacementOK(int depX, int depY, int tab[], int& tabl)
{
    tab = NULL;
    tabl = 0;
    return 1;
}

int Piece::PriseOK(int depX, int depY, int tab[], int& tabl)
{
    return Piece::DeplacementOK(depX, depY, tab, tabl);
}

