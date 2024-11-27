#ifndef PARCELLE_HPP
#define PARCELLE_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "Polygone.hpp"

using namespace std;

class Parcelle
{
public:
    Parcelle(int num, const string &prop, const Polygone<int> &p);

    // Mutateurs
    void setNumero(int n);
    void setProprietaire(const string &prop);
    void setForme(const Polygone<int> &forme);
    virtual void setType(const string &type);

    // Accesseurs
    int getNumero() const;
    string getProprietaire() const;
    float getSurface() const;
    Polygone<int> getForme() const;
    string getType() const;

    // Méthodes
    void calculSurface();

    // Surcharge de l'opérateur <<
    friend ostream &operator<<(ostream &os, const Parcelle &parcelle);

private:
    int numero;
    string proprietaire;
    Polygone<int> forme;
    double surface;
    bool constructible;
    string type;
};

#endif
