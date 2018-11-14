#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int afficherMenu(int choixMenu){
    system("CLS");
    printf("\n=========================( MENU PRINCIPAL )=========================");
    printf("\n 0: Quitter");
    printf("\n 1: Afficher les donnees dans l'ordre enregistre");
    printf("\n 2: Ordonner en fonction du pouls/du temps");
    printf("\n 3: Rechercher les donnees pour un temps particulier");
    printf("\n 4: Afficher la moyenne de pouls dans une plage de temps donnee");
    printf("\n 5: Afficher le nombre de lignes actuellement en memoire");
    printf("\n 6: Rechercher le max/min de pouls");
    printf("\n====================================================================");
    printf("\n Votre choix: ");
    scanf("%d", &choixMenu);
return choixMenu;
}

int afficherMenu2(int choixMenu2){ 
    system("CLS"); 
    printf("\n=========================( 2/ ORDONNER )=========================");
    printf("\n 0: Quitter");
    printf("\n 1: Pouls");
    printf("\n 2: Temps");
    printf("\n=================================================================");
    printf("\n Votre choix: ");
    scanf("%d", &choixMenu2);
return choixMenu2;
}

int afficherMenu6(int choixMenu6){
    system("CLS");
    printf("\n=====================( 6/ RECHERCHER POULS )=====================");
    printf("\n 0: Quitter");
    printf("\n 1: Maximum");
    printf("\n 2: Minimum");
    printf("\n=================================================================");
    printf("\n Votre choix: ");
    scanf("%d", &choixMenu6);
return choixMenu6;
}

int afficherMenu21(int choixMenu21){
    system("CLS");
    printf("\n=====================( 2.1/ ORDONNER POULS )=====================");
    printf("\n 0: Quitter");
    printf("\n 1: Croissant");
    printf("\n 2: Decroissant");
    printf("\n=================================================================");
    printf("\n Votre choix: ");
    scanf("%d", &choixMenu21);
return choixMenu21;
}

int afficherMenu22(int choixMenu22){
    system("CLS");
    printf("\n=====================( 2.2/ ORDONNER TEMPS )=====================");
    printf("\n 0: Quitter");
    printf("\n 1: Croissant");
    printf("\n 2: Decroissant");
    printf("\n=================================================================");
    printf("\n Votre choix: ");
    scanf("%d", &choixMenu22);
return choixMenu22;
}
