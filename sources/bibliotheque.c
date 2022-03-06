#include <stdio.h>
#include <stdlib.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/livres.h"
#include "../header/adherants.h"
#include "../header/emprunter.h"
#include "../header/deposer.h"


int main()
{
    //Appel initialisations des differents fonctions
    int adherants();
    int emprunter();
    void livres();
    int deposer();

    //Variables 
    int choix;
    


    printf("  \n \n ******************************** BIENVENU DANS LA BIBLIOTHEQUE NUMERIQUE DE LA SIGL ******************************** \n \n ");


    printf(" \n ------->  1 - Livres ");
    printf(" \n ------->  2 - Emprunter ");
    printf(" \n ------->  3 - Deposer");
    printf(" \n ------->  4 - Inscription");
    printf(" \n ------->  5 - Quitter \n");
    printf("\n \n  ------->  Taper le numero de votre choiX \n \n");
    scanf("%d",&choix);
    
    switch(choix)
    {
        case 1 :
            livres();
            emprunter();
        case 2 :
            emprunter();
        case 3 :
            deposer();
        case 4 :
            adherants();
        default :
            printf(" \n Merci d'être venu, a la prochaine ");
    }

    return 0;
}