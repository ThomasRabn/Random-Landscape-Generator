#ifndef DEUXIEMEPLAN_H_INCLUDED
#define DEUXIEMEPLAN_H_INCLUDED

#include "chaineMontagne.h"
#include "../util/structureChoix.h"

/// Classe regroupant tous les objets appartenant au second plan
class DeuxiemePlan : public Groupe
{
    public:
        /// Constructeur prenant en param�tre une structure Choix et cr�ant tout le second plan en fonction de celle-ci
        DeuxiemePlan(Choix& plan);

        /// Destructeur par d�faut
        virtual ~DeuxiemePlan() = default;
};

#endif // DEUXIEMEPLAN_H_INCLUDED
