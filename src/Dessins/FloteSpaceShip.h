#ifndef FLOTESPACESHIP_H_INCLUDED
#define FLOTESPACESHIP_H_INCLUDED

#include "groupe.h"
#include "spaceShip.h"

class FloteSpaceShip : public Groupe
{
    public:
        FloteSpaceShip(double nombreVaisseau, std::mt19937 graine); /// regarde si une graine est re�ue en param�tre et en fonction de �a choisit le bon constructeur
        virtual ~FloteSpaceShip() = default;
        void constructeurAleatoire(double nombreVaisseau); /// construit un groupe de vaisseau en fonction d'un nombre re�u en param�tre
        void constructeurGraine(std::mt19937 graine, double nombreVaisseau); /// construit un groupe de vaisseau en fonction d'un nombre re�u en param�tre et de la graine
};

#endif // FLOTESPACESHIP_H_INCLUDED
