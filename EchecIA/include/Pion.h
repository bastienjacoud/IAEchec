#ifndef ECHECIA_PION_H
#define ECHECIA_PION_H

#include "Piece.h"

class Pion : public Piece
{
    public:
        Pion();
        bool DeplacementOK(int depX, int depY);
};
#endif //ECHECIA_PION_H
