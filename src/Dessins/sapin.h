#ifndef SAPIN_H_INCLUDED
#define SAPIN_H_INCLUDED

#include "groupe.h"
#include "../Primitives/rectangle.h"
#include "../Primitives/triangle.h"

/// Classe regroupant des triangles et un rectangle (dans un vecteur de Dessin*). Repr�sente un sapin
class Sapin : public Groupe
{
    public:
        /// Constructeur prenant en param�tres la position et les couleurs du sapin et la taille moyenne des arbres
        Sapin(Coords position, Couleur couleurTronc, Couleur couleurFeuilles, double tailleMoyenne);

        /// Destructeur par d�faut
        ~Sapin() = default;
};

#endif // SAPIN_H_INCLUDED
