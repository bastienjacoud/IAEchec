#include "../include/Plateau.h"

Plateau::Plateau()
{
    //ctor
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

    return 0;
}
