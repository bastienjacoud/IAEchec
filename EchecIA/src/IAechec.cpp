//
// Created by natjo on 20/05/2017.
//

#include "../include/IAechec.h"


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
case vide '_'
Joueur 1 'X'
Joueur 2 'O'
Joueur commence
*/
/*
int minCalc(char[3][3], char, int);
void series(char[3][3], int&, int&, int, char);
Plateau p;

char TestFin(Plateau pt) {
    //la partie se termine lorsque le roi adverse est prit ou en echec et mat
    //Lignes et colonnes
    int i = pt.getPiecesPrisent.size();                //PiecesPrisent = ArrayList des pieces qui se font prendre
    if (pt.getPiecesPrisent().get(i) == R1) {     //Les pieces sont nommées differemment en fonction de leur couleur (R1 couleur 1...)
        return 2;
    }
    if (pt.getPiecesPrisent().get(i) == R2) {
        return 1;
    }
    else{
        return ('_');
    }
}


/*
void Jouer(char grille[3][3], char c, int d)
{
    cout << endl;

    p.Afficher();

    cout << endl
         << "Entrez les coordonnees de la case a laquelle jouer." << endl
         << "Par exemple pour la seconde case de la premiere ligne, entrez \"1 0\"" << endl;
    int i = 0, j = 0;
    bool test;
    do
    {
        test = true;
        cin >> i >> j;
        if((i < 0) || (i > 2) || (j < 0) || (j > 2))
        {
            test = false;
            cout << "Entrez des valeurs entieres dans [0;2]." << endl;
        }
        else
        {
            if(grille[i][j] != '_')
            {
                test = false;
                cout << "Cette case est deja occupee." << endl;
            }
        }
    }while(!test);
    grille[i][j] = c;
}
 */

//Fonctions de l'IA
/*
int nbrPions(Plateau pt)
{
    int x = 0;
    for(int i=0; i<8; i++)
        for(int j=0;j<8;j++)
        {
            if(pt.Getplateau(i,j).Getpiece() != NULL){
                x++;
            }
        }
}

void series(char grille[3][3], int &serieJ1, int &serieJ2, int n, char c)//n le nombre de pions de la série
{
    int cpt1 = 0,
            cpt2 = 0,
            i, j;
    serieJ1 = 0;
    serieJ2 = 0;
    //diagonale1
    for(i = 0; i < 3; i++)
    {
        if(grille[i][i] == c)
        {
            cpt1++;
            cpt2 = 0;
            if(cpt1 == n)
                serieJ1++;
        }
        else if(grille[i][i] != '_')
        {
            cpt2++;
            cpt1 = 0;
            if(cpt2 == n)
                serieJ2++;
        }
    }

    cpt1 = 0;
    cpt2 = 0;

    //diagonale2
    for(i = 0; i < 3; i++)
    {
        if(grille[i][2-i] == c)
        {
            cpt1++;
            cpt2 = 0;
            if(cpt1 == n)
                serieJ1++;
        }
        else if(grille[i][2-i] != '_')
        {
            cpt2++;
            cpt1 = 0;
            if(cpt2 == n)
                serieJ2++;
        }
    }

    //Verticalement ou horizontalement
    for(i = 0; i < 3; i++)
    {
        //horizontalement
        cpt1 = 0;
        cpt2 = 0;
        for(j = 0; j < 3; j++)
        {
            if(grille[i][j] == c)
            {
                cpt1++;
                cpt2 = 0;
                if(cpt1 == n)
                    serieJ1++;
            }
            else if(grille[i][j] != '_')
            {
                cpt2++;
                cpt1 = 0;
                if(cpt2 == n)
                    serieJ2++;
            }
        }
        //verticalement
        cpt1 = 0;
        cpt2 = 0;
        for(j = 0; j < 3; j++)
        {
            if(grille[j][i] == c)
            {
                cpt1++;
                cpt2 = 0;
                if(cpt1 == n)
                    serieJ1++;
            }
            else if(grille[j][i] != '_')
            {
                cpt2++;
                cpt1 = 0;
                if(cpt2 == n)
                    serieJ2++;
            }
        }
    }

}

int evaluation(Plateau pt, char c)
{
    char t;
    //si partie finie
    if((t = TestFin(pt)) != '_')
    {
        if(t == c)
            return (1000 - nbrPions(pt));
        if(t == ' ')
            return 0;
        return (nbrPions(pt) - 1000);
    }

    int serieJ1, serieJ2;
 //   series(grille, serieJ1, serieJ2, 2, c);
    return (serieJ1 - serieJ2);
}

int maxCalc(char grille[3][3],char c, int profondeur)
{
    int maximum = -10000;

    if((profondeur == 0) || (TestFin(grille) != '_'))
        return evaluation(grille, c);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grille[i][j] == '_')
            {
                grille[i][j] = c;
                int tmp = minCalc(grille, c, profondeur - 1);

                if((tmp > maximum) || ((tmp == maximum) && ((rand() % 2) == 0)))
                    maximum = tmp;
                grille[i][j] = '_';
            }
        }
    }
    return maximum;
}

int minCalc(char grille[3][3], char c, int profondeur)
{
    int minimum = 10000;

    if((profondeur == 0) || (TestFin(grille) != '_'))
        return evaluation(grille, c);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grille[i][j] == '_')
            {
                grille[i][j] = (c == 'X') ? 'O' : 'X';
                int tmp = maxCalc(grille, c, profondeur - 1);

                if((tmp < minimum) || ((tmp == minimum) && ((rand() % 2) == 0)))
                    minimum = tmp;
                grille[i][j] = '_';
            }
        }
    }
    return minimum;
}

//La difficulté est la profondeur de parcours de l'arbre
void IARecJouer(char grille[3][3], char c, int difficulte)
{
    int maximum = -10000,
            maxi, maxj;
    //Affichage(grille);
    p.Afficher();

    //Même systeme que maxCalc avec enregistrement des indices
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grille[i][j] == '_')
            {
                grille[i][j] = c;
                int tmp = minCalc(grille, c, difficulte - 1);
                if((tmp > maximum) || ((tmp == maximum) && ((rand() % 2) == 0)))
                {
                    maximum = tmp;
                    maxi = i;
                    maxj = j;
                }
                grille[i][j] = '_';
            }
        }
    }
    grille[maxi][maxj] = c;
}
*/

/*
void IAIteJouer(char grille[3][3], char c, int d)
{
    //IA itérative
    //On commence par vérifier s'il y a des cases qui nous permettent de gagner
    for(int i = 0; i < 3; i++)
    {
        //On regarde les lignes et les colonnes
        int ctrL = 0, ctrC = 0;
        for(int j = 0; j < 3; j++)
        {
            ctrL += (grille[i][j] == c);
            ctrC += (grille[j][i] == c);
        }
        if(ctrL == 2)
        {
            //Il y a possibilite de gagner
            for(int j = 0; j < 3; j++)
            {
                if(grille[i][j] == '_')
                {
                    grille[i][j] = c;
                    return;
                }
            }
        }
        if(ctrC == 2)
        {
            //Il y a possibilite de gagner
            for(int j = 0; j < 3; j++)
            {
                if(grille[j][i] == '_')
                {
                    grille[j][i] = c;
                    return;
                }
            }
        }
    }
    //Pour les diagonales
    int ctrD1 = 0, ctrD2 =0;
    //On regarde les diagonales où il y a 2 de nos pions
    for(int i=0;i<3;i++)
    {
        ctrD1 += (grille[i][i] == c);
        ctrD2 += (grille[i][2-i] == c);
    }
    if(ctrD1 == 2)
    {
        for(int i=0;i<3;i++)
        {
            //s'il y possibilité de gagner
            if(grille[i][i] == '_')
            {
                grille[i][i] =c;
                return;
            }
        }

    }
    if(ctrD2 == 2)
    {
        for(int i=0;i<3;i++)
        {
            //s'il y a possibilité de gagner
            if(grille[i][2-i] == '_')
            {
                grille[i][2-i] =c;
                return;
            }
        }

    }

    //S'il n'y en a pas on regarde s'il y a des cases qui peuvent nous éviter de perdre au prochain tour
    for(int i = 0; i < 3; i++)
    {
        //On regarde les lignes et les colonnes
        int ctrL = 0, ctrC = 0;
        for(int j = 0; j < 3; j++)
        {
            ctrL += ((grille[i][j] != c) && (grille[i][j] != '_'));
            ctrC += ((grille[j][i] != c) && (grille[j][i] != '_'));
        }
        if(ctrL == 2)
        {
            //Il y a possibilite de ne pas perdre
            for(int j = 0; j < 3; j++)
            {
                if(grille[i][j] == '_')
                {
                    grille[i][j] = c;
                    return;
                }
            }
        }
        if(ctrC == 2)
        {
            //Il y a possibilite de ne pas perdre
            for(int j = 0; j < 3; j++)
            {
                if(grille[j][i] == '_')
                {
                    grille[j][i] = c;
                    return;
                }
            }
        }
    }
    ctrD1 = 0, ctrD2 = 0;
    //on regarde les idagonales où il y a 2 pions adverses
    for(int i=0;i<3;i++)
    {
        ctrD1 += ((grille[i][i] != c) && (grille[i][i] != '_'));
        ctrD2 += ((grille[i][2-i] != c) && (grille[i][2-i] != '_'));
    }
    if(ctrD1 == 2)
    {
        for(int i=0;i<3;i++)
        {
            //si l'y a possibilité de ne pas perdre
            if(grille[i][i] == '_')
            {
                grille[i][i] = c;
                return;
            }
        }
    }
    if(ctrD2 == 2)
    {
        for(int i=0;i<3;i++)
        {
            //si l'y a possibilité de ne pas perdre
            if(grille[i][2-i] == '_')
            {
                grille[i][2-i] = c;
                return;
            }
        }
    }

    //Sinon on joue au hasard
    int ctr = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            ctr += (grille[i][j] == '_');
    }
    ctr = (rand() % ctr);
    for(int i = 0; (i < 3) && (ctr >= 0); i++)
    {
        for(int j = 0; (j < 3) && (ctr >= 0); j++)
        {
            if(grille[i][j] == '_')
            {
                if(ctr == 0)
                    grille[i][j] = c;
                ctr--;
            }
        }
    }
}
*/

/*
int InitJoueurType(int nJoueur)
{
    cout << endl
         << "Voulez vous que le joueur " << nJoueur + 1 << " soit : " << endl
         << " 1 : Un joueur humain" << endl
         << " 2 : Une IA recursive" << endl
         << " 3 : Une IA Iterative" << endl;
    int type = 1;
    do
    {
        if((type < 1) || (type > 3))
            cout << "Entrez une valeur valide." << endl;
        cin >> type;
    }while((type < 1) || (type > 9));
    return type;
}
*/

/*

int NiveauIA()
{
    cout << "Quel niveau voulez vous pour votre IA, entre 1 et 9" << endl
         << "1 : Faible, 9 : Forte" << endl;
    int niveau = 1;
    do
    {
        if((niveau < 1) || (niveau > 9))
            cout << "Entrez une valeur entre 1 et 9 compris." << endl;
        cin >> niveau;
    }while((niveau < 1) || (niveau > 9));
    return niveau;
}
 */

/*
int main()
{
    srand(time(NULL));
    char g;
    void (*Joueurs[2])(char[3][3], char, int);
    void (*Joueur2)(char[3][3], char, int);
    do
    {
        int nIA = 1, niveau = 1;
        cout << endl
             << "Jeu de morpion : " << endl
             << " > Joueur 1 : X" << endl
             << " > Joueur 2 : O" << endl
             << "Le joueur commence." << endl
             << endl;
        //Initialisation des joueurs
        for(int i = 0; i < 2; i++)
        {
            //On choisi le type du joueur i
            switch(InitJoueurType(i))
            {
                case 1 :
                    //Joueur humain
                    Joueurs[i] = Jouer;
                    break;

                case 2 :
                    //IA recursive
                    Joueurs[i] = IARecJouer;
                    niveau = NiveauIA();
                    break;

                default :
                    //IA itérative
                    Joueurs[i] = IAIteJouer;
            }
        }

        g = '_';
        char grille[3][3];
        GInit(grille);
        //Jeu
        while((g == '_') && ((g = TestFin(grille)) == '_'))
        {
            //Jeu du joueur
            cout << "J1" << endl;
            Joueurs[0](grille, 'X', niveau);
            if((g = TestFin(grille)) == '_')
            {
                //Jeu de l'IA
                cout << "J2" << endl;
                Joueurs[1](grille, 'O', niveau);
            }
        }
        //Gagnant
        switch(g)
        {
            case ' ' :
                cout << "Match nul !" << endl;
                break;

            case 'X' :
                cout << "Bravo Joueur 1, tu as gagne." << endl;
                break;

            case 'O' :
                cout << "Bravo Joueur 2, tu as gagne." << endl;
                break;

            default :
                cout << "Cas etrange..." << endl;
                break;
        }
        cout << "Pour quitter, entrez Q, pour recommencer entrez n'importe quelle autre valeur" << endl;
        cin >> g;
    }while(g != 'Q');
    return 0;
}
*/
