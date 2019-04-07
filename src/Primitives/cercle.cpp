#include "cercle.h"

Cercle::Cercle(Coords centre, double r, double ep, Couleur color)
    : m_centre{centre}, m_rayon{r}, m_epaisseur{ep}, m_couleurCercle{color}
{ }

void Cercle::afficher()const
{
    std::cout << "CERCLE" << std::endl;
    m_centre.afficher();
    std::cout<< std::endl;
    std::cout << m_rayon << std::endl;
    std::cout << m_epaisseur << std::endl;
    m_couleurCercle.afficher();
    std::cout << std::endl;
}

void Cercle::dessiner(Svgfile& svgout)
{
    svgout.addCircle(m_centre.getX(), m_centre.getY(), m_rayon, m_epaisseur, m_couleurCercle);
}
