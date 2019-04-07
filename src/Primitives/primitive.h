#ifndef PRIMITIVE_H_INCLUDED
#define PRIMITIVE_H_INCLUDED

#include "../Dessins/dessin.h"

/// Classe générale des primitives (au cas-où nous avons besoin d'un attribut ou d'une méthode générale)
class Primitive : public Dessin
{
    public:
        Primitive();
        virtual ~Primitive() = default;

};

#endif // PRIMITIVE_H_INCLUDED
