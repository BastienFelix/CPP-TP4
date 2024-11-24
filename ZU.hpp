#ifndef ZU_H
#define ZU_H

#include "Constructible.hpp"

class ZU : public Constructible, public Parcelle<int> {

public:
    ZU(int num, const string& prop, Polygone<int> polygone);

    void setType(const string& type) override;

    friend ostream& operator<<(ostream& os, const ZU& zu);
};

ZU::ZU(int num, const string& prop, Polygone<int> polygone) : Parcelle<int>(num, prop, polygone) {
    setType("Zone Urbaine");
    Constructible::genererSurfaceConstructible();
}

void ZU::setType(const string& type) {
    Parcelle<int>::setType(type);
}

ostream& operator<<(ostream& os, const ZU& zu) {
    os << "Parcelle n°" << zu.getNumero() << " :" << endl;
    os << "     Type : " << zu.getType() << endl;
    os << "     Propriétaire : " << zu.getProprietaire() << endl;
    os << "     Surface : " << zu.getSurface() << " m²" << endl;
    os << "     Surface constructible restante : " << zu.getSurfaceConstructible() << "%" << endl;
    os << "     " << zu.getForme() << endl;

    return os;
}

#endif
