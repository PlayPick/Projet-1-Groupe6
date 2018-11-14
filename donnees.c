#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"


File *initialiser_file(){
    File *file = malloc(sizeof(*file));
    file->premier = NULL;
    return file;
}

void file_ajout(File *file, Ligne nvdonnee){
    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }
    nouveau->donnee = nvdonnee;
    nouveau->suivant = NULL;
    if (file->premier != NULL){
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL){
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else{
        file->premier = nouveau;
    }
}

Ligne file_retrait(File *file){
    if (file == NULL){
        exit(EXIT_FAILURE);
    }
    Ligne nombreDefile = {0, 0};
    if (file->premier != NULL){
        Element *elementDefile = file->premier;
        nombreDefile = elementDefile->donnee;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }
    return nombreDefile;
}

void file_clear(File *file){
    Element *element = file->premier;
    while (element != NULL){
        file_retrait(file);
    }
}

int lecture(File *file, int taille){
    int c;
    FILE* csv = NULL;
    csv = fopen("fichier.txt", "r");
    if(csv != NULL){
        while((c=fgetc(csv)) != EOF){
            Ligne donnee;
            fscanf(csv, "%d;%d", &(donnee.frequence), &(donnee.temps));
            //printf("\n %d %d", donnee);
            file_ajout(file, donnee);
            taille++;
        }
        printf("\n");
        fclose(csv);
    }
    return taille;
}