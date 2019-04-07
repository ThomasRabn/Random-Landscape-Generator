#include "FloteSpaceShip.h"
/** vérifie que le constructeur reçoit bien une graine valide. Si non on appel
le constructeur qui va générer des vaisseaux aléatoirements **/
FloteSpaceShip::FloteSpaceShip(double nombreVaisseau, std::mt19937 graine)
    :Groupe{}
{
    std::mt19937 aleatoire{0};
    if (graine == aleatoire)
    {
        constructeurAleatoire(nombreVaisseau);
    }
    else
    {
        constructeurGraine(graine, nombreVaisseau);
    }
}
/** constructeur aléatoire qui va générer un nombre de vaisseau ainsi que leurs positions **/
void FloteSpaceShip::constructeurAleatoire(double nombreVaisseau)
{
    double nbrVaisseau = 0;
    if (nombreVaisseau == -1)       { nbrVaisseau = util::alea(5,10); }
    else nbrVaisseau = nombreVaisseau;
    for(int i=0;i<nbrVaisseau;i++)
    {
        double hautGaucheX = util::alea(0,1000);
        double hautGaucheY = util::alea(0,250);

        Coords hautGauche(hautGaucheX,hautGaucheY);

        SpaceShip* vaisseau = new SpaceShip(hautGauche);
        m_liste.push_back(vaisseau);
    }
}
/** constructeur qui va choisir le nombre de vaisseau ainsi que leurs positions
en fonction de la série de nombres choisie par la graine **/
void FloteSpaceShip::constructeurGraine(std::mt19937 graine, double nombreVaisseau)
{
    double nbrVaisseau = 0;
    if (nombreVaisseau == -1)nbrVaisseau = util::alea(3,30,graine);
    else nbrVaisseau = nombreVaisseau;
    for(int i=0;i<nbrVaisseau;i++)
    {
        double hautGaucheX = util::alea(0,1000,graine);
        double hautGaucheY = util::alea(0,250,graine);

        Coords hautGauche(hautGaucheX,hautGaucheY);

        SpaceShip* vaisseau = new SpaceShip(hautGauche, graine);
        m_liste.push_back(vaisseau);
    }
}
