#ifndef DEUXIEMEPLAN_H_INCLUDED
#define DEUXIEMEPLAN_H_INCLUDED

#include "chaineMontagne.h"
#include "../util/structureChoix.h"

/// Classe regroupant tous les objets appartenant au second plan
class DeuxiemePlan : public Groupe
{
    public:
        /// Constructeur prenant en paramètre une structure Choix et créant tout le second plan en fonction de celle-ci
        DeuxiemePlan(Choix& plan);

        /// Destructeur par défaut
        virtual ~DeuxiemePlan() = default;
};

#endif // DEUXIEMEPLAN_H_INCLUDED
