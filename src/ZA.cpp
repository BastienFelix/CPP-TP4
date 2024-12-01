#include "../headers/ZA.hpp"

using namespace std;

ZA::ZA(int num, const string &prop, Polygone<int> polygone) : ZN(num, prop, polygone)
{
    setType("Zone Agripcole");
}

void ZA::setType(const string &type)
{
    Parcelle::setType(type);
}

ostream &operator<<(ostream &os, const ZA &za)
{
    os << "Parcelle n°" << za.getNumero() << " :" << endl;
    os << "     Type : " << za.getType() << endl;
    os << "     Propriétaire : " << za.getProprietaire() << endl;
    os << "     Surface : " << za.getSurface() << " m²" << endl;
    os << "     Surface constructible : 10%" << endl;
    os << "     " << za.getForme() << endl;

    return os;
}