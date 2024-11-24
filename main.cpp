#include <iostream>
#include <vector>
#include "Parcelle.hpp"
#include "Polygone.hpp"
#include "Point2D.hpp"
#include "ZA.hpp"


using namespace std;

int main() {
    // Création de points pour définir un polygone
    Point2D<int> p1(0, 0);
    Point2D<int> p2(7, 0);
    Point2D<int> p3(10, 5);
    Point2D<int> p4(0, 9);

    // Création du polygone avec ces points
    vector<Point2D<int>> points = { p1, p2, p3, p4 };
    Polygone<int> poly(points);

    // Création d'une instance de ZA
    ZA za(1, "Bastien FELIX", poly);

    // Affichage des informations de ZA
    cout << za << endl;

    // Test de modification du type
    za.setType("Zone Agricole Modifiée");
    cout << "Type modifié : " << za.getType() << endl;

    return 0;
}
