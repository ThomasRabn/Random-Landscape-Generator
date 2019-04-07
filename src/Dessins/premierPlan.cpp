#include "premierPlan.h"

/// Constructeur
PremierPlan::PremierPlan(Choix& plan)
{
    std::mt19937 aleatoire{0};

    if(plan.m_graine == aleatoire) /// Si l'utilisateur veut de l'al�atoire
    {
        /// On lance le constructeur al�atoire
        constructeurAleatoire(plan);
    }
    else{   /// sinon
        constructeurGraine(plan); /// On lance la version avec la graine
    }
}

/// Cr�e un premier plan en fonciton des param�tres SANS la graine
void PremierPlan::constructeurAleatoire(Choix& plan)
{
    /// On cr�e un sol et deux for�ts
    Disque* sol = new Disque{{500, 3000},2500, {224, 205, 169}};
    Foret* foret2 = new Foret{{300, 510}, {400, 40}, plan.m_couleurDominante, plan.m_paramSupp, 10 };
    Foret* foret = new Foret{{-100, 550}, {1200, 300}, plan.m_couleurDominante, plan.m_paramSupp, 110 };
    /// On ajoute �a au vecteur
    m_liste.push_back(sol);
    m_liste.push_back(foret2);
    m_liste.push_back(foret);
}

/// Cr�e un premier plan en fonciton des param�tres AVEC la graine
void PremierPlan::constructeurGraine(Choix& plan)
{
    /// On cr�e un sol et deux for�ts
    Disque* sol = new Disque{{500, 3000},2500, {224, 205, 169}};
    Foret* foret2 = new Foret{{300, 510}, {400, 40}, plan.m_couleurDominante, plan.m_paramSupp, plan.m_graine, 10 };
    Foret* foret = new Foret{{-50, 550}, {1000, 300}, plan.m_couleurDominante, plan.m_paramSupp, plan.m_graine, 110 };
    /// On ajoute �a au vecteur
    m_liste.push_back(sol);
    m_liste.push_back(foret2);
    m_liste.push_back(foret);
}
