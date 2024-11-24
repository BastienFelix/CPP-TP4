#ifndef ZA_H
#define ZA_H

#include "ZN.hpp"

class ZA : public ZN {
private:
    string typeCulture; 
    ZA(int num, const string& prop, Polygone<int> forme, const string& culture)
        : ZN(num, prop, forme), typeCulture(culture) {}

    
    void TypeZ(const string& type) override {
        this->type = "Zone Agricole";
    }

    friend ostream& operator<<(ostream& os, const ZA& za) {
        os << "Type: " << za.type << ", Numero: " << za.numero
           << ", Proprietaire: " << za.proprietaire
           << ", Surface Totale: " << za.surface << " m²"
           << ", Type de Culture: " << za.typeCulture;
        return os;
    }
};

#endif
