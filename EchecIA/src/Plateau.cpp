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
        cout<<endl<<endl;
    }
}

int Plateau::prendrePiece(int xdep, int ydep, int xarrivee, int yarrivee)//Fonction pour prendre une piece adverse
{
    //A fini
    if(this->Getplateau(xarrivee, yarrivee).Getpiece()->GetCouleur() != this->Getplateau(xdep, ydep).Getpiece()->GetCouleur())
    {
        this->Getplateau(xarrivee, yarrivee).Setpiece(  this->Getplateau(xdep, ydep).Move() );
        return 1;
    }
    else
    {
        //cout<<"Impossible de déplacer la pièce ici."<<endl;
        return 0;
    }
}

int Plateau::DeplacerPiece(int xdep, int ydep, int xarrivee, int yarrivee)
{
    if(this->Getplateau(xarrivee, yarrivee).Getpiece() == NULL)//Si on bouge sur une case vide
    {
        int tab[8];
        int tabt;
        if(this->Getplateau(xdep, ydep).Getpiece()->DeplacementOK(xarrivee - xdep,yarrivee - ydep, tab, &tabt) == 1)
        {
            if(tab == NULL)//Si pas de case entre case arrivée et case départ
            {
                this->Getplateau(xarrivee, yarrivee).Setpiece(  this->Getplateau(xdep, ydep).Move() );
                return 1;
            }
            else
            {
                int b=1;
                for(int i=0;i<tabt;i+=2)
                {
                    if(this->Getplateau(tab[i] + xdep, tab[i+1] + ydep).Getpiece() != NULL)//S'il y a une pièce entre la case de départ et d'arrivé
                        b=0;
                }
                if(b==1)
                {
                    this->Getplateau(xarrivee, yarrivee).Setpiece(  this->Getplateau(xdep, ydep).Move() );
                    return 1;
                }
                else if(b==0)
                {
                    return 0;
                }
            }

        }
        else
        {
            return 0;
        }

    }
    else
        return this->prendrePiece(xdep, ydep, xarrivee, yarrivee);
}

int Plateau::TestFinJeu()
{
    //A faire
    return 1;
}

int main()
{
    Plateau* p = new Plateau();
    int xd;
    int yd;
    int xf;
    int yf;
    int joueurcourant=1;
    //int b=1;//servira plus tard de booléen de test de fin du jeu
    p->Afficher();

    while(p->TestFinJeu() == 1)
    {
        cout<<"C'est au joueur "<<joueurcourant<<" de jouer."<<endl;

        cout << "ligne de la piece a bouger : \n"; cin >> xd;xd--;
        cout << "colonne de la piece a bouger : \n"; cin >> yd;yd--;
        while((xd>=8 || xd<0 || yd>=8 || yd<0) || p->Getplateau(xd,yd).Getpiece() == NULL || joueurcourant != p->Getplateau(xd,yd).Getpiece()->GetCouleur())
        {
            cout<< "Coordonnees de la piece a deplacer invalides. Veuillez reessayer."<<endl;
            cout << "ligne de la piece a bouger : \n"; cin >> xd;xd--;
            cout << "colonne de la piece a bouger : \n"; cin >> yd;yd--;
        }


        cout << "ligne ou deplacer la piece : \n"; cin >> xf;xf--;
        cout << "colonne ou deplacer la piece : \n"; cin >> yf;yf--;
        while((xf>=8 || xf<0 || yf>=8 || yf<0) || (p->DeplacerPiece(xd, yd, xf, yf) == 0))
        {
            cout<< "Coordonnees de la case d'arrivee invalides. Veuillez reessayer."<<endl;
            cout << "ligne ou deplacer la piece : \n"; cin >> xf;xf--;
            cout << "colonne ou deplacer la piece : \n"; cin >> yf;yf--;
        }
        /*
        if(joueurcourant == 1)
            joueurcourant = 2;
        else if(joueurcourant == 2)
            joueurcourant = 1;
        */
        p->Afficher();
    }
    return 0;
}
