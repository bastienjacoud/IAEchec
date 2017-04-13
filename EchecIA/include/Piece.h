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
        int GetCouleur() {return m_couleur;}
        void SetCouleur(int couleur) {m_couleur = couleur;}
    protected:
        int m_posX;
        int m_posY;
        int m_couleur;//1 pour noir, 2 pour blanc
    private:

};

#endif // PIECE_H
