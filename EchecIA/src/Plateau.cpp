#include<iostream>
#include <windows.h>
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
    this->m_plateau[0][2]->Setpiece( new Fou(1) );//0 2
    this->m_plateau[0][4]->Setpiece( new Roi(1) );
    this->m_plateau[0][6]->Setpiece( new Cavalier(1) );
    this->m_plateau[1][1]->Setpiece( new Pion(1) );
    this->m_plateau[1][3]->Setpiece( new Pion(1) );
    this->m_plateau[1][5]->Setpiece( new Pion(1) );
    this->m_plateau[1][7]->Setpiece( new Pion(1) );
    this->m_plateau[2][0]->Setpiece( new Pion(1) );//2 0
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
    this->m_plateau[6][7]->Setpiece( new Pion(2) );//6 7
    this->m_plateau[5][0]->Setpiece( new Pion(2) );//5 0
    this->m_plateau[5][2]->Setpiece( new Pion(2) );
    this->m_plateau[5][4]->Setpiece( new Pion(2) );
    this->m_plateau[5][6]->Setpiece( new Pion(2) );

    for(int i=0;i<24;i++)
        this->piecesPrisent[i] = new Piece();

    for(int i=0;i<768;i++)
        for(int j=0;j<4;j++)
            pos_possible[i][j] = -1;

}

Plateau::Plateau(Plateau& p)
{
    //Initialisation de la grille
    for(int i=0; i<8; i++)
        for(int j=0;j<8;j++)
        {
            this->m_plateau[i][j] = new Case();
        }

    for(int i=0;i<768;i++)
        for(int j=0;j<4;j++)
        {
            this->pos_possible[i][j] = p.pos_possible[i][j];
        }

    this->np = p.np;
    //cout<<"test"<<endl;
    for(int i=0;i<24;i++)
        this->piecesPrisent[i] = new Piece(*p.piecesPrisent[i]);
    //cout<<"test"<<endl;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(p.Getplateau(i,j).Getpiece() != NULL)
            {
                //cout<<"test"<<endl;
                if(p.m_plateau[i][j]->Getpiece()->getType() == 'C')
                    this->m_plateau[i][j]->Setpiece( new Cavalier(*p.Getplateau(i,j).Getpiece()));
                else if(p.m_plateau[i][j]->Getpiece()->getType() == 'F')
                    this->m_plateau[i][j]->Setpiece( new Fou(*p.Getplateau(i,j).Getpiece()));
                else if(p.m_plateau[i][j]->Getpiece()->getType() == 'P')
                    this->m_plateau[i][j]->Setpiece( new Pion(*p.Getplateau(i,j).Getpiece()));
                else if(p.m_plateau[i][j]->Getpiece()->getType() == 'R')
                    this->m_plateau[i][j]->Setpiece( new Roi(*p.Getplateau(i,j).Getpiece()));
                else if(p.m_plateau[i][j]->Getpiece()->getType() == 'T')
                    this->m_plateau[i][j]->Setpiece( new Tour(*p.Getplateau(i,j).Getpiece()));
                //this->m_plateau[i][j]->Setpiece( new Case(*p.Getplateau(i,j).Getpiece()) );
            }

}


Plateau* Plateau::CopiePlateau()
{
    Plateau* p = new Plateau();

    return p;
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
                this->Getplateau(xdep, ydep).Getpiece()->SetPremierCoup(0);
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
                    this->Getplateau(xdep, ydep).Getpiece()->SetPremierCoup(0);
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
                this->Getplateau(xdep, ydep).Getpiece()->SetPremierCoup(0);
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
                    this->Getplateau(xdep, ydep).Getpiece()->SetPremierCoup(0);
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
            //cout<<"test"<<endl;
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
                    {
                        cout<<"le joueur 2 a gagne."<<endl;
                        return 2;
                    }
                if (piecesPrisent[i]->GetCouleur() == 2)
                    {
                        cout<<"le joueur 1 a gagne."<<endl;
                        return 1;
                    }
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
                    cout<<"Par quelle piece remplacer votre pion?(T, C ou F)"<<endl;
                    cin>>c;
                    if(c == 'T'){
                        this->Getplateau(0,i).Setpiece(new Tour(2));
                        b=1;
                    }

                    if(c == 'C'){
                        this->Getplateau(0,i).Setpiece(new Cavalier(2));
                        b=1;
                    }

                    if(c == 'F'){
                        this->Getplateau(0,i).Setpiece(new Fou(2));
                        b=1;
                    }
/*                    for(int k=0;k<24;k++)
                    {
                        if(this->piecesPrisent[k] != NULL)
                        {
                            if((this->piecesPrisent[k]->getType() == c) && (this->piecesPrisent[k]->GetCouleur() == 2))
                            {
                                b=1;
                                this->Getplateau(0,i).Setpiece(this->piecesPrisent[k]);
                                this->piecesPrisent[k] = NULL;
                            }
                        }
                        else // si le joueur ne s'est fait prendre aucune piece
                            if(c == 'P')
                                b=1;
                    }
*/                    if(b==0)
                    {
                        //cout<<"Choisissez une pièce que vous avez perdu !"<<endl;
                        cout<<"Vous avez le choix seulement entre T, C et F !"<<endl;
                    }
                }
            }

        if(this->Getplateau(7,i).Getpiece() != NULL)
            if(this->Getplateau(7,i).Getpiece()->getType() == 'P')
            {
                int b=0;
                while(b==0)
                {
                    cout<<"Par quelle piece remplacer votre pion?(T, C ou F)"<<endl;
                    cin>>c;
                    if(c == 'T'){
                        this->Getplateau(7,i).Setpiece(new Tour(1));
                        b=1;
                    }

                    if(c == 'C'){
                        this->Getplateau(7,i).Setpiece(new Cavalier(1));
                        b=1;
                    }

                    if(c == 'F'){
                        this->Getplateau(7,i).Setpiece(new Fou(1));
                        b=1;
                    }
/*                    for(int k=0;k<24;k++)
                    {
                        if(this->piecesPrisent[k] != NULL)
                            if((this->piecesPrisent[k]->getType() == c) && (this->piecesPrisent[k]->GetCouleur() == 1))
                            {
                                b=1;
                                this->Getplateau(7,i).Setpiece(this->piecesPrisent[k]);
                                this->piecesPrisent[k] = NULL;
                            }
                    }
*/                    if(b==0)
                    {
                        //cout<<"Choisissez une pièce que vous avez perdu !"<<endl;
                        cout<<"Vous avez le choix seulement entre T, C et F !"<<endl;
                    }
                }
            }
    }
}



/*
        IMPLEMENTATION DE L'IA
*/

int Plateau::Evaluation(Plateau& plateau, int xarr, int yarr)
{
    if(plateau.Getplateau(xarr, yarr).Getpiece() == NULL)
        {return 0;}
    else if(plateau.Getplateau(xarr, yarr).Getpiece()->getType() == 'P')
        {return 50;}
    else if(plateau.Getplateau(xarr, yarr).Getpiece()->getType() == 'C')
        {return 200;}
    else if(plateau.Getplateau(xarr, yarr).Getpiece()->getType() == 'F')
        {return 250;}
    else if(plateau.Getplateau(xarr, yarr).Getpiece()->getType() == 'T')
        {return 250;}
    else if(plateau.Getplateau(xarr, yarr).Getpiece()->getType() == 'R')
        {return 500;}
    return 0;
}

int Plateau::alphaBetaMax(Plateau& plateau, int& alpha, int& beta, int prof, int xarr, int yarr )//plateau modifié
{
    int score;
    Piece* prise;//Sert si l'IA "prend" une piece à la remettre
    if ( prof == 0 || plateau.TestFinJeu() != 0 )
        return Evaluation(plateau, xarr, yarr);

    int tabDepl = plateau.deplacementPossible(2);//l'IA jouera toujours avec la couleur 2

    int positions[tabDepl][4];
    for(int i=0;i<tabDepl;i++)
        for(int j=0;j<4;j++)
            positions[i][j] = plateau.pos_possible[i][j];

    for (int i = 0; i< tabDepl; i++)
    {
      Plateau plateau_modifie(plateau); //copie du plateau

      if(plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Getpiece() == NULL)
            prise = NULL;
      else
            prise = plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Getpiece();

      //On joue le coup
      plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Setpiece( plateau_modifie.Getplateau(positions[i][0], positions[i][1]).Move() );
      plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Getpiece()->SetPremierCoup(0);

      //On calcule le score
      score = alphaBetaMin(plateau_modifie, alpha, beta, prof - 1, positions[i][2], positions[i][3] );

      //On annule le coup
      plateau_modifie.Getplateau(positions[i][0], positions[i][1]).Setpiece( plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Move() );
      plateau_modifie.Getplateau(positions[i][0], positions[i][1]).Getpiece()->SetPremierCoup(1);

      if(prise != NULL)
            plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Setpiece( prise );

      if( score >= beta )
         return beta;
      if( score > alpha )
         alpha = score;
    }
    return alpha;
}

int Plateau::alphaBetaMin(Plateau& plateau, int& alpha, int& beta, int prof, int xarr, int yarr )
{
    int score;
    Piece* prise;//Sert si le joueur "prend" une piece à la remettre
    if ( prof == 0 || plateau.TestFinJeu() != 0 )
        return - Evaluation(plateau, xarr, yarr);

    int tabDepl = plateau.deplacementPossible(1);//le joueur jouera toujours avec la couleur 1

    int positions[tabDepl][4];
    for(int i=0;i<tabDepl;i++)
        for(int j=0;j<4;j++)
        {
            positions[i][j] = plateau.pos_possible[i][j];
        }

    for (int i = 0; i< tabDepl; i++)
    {

      Plateau plateau_modifie(plateau); //copie du plateau

      if(plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Getpiece() == NULL)
            prise = NULL;
      else
            prise = plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Getpiece();

      //On joue le coup
      plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Setpiece( plateau_modifie.Getplateau(positions[i][0], positions[i][1]).Move() );
      plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Getpiece()->SetPremierCoup(0);

      //On calcule le score
      score = alphaBetaMax(plateau_modifie, alpha, beta, prof - 1, positions[i][2], positions[i][3] );

      //On annule le coup
      plateau_modifie.Getplateau(positions[i][0], positions[i][1]).Setpiece( plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Move() );
      plateau_modifie.Getplateau(positions[i][0], positions[i][1]).Getpiece()->SetPremierCoup(1);

      if(prise != NULL)
            plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Setpiece( prise );

      if( score <= alpha )
      {
          return alpha;
      }

      if( score < beta )
         beta = score;
    }
    return beta;
}


void Plateau::lancerIA(int prof)
{
    int score;
    int maximum = -10000;
    int minimum = 10000;
    Piece* prise;//Sert si l'IA "prend" une piece à la remettre
    int xdep,ydep,xarr,yarr;


    int tabDepl = deplacementPossible(2);//l'IA jouera toujours avec la couleur 2

    int positions[tabDepl][4];
    for(int i=0;i<tabDepl;i++)
        for(int j=0;j<4;j++)
            positions[i][j] = pos_possible[i][j];
    //cout<<"test"<<endl;
    for (int i = 0; i< tabDepl; i++)
    {

        Plateau plateau_modifie(*this); //copie du plateau

        //On simule le déplacement d'une piece
        if(plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Getpiece() == NULL)
            prise = NULL;
        else
            prise = plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Getpiece();
        plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Setpiece( plateau_modifie.Getplateau(positions[i][0], positions[i][1]).Move() );
        plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Getpiece()->SetPremierCoup(0);

        //On calcule le score
        score = alphaBetaMin(plateau_modifie, maximum, minimum, prof - 1, positions[i][2], positions[i][3] );
        //cout<<score<<endl;

        if(score >= maximum)
        {
            maximum = score;
            xdep = positions[i][0];
            ydep = positions[i][1];
            xarr = positions[i][2];
            yarr = positions[i][3];
        }

        //On annule le déplacement effectue
        plateau_modifie.Getplateau(positions[i][0], positions[i][1]).Setpiece( plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Move() );
        plateau_modifie.Getplateau(positions[i][0], positions[i][1]).Getpiece()->SetPremierCoup(1);
        if(prise != NULL)
            plateau_modifie.Getplateau(positions[i][2], positions[i][3]).Setpiece( prise );

    }

    //On déplace la pièce sur le meilleur score
    if(this->Getplateau(xarr, yarr).Getpiece() == NULL)
    {
        this->Getplateau(xarr, yarr).Setpiece( this->Getplateau(xdep, ydep).Move() );
        this->Getplateau(xarr, yarr).Getpiece()->SetPremierCoup(0);
    }
    else
    {
        this->AjoutePiecePrise(this->Getplateau(xarr, yarr).Getpiece());
        this->Getplateau(xarr, yarr).Setpiece( this->Getplateau(xdep, ydep).Move() );
        this->Getplateau(xarr, yarr).Getpiece()->SetPremierCoup(0);
    }

}

int Plateau::deplacementPossible(int couleur) // Fonctionnelle
{
    int n = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(this->Getplateau(i, j).Getpiece() != NULL && this->Getplateau(i,j).Getpiece()->GetCouleur() == couleur)
            {
                for(int a = 0; a < 8; a++)
                {
                    for(int b = 0; b < 8; b++)
                    {
                        if(this->Getplateau(a, b).Getpiece() == NULL)//Si on bouge sur une case vide
                        {
                            int tabt;
                            int tab[16];
                            for(int k=0;k<16;k++)
                                tab[k] = 0;
                            if(this->Getplateau(i, j).Getpiece()->DeplacementOK(a - i,b - j, tab, tabt) == 1)
                            {

                                if(tabt == 0)//Si pas de case entre case arriv�e et case d�part
                                {
                                    //cout<<n<<endl;
                                    //cout<<"n1 :"<<n<<endl;
                                    pos_possible[n][0] = i;
                                    pos_possible[n][1] = j;
                                    pos_possible[n][2] = a;
                                    pos_possible[n][3] = b;

                                    n++;
                                    /*
                                    cout<< pos_possible[n-1][0] <<endl;
                                    cout<< pos_possible[n-1][1] <<endl;
                                    cout<< pos_possible[n-1][2] <<endl;
                                    cout<< pos_possible[n-1][3] <<endl;
                                    */
                                    //Sleep(100000);
                                }
                                else
                                {
                                    int m=1;
                                    for(int k=0;k<tabt;k+=2)
                                    {
                                        if(this->Getplateau(i + tab[k+1], j + tab[k]).Getpiece() != NULL)//S'il y a une pi�ce entre la case de d�part et d'arriv�
                                            m=0;
                                    }
                                    if(m==1)
                                    {
                                        //cout<<n<<endl;
                                        //cout<<"n2 :"<<n<<endl;
                                        pos_possible[n][0] = i;
                                        pos_possible[n][1] = j;
                                        pos_possible[n][2] = a;
                                        pos_possible[n][3] = b;

                                        n++;
                                        /*
                                        cout<< pos_possible[n-1][0] <<endl;
                                        cout<< pos_possible[n-1][1] <<endl;
                                        cout<< pos_possible[n-1][2] <<endl;
                                        cout<< pos_possible[n-1][3] <<endl;
                                        */
                                    }
                                }
                            }

                        }
                        else if(this->Getplateau(a, b).Getpiece()->GetCouleur() != this->Getplateau(i, j).Getpiece()->GetCouleur())
                        {
                            int tabt;
                            int tab[16];
                            for(int k=0;k<16;k++)
                                tab[k] = 0;
                            if(this->Getplateau(i, j).Getpiece()->PriseOK(a - i,b - j, tab, tabt) == 1)
                            {
                                /*
                                cout<<"i :"<<i<<endl;
                                cout<<"j :"<<j<<endl;
                                */
                                if(tabt == 0)//Si pas de case entre case arriv�e et case d�part
                                {
                                    //cout<<n<<endl;
                                    //cout<<"n3 :"<<n<<endl;
                                    pos_possible[n][0] = i;
                                    pos_possible[n][1] = j;
                                    pos_possible[n][2] = a;
                                    pos_possible[n][3] = b;

                                    n++;
                                    /*
                                    cout<< pos_possible[n-1][0] <<endl;
                                    cout<< pos_possible[n-1][1] <<endl;
                                    cout<< pos_possible[n-1][2] <<endl;
                                    cout<< pos_possible[n-1][3] <<endl;
*/
                                }
                                else
                                {
                                    int m=1;
                                    for(int k=0;k<tabt;k+=2)
                                    {
                                        if(this->Getplateau(i + tab[k+1], j + tab[k]).Getpiece() != NULL)//S'il y a une pi�ce entre la case de d�part et d'arriv�
                                        {
                                            m=0;
                                        }

                                    }
                                    if(m==1)
                                    {
                                        //cout<<n<<endl;
                                        //cout<<"n4 :"<<n<<endl;
                                        pos_possible[n][0] = i;
                                        pos_possible[n][1] = j;
                                        pos_possible[n][2] = a;
                                        pos_possible[n][3] = b;

                                        n++;
                                        /*
                                        cout<< pos_possible[n-1][0] <<endl;
                                        cout<< pos_possible[n-1][1] <<endl;
                                        cout<< pos_possible[n-1][2] <<endl;
                                        cout<< pos_possible[n-1][3] <<endl;
                                        */
                                    }
                                }
                            }
                        }
                    }

                }
            }
        }
    }
    return n;
}



int main()
{
    Plateau* p = new Plateau();
    int xd;
    int yd;
    int xf;
    int yf;
    int joueurcourant=1;
    // 1 -> joueur
    // 2 -> IA
    int chgtpiece;

    while(p->TestFinJeu() == 0)
    //while(true)
    {
        if(joueurcourant == 1)
        {
            chgtpiece = 0;
            cout<<"C'est au joueur "<<joueurcourant<<" de jouer."<<endl;

            p->Afficher();

            cout << "ligne de la piece a bouger : \n"; cin >> xd;xd--;
            cout << "colonne de la piece a bouger : \n"; cin >> yd;yd--;
            while((xd>=8 || xd<0 || yd>=8 || yd<0) || p->Getplateau(xd,yd).Getpiece() == NULL || joueurcourant != p->Getplateau(xd,yd).Getpiece()->GetCouleur())
            {
                cout<< "Coordonnees de la piece a deplacer invalides. Veuillez reessayer."<<endl;
                p->Afficher();
                cout << "ligne de la piece a bouger : \n"; cin >> xd;xd--;
                cout << "colonne de la piece a bouger : \n"; cin >> yd;yd--;
            }


            cout << "ligne ou deplacer la piece(0 0 pour changer de piece) : \n"; cin >> xf;xf--;
            cout << "colonne ou deplacer la piece(0 0 pour changer de piece) : \n"; cin >> yf;yf--;
            if(xf == -1 && yf == -1)
                chgtpiece = 1;

            while((chgtpiece == 0) && ((xf>=8 || xf<0 || yf>=8 || yf<0) || (p->DeplacerPiece(xd, yd, xf, yf) == 0)) )
            {

                cout<< "Coordonnees de la case d'arrivee invalides. Veuillez reessayer."<<endl;
                p->Afficher();
                cout << "ligne ou deplacer la piece(0 0 pour changer de piece) : \n"; cin >> xf;xf--;
                cout << "colonne ou deplacer la piece(0 0 pour changer de piece) : \n"; cin >> yf;yf--;
                if(xf == -1 && yf == -1)
                    chgtpiece = 1;
            }

            if(chgtpiece==0)
            {
                joueurcourant = 2;
            }

            //p->AffichePiecePrise();
            p->TestPionArrive();
        }
        else if(joueurcourant == 2)
        {
            cout<<"L'ia est en train de jouer"<<endl;
            //Sleep(10000);
            p->lancerIA(6);
            //p->AffichePiecePrise();
            p->TestPionArrive();

            //p->Afficher();

            joueurcourant = 1;
        }


    }

    return 0;
}
