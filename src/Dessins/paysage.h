#ifndef PAYSAGE_H_INCLUDED
#define PAYSAGE_H_INCLUDED

#include <fstream>
#include "../util/structureChoix.h"
#include "premierPlan.h"
#include "deuxiemePlan.h"
#include "troisiemePlan.h"

/// Classe d�rivant de Groupe et contenant toutes les m�thodes d'affichage de menu et de choix de param�tres.
class Paysage : public Groupe
{
    private:
        /// 2 structures Choix et 1 structure Choix3 en private afin de pouvoir stocker les choix de l'utilisateur
        Choix m_premierPlan, m_deuxiemePlan;
        Choix3 m_troisiemePlan;
    public:
        /// Constructeur : initialise les valeurs des choix de l'utilisateur
        Paysage();

        /// Destructeur par d�faut h�rit� de Groupe
        virtual ~Paysage() = default;

        /// M�thode permettant de vider le vecteur de Dessin* de l'objet Paysage cibl� afin de le remplir
        /// avec les informations entr�es par l'utilisateur et ayant �t� stock�es dans les structures.
        /// Permet donc de mettre � jour le dessin
        void actualiserListe();

        /// Un menu de base afin que l'utilisateur puisse choisir ce qu'il veut faire
        void menu();

        /// Permet � l'utilisateur de pouvoir changer les informations stock�es dans les structures
        void parametrePlan(int numeroPlan);

        /// Affiche un menu diff�rent pour chaque plan
        void menuPlan1();
        void menuPlan2();
        void menuPlan3();

        /// M�thode overrid�e afin de pouvoir appeler une actualisation du vecteur avant de dessiner
        /// Permet donc de dessiner tout ce que le vecteur contient
        void dessiner(Svgfile& svgout);

        /// M�thode permettant d'enregister toutes les donn�es entr�es par l'utilisateur dans un fichier externe
        void sauvegarder();

        /// M�thode permettant de charger les donn�es pr�c�demennt enregistr�es
        void charger();
};

#endif // PAYSAGE_H_INCLUDED
