#include <stdio.h>
#include <stdlib.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include <string.h>
#include  <time.h>
#include "../header/livres.h"
#include "../header/adherants.h"
#include "../header/bibliotheque.h"

int emprunter() {

    //Declarition des methodes
    void livres();
    int adherants();
    int ajouter=0;
    
    //Connexion a la base de données
    MYSQL mysql;
    //initialisation
    mysql_init(&mysql);
    
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
            //Variables 
            int choix_liv,date_ret = 0,nb_emprunt,date_sor, compte,num_emp,statut=0,choix;
            char bloquer,num_Adh[30],num_liv[30];

        printf("\n \n \n ------->  Avez vous un compte ? \n \n   1 - OUI \n   2 - NON \n   3 - RETOUR \n \n");
        scanf("%d",&choix);


        if(choix==1)
        {
            do
            {
                time_t date_lim;
                printf(" \n \n ------->   Enter votre Identifiant %d \n",date_lim);

                char emprunt[1000];
                char liv[1000]; //reçoit une requette qui diminue le nombre de libre 

                printf(" \n \n ------->   Enter votre Identifiant \n");
                scanf("%s",&num_Adh);

                printf(" \n \n  ------->  Veillez entrer le numero du livre  \n");
                scanf("%s",&num_liv);

                printf(" \n \n  ------->  Combien de jours va durée l'emprunt ? \n");
                scanf("%s",&nb_emprunt);
                nb_emprunt = nb_emprunt*86400;
                date_lim = date_sor + nb_emprunt;
                
                //char nb = "SELECT nb_exem FROM livres WHERE num_liv='%d'",num_liv;
                //int row = mysql_query(&mysql,nb);

                sprintf(emprunt,"INSERT INTO Emprunt(num_emp,date_sor,date_ret,date_lim,num_Adh,num_liv,statut) VALUES('%d','%d','%d','%d','%s','%s','%d')",num_emp,date_sor,date_ret,date_lim,num_Adh,num_liv,statut);
                //sprintf(liv,"UPDATE livres SET nb_exem ='%d' WHERE num_liv='%s'",row-1,num_liv);
                
                if(!mysql_query(&mysql,emprunt))
                {
                    /*if(mysql_query(&mysql,liv))
                    {
                        printf("\n on a bien fait la soustractions\n ");
                    }*/
                    printf(" \n \n -------> Emprunt effectuer avec succes <------- \n \n %s est la date limite de retour \n ------->  Taper une 1 puis la touche Enter pour continuer \n ",ctime(&date_lim));
                    
                    scanf("%s",&bloquer);
                    //Appel de la fonctions livres
                    livres();

                    printf("\n \n \n ------->  Voulez-vous emprunter un autre ? \n \n   1 - OUI \n   2 - NON (quitter la bibliotheque) \n \n");
                    scanf("%d",&ajouter);
                    if(ajouter!=1)
                    {
                        main();
                    }
                }
                else
                {
                    printf("\n \n Echec veuillez ressayer \n \n ");
                    ajouter=1;
                }
            } while (ajouter==1);
        }
        else if(choix==2)
        {
            //Appel de la fonction fonction inscription
            adherants();
        }
        else
        {
            main();
        }
        
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base \n \n ");
    }

}