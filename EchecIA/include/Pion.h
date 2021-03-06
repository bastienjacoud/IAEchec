#ifndef ECHECIA_PION_H
#define ECHECIA_PION_H

#include "Piece.h"

class Pion : public Piece
{
    public:
        Pion();
        Pion(int couleur);
        Pion(Piece& p);
        virtual ~Pion();
        virtual void Afficher();
        virtual int DeplacementOK(int depX, int depY, int tab[], int& tabl);
        virtual int PriseOK(int depX, int depY, int tab[], int& tabl);
        virtual char getType(){ return 'P';}
        virtual void SetPremierCoup(int coup);
    private:
        int premierCoup;//vaut 1 si c'est le premier coup, 0 sinon
};
#endif //ECHECIA_PION_H
