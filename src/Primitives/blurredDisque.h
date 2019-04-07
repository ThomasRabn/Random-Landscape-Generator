#ifndef BLURREDDISQUE_H_INCLUDED
#define BLURREDDISQUE_H_INCLUDED

#include "disque.h"

/// Classe mod�lisant un disque flou (d�rive de Disque)
class BlurredDisque : public Disque
{
    public:
        BlurredDisque(Coords centre, double rayon, Couleur couleurDisque, double opacity = 1);

        void dessiner(Svgfile& svgout);
};


#endif // BLURREDDISQUE_H_INCLUDED
