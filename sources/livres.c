/**
 * @file livres.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE(Kounapetri05@gmail.com) et ZOMADI MARCLEORD(zomadimarcleord@gmail.com)
 * @brief Gestion des livres
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
#include "../header/gestion.h"
#include "../header/lire.h"

/**
 * @brief Fonction qui permet de liste des livres
 * 
 */
int livres()
{
    system("clear");

    int gestion();
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        printf("  \n \n ******************************** LIVRES DE LA BIBLIOTHÈQUE ******************************** \n \n ");
        mysql_query(&mysql, "SELECT * FROM livres ");
        //Déclaration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;
        
        result = mysql_use_result(&mysql);
        
        while ((row = mysql_fetch_row(result)))
        {
            printf(" \n Numero %s", row[0]);
            printf(" \n Titre %s", row[1]);
            printf(" \n Auteur : %s", row[2]);
            printf(" \n Mots cles : %s", row[3]);
            printf(" \n Date de parution : %s ", row[4]);
            printf(" \n Nombre d'exemplaire :  %s \n", row[5]);
        }
        mysql_close(&mysql);
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau des livres \n \n ");
    }
    return (0);
}

/**
 * @brief Fonction qui permet d'ajouter un livre
 * 
 */
int ajouter_livres()
{

    int gestion();
    char *lire(int size);

    int continuer;
    int ajouter;

    //initialisation 
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        do
        {

            int age,contact,date_par,nb_exem;
            char *num_liv,*titre, *auteur, *mot_cle;
            printf(" \n \n  ****** Veuiller renseigné les informations du ou des livre(s) \n \n ");

            printf("    Numero :  ");
            getchar();
            num_liv = lire(31);
            printf("    Titre :  ");
            titre = lire(101);
            printf("\n  Auteur : ");
            auteur = lire(101);
            printf("    Mots clé du livres :  ");
            mot_cle = lire(101);
            printf("    Année de parution :  ");
            scanf("%d",&date_par);
            printf("    Nombre d'exemplaire :  ");
            scanf("%d",&nb_exem);

            char liv[1000];
            sprintf(liv,"INSERT INTO livres VALUES('%s','%s','%s','%s','%d','%d')",num_liv,titre,auteur,mot_cle,date_par,nb_exem);
            if(!mysql_query(&mysql,liv))
            {
                printf("\n **************** Les livres ont été ajouter avec succes  **************** \n \n ");

                printf("\n \n \n ------->  Taper  1 - Ajouter d'autre livres \n ------->  2 - Pour revenir en arrière \n \n");
                scanf("%d",&ajouter);
                if (ajouter == 1)
                {
                    ajouter = 0;
                }
                else
                {
                    mysql_close(&mysql);
                }
            }
            else
            {
                printf("\n  **************** Echec veuillez ressayer  **************** ");
                printf("\n \n \n ------->  Taper  1 - Pour réessayer \n ------->  2 - Pour revenir en arrière \n \n");
                scanf("%d",&ajouter);
                if (ajouter == 1)
                {
                    ajouter = 0;
                }
                else
                {
                    mysql_close(&mysql);
                }
            }
        } while (ajouter==0);
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des livres \n \n ");
    }
    return (0);
}

/**
 * @brief Fonction qui permet de modifier les informlations d'un livre 
 * 
 */
int modifier_livres()
{
    int gestion();
    char *lire(int size);

    int modifier;

    //initialisation
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        do
        {
            int age,contact,date_par,nb_exem;
            char *num_liv,*titre, *auteur, *mot_cle;
            printf(" \n \n **************** Veuiller renseigner les informations du livres à modifier \n \n ");

            printf("    Numero :  ");
            getchar();
            num_liv = lire(31);
            printf("    Titre :  ");
            titre = lire(101);
            printf("\n  Auteur : ");
            auteur = lire(101);
            printf("    Mots clé du livres :  ");
            mot_cle = lire(101);
            printf("    Année de parution :  ");
            scanf("%d",&date_par);
            printf("    Nombre d'exemplaire :  ");
            scanf("%d",&nb_exem);

            char liv[1000];
            sprintf(liv,"UPDATE livres SET titre = '%s', auteur= '%s', mot_cle = '%s', date_par = '%d', nb_exem = '%d' WHERE num_liv = '%s' ", titre, auteur, mot_cle, date_par, nb_exem, num_liv);
            if(!mysql_query(&mysql,liv))
            {
                printf("\n \n ****************  Les livres ont été modifier avec succes  **************** \n ");

                printf("\n ------->  Taper  1 - Pour modifier un autre livre \n ------->  2 - Pour revenir en arrière \n \n");
                scanf("%d",&modifier);
                if (modifier==1)
                {
                    modifier = 0;
                }
                else
                {
                    mysql_close(&mysql);
                }
            }
            else
            {
                printf("\n \n **************** Echec veuillez ressayer **************** ");
                printf("\n \n ------->  Taper  1 - Pour réessayer \n ------->  2 - Pour revenir en arrière \n \n");
                scanf("%d",&modifier);
                if (modifier==1)
                {
                    modifier = 0;
                }
                else
                {
                    mysql_close(&mysql);
                    gestion();
                }
            }
        } while (modifier==0);
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des livres \n \n ");
    }
    return (0);
}

/**
 * @brief Fonction qui permet de suppression de livres
 * 
 */
int supprimer_livres()
{
    int gestion();
    char *lire(int size);

    int supprimer;

    //initialisation
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        do
        {
            char *num_liv;
            printf(" \n \n **************** Veuiller renseigner les informations du ou des livre(s) \n \n ");

            printf("    Numero du livre à supprimer :  ");
            getchar();
            num_liv = lire(31);

            char liv[1000];
            sprintf(liv,"DELETE FROM livres WHERE num_liv ='%s'",num_liv);
            printf("%s \n ",liv);
            if(!mysql_query(&mysql,liv))
            {
                printf(" \n  **************** Les livres ont été supprimés avec succes  **************** \n \n ");

                printf("\n \n \n ------->  Taper  1 - Pour supprimer d'autre livres \n ------->  2 - Pour revenir en arrière \n \n");
                scanf("%d",&supprimer);
                if (supprimer==1)
                {
                    supprimer = 0;
                }
                else
                {
                    //Fermeture de MySQL
                    mysql_close(&mysql);
                    gestion();
                }
            }
            else
            {
                printf("  \n \n  ****************  Echec veuillez ressayer  ****************   ");
                printf("\n \n ------->  Taper  1 - Pour réessayer \n ------->  2 - Pour revenir en arrière \n \n");
                scanf("%d",&supprimer);
                if (supprimer==1)
                {
                    supprimer = 0;
                }
                else
                {
                    mysql_close(&mysql);
                }
            }
        } while (supprimer==0);
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des livres \n \n ");
    }
    return (0);
}
