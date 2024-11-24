#include <iostream>
#include <vector>
#include "Parcelle.hpp"
#include "Polygone.hpp"
#include "Point2D.hpp"
#include "ZAU.hpp"

using namespace std;

int main() {
    // Création de points pour définir un polygone
    Point2D<int> p1(0, 0);
    Point2D<int> p2(4, 0);
    Point2D<int> p3(4, 3);
    Point2D<int> p4(0, 3);

    // Création du polygone avec ces points
    vector<Point2D<int>> points = { p1, p2, p3, p4 };
    Polygone<int> poly(points);

    // Création d'une instance de ZAU
    ZAU zau(1, "Tommy Royer", poly);

    // Affichage des informations de ZAU
    cout << zau << endl;

    return 0;
}