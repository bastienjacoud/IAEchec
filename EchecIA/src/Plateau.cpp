#include<iostream>
#include "../include/Plateau.h"

using namespace std;

Plateau::Plateau()
{
    //Initialisation de la grille
    for(int i=0; i<8; i++)
        for(int j=0;j<8;j++)
            this->m_plateau[i][j] = new Case();
    //placement des pions
    delete this->m_plateau[0][0]->Getpiece();
    //this->m_plateau[0][0].ge
}

Plateau::~Plateau()
{
    //dtor
}

void Plateau::Setplateau(Case plateau[8][8])
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            *m_plateau[i][j] = plateau[i][j];
}

void Plateau::Afficher()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            this->Getplateau(i,j).Afficher();
        }
        cout<<endl;
    }
}

void Plateau::prendrePiece(int xarrive, int yarrive)        //Fonction pour prendre une piece adverse
{
    
}

int main()
{
    cout<<"Bastien est une merde"<<endl;
    Plateau* p = new Plateau();
    p->Afficher();


    int xd;
    int yd;
    int xf;
    int yf;
    cout << "ligne de la piece a bouger : \n"; cin >> xd;
    cout << "colonne de la piece a bouger : \n"; cin >> yd;
    cout << "ligne ou deplacer la piece : \n"; cin >> xf;
    cout << "colonne ou deplacer la piece : \n"; cin >> yf;



    return 0;
}
