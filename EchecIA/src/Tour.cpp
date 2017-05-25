#include <array>
#include <iostream>
#include "../include/Tour.h"

using namespace std;

Tour::Tour()
{
    //ctor
}

Tour::Tour(int couleur) : Piece(couleur)
{

}

Tour::~Tour()
{
    //dtor
}

int Tour::DeplacementOK(int depY, int depX, int tab[], int* tabl)//depY -> vertical, depX -> horizontal
{
    cout<<"depX : "<<depX<<endl;
    cout<<"depY : "<<depY<<endl;
    int j=0;
    *tabl = 0;
    if(depX == 0)
    {
        if(depY>0)
        {
            for(int i=1;i<depY;i++)
            {
                tab[j] = 0;
                tab[j+1] = i;
                *tabl +=2;
                j+=2;
            }
        }
        else if(depY<0)
        {
            for(int i=-1;i>depY;i--)
            {
                tab[j] = 0;
                tab[j+1] = i;
                *tabl +=2;
                j+=2;
            }
        }
        return 1;
    }

    else if(depY == 0)
    {
        if(depX>0)
        {
            for(int i=1;i<depX;i++)
            {
                tab[j] = 0;
                tab[j+1] = i;
                *tabl +=2;
                j+=2;
            }
        }
        else if(depX<0)
        {
            for(int i=-1;i>depX;i--)
            {
                tab[j] = 0;
                tab[j+1] = i;
                *tabl +=2;
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

int Tour::PriseOK(int depX, int depY, int tab[], int* tabl)
{
    return Tour::DeplacementOK(depX, depY, tab, tabl);
}

void Tour::Afficher()
{
    cout<<" T"<<GetCouleur()<<" ";
}
