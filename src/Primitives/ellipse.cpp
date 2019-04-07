#include "ellipse.h"

Ellipse::Ellipse(Coords centre, double rx, double ry, Couleur color, double epaisseur, Couleur couleurContourEllipse, double opacity)
    : m_centre{centre}, m_rayonX{rx}, m_rayonY{ry}, m_couleurEllipse{color}, m_epaisseur{epaisseur},
      m_couleurContourEllipse{couleurContourEllipse}, m_opacity{opacity}
{ }

void Ellipse::afficher()const
{
    std::cout << "ELLIPSE" << std::endl;
    m_centre.afficher();
    std::cout<< std::endl;
    std::cout << m_rayonX << std::endl;
    std::cout << m_rayonY << std::endl;
    m_couleurEllipse.afficher();
    std::cout << std::endl;
}

void Ellipse::dessiner(Svgfile& svgout)
{
    svgout.addEllipse(m_centre.getX(), m_centre.getY(), m_rayonX, m_rayonY, m_couleurEllipse, m_epaisseur, m_couleurContourEllipse, m_opacity);
}
