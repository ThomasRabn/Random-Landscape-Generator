#include "troisiemePlan.h"

/// constructeur
TroisiemePlan::TroisiemePlan(Choix3& plan)
{
    /// On crée le ciel et la flotte
    BackGround* ciel = new BackGround(plan.m_couleur, plan.m_graine);
    FloteSpaceShip* flotte = new FloteSpaceShip(plan.m_paramSupp, plan.m_graine);
    /// On les ajoute au vecteur
    m_liste.push_back(ciel);
    m_liste.push_back(flotte);
}
