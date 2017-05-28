#include <array>
#include<iostream>
#include "../include/Pion.h"

using namespace std;

Pion::Pion()
{
    premierCoup = 1;
}

Pion::Pion(int couleur) : Piece(couleur)
{
    premierCoup = 1;
}

Pion::~Pion()
{

}

int Pion::DeplacementOK(int depX, int depY, int tab[], int& tabl)
{

    if(GetCouleur() == 1)
    {
        if(premierCoup == 1)
        {
            if((depX==1) && (depY==0))
            {
                premierCoup = 0;
                tab = NULL;
                tabl = 0;
                return 1;
            }
            else if((depX==2) && (depY==0))
            {
                premierCoup = 0;
                tab[0] = 0;
                tab[1] = 1;
                tabl = 2;
                return 1;
            }
            else
            {
                tab = NULL;
                tabl = 0;
                return 0;
            }

        }
        else
        {
            if((depX==1) && (depY==0))
            {
                premierCoup = 0;
                tab = NULL;
                tabl = 0;
                return 1;
            }
            else
            {
                tab = NULL;
                tabl = 0;
                return 0;
            }

        }
    }
    else
    {
        if(premierCoup == 1)
        {
            if((depX==-1) && (depY==0))
            {
                premierCoup = 0;
                tab = NULL;
                tabl = 0;
                return 1;
            }
            else if((depX==-2) && (depY==0))
            {
                premierCoup = 0;
                tab[0] = 0;
                tab[1] = -1;
                tabl = 2;
                return 1;
            }
            else
            {
                tab = NULL;
                tabl = 0;
                return 0;
            }

        }
        else
        {
            if((depX==-1) && (depY==0))
            {
                premierCoup = 0;
                tab = NULL;
                tabl = 0;
                return 1;
            }
            else
            {
                tab = NULL;
                tabl = 0;
                return 0;
            }

        }
    }
    //return 0;
}

int Pion::PriseOK(int depX, int depY, int tab[], int& tabl)
{
    if(GetCouleur() == 1)
    {
        if((depX==1) && (depY==1))
        {
            premierCoup = 0;
            tab = NULL;
            tabl = 0;
            return 1;
        }
        else if((depX==1) && (depY==-1))
        {
            premierCoup = 0;
            tab = NULL;
            tabl = 0;
            return 1;
        }
        else
        {
            tab = NULL;
            tabl = 0;
            return 0;
        }
    }
    else
    {
        if((depX==-1) && (depY==1))
        {
            premierCoup = 0;
            tab = NULL;
            tabl = 0;
            return 1;
        }
        else if((depX==-1) && (depY==-1))
        {
            premierCoup = 0;
            tab = NULL;
            tabl = 0;
            return 1;
        }
        else
        {
            tab = NULL;
            tabl = 0;
            return 0;
        }
    }
}

void Pion::Afficher()
{
    cout<<" P"<<GetCouleur()<<" ";
}
