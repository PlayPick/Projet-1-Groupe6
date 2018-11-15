#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"


File *initialiser_file(){
    // Alloue de la place en mémoire pour le pointeur de la file
    File *file = malloc(sizeof(*file));
    // Donne la valeur NULL au pointeur pointant vers le premier élément de la file
    file->premier = NULL;
    return file;
}

void file_ajout(File *file, Ligne nvdonnee){

    // Alloue de la place en mémoire pour le nouvel élément qui va être ajouté à la file
    Element *nouveau = malloc(sizeof(*nouveau));
    // Teste si la file existe
    if (file == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }

    // Entre la donnée à ajouter dans l'élément "nouveau", et fait pointer son pointeur vers le suivant vers NULL
    nouveau->donnee = nvdonnee;
    nouveau->suivant = NULL;

    // Si le premier élément de la file n'est pas vide, on parcourt la file jusqu'à trouver le dernier élément (celui dont le pointeur vers suivant pointe sur NULL)
    if (file->premier != NULL){
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL){
            // On passe à l'élément suivant
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    // Sinon, la file est vide donc on a juste à rentrer la valeur que l'on veut ajouter dans le premier élément
    else{
        file->premier = nouveau;
    }
}

Ligne file_retrait(File *file){

    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    // Déclare un objet de type Ligne qui sera la donnée que l'on va retirer de la file
    Ligne nombreRetire;
    // Regarde si le premier élément de la file existe (s'il n'existe pas ça ne sert à rien de le retirer)
    if (file->premier != NULL){
        // Dédlare un pointeur vers le premier élément de la file
        Element *elementRetire = file->premier;
        // nombreRetire prend la valeur du premier élément de la file
        nombreRetire = elementRetire->donnee;
        // Fait pointer le pointeur vers le premier élément de la file vers le deuxième
        file->premier = elementRetire->suivant;
        // Libère la mémoire allouée à elementRetire
        free(elementRetire);
    }
    return nombreRetire;
}

void file_clear(File *file){
    
    // On retire le premier élément de la file jusqu'à ce que le pointeur vers le premier element de la file soit NULL
    Element *element = file->premier;
    while (element != NULL){
        file_retrait(file);
    }
}

int lecture(File *file, int taille){
    int c;
    FILE* csv = NULL;
    // Ouvre le fichier "battements.csv" enregistré dans le même dossier que le .exe en lecture seule.
    csv = fopen("battementscsv/battements.csv", "r");

    if(csv != NULL){
        // On parcourt l'ensemble du fichier jusqu'au dernier caractère (EOF = End Of File)
        while((c=fgetc(csv)) != EOF){
            // On initialise une donnee de type Ligne et on lui donne les valeurs lues sur la ligne correspondante du csv
            Ligne donnee;
            fscanf(csv, "%d;%d", &(donnee.frequence), &(donnee.temps));
            // On ajoute la donnee lue à la file
            file_ajout(file, donnee);
            taille++;
        }

        // Enlève la première valeur enregistrée car elle est source d'erreurs
        file_retrait(file);
        printf("\n");
        // Ferme le fichier csv
        fclose(csv);
    }
    return taille-1;
}