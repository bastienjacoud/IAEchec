#ifndef ECHECIA_TOUR_H
#define ECHECIA_TOUR_H

#include "Piece.h"

class Tour : public Piece
{
    public:
        Tour();
        Tour(int couleur);
        Tour(Piece& p);
        virtual ~Tour();
        virtual int DeplacementOK(int depX, int depY, int tab[], int& tabl);
        virtual int PriseOK(int depX, int depY, int tab[], int& tabl);
        virtual void Afficher();
        virtual char getType(){ return 'T';}
    private:
        //int
};

#endif //ECHECIA_TOUR_H
