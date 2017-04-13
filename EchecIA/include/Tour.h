#ifndef ECHECIA_TOUR_H
#define ECHECIA_TOUR_H

#include "Piece.h"

class Tour : public Piece
{
    public:
        Tour();
        virtual ~Tour();
        bool DeplacementOK(int depX, int depY);
};

#endif //ECHECIA_TOUR_H
