#ifndef PRIMITIVE_H_INCLUDED
#define PRIMITIVE_H_INCLUDED

#include "../Dessins/dessin.h"

/// Classe g�n�rale des primitives (au cas-o� nous avons besoin d'un attribut ou d'une m�thode g�n�rale)
class Primitive : public Dessin
{
    public:
        Primitive();
        virtual ~Primitive() = default;

};

#endif // PRIMITIVE_H_INCLUDED
