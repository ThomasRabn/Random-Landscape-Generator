#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include "groupe.h"

class BackGround : public Groupe
{
    public:
        BackGround(int valeurAleatoire,std::mt19937 graine);
        /** Constructeur qui gère la création des valeurs aléatoires si il n'y a pas de graine.
        Dans le cas ou on a une graine alors on donne des valeurs aléatoires qui suivent la
        suite de valeur définie par la graine. **/
        virtual ~BackGround() = default;
        /** Le constructeur général qui évite une répétition de code, il recoit les paramètres
        de "BackGround" puis injecte dans m_liste des lignes pour le dégradée ainsi qu'un
        soleil de couleur en fonction de valeur aléaoire et du rayon et un flou sur le soleil **/
        void constructeurBackground(double rayon, int valeurAleatoire);
};

#endif // BACKGROUND_H_INCLUDED
