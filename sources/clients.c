/**
 * @file client.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE(Kounapetri05@gmail.com) et ZOMADI MARCLEORD(zomadimarcleord@gmail.com)
 * @brief gestion des ajout et affiches des clients
 * @version 0.1
 * @date 2022-02-20 au 2022-03-14
 * 
 * @copyright Copyright (c) OKA && ZOMADI
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/gestion.h"
#include "../header/bibliotheque.h"
#include "../header/gestion.h"
#include "../header/lire.h"

/**
 * @brief Fonction qui permet d'ajouter un client (adherants)
 */
int ajout_adherants(){

    int main();
    int livres();
    int emprunter();
    char *lire(int size);

    int ajouter = 1,age,sexe=0;
    char *num_Adh,*nom, *prenoms,*contact, *residence, *continuer;
    MYSQL mysql;

    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        do
        {
            printf(" \n \n INSCRIPTION \n \n ");

            printf("\n Numero d'identifiant (nouveau) :  ");
            getchar();
            num_Adh = lire(31);
            printf(" Nom :  ");
            nom = lire(31);
            printf(" Prenoms :  ");
            prenoms = lire(101);
            printf(" Age :  ");
            scanf("%d",&age);
            printf(" Sexe :  \n Taper  1 - Homme           2 - Femme \n ");
            scanf("%d",&sexe);
            printf(" Contact :  ");
            getchar();
            contact=lire(31);
            printf(" residence :  ");
            residence = lire(31);

            char add[1000]; 
            //Copie de la requette dans la variables add
            sprintf(add, "INSERT INTO Adherents(num_Adh,nom,prenoms,age,contact,residence,sexe) VALUES ('%s','%s','%s','%d','%s','%s','%d')",num_Adh,nom,prenoms,age,contact,residence,sexe);
            
            if(!mysql_query(&mysql,add))
            {
                printf("\n ****************  Inscription valider, veuillez renseigner les information du livres a emprunter \n \n ");

                printf(" \n \n ****************  Votre NUMERO D'IDENTFIANT est le %s . \n  Garder le precieusement \n \n ",num_Adh);

                printf(" \n Taper un caractere puis Entrer pour continuer \n  ");
                continuer = lire(11);

                livres();
                emprunter();
                
            }
            else
            {
                printf(" \n \n Echec veuillez réessayer !!! \n ");
                ajouter=0;
            }
        } while (ajouter==0);
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
    return 0;
    
}

/**
 * @brief Fonction qui liste des clients (liste_adherants)
 */
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
        if(choix == 2)
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