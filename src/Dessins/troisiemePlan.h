#ifndef TROISIEMEPLAN_H_INCLUDED
#define TROISIEMEPLAN_H_INCLUDED

#include "backGround.h"
#include "FloteSpaceShip.h"
#include "../util/structureChoix.h"

/// Classe regroupant tous les objets appartenant au troisième plan
class TroisiemePlan : public Groupe
{
    public:
        /// Constructeur prenant en paramètre une structure Choix3 et créant tout le troisième plan en fonction de celle-ci
        TroisiemePlan(Choix3& plan);

        /// Destructeur par défaut
        virtual ~TroisiemePlan() = default;
};

#endif // TROISIEMEPLAN_H_INCLUDED
