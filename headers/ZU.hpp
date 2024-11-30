
/**
 * @file ZU.hpp
 * @brief Déclaration de la classe ZU.
 *
 * Ce fichier contient la déclaration de la classe ZU, qui hérite des classes
 * Constructible et Parcelle. La classe ZU représente une zone urbaine avec
 * des propriétés spécifiques.
 *
 * @author Votre Nom
 * @date Date de création
 */

#ifndef ZU_HPP
#define ZU_HPP

#include "Constructible.hpp"

/**
 * @class ZU
 * @brief Classe représentant une zone urbaine.
 *
 * La classe ZU hérite des classes Constructible et Parcelle. Elle permet de
 * définir une zone urbaine avec un numéro, un propriétaire et un polygone.
 */
class ZU : public Constructible, public Parcelle
{

public:
    /**
     * @brief Constructeur de la classe ZU.
     *
     * @param num Numéro de la zone urbaine.
     * @param prop Propriétaire de la zone urbaine.
     * @param polygone Polygone représentant la zone urbaine.
     */
    ZU(int num, const string &prop, Polygone<int> polygone);

    /**
     * @brief Définit le type de la zone urbaine.
     *
     * Cette méthode redéfinit la méthode virtuelle pure setType de la classe
     * Constructible.
     *
     * @param type Type de la zone urbaine.
     */
    void setType(const string &type) override;

    /**
     * @brief Surcharge de l'opérateur de flux de sortie.
     *
     * Cette méthode permet d'afficher les informations de la zone urbaine
     * dans un flux de sortie.
     *
     * @param os Flux de sortie.
     * @param zu Référence constante vers l'objet ZU à afficher.
     * @return Référence vers le flux de sortie.
     */
    friend ostream &operator<<(ostream &os, const ZU &zu);
};

ZU::ZU(int num, const string &prop, Polygone<int> polygone) : Parcelle(num, prop, polygone)
{
    setType("Zone Urbaine");
    Constructible::genererSurfaceConstructible();
}

void ZU::setType(const string &type)
{
    Parcelle::setType(type);
}

ostream &operator<<(ostream &os, const ZU &zu)
{
    os << "Parcelle n°" << zu.getNumero() << " :" << endl;
    os << "     Type : " << zu.getType() << endl;
    os << "     Propriétaire : " << zu.getProprietaire() << endl;
    os << "     Surface : " << zu.getSurface() << " m²" << endl;
    os << "     Surface constructible restante : " << zu.getSurfaceConstructible() << "%" << endl;
    os << "     " << zu.getForme() << endl;

    return os;
}

#endif
