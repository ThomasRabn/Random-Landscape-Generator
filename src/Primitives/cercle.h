#ifndef CERCLE_H_INCLUDED
#define CERCLE_H_INCLUDED

#include "primitive.h"

/// Classe mod�lisant un cerle
class Cercle : public Primitive
{
    private:
        Coords m_centre; /// Centre
        double m_rayon; /// Rayon
        double m_epaisseur; /// Epaisseur du bord
        Couleur m_couleurCercle; /// Couleur du bord

    public:
        /// Constructeur
        Cercle(Coords centre, double r, double ep, Couleur color);
        /// Destructeur par d�faut
        ~Cercle() = default;

        /// M�thode afficher permettant d'afficher les donn�es et dessiner permettant de dessiner la forme sur le svgfile
        void afficher()const;
        void dessiner(Svgfile& svgout);
};

#endif // CERCLE_H_INCLUDED
