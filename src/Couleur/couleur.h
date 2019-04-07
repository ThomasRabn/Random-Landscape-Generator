#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

#include <string>
#include <cstdint>
#include "../util/util.h"

class Couleur
{
    public :
        Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu);
        Couleur();
        void afficher() const;
        void saisir();

        void muter(double amplitude, std::mt19937& graine);
        void muter(double amplitude);

        uint8_t getRouge()const
        { return m_rouge; }

        uint8_t getVert()const
        { return m_vert; }

        uint8_t getBleu()const
        { return m_bleu; }

        operator std::string() const;

    private :
        // uint8_t équivalent à unsigned char :
        // unsigned 8 bits (8 bits non signé)
        uint8_t m_rouge, m_vert, m_bleu;
};

inline bool operator==(const Couleur& a, const Couleur& b)
{
    return (a.getBleu()==b.getBleu() && a.getRouge() == b.getRouge() && a.getVert() == b.getVert());
}

#endif // COULEUR_H_INCLUDED
