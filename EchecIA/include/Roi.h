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
    protected:
    private:
};

#endif // ROI_H
