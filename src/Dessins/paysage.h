#ifndef PAYSAGE_H_INCLUDED
#define PAYSAGE_H_INCLUDED

#include <fstream>
#include "../util/structureChoix.h"
#include "premierPlan.h"
#include "deuxiemePlan.h"
#include "troisiemePlan.h"

/// Classe dérivant de Groupe et contenant toutes les méthodes d'affichage de menu et de choix de paramètres.
class Paysage : public Groupe
{
    private:
        /// 2 structures Choix et 1 structure Choix3 en private afin de pouvoir stocker les choix de l'utilisateur
        Choix m_premierPlan, m_deuxiemePlan;
        Choix3 m_troisiemePlan;
    public:
        /// Constructeur : initialise les valeurs des choix de l'utilisateur
        Paysage();

        /// Destructeur par défaut hérité de Groupe
        virtual ~Paysage() = default;

        /// Méthode permettant de vider le vecteur de Dessin* de l'objet Paysage ciblé afin de le remplir
        /// avec les informations entrées par l'utilisateur et ayant été stockées dans les structures.
        /// Permet donc de mettre à jour le dessin
        void actualiserListe();

        /// Un menu de base afin que l'utilisateur puisse choisir ce qu'il veut faire
        void menu();

        /// Permet à l'utilisateur de pouvoir changer les informations stockées dans les structures
        void parametrePlan(int numeroPlan);

        /// Affiche un menu différent pour chaque plan
        void menuPlan1();
        void menuPlan2();
        void menuPlan3();

        /// Méthode overridée afin de pouvoir appeler une actualisation du vecteur avant de dessiner
        /// Permet donc de dessiner tout ce que le vecteur contient
        void dessiner(Svgfile& svgout);

        /// Méthode permettant d'enregister toutes les données entrées par l'utilisateur dans un fichier externe
        void sauvegarder();

        /// Méthode permettant de charger les données précédemennt enregistrées
        void charger();
};

#endif // PAYSAGE_H_INCLUDED
