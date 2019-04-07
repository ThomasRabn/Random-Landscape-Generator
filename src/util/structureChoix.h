#ifndef STRUCTURECHOIX_H_INCLUDED
#define STRUCTURECHOIX_H_INCLUDED

#include "util.h"
#include "../Couleur/couleur.h"

/// Structure permettant de stocker les données du premier et du second plan
struct Choix
{
    /// Une graine, une couleur dominante et un paramètre supplémentaire en attributs
    std::mt19937 m_graine{0};
    Couleur m_couleurDominante;
    double m_paramSupp{100};

    void changerGraine(); /// Permet de changer la graine
    void changerCouleur(); /// Permet de changer la couleur
    void changerParametreSuppPlan1(); /// Permet de changer le paramètre supplémentaire pour le premier plan
    void changerParametreSuppPlan2(); /// Permet de changer le paramètre supplémentaire pour le deuxième plan
};

/// Structure permettant de stocker les données du troisième plan
struct Choix3
{
    /// Une graine, une couleur sous forme d'entier et un paramètre supplémentaire (le nombre de vaisseaux) en attributs
    std::mt19937 m_graine{0};
    int m_couleur{-1};
    double m_paramSupp{-1};

    void changerGraine(); /// Permet de changer la graine
    void changerCouleur(); /// Permet de changer la couleur
    void changerNombreVaisseaux(); /// Permet de changer le nombre de vaisseaux
};

#endif // STRUCTURECHOIX_H_INCLUDED
