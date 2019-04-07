#ifndef ELLIPSE_H_INCLUDED
#define ELLIPSE_H_INCLUDED

#include "primitive.h"

/// Classe modélisant une ellipse
class Ellipse : public Primitive
{
    private:
        Coords m_centre; /// centre
        double m_rayonX; /// rayon en x
        double m_rayonY; /// rayon en y
        Couleur m_couleurEllipse; /// couleur interieure
        double m_epaisseur; /// epaisseur des bords
        Couleur m_couleurContourEllipse; /// couleur des bords
        double m_opacity; /// opacité de l'ellipse
    public:
        Ellipse(Coords centre, double rx, double ry, Couleur color, double epaisseur = 0, Couleur couleurContourEllipse = {0,0,0}, double opacity = 1);
        ~Ellipse() = default;

        /// Méthode afficher permettant d'afficher les données et dessiner permettant de dessiner la forme sur le svgfile
        void afficher()const;
        void dessiner(Svgfile& svgout);
};

#endif // ELLIPSE_H_INCLUDED
