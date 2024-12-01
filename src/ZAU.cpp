#include "../headers/ZAU.hpp"

using namespace std;

ZAU::ZAU(int num, const string &prop, Polygone<int> polygone) : Parcelle(num, prop, polygone)
{
    setType("Zone Agricole Urbaine");
    Constructible::genererSurfaceConstructible();
}

void ZAU::setType(const string &type)
{
    Parcelle::setType(type);
}

ostream &operator<<(ostream &os, const ZAU &zau)
{
    os << "Parcelle n°" << zau.getNumero() << " :" << endl;
    os << "     Type : " << zau.getType() << endl;
    os << "     Propriétaire : " << zau.getProprietaire() << endl;
    os << "     Surface : " << zau.getSurface() << " m²" << endl;
    os << "     Surface constructible : " << zau.getSurfaceConstructible() << "%" << endl;
    os << "     " << zau.getForme() << endl;

    return os;
}