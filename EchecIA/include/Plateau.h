#ifndef PLATEAU_H
#define PLATEAU_H

#include "Case.h"

class Plateau
{
    public:
        Plateau();
        virtual ~Plateau();
        int main();
        Case Getplateau(int i, int j) { return m_plateau[i][j]; }
        void Setplateau(Case plateau[8][8]);
    protected:
    private:
        Case m_plateau[8][8];
};

#endif // PLATEAU_H
