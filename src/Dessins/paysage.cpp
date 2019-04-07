#include "paysage.h"

/// Constructeur
Paysage::Paysage()
    : Groupe{}
{
    m_deuxiemePlan.m_paramSupp = 5;
    actualiserListe(); ///On actualise la liste dès la création d'un paysage
}

/// actualiseur de liste
void Paysage::actualiserListe()
{
    for(const auto& ptr : m_liste) /// On libère la mémoire de tous ce qu'il y a dans le vecteur
    {
        delete ptr;
    }

    m_liste.clear(); /// On vide le vecteur

    /// On crée trois calque, 1 pour chaque plan, en foncion de ce que l'utilisateur a entré
    PremierPlan* calque1 = new PremierPlan(m_premierPlan);
    DeuxiemePlan* calque2 = new DeuxiemePlan(m_deuxiemePlan);
    TroisiemePlan* calque3 = new TroisiemePlan(m_troisiemePlan);

    /// On met tout ça dans le vecteur
    m_liste.push_back(calque3);
    m_liste.push_back(calque2);
    m_liste.push_back(calque1);
}

/// Menu de base
void Paysage::menu()
{
    int choix = -1;
    int verif = 0;

    /// Menu qui tourne tant que l'utilisateur n'entre pas "0"
    do{
        std::cout << "Que voulez-faire ?" << std::endl
                  << "0) Quitter" << std::endl
                  << "1) Generer un paysage" << std::endl
                  << "2) Choisir les parametres de premier plan" << std::endl
                  << "3) Choisir les parametres de second plan" << std::endl
                  << "4) Choisir les parametres d'arriere plan" << std::endl
                  << "5) Charger les donnees precedemment sauvegardees" << std::endl
                  << "6) Sauvegarder les donnees" << std::endl;

        if(!(std::cin >> choix))
        {
            std::cout << "Mauvaise entree" << std::endl;
            std::cin.clear(); // effacer les bits d'erreurs
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
        }

        else if(choix < 0 ||choix > 6)
        {
            std::cout << "Mauvaise entree, veuillez recommencer" << std::endl;
        }

        else if(choix == 0)
        {
            verif = 1;
        }

        else if(choix == 1)
        {
            std::cout << std::endl;
            Svgfile svgout;
            dessiner(svgout);
        }

        else if(choix == 2)
        {
            std::cout << std::endl;
            parametrePlan(1);
        }

        else if(choix == 3)
        {
            std::cout << std::endl;
            parametrePlan(2);
        }

        else if(choix == 4)
        {
            std::cout << std::endl;
            parametrePlan(3);
        }

        else if(choix == 5)
        {
            std::cout << std::endl;
            charger();
        }

        else if(choix == 6)
        {
            std::cout << std::endl;
            sauvegarder();
        }

        std::cout << std::endl;

    }while(verif != 1);
}

/// Permet à l'utilisateur de changer les paramètres
void Paysage::parametrePlan(int numeroPlan)
{
    int choix = 1;

    Choix* plan = nullptr;

    do{
        if(numeroPlan == 1)         { plan = &m_premierPlan; menuPlan1(); }

        else if(numeroPlan == 2)    { plan = &m_deuxiemePlan; menuPlan2(); }

        else if(numeroPlan == 3)    { menuPlan3(); }

        if(!(std::cin >> choix))
        {
            std::cout << "Mauvaise entree" << std::endl;
            std::cin.clear(); // effacer les bits d'erreurs
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
            std::cout << std::endl;
        }

        else if(choix < 0 ||choix > 3)
        {
            std::cout << "Mauvaise entree, veuillez recommencer" << std::endl;
            std::cout << std::endl;
        }


        else if((choix == 1)&&(numeroPlan != 3))        { std::cout << std::endl; plan->changerGraine(); choix = 0; }
        else if((choix == 1)&&(numeroPlan == 3))        { std::cout << std::endl; m_troisiemePlan.changerGraine(); choix = 0; }

        else if((choix == 2)&&(numeroPlan != 3))        { std::cout << std::endl; plan->changerCouleur(); choix = 0; }
        else if((choix == 2)&&(numeroPlan ==3 ))        { std::cout << std::endl; m_troisiemePlan.changerCouleur(); choix = 0; }

        else if(choix == 3)
        {
            std::cout << std::endl;
            if(numeroPlan == 1)             { m_premierPlan.changerParametreSuppPlan1(); choix = 0; }
            else if(numeroPlan == 2)        { m_deuxiemePlan.changerParametreSuppPlan2(); choix = 0; }
            else if(numeroPlan == 3)        { m_troisiemePlan.changerNombreVaisseaux(); choix = 0; }
        }

    }while(choix!=0);
}

/// Menu pour le plan 1
void Paysage::menuPlan1()
{
    std::cout << "Que voulez-faire ?" << std::endl
              << "0) Revenir au menu precedent" << std::endl
              << "1) Changer la graine du premier plan" << std::endl
              << "2) Changer la couleur dominante du plan" << std::endl
              << "3) Changer la taille moyenne des objets sur le premier plan" << std::endl;
}

/// Menu pour le plan 2
void Paysage::menuPlan2()
{
    std::cout << "Que voulez-faire ?" << std::endl
              << "0) Revenir au menu precedent" << std::endl
              << "1) Changer la graine du second plan" << std::endl
              << "2) Changer la couleur dominante du plan" << std::endl
              << "3) Changer le nombre de montagnes sur le second plan" << std::endl;
}

/// Menu pour le plan 3
void Paysage::menuPlan3()
{
    std::cout << "Que voulez-faire ?" << std::endl
              << "0) Revenir au menu precedent" << std::endl
              << "1) Changer la graine du troisieme plan" << std::endl
              << "2) Changer la couleur dominante du plan" << std::endl
              << "3) Changer le nombre de vaisseau sur le troisieme plan" << std::endl;
}

/// Dessine le paysage sur le svgout
void Paysage::dessiner(Svgfile& svgout)
{
    actualiserListe(); /// Actualise la liste
    for(const auto& ptr : m_liste) /// Dessine chaque vecteur de la liste
    {
        ptr->dessiner(svgout);
    }
}

/// Sauvegarde sur un fichiere
void Paysage::sauvegarder()
{
    std::ofstream fichier("sauvegarde.txt"); /// Ouvre le fichier "sauvegarde.txt"
    int choix;
    int verif = 0;

    /// Ouvre un menu pour savoir si l'utilisateur est sûr de vouloir sauvegarder
    do{
        std::cout << "Cela ecrasera les donnees precedentes. Etes-vous sur ? (1 pour accepter)" << std::endl;

        if(!(std::cin >> choix))
        {
            std::cout << "Mauvaise entree" << std::endl;
            std::cin.clear(); // effacer les bits d'erreurs
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
            std::cout << std::endl;
        }

        else{
            verif = 1;
        }
    }while(verif!=1);

    /// Si il ya un problème d'ouverture de fichier on affiche une erreur
    if(!fichier)
    {
        std::cerr << "ERREUR OUVERTURE FICHIER. VEUILLEZ REESSAYER" << std::endl;
    }

    /// Sinon, et si il a bien validé on enregistre les données
    else if(choix==1)
    {
        /// ENREGISTREMENT DES DONNÉES DU PREMIER PLAN
        fichier << m_premierPlan.m_graine << std::endl;
        fichier << (int)m_premierPlan.m_couleurDominante.getRouge() << std::endl;
        fichier << (int)m_premierPlan.m_couleurDominante.getVert() << std::endl;
        fichier << (int)m_premierPlan.m_couleurDominante.getBleu() << std::endl;
        fichier << m_premierPlan.m_paramSupp << std::endl;

        /// ENREGISTREMENT DES DONNÉES DU SECOND PLAN
        fichier << m_deuxiemePlan.m_graine << std::endl;
        fichier << (int)m_deuxiemePlan.m_couleurDominante.getRouge() << std::endl;
        fichier << (int)m_deuxiemePlan.m_couleurDominante.getVert() << std::endl;
        fichier << (int)m_deuxiemePlan.m_couleurDominante.getBleu() << std::endl;
        fichier << m_deuxiemePlan.m_paramSupp << std::endl;

        /// ENREGISTREMENT DES DONNÉES DU TROISIÈME PLAN
        fichier << m_troisiemePlan.m_graine << std::endl;
        fichier << m_troisiemePlan.m_couleur << std::endl;
        fichier << m_troisiemePlan.m_paramSupp << std::endl;

        std::cout << "Sauvergarde terminee." << std::endl;
    }

    else{
        std::cout << "Sauvegarde annulee." << std::endl;
    }
}

/// On charge les données du fichier de sauvegarde
void Paysage::charger()
{
    std::ifstream fichier("sauvegarde.txt"); /// On ouvre le fichier de sauvegarde

    int rouge;
    int vert;
    int bleu;

    if(!fichier) /// Si il y a un probleme d'ouverture on l'affiche
    {
        std::cerr << "ERREUR OUVERTURE FICHIER. VEUILLEZ REESSAYER. (Le fichie existe-t-il?)" << std::endl;
    }

    else /// Sinon on charge
    {
        /// RÉCUPÉRATION DES DONNÉES DU PREMIER PLAN
        fichier >> m_premierPlan.m_graine;
        fichier >> rouge;
        fichier >> vert;
        fichier >> bleu;
        Couleur newCouleur1(rouge, vert, bleu);
        m_premierPlan.m_couleurDominante = newCouleur1;
        fichier >> m_premierPlan.m_paramSupp;

        /// RÉCUPÉRATION DES DONNÉES DU SECOND PLAN
        fichier >> m_deuxiemePlan.m_graine;
        fichier >> rouge;
        fichier >> vert;
        fichier >> bleu;
        Couleur newCouleur2(rouge, vert, bleu);
        m_deuxiemePlan.m_couleurDominante = newCouleur2;
        fichier >> m_deuxiemePlan.m_paramSupp;

        /// RÉCUPÉRATION DES DONNÉES DU TROISIÈME PLAN
        fichier >> m_troisiemePlan.m_graine;
        fichier >> m_troisiemePlan.m_couleur;
        fichier >> m_troisiemePlan.m_paramSupp;

        std::cout << "Chargement termine." << std::endl;
    }
}
