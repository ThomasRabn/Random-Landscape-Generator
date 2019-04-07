#include "blurredDisque.h"

/// Constructeur
BlurredDisque::BlurredDisque(Coords centre, double rayon, Couleur couleurDisque, double opacity)
    :Disque{centre, rayon, couleurDisque, opacity}
{ }

void BlurredDisque::dessiner(Svgfile& svgout)
{
    svgout.addBlurredDisk(m_centre.getX(), m_centre.getY(), m_rayon, m_opacity, m_couleurDisque);
}
