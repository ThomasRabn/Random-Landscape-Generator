#ifndef DESSIN_H_INCLUDED
#define DESSIN_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "../Svgfile/svgfile.h"
#include "../Geometrie/coords.h"
#include "../Couleur/couleur.h"

/// Classe m�re � presque la totalit� des classes du projet. Permet de faire du polymorphisme (en utilisant le pattern composite)
/// C'est une classe abstraite
class Dessin
{
    protected:
        double m_profondeur = 0; /// Permet de trier (si besoin) les objets des groupes

    public:
        virtual ~Dessin() = default; ///Destructeur par d�faut

        /// M�thodes virtuelles pures centrales au polymorphisme
        virtual void dessiner(Svgfile& svgout) = 0;
        virtual void afficher()const = 0;

        /// M�thode retournant la profondeur d'un objet de classe Dessin (toujours pour pouvoir trier)
        virtual double getProfondeur()const    { return m_profondeur; }
};


#endif // DESSIN_H_INCLUDED
