#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

int main() {
    //========Initialisation=========//
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
                remplirMatrice(&matrice2, 4, 2);
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '2' :
                afficherMatrice(*matrice1);
                afficherMatrice(matrice2);
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '3' :
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '4' :
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '5' :
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '6' :
                // Ecrire ici le code pour ce choix utlisateur
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

    return 0;
}
