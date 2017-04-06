#ifndef PION_H
#define PION_H


class Pion
{
    public:
        Pion();
        virtual ~Pion();
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

#endif // PION_H
