#include "deuxiemePlan.h"

DeuxiemePlan::DeuxiemePlan(Choix& plan)
{
    /// On crée et place tout ce qu'il y a sur le second plan dans le vecteur
    ChaineMontagne* chaine = new ChaineMontagne{plan.m_couleurDominante, plan.m_paramSupp, plan.m_graine};
    m_liste.push_back(chaine);
}
