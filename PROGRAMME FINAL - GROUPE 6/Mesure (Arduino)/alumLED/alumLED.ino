#include <Arduino.h>
#include "coeur.h"
#include "param.h"
#include "cardio.h"

void setup()
{
  Serial.begin(9600);//initialise la console 
  mode();//appelle la fonction mode

}


void loop()//on entre dans la boucle
{
  //appel des fonction celon le menu choisit
  if(a==1)
  {
    calculPouls();//insere la fonction calculPouls() pour recuperer les données des capteurs 
    allumage1();
  }
  else if(a==2)
  {
    calculPouls();
    allumage2();
  }
   else if(a==3)
  {
    calculPouls();
    allumage3();
  }
   else if(a==4)
  {
    calculPouls();
    allumagechenille();
  }
  else if(a==5)
 {
   calculPouls();
   allumage5();
 }
   else if(a==6)
 {
   calculPouls();
   allumage6();
 }
 else if(a==7)
{
 calculPouls();
 allumage7();
}
}
