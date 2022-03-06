#include <stdio.h>
#include <string.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/livres.h"
#include "../header/emprunter.h"
#include "../header/bibliotheque.h"



int adherants(){

    void livres();
    int emprunter();

    int continuer, ajouter = 1,age,contact;
    char num_Adh[30],nom[30],prenoms[50],residence[30];
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
            printf(" Contact :  ");
            scanf("%d",&contact);
            printf(" residence :  ");
            scanf("%s",&residence);

            char add[1000]; 
            //Copie de la requette dans la variables add
            sprintf(add, "INSERT INTO Adherents(num_Adh,nom,prenoms,age,contact,residence) VALUES ('%s','%s','%s','%d','%d','%s')",num_Adh,nom,prenoms,age,contact,residence);
            
            if(!mysql_query(&mysql,add))
            {
                printf("\n Inscription valider, veuillez renseigner les information du livres a emprunter \n \n ");

                printf(" \n \n Votre NUMERO D'IDENTFIANT est le %s . \n  Garder le precieusement \n \n ",num_Adh);

                main();
                
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
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
    return 0;
    
}
