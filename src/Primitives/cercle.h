#ifndef CERCLE_H_INCLUDED
#define CERCLE_H_INCLUDED

#include "primitive.h"

/// Classe modélisant un cerle
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
        /// Destructeur par défaut
        ~Cercle() = default;

        /// Méthode afficher permettant d'afficher les données et dessiner permettant de dessiner la forme sur le svgfile
        void afficher()const;
        void dessiner(Svgfile& svgout);
};

#endif // CERCLE_H_INCLUDED
