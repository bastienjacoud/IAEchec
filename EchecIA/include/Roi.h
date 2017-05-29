#ifndef ECHECIA_ROI_H
#define ECHECIA_ROI_H

#include "Piece.h"


class Roi : public Piece
{
    public:
        Roi();
        Roi(int couleur);
        Roi(Piece& p);
        virtual ~Roi();
        virtual void Afficher();
        virtual int DeplacementOK(int depX, int depY, int tab[], int& tabl);
        virtual int PriseOK(int depX, int depY, int tab[], int& tabl);
        virtual char getType(){ return 'R';}
    protected:
    private:
};

#endif // ECHECIA_ROI_H
