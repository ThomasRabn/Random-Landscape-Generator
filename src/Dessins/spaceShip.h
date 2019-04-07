#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED

#include "groupe.h"

class SpaceShip : public Groupe
{
    public:
        SpaceShip(Coords positionShip); /// construit un vaisseau spacial en fonction d'une position, le style du vaisseau est constant ainsi que sa couleur
        SpaceShip(Coords positionShip, std::mt19937 graine); /// constructeur avec une graine en paramètre permet de fixer la couleur de chaque vaisseau/position/taille
        virtual ~SpaceShip() = default;

};

#endif // SPACESHIP_H_INCLUDED
