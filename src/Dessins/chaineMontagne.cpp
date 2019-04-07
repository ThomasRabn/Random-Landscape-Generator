#include "chaineMontagne.h"

ChaineMontagne::ChaineMontagne(Couleur couleurDominante, double nombreMontagne, std::mt19937 graine) // creation de la classe Chaine de montagne regroupant des montagnes
    :Groupe{}
{
    int nbrMontagne;
    if(nombreMontagne == -1) //nombre de montagne aléatoire au debut de 5 à 10
    {
        nbrMontagne = util::alea(5,10);
    }
    else{
        nbrMontagne = (int)nombreMontagne; //sinon le nombre de montagne est egale a celui donné par l'utilisateur
    }

    Couleur colorNone{0,0,0}; // creation de la couleur vide

    std::mt19937 aleatoire{0};
    if(graine == aleatoire) // verification de la valeur de la graine
    {
        for(int i=0;i<nbrMontagne;i++) // Boucle pour la creation du nombre des montagnes
        {
            double basGaucheX = util::alea(-100,800); //creation des points des montagnes
            double basGaucheY = 550;
            double hautDroiteX = util::alea(basGaucheX+200,basGaucheX+500);
            double hautDroiteY = util::alea(250,400);

            Coords basGauche(basGaucheX,basGaucheY); //creation des points des montagnes
            Coords hautDroite(hautDroiteX,hautDroiteY);

            if(couleurDominante == colorNone) // verification de la couleur dominante
            {
                Montagne* montagne = new Montagne(basGauche,hautDroite); //creation de la montagne
                m_liste.push_back(montagne); //ajout de la montagne dans la liste a dessiner
            }
            else{
                Montagne* montagne = new Montagne(basGauche,hautDroite,couleurDominante); //creation de la montagne
                m_liste.push_back(montagne); //ajout de la montagne dans la liste a dessiner
            }
        }
    }

    else{
        for(int i=0;i<nbrMontagne;i++) // Boucle pour la creation du nombre des montagnes
        {
            double basGaucheX = util::alea(-100,800,graine); //creation des points des montagnes
            double basGaucheY = 550;
            double hautDroiteX = util::alea(basGaucheX+200,basGaucheX+500,graine);
            double hautDroiteY = util::alea(250,400,graine);

            Coords basGauche(basGaucheX,basGaucheY); //creation des points des montagnes
            Coords hautDroite(hautDroiteX,hautDroiteY);

            if(couleurDominante == colorNone) // verification de la couleur dominante
            {
                Montagne* montagne = new Montagne(basGauche,hautDroite,graine); //creation de la montagne
                m_liste.push_back(montagne); //ajout de la montagne dans la liste a dessiner
            }
            else{
                Montagne* montagne = new Montagne(basGauche,hautDroite,couleurDominante,graine); //creation de la montagne
                m_liste.push_back(montagne); //ajout de la montagne dans la liste a dessiner
            }


        }
    }

}
