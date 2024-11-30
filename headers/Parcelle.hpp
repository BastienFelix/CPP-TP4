/**
 * @file Parcelle.hpp
 * @brief Déclaration de la classe Parcelle représentant une parcelle de terrain.
 *
 * La classe Parcelle contient des informations sur une parcelle de terrain,
 * telles que son numéro, son propriétaire, sa forme géométrique, sa surface,
 * et son type (constructible ou non).
 *
 * @version 1.0
 * @date 2023-10-05
 *
 */

#ifndef PARCELLE_HPP
#define PARCELLE_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "Polygone.hpp"

using namespace std;

/**
 * @class Parcelle
 * @brief Classe représentant une parcelle de terrain.
 *
 * La classe Parcelle permet de gérer les informations relatives à une parcelle
 * de terrain, y compris son numéro, son propriétaire, sa forme géométrique,
 * sa surface, et son type (constructible ou non).
 */
class Parcelle
{
public:
    /**
     * @brief Constructeur de la classe Parcelle.
     *
     * @param num Numéro de la parcelle.
     * @param prop Nom du propriétaire de la parcelle.
     * @param p Forme géométrique de la parcelle représentée par un polygone.
     */
    Parcelle(int num, const string &prop, const Polygone<int> &p);

    /**
     * @brief Définit le numéro de la parcelle.
     *
     * @param n Nouveau numéro de la parcelle.
     */
    void setNumero(int n);

    /**
     * @brief Définit le propriétaire de la parcelle.
     *
     * @param prop Nouveau propriétaire de la parcelle.
     */
    void setProprietaire(const string &prop);

    /**
     * @brief Définit la forme géométrique de la parcelle.
     *
     * @param forme Nouvelle forme géométrique de la parcelle.
     */
    void setForme(const Polygone<int> &forme);

    /**
     * @brief Définit le type de la parcelle (constructible ou non).
     *
     * @param type Nouveau type de la parcelle.
     */
    virtual void setType(const string &type);

    /**
     * @brief Obtient le numéro de la parcelle.
     *
     * @return Numéro de la parcelle.
     */
    int getNumero() const;

    /**
     * @brief Obtient le propriétaire de la parcelle.
     *
     * @return Nom du propriétaire de la parcelle.
     */
    string getProprietaire() const;

    /**
     * @brief Obtient la surface de la parcelle.
     *
     * @return Surface de la parcelle.
     */
    float getSurface() const;

    /**
     * @brief Obtient la forme géométrique de la parcelle.
     *
     * @return Forme géométrique de la parcelle.
     */
    Polygone<int> getForme() const;

    /**
     * @brief Obtient le type de la parcelle (constructible ou non).
     *
     * @return Type de la parcelle.
     */
    string getType() const;

    /**
     * @brief Calcule la surface de la parcelle.
     */
    void calculSurface();

    /**
     * @brief Surcharge de l'opérateur << pour l'affichage des informations de la parcelle.
     *
     * @param os Flux de sortie.
     * @param parcelle Parcelle à afficher.
     * @return Flux de sortie modifié.
     */
    friend ostream &operator<<(ostream &os, const Parcelle &parcelle);

private:
    int numero;          ///< Numéro de la parcelle.
    string proprietaire; ///< Nom du propriétaire de la parcelle.
    Polygone<int> forme; ///< Forme géométrique de la parcelle.
    double surface;      ///< Surface de la parcelle.
    bool constructible;  ///< Indique si la parcelle est constructible.
    string type;         ///< Type de la parcelle.
};

#endif
