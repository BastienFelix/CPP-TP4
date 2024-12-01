#include "../headers/ZN.hpp"

using namespace std;

ZN::ZN(int num, const string &prop, Polygone<int> polygone) : Parcelle(num, prop, polygone)
{
    setType("Zone Naturelle et forestière");
}

void ZN::setType(const string &type)
{
    Parcelle::setType(type);
}

ostream &operator<<(ostream &os, const ZN &zn)
{
    os << "Parcelle n°" << zn.getNumero() << " :" << endl;
    os << "     Type : " << zn.getType() << endl;
    os << "     Propriétaire : " << zn.getProprietaire() << endl;
    os << "     Surface : " << zn.getSurface() << " m²" << endl;
    os << "     Surface constructible : 0%" << endl;
    os << "     " << zn.getForme() << endl;

    return os;
}