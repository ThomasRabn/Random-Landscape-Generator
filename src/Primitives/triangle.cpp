#include "triangle.h"

Triangle::Triangle(Coords a, Coords b, Coords c, Couleur couleur, double ep, Couleur couleurContour)
    :m_a{a}, m_b{b}, m_c{c}, m_couleurTriangle{couleur}, m_epaisseur{ep}, m_couleurContourTriangle{couleurContour}
{ }

void Triangle::dessiner(Svgfile& svgout)
{
    svgout.addTriangle(m_a.getX(), m_a.getY(), m_b.getX(), m_b.getY(), m_c.getX(), m_c.getY(),
                       m_couleurTriangle, m_epaisseur, m_couleurContourTriangle);
}

void Triangle::afficher()const
{
    std::cout << "TRIANGLE :";
    m_a.afficher();
    std::cout << std::endl;
    m_b.afficher();
    std::cout << std::endl;
    m_c.afficher();
    std::cout << std::endl;
    m_couleurTriangle.afficher();
    std::cout << std::endl;
}

