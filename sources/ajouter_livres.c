#include <stdio.h>
#include <string.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include <time.h>
#include "../header/gestion.h"

    
int ajouter_livres()
{

    int continuer;
    char ajouter;
    MYSQL mysql;

    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        do
        {

            int age,contact,date_par,nb_exem;
            char num_liv[30],titre[50],auteur[50],mot_cle[100];
            printf(" \n \n  ****** Veiller renseigner les informations du ou des livre(s) \n \n ");

            printf("    Numero :  ");
            scanf("%s",&num_liv);
            printf("    Titre :  ");
            scanf("%s",&titre);
            printf("\n  Auteur : ");
            scanf("%s",&auteur);
            printf("    Mots clé du livres :  ");
            scanf("%s",&mot_cle);
            printf("    Année de parution :  ");
            scanf("%d",&date_par);
            printf("    Nombre d'exemplaire :  ");
            scanf("%d",&nb_exem);

            char liv[1000];
            sprintf(liv,"INSERT INTO livres VALUES('%s','%s','%s','%s','%d','%d')",num_liv,titre,auteur,mot_cle,date_par,nb_exem);

            if(!mysql_query(&mysql,liv))
            {
                printf("Les livres ont été ajouter avec succes\n \n ");

                printf(" \ n Taper 1 pour Ajouter d'autre livres \n ");

                scanf("%s",&ajouter);
                if (ajouter=="1")
                {
                    ajouter = "0";
                }
                else
                {
                   gestion();
                }
                
            }
            else
            {
                printf("Echec veuillez ressayer");
                ajouter="0";
            }
        } while (ajouter=="0");

    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des livres \n \n ");
    }

    return 0;
}