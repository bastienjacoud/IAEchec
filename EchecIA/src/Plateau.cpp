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
        }

    //placement des pions noirs
    this->m_plateau[0][0]->Setpiece( new Tour(1) );
    this->m_plateau[3][4]->Setpiece( new Fou(1) );//0 2
    this->m_plateau[0][4]->Setpiece( new Roi(1) );
    this->m_plateau[0][6]->Setpiece( new Cavalier(1) );
    //this->m_plateau[1][1]->Setpiece( new Pion(1) );
    //this->m_plateau[1][3]->Setpiece( new Pion(1) );
    this->m_plateau[1][5]->Setpiece( new Pion(1) );
    this->m_plateau[1][7]->Setpiece( new Pion(1) );
    //this->m_plateau[2][0]->Setpiece( new Pion(1) );
    this->m_plateau[2][2]->Setpiece( new Pion(1) );
    //this->m_plateau[2][4]->Setpiece( new Pion(1) );
    this->m_plateau[2][6]->Setpiece( new Pion(1) );


    //placement des pions blancs
    this->m_plateau[7][0]->Setpiece( new Tour(2) );
    this->m_plateau[7][2]->Setpiece( new Fou(2) );
    this->m_plateau[7][4]->Setpiece( new Roi(2) );
    this->m_plateau[7][6]->Setpiece( new Cavalier(2) );
    //this->m_plateau[6][1]->Setpiece( new Pion(2) );
    this->m_plateau[6][3]->Setpiece( new Pion(2) );
    this->m_plateau[6][5]->Setpiece( new Pion(2) );
    this->m_plateau[6][7]->Setpiece( new Pion(2) );
    this->m_plateau[5][0]->Setpiece( new Pion(2) );
    this->m_plateau[5][2]->Setpiece( new Pion(2) );
    this->m_plateau[5][4]->Setpiece( new Pion(2) );
    this->m_plateau[5][6]->Setpiece( new Pion(2) );

    for(int i=0;i<24;i++)
        this->piecesPrisent[i] = new Piece();

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

void Plateau::AjoutePiecePrise(Piece* p)
{
    for(int i=0;i<24;i++)
        if(this->piecesPrisent[i] != NULL)
        {
            if(this->piecesPrisent[i]->getType() == 'I')
            {
                this->piecesPrisent[i] = p;
                return;
            }
        }

}

void Plateau::SupprimePiecePrise(Piece p)
{
    for(int i=0;i<24;i++)
        if(this->piecesPrisent[i] != NULL)
            if(this->piecesPrisent[i]->getType() == p.getType())
                this->piecesPrisent[i] = NULL;
}

void Plateau::AffichePiecePrise()
{
    for(int i=0;i<24;i++)
        if(this->piecesPrisent[i] != NULL)
            cout<<this->piecesPrisent[i]->getType()<<endl;
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
    if(this->Getplateau(xarrivee, yarrivee).Getpiece()->GetCouleur() != this->Getplateau(xdep, ydep).Getpiece()->GetCouleur())
    {
        int tabt;
        int tab[16];
        for(int i=0;i<16;i++)
            tab[i] = 0;
        if(this->Getplateau(xdep, ydep).Getpiece()->PriseOK(xarrivee - xdep,yarrivee - ydep, tab, tabt) == 1)
        {
            if(tabt == 0)//Si pas de case entre case arriv�e et case d�part
            {
                this->AjoutePiecePrise(this->Getplateau(xarrivee, yarrivee).Getpiece());
                //this->AffichePiecePrise();
                /*
                piecesPrisent[np] = this->Getplateau(xarrivee, yarrivee).Getpiece();
                char c = piecesPrisent[np]->getType();    //Donne le bon type quand l'affichage marche
                cout << "fzdfsd ==" << c << endl;
                np ++;
                int x = this->TestFinJeu();
                cout<< "x = " << x << endl;
                cout<< "np = " << np << endl;
                */
                this->Getplateau(xarrivee, yarrivee).Setpiece(  this->Getplateau(xdep, ydep).Move() );
                return 1;
            }
            else
            {
                int b=1;
                for(int i=0;i<tabt;i+=2)
                {
                    if(this->Getplateau(xdep + tab[i+1], ydep + tab[i]).Getpiece() != NULL)//S'il y a une pi�ce entre la case de d�part et d'arriv�
                    {
                        b=0;
                    }

                }
                if(b==1)
                {
                    this->AjoutePiecePrise(this->Getplateau(xarrivee, yarrivee).Getpiece());
                    //this->AffichePiecePrise();
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
    {
        return 0;
    }
    return 0;
}

int Plateau::DeplacerPiece(int xdep, int ydep, int xarrivee, int yarrivee)
{
    //x -> lignes
    //y colonnes
    if(this->Getplateau(xarrivee, yarrivee).Getpiece() == NULL)//Si on bouge sur une case vide
    {
        int tabt;
        int tab[16];
        for(int i=0;i<16;i++)
            tab[i] = 0;
        if(this->Getplateau(xdep, ydep).Getpiece()->DeplacementOK(xarrivee - xdep,yarrivee - ydep, tab, tabt) == 1)
        {
            if(tabt == 0)//Si pas de case entre case arriv�e et case d�part
            {
                this->Getplateau(xarrivee, yarrivee).Setpiece( this->Getplateau(xdep, ydep).Move() );
                return 1;
            }
            else
            {
                int b=1;
                for(int i=0;i<tabt;i+=2)
                {
                    if(this->Getplateau(xdep + tab[i+1], ydep + tab[i]).Getpiece() != NULL)//S'il y a une pi�ce entre la case de d�part et d'arriv�
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
    return 0;
}

int Plateau::TestFinJeu()
{
    //la partie se termine lorsque le roi adverse est prit ou en echec et mat
    for(int i=0;i<24;i++)
    {
        if(piecesPrisent[i] != NULL)
        {
            if(piecesPrisent[i]->getType() == 'R')
            {
                if (piecesPrisent[i]->GetCouleur() == 1)
                    { return 2;}
                if (piecesPrisent[i]->GetCouleur() == 2)
                    { return 1;}
            }
        }
    }
    return 0;
}

void Plateau::TestPionArrive()
{
    char c;
    for(int i=0;i<8;i++)
    {
        if(this->Getplateau(0,i).Getpiece() != NULL)
            if(this->Getplateau(0,i).Getpiece()->getType() == 'P')
            {
                int b=0;
                while(b==0)
                {
                    cout<<"Par quelle piece remplacer votre pion?(P, T, C ou F)"<<endl;
                    cin>>c;
                    for(int k=0;k<24;k++)
                    {
                        if(this->piecesPrisent[k] != NULL)
                            if((this->piecesPrisent[k]->getType() == c) && (this->piecesPrisent[k]->GetCouleur() == 2))
                            {
                                b=1;
                                this->Getplateau(0,i).Setpiece(this->piecesPrisent[k]);
                                this->piecesPrisent[k] = NULL;
                            }
                    }
                    if(b==0)
                    {
                        cout<<"Choisissez une pièce que vous avez perdu !"<<endl;
                    }
                }
            }

        if(this->Getplateau(7,i).Getpiece() != NULL)
            if(this->Getplateau(7,i).Getpiece()->getType() == 'P')
            {
                int b=0;
                while(b==0)
                {
                    cout<<"Par quelle piece remplacer votre pion?(P, T, C ou F)"<<endl;
                    cin>>c;
                    for(int k=0;k<24;k++)
                    {
                        if(this->piecesPrisent[k] != NULL)
                            if((this->piecesPrisent[k]->getType() == c) && (this->piecesPrisent[k]->GetCouleur() == 1))
                            {
                                b=1;
                                this->Getplateau(7,i).Setpiece(this->piecesPrisent[k]);
                                this->piecesPrisent[k] = NULL;
                            }
                    }
                    if(b==0)
                    {
                        cout<<"Choisissez une pièce que vous avez perdu !"<<endl;
                    }
                }
            }
    }
}



int main()
{
    Plateau* p = new Plateau();
    int xd;
    int yd;
    int xf;
    int yf;
    int joueurcourant=1;
    //int b=1;//servira plus tard de bool�en de test de fin du jeu
    p->Afficher();


    while(p->TestFinJeu() == 0)
    //while(true)
    {
        cout<<"C'est au joueur "<<joueurcourant<<" de jouer."<<endl;

        cout << "ligne de la piece a bouger : \n"; cin >> xd;xd--;
        cout << "colonne de la piece a bouger : \n"; cin >> yd;yd--;
        while((xd>=8 || xd<0 || yd>=8 || yd<0) || p->Getplateau(xd,yd).Getpiece() == NULL || joueurcourant != p->Getplateau(xd,yd).Getpiece()->GetCouleur())
        {
            cout<< "Coordonnees de la piece a deplacer invalides. Veuillez reessayer."<<endl;
            p->Afficher();
            cout << "ligne de la piece a bouger : \n"; cin >> xd;xd--;
            cout << "colonne de la piece a bouger : \n"; cin >> yd;yd--;
        }


        cout << "ligne ou deplacer la piece : \n"; cin >> xf;xf--;
        cout << "colonne ou deplacer la piece : \n"; cin >> yf;yf--;
        while((xf>=8 || xf<0 || yf>=8 || yf<0) || (p->DeplacerPiece(xd, yd, xf, yf) == 0))
        {
            cout<< "Coordonnees de la case d'arrivee invalides. Veuillez reessayer."<<endl;
            p->Afficher();
            cout << "ligne ou deplacer la piece : \n"; cin >> xf;xf--;
            cout << "colonne ou deplacer la piece : \n"; cin >> yf;yf--;
        }

        /*
        if(joueurcourant == 1)
            joueurcourant = 2;
        else if(joueurcourant == 2)
            joueurcourant = 1;
        */
        //p->AffichePiecePrise();

        p->Afficher();
    }
    return 0;
}
