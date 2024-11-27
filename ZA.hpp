#ifndef ZA_H
#define ZA_H

#include "ZN.hpp"
#include "Parcelle.hpp"

class ZA : public ZN {
public:
    ZA(int num, const string& prop, Polygone<int> polygone);
    void setType(const string& type) override;
    friend ostream& operator<<(ostream& os, const ZA& za);
};

ZA::ZA(int num, const string& prop, Polygone<int> polygone) : ZN(num, prop, polygone) {
    setType("Zone Agricole");
}

void ZA::setType(const string& type) {
    Parcelle::setType(type);
}

ostream& operator<<(ostream& os, const ZA& za) {
    os << "Parcelle n°" << za.getNumero() << " :" << endl;
    os << "     Type : " << za.getType() << endl;
    os << "     Propriétaire : " << za.getProprietaire() << endl;
    os << "     Surface : " << za.getSurface() << " m²" << endl;
    os << "     Surface constructible : 10%" << endl;
    os << "     " << za.getForme() << endl;

    return os;
}

#endif
