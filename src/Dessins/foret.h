#ifndef FORET_H_INCLUDED
#define FORET_H_INCLUDED

#include "arbre.h"
#include "sapin.h"

/// Classe regroupant tout ce qui compose une for�t : arbres, sapins...
class Foret : public Groupe
{
    public:
        /// Constructeur prenant en param�tre la position, la taille, la couleurDominante et la tailleMoyenne des objets de cette for�t
        /// Il va alors cr�er des objets arbres et sapins en fonction de ces param�tres
        Foret(Coords position, Coords taille, Couleur couleurDominante, double tailleMoyenne, int nbrArbresMoyen);

        /// Constructeur surcharg� : on passe la graine en plus afin de pouvoir avoir toujours la m�me for�t (fait pareil que le constructeur de base)
        Foret(Coords position, Coords taille, Couleur couleurDominante, double tailleMoyenne, std::mt19937 graine, int nbrArbresMoyen);

        /// Destructeur par d�faut (h�rit� de Groupe)
        ~Foret() = default;
};


#endif // FORET_H_INCLUDED
