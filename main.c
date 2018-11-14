#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "actions.h"



int main(int argc, char *argv[]){
    int taille=0;
    File *filecsv = initialiser_file();
    Ligne donnee;
    taille=lecture(filecsv, taille);
    int choixMenu, choixMenu2, choixMenu6, choixMenu21, choixMenu22;
    choixMenu = afficherMenu(choixMenu);
    // Choisit l'action à faire en fonction du choix de l'utilisateur dans le menu précédent
    switch(choixMenu){
        case 1:
            afficher_file(filecsv);
            break;
        case 2:
            choixMenu2 = afficherMenu2(choixMenu2);
            switch(choixMenu2){
                case 1:
                    choixMenu21 = afficherMenu21(choixMenu21);
                    sort(filecsv, taille, choixMenu21);
                    break;
                case 2:
                    choixMenu22 = afficherMenu22(choixMenu22);
                    switch(choixMenu22){
                        case 1:
                            afficher_file(filecsv);
                            break;
                        case 2:
                            renverse(filecsv, taille);
                            break;
                        default:
                            return 0;
                            break;
                        }
                    break;
                default:
                    return 0;
                    break;
            }
            break;
        case 3:
            rech_temps(filecsv);
            break;
        case 4:
            moy_pouls(filecsv);
            break;
        case 5:
            printf("\n Il y  actuellement (%d) lignes en memoire.\n", taille);
            break;
        case 6:
            choixMenu6 = afficherMenu6(choixMenu6);
            switch(choixMenu6){
                case 1:
                    rech_pouls_max(filecsv);
                    break;
                case 2:
                    rech_pouls_min(filecsv);
                    break;
                default:
                    return 0;
                    break;
            }
            break;
        default:
            return 0;
            break;
    }
    printf("\n");
    system("pause");
   
return 0;
}