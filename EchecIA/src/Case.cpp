#include <array>
#include <iostream>
#include "../include/Case.h"

using namespace std;

Case::Case() : m_piece()
{
    //ctor
}

Case::Case(int i)
{
    //dynamic_cast<Tour>(this.Getpiece()) = new Tour();
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

