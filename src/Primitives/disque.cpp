#include "disque.h"

Disque::Disque(Coords centre, double rayon, Couleur couleurDisque, double opacity)
    :m_centre{centre},m_rayon{rayon},m_couleurDisque{couleurDisque}, m_opacity{opacity}
{}

void Disque::dessiner(Svgfile& svgout)
{
    svgout.addDisk(m_centre.getX(), m_centre.getY(), m_rayon, m_opacity, m_couleurDisque);
}

void Disque::afficher()const
{
    std::cout << "DISQUE :";
    m_centre.afficher();
    std::cout << std::endl << m_rayon << std::endl;
    m_couleurDisque.afficher();
    std::cout << std::endl;

}
