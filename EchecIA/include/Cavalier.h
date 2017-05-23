//
// Created by natjo on 23/05/2017.
//

#ifndef ECHECIA_CAVALIER_H
#define ECHECIA_CAVALIER_H

#include "Piece.h"


class Cavalier : public Piece
{
    public:
        Cavalier();
        Cavalier(int couleur);
        virtual ~Cavalier();
        virtual void Afficher();
        virtual int DeplacementOK(int depX, int depY, int tab[], int* tabl);
        virtual char getType(){ return 'C';}
    protected:
    private:
};


#endif //ECHECIA_CAVALIER_H


