#ifndef FLOTESPACESHIP_H_INCLUDED
#define FLOTESPACESHIP_H_INCLUDED

#include "groupe.h"
#include "spaceShip.h"

class FloteSpaceShip : public Groupe
{
    public:
        FloteSpaceShip(double nombreVaisseau, std::mt19937 graine); /// regarde si une graine est reçue en paramètre et en fonction de ça choisit le bon constructeur
        virtual ~FloteSpaceShip() = default;
        void constructeurAleatoire(double nombreVaisseau); /// construit un groupe de vaisseau en fonction d'un nombre reçu en paramètre
        void constructeurGraine(std::mt19937 graine, double nombreVaisseau); /// construit un groupe de vaisseau en fonction d'un nombre reçu en paramètre et de la graine
};

#endif // FLOTESPACESHIP_H_INCLUDED
