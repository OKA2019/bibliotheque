#include <stdio.h>
#include <stdlib.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/gestion.h"
#include "../header/bibliotheque.h"

//#include "../header/livres.h"
    
void liste_adherants()
{

    //On efface l'écrans
    system("clear");
    
    int main();
    int gestion();

    int choix;

    printf("  \n \n ******************************** LISTE DES  ADRERANTS ******************************** \n \n ");

    MYSQL mysql;

    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {

        //Requête qui sélectionne tout dans ma table scores
        mysql_query(&mysql, "SELECT * FROM Adherents");
        //Déclaration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;

        result = mysql_use_result(&mysql);
        
        //Tant qu'il y a encore un résultat ...
        while ((row = mysql_fetch_row(result)))
        {
            printf(" \n \n Matricule %s ", row[0]);
            printf(" \n Nom : %s", row[1]);
            printf(" \n Prenoms : %s", row[2]);
            if(row[6]==0)
            {
                printf(" \n Sexe :  Femme ");
            }
            else
            {
                printf(" \n Sexe :  Homme ");
            }
            printf(" \n Age : %s", row[3]);
            printf(" \n Contact : %s ", row[4]);
            printf(" \n Residence:  %s ", row[5]);
        }

        //Libération du jeu de résultat
        mysql_free_result(result);

        //Fermeture de MySQL
        mysql_close(&mysql);


        printf("\n \n \n ------->  Voulez-vous revenir au menu gestionnaire ? \n \n   1 - OUI \n   2 - NON (retour au menu principal) \n \n");
        scanf("%d",&choix);
        if(choix == 1)
        {
            //appel la fonction menu(des utilisateurs)
            gestion();
        }
        else
        {
            //appel la fonction main(des utilisateurs)
            main();
        }
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau des livres \n \n ");
    }

}