#ifndef FORET_H_INCLUDED
#define FORET_H_INCLUDED

#include "arbre.h"
#include "sapin.h"

/// Classe regroupant tout ce qui compose une forêt : arbres, sapins...
class Foret : public Groupe
{
    public:
        /// Constructeur prenant en paramètre la position, la taille, la couleurDominante et la tailleMoyenne des objets de cette forêt
        /// Il va alors créer des objets arbres et sapins en fonction de ces paramètres
        Foret(Coords position, Coords taille, Couleur couleurDominante, double tailleMoyenne, int nbrArbresMoyen);

        /// Constructeur surchargé : on passe la graine en plus afin de pouvoir avoir toujours la même forêt (fait pareil que le constructeur de base)
        Foret(Coords position, Coords taille, Couleur couleurDominante, double tailleMoyenne, std::mt19937 graine, int nbrArbresMoyen);

        /// Destructeur par défaut (hérité de Groupe)
        ~Foret() = default;
};


#endif // FORET_H_INCLUDED
