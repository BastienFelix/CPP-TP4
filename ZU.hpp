#ifndef ZU_H
#define ZU_H

#include "Constructible.h"

class ZU : public Constructible {
private:
    float ConstructibleRestante; 

public:
    ZU(int num, const string& prop, Polygone<int> forme, int pourcentage, float surfaceConstr)
        : Constructible(num, prop, forme, pourcentage), surfaceConstruite(surfaceConstr) {}

    
    float surfaceConstructible() const override {
        return (surface * surfaceConstructiblePercent / 100) - surfaceConstruite;
    }


    void TypeZ(const string& type) override {
        this->type = "Zone Urbaine";
    }

    friend ostream& operator<<(ostream& os, const ZU& zu) {
        os << "Type: " << zu.type << ", Numero: " << zu.numero
           << ", Proprietaire: " << zu.proprietaire
           << ", Surface Totale: " << zu.surface << " m²"
           << ", Surface Construite: " << zu.surfaceConstruite << " m²"
           << ", Surface Constructible Restante: " << zu.surfaceConstructible() << " m²";
        return os;
    }
};

#endif
