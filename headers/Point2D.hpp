/**
 * @file Point2D.hpp
 * @brief Déclaration et implémentation de la classe template Point2D.
 *
 * La classe Point2D représente un point dans un plan 2D avec des coordonnées de type générique T.
 * Elle fournit des constructeurs, des accesseurs, des mutateurs, une méthode de translation et une surcharge de l'opérateur <<.
 *
 * @tparam T Type des coordonnées du point.
 */

#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <iostream>
using namespace std;

/**
 * @class Point2D
 * @brief Classe template représentant un point dans un plan 2D.
 *
 * @tparam T Type des coordonnées du point.
 */
template <typename T>
class Point2D
{
private:
    T x; ///< Coordonnée x du point.
    T y; ///< Coordonnée y du point.

public:
    /**
     * @brief Constructeur avec paramètres.
     *
     * @param x Coordonnée x initiale.
     * @param y Coordonnée y initiale.
     */
    Point2D(T x, T y);

    /**
     * @brief Constructeur par défaut.
     *
     * Initialise les coordonnées à 0.
     */
    Point2D();

    /**
     * @brief Constructeur de copie.
     *
     * @param p Point2D à copier.
     */
    Point2D(const Point2D<T> &p);

    /**
     * @brief Constructeur par conversion.
     *
     * Permet de convertir un Point2D d'un autre type en Point2D de type T.
     *
     * @tparam U Type des coordonnées du point à convertir.
     * @param p Point2D à convertir.
     */
    template <typename U>
    Point2D(const Point2D<U> &p);

    /**
     * @brief Accesseur pour la coordonnée x.
     *
     * @return La coordonnée x.
     */
    T getX() const;

    /**
     * @brief Accesseur pour la coordonnée y.
     *
     * @return La coordonnée y.
     */
    T getY() const;

    /**
     * @brief Mutateur pour la coordonnée x.
     *
     * @param x Nouvelle valeur pour la coordonnée x.
     */
    void setX(T x);

    /**
     * @brief Mutateur pour la coordonnée y.
     *
     * @param y Nouvelle valeur pour la coordonnée y.
     */
    void setY(T y);

    /**
     * @brief Méthode de translation.
     *
     * Translate le point de dx en x et dy en y.
     *
     * @param dx Déplacement en x.
     * @param dy Déplacement en y.
     */
    void translate(T dx, T dy);

    /**
     * @brief Surcharge de l'opérateur << pour l'affichage.
     *
     * @tparam U Type des coordonnées du point.
     * @param os Flux de sortie.
     * @param point Point à afficher.
     * @return Référence au flux de sortie.
     */
    template <typename U>
    friend ostream &operator<<(ostream &os, const Point2D<U> &point);
};

// Constructeurs
template <typename T>
Point2D<T>::Point2D(T x, T y) : x(x), y(y) {}

template <typename T>
Point2D<T>::Point2D() : x(0), y(0) {}

template <typename T>
Point2D<T>::Point2D(const Point2D<T> &p) : x(p.x), y(p.y) {}

// Constructeur par conversion
template <typename T>
template <typename U>
Point2D<T>::Point2D(const Point2D<U> &p) : x(static_cast<T>(p.getX())), y(static_cast<T>(p.getY())) {}

// Accesseurs
template <typename T>
T Point2D<T>::getX() const
{
    return x;
}

template <typename T>
T Point2D<T>::getY() const
{
    return y;
}

// Mutateurs
template <typename T>
void Point2D<T>::setX(T x)
{
    this->x = x;
}

template <typename T>
void Point2D<T>::setY(T y)
{
    this->y = y;
}

// Méthode de translation
template <typename T>
void Point2D<T>::translate(T dx, T dy)
{
    x += dx;
    y += dy;
}

// Opérateur << (fonction externe)
template <typename T>
ostream &operator<<(ostream &os, const Point2D<T> &point)
{
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}

#endif
