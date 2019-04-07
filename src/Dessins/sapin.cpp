#include "sapin.h"
/// Constructeur d'un sapin
Sapin::Sapin(Coords position, Couleur couleurTronc, Couleur couleurFeuilles, double tailleMoyenne)
{
    m_profondeur = 800 - position.getY(); /// On calcule la profondeur en fonction de la position en Y
    double coeffTaille = (position.getY()/800)*(position.getY()/800)*(position.getY()/800); /// Coefficient de la taille en fonction de la position en Y
    /// Création de la taille
    Coords taille{tailleMoyenne*coeffTaille, tailleMoyenne*coeffTaille};
    /// Création données tronc
    Coords troncHautGauche{(position.getX() + (3*taille.getX()/8)), position.getY() - taille.getY()};
    Coords tailleTronc{taille.getX()/4, taille.getY()};

    /// Création sommets des 3 triangles constituant les feuilles
    Coords sommet1{position.getX()+taille.getX()/2, position.getY()-1.8*taille.getY()};
    Coords sommet2{position.getX(), position.getY()-taille.getY()+taille.getY()*0.7};
    Coords sommet3{position.getX()+taille.getX(), position.getY()-taille.getY()+taille.getY()*0.7};

    Coords sommet4{position.getX(), position.getY()-taille.getY()+0.4*taille.getY()};
    Coords sommet5{position.getX()+taille.getX(), position.getY()-taille.getY()+0.4*taille.getY()};

    Coords sommet6{position.getX(), position.getY()-taille.getY()+0.1*taille.getY()};
    Coords sommet7{position.getX()+taille.getX(), position.getY()-taille.getY()+0.1*taille.getY()};

    /// Couleur des feuilles
    uint8_t rouge = couleurFeuilles.getRouge();
    uint8_t vert = couleurFeuilles.getVert();
    uint8_t bleu = couleurFeuilles.getBleu();

    if(rouge < 245){
        rouge+=10;
    }
    if(bleu < 245){
        bleu+=10;
    }
    if(vert < 245){
        vert+=10;
    }
    /// Couleur du deuxieme triangle (plus clair que le premier)
    Couleur couleurFeuilles2{rouge, vert, bleu};

    if(rouge < 245){
        rouge+=10;
    }
    if(bleu < 245){
        bleu+=10;
    }
    if(vert < 245){
        vert+=10;
    }
    /// Couleur du troisième triangle (plus clair que les autres)
    Couleur couleurFeuilles3{rouge, vert, bleu};

    /// On crée le tronc et les feuilles
    Rectangle* tronc = new Rectangle{troncHautGauche, tailleTronc, couleurTronc, 1};
    Triangle* feuilles = new Triangle{sommet1, sommet2, sommet3, couleurFeuilles, 1};
    Triangle* feuilles2 = new Triangle{sommet1, sommet4, sommet5, couleurFeuilles2, 1};
    Triangle* feuilles3 = new Triangle{sommet1, sommet6, sommet7, couleurFeuilles3, 1};
    /// On les ajoute au vecteur
    m_liste.push_back(tronc);
    m_liste.push_back(feuilles);
    m_liste.push_back(feuilles2);
    m_liste.push_back(feuilles3);
}
