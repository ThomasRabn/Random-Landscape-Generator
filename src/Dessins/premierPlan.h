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
        /// Constructeur prenant en param�tre une structure Choix et cr�ant tout le second plan en fonction de celle-ci
        PremierPlan(Choix& plan);

        /// Destructeur par d�faut
        virtual ~PremierPlan() = default;

        /// M�thodes permettant de mettre d'un cot� le code pour le constructeur avec grain et celui sans graine
        void constructeurAleatoire(Choix& plan);
        void constructeurGraine(Choix& plan);
};

#endif // PREMIERPLAN_H_INCLUDED
