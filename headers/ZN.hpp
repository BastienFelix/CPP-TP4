
/**
 * @file ZN.hpp
 * @brief Déclaration de la classe ZN.
 *
 * Ce fichier contient la déclaration de la classe ZN, qui hérite de la classe Parcelle.
 *
 * @author Votre Nom
 * @date Date de création
 */

#ifndef ZN_HPP
#define ZN_HPP

#include "Parcelle.hpp"

using namespace std;

/**
 * @class ZN
 * @brief Classe représentant une zone naturelle.
 *
 * La classe ZN hérite de la classe Parcelle et représente une zone naturelle avec un numéro,
 * un propriétaire et un polygone.
 */
class ZN : public Parcelle
{
public:
    /**
     * @brief Constructeur de la classe ZN.
     *
     * @param num Numéro de la parcelle.
     * @param prop Propriétaire de la parcelle.
     * @param polygone Polygone représentant la forme de la parcelle.
     */
    ZN(int num, const string &prop, Polygone<int> polygone);

    /**
     * @brief Définit le type de la parcelle.
     *
     * @param type Type de la parcelle.
     */
    void setType(const string &type) override;

    /**
     * @brief Surcharge de l'opérateur de flux de sortie.
     *
     * @param os Flux de sortie.
     * @param zn Objet ZN à afficher.
     * @return Référence au flux de sortie.
     */
    friend ostream &operator<<(ostream &os, const ZN &zn);
};

#endif

