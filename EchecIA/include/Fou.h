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
        bool DeplacementOK(int depX, int depY);
        void Afficher();
    protected:
    private:
};


#endif //ECHECIA_FOU_H
