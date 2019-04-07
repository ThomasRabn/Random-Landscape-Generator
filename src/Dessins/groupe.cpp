#include "groupe.h"

/// Constructeur vide
Groupe::Groupe()
    : Dessin{}, m_liste{}
{ }

/// Destructeur
Groupe::~Groupe()
{
    /// Pour chaque element du vecteur
    for(const auto& ptr : m_liste)
    {
        delete ptr; /// On libère la mémoire
    }
}

/// Méthode dessiner
void Groupe::dessiner(Svgfile& svgout)
{
    trier(); /// On trie le vecteur
    /// Pour chaque element du vecteur
    for(const auto& ptr : m_liste)
    {
        ptr->dessiner(svgout); /// On le dessine
    }
}

/// Permet d'afficher toutes les données
void Groupe::afficher()const
{
    /// pour tout le vecteur
    for(const auto& ptr : m_liste)
    {
        /// on affiche les données
        ptr->afficher();
    }
}

/// Tri fait maison
void Groupe::trier()
{
    /// Pour chaque élément du vecteur
    for(unsigned int i=1; i<m_liste.size(); ++i)
    {
        unsigned int j = i;
        /// On le déplace jusqu'à sa position (plus il est profond, plus il va au début)
        while((j>0)&&(m_liste[j-1]->getProfondeur() < m_liste[j]->getProfondeur()))
        {
            Dessin* temp = m_liste[j];
            m_liste[j] = m_liste[j-1];
            m_liste[j-1] = temp;
            --j;
        }
    }
}
