#ifndef ZAU_H
#define ZAU_H

#include <random>
#include "Constructible.hpp"
#include "Parcelle.hpp"

using namespace std;

class ZAU : public Constructible, public Parcelle<int> {
public:
    ZAU(int num, const string& prop, Polygone<int> polygone);

    void genererSurfaceConstructible() override;

    void setType(const string& type) override;

    friend ostream& operator<<(ostream& os, const ZAU& zau);
};

ZAU::ZAU(int num, const string& prop, Polygone<int> polygone) : Parcelle<int>(num, prop, polygone) {
    setType("Zone Agricole Urbaine");
    genererSurfaceConstructible();
}

void ZAU::genererSurfaceConstructible() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);

    dis(gen);

    Constructible::setSurfaceConstructible(dis(gen));
}

void ZAU::setType(const string& type) {
    Parcelle<int>::setType(type);
}

ostream& operator<<(ostream& os, const ZAU& zau) {
    os << "Parcelle n°" << zau.getNumero() << " :" << endl;
    os << "     Type : " << zau.getType() << endl;
    os << "     Propriétaire : " << zau.getProprietaire() << endl;
    os << "     Surface : " << zau.getSurface() << " m²" << endl;
    os << "     Surface constructible : " << zau.getSurfaceConstructible() << "%" << endl;
    os << "     " << zau.getForme() << endl;

    return os;
}

#endif
