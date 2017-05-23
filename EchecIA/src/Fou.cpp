//
// Created by natjo on 13/04/2017.
//
#include <iostream>
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


int Fou::DeplacementOK(int depX, int depY, int tab[], int* tabl)
{
    *tabl = 0;
    int j=0;
    if(depX == depY)
    {
        if(depX>0)
        {
            for(int i=1;i<depX;i++)
            {
                tab[j] = i;
                tab[j+1] = i;
                *tabl += 2;
                j+=2;
            }
        }
        if(depX<0)
        {
            for(int i=-1;i>depX;i--)
            {
                tab[j] = i;
                tab[j+1] = i;
                *tabl += 2;
                j+=2;
            }
        }
        return 1;
    }

    else if(depX == -depY)
    {
        if(depX>0)
        {
            for(int i=1;i<depX;i++)
            {
                tab[j] = i;
                tab[j+1] = -i;
                *tabl += 2;
                j+=2;
            }
        }
        if(depX<0)
        {
            for(int i=-1;i>depX;i--)
            {
                tab[j] = i;
                tab[j+1] = -i;
                *tabl += 2;
                j+=2;
            }
        }
        return 1;
    }
    else
    {
        tab = NULL;
        *tabl = 0;
        return 0;
    }

}

int Fou::PriseOK(int depX, int depY, int tab[], int* tabl)
{
    return Fou::DeplacementOK(depX, depY, tab, tabl);
}

void Fou::Afficher()
{
    cout<<" F"<<GetCouleur()<<" ";
}
