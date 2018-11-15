#include "cardio.h"

 int valeurPrecedente = 0;
 long tempsPrecedent = 0;

void calculPouls(){

  int valeurActuelle, valeurSeuil;
  long tempsDetection;

  valeurActuelle = analogRead(0);
  valeurSeuil = 200;//valeur pour laquelle on definit qu'un battement a lieu 

  if (valeurActuelle > valeurSeuil) {//On teste si il y a un battement, donc si la valeur qu'on obtient avec le capteur depasse 200 
    if (valeurPrecedente <= valeurSeuil) {//on applique la fonction millis() a la variable tempsPrecedent
      tempsDetection = millis();
      if (tempsDetection > (tempsPrecedent + 200)){// on veut etre sur qu ce n'est pas que des interférences, donc si le signal est assez long, il entre dans le si
        long tempsEcoule = millis();//applique la fonction millis() a tempsEcoule pour avoir le chronometre depuis le lancement du programme
        Serial.print((1000.0 * 60.0) / (tempsDetection - tempsPrecedent) ,0);//on calcule avec les valeurs obtenues pour obtenir un pouls et on imprime le resultat en console 
        Serial.print(";");//separation pour le .csv
        Serial.println(tempsEcoule);//on imprime le temps ecoule depuis le debut du programme
        tempsPrecedent = tempsDetection;//on applique la valeur de tempsactuel a tempsprecedent pour dire qu'on ne se situe plus dans une pulsation
      }
    }
  }

  valeurPrecedente = valeurActuelle;//idem pour la valeur 
 
}
