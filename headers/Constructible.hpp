
/**
 * @file Constructible.hpp
 * @brief Déclaration de la classe Constructible.
 *
 * Ce fichier contient la déclaration de la classe Constructible, qui représente une surface constructible.
 *
 * @author Votre Nom
 * @date Date de création
 */

#ifndef CONSTRUCTIBLE_HPP
#define CONSTRUCTIBLE_HPP

#include "Parcelle.hpp"
#include <random>

/**
 * @class Constructible
 * @brief Classe représentant une surface constructible.
 *
 * La classe Constructible permet de gérer une surface constructible avec des méthodes pour générer et
 * obtenir la surface constructible.
 */
class Constructible
{
protected:
    int surfaceConstructible; ///< Surface constructible en mètres carrés.
public:
    /**
     * @brief Constructeur par défaut.
     *
     * Initialise la surface constructible à 0.
     */
    Constructible();

    /**
     * @brief Destructeur.
     */
    ~Constructible();

    /**
     * @brief Obtient la surface constructible.
     *
     * @return La surface constructible en mètres carrés.
     */
    int getSurfaceConstructible() const;

    /**
     * @brief Définit la surface constructible.
     *
     * @param surface La nouvelle surface constructible en mètres carrés.
     */
    void setSurfaceConstructible(int surface);

    /**
     * @brief Génère une surface constructible aléatoire.
     *
     * Utilise un générateur de nombres aléatoires pour définir une surface constructible entre 0 et 100 mètres carrés.
     */
    void genererSurfaceConstructible();
};

Constructible::Constructible()
{
    surfaceConstructible = 0;
}

Constructible::~Constructible()
{
}

void Constructible::genererSurfaceConstructible()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);

    dis(gen);

    Constructible::setSurfaceConstructible(dis(gen));
}

int Constructible::getSurfaceConstructible() const
{
    return surfaceConstructible;
}

void Constructible::setSurfaceConstructible(int surface)
{
    surfaceConstructible = surface;
}

#endif // CONSTRUCTIBLE_HPP

