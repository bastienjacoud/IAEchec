#ifndef CAVALIER_H
#define CAVALIER_H

#include <Piece.h>


class Cavalier : public Piece
{
    public:
        Cavalier();
        virtual ~Cavalier();
        bool DeplacementOK(int depX, int depY);
    protected:
    private:
};

#endif // CAVALIER_H
