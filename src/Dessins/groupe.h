#ifndef GROUPE_H_INCLUDED
#define GROUPE_H_INCLUDED

#include "dessin.h"
#include "../util/util.h"
#include <algorithm>

/// Classe fille � Dessin mais m�re de tous les autres Groupes.
/// Permet de traiter tous les groupes de la m�me mani�re gr�ce au polymorphisme
class Groupe : public Dessin
{
    protected:
        /// Un vecteur de Dessin* afin de pouvoir stocker tout type d'objet, en les allouant dynamiquement
        std::vector<Dessin*> m_liste;

    public:
        ///Constructeur d'un groupe
        Groupe();
        /// Destructeur virtuel d'un groupe permettant de vider tout ce qu'il contient
        virtual ~Groupe();

        /// M�thode permettant de dessiner sur le fichier passer en param�tre tout ce que le groupe contient
        virtual void dessiner(Svgfile& svgout);

        /// M�thode permettant d'afficher dans la console les informations de toutes les primitives dont le Groupe est compos�
        virtual void afficher()const;

        /// M�thode permettant de trier les objets du vecteur du groupe en fonction de leur profondeur
        ///( les plus profonds sont mis avant dans le vecteur)
        void trier();
};

#endif // GROUPE_H_INCLUDED
