#include "FloteSpaceShip.h"
/** v�rifie que le constructeur re�oit bien une graine valide. Si non on appel
le constructeur qui va g�n�rer des vaisseaux al�atoirements **/
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
/** constructeur al�atoire qui va g�n�rer un nombre de vaisseau ainsi que leurs positions **/
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
en fonction de la s�rie de nombres choisie par la graine **/
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
