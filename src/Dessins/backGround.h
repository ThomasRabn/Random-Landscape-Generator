#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include "groupe.h"

class BackGround : public Groupe
{
    public:
        BackGround(int valeurAleatoire,std::mt19937 graine);
        /** Constructeur qui g�re la cr�ation des valeurs al�atoires si il n'y a pas de graine.
        Dans le cas ou on a une graine alors on donne des valeurs al�atoires qui suivent la
        suite de valeur d�finie par la graine. **/
        virtual ~BackGround() = default;
        /** Le constructeur g�n�ral qui �vite une r�p�tition de code, il recoit les param�tres
        de "BackGround" puis injecte dans m_liste des lignes pour le d�grad�e ainsi qu'un
        soleil de couleur en fonction de valeur al�aoire et du rayon et un flou sur le soleil **/
        void constructeurBackground(double rayon, int valeurAleatoire);
};

#endif // BACKGROUND_H_INCLUDED
