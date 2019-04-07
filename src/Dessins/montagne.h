#ifndef MONTAGNE_H_INCLUDED
#define MONTAGNE_H_INCLUDED

#include "groupe.h"
#include "../Primitives/triangle.h"
#include "../Primitives/disque.h"
#include "../Primitives/ellipse.h"

///La classe Montagne regroupe une deux o� quatre triangles(neiges), et des ellipses (1fois sur deux pour les nuages) et repr�sente donc une montagne
class Montagne : public Groupe
{
    public:
        /// Constructeur simple, on entre la position en bas � gauche et en haut � droite qui repr�sente les extr�mit�s de la montagne
        Montagne(Coords basGauche,Coords hautdroite);

        /// M�me constructeur mais avec la couleur dominante en plus
        Montagne(Coords basGauche,Coords hautdroite,Couleur couleurDominante);

        /// M�me constructeur mais avec la graine en plus
        Montagne(Coords basGauche,Coords hautdroite,std::mt19937 graine);

        /// M�me constructeur mais avec la couleur dominante et la graine en plus
        Montagne(Coords basGauche,Coords hautdroite,Couleur couleurDominate,std::mt19937 graine);
        virtual ~Montagne() = default;
};

#endif // MONTAGNE_H_INCLUDED
