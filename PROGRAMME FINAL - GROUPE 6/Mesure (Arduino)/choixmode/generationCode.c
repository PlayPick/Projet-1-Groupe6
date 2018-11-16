#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "generationCode.h"

int create_param() {
   FILE * fp;
   int a;
   int b;
   a = menu();//a prend la valeur de la variable i de la fonction menu()
   //b = menu2();
   fp = fopen ("C:\\Users\\schub\\OneDrive\\Bureau\\PROGRAMME FINAL - GROUPE 6\\Mesure (Arduino)\\alumLED\\param.h", "w+");//crée un fichier param.h
   fprintf(fp, "%s \n%s \n%s %s %d %s\n%s %s %d %s", "#ifndef PARAM", "#define PARAM","const int", "a=",a,";","const int", "b=",b,";\n#endif");//écrit dans le fichier param.h

   fclose(fp);

   return(0);
}
