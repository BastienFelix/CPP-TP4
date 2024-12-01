#include <iostream>
#include <vector>
#include "../headers/Parcelle.hpp"
#include "../headers/Carte.hpp"

using namespace std;

int main() {
    Carte carte("../Parcelles.txt");
    vector<Parcelle *> parcelles = carte.getParcelles();

    for (Parcelle *parcelle : parcelles) {
        cout << *parcelle << endl;
    }

    cout << carte.getSurfaceTotale() << " m²" << endl;

    carte.exporterParcelles("Parcelles_export.txt");

    return 0;
}