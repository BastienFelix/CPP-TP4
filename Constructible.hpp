#ifndef CONSTRUCTIBLE_H
#define CONSTRUCTIBLE_H

#include "Parcelle.hpp"
#include <random>


class Constructible {
protected:
    int surfaceConstructible; 
public:
    Constructible();
    ~Constructible();
    

    int getSurfaceConstructible() const;
    void setSurfaceConstructible(int surface);
    
    void genererSurfaceConstructible();
};

Constructible::Constructible() {
    surfaceConstructible = 0;
}

Constructible::~Constructible() {

}

void Constructible::genererSurfaceConstructible() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);

    dis(gen);

    Constructible::setSurfaceConstructible(dis(gen));
}

int Constructible::getSurfaceConstructible() const {
    return surfaceConstructible;
}

void Constructible::setSurfaceConstructible(int surface) {
    surfaceConstructible = surface;
}

#endif
