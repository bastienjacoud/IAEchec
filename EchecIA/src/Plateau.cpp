#include<iostream>
#include "../include/Plateau.h"

using namespace std;

Plateau::Plateau()
{

}

Plateau::~Plateau()
{
    //dtor
}

void Plateau::Setplateau(Case plateau[8][8])
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            m_plateau[i][j] = plateau[i][j];
}

int main()
{
    cout<<"Nathan est une merde";
    return 0;
}
