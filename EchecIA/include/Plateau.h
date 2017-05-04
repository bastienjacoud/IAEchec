#ifndef PLATEAU_H
#define PLATEAU_H

#include "Case.h"

class Plateau
{
    public:
        Plateau();
        virtual ~Plateau();
        int main();
        Case Getplateau(int i, int j) { return *m_plateau[i][j]; }
        void Setplateau(Case plateau[8][8]);
        void SetPiece(int i, int j, Piece* p);
        void Afficher();
        void prendrePiece(int xarrive, int yarrive);
    protected:
    private:
        Case* m_plateau[8][8];
};

#endif // PLATEAU_H
