#ifndef CHAINEMONTAGNE_H_INCLUDED
#define CHAINEMONTAGNE_H_INCLUDED

#include "groupe.h"
#include "montagne.h"

/// Classe regroupant tout ce qui compose une forêt : arbres, sapins...
class ChaineMontagne : public Groupe
{
    public:
        /// Constructeur prenant en paramètre la couleurDominante et la tailleMoyenne des objets de cette forêt
        /// Il va alors créer des objets montagnes en fonction de ces paramètres
        ChaineMontagne(Couleur couleurDominante, double nombreMontagne, std::mt19937 graine);

        /// Destructeur par défaut (hérité de Groupe)
        virtual ~ChaineMontagne() = default;
};

#endif // CHAINEMONTAGNE_H_INCLUDED
