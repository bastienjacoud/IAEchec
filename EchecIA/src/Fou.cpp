//
// Created by natjo on 13/04/2017.
//
#include <iostream>
#include <cmath>
#include "../include/Fou.h"

using namespace std;

//Constructeur par défaut
Fou::Fou()
{

}

//Constructeur avec couleur
Fou::Fou(int couleur) : Piece(couleur)
{

}

Fou::~Fou()
{

}


int Fou::DeplacementOK(int depY, int depX, int tab[], int& tabl)
{
    //tab[j] -> horizontal
    //tab[j+1] -> vertical
    int j=0;
    if(depX == depY)
    {
        tabl = 2*(abs(depX)-1);
        if(depX>0)
        {
            for(int i=1;i<depX;i++)
            {
                tab[j] = i;
                tab[j+1] = i;
                j+=2;
            }
        }
        if(depX<0)
        {
            for(int i=-1;i>depX;i--)
            {
                tab[j] = i;
                tab[j+1] = i;
                j+=2;
            }
        }
        return 1;
    }

    else if(depX == -depY)
    {
        tabl = 2*(abs(depX)-1);
        if(depX>0)
        {
            for(int i=1;i<depX;i++)
            {
                tab[j] = i;
                tab[j+1] = -i;
                j+=2;
            }
        }
        if(depX<0)
        {
            for(int i=-1;i>depX;i--)
            {
                tab[j] = i;
                tab[j+1] = -i;
                j+=2;
            }
        }
        return 1;
    }
    else
    {
        tab = NULL;
        tabl = 0;
        return 0;
    }

}

int Fou::PriseOK(int depX, int depY, int tab[], int& tabl)
{
    return Fou::DeplacementOK(depX, depY, tab, tabl);
}

void Fou::Afficher()
{
    cout<<" F"<<GetCouleur()<<" ";
}
