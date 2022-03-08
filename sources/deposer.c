#include <stdio.h>
#include <stdlib.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include  <time.h>
#include "../header/livres.h"
#include "../header/bibliotheque.h"

int deposer()
{
    // initialisation des fonctions
    int main();

    //variables
    int deposer =0;
    MYSQL mysql;

    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
            //Variables 
            int choix_liv,date_ret, compte,num_emp,statut=1;
            char bloquer,num_Adh[30],num_liv[30];

        do
        {
            time_t date_ret;
            char retour[1000];

            printf(" \n \n ------->   Enter votre Identifiant \n");
            scanf("%s",&num_Adh);

            printf(" \n \n  ------->  Veillez entrer le numero du livre  \n");
            scanf("%s",&num_liv);

            sprintf(retour,"UPDATE Emprunt SET date_ret='%d',statut='%d' WHERE num_Adh='%s' AND num_liv ='%s'",date_ret,statut,num_Adh,num_liv);

            if(!mysql_query(&mysql,retour))
            {
                printf(" \n \n Retour effacter avec succès \n \n ");

                printf("\n \n \n ------->  Voulez-vous effecter un autre depot ? \n \n   1 - OUI \n   2 - NON (retour au menu) \n \n");
                scanf("%d",&deposer);
                if(deposer == 1)
                {
                    deposer==1;
                }
                else
                {
                    //appel la fonction menu(des utilisateurs)
                    main();
                }
            }
            else
            {
                printf("\n \n Echec, vueiller réessayer ! \n \n ");
                deposer = 1;
            }

        }while (deposer!=1);
        
    }
    else
    {
        printf("Echec de connexion a la base ");
    }

    return 0;
}