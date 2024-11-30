/**
 * @file ZAU.hpp
 * @brief Déclaration de la classe ZAU.
 *
 * Ce fichier contient la déclaration de la classe ZAU, qui hérite des classes Constructible et Parcelle.
 * La classe ZAU représente une Zone Agricole Urbaine.
 */

#ifndef ZAU_HPP
#define ZAU_HPP

#include "Constructible.hpp"
#include "Parcelle.hpp"

using namespace std;

/**
 * @class ZAU
 * @brief Classe représentant une Zone Agricole Urbaine.
 *
 * La classe ZAU hérite des classes Constructible et Parcelle. Elle permet de gérer les informations
 * relatives à une parcelle de type Zone Agricole Urbaine.
 */
class ZAU : public Constructible, public Parcelle
{
public:
    /**
     * @brief Constructeur de la classe ZAU.
     *
     * @param num Numéro de la parcelle.
     * @param prop Propriétaire de la parcelle.
     * @param polygone Forme de la parcelle représentée par un polygone.
     */
    ZAU(int num, const string &prop, Polygone<int> polygone);

    /**
     * @brief Définit le type de la parcelle.
     *
     * Cette méthode redéfinit la méthode setType de la classe Parcelle pour définir le type de la parcelle.
     *
     * @param type Type de la parcelle.
     */
    void setType(const string &type) override;

    /**
     * @brief Surcharge de l'opérateur de flux de sortie pour la classe ZAU.
     *
     * Cette fonction permet d'afficher les informations relatives à une parcelle de type ZAU.
     *
     * @param os Flux de sortie.
     * @param zau Référence constante vers l'objet ZAU à afficher.
     * @return Référence vers le flux de sortie.
     */
    friend ostream &operator<<(ostream &os, const ZAU &zau);
};

ZAU::ZAU(int num, const string &prop, Polygone<int> polygone) : Parcelle(num, prop, polygone)
{
    setType("Zone Agricole Urbaine");
    Constructible::genererSurfaceConstructible();
}

void ZAU::setType(const string &type)
{
    Parcelle::setType(type);
}

ostream &operator<<(ostream &os, const ZAU &zau)
{
    os << "Parcelle n°" << zau.getNumero() << " :" << endl;
    os << "     Type : " << zau.getType() << endl;
    os << "     Propriétaire : " << zau.getProprietaire() << endl;
    os << "     Surface : " << zau.getSurface() << " m²" << endl;
    os << "     Surface constructible : " << zau.getSurfaceConstructible() << "%" << endl;
    os << "     " << zau.getForme() << endl;

    return os;
}

#endif
