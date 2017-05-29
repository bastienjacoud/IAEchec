#include <array>
#include <iostream>
#include <cmath>
#include "../include/Tour.h"

using namespace std;

Tour::Tour()
{
    //ctor
}

Tour::Tour(int couleur) : Piece(couleur)
{

}

Tour::Tour(Piece& p) : Piece(p)
{
    //cout<<"test1"<<endl;
}

Tour::~Tour()
{
    //dtor
}

int Tour::DeplacementOK(int depY, int depX, int tab[], int& tabt)//depY -> vertical, depX -> horizontal
{
    //tab[j] -> horizontal
    //tab[j+1] -> vertical
    int j=0;
    if(depX == 0)
    {
        tabt = 2*(abs(depY)-1);
        if(depY>0)
        {
            for(int i=1;i<depY;i++)
            {
                tab[j] = 0;
                tab[j+1] = i;
                j+=2;
            }
        }
        else if(depY<0)
        {
            for(int i=-1;i>depY;i--)
            {
                tab[j] = 0;
                tab[j+1] = i;
                j+=2;
            }
        }
        return 1;
        //cout<<"test"<<endl;
    }
    else if(depY == 0)
    {
        tabt = 2*(abs(depX)-1);
        if(depX>0)
        {
            for(int i=1;i<depX;i++)
            {
                tab[j] = i;
                tab[j+1] = 0;
                j+=2;
            }
        }
        else if(depX<0)
        {
            for(int i=-1;i>depX;i--)
            {
                tab[j] = i;
                tab[j+1] = 0;
                j+=2;
            }
        }
        return 1;
    }
    else
    {
        tab = NULL;
        tabt = 0;
        return 0;
    }

}

int Tour::PriseOK(int depX, int depY, int tab[], int& tabt)
{
    return Tour::DeplacementOK(depX, depY, tab, tabt);
}

void Tour::Afficher()
{
    cout<<" T"<<GetCouleur()<<" ";
}
