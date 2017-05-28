#ifndef PLATEAU_H
#define PLATEAU_H

#include <vector>
#include "Case.h"

class Plateau
{
    public:
        Plateau();
        virtual ~Plateau();
        int main();
        Case& Getplateau(int i, int j) { return *m_plateau[i][j]; }//ligne puis colonne
        void Setplateau(Case plateau[8][8]);
        void SetPiece(int i, int j, Piece* p);
        void Afficher();
        int prendrePiece(int xdep, int ydep, int xarrive, int yarrive);
        int DeplacerPiece(int xdep, int ydep, int xarrivee, int yarrivee);
        int TestFinJeu();
        void AjoutePiecePrise(Piece* p);
        void SupprimePiecePrise(Piece p);
        void AffichePiecePrise();
        void TestPionArrive();
        void deplacementPossible(int couleur);
    protected:
    private:
        Case* m_plateau[8][8];
        Piece* piecesPrisent[24];
        int np = 0;
        int pos_possible[368][4];
};

#endif // PLATEAU_H
