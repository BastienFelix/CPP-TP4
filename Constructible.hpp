#ifndef CONSTRUCTIBLE_H
#define CONSTRUCTIBLE_H

#include "Parcelle.hpp"

class Constructible {
protected:
    int surfaceConstructible; 
public:
    Constructible();
    ~Constructible();

    int getSurfaceConstructible() const;
    void setSurfaceConstructible(int surface);

    virtual void genererSurfaceConstructible() = 0;
};

Constructible::Constructible() {
    surfaceConstructible = 0;
}

Constructible::~Constructible() {

}

int Constructible::getSurfaceConstructible() const {
    return surfaceConstructible;
}

void Constructible::setSurfaceConstructible(int surface) {
    surfaceConstructible = surface;
}

#endif
