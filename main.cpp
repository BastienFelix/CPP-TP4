#include <iostream>
#include <vector>
#include "Parcelle.hpp"
#include "Polygone.hpp"
#include "Point2D.hpp"
#include "Carte.hpp"
#include "ZA.hpp"

using namespace std;

int main()
{
    // Création de points pour définir un polygone
    Carte carte("Parcelles_short.txt");
    vector<Parcelle *> parcelles = carte.getParcelles();

    for (Parcelle *parcelle : parcelles)
    {
        cout << *parcelle << endl;
    }

    cout << carte.getSurfaceTotale() << " m²" << endl;

    carte.exporterParcelles("Parcelles_export.txt");

    return 0;
}
