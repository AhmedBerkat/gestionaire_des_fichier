#include <stdio.h>
#include <stdlib.h>
#include "file_operation.h"
// Paramètre qui représente le nom du fichier, passé en tant que chaîne de caractères constante 
//(const signifie qu'on ne peut pas modifier la chaîne).
void createFile(const char *filename) {
    //Déclaration d'un pointeur vers une structure FILE pour manipuler des fichiers.
    //Ouvre le fichier en mode écriture ("w"), le crée s'il n'existe pas. Retourne un pointeur vers le fichier ou NULL en cas d'échec.
    FILE *file = fopen(filename, "w");
    //Vérifie si l'ouverture du fichier a échoué. Si fopen n'a pas pu ouvrir ou créer le fichier, il retourne NULL.
    if (file == NULL) {
        printf("Erreur de création du fichier.\n");
        return;
    }
    //fprintf : Écrit dans le fichier ouvert.
    //file : Pointeur vers le fichier dans lequel on écrit.
    //"Ceci est le contenu du fichier.\n" : Texte à écrire dans le fichier.
    fprintf(file, "Ceci est le contenu du fichier.\n");
    //fclose : Ferme le fichier après utilisation pour libérer les ressources.
    fclose(file);
    printf("Fichier créé avec succès : %s\n", filename);
}

void readFile(const char *filename) {
    //char ch : Variable pour stocker chaque caractère lu du fichier.
    char ch;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }
    //fgetc(file) : Lit un caractère du fichier.
    //EOF : Fin du fichier. La boucle continue jusqu'à ce que tous les caractères soient lus.
    while ((ch = fgetc(file)) != EOF) {
        //putchar(ch) : Affiche chaque caractère lu à la console
        putchar(ch);
    }
    fclose(file);
}

void writeFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "a"); //"a" : Mode d'ouverture "append", pour ajouter du contenu sans écraser ce qui existe déjà.
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }
    //"%s" : Remplace par le contenu passé à la fonction et l'écrit dans le fichier.
    fprintf(file, "%s\n", content);
    fclose(file);
    printf("Contenu ajouté avec succès à : %s\n", filename);
}

void deleteFile(const char *filename) {
    //Supprime le fichier. Retourne 0 en cas de succès, sinon une valeur différente.
    if (remove(filename) == 0) {
        printf("Fichier supprimé avec succès : %s\n", filename);
    } else {
        printf("Erreur lors de la suppression du fichier.\n");
    }
}

void listFiles() {
    system("dir"); // Exécute une commande système.
}
