#include <stdio.h>
#include <stdlib.h>
#include "../header/livres.h"
#include "../header/clients.h"
#include "../header/emprunts.h"
#include "../header/liste_adherants.h"
#include "../header/bibliotheque.h"

int gestion()
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    int main();
    void livres();
    int ajouter_livres();
    void liste_adherants();
    void liste_emprunts();
    void liste_retard_depot();
    int supprimer_emprunter();

    //Variables 
    int choix_liv,choix_menu, option;

    printf(" \n \n ***************** GESTION DE LA BIBLIOTHEQUE NUMERIQUE ***************** \n \n ");
    printf(" \n ***************** MENU DU GESTIONNAIRE ***************** \n \n ");

    printf(" \n -------> 1 - Livres \n");
    printf(" \n -------> 2 - Emprunts \n");
    printf(" \n -------> 3 - Nos clients \n");
    printf(" \n -------> 4 - Accueil \n");

    printf("\n \n  ------->  Taper le numero de votre choiX \n \n");
    do
    {
        scanf("%d",&choix_menu);
        switch(choix_menu)
        {
            case 1:
                livres();
                printf(" \n ********** 1 - Ajouter des livres \n");
                printf(" \n ********** 2 - Modifier un livre \n");
                printf(" \n ********** 3 - Supprimer des livre \n");
                printf("\n \n  ------->  Taper le numero de votre choiX \n \n");
                scanf("%d",&option);
                if (option == 1)
                {
                    ajouter_livres();
                }
                else if (option == 2)
                {
                    modifier_livres();
                }
                else if (option == 3)
                {
                    supprimer_livres();
                }
                else
                {
                    gestion();
                }
            break;
            case 2:
                liste_emprunts();
                printf(" \n \n \n ********** 1 - Liste des retards \n");
                printf(" \n ********** 2 - Supprimer un emprunt \n");
                printf("\n \n  ------->  Taper le numero de votre choiX \n \n");
                scanf("%d",&option);
                if (option == 1)
                {
                    liste_retard_depot();
                }
                else if (option == 2)
                {
                    supprimer_emprunter();
                }
                else
                {
                    gestion();
                }
            break;
            case 3:
                liste_adherants();
                printf("\n \n \n ------->  Voulez-vous revenir au menu gestionnaire ? \n \n   1 - OUI \n   2 - NON (retour a page d'accueil) ");
                printf("\n \n  ------->  Taper le numero de votre choiX \n \n");
                scanf("%d",&option);
                if(option == 1)
                {
                    gestion();
                }
                else
                {
                    main();
                }
            break;
            case 4:
                main();
            break;
            default:
                printf(" \n ERREUR DE SAISI VUEILLER RÉESSAYER ! \n");
                choix_menu = 0;
        }
    } while (choix_menu==0);
    
    return 0;
}