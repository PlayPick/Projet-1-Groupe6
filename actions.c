#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "actions.h"

void afficher_file(File *file){
    if (file == NULL){
        exit(EXIT_FAILURE);
    }
    Element *element = file->premier;
    while (element != NULL){
        printf("\n %d ms ==> %d b/min", element->donnee.temps, element->donnee.frequence);
        element = element->suivant;
    }
}

void rech_temps(File *file){
    int tprech, t2, f2, varpoubelle=1;
    printf("\n Temps recherche (en ms): ");
    scanf("%d", &tprech);
    if (file == NULL){
        exit(EXIT_FAILURE);
    }
    Element *element = file->premier;
    while (element != NULL){
        if ((element->donnee.temps) == tprech){
            printf("\n %d ms ==> %d b/min\n", tprech, (element->donnee.frequence));
            varpoubelle=0;
        }
        element = element->suivant;
    }
    // Si le temps choisi n'existe pas, recherche les données pour le temps existant le plus proche
    if (varpoubelle){
        printf("\n Le temps recherche n'existe pas.\n Recherche du temps le plus proche en cours...\n");
        Element *element = file->premier;
        while (tprech > (element->donnee.temps)){
            t2 = (element->donnee.temps);
            f2 = (element->donnee.frequence);
            if(element->suivant == NULL){
                printf("\n Le temps le plus proche de votre recherche est: %d ms ==> %d b/min\n", t2, f2);
                system("pause");
            }
            element = element->suivant;
            
        }
        if ((tprech - t2) < ((element->donnee.temps) - tprech)){
            printf("\n Le temps le plus proche de votre recherche est: %d ms ==> %d b/min\n", t2, f2);
        }
        else{
            printf("\n Le temps le plus proche de votre recherche est: %d ms ==> %d b/min\n", (element->donnee.temps), (element->donnee.frequence));
        }
    }
}

void rech_pouls_max(File *file){
    int max=0;
    if (file == NULL){
        exit(EXIT_FAILURE);
    }
    Element *element = file->premier;
    while (element != NULL){
        if ((element->donnee.frequence) > max){
            max = (element->donnee.frequence);
        }
        element = element->suivant;
    }
    printf("\n La frequence de pouls maximum enregistree est: %d\n", max);
}

void rech_pouls_min(File *file){
    int min=9999999;
    if (file == NULL){
        exit(EXIT_FAILURE);
    }
    Element *element = file->premier;
    while (element != NULL){
        if ((element->donnee.frequence) < min){
            min = (element->donnee.frequence);
        }
        element = element->suivant;
    }
    printf("\n La frequence de pouls minimum enregistree est: %d\n", min);
}

void moy_pouls(File *file){
    int binf, bsup, plage=0, frequence_moyenne, somme_frequences=0;
    printf("\n Entrez les bornes superieure et inferieure de la plage de temps (en ms).");
    printf("\n Borne inferieure: ");
    scanf(" %d", &binf);
    printf("\n Borne superieure: ");
    scanf(" %d", &bsup);
    if (file == NULL){
        exit(EXIT_FAILURE);
    }
    Element *element = file->premier;
    while (element != NULL){
        if (((element->donnee.temps) > binf) && ((element->donnee.temps) < bsup)){
            somme_frequences = somme_frequences + (element->donnee.frequence);
            plage++;
        }
        element = element->suivant;
    }
    frequence_moyenne = somme_frequences/plage;
    printf("\n La frequence cardiaque moyenne entre %d ms et %d ms est environ %d b/min", binf, bsup, frequence_moyenne);
}