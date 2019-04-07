#include "foret.h"

/// Constructeur surchargé avec graine
Foret::Foret(Coords position, Coords taille, Couleur couleurDominante, double tailleMoyenne, std::mt19937 graine, int nbrArbresMoyen)
{
    int choixArbre;
    int changementNbrArbres = util::alea(-5, 5, graine);
    int nbrArbres = nbrArbresMoyen+changementNbrArbres; /// nombre d'arbre final de la foret
    double coeffNombre = 150/tailleMoyenne; /// On fait un coeff plus elevé si les arbres sont petits
    nbrArbres*=coeffNombre; /// On multiplie le nombre d'arbre par le coeff : plus ils sont petits plus il y en a

    /// On définit des couleurs
    Couleur colorNone{0,0,0};
    Couleur colorRed{200, 50, 25};
    Couleur colorGreen{25, 200, 50};
    Couleur colorBlue{50, 25, 200};

    /// boucle qui tourne autant de fois qu'il y a d'arbres
    for(int i = 0; i<nbrArbres; ++i)
    {
        choixArbre = util::alea(0,1, graine); /// Si ça tombe sur 0 on fait un arbre, sur 1 on fait un sapin
        if(choixArbre == 0)
        {
            /// Couleur tronc arbre
            uint8_t couleurR = 91;
            uint8_t couleurV = 60;
            uint8_t couleurB = 21;
            Couleur couleurTronc{couleurR, couleurV, couleurB};
            couleurTronc.muter(20, graine);

            /// Couleur feuilles
            uint8_t rouge;
            uint8_t vert;
            uint8_t bleu;
            /// Si la couleur dominante n'a pas été choisie on fait en crée, sinon on prend les coeff RVB de la couleurDominante
            if(couleurDominante == colorNone)       { rouge = 25; vert = 200; bleu = 50; }
            else   { rouge = couleurDominante.getRouge(); vert = couleurDominante.getVert(); bleu = couleurDominante.getBleu(); }
            Couleur couleurFeuilles{rouge, vert, bleu}; /// La couleur des feuilles est créée
            couleurFeuilles.muter(40, graine); /// On la mute

            /// On tire la position au hasard
            Coords positionArbre(util::alea(position.getX(), position.getX()+taille.getX(), graine), util::alea(position.getY(), position.getY()+taille.getY(), graine));

            int tirageAleatoire;
            int ajout = 0;
            tirageAleatoire = util::alea(1, 6, graine); /// Tirage aléatoire d'un chiffre entre 1 et 6

            /// Les tests suivants permettent d'avoir plus d'arbres au loin que d'arbres proches afin de créer un effet de profondeur
            if(positionArbre.getY() < 600)
            {
                ajout = 1;
            }

            else if(positionArbre.getY() < 650)
            {
                if(tirageAleatoire < 6)     ajout = 1;
            }

            else if(positionArbre.getY() < 700)
            {
                if(tirageAleatoire < 5)     ajout = 1;
            }

            else if(positionArbre.getY() < 750)
            {
                if(tirageAleatoire < 4)     ajout = 1;
            }

            else if(positionArbre.getY() < 800)
            {
                if(tirageAleatoire < 3)     ajout = 1;
            }

            else{
                if(tirageAleatoire < 2)     ajout = 1;
            }

            /// On ajoute dans le vecteur
            if(ajout == 1)
            {
                Arbre* ptr = new Arbre{positionArbre, couleurTronc, couleurFeuilles, tailleMoyenne, graine};
                m_liste.push_back(ptr);
            }
        }
        else if(choixArbre == 1) /// On crée un sapin
        {
            /// Couleur tronc
            uint8_t couleurR = 61;
            uint8_t couleurV = 43;
            uint8_t couleurB = 31;
            Couleur couleurTronc{couleurR, couleurV, couleurB};
            couleurTronc.muter(20, graine);

            /// Couleur feuilles
            uint8_t rouge;
            uint8_t vert;
            uint8_t bleu;
            /// On change les valeurs en fonction de la couleur dominante
            if(couleurDominante == colorNone)       { rouge = 25; vert = 82; bleu = 40; }
            else if(couleurDominante == colorRed)   { rouge = 120; vert = 10; bleu = 15; }
            else if(couleurDominante == colorGreen) { rouge = 25; vert = 100; bleu = 15; }
            else if(couleurDominante == colorBlue)  { rouge = 10; vert = 15; bleu = 120; }
            Couleur couleurFeuilles{rouge, vert, bleu};
            couleurFeuilles.muter(40, graine);

            ///Tirage aléatoire de la position
            Coords positionArbre(util::alea(position.getX(), position.getX()+taille.getX(), graine), util::alea(position.getY(), position.getY()+taille.getY(), graine));

            int tirageAleatoire;
            int ajout = 0;
            tirageAleatoire = util::alea(1, 6, graine);

            /// Les tests suivants permettent d'avoir plus d'arbres au loin que d'arbres proches afin de créer un effet de profondeur
            if(positionArbre.getY() < 600)
            {
                ajout = 1;
            }

            else if(positionArbre.getY() < 650)
            {
                if(tirageAleatoire < 6)     ajout = 1;
            }

            else if(positionArbre.getY() < 700)
            {
                if(tirageAleatoire < 5)     ajout = 1;
            }

            else if(positionArbre.getY() < 750)
            {
                if(tirageAleatoire < 4)     ajout = 1;
            }

            else if(positionArbre.getY() < 800)
            {
                if(tirageAleatoire < 3)     ajout = 1;
            }

            else{
                if(tirageAleatoire < 2)     ajout = 1;
            }

            /// On ajoute dans le vecteur
            if(ajout == 1)
            {
                Sapin* ptr = new Sapin{positionArbre, couleurTronc, couleurFeuilles, tailleMoyenne};
                m_liste.push_back(ptr);
            }
        }
    }
}

/// Constructeur sans graine
Foret::Foret(Coords position, Coords taille, Couleur couleurDominante, double tailleMoyenne, int nbrArbresMoyen)
{
    int choixArbre;
    int changementNbrArbres = util::alea(-5, 5);
    int nbrArbres = nbrArbresMoyen+changementNbrArbres; /// nombre d'arbre final de la foret
    double coeffNombre = 150/tailleMoyenne; /// On fait un coeff plus elevé si les arbres sont petits
    nbrArbres*=coeffNombre; /// On multiplie le nombre d'arbre par le coeff : plus ils sont petits plus il y en a

    /// On crée les couleurs
    Couleur colorNone{0,0,0};
    Couleur colorRed{200, 50, 25};
    Couleur colorGreen{25, 200, 50};
    Couleur colorBlue{50, 25, 200};

    ///Boucle qui tourne pour chaque arbre
    for(int i = 0; i<nbrArbres; ++i)
    {
        choixArbre = util::alea(0,1);
        if(choixArbre == 0)
        {
            /// Couleur tronc
            uint8_t couleurR = 91;
            uint8_t couleurV = 60;
            uint8_t couleurB = 21;
            Couleur couleurTronc{couleurR, couleurV, couleurB};
            couleurTronc.muter(20);

            /// Couleur feuilles
            uint8_t rouge;
            uint8_t vert;
            uint8_t bleu;
            /// Si la couleur dominante n'a pas été choisie on la crée, sinon on prend les coeff RVB de la couleurDominante
            if(couleurDominante == colorNone)       { rouge = 25; vert = 200; bleu = 50; }
            else   { rouge = couleurDominante.getRouge(); vert = couleurDominante.getVert(); bleu = couleurDominante.getBleu(); }
            Couleur couleurFeuilles{rouge, vert, bleu};
            couleurFeuilles.muter(40);

            /// Création de la position
            Coords positionArbre(util::alea(position.getX(), position.getX()+taille.getX()), util::alea(position.getY(), position.getY()+taille.getY()));

            int tirageAleatoire;
            int ajout = 0;
            tirageAleatoire = util::alea(1, 6);

            /// Les tests suivants permettent d'avoir plus d'arbres au loin que d'arbres proches afin de créer un effet de profondeur
            if(positionArbre.getY() < 600)
            {
                ajout = 1;
            }

            else if(positionArbre.getY() < 650)
            {
                if(tirageAleatoire < 6)     ajout = 1;
            }

            else if(positionArbre.getY() < 700)
            {
                if(tirageAleatoire < 5)     ajout = 1;
            }

            else if(positionArbre.getY() < 750)
            {
                if(tirageAleatoire < 4)     ajout = 1;
            }

            else if(positionArbre.getY() < 800)
            {
                if(tirageAleatoire < 3)     ajout = 1;
            }

            else{
                if(tirageAleatoire < 2)     ajout = 1;
            }

            if(ajout == 1)
            {
                Arbre* ptr = new Arbre{positionArbre, couleurTronc, couleurFeuilles, tailleMoyenne };
                m_liste.push_back(ptr);
            }
        }
        else if(choixArbre == 1)
        {
            /// Couleur tronc
            uint8_t couleurR = 61;
            uint8_t couleurV = 43;
            uint8_t couleurB = 31;
            Couleur couleurTronc{couleurR, couleurV, couleurB};
            couleurTronc.muter(20);

            /// Couleur feuilles
            uint8_t rouge;
            uint8_t vert;
            uint8_t bleu;
            /// Si la couleur dominante n'a pas été choisie on la crée, sinon on prend les coeff RVB de la couleurDominante
            if(couleurDominante == colorNone)       { rouge = 25; vert = 82; bleu = 40; }
            else if(couleurDominante == colorRed)   { rouge = 120; vert = 10; bleu = 15; }
            else if(couleurDominante == colorGreen) { rouge = 25; vert = 100; bleu = 15; }
            else if(couleurDominante == colorBlue)  { rouge = 10; vert = 15; bleu = 120; }
            Couleur couleurFeuilles{rouge, vert, bleu};
            couleurFeuilles.muter(40);

            /// Creation position
            Coords positionArbre(util::alea(position.getX(), position.getX()+taille.getX()), util::alea(position.getY(), position.getY()+taille.getY()));

            int tirageAleatoire;
            int ajout = 0;
            tirageAleatoire = util::alea(1, 6);

            /// Les tests suivants permettent d'avoir plus d'arbres au loin que d'arbres proches afin de créer un effet de profondeur
            if(positionArbre.getY() < 600)
            {
                ajout = 1;
            }

            else if(positionArbre.getY() < 650)
            {
                if(tirageAleatoire < 6)     ajout = 1;
            }

            else if(positionArbre.getY() < 700)
            {
                if(tirageAleatoire < 5)     ajout = 1;
            }

            else if(positionArbre.getY() < 750)
            {
                if(tirageAleatoire < 4)     ajout = 1;
            }

            else if(positionArbre.getY() < 800)
            {
                if(tirageAleatoire < 3)     ajout = 1;
            }

            else{
                if(tirageAleatoire < 2)     ajout = 1;
            }


            if(ajout == 1)
            {
                Sapin* ptr = new Sapin{positionArbre, couleurTronc, couleurFeuilles, tailleMoyenne};
                m_liste.push_back(ptr);
            }
        }
    }
}
