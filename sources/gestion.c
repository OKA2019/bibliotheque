/**
 * @file gestion.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE(Kounapetri05@gmail.com) et ZOMADI MARCLEORD(zomadimarcleord@gmail.com)
 * @brief Gestion de la bibliotheque
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
#include "../header/emprunts.h"
#include "../header/liste_adherants.h"
#include "../header/action_client.h"
#include "../header/bibliotheque.h"
#include "../header/lire.h"

/**
 * @brief Fonction de gestion de la bibliotheque
 */
int gestion()
{
    //Appel initialisations des differents fonctions
    int main();
    void livres();
    int ajouter_livres();
    void liste_adherants();
    void liste_emprunts();
    void liste_retard_depot();
    int supprimer_emprunter();
    char *lire(int size);

    //Variables 
    int choix_liv, choix_menu, quitter, option, continuer;
    char caractere, *nom_gestion, *pass_gestion;

    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        do
        {
            printf("\n**************************  AUTHENTIFICATION DU GESTIONNAIRE **************************\n\n");
    
            printf("\n\t Entrer votre nom d'utilisateur \n");
            getchar();
            nom_gestion = lire(31);
            printf("\t Entrer votre mot de pass \n");
            pass_gestion = lire(51);

            char gestionnaire[5000];
            sprintf(gestionnaire,"SELECT * FROM gestionnaire WHERE nom_gestion = '%s' AND pass_gestion = '%s' ", nom_gestion, pass_gestion);
            mysql_query(&mysql, gestionnaire);
            MYSQL_RES *resultat = NULL;
            MYSQL_ROW row;
            int i = 1;
            resultat = mysql_use_result(&mysql);
            printf("\n %s \n", resultat);
            row = mysql_fetch_row(resultat);
            if(row != NULL)
            {
                do
                {
                    //On efface l'écrans
                    system("clear");
                    printf(" \n ***************** MENU DU GESTIONNAIRE ***************** \n \n ");

                    printf(" \n\ --------------> 1 - Livres \n");
                    printf(" \n --------------> 2 - Emprunts \n");
                    printf(" \n --------------> 3 - Nos clients \n");
                    printf(" \n --------------> 4 - Accueil \n");

                    printf("\n \n  -------------->  Taper le numero de votre choiX \n \n");
                    scanf("%d",&choix_menu);
                    switch(choix_menu)
                    {
                        case 1:
                            livres();
                            printf(" \n ******************** 1 - Ajouter des livres \n");
                            printf(" \n ******************** 2 - Modifier un livre \n");
                            printf(" \n ******************** 3 - Supprimer des livre \n");
                            printf("\n \n  -------------->  Taper le numero de votre choiX \n \n");
                            scanf("%d",&option);
                            if (option == 1)
                            {
                                ajouter_livres();
                                quitter = 0;
                            }
                            else if (option == 2)
                            {
                                modifier_livres();
                                quitter = 0;
                            }
                            else if (option == 3)
                            {
                                supprimer_livres();
                                quitter = 0;
                            }
                            else
                            {
                                quitter = 0;
                            }
                        break;
                        case 2:
                            liste_emprunts();
                            printf(" \n \n \n ******************** 1 - Liste des retards \n");
                            printf(" \n ******************** 2 - Supprimer un emprunt \n");
                            printf(" \n ******************** 3 - Retour \n");
                            printf("\n \n  -------------->  Taper le numero de votre choiX \n \n");
                            scanf("%d",&option);
                            if (option == 1)
                            {
                                liste_retard_depot();
                                quitter = 0;
                            }
                            else if (option == 2)
                            {
                                supprimer_emprunter();
                                quitter = 0;
                            }
                            else if (option == 3)
                            {
                                quitter = 0;
                            }
                        break;
                        case 3:
                            liste_adherants();
                            quitter = 0;
                        break;
                        case 4:
                            main();
                        break;
                        default:
                            printf(" \n ERREUR DE SAISI VEUILLER RÉESSAYER ! \n");
                            quitter = 0;
                    }
                } while (quitter == 0);
    
            }
            else
            {
                printf("\tErreur, ces coordonnées ne figure pas dans notre base \n \n");
                printf("\n \n --------------> 1 - Pour réessayer \n");
                printf("\n --------------> 2 - Accueil \n");
                scanf("%d",&continuer);
                if (continuer == 2)
                {
                    main();
                }
                else
                {
                    continuer = 1;
                }
            }
        }while (continuer == 1);
    }
    else
    {
        printf("\n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }

    return 0;
}