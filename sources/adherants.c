#include <stdio.h>
#include <string.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/gestion.h"
#include "../header/bibliotheque.h"



int adherants(){

    int main();

    int ajouter = 1,age,contact,sexe=0;
    char num_Adh[30],nom[30],prenoms[50],residence[30],continuer[5];
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
            scanf("%s",&num_Adh);
            printf(" Nom :  ");
            scanf("%s",&nom);
            printf(" Prenoms :  ");
            scanf("%s",&prenoms);
            printf(" Age :  ");
            scanf("%d",&age);
            printf(" Sexe :  \n Taper  1 - Homme           2 - Femme \n ");
            scanf("%d",&sexe);
            printf(" Contact :  ");
            scanf("%d",&contact);
            printf(" residence :  ");
            scanf("%s",&residence);

            char add[1000]; 
            //Copie de la requette dans la variables add
            sprintf(add, "INSERT INTO Adherents(num_Adh,nom,prenoms,age,contact,residence,sexe) VALUES ('%s','%s','%s','%d','%d','%s','%d')",num_Adh,nom,prenoms,age,contact,residence,sexe);
            
            if(!mysql_query(&mysql,add))
            {
                printf("\n Inscription valider, veuillez renseigner les information du livres a emprunter \n \n ");

                printf(" \n \n Votre NUMERO D'IDENTFIANT est le %s . \n  Garder le precieusement \n \n ",num_Adh);

                printf(" \n Taper un caractere puis Entrer pour continuer \n  ");

                scanf("%c",&continuer);

                livres();
                
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
