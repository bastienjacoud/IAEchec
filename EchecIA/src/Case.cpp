#include <array>
#include <iostream>
#include "../include/Case.h"

using namespace std;

Case::Case()
{
    //cout<<"test2"<<endl;
    this->m_piece = NULL;
    //ctor
}

Case::Case(Piece p)
{
    //cout<<"test1"<<endl;
    if(this->m_piece->getType() == 'C')
        this->m_piece = new Cavalier(p);
    else if(this->m_piece->getType() == 'F')
        this->m_piece = new Fou(p);
    else if(this->m_piece->getType() == 'P')
        this->m_piece = new Pion(p);
    else if(this->m_piece->getType() == 'R')
        this->m_piece = new Roi(p);
    else if(this->m_piece->getType() == 'T')
        this->m_piece = new Tour(p);
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

Case* Case::CopieCase(){

    Case* c = new Case();
    if(this->Getpiece() == NULL)
        c->m_piece = NULL;
    else
        c->Setpiece(this->Getpiece()->CopiePiece());
    return c;

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

