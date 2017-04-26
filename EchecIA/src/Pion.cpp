#include <array>
#include "../include/Pion.h"
using namespace std;

Pion::Pion()
{

}

bool Pion::DeplacementOK(int depX, int depY)
{
    if(GetCouleur() == 1)
    {
        if((depX==1) && (depY==0))
            return true;
    }
    else
    {
        if((depX==-1) && (depY==0))
            return true;
    }
    return false;
}
