#ifndef CASE_H
#define CASE_H

#include "Piece.h"
#include "Tour.h"

class Case
{
    public:
        Case();
        virtual ~Case();
        Piece* Getpiece() { return m_piece; }
        void Setpiece(Piece* val) { m_piece = val; }
        void Afficher();
        void ChangePiece(Piece* p);
    protected:
    private:
        Piece* m_piece;
};

#endif // CASE_H
