//
// Created by natjo on 13/04/2017.
//

#ifndef ECHECIA_FOU_H
#define ECHECIA_FOU_H

#include "Piece.h"

class Fou : public Piece
{
    public:
        Fou();
        Fou(int couleur);
        virtual ~Fou();
        virtual int DeplacementOK(int depX, int depY, int tab[], int* tabl);
        virtual void Afficher();
    protected:
    private:
};


#endif //ECHECIA_FOU_H
