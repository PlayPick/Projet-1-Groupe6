#include <Arduino.h>
#include "cardio.h"//inclus la bibliotheque cardio.h 

void setup() {
  Serial.begin(9600);//on initialise la console 
}


void loop() {//on entre dans la boucle 
  calculPouls();//appelle la fonction calculPouls 
}
