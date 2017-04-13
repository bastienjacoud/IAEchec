#ifndef PIECE_H
#define PIECE_H


class Piece
{
    public:
        Piece();
        virtual ~Piece();
        int GetposX() { return m_posX; }
        void SetposX(int val) { m_posX = val; }
        int GetposY() { return m_posY; }
        void SetposY(int val) { m_posY = val; }
    protected:
    private:
        int m_posX;
        int m_posY;
        int m_b;
};

#endif // PIECE_H
