#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

void afficher_file(File *file){

    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    Element *element = file->premier;
    // Tant que element représente quelque chose dans la file, on lit la donnee correspondante
    while (element != NULL){
        printf("\n %d ms ==> %d b/min", element->donnee.temps, element->donnee.frequence);
        // Envoie le pointeur vers element à l'élément suivant
        element = element->suivant;
    }
}

void rech_temps(File *file){
    // drapeau est une variable locale utilisée pour contrôler la focntion (à la manière d'un drapeau)
    // tprecedent et fprecedent sont utilisées pour stocker la donnée précédente de celle traitée sur le moment, pour faire un encadrement
    int trech, tprecedent, fprecedent, drapeau=1;
    // L'utilisateur rentre le temps recherché
    printf("\n Temps recherche (en ms): ");
    scanf("%d", &trech);

    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    Element *element = file->premier;
    // On parcourt la file jusqu'à trouver le temps recherché
    while (element != NULL){
        if ((element->donnee.temps) == trech){
            // Affichage du temps recherché et de la fréquence associée
            printf("\n %d ms ==> %d b/min\n", trech, (element->donnee.frequence));
            drapeau=0;
        }
        element = element->suivant;
    }

    // Si le temps recherché n'a pas été trouvé, on recherche les données pour le temps existant le plus proche
    if (drapeau){
        printf("\n Le temps recherche n'existe pas.\n Recherche du temps le plus proche en cours...\n");

        Element *element = file->premier;
        // On parcourt la file jusqu'à trouver le temps supérieur le plus proche
        while (trech > (element->donnee.temps)){
            tprecedent = (element->donnee.temps);
            fprecedent = (element->donnee.frequence);

            // Si on arrive à la fin de la file sans avoir trouvé de temps supérieur, alors la dernière valeur de la file est la plus proche du temps recherché
            if(element->suivant == NULL){
                printf("\n Le temps le plus proche de votre recherche est: %d ms ==> %d b/min\n", tprecedent, fprecedent);
                system("pause");
            }
            element = element->suivant;
        }

        // On calcule lequel du temps supérieur ou du temps inférieur est le plus proche du temps recherché
        if ((trech - tprecedent) < ((element->donnee.temps) - trech)){
            printf("\n Le temps le plus proche de votre recherche est: %d ms ==> %d b/min\n", tprecedent, fprecedent);
        }
        else{
            printf("\n Le temps le plus proche de votre recherche est: %d ms ==> %d b/min\n", (element->donnee.temps), (element->donnee.frequence));
        }
    }
}

void rech_pouls_max(File *file){
    // max sera utilisée pour stocker la valeur de pouls maximum trouvée
    int max=0;

    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    Element *element = file->premier;
    while (element != NULL){
        // Si on rencontre un pouls supérieur à max, alors ce dernier prend sa valeur.
        if ((element->donnee.frequence) > max){
            max = (element->donnee.frequence);
        }
        element = element->suivant;
    }
    printf("\n La frequence de pouls maximum enregistree est: %d\n", max);
}

void rech_pouls_min(File *file){
    // Basiquement l'inverse de la fonction rech_pouls_max.
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
    // Pour calculer la moyenne de pouls sur une plage de temps, on va faire la somme des pouls compris dans la plage de temps recherchée puis la diviser par le nombre de termes additionnés
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
        // On regarde si la valeur du temps de l'élément traité actuellement est comprise dans la plage de temps recherchée
        if (((element->donnee.temps) > binf) && ((element->donnee.temps) < bsup)){
            // On additionne la valeur du pouls associé avec la somme des autres pouls
            somme_frequences = somme_frequences + (element->donnee.frequence);
            plage++;
        }
        element = element->suivant;
    }

    frequence_moyenne = somme_frequences/plage;
    printf("\n La frequence cardiaque moyenne entre %d ms et %d ms est environ %d b/min", binf, bsup, frequence_moyenne);
}

void tri_insertion(Ligne tab[], int taille){
    // Cette fonction va trier un tableau de structures de type Ligne de taille "taille"
    int i, j;
    // La méthode de tri utilisée est le tri par insertion
    for(i = 1; i < taille+1; i++){
       Ligne elem = tab[i];
       for (j = i; j > 0 && (tab[j-1].frequence) > elem.frequence; j--){
           tab[j] = tab[j-1];
       }
       tab[j] = elem;
   }
}

void sort(File *file, int taille, int choixMenu21){
    // Cette fonction va trier la file dans l'ordre croissant (avec le tri par insertion) et l'afficher à l'endroit ou à l'envers
    Ligne tableau[taille];
    int i, k=0;

    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    Element *element = file->premier;
    // Entre dans un tableau de même taille que la file la donnée correspondante au numéro de case du tableau (qui est k)
    while (element != NULL){
        tableau[k] = element->donnee;
        element = element->suivant;
        k++;
    }
    
    // On trie le tableau obtenu
    tri_insertion(tableau, taille);
    
    // En fonction du choix du menu, on lit le tableau à l'endroit ou à l'envers. Lire le tableau à l'envers permet d'afficher
    // dans l'ordre décroissant sans pour autant trier de nouveau la liste.
    switch(choixMenu21){
        case 1:
            for(i = 1; i <= taille; i++){
                printf("\n %d ==> %d", tableau[i].frequence, tableau[i].temps);
            }
            break;
        case 2:
            for(i = taille; i >= 1; i--){
                printf("\n %d ==> %d", tableau[i].frequence, tableau[i].temps);
            }
            break;
        default:
            break;
    }
}

void renverse(File *file, int taille){
    // Cette fonction prends les valeurs d'une file, les introduit dans un tableau et lit le tableau à l'envers

    Ligne tableau[taille];
    int i, k=0;

    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    Element *element = file->premier;
    while (element != NULL){
        // Entre dans un tableau de même taille que la file la donnée correspondante au numéro de case du tableau (qui est k)
        tableau[k] = element->donnee;
        element = element->suivant;
        k++;
    }

    // Lit le tableau à l'envers
    for(i = taille; i >= 0; i--){
        printf("\n %d ==> %d", tableau[i].frequence, tableau[i].temps);
    }

    printf("\n");
}