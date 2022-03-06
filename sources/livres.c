#include <stdio.h>
#include <stdlib.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"

//#include "../header/livres.h"
    
int livres()
{



    printf("  \n \n ******************************** NOS LIVRES ******************************** \n \n ");

    MYSQL mysql;

    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        //Requête qui sélectionne tout dans ma table scores
        mysql_query(&mysql, "SELECT * FROM livres ");
        //Déclaration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;
        
        result = mysql_use_result(&mysql);
        
        //Tant qu'il y a encore un résultat ...
        while ((row = mysql_fetch_row(result)))
        {
            printf(" \n \n Numero %s", row[0]);
            printf(" \n Titre %s", row[1]);
            printf(" \n Auteur : %s", row[2]);
            printf(" \n Mots cles : %s", row[3]);
            printf(" \n Date de parution : %d ", row[4]);
            printf(" \n Nombre d'exemplaire :  %d ", row[5]);
        }
        //Libération du jeu de résultat
        mysql_free_result(result);

        //Fermeture de MySQL
        mysql_close(&mysql);
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau des livres \n \n ");
    }

    return 0;
}