#include <stdio.h>
#include <stdlib.h>


int menu(int i)
{
  //Ecrit une liste de choix dans la console
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("~~~~~~~~~~~Entrer 1 si vous voulez allumer toutes les leds~~~~~~~~~~~ \n");
  printf("Entrer 2 si vous voulez allumer 1 led sur 2 \n");
  printf("Entrer 3 si vous voulez allumer 1 led sur 3 \n");
  printf("Entrer 4 si vous voulez allumer les leds une par une \n");
  printf("Entrer 5 si vous voulez allumer les leds en chenillard \n");
  printf("Entrer 6 si vous voulez allumer les leds aleatoirement \n");
  printf("Entrer 7 pour choisir votre led \n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  //demande de rentrer une valeur correspondant à notre choix
  printf("Votre choix : ");
  scanf("%d", &i);
  printf("\n");

  //Si a est supérieur à 6 on redemande d'entrer une valeur
  while(i>7)
  {
    printf("Veuillez entrer un nombre valide\n");
    printf("Votre choix : ");
    scanf("%d", &i);
  }

  /*if(i==7)
  {
    menu2();
  }*/

  return i;
}


/*int menu2(int j)
{
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Entrer un nombre entre 2 et 12 correspondant aux pin de la led choisit\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Votre choix : ");
  scanf("%d", &j);
  printf("\n");


  while(j>12 || j<2)
  {
    printf("Veuillez entrer un nombre valide\n");
    printf("Votre choix : ");
    scanf("%d", &j);
    printf("\n");
  }

  return j;
}*/
