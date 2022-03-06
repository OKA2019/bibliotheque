#include <stdio.h>
#include "../header/livres.h"
#include "../header/ajouter_livre.h"
#include "../header/adherants.h"
#include "../header/emprunter.h"

int main()
{
    //Appel initialisations des differents fonctions
    void livres();
    int ajouter_livres();

    //Variables 
    int choix_liv,choix_menu, compte_exit;


        printf(" \n \n ***************** GESTION DE LA BIBLIOTHEQUE NUMERIQUE ***************** \n \n ");

        printf(" \n ***************** MENU ***************** \n \n ");

        printf(" \n  1 - Aderents \n");
        printf(" \n  2 - Liste des livres \n");
        printf(" \n  3 - Listes des Emprunts \n");
        printf(" \n  4 - Ajouter des livres \n");
        printf(" \n  5 - Quitter \n");

        do
        {
            scanf("%d",&choix_menu);
            switch(choix_menu)
            {
                case 1:
                    //Appel de la fonctions listes des aderents

                break;
                case 2:
                    //Appel de la fonctions listes
                    livres();

                break;
                case 3:
                    //Appel de la fonctions listes des aderents

                break;
                case 4:
                    //Appel de la fonctions Ajouter livres
                    ajouter_livres();
                break;
                case 5:
                    //Appel de la fonctions listes des aderents

                break;
                default:
                    choix_menu = 0;
                    printf("\n Erreur de saisi, veullez réessayer \n ");
            }
        } while (choix_menu==0);
       
    return 0;
}