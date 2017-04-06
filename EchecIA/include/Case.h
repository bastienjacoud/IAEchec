#ifndef CASE_H
#define CASE_H

#include "Pion.h"

class Case
{
    public:
        Case();
        virtual ~Case();
        Pion Getpion() { return m_pion; }
        void Setpion(Pion val) { m_pion = val; }
    protected:
    private:
        Pion m_pion;
};

#endif // CASE_H
