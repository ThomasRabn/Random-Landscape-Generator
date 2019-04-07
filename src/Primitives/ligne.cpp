#include "ligne.h"

Ligne::Ligne(Coords a, Coords b, Couleur couleurLigne)
    :m_a{a}, m_b{b}, m_couleurLigne{couleurLigne}
{}

void Ligne::dessiner(Svgfile& svgout)
{
     svgout.addLine(m_a.getX(), m_a.getY(), m_b.getX(), m_b.getY(), m_couleurLigne);
}

void Ligne::afficher()const
{
    std::cout << "Ligne :";
    m_a.afficher();
    std::cout << std::endl;
    m_b.afficher();
    std::cout << std::endl;
    m_couleurLigne.afficher();
    std::cout << std::endl;
}
