#ifndef PREMIERPLAN_H_INCLUDED
#define PREMIERPLAN_H_INCLUDED

#include "groupe.h"
#include "foret.h"
#include "../Primitives/disque.h"
#include "../util/structureChoix.h"

/// Classe regroupant tous les objets appartenant au premier plan
class PremierPlan : public Groupe
{
    public:
        /// Constructeur prenant en paramètre une structure Choix et créant tout le second plan en fonction de celle-ci
        PremierPlan(Choix& plan);

        /// Destructeur par défaut
        virtual ~PremierPlan() = default;

        /// Méthodes permettant de mettre d'un coté le code pour le constructeur avec grain et celui sans graine
        void constructeurAleatoire(Choix& plan);
        void constructeurGraine(Choix& plan);
};

#endif // PREMIERPLAN_H_INCLUDED
