#include "spaceShip.h"
#include "../Primitives/triangle.h"
/** Constructeur de vaisseau avec graine, le partern du vaisseau est fixe mais on peut facilement
modifier ses attributs ou sa forme. La position est reçue en paramètre et le vaisseau ce construit
à partie de ce simple coords. La couleur est choisie en fonction de la graine et ensuite on pushBack
les différentes valeurs obtenue dans le m_liste du SpaceShip crée **/
SpaceShip::SpaceShip(Coords positionShip, std::mt19937 graine)
    : Groupe{}
{
    uint8_t c1 = util::alea(0,255,graine);
    uint8_t c2 = util::alea(0,255,graine);
    uint8_t c3 = util::alea(0,255,graine);
    Couleur couleurCockpit{c1,c2,c3};
    Couleur couleurArmature{120,120,120};
    double hauteurShip = 25, longueurShip = 50, longueurReacteur = 25, longueurTrainee = 100, coefDiviseur=4;
    double coefModificateur = util::alea(0.4,1.0,graine);
    hauteurShip *= coefModificateur;
    longueurShip *= coefModificateur;
    longueurReacteur *= coefModificateur;
    longueurTrainee *= coefModificateur;

    m_profondeur = 1-coefModificateur;


    Coords mainHautGauche = positionShip;
    Coords mainCentre {positionShip.getX(),positionShip.getY()+hauteurShip};
    Coords mainBasDroite {positionShip.getX()+longueurShip,positionShip.getY()+hauteurShip};

    Coords cockpitHautGauche {positionShip.getX()+(longueurShip/coefDiviseur),positionShip.getY()+(hauteurShip/coefDiviseur)};
    Coords cockpitCentre {positionShip.getX()+(longueurShip/coefDiviseur),positionShip.getY()+hauteurShip-(hauteurShip/coefDiviseur)};
    Coords cockpitBasDroite {positionShip.getX()+longueurShip-(longueurShip/coefDiviseur),positionShip.getY()+hauteurShip-(hauteurShip/coefDiviseur)};

    Coords reacteurArriere {positionShip.getX()-longueurReacteur,positionShip.getY()};
    Coords reacteurCentre = positionShip;
    Coords reacteurBas = mainCentre;

    Coords traineeHaut = {positionShip.getX(),positionShip.getY()+(hauteurShip/6)};
    Coords traineeBas = {positionShip.getX(),positionShip.getY()+hauteurShip-(hauteurShip/6)};
    Coords traineeCentre {positionShip.getX()-longueurTrainee,(positionShip.getY()+(hauteurShip/6)+positionShip.getY()+hauteurShip-(hauteurShip/6))/2};

    //Cockpit allongé
    ///Coords cockpitBasDroite {positionShip.getX()+longueurShip,positionShip.getY()+hauteurShip};
    Triangle* triangleMain = new Triangle{mainHautGauche,mainCentre,{mainBasDroite},couleurArmature};
    Triangle* triangleCockpit = new Triangle{{cockpitHautGauche},{cockpitCentre},{cockpitBasDroite},couleurCockpit};
    Triangle* triangleTrainee = new Triangle{{traineeHaut},{traineeBas},{traineeCentre},couleurCockpit};
    Triangle* triangleReacteur = new Triangle{{reacteurArriere},{reacteurCentre},{reacteurBas},couleurArmature};

    m_liste.push_back(triangleMain);
    m_liste.push_back(triangleCockpit);
    m_liste.push_back(triangleTrainee);
    m_liste.push_back(triangleReacteur);
}
/** on utilise le même constructeur que pour le cas ou on recoit une graine en paramètre mais
dans ce cas toutes les valeurs seront tirées de manière aléatoire **/
SpaceShip::SpaceShip(Coords positionShip)
    : Groupe{}
{
    uint8_t c1 = util::alea(0,255);
    uint8_t c2 = util::alea(0,255);
    uint8_t c3 = util::alea(0,255);
    Couleur couleurCockpit{c1,c2,c3};
    Couleur couleurArmature{120,120,120};
    double hauteurShip = 25, longueurShip = 50, longueurReacteur = 25, longueurTrainee = 100, coefDiviseur=4;
    double coefModificateur = util::alea(0.4,1.0);
    hauteurShip *= coefModificateur;
    longueurShip *= coefModificateur;
    longueurReacteur *= coefModificateur;
    longueurTrainee *= coefModificateur;

    m_profondeur = 1-coefModificateur;


    Coords mainHautGauche = positionShip;
    Coords mainCentre {positionShip.getX(),positionShip.getY()+hauteurShip};
    Coords mainBasDroite {positionShip.getX()+longueurShip,positionShip.getY()+hauteurShip};

    Coords cockpitHautGauche {positionShip.getX()+(longueurShip/coefDiviseur),positionShip.getY()+(hauteurShip/coefDiviseur)};
    Coords cockpitCentre {positionShip.getX()+(longueurShip/coefDiviseur),positionShip.getY()+hauteurShip-(hauteurShip/coefDiviseur)};
    Coords cockpitBasDroite {positionShip.getX()+longueurShip-(longueurShip/coefDiviseur),positionShip.getY()+hauteurShip-(hauteurShip/coefDiviseur)};

    Coords reacteurArriere {positionShip.getX()-longueurReacteur,positionShip.getY()};
    Coords reacteurCentre = positionShip;
    Coords reacteurBas = mainCentre;

    Coords traineeHaut = {positionShip.getX(),positionShip.getY()+(hauteurShip/6)};
    Coords traineeBas = {positionShip.getX(),positionShip.getY()+hauteurShip-(hauteurShip/6)};
    Coords traineeCentre {positionShip.getX()-longueurTrainee,(positionShip.getY()+(hauteurShip/6)+positionShip.getY()+hauteurShip-(hauteurShip/6))/2};

    //Cockpit allongé
    ///Coords cockpitBasDroite {positionShip.getX()+longueurShip,positionShip.getY()+hauteurShip};
    Triangle* triangleMain = new Triangle{mainHautGauche,mainCentre,{mainBasDroite},couleurArmature};
    Triangle* triangleCockpit = new Triangle{{cockpitHautGauche},{cockpitCentre},{cockpitBasDroite},couleurCockpit};
    Triangle* triangleTrainee = new Triangle{{traineeHaut},{traineeBas},{traineeCentre},couleurCockpit};
    Triangle* triangleReacteur = new Triangle{{reacteurArriere},{reacteurCentre},{reacteurBas},couleurArmature};

    m_liste.push_back(triangleMain);
    m_liste.push_back(triangleCockpit);
    m_liste.push_back(triangleTrainee);
    m_liste.push_back(triangleReacteur);
}
