#include "arbre.h"

/// Constructeur arbre sans graine
Arbre::Arbre(Coords position, Couleur couleurTronc, Couleur couleurFeuilles, double tailleMoyenne)
{
    double coeffLargeur = util::alea(0.7, 1.5);
    double coeffHauteur = util::alea(0.7, 1.5);

    creationArbre(position, couleurTronc, couleurFeuilles, tailleMoyenne, coeffLargeur, coeffHauteur);
}

/// Constructeur arbre surcharg� avec graine
Arbre::Arbre(Coords position, Couleur couleurTronc, Couleur couleurFeuilles, double tailleMoyenne, std::mt19937 graine)
{
    double coeffLargeur = util::alea(0.7, 1.5, graine);
    double coeffHauteur = util::alea(0.7, 1.5, graine);

    creationArbre(position, couleurTronc, couleurFeuilles, tailleMoyenne, coeffLargeur, coeffHauteur);
}

/// M�thode permettant de ne pas copier tout le code dans chaque constructeurs
void Arbre::creationArbre(Coords position, Couleur couleurTronc, Couleur couleurFeuilles,
                          double tailleMoyenne, double coeffLargeur, double coeffHauteur)
{
    m_profondeur = 800 - position.getY(); /// On cr�e une profondeur en fonction de la position en Y

    /// On cr�e un coefficient pour la taille de l'arbre en fonction de sa position en Y
    double coeffTaille = (position.getY()/800)*(position.getY()/800)*(position.getY()/800);

    /// On cr�e des coordonn�es taille pour avoir la taille totale de l'arbre (en x et y)
    Coords taille{tailleMoyenne*coeffTaille, tailleMoyenne*coeffTaille};

    /// On calcule la position du haut gauche du tronc
    Coords troncHautGauche{(position.getX() + (3*taille.getX()/8)), position.getY() - taille.getY()};
    /// On calcule la taille du tronc
    Coords tailleTronc{taille.getX()/4, taille.getY()};
    /// On calcule la position du centre des feuilles
    Coords centreFeuilles{(position.getX() + taille.getX()/2), position.getY() - taille.getY()};

    /// On cr�e un rectangle et une ellipse pour le tronc et les feuilles en fonction de ce qu'on a calcul�
    Rectangle* tronc = new Rectangle{troncHautGauche, tailleTronc, couleurTronc, 1};
    Ellipse* feuilles = new Ellipse{centreFeuilles, coeffLargeur*taille.getX()/2, coeffHauteur*taille.getX()/2, couleurFeuilles, 1};

    /// On met tout �a dans le vecteur de Dessin*
    m_liste.push_back(tronc);
    m_liste.push_back(feuilles);
}
