#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

int main() {
    /* ============= variable de utilisateur ============= */
    struct MatriceCreuse* m1;
    struct MatriceCreuse* m2;
    // ============= MENU UTILISATEUR ============= */
    char choix = '0';
    while (choix != '8') {
        printf("\n======================================");
        printf("\n1. Remplir une matrice creuse");
        printf("\n2. Afficher une matrice creuse sous forme de tableau");
        printf("\n3. Afficher une matrice creuse sous forme de listes");
        printf("\n4. Donner la valeur d'un element d'une matrice creuse");
        printf("\n5. Affecter une valeur ? un 閘閙ent d抲ne matrice creuse");
        printf("\n6. Additionner deux matrices creuses");
        printf("\n7. Calculer le gain");
        printf("\n8. Quitter");
        printf("\n======================================");
        printf("\n   Votre choix ? ");
        choix = getchar();

        switch (choix) {
            case '1' :
                m1=creerMatrice();
                remplirMatrice(m1,m1->Nlignes,m1->Ncolonnes);
                break;

            case '2' :
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
