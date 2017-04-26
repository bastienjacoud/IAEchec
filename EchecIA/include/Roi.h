#ifndef ROI_H
#define ROI_H

#include <Piece.h>


class Roi : public Piece
{
    public:
        Roi();
        virtual ~Roi();
        bool DeplacementOK(int depX, int depY);
    protected:
    private:
};

#endif // ROI_H
