#ifndef MONTAGNE_H_INCLUDED
#define MONTAGNE_H_INCLUDED

#include "groupe.h"
#include "../Primitives/triangle.h"
#include "../Primitives/disque.h"
#include "../Primitives/ellipse.h"

///La classe Montagne regroupe une deux où quatre triangles(neiges), et des ellipses (1fois sur deux pour les nuages) et représente donc une montagne
class Montagne : public Groupe
{
    public:
        /// Constructeur simple, on entre la position en bas à gauche et en haut à droite qui représente les extrémités de la montagne
        Montagne(Coords basGauche,Coords hautdroite);

        /// Même constructeur mais avec la couleur dominante en plus
        Montagne(Coords basGauche,Coords hautdroite,Couleur couleurDominante);

        /// Même constructeur mais avec la graine en plus
        Montagne(Coords basGauche,Coords hautdroite,std::mt19937 graine);

        /// Même constructeur mais avec la couleur dominante et la graine en plus
        Montagne(Coords basGauche,Coords hautdroite,Couleur couleurDominate,std::mt19937 graine);
        virtual ~Montagne() = default;
};

#endif // MONTAGNE_H_INCLUDED
