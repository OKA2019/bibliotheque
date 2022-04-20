#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <time.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/livres.h"
#include "../header/clients.h"
#include "../header/bibliotheque.h"
#include "../header/gestion.h"
#include "../header/lire.h"

//Fonction d'emporunt de livres
int emprunter() {

    //Declarition des methodes
    void livres();
    char *lire(int size);
    int ajout_adherants();

    int ajouter=0;
    
    //Connexion a la base de données
    MYSQL mysql;
    //initialisation
    mysql_init(&mysql);
    
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        //Variables 
        int choix_liv,date_lim, date_ret = 0, nb_emprunt,date_sor, compte,num_emp = 0,statut=0,choix;
        char bloquer, *num_Adh, *num_liv;

        printf("\n \n \n ------->  Avez vous un compte ? \n \n   1 - OUI \n   2 - NON \n   3 - RETOUR \n \n");
        scanf("%d",&choix);

        if(choix==1)
        {
            do
            {
                char emprunt[1000];
                char liv[1000]; //reçoit une requette qui diminue le nombre de libre 

                printf(" \n \n ------->   Enter votre Identifiant \n");
                getchar();
                num_Adh = lire(31);
                printf(" \n \n  ------->  Veillez entrer le numero du livre  \n");
                num_liv = lire(31);
                printf(" \n \n  ------->  Combien de jours va durée l'emprunt ? \n");
                scanf("%d",&nb_emprunt);

                time_t date_sorti;
                time(&date_sorti);
                nb_emprunt = nb_emprunt * 86400;
                date_lim = date_sorti + nb_emprunt;
                
                sprintf(emprunt,"INSERT INTO Emprunt(num_emp,date_sor,date_ret,date_lim,iden_Adh,iden_liv,statut) VALUES('%d','%d','%d','%d','%s','%s','%d')",num_emp,abs(date_sorti),date_ret,abs(date_lim),num_Adh,num_liv,statut);
                printf(" \n \n %s ", emprunter);
                if(!mysql_query(&mysql,emprunt))
                {
                    printf(" \n \n -------> Emprunt effectuer avec succes <------- \n \n %s est la date limite de retour \n ------->  Taper un caractère puis la touche Enter pour continuer \n ",ctime(abs(date_lim)));
                    scanf("%s",&bloquer);
                    //Appel de la fonctions livres
                    livres();

                    printf("\n \n \n ------->  Voulez-vous emprunter un autre ? \n \n   1 - OUI \n   2 - NON (quitter la bibliotheque) \n \n");
                    scanf("%d",&ajouter);
                    if(ajouter!=1)
                    {
                        livres();
                        emprunter();
                    }
                }
                else
                {
                    printf("\n \n -------> Echec veuillez ressayer en tapant 1 <-------                                 \n \n ");
                    scanf("%d",&ajouter);
                    if(ajouter != 1)
                    {
                        livres();
                        emprunter();
                    }
                }
            } while (ajouter==1);
        }
        else if(choix==2)
        {
            ajout_adherants();
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

    return (0);
}

//Fonction de depot de livres
int deposer()
{
    // initialisation des fonctions
    int main();
    char *lire(int size);

    //variables
    int deposer =0;

    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
{
        //Variables 
        int choix_liv,date_ret, compte,num_emp,statut=1;
        char bloquer, *num_Adh, *num_liv;

        do
        {
            time_t date_ret;
            time(&date_ret);
            char retour[1000];

            printf(" \n \n ------->   Enter votre Identifiant \n");
            getchar();
            num_Adh = lire(31);

            printf(" \n \n  ------->  Veillez entrer le numero du livre  \n");
            num_liv = lire(31);

            sprintf(retour,"UPDATE Emprunt SET date_ret='%d',statut='%d' WHERE num_Adh='%s' AND num_liv ='%s'", abs(date_ret),statut,num_Adh,num_liv);

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
                    livres();
                    emprunter();
                }
            }
            else
            {
                printf("\n \n Echec, vueiller réessayer ! \n \n ");                
                printf("\n \n \n ------->  Taper 1 - Pour réessayer \n   2 - Pour revenir au menu \n \n");
                scanf("%d",&deposer);
                if(deposer == 1)
                {
                    deposer==1;
                }
                else
                {
                    main();
                }
            }

        }while (deposer!=1);
        
    }
    else
    {
        printf("Echec de connexion a la base ");
    }

    return 0;
}

//Liste des e;prunts
void liste_emprunts()
{
    //On efface l'écrans
    system("clear");

    int main();
    int gestion();

    int choix;

    printf("  \n \n ******************************** LISTE DES  EMPRUNTS ******************************** \n \n ");

    MYSQL mysql;
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
        mysql_close(&mysql);
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau des livres \n \n ");
    }

}

//Liste des retards de depot de livres
void liste_retard_depot()
{
    //On efface l'écrans
    system("clear");

    int main();
    int gestion();

    int choix;

    printf("  \n \n ******************************** LISTE DES RETARDATAIRES DE DEPOTS DE LIVRES ******************************** \n \n ");

    MYSQL mysql;

    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        int aujour;
        time_t Ajou;
        //time(&Ajou);
        aujour = Ajou;
        char retard[1000];
        //Requête qui sélectionne tout dans ma table scores
        sprintf(retard, "SELECT nom,prenoms,contact,residence,titre,auteur, from_unixtime(date_sor), from_unixtime(date_lim) FROM Adherents,livres,Emprunt WHERE num_Adh = iden_Adh AND num_liv = iden_liv AND statut=0 AND date_lim < %d ",atoi(aujour));
        mysql_query(&mysql, retard);
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
        mysql_close(&mysql);

        printf("\n \n \n ------->  Voulez-vous revenir au menu gestionnaire ? \n \n   1 - OUI \n   2 - NON (retour au menu) \n \n");
        scanf("%d",&choix);
        if(choix == 1)
        {
            gestion();
        }
        else
        {
            main();
        }
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau des livres \n \n ");
    }

}

//Fonction d'emporunt de livres
int supprimer_emprunter() {
    
    int gestion();
    char *lire(int size);

    int supprimer = 0;
    
    //Connexion a la base de données
    MYSQL mysql;
    //initialisation
    mysql_init(&mysql);
    
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","bibliotheque",0,NULL,0))
    {
        //Variables 
        char *num_Adh, *num_liv;
 
        do
        {
            char emprunt[1000];
            char liv[1000]; //reçoit une requette qui diminue le nombre de libre 

            printf(" \n \n ------->   Enter votre Identifiant \n");
            getchar();
            num_Adh = lire(31);
            printf(" \n \n  ------->  Veillez entrer le numero du livre  \n");
            num_liv = lire(31);

            sprintf(emprunt,"DELETE FROM Emprunt WHERE iden_Adh = '%s' AND iden_liv = '%s' AND statut= '0'", num_Adh, num_liv);
            if(!mysql_query(&mysql,emprunt))
            {
                printf(" \n \n -------> Emprunt a été supprimer avec succes <------- ");
                printf("\n \n \n ------->  Voulez-vous supprimer un autre ? \n \n   1 - OUI \n   2 - NON (quitter la bibliotheque) \n \n");
                scanf("%d",&supprimer);
                if(supprimer != 1)
                {
                    gestion();
                }
            }
            else
            {
                printf("\n \n -------> Echec veuillez ressayer en tapant 1  <------- \n \n ");
                scanf("%d",&supprimer);
                if(supprimer != 1)
                {
                    gestion();
                }
            }
        } while (supprimer==1);
    }
    else
    {
        printf(" \n \n Erreur de connexion a la base \n \n ");
    }
    return (0);
}
