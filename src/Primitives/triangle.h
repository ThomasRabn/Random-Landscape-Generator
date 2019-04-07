#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "primitive.h"

/// Classe modélisant un triangle
class Triangle : public Dessin
{
    private:
        Coords m_a, m_b, m_c;
        Couleur m_couleurTriangle;
        double m_epaisseur;
        Couleur m_couleurContourTriangle;

    public:
        Triangle(Coords a, Coords b, Coords c, Couleur couleur, double ep = 0, Couleur couleurContour = {0,0,0});
        ~Triangle() = default;

        /// Méthode afficher permettant d'afficher les données et dessiner permettant de dessiner la forme sur le svgfile
        void dessiner(Svgfile& svgout);
        void afficher()const;
};

#endif // TRIANGLE_H_INCLUDED
