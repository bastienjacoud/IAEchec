#include <array>
#include <iostream>
#include "../include/Case.h"

using namespace std;

Case::Case()
{
    this->m_piece = NULL;
    //ctor
}

Case::~Case()
{
    //dtor
}

void Case::Afficher()
{
    if(this->Getpiece() == NULL)
        cout<<" __ ";
    else
        m_piece->Afficher();
}

Case Case::CopieCase()
{
    Case c;
    c.Getpiece() = this->Getpiece()->CopiePiece();
}

Piece* Case::Move()
{
    Piece *p = m_piece;
    m_piece = NULL;
    return p;
}

void Case::ChangePiece(Piece* p)
{

}

