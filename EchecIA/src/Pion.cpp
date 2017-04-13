#include "../include/Pion.h"
using namespace std;

Pion::Pion()
{

}

bool Pion::DeplacementOK(int depX, int depY)
{
    if(GetCouleur() == 1)
    {
        if((depY==1) && (depX==0))
            return true;
    }
    else
    {
        if((depY==-1) && (depX==0))
            return true;
    }
    return false;
}
