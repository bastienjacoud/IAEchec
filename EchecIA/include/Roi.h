#ifndef ROI_H
#define ROI_H

#include "Piece.h"


class Roi : public Piece
{
    public:
        Roi();
        Roi(int couleur);
        virtual ~Roi();
        virtual void Afficher();
        virtual int DeplacementOK(int depX, int depY, int tab[], int* tabl);
        virtual int PriseOK(int depX, int depY, int tab[], int* tabl);
    protected:
    private:
};

#endif // ROI_H
