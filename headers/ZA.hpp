/**
 * @file ZA.hpp
 * @brief Déclaration de la classe ZA représentant une zone agricole.
 */

#ifndef ZA_HPP
#define ZA_HPP

#include "ZN.hpp"
#include "Parcelle.hpp"

/**
 * @class ZA
 * @brief Classe représentant une zone agricole, dérivée de ZN.
 *
 * La classe ZA hérite de la classe ZN et représente une parcelle de type zone agricole.
 * Elle permet de définir le type de la parcelle et de surcharger l'opérateur de flux pour l'affichage.
 */
class ZA : public ZN
{
public:
    /**
     * @brief Constructeur de la classe ZA.
     *
     * @param num Numéro de la parcelle.
     * @param prop Propriétaire de la parcelle.
     * @param polygone Forme de la parcelle représentée par un polygone.
     */
    ZA(int num, const string &prop, Polygone<int> polygone);

    /**
     * @brief Définit le type de la parcelle.
     *
     * @param type Type de la parcelle.
     */
    void setType(const string &type) override;

    /**
     * @brief Surcharge de l'opérateur de flux pour l'affichage des informations de la parcelle.
     *
     * @param os Flux de sortie.
     * @param za Référence constante vers l'objet ZA à afficher.
     * @return Référence vers le flux de sortie.
     */
    friend ostream &operator<<(ostream &os, const ZA &za);
};

#endif
