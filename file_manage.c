#include <stdio.h>
#include <stdlib.h>
#include "file_operation.h"

int main() {
    int choice;
    char filename[100];
    char content[256];

    do {
        printf("\n1. Créer un fichier\n");
        printf("2. Lire un fichier\n");
        printf("3. Écrire dans un fichier\n");
        printf("4. Supprimer un fichier\n");
        printf("5. Lister les fichiers\n");
        printf("6. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Entrez le nom du fichier : ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 2:
                printf("Entrez le nom du fichier à lire : ");
                scanf("%s", filename);
                readFile(filename);
                break;
            case 3:
                printf("Entrez le nom du fichier : ");
                scanf("%s", filename);
                printf("Entrez le contenu à écrire : ");
                scanf(" %[^\n]", content); // Lit toute une ligne de texte, y compris les espaces, jusqu'à ce qu'une nouvelle ligne (\n) soit rencontrée.
                writeFile(filename, content);
                break;
            case 4:
                printf("Entrez le nom du fichier à supprimer : ");
                scanf("%s", filename);
                deleteFile(filename);
                break;
            case 5:
                listFiles();
                break;
            case 6:
                printf("Au revoir!\n");
                break;
            default:
                printf("Option invalide.\n");
        }
    } while (choice != 6);

    return 0;
}
