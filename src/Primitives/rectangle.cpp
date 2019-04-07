#include "rectangle.h"

Rectangle::Rectangle(Coords position, Coords taille, Couleur couleur, double ep, Couleur couleurContour)
    : m_position{position}, m_taille{taille}, m_couleurRectangle{couleur}, m_epaisseur{ep}, m_couleurContourRectangle{couleurContour}
{ }

void Rectangle::afficher()const
{
    std::cout << "RECTANGLE" << std::endl;
    m_position.afficher();
    std::cout << std::endl;
    m_taille.afficher();
    std::cout << std::endl;
    m_couleurRectangle.afficher();
    std::cout << std::endl;
}

void Rectangle::dessiner(Svgfile& svgout)
{
    svgout.addRectangle(m_position.getX(), m_position.getY(), m_taille.getX(), m_taille.getY(),
                        m_epaisseur, m_couleurRectangle, m_couleurContourRectangle);
}
