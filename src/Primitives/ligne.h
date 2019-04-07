#ifndef LIGNE_H_INCLUDED
#define LIGNE_H_INCLUDED

#include "primitive.h"

/// Classe mod�lisant une ligne
class Ligne : public Dessin
{
    private:
        Coords m_a, m_b; /// point de d�but et de fin
        Couleur m_couleurLigne; /// couleur

    public:
        Ligne(Coords a, Coords b, Couleur couleurLigne); /// dessine une ligne entre 2 coords d'une couleur obtenue en param�tre
        ~Ligne() = default;

        /// M�thode afficher permettant d'afficher les donn�es et dessiner permettant de dessiner la forme sur le svgfile
        void dessiner(Svgfile& svgout);
        void afficher()const;
};

#endif // LIGNE_H_INCLUDED
