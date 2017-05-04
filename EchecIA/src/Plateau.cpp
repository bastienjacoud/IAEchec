#include<iostream>
#include "../include/Plateau.h"

using namespace std;

Plateau::Plateau()
{
    //Initialisation de la grille
    for(int i=0; i<8; i++)
        for(int j=0;j<8;j++)
        {
            this->m_plateau[i][j] = new Case();
            //this->m_plateau[i][j]->Setpiece(new Tour());
        }

    //placement des pions noirs
    this->m_plateau[0][0]->Setpiece( new Tour(1) );
    this->m_plateau[0][2]->Setpiece( new Fou(1) );
    this->m_plateau[0][4]->Setpiece( new Roi(1) );
    this->m_plateau[0][6]->Setpiece( new Cavalier(1) );
    this->m_plateau[1][1]->Setpiece( new Pion(1) );
    this->m_plateau[1][3]->Setpiece( new Pion(1) );
    this->m_plateau[1][5]->Setpiece( new Pion(1) );
    this->m_plateau[1][7]->Setpiece( new Pion(1) );
    this->m_plateau[2][0]->Setpiece( new Pion(1) );
    this->m_plateau[2][2]->Setpiece( new Pion(1) );
    this->m_plateau[2][4]->Setpiece( new Pion(1) );
    this->m_plateau[2][6]->Setpiece( new Pion(1) );

    //placement des pions blancs
    this->m_plateau[7][0]->Setpiece( new Tour(2) );
    this->m_plateau[7][2]->Setpiece( new Fou(2) );
    this->m_plateau[7][4]->Setpiece( new Roi(2) );
    this->m_plateau[7][6]->Setpiece( new Cavalier(2) );
    this->m_plateau[6][1]->Setpiece( new Pion(2) );
    this->m_plateau[6][3]->Setpiece( new Pion(2) );
    this->m_plateau[6][5]->Setpiece( new Pion(2) );
    this->m_plateau[6][7]->Setpiece( new Pion(2) );
    this->m_plateau[5][0]->Setpiece( new Pion(2) );
    this->m_plateau[5][2]->Setpiece( new Pion(2) );
    this->m_plateau[5][4]->Setpiece( new Pion(2) );
    this->m_plateau[5][6]->Setpiece( new Pion(2) );

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
/*
void Plateau::SetPiece(int i, int j, Piece* p)
{
    this->m_plateau[0][0]->Setpiece(p);
}
*/
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
    Plateau* p = new Plateau();
    int xd;
    int yd;
    int xf;
    int yf;
    int b=1;//servira plus tard de booléen de test de fin du jeu
    p->Afficher();

    while(b)
    {
        do
        {
            cout << "ligne de la piece a bouger : \n"; cin >> xd;
            cout << "colonne de la piece a bouger : \n"; cin >> yd;
        }
        while( p->Getplateau(xd,yd).Getpiece() == NULL );

        cout << "ligne ou deplacer la piece : \n"; cin >> xf;
        cout << "colonne ou deplacer la piece : \n"; cin >> yf;
    }




    return 0;
}
