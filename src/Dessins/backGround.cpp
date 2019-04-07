#include "backGround.h"
#include "../Primitives/ligne.h"
#include "../Primitives/blurredDisque.h"
/** On construit le Background du projet en recevant une valeurAleatoire qui correspond à la
couleur du ciel ainsi que la graine pour fixer le troisième plan si le client veut garder le
même plan. On fait donc ensuite un test pour savoir si il y a une graine dans ce cas on crée
les valeurs en fonction de cette dernière sinon on crée des valeurs aléatoires. Ensuite on va
envoyer les données à "constructeurBackground" qui va gérer la construction des éléments en
fonction des paramètres envoyés**/
BackGround::BackGround(int valeurAleatoire, std::mt19937 graine)
    : Groupe{}
{
    std::mt19937 aleatoire{0};
    double rayon;
    if(graine == aleatoire)
    {
        rayon = util::alea(300.0,400.0);
        if(valeurAleatoire == -1)   valeurAleatoire = util::alea(0,5); /// modulo 6
    }
    else
    {
        rayon = util::alea(300.0,400.0, graine);
        if(valeurAleatoire == -1)   valeurAleatoire = util::alea(0,5, graine); /// modulo 6
    }
    constructeurBackground(rayon,valeurAleatoire);
}
/** Le constructeur qui va afficher l'arrière plan avec un soleil et un gradient de couleur qui dépend de la valeurAleatoire
reçue en paramètre. On crée et enregistre toutes ces valeurs dans "m_liste" qui sera déssinée ensuite grâce au polymorphisme **/
void BackGround::constructeurBackground(double rayon, int valeurAleatoire)
{
    double longueurBande = 0.5;
    double maxScreenY = 550, maxScreenX = 1000;
    Couleur couleurLigne{0,0,0};
    Couleur couleurSoleil{0,0,0};

    switch (valeurAleatoire)
        {
            case 0:
                couleurSoleil = {240,240,0}; //Jaune
                break;
            case 1:
                couleurSoleil = {240,0,0}; //Rouge
                break;
            case 2:
                couleurSoleil = {240,240,0}; //Jaune
                break;
            case 3:
                couleurSoleil = {0,240,0}; //Vert
                break;
            case 4:
                couleurSoleil = {0,240,240}; //Bleu clair
                break;
            case 5:
                couleurSoleil = {0,0,240}; //Bleu Fonce
                break;
        }

    for (double i=0 ; i<=maxScreenY ; i+=longueurBande)
    {
        uint8_t modifCouleur = ((maxScreenY-i)/maxScreenY)*255;
        uint8_t inversionCouleur = 255-((maxScreenY-i)/maxScreenY)*255;

        switch (valeurAleatoire)
        {
            case 0:
                couleurLigne = {255,modifCouleur,0}; //Jaune vers Rouge
                break;
            case 1:
                couleurLigne = {255,inversionCouleur,0}; //Rouge vers Jaune
                break;
            case 2:
                couleurLigne = {modifCouleur,255,0}; //Jaune vers Vert
                break;
            case 3:
                couleurLigne = {inversionCouleur,255,0}; //Vert vers Jaune
                break;
            case 4:
                couleurLigne = {0,modifCouleur,255}; //Bleu Clair vers Fonce
                break;
            case 5:
                couleurLigne = {0,inversionCouleur,255}; //Bleu Fonce vers Clair
                break;
        }

        Coords ligneGauche{0,i};
        Coords ligneDroite{maxScreenX,i+longueurBande};

        Ligne* ligneActuelle = new Ligne(ligneGauche,ligneDroite,couleurLigne);
        m_liste.push_back(ligneActuelle);
    }
    Coords centreSoleil{500,550};
    BlurredDisque* soleil = new BlurredDisque(centreSoleil,rayon,couleurSoleil);
    m_liste.push_back(soleil);
}
