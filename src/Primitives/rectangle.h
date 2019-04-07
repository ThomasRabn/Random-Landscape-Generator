#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "primitive.h"

class Rectangle : public Primitive
{
    /// Classe mod�lisant un rectangle
    private:
        Coords m_position; /// coordonn�e haut-gauche
        Coords m_taille; /// taille
        Couleur m_couleurRectangle; /// couleur int�rieure
        double m_epaisseur; /// epaisseur des bords
        Couleur m_couleurContourRectangle; /// couleur des bords
    public:
        Rectangle(Coords position, Coords taille, Couleur couleur, double ep = 0, Couleur couleurContour = {0,0,0});
        ~Rectangle() = default;

        /// M�thode afficher permettant d'afficher les donn�es et dessiner permettant de dessiner la forme sur le svgfile
        void afficher()const;
        void dessiner(Svgfile& svgout);
};

#endif // RECTANGLE_H_INCLUDED
