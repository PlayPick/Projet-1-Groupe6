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
    int tprech, t2, f2, v=1;
    printf("\n Temps recherche (en ms): ");
    scanf("%d", &tprech);
    if (file == NULL){
        exit(EXIT_FAILURE);
    }
    Element *element = file->premier;
    while (element != NULL){
        if ((element->donnee.temps) == tprech){
            printf("\n %d ms ==> %d b/min\n", tprech, (element->donnee.frequence));
            v=0;
        }
        element = element->suivant;
    }
    // Si le temps choisi n'existe pas, recherche les données pour le temps existant le plus proche
    if (v){
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

void tri_insertion(Ligne tab[], int taille){
   int i, j;
   for(i = 1; i < taille; ++i){
       Ligne elem = tab[i];
       for (j = i; j > 0 && (tab[j-1].frequence) > elem.frequence; j--){
           tab[j] = tab[j-1];
       }
       tab[j] = elem;
   }
}

void sort(File *file, int taille, int choixMenu21){
    Ligne tableau[taille];
    int i, k=0;

    if (file == NULL){
        exit(EXIT_FAILURE);
    }
    Element *element = file->premier;
    while (element != NULL){
        tableau[k] = element->donnee;
        element = element->suivant;
        k++;
    }
    
    tri_insertion(tableau, taille);
    
    switch(choixMenu21){
        case 1:
            for(i = 0; i < taille; i++){
                printf("\n %d ==> %d", tableau[i].frequence, tableau[i].temps);
            }
            printf("\n");
            break;
        case 2:
            for(i = taille-1; i >= 0; i--){
                printf("\n %d ==> %d", tableau[i].frequence, tableau[i].temps);
            }
            printf("\n");
            break;
        default:
            break;
    }
}

void renverse(File *file, int taille){
    Ligne tableau[taille];
    int i, k=0;

    if (file == NULL){
        exit(EXIT_FAILURE);
    }
    Element *element = file->premier;
    while (element != NULL){
        tableau[k] = element->donnee;
        element = element->suivant;
        k++;
    }
    for(i = taille-1; i >= 0; i--){
        printf("\n %d ==> %d", tableau[i].frequence, tableau[i].temps);
    }
    printf("\n");
}