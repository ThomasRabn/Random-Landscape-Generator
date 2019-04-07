#ifndef DISQUE_H_INCLUDED
#define DISQUE_H_INCLUDED

#include "primitive.h"

/// Classe modélisant un disque
class Disque : public Primitive
{
    protected:
        Coords m_centre; /// centre
        double m_rayon; /// rayon
        Couleur m_couleurDisque; /// couleur
        double m_opacity; /// opacité

    public:
        Disque(Coords centre, double rayon, Couleur couleurDisque, double opacity = 1);

        /// Méthode afficher permettant d'afficher les données et dessiner permettant de dessiner la forme sur le svgfile
        void afficher()const;
        virtual void dessiner(Svgfile& svgout);
};

#endif //DISQUE_H_INCLUDED
