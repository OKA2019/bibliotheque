#include <stdio.h>
#include <string.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include <time.h>
//#include "../header/livres.h"

 struct livres{
    char num_liv[30];
    char titre[100];
    char auteur[30];
    char mot_cle[100];
    int date_par;
    int nb_exem ;
    };
    
int ajouter_lives()
{

    int continuer, ajouter = 1;

    struct livres liv1;

    MYSQL mysql;

    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        do
        {
            printf(" \n \n  ****** Veiller renseigner les informations du ou des livre(s) \n \n ");

            printf("Numero :  ");
            scanf("%s",&liv1.num_liv);
            printf("Titre :  ");
            gets(liv1.titre);
            printf("\n Auteur : %s \n ",liv1.titre);
            gets(liv1.auteur);
            printf("Mots clé du livres :  ");
            gets(liv1.mot_cle);
            printf("Année de parution :  ");
            scanf("%d",&liv1.date_par);
            printf("Nombre d'exemplaire :  ");
            scanf("%d",&liv1.nb_exem);

            
            if(mysql_query(&mysql,&liv1))
            {
                printf("Les livres ont été ajouter avec succes\n \n ");

                printf(" \ n Taper 1 pour Ajouter d'autre livres \n ");

                scanf("%d",&ajouter);
                if (ajouter!=1)
                {
                   gestion();
                }
                
            }
            else
            {
                printf("Echec veuillez ressayer");
                ajouter=0;
            }
        } while (ajouter==0);

    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des livres \n \n ");
    }

    return 0;
}