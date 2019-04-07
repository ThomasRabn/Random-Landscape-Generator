#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include "groupe.h"
#include "../Primitives/rectangle.h"
#include "../Primitives/ellipse.h"
#include "../Primitives/cercle.h"

///La classe Arbre regroupe une ellipse et un rectangle et représente donc un arbre
class Arbre : public Groupe
{
    public:

        /// Constructeur simple, on entre une position, des couleurs et une taille et l'arbre va lui même créer
        /// les formes qui le composent et va les ajouter à son vecteur de Dessin*S
        Arbre(Coords position, Couleur couleurTronc, Couleur couleurFeuilles, double tailleMoyenne);

        /// Constructeur surchargé : est appelé lorsque l'utilisateur entre une graine mais fait pareil que le constructeur de base
        Arbre(Coords position, Couleur couleurTronc, Couleur couleurFeuilles, double tailleMoyenne, std::mt19937 graine);

        /// Destructeur par défaut (hérité de Groupe)
        virtual ~Arbre() = default;

        /// Méthode permettant de regrouper ce que les 2 constructeurs ont en commun afin de ne pas avoir de duplication de code
        void creationArbre(Coords position, Couleur couleurTronc, Couleur couleurFeuilles,
                           double tailleMoyenne, double coeffLargeur, double coeffHauteur);
};

#endif // ARBRE_H_INCLUDED
