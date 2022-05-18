/**
 * @file lire.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE(Kounapetri05@gmail.com) et ZOMADI MARCLEORD(zomadimarcleord@gmail.com)
 * @brief Gestion des livres
 * @version 0.1
 * @date 2022-02-20 au 2022-03-14
 * 
 * @copyright Copyright (c) DIÉKÉ JONATHAN
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Réccupère la chaine de caractères
 * 
 */

char *lire(int size){
    int i = 0;

    char* text = (char*) malloc(sizeof(char)*size);

    while(i < size){
        scanf("%c", &text[i]);
        if(text[i] == '\n') break ;
        else i++ ;
    }
    text[i] = '\0';
    return text ;
}