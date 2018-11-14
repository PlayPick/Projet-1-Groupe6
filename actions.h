/*
*   Cette bibliothèque contient les fonctions
*   pour exécuter l'action choisie par l'utilisateur
*   sur le menu.
*/

#include "donnees.h"

// Affiche à la suite les objets de la file
void afficher_file(File *file);

// Recherche et affiche les données pour un temps particulier
void rech_temps(File *file);

// Recherche et affiche la fréquence de pouls maximum enregistrée
void rech_pouls_max(File *file);

// Recherche et affiche la fréquence de pouls minimum enregistrée
void rech_pouls_min(File *file);

// Calcule la moyenne de pouls dans une plage de temps donnee
void moy_pouls(File *file);