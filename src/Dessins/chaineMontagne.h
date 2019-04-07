#ifndef CHAINEMONTAGNE_H_INCLUDED
#define CHAINEMONTAGNE_H_INCLUDED

#include "groupe.h"
#include "montagne.h"

/// Classe regroupant tout ce qui compose une for�t : arbres, sapins...
class ChaineMontagne : public Groupe
{
    public:
        /// Constructeur prenant en param�tre la couleurDominante et la tailleMoyenne des objets de cette for�t
        /// Il va alors cr�er des objets montagnes en fonction de ces param�tres
        ChaineMontagne(Couleur couleurDominante, double nombreMontagne, std::mt19937 graine);

        /// Destructeur par d�faut (h�rit� de Groupe)
        virtual ~ChaineMontagne() = default;
};

#endif // CHAINEMONTAGNE_H_INCLUDED
