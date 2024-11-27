#ifndef CARTE_H
#define CARTE_H

#include "Parcelle.hpp"
#include "Polygone.hpp"
#include "Point2D.hpp"
#include "ZA.hpp"
#include "ZAU.hpp"
#include "ZU.hpp"
#include "ZN.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Carte
{
private:
    int surfaceTotale;
    vector<Parcelle *> parcelles;

public:
    // Constructeur : charge les données à partir d'un fichier
    Carte(const string &cheminFichier);

    // Accesseur pour la surface totale
    int getSurfaceTotale() const;

    // Accesseur pour obtenir les parcelles
    vector<Parcelle *> getParcelles() const;

    // Méthode pour exporter les parcelles dans un fichier
    void exporterParcelles(const string &cheminFichier) const;

private:
    // Fonction utilitaire pour découper une chaîne en plusieurs sous-chaînes
    vector<string> split(string s, string delimiter);
};

// Constructeur : charge les données depuis un fichier
Carte::Carte(const string &cheminFichier)
{
    ifstream fichier(cheminFichier);

    if (!fichier.is_open())
    {
        throw runtime_error("Impossible d'ouvrir le fichier " + cheminFichier);
    }

    string ligne1, ligne2;
    while (getline(fichier, ligne1) && getline(fichier, ligne2))
    {
        istringstream ss(ligne1);
        string typeParcelle, numero, proprietaire;
        ss >> typeParcelle >> numero >> proprietaire;

        vector<Point2D<int>> points;
        istringstream ssPoints(ligne2);
        string pointStr;
        while (ssPoints >> pointStr)
        {
            int x, y;
            sscanf(pointStr.c_str(), "[%d;%d]", &x, &y);
            points.emplace_back(x, y);
        }

        Polygone<int> polygone(points);
        Parcelle *parcelle = nullptr;

        if (typeParcelle == "ZU")
        {
            parcelle = new ZU(stoi(numero), proprietaire, polygone);
        }
        else if (typeParcelle == "ZAU")
        {
            parcelle = new ZAU(stoi(numero), proprietaire, polygone);
        }
        else if (typeParcelle == "ZA")
        {
            parcelle = new ZA(stoi(numero), proprietaire, polygone);
        }
        else if (typeParcelle == "ZN")
        {
            parcelle = new ZN(stoi(numero), proprietaire, polygone);
        }

        if (parcelle)
        {
            parcelles.push_back(parcelle);
        }
    }

    fichier.close();

    for (auto parcelle : parcelles)
    {
        surfaceTotale += parcelle->getSurface();
    }
}

// Accesseur pour obtenir la surface totale
int Carte::getSurfaceTotale() const
{
    return surfaceTotale;
}

// Accesseur pour obtenir la liste des parcelles
vector<Parcelle *> Carte::getParcelles() const
{
    return parcelles;
}

// Méthode pour exporter les parcelles dans un fichier
void Carte::exporterParcelles(const string &cheminFichier) const
{
    ofstream fichier(cheminFichier);

    if (!fichier.is_open())
    {
        throw runtime_error("Impossible d'ouvrir le fichier " + cheminFichier);
    }

    for (const auto &parcelle : parcelles)
    {
        fichier << parcelle->getType() << " " << parcelle->getNumero() << " " << parcelle->getProprietaire() << endl;

        const auto &points = parcelle->getForme().getSommets();
        for (const auto &point : points)
        {
            fichier << "[" << point.getX() << ";" << point.getY() << "] ";
        }
        fichier << endl;
    }

    fichier.close();
}

#endif
