#include "structureChoix.h"

void Choix::changerGraine()
{
    int graine;
    int verif = 0;
    std::cout << "Vous avez decide de changer la graine. Entrez une valeur svp (0 = aleatoire) : ";

    do{
        if(!(std::cin >> graine))
        {
            std::cout << "Mauvaise entree" << std::endl;
            std::cin.clear(); // effacer les bits d'erreurs
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
        }

        else{
            std::mt19937 rg{graine};
            m_graine = rg;
            verif = 1;
        }

    }while(verif!=1);
}

void Choix3::changerGraine()
{
    int graine;
    int verif = 0;
    std::cout << "Vous avez decide de changer la graine. Entrez une valeur svp (0 = aleatoire) : ";

    do{
        if(!(std::cin >> graine))
        {
            std::cout << "Mauvaise entree" << std::endl;
            std::cin.clear(); // effacer les bits d'erreurs
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
        }

        else{
            std::mt19937 rg{graine};
            m_graine = rg;
            verif = 1;
        }

    }while(verif!=1);
}

void Choix::changerCouleur()
{
    std::string color;
    int verif = 0;
    std::cout << "Vous avez decide de changer la couleur dominante." << std::endl
              << "Vous avez le choix entre \"None\" (pour de l'aleatoire), \"Rouge\", \"Vert\" et \"Bleu\"" << std::endl
              << "Quelle couleur voulez-vous : ";
    do{
        if(!(std::cin >> color))
        {
            std::cout << "Mauvaise entree" << std::endl;
            std::cin.clear(); // effacer les bits d'erreurs
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
        }

        else if((color != "None")&&(color != "Rouge")&&(color != "Vert")&&(color != "Bleu")
              &&(color != "none")&&(color != "rouge")&&(color != "vert")&&(color != "bleu"))
        {
            std::cout << "Mauvaise entree" << std::endl;
        }

        else if((color == "None")||(color == "none"))   { Couleur colortemp{0,0,0}; m_couleurDominante = colortemp; verif = 1; }
        else if((color == "Rouge")||(color == "rouge")) { Couleur colortemp{200,50,25}; m_couleurDominante = colortemp; verif = 1; }
        else if((color == "Vert")||(color == "vert"))   { Couleur colortemp{25,200,50}; m_couleurDominante = colortemp; verif = 1; }
        else if((color == "Bleu")||(color == "bleu"))   { Couleur colortemp{50,25,200}; m_couleurDominante = colortemp; verif = 1; }

        else{
            std::cout << "ERREUR ELSE CHANGEMENT COULEUR" << std::endl;
        }

        std::cout << std::endl;

    }while(verif!=1);
}

void Choix3::changerCouleur()
{
    std::string color;
    int verif = 0;
    std::cout << "Vous avez decide de changer la couleur dominante." << std::endl
              << "Vous avez le choix entre \"None\" (pour de l'aleatoire), \"Rouge\", \"Vert\", \"Jaune\", \"BleuClair\"et \"BleuFonce\"" << std::endl
              << "Quelle couleur voulez-vous : ";
    do{
        if(!(std::cin >> color))
        {
            std::cout << "Mauvaise entree" << std::endl;
            std::cin.clear(); // effacer les bits d'erreurs
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
        }

        else if((color != "None")&&(color != "Rouge")&&(color != "Vert")&&(color != "Jaune")&&(color != "BleuClair")&&(color != "BleuFonce")
              &&(color != "none")&&(color != "rouge")&&(color != "vert")&&(color != "jaune")&&(color != "bleuclair")&&(color != "bleufonce"))
        {
            std::cout << "Mauvaise entree" << std::endl;
        }

        else if((color == "None")||(color == "none"))   {m_couleur = -1 ; verif = 1; }
        else if((color == "Rouge")||(color == "rouge")) {m_couleur = 1; verif = 1; }
        else if((color == "Vert")||(color == "vert"))   {m_couleur = 3; verif = 1; }
        else if((color == "Jaune")||(color == "jaune"))   {m_couleur = 0; verif = 1; }
        else if((color == "BleuClair")||(color == "bleuclair"))   {m_couleur = 4; verif = 1; }
        else if((color == "BleuFonce")||(color == "bleufonce"))   {m_couleur = 5; verif = 1; }


        else{
            std::cout << "ERREUR ELSE CHANGEMENT COULEUR" << std::endl;
        }

        std::cout << std::endl;

    }while(verif!=1);
}

void Choix::changerParametreSuppPlan1()
{
    int verif = 0;
    double paramSupp = 0;

    std::cout << "Vous avez decide de changer la taille des objets." << std::endl
              << "Veuillez entrez une taille entre 50 et 150 : ";

    do{
        if(!(std::cin >> paramSupp))
        {
            std::cout << "Mauvaise entree" << std::endl;
            std::cin.clear(); // effacer les bits d'erreurs
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
        }

        else if((paramSupp < 50)||(paramSupp > 150))
        {
            std::cout << "Mauvaise entree" << std::endl;
        }

        else{
            m_paramSupp = paramSupp;
            verif = 1;
        }

        std::cout << std::endl;

    }while(verif!=1);
}

void Choix::changerParametreSuppPlan2()
{
    int verif = 0;
    double paramSupp = 0;

    std::cout << "Vous avez decide de changer le nombre de montagnes." << std::endl
              << "Veuillez entrez un nombre entre 1 et 100 : ";

    do{
        if(!(std::cin >> paramSupp))
        {
            std::cout << "Mauvaise entree" << std::endl;
            std::cin.clear(); // effacer les bits d'erreurs
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
        }

        else if((paramSupp < 0)||(paramSupp > 100))
        {
            std::cout << "Mauvaise entree" << std::endl;
        }

        else{
            m_paramSupp = paramSupp;
            verif = 1;
        }

        std::cout << std::endl;

    }while(verif!=1);
}

void Choix3::changerNombreVaisseaux()
{
    int verif = 0;
    double paramSupp = 0;

    std::cout << "Vous avez decide de changer le nombre d'objets." << std::endl
              << "Veuillez entrez une taille entre 0 et 100 (-1 pour un nombre Aleatoire): ";

    do{
        if(!(std::cin >> paramSupp))
        {
            std::cout << "Mauvaise entree" << std::endl;
            std::cin.clear(); // effacer les bits d'erreurs
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
        }

        else if((paramSupp < -1)||(paramSupp > 100))
        {
            std::cout << "Mauvaise entree" << std::endl;
        }

        else{
            m_paramSupp = paramSupp;
            verif = 1;
        }

        std::cout << std::endl;

    }while(verif!=1);
}
