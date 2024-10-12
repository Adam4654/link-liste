#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"
#define MAX_MEMORY 5

int main() {
    //========Initialisation=========//
    //matrice_creuse *memory_matrice = (matrice_creuse *)malloc(MAX_MEMORY*sizeof(matrice_creuse));
    //for(int i=0; i<MAX_MEMORY; i++) memory_matrice[i] = NULL;

    matrice_creuse *matrice1;
    matrice_creuse matrice2;
    // ============= MENU UTILISATEUR ============= */
    char choix = '0';
    while (choix != '8') {
        printf("\n======================================");
        printf("\n1. Remplir une matrice creuse");
        printf("\n2. Afficher une matrice creuse sous forme de tableau");
        printf("\n3. Afficher une matrice creuse sous forme de listes");
        printf("\n4. Donner la valeur d'un element d'une matrice creuse");
        printf("\n5. Affecter une valeur à un élément d’une matrice creuse");
        printf("\n6. Additionner deux matrices creuses");
        printf("\n7. Calculer le gain");
        printf("\n8. Quitter");
        printf("\n======================================");
        printf("\n   Votre choix ? ");
        choix = getchar();

        switch (choix) {
            case '1' :
                matrice1 = cree_matrice();
                remplirMatrice(&matrice2, 4, 3);
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '2' :
                printf("\nAffichange de matrice %p: ", matrice1);
                afficherMatrice(*matrice1);
                printf("\nAffichange de matrice %p: ", &matrice2);
                afficherMatrice(matrice2);
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '3' :
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '4' :
                int ligne, colone;
                printf("Ligne: ");
                scanf(" %d", &ligne);
                printf("Colonne: ");
                scanf(" %d", &colone);
                printf(" [%d][%d] -> %d", ligne, colone, rechercherValeur(*matrice1, ligne, colone));
                break;

            case '5' :
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '6' :
                additionerMatrices(*matrice1, matrice2);
                break;

            case '7' :
                // Ecrire ici le code pour ce choix utlisateur
               break;

            case '8' :
                free_matrice(*matrice1);
                free(matrice1);
                free_matrice(matrice2);
                printf("\n======== PROGRAMME TERMINE ========\n");
                break;

            default :
                printf("\n\nERREUR : votre choix n'est valide ! ");
        }
        printf("\n\n\n");
        viderBuffer();
    }
//    free(memory_matrice);
    return 0;
}
