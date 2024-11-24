#ifndef PARCELLE_H
#define PARCELLE_H

#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "Polygone.hpp"

using namespace std;

template <typename T>
class Parcelle {
public:
    Parcelle(int num, const string& prop, const Polygone<T>& p);

    // Mutateurs
    void setNumero(int n);
    void setProprietaire(const string& prop);
    void setForme(const Polygone<T>& forme);
    virtual void setType(const string& type);

    // Accesseurs
    int getNumero() const;
    string getProprietaire() const;
    float getSurface() const;
    Polygone<T> getForme() const;
    string getType() const;

    // Méthodes
    void calculSurface();

    // Surcharge de l'opérateur <<
    template <typename U>
    friend ostream& operator<<(ostream& os, const Parcelle<U>& parcelle);

private:
    int numero;
    string proprietaire;
    Polygone<T> forme;
    double surface;
    bool constructible;
    string type;
};

template <typename T>
Parcelle<T>::Parcelle(int num, const string& prop, const Polygone<T>& p)
    : numero(num), proprietaire(prop), forme(p), surface(0), constructible(0) {
    calculSurface();

    if (surface <= 0) {
        throw invalid_argument("La surface de la parcelle doit être strictement positive.");
    }
}

template <typename T>
int Parcelle<T>::getNumero() const {
    return numero;
}

template <typename T>
string Parcelle<T>::getProprietaire() const {
    return proprietaire;
}

template <typename T>
float Parcelle<T>::getSurface() const {
    return surface;
}

template <typename T>
Polygone<T> Parcelle<T>::getForme() const {
    return forme;
}

template <typename T>
string Parcelle<T>::getType() const {
    return type;
}

template <typename T>
void Parcelle<T>::setNumero(int n) {
    numero = n;
}

template <typename T>
void Parcelle<T>::setProprietaire(const string& prop) {
    proprietaire = prop;
}

template <typename T>
void Parcelle<T>::setForme(const Polygone<T>& f) {
    forme = f;
    calculSurface(); // Recalculer la surface si la forme change
}

template <typename T>
void Parcelle<T>::setType(const string& t) {
    type = t;
}

template <typename T>
void Parcelle<T>::calculSurface() {
    vector<Point2D<T>> points = this->forme.getSommets();

    // Vérification que le polygone a au moins 3 sommets
    if (points.size() < 3) {
        throw invalid_argument("Un polygone doit avoir au moins 3 sommets pour calculer une surface.");
    }

    float surfaceSum = 0.0;

    for (size_t i = 0; i < points.size(); i++) {
        int x_i = points[i].getX();
        int y_i = points[i].getY();

        int x_next = points[(i + 1) % points.size()].getX();
        int y_next = points[(i + 1) % points.size()].getY();

        surfaceSum += (x_i * y_next) - (x_next * y_i);
    }

    this->surface = abs(surfaceSum) / 2.0f;
}

// Surcharge de l'opérateur <<
template <typename T>
ostream& operator<<(ostream& os, const Parcelle<T>& parcelle) {
    os << "Parcelle " << parcelle.numero
       << " (" << parcelle.proprietaire << ") : "
       << "Surface = " << parcelle.surface << " m²"
       << ", Type = " << parcelle.type;
    return os;
}

#endif
