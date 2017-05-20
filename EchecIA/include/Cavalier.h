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
    protected:
    private:
};

#endif // CAVALIER_H
