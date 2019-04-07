#ifndef TROISIEMEPLAN_H_INCLUDED
#define TROISIEMEPLAN_H_INCLUDED

#include "backGround.h"
#include "FloteSpaceShip.h"
#include "../util/structureChoix.h"

/// Classe regroupant tous les objets appartenant au troisi�me plan
class TroisiemePlan : public Groupe
{
    public:
        /// Constructeur prenant en param�tre une structure Choix3 et cr�ant tout le troisi�me plan en fonction de celle-ci
        TroisiemePlan(Choix3& plan);

        /// Destructeur par d�faut
        virtual ~TroisiemePlan() = default;
};

#endif // TROISIEMEPLAN_H_INCLUDED
