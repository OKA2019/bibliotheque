#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/gestion.h"
#include "../header/bibliotheque.h"

//#include "../header/livres.h"
    
void liste_emprunts()
{
    //On efface l'écrans
    system("clear");

    int main();
    int gestion();

    int choix;

    printf("  \n \n ******************************** LISTE DES  EMPRUNTS ******************************** \n \n ");

    MYSQL mysql;

    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        //Requête qui sélectionne tout dans ma table scores
        mysql_query(&mysql, "SELECT nom,prenoms,contact,residence,titre,auteur, from_unixtime(date_sor), from_unixtime(date_lim) FROM Adherents,livres,Emprunt WHERE num_Adh = iden_Adh AND num_liv = iden_liv AND statut=0 ");
        //Déclaration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW resul;
        int i = 1;
        
        result = mysql_use_result(&mysql);
        
        //Tant qu'il y a encore un résultat ...
        char numero[4] = "N°";
        char noms[35] = "Nom et prenoms";
        char Contacts[10] = "Contacts";
        char Residence[12] = "Residence";
        char Titre[15] = "Titre";
        char Auteur[12] = "Auteur";
        char sortie[18] = "Date de sortie";
        char limite[18] = "Date limite";

        printf(" \n \n |  %4s | %35s | %12s | %12s | %15s | %15s | %19s | %19s | \n  ", numero,noms,Contacts,Residence,Titre,Auteur,sortie,limite);
        while ((resul = mysql_fetch_row(result)))
        {
            printf(" \n \n | %4d | %10s %24s | %12s | %12s | %15s | %15s | %18s | %18s | \n  ",i,resul[0],resul[1],resul[2],resul[3],resul[4],resul[5],resul[6],resul[7]);
            i++;
        }

        //Libération du jeu de résultat
        mysql_free_result(result);

        //Fermeture de MySQL
        mysql_close(&mysql);


        printf("\n \n \n ------->  Voulez-vous revenir au menu gestionnaire ? \n \n   1 - OUI \n   2 - NON (retour au menu) \n \n");
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