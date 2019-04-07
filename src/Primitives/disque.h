#ifndef DISQUE_H_INCLUDED
#define DISQUE_H_INCLUDED

#include "primitive.h"

/// Classe mod�lisant un disque
class Disque : public Primitive
{
    protected:
        Coords m_centre; /// centre
        double m_rayon; /// rayon
        Couleur m_couleurDisque; /// couleur
        double m_opacity; /// opacit�

    public:
        Disque(Coords centre, double rayon, Couleur couleurDisque, double opacity = 1);

        /// M�thode afficher permettant d'afficher les donn�es et dessiner permettant de dessiner la forme sur le svgfile
        void afficher()const;
        virtual void dessiner(Svgfile& svgout);
};

#endif //DISQUE_H_INCLUDED
