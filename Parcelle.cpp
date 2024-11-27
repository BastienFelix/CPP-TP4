#include "Parcelle.hpp"

using namespace std;

Parcelle::Parcelle(int num, const string &prop, const Polygone<int> &p)
    : numero(num), proprietaire(prop), forme(p), surface(0), constructible(0)
{
    calculSurface();

    if (surface <= 0)
    {
        throw invalid_argument("La surface de la parcelle doit être strictement positive.");
    }
}

int Parcelle::getNumero() const
{
    return numero;
}

string Parcelle::getProprietaire() const
{
    return proprietaire;
}

float Parcelle::getSurface() const
{
    return surface;
}

Polygone<int> Parcelle::getForme() const
{
    return forme;
}

string Parcelle::getType() const
{
    return type;
}

void Parcelle::setNumero(int n)
{
    numero = n;
}

void Parcelle::setProprietaire(const string &prop)
{
    proprietaire = prop;
}

void Parcelle::setForme(const Polygone<int> &f)
{
    forme = f;
    calculSurface(); // Recalculer la surface si la forme change
}

void Parcelle::setType(const string &t)
{
    type = t;
}

void Parcelle::calculSurface()
{
    vector<Point2D<int>> points = this->forme.getSommets();

    // Vérification que le polygone a au moins 3 sommets
    if (points.size() < 3)
    {
        throw invalid_argument("Un polygone doit avoir au moins 3 sommets pour calculer une surface.");
    }

    float surfaceSum = 0.0;

    for (size_t i = 0; i < points.size(); i++)
    {
        int x_i = points[i].getX();
        int y_i = points[i].getY();

        int x_next = points[(i + 1) % points.size()].getX();
        int y_next = points[(i + 1) % points.size()].getY();

        surfaceSum += (x_i * y_next) - (x_next * y_i);
    }

    this->surface = abs(surfaceSum) / 2.0f;
}

// Surcharge de l'opérateur <<
ostream &operator<<(ostream &os, const Parcelle &parcelle)
{
    os << "Parcelle " << parcelle.numero
       << " (" << parcelle.proprietaire << ") : "
       << "Surface = " << parcelle.surface << " m²"
       << ", Type = " << parcelle.type;
    return os;
}