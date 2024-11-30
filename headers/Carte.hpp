/**
 * @file Carte.hpp
 * @brief Déclaration de la classe Carte.
 *
 * La classe Carte permet de charger des données de parcelles à partir d'un fichier,
 * d'accéder à la surface totale de la carte, d'obtenir les parcelles et d'exporter
 * les parcelles dans un fichier.
 */

#ifndef CARTE_HPP
#define CARTE_HPP

#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "Parcelle.hpp"

using namespace std;

/**
 * @class Carte
 * @brief Classe représentant une carte contenant des parcelles.
 *
 * La classe Carte permet de charger des données de parcelles à partir d'un fichier,
 * d'accéder à la surface totale de la carte, d'obtenir les parcelles et d'exporter
 * les parcelles dans un fichier.
 */
class Carte

{
private:
    int surfaceTotale;
    vector<Parcelle *> parcelles;

public:
    /**
     * @brief Constructeur de la classe Carte.
     *
     * Charge les données des parcelles à partir d'un fichier spécifié.
     *
     * @param cheminFichier Chemin du fichier contenant les données des parcelles.
     */
    Carte(const string &cheminFichier);

    /**
     * @brief Accesseur pour obtenir la surface totale de la carte.
     *
     * @return La surface totale de la carte.
     */
    int getSurfaceTotale() const;

    /**
     * @brief Accesseur pour obtenir les parcelles de la carte.
     *
     * @return Un vecteur de pointeurs vers les parcelles de la carte.
     */
    vector<Parcelle *> getParcelles() const;

    /**
     * @brief Méthode pour exporter les parcelles dans un fichier.
     *
     * Exporte les données des parcelles dans un fichier spécifié.
     *
     * @param cheminFichier Chemin du fichier où exporter les données des parcelles.
     */
    void exporterParcelles(const string &cheminFichier) const;
};

#endif
