/**
 * @file main.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE(Kounapetri05@gmail.com) et ZOMADI MARCLEORD(zomadimarcleord@gmail.com)
 * @brief La page d'acceuil de l'application
 * @version 0.1
 * @date 2022-02-20 au 2022-03-14
 * 
 * @copyright Copyright (c) OKA && ZOMADI
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/livres.h"
#include "../header/clients.h"
#include "../header/action_client.h"
#include "../header/gestion.h"


int main()
{ 
    system("clear");
    
    /* Appel initialisations des differents fonctions */
    int ajout_adherants();
    int emprunter();
    void livres();
    int deposer();
    int gestion();

    //Variables 
    int choix;
    printf("  \n \n ******************************** BIENVENU DANS LA BIBLIOTHEQUE NUMERIQUE DE LA SIGL ******************************** \n \n ");


    printf(" \n ----------------------------------->  1 - Livres ");
    printf(" \n ----------------------------------->  2 - Emprunter ");
    printf(" \n ----------------------------------->  3 - Deposer");
    printf(" \n ----------------------------------->  4 - Inscription");
    printf(" \n ----------------------------------->  5 - Gestionnaire");
    printf(" \n ----------------------------------->  6 - Quitter \n");
    printf("\n \n  ---------------------------->  Taper le numero de votre choiX \n \n");
    
    do
    {
        scanf("%d",&choix);
        switch(choix)
        {
            case 1 :
                livres();
                emprunter();
                break;
            case 2 :
                emprunter();
                break;
            case 3 :
                deposer();
            case 4 :
                ajout_adherants();
                break;
            case 5 :
                gestion();
                break;
            case 6 :
                printf(" \n \n Merci d'être venu, a la prochaine \n \n");
                break;
            default :
                printf(" \n ERREUR DE SAISI VEUILLER RÉESSAYER ! \n");
                choix = 0;
        }
    } while (choix == 0);

    return 0;
}