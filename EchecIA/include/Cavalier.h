#ifndef CAVALIER_H
#define CAVALIER_H

#include "Piece.h"


class Cavalier : public Piece
{
    public:
        Cavalier();
        Cavalier(int couleur);
        virtual ~Cavalier();
        virtual void Afficher();
        virtual int DeplacementOK(int depX, int depY, int tab[], int* tabl);
        virtual int PriseOK(int depX, int depY, int tab[], int* tabl);
    protected:
    private:
};

#endif // CAVALIER_H
