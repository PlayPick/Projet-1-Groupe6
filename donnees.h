/*
*   Cette bibliothèque contient toutes les fonctions
*   nécessaires à la manipulation de la structure de
*   données et la lecture du fichier csv.
*/

// Chaque objet de cette structure est une ligne du fichier csv
typedef struct ligne{
    int frequence;
    int temps;
} Ligne;

// Chaque objet de cette structure est un élément de la file
typedef struct Element{
    Ligne donnee;
    struct Element *suivant;
} Element;

// Le structure de données qui va stocker les informations du csv est une file de données
typedef struct file{
    Element *premier;
} File;

// Initialise la file
File *initialiser_file();

// Ajoute un élément à la file
void file_ajout(File *file, Ligne nvdonnee);

// Cette fonction va retirer la première valeur entrée dans la file (FIFO)
Ligne file_retrait(File *file);

// La fonction qui vide la file
void file_clear(File *file);

// La fonction qui va lire le csv
int lecture(File *file, int taille);
