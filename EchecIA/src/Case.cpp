#include <array>
#include <iostream>
#include "../include/Case.h"

using namespace std;

Case::Case() : m_piece()
{
    //ctor
}

Case::~Case()
{
    //dtor
}

void Case::Afficher()
{
    if(this->Getpiece() == NULL)
        cout<<" _ ";
    else
        m_piece->Afficher();
}

void Case::ChangePiece(Piece* p)
{

}

