#include <Arduino.h>
#include "coeur.h"
#include "cardio.h"

//définit les pin des leds
int L1 = 2;
int L2 = 3;
int L3 = 4;
int L4 = 5;
int L5 = 6;
int L6 = 7;
int L7 = 8;
int L8 = 9;
int L9 = 10;
int L10 = 11;
int L11 = 12;
int L=2;

int etat = analogRead(0);//on lit l'etat de la LED au pin analogique A0

void mode(){
  pinMode(L1, OUTPUT);//definit les LED en sortie 
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
  pinMode(L8, OUTPUT);
  pinMode(L9, OUTPUT);
  pinMode(L10, OUTPUT);
  pinMode(L11, OUTPUT);
}

void allumage1()
{
  int valeurActuelle = analogRead(0);//applique a la variable valeurActuelle l'etat de la LED en A0
  if (valeurActuelle != 0 && valeurActuelle > 200){//Si notre valeur est superieure au seuil on allume les LED 
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, HIGH);
  digitalWrite(L5, HIGH);
  digitalWrite(L6, HIGH);
  digitalWrite(L7, HIGH);
  digitalWrite(L8, HIGH);
  digitalWrite(L9, HIGH);
  digitalWrite(L10, HIGH);
  }
else{//sinon on les laisse eteintes 
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);
  digitalWrite(L10, LOW);

}
}

void allumage2()//idem 
{
  int valeurActuelle = analogRead(0);
  if (valeurActuelle != 0 && valeurActuelle > 200){
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, LOW);
  digitalWrite(L5, HIGH);
  digitalWrite(L6, LOW);
  digitalWrite(L7, HIGH);
  digitalWrite(L8, LOW);
  digitalWrite(L9, HIGH);
  digitalWrite(L10, LOW);
  }
else{
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);
  digitalWrite(L10, LOW);
}
}


void allumage3()//idem
{
  int valeurActuelle = analogRead(0);
  if (valeurActuelle != 0 && valeurActuelle > 200){
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, HIGH);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, HIGH);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);
  digitalWrite(L10, HIGH);
  }
else{
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);
  digitalWrite(L10, LOW);
}
}


void allumagechenille()//idem
{
 int valeurActuelle = analogRead(0);
  if(valeurActuelle >200)
  {
    digitalWrite(L, HIGH);//on allume une led puis on l'eteint, et on rajoute 1 a L pour faire allumer la LED suivante ensuite 
    delay(80);
    digitalWrite(L , LOW);
    delay(500);

    L=L+1;

    if(L==12)
    {
      L=2;//si on arrive a la derniere LED, on rallume la premiere LED, donc celle sur le pin 2
    }

  }

}

void allumage5()//idem allumage 3
{
  int valeurActuelle = analogRead(0);
  if (valeurActuelle != 0 && valeurActuelle > 200)
  {
    digitalWrite(L1, HIGH);
    delay(15);
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
    delay(15);
    digitalWrite(L2, LOW);
    digitalWrite(L3, HIGH);
    delay(15);
    digitalWrite(L3, LOW);
    digitalWrite(L4, HIGH);
    delay(15);
    digitalWrite(L4, LOW);
    digitalWrite(L5, HIGH);
    delay(15);
    digitalWrite(L5, LOW);
    digitalWrite(L6, HIGH);
    delay(15);
    digitalWrite(L6, LOW);
    digitalWrite(L7, HIGH);
    delay(15);
    digitalWrite(L7, LOW);
    digitalWrite(L8, HIGH);
    delay(15);
    digitalWrite(L8, LOW);
    digitalWrite(L9, HIGH);
    delay(15);
    digitalWrite(L9, LOW);
    digitalWrite(L10, HIGH);
    delay(15);
    digitalWrite(L10, LOW);
    delay(15);
  }
}

void allumage6()//On allume de facon aleatoire une led dans le coeur 
{
  int valeurActuelle = analogRead(0);
  if (valeurActuelle != 0 && valeurActuelle > 200)
    {
      int I = random(2,12);
      digitalWrite(I,HIGH);
      delay(80);
      digitalWrite(I,LOW);
      delay(500);
    }
}

void allumage7()//On peut choisir dans celui ci quelle LED on veut allumer en fonction du fichier param.h
{
  int valeurActuelle = analogRead(0);
  if (valeurActuelle != 0 && valeurActuelle > 200)
  {
  digitalWrite(b,HIGH);
  delay(80);
  digitalWrite(b,LOW);
  delay(500);
}
}
