#include <stdio.h>
#include <stdlib.h>
#include "../header/livres.h"
#include "../header/ajouter_livres.h"
#include "../header/adherants.h"
#include "../header/liste_emprunts.h"
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
    int liste_emprunts();

    //Variables 
    int choix_liv,choix_menu, compte_exit;


        printf(" \n \n ***************** GESTION DE LA BIBLIOTHEQUE NUMERIQUE ***************** \n \n ");

        printf(" \n ***************** MENU DU GESTIONNAIRE ***************** \n \n ");

        printf(" \n  1 - Adherants \n");
        printf(" \n  2 - Liste des livres \n");
        printf(" \n  3 - Listes des Emprunts \n");
        printf(" \n  4 - Ajouter des livres \n");
        printf(" \n  5 - Accueil \n");

        printf("\n \n  ------->  Taper le numero de votre choiX \n \n");

        do
        {
            scanf("%d",&choix_menu);
            switch(choix_menu)
            {
                case 1:
                    //Appel de la fonctions listes des aderents
                    liste_adherants();
                break;
                case 2:
                    //Appel de la fonctions listes
                    livres();
                break;
                case 3:
                    //Appel de la fonctions listes des emprunts
                    liste_emprunts();
                case 4:
                    //Appel de la fonctions Ajouter livres
                    ajouter_livres();
                case 5:
                    //Appel de la fonctions listes des aderents
                    main();
                case 6:
                    printf(" \n Merci d'être venu, a la prochaine ");
                default:
                    printf(" \n ERREUR DE SAISI VUEILLER RÉESSAYER ! ");
                    choix_menu==0;
            }
        } while (choix_menu==0);
       
    return 0;
}