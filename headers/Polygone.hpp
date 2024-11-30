/**
 * @file Polygone.hpp
 * @brief Déclaration et implémentation de la classe template Polygone.
 *
 * Ce fichier contient la déclaration et l'implémentation de la classe template Polygone,
 * qui représente un polygone dans un espace 2D. La classe utilise des objets Point2D pour
 * représenter les sommets du polygone.
 *
 * @tparam T Type des coordonnées des points du polygone.
 */

#ifndef POLYGONE_HPP
#define POLYGONE_HPP

#include <vector>
#include "Point2D.hpp"

using namespace std;

/**
 * @class Polygone
 * @brief Classe template représentant un polygone en 2D.
 *
 * La classe Polygone permet de créer et manipuler des polygones en 2D. Elle offre des
 * méthodes pour obtenir et définir les sommets, ajouter des points, et translater le polygone.
 *
 * @tparam T Type des coordonnées des points du polygone.
 */
template <typename T>
class Polygone
{

private:
    vector<Point2D<T>> sommets;

public:
    /**
     * @brief Constructeur par défaut de la classe Polygone.
     *
     * Initialise un polygone vide.
     */
    Polygone();

    /**
     * @brief Constructeur avec liste de sommets.
     *
     * Initialise un polygone avec une liste de sommets donnée.
     *
     * @param listeSommets Vecteur de points représentant les sommets du polygone.
     */
    Polygone(const vector<Point2D<T>> &listeSommets);

    /**
     * @brief Constructeur de copie.
     *
     * Initialise un polygone en copiant un autre polygone.
     *
     * @param poly Polygone à copier.
     */
    Polygone(const Polygone<T> &poly);

    /**
     * @brief Obtient les sommets du polygone.
     *
     * @return Vecteur de points représentant les sommets du polygone.
     */
    vector<Point2D<T>> getSommets() const;

    /**
     * @brief Définit les sommets du polygone.
     *
     * @param listeSommets Vecteur de points représentant les nouveaux sommets du polygone.
     */
    void setSommets(const vector<Point2D<T>> &listeSommets);

    /**
     * @brief Ajoute un point au polygone.
     *
     * @param point Point à ajouter au polygone.
     */
    void addPoint(const Point2D<T> &point);

    /**
     * @brief Translate le polygone.
     *
     * Déplace tous les sommets du polygone de (x, y).
     *
     * @param x Déplacement en x.
     * @param y Déplacement en y.
     */
    void translate(T x, T y);

    /**
     * @brief Surcharge de l'opérateur de flux de sortie.
     *
     * Permet d'afficher les informations du polygone dans un flux de sortie.
     *
     * @tparam U Type des coordonnées des points du polygone.
     * @param os Flux de sortie.
     * @param poly Polygone à afficher.
     * @return Référence au flux de sortie.
     */
    template <typename U>
    friend ostream &operator<<(ostream &os, const Polygone<U> &poly);
};

template <typename T>
Polygone<T>::Polygone() : sommets() {}

template <typename T>
Polygone<T>::Polygone(const vector<Point2D<T>> &listeSommets) : sommets(listeSommets) {}

template <typename T>
Polygone<T>::Polygone(const Polygone<T> &poly) : sommets(poly.sommets) {}

template <typename T>
vector<Point2D<T>> Polygone<T>::getSommets() const
{
    return sommets;
}

template <typename T>
void Polygone<T>::setSommets(const vector<Point2D<T>> &listeSommets)
{
    sommets = listeSommets;
}

template <typename T>
void Polygone<T>::addPoint(const Point2D<T> &point)
{
    sommets.push_back(point);
}

template <typename T>
void Polygone<T>::translate(T x, T y)
{
    for (auto &sommet : sommets)
    {
        sommet.translate(x, y);
    }
}

template <typename T>
ostream &operator<<(ostream &os, const Polygone<T> &poly)
{
    os << "Polygone: ";
    for (const auto &sommet : poly.sommets)
    {
        os << sommet << " ";
    }
    return os;
}

#endif
