#ifndef CASE_H
#define CASE_H

#include "Piece.h"
#include "Tour.h"
#include "Roi.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Pion.h"

class Case
{
    public:
        Case();
        virtual ~Case();
        Piece* Getpiece() { return m_piece; }
        Piece* Move();
        void Setpiece(Piece* val) { m_piece = val; }
        void Afficher();
        void ChangePiece(Piece* p);
    protected:
    private:
        Piece* m_piece;
};

#endif // CASE_H
