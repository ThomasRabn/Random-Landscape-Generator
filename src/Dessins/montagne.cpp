#include "montagne.h"
/// Chaque constructeur est différent puisque si il n'y a pas de paramètre le choix des couleurs de la neige et des nuages et fait aléatoirement

Montagne::Montagne(Coords basGauche,Coords hautDroite) // creation de montagne qui est donc un groupe
    :Groupe{}
{
    m_profondeur = 800 - hautDroite.getY(); // mise au point de le profondeur

    uint8_t couleurM = hautDroite.getY() +100; // Création de la couleur principale de la montagne
    Couleur couleurmontagne{couleurM,couleurM,couleurM};
    couleurmontagne.muter(20);  // On fait muter la couleur aléatioirement de 20

    Coords basDroite{hautDroite.getX(),basGauche.getY()};   // Calcul du point en bas à droite
    Coords hautMilieu{((basGauche.getX()+hautDroite.getX())/2),hautDroite.getY()}; // Calcul du point au sommet de la montagne
    Coords basMilieu{basGauche.getX() + (basDroite.getX()-basGauche.getX())/2,basDroite.getY()}; // Calcul du point en bas au milieu

    // Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())/3*2,basDroite.getY()}; // Calcul du point où l'ombre seza positionné



    uint8_t couleurMOR = couleurmontagne.getRouge()-50;  // Creation de la couleur de l'ombre
    uint8_t couleurMOV = couleurmontagne.getVert()-50;
    uint8_t couleurMOB = couleurmontagne.getBleu()-50;
    Couleur couleurMontagneombre{couleurMOR,couleurMOV,couleurMOB};

    Triangle* montagne = new Triangle(basGauche,basDroite,hautMilieu,couleurmontagne); // Creation du triangle représntant la montagne
    m_liste.push_back(montagne); // Mettre le triangle dans la liste à dessiner

    /// Il existe deux cas : Le premier où la l'ombre est a droite de la montagne et l'un ou il est à gauche
    /// Il le point est calculé par rapport au centre du plan

    if(basMilieu.getX() <= 500) // à gauche du centre
    {
        Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())*(1-(basMilieu.getX()/500)),basDroite.getY()}; // Creation du point en bas du triangle
        Triangle* montagneombre = new Triangle(basOmbre,basGauche,hautMilieu,couleurMontagneombre); // Creation du triangle représntant l'ombre
        m_liste.push_back(montagneombre); // Mettre le triangle dans la liste à dessiner
    }
    if(basMilieu.getX() > 500) // à droite du centre
    {
        Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())*(1-((basMilieu.getX()-500)/500)),basDroite.getY()}; // Creation du point en bas du triangle
        Triangle* montagneombre = new Triangle(basOmbre,basDroite,hautMilieu,couleurMontagneombre); // Creation du triangle représntant l'ombre
        m_liste.push_back(montagneombre); // Mettre le triangle dans la liste à dessiner
    }


    /// Neige

    int i = util::alea(0,1); // une chance sur deux d'avoir de la neige
    if(i==1)
    {

        Coords basDroiteN{hautMilieu.getX()+((basDroite.getX()-hautMilieu.getX())/3),hautMilieu.getY()+((basDroite.getY()-hautMilieu.getY())/3)}; // Calcul du point en bas à droite de la neige
        Coords basGaucheN{hautMilieu.getX()-((hautMilieu.getX()-basGauche.getX())/3),hautMilieu.getY()+((basGauche.getY()-hautMilieu.getY())/3)}; // Calcul du point au sommet de la montagne de la neige
        Coords basMilieuN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())/2,hautMilieu.getY()+((basGaucheN.getY()-hautMilieu.getY())/3)};// Calcul du point en bas au milieu de la neige

        //Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())/3*2,hautMilieu.getY()+((basGauche.getY()-hautMilieu.getY())/3)};

        uint8_t couleurN = util::alea(230,255); // Creation de la couleur de neige
        Couleur neige{couleurN,couleurN,255};
        uint8_t couleurNF = couleurN-50;// Creation de la couleur de l'ombre
        Couleur neigeF{couleurNF,couleurNF,255-50};


        Triangle* montagne2 = new Triangle(basGaucheN,basDroiteN,hautMilieu, neige); // Creation du triangle représntant la montagne
        m_liste.push_back(montagne2);// Mettre le triangle dans la liste à dessiner

        /// Il existe aussi les deux mêmes cas que pour la montagne

        if(basMilieuN.getX() <= 500) // à gauche du centre
        {
            Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())*(1-(basMilieu.getX()/500)),basDroiteN.getY()}; // Creation du point en bas du triangle
            Triangle* montagne2ombre = new Triangle(basOmbreN,basGaucheN,hautMilieu,neigeF); // Creation du triangle représntant l'ombre
            m_liste.push_back(montagne2ombre); // Mettre le triangle dans la liste à dessiner
        }
        if(basMilieuN.getX() > 500) // à droit du centre
        {
            Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())*(1-((basMilieuN.getX()-500)/500)),basDroiteN.getY()};// Creation du point en bas du triangle
            Triangle* montagne2ombre = new Triangle(basOmbreN,basDroiteN,hautMilieu,neigeF); // Creation du triangle représntant l'ombre
            m_liste.push_back(montagne2ombre);// Mettre le triangle dans la liste à dessiner
        }

    }

    /// Nuages

    int j = util::alea(0,1); // une chance sur deux d'avoir des nuages
    if(j==1)
    {
        for(int k=0;k<10;k++) // Boucle servant à creer les ellipses
        {
            int nX = util::alea(hautMilieu.getX()-50,hautMilieu.getX()+50); // abssice du centre
            int nY = util::alea(hautMilieu.getY()+50,hautMilieu.getY()+55); // ordonnée du centre
            Coords centre(nX,nY);
            int rX = util::alea(20,30); // rayon 1
            int rY = util::alea(4,6); // rayon 2
            uint8_t couleurB = 255,couleurN = 230; // creation des couleurs Blanc et le blanc foncé
            Couleur B{couleurB,couleurB,couleurB},N{couleurN,couleurN,couleurN};
            Ellipse* Blanc = new Ellipse(centre,rX,rY,B); // Creation de la premiere ellipse
            Ellipse* Noir = new Ellipse(centre,rX+1,rY+1,N); // Creation de la deuxieme ellipse
            m_liste.push_back(Noir); // Mettre la premiere ellipse dans la liste à dessiner
            m_liste.push_back(Blanc); // Mettre la deuxieme ellipse dans la liste à dessiner

        }
    }


}

/// Montagne avec Couleur Dominante

Montagne::Montagne(Coords basGauche,Coords hautDroite,Couleur couleurDominante) // creation de montagne qui est donc un groupe
    :Groupe{}
{
    m_profondeur = 800 - hautDroite.getY(); // mise au point de le profondeur

    uint8_t couleurMR = couleurDominante.getRouge(); // Création de la couleur principale de la montagne
    uint8_t couleurMV = couleurDominante.getVert();
    uint8_t couleurMB = couleurDominante.getBleu();
    Couleur couleurmontagne{couleurMR,couleurMV,couleurMB};
    couleurmontagne.muter(20); // On fait muter la couleur aléatioirement de 20


    Coords basDroite{hautDroite.getX(),basGauche.getY()}; // Calcul du point en bas à droite
    Coords hautMilieu{((basGauche.getX()+hautDroite.getX())/2),hautDroite.getY()}; // Calcul du point au sommet de la montagne
    Coords basMilieu{basGauche.getX() + (basDroite.getX()-basGauche.getX())/2,basDroite.getY()}; // Calcul du point en bas au milieu

    //Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())/3*2,basDroite.getY()}; // Calcul du point où l'ombre seza positionné


    uint8_t couleurMOR = couleurDominante.getRouge()-20; // Creation de la couleur de l'ombre
    uint8_t couleurMOV = couleurDominante.getVert()-20;
    uint8_t couleurMOB = couleurDominante.getBleu()-20;
    Couleur couleurMontagneombre{couleurMOR,couleurMOV,couleurMOB};

    Triangle* montagne = new Triangle(basGauche,basDroite,hautMilieu,couleurmontagne); // Creation du triangle représntant la montagne
    m_liste.push_back(montagne); // Mettre le triangle dans la liste à dessiner

    if(basMilieu.getX() <= 500) // à gauche du centre
    {
        Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())*(1-(basMilieu.getX()/500)),basDroite.getY()}; // Creation du point en bas du triangle
        Triangle* montagneombre = new Triangle(basOmbre,basGauche,hautMilieu,couleurMontagneombre); // Creation du triangle représntant l'ombre
        m_liste.push_back(montagneombre); // Mettre le triangle dans la liste à dessiner
    }
    if(basMilieu.getX() > 500) // à droite du centre
    {
        Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())*(1-((basMilieu.getX()-500)/500)),basDroite.getY()}; // Creation du point en bas du triangle
        Triangle* montagneombre = new Triangle(basOmbre,basDroite,hautMilieu,couleurMontagneombre); // Creation du triangle représntant l'ombre
        m_liste.push_back(montagneombre); // Mettre le triangle dans la liste à dessiner
    }


    /// Neige

    int i = util::alea(0,1);
    if(i==1)
    {
        Coords basDroiteN{hautMilieu.getX()+((basDroite.getX()-hautMilieu.getX())/3),hautMilieu.getY()+((basDroite.getY()-hautMilieu.getY())/3)}; // Calcul du point en bas à droite de la neige
        Coords basGaucheN{hautMilieu.getX()-((hautMilieu.getX()-basGauche.getX())/3),hautMilieu.getY()+((basGauche.getY()-hautMilieu.getY())/3)}; // Calcul du point au sommet de la montagne
        Coords basMilieuN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())/2,hautMilieu.getY()+((basGaucheN.getY()-hautMilieu.getY())/3)}; // Calcul du point au sommet de la montagne

        // Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())/3*2,hautMilieu.getY()+((basGauche.getY()-hautMilieu.getY())/3)};

        uint8_t couleurN = util::alea(230,255); // Creation de la couleur de neige
        Couleur neige{couleurN,couleurN,255};
        uint8_t couleurNF = couleurN-50; // Creation de la couleur de l'ombre
        Couleur neigeF{couleurNF,couleurNF,255-50};


        Triangle* montagne2 = new Triangle(basGaucheN,basDroiteN,hautMilieu, neige); // Creation du triangle représntant la montagne
        m_liste.push_back(montagne2); // Mettre le triangle dans la liste à dessiner

        if(basMilieuN.getX() <= 500) // à gauche du centre
        {
            Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())*(1-(basMilieu.getX()/500)),basDroiteN.getY()}; // Creation du point en bas du triangle
            Triangle* montagne2ombre = new Triangle(basOmbreN,basGaucheN,hautMilieu,neigeF); // Creation du triangle représntant l'ombre
            m_liste.push_back(montagne2ombre); // Mettre le triangle dans la liste à dessiner
        }
        if(basMilieuN.getX() > 500) // à droit du centre
        {
            Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())*(1-((basMilieuN.getX()-500)/500)),basDroiteN.getY()}; // Creation du point en bas du triangle
            Triangle* montagne2ombre = new Triangle(basOmbreN,basDroiteN,hautMilieu,neigeF); // Creation du triangle représntant l'ombre
            m_liste.push_back(montagne2ombre); // Mettre le triangle dans la liste à dessiner
        }

    }

    /// Nuages

    int j = util::alea(0,1); // une chance sur deux d'avoir des nuages
    if(j==1)
    {
        for(int k=0;k<10;k++) // Boucle servant à creer les ellipses
        {
            int nX = util::alea(hautMilieu.getX()-50,hautMilieu.getX()+50); // abssice du centre
            int nY = util::alea(hautMilieu.getY()+50,hautMilieu.getY()+55); // ordonnée du centre
            Coords centre(nX,nY);
            int rX = util::alea(20,30); // rayon 1
            int rY = util::alea(4,6); // rayon 2
            uint8_t couleurB = 255,couleurN = 230; // creation des couleurs Blanc et le blanc foncé
            Couleur B{couleurB,couleurB,couleurB},N{couleurN,couleurN,couleurN};
            Ellipse* Blanc = new Ellipse(centre,rX,rY,B); // Creation de la premiere ellipse
            Ellipse* Noir = new Ellipse(centre,rX+1,rY+1,N); // Creation de la deuxieme ellipse
            m_liste.push_back(Noir); // Mettre la premiere ellipse dans la liste à dessiner
            m_liste.push_back(Blanc); // Mettre la deuxieme ellipse dans la liste à dessiner

        }
    }
}



/// Montagne avec Graine

Montagne::Montagne(Coords basGauche,Coords hautDroite,std::mt19937 graine)
    :Groupe{}
{
    m_profondeur = 800 - hautDroite.getY(); // mise au point de le profondeur

    uint8_t couleurM = hautDroite.getY()+100; // Création de la couleur principale de la montagne
    Couleur couleurmontagne{couleurM,couleurM,couleurM};
    couleurmontagne.muter(20, graine); // On fait muter la couleur aléatioirement de 20

    Coords basDroite{hautDroite.getX(),basGauche.getY()};   // Calcul du point en bas à droite
    Coords hautMilieu{((basGauche.getX()+hautDroite.getX())/2),hautDroite.getY()}; // Calcul du point au sommet de la montagne
    Coords basMilieu{basGauche.getX() + (basDroite.getX()-basGauche.getX())/2,basDroite.getY()}; // Calcul du point en bas au milieu

    //Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())/3*2,basDroite.getY()};


    uint8_t couleurMOR = couleurmontagne.getRouge()-50; // Creation de la couleur de l'ombre
    uint8_t couleurMOV = couleurmontagne.getVert()-50;
    uint8_t couleurMOB = couleurmontagne.getBleu()-50;
    Couleur couleurMontagneombre{couleurMOR,couleurMOV,couleurMOB};

    Triangle* montagne = new Triangle(basGauche,basDroite,hautMilieu,couleurmontagne); // Creation du triangle représntant la montagne
    m_liste.push_back(montagne); // Mettre le triangle dans la liste à dessiner

    if(basMilieu.getX() <= 500) // à gauche du centre
    {
        Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())*(1-(basMilieu.getX()/500)),basDroite.getY()}; // Creation du point en bas du triangle
        Triangle* montagneombre = new Triangle(basOmbre,basGauche,hautMilieu,couleurMontagneombre); // Creation du triangle représntant l'ombre
        m_liste.push_back(montagneombre); // Mettre le triangle dans la liste à dessiner
    }
    if(basMilieu.getX() > 500) // à droite du centre
    {
        Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())*(1-((basMilieu.getX()-500)/500)),basDroite.getY()}; // Creation du point en bas du triangle
        Triangle* montagneombre = new Triangle(basOmbre,basDroite,hautMilieu,couleurMontagneombre); // Creation du triangle représntant l'ombre
        m_liste.push_back(montagneombre); // Mettre le triangle dans la liste à dessiner
    }


    /// Neige

    int i = util::alea(0,1,graine); // une chance sur deux d'avoir de la neige
    if(i==1)
    {
        Coords basDroiteN{hautMilieu.getX()+((basDroite.getX()-hautMilieu.getX())/3),hautMilieu.getY()+((basDroite.getY()-hautMilieu.getY())/3)}; // Calcul du point en bas à droite de la neige
        Coords basGaucheN{hautMilieu.getX()-((hautMilieu.getX()-basGauche.getX())/3),hautMilieu.getY()+((basGauche.getY()-hautMilieu.getY())/3)}; // Calcul du point au sommet de la montagne de la neige
        Coords basMilieuN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())/2,hautMilieu.getY()+((basGaucheN.getY()-hautMilieu.getY())/3)}; // Calcul du point en bas au milieu de la neige

        //Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())/3*2,hautMilieu.getY()+((basGauche.getY()-hautMilieu.getY())/3)};

        uint8_t couleurN = util::alea(230,255,graine); // Creation de la couleur de neige
        Couleur neige{couleurN,couleurN,255};
        uint8_t couleurNF = couleurN-50; // Creation de la couleur de l'ombre
        Couleur neigeF{couleurNF,couleurNF,255-50};


        if(basMilieuN.getX() <= 500) // à gauche du centre
        {
            Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())*(1-(basMilieu.getX()/500)),basDroiteN.getY()}; // Creation du point en bas du triangle
            Triangle* montagne2ombre = new Triangle(basOmbreN,basGaucheN,hautMilieu,neigeF); // Creation du triangle représntant l'ombre
            m_liste.push_back(montagne2ombre); // Mettre le triangle dans la liste à dessiner
        }
        if(basMilieuN.getX() > 500) // à droit du centre
        {
            Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())*(1-((basMilieuN.getX()-500)/500)),basDroiteN.getY()};// Creation du point en bas du triangle
            Triangle* montagne2ombre = new Triangle(basOmbreN,basDroiteN,hautMilieu,neigeF); // Creation du triangle représntant l'ombre
            m_liste.push_back(montagne2ombre);// Mettre le triangle dans la liste à dessiner
        }

    }

    /// Nuages

    int j = util::alea(0,1,graine); // une chance sur deux d'avoir des nuages
    if(j==1)
    {
        for(int k=0;k<10;k++)
        {
            int nX = util::alea(hautMilieu.getX()-50,hautMilieu.getX()+50,graine); // abssice du centre
            int nY = util::alea(hautMilieu.getY()+50,hautMilieu.getY()+55,graine); // ordonnée du centre
            Coords centre(nX,nY);
            int rX = util::alea(20,30,graine); // rayon 1
            int rY = util::alea(4,6,graine); // rayon 2
            uint8_t couleurB = 255,couleurN = 230; // creation des couleurs Blanc et le blanc foncé
            Couleur B{couleurB,couleurB,couleurB},N{couleurN,couleurN,couleurN};
            Ellipse* Blanc = new Ellipse(centre,rX,rY,B); // Creation de la premiere ellipse
            Ellipse* Noir = new Ellipse(centre,rX+1,rY+1,N); // Creation de la deuxieme ellipse
            m_liste.push_back(Noir); // Mettre la premiere ellipse dans la liste à dessiner
            m_liste.push_back(Blanc); // Mettre la deuxieme ellipse dans la liste à dessiner

        }
    }


}

/// Montagne avec Graine et Couleur

Montagne::Montagne(Coords basGauche,Coords hautDroite,Couleur couleurDominante,std::mt19937 graine)
    :Groupe{}
{
    m_profondeur = 800 - hautDroite.getY(); // mise au point de le profondeur

    uint8_t couleurMR = couleurDominante.getRouge(); // Création de la couleur principale de la montagne en fonction de la couleur dominante
    uint8_t couleurMV = couleurDominante.getVert();
    uint8_t couleurMB = couleurDominante.getBleu();
    Couleur couleurmontagne{couleurMR,couleurMV,couleurMB};
    couleurmontagne.muter(20, graine); // On fait muter la couleur aléatioirement de 20

    Coords basDroite{hautDroite.getX(),basGauche.getY()};   // Calcul du point en bas à droite
    Coords hautMilieu{((basGauche.getX()+hautDroite.getX())/2),hautDroite.getY()}; // Calcul du point au sommet de la montagne
    Coords basMilieu{basGauche.getX() + (basDroite.getX()-basGauche.getX())/2,basDroite.getY()}; // Calcul du point en bas au milieu

    //Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())/3*2,basDroite.getY()};


    uint8_t couleurMOR = couleurDominante.getRouge()-20; // Creation de la couleur de l'ombre
    uint8_t couleurMOV = couleurDominante.getVert()-20;
    uint8_t couleurMOB = couleurDominante.getBleu()-20;
    Couleur couleurMontagneombre{couleurMOR,couleurMOV,couleurMOB};

    Triangle* montagne = new Triangle(basGauche,basDroite,hautMilieu,couleurmontagne);// Creation du triangle représntant la montagne
    m_liste.push_back(montagne); // Mettre le triangle dans la liste à dessiner

    if(basMilieu.getX() <= 500) // à gauche du centre
    {
        Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())*(1-(basMilieu.getX()/500)),basDroite.getY()}; // Creation du point en bas du triangle
        Triangle* montagneombre = new Triangle(basOmbre,basGauche,hautMilieu,couleurMontagneombre); // Creation du triangle représntant l'ombre
        m_liste.push_back(montagneombre); // Mettre le triangle dans la liste à dessiner
    }
    if(basMilieu.getX() > 500) // à droite du centre
    {
        Coords basOmbre{basGauche.getX() + (basDroite.getX()-basGauche.getX())*(1-((basMilieu.getX()-500)/500)),basDroite.getY()}; // Creation du point en bas du triangle
        Triangle* montagneombre = new Triangle(basOmbre,basDroite,hautMilieu,couleurMontagneombre); // Creation du triangle représntant l'ombre
        m_liste.push_back(montagneombre); // Mettre le triangle dans la liste à dessiner
    }


    /// Neige

    int i = util::alea(0,1,graine); // une chance sur deux d'avoir de la neige
    if(i==1)
    {
        Coords basDroiteN{hautMilieu.getX()+((basDroite.getX()-hautMilieu.getX())/3),hautMilieu.getY()+((basDroite.getY()-hautMilieu.getY())/3)}; // Calcul du point en bas à droite de la neige
        Coords basGaucheN{hautMilieu.getX()-((hautMilieu.getX()-basGauche.getX())/3),hautMilieu.getY()+((basGauche.getY()-hautMilieu.getY())/3)}; // Calcul du point au sommet de la montagne de la neige
        Coords basMilieuN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())/2,hautMilieu.getY()+((basGaucheN.getY()-hautMilieu.getY())/3)}; // Calcul du point en bas au milieu de la neige

        //Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())/3*2,hautMilieu.getY()+((basGauche.getY()-hautMilieu.getY())/3)};

        uint8_t couleurN = util::alea(230,255,graine); // Creation de la couleur de neige
        Couleur neige{couleurN,couleurN,255};
        uint8_t couleurNF = couleurN-50; // Creation de la couleur de l'ombre
        Couleur neigeF{couleurNF,couleurNF,255-50};


        Triangle* montagne2 = new Triangle(basGaucheN,basDroiteN,hautMilieu, neige); // Creation du triangle représntant la montagne
        m_liste.push_back(montagne2); // Mettre le triangle dans la liste à dessiner

        if(basMilieuN.getX() <= 500) // à gauche du centre
        {
            Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())*(1-(basMilieu.getX()/500)),basDroiteN.getY()}; // Creation du point en bas du triangle
            Triangle* montagne2ombre = new Triangle(basOmbreN,basGaucheN,hautMilieu,neigeF); // Creation du triangle représntant l'ombre
            m_liste.push_back(montagne2ombre); // Mettre le triangle dans la liste à dessiner
        }
        if(basMilieuN.getX() > 500) // à droit du centre
        {
            Coords basOmbreN{basGaucheN.getX() + (basDroiteN.getX()-basGaucheN.getX())*(1-((basMilieuN.getX()-500)/500)),basDroiteN.getY()};// Creation du point en bas du triangle
            Triangle* montagne2ombre = new Triangle(basOmbreN,basDroiteN,hautMilieu,neigeF); // Creation du triangle représntant l'ombre
            m_liste.push_back(montagne2ombre);// Mettre le triangle dans la liste à dessiner
        }

    }

    /// Nuages

    int j = util::alea(0,1,graine); // une chance sur deux d'avoir des nuages
    if(j==1)
    {
        for(int k=0;k<10;k++) // Boucle servant à creer les ellipses
        {
            int nX = util::alea(hautMilieu.getX()-50,hautMilieu.getX()+50,graine); // abssice du centre
            int nY = util::alea(hautMilieu.getY()+50,hautMilieu.getY()+55,graine); // ordonnée du centre
            Coords centre(nX,nY);
            int rX = util::alea(20,30,graine); // rayon 1
            int rY = util::alea(4,6,graine); // rayon 2
            uint8_t couleurB = 255,couleurN = 230; // creation des couleurs Blanc et le blanc foncé
            Couleur B{couleurB,couleurB,couleurB},N{couleurN,couleurN,couleurN};
            Ellipse* Blanc = new Ellipse(centre,rX,rY,B); // Creation de la premiere ellipse
            Ellipse* Noir = new Ellipse(centre,rX+1,rY+1,N); // Creation de la deuxieme ellipse
            m_liste.push_back(Noir); // Mettre la premiere ellipse dans la liste à dessiner
            m_liste.push_back(Blanc); // Mettre la deuxieme ellipse dans la liste à dessiner

        }
    }
}
