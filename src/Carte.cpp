#include "headers/Carte.hpp"
#include "headers/Polygone.hpp"
#include "headers/Point2D.hpp"
#include "headers/ZA.hpp"
#include "headers/ZAU.hpp"
#include "headers/ZU.hpp"
#include "headers/ZN.hpp"

using namespace std;

Carte::Carte(const string &cheminFichier) {
    ifstream fichier(cheminFichier);

    if (!fichier.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier " + cheminFichier);
    }

    string ligne1, ligne2;
    while (getline(fichier, ligne1) && getline(fichier, ligne2)) {
        istringstream ss(ligne1);
        string typeParcelle, numero, proprietaire;
        ss >> typeParcelle >> numero >> proprietaire;

        vector<Point2D<int>> points;
        istringstream ssPoints(ligne2);
        string pointStr;
        while (ssPoints >> pointStr) {
            int x, y;
            sscanf(pointStr.c_str(), "[%d;%d]", &x, &y);
            points.emplace_back(x, y);
        }

        Polygone<int> polygone(points);
        Parcelle *parcelle = nullptr;

        if (typeParcelle == "ZU") {
            parcelle = new ZU(stoi(numero), proprietaire, polygone);
        } else if (typeParcelle == "ZAU") {
            parcelle = new ZAU(stoi(numero), proprietaire, polygone);
        } else if (typeParcelle == "ZA") {
            parcelle = new ZA(stoi(numero), proprietaire, polygone);
        } else if (typeParcelle == "ZN") {
            parcelle = new ZN(stoi(numero), proprietaire, polygone);
        }

        if (parcelle) {
            parcelles.push_back(parcelle);
        }
    }

    fichier.close();

    for (auto parcelle : parcelles) {
        surfaceTotale += parcelle->getSurface();
    }
}

int Carte::getSurfaceTotale() const {
    return surfaceTotale;
}

vector<Parcelle *> Carte::getParcelles() const {
    return parcelles;
}

void Carte::exporterParcelles(const string &cheminFichier) const {
    ofstream fichier(cheminFichier);

    if (!fichier.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier " + cheminFichier);
    }

    for (const auto &parcelle : parcelles) {
        fichier << parcelle->getType() << " " << parcelle->getNumero() << " " << parcelle->getProprietaire() << endl;

        const auto &points = parcelle->getForme().getSommets();
        for (const auto &point : points) {
            fichier << "[" << point.getX() << ";" << point.getY() << "] ";
        }
        fichier << endl;
    }

    fichier.close();
}