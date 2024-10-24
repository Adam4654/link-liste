#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"
#define MAX_MEMORY 5

int main() {
    //========Initialisation=========//
    int iMatrice_active = 0;
    matrice_creuse ** memory_matrice = (matrice_creuse **)malloc(MAX_MEMORY*sizeof(matrice_creuse*));
    for(int i=0; i<MAX_MEMORY; i++) memory_matrice[i] = NULL;

    //matrice_creuse active_matrice = memory_matrice[0];



    //matrice_creuse *matrice1;
    //matrice_creuse matrice2;
    // ============= MENU UTILISATEUR ============= */
    char choix = ' ';
    char choix2 = '0';
    while (choix != '8') {
        printf("\n======================================");
        printf("\n0. Activer matrice / Voire le memoire des matrices");
        printf("\n1. Remplir une matrice creuse");
        printf("\n2. Afficher une matrice creuse sous forme de tableau");
        printf("\n3. Afficher une matrice creuse sous forme de listes");
        printf("\n4. Donner la valeur d'un element d'une matrice creuse");
        printf("\n5. Affecter une valeur a un element d'une matrice creuse");
        printf("\n6. Additionner deux matrices creuses");
        printf("\n7. Calculer le gain");
        printf("\n8. Quitter");
        printf("\n======================================");
        printf("\n   Votre choix ? ");
        choix = getchar();

        switch (choix) {
            case '0':
                viderBuffer();
                choix2 = '0';
                while(choix2 != '3'){
                    for(int i=0; i<MAX_MEMORY; i++){
                        char selected;
                        selected = (i == iMatrice_active)? '>' : ' ';
                        memory_matrice[i]?  printf("\n %c %d. Identifiant %p - Dimensions: %d x %d", selected, i+1, memory_matrice[i], \
                                                                                memory_matrice[i]->Nlignes, memory_matrice[i]->Ncolonnes) \
                                          : printf("\n %c %d. NULL - FREE", selected, i+1);
                    }
                    printf("\nMatrice Active (selecte): %d. - %p", iMatrice_active+1, memory_matrice[iMatrice_active]);

                    printf("\n------------------------------------------------------------");
                    printf("\n1. Changer selection");
                    printf("\n2. Delete selection (free memory)");
                    printf("\n3. Retourner");
                    printf("\n   Votre choix ? ");
                    choix2 = getchar();
                    switch(choix2){
                        case '1':
                            iMatrice_active = -1;
                            while(iMatrice_active<0 || iMatrice_active>MAX_MEMORY){
                                printf("Selection[%d - %d]: ", 1, MAX_MEMORY);
                                scanf(" %d", &iMatrice_active);
                                iMatrice_active--;
                            }
                            break;
                        case '2':
                            if(memory_matrice[iMatrice_active]){
                                free_matrice(memory_matrice[iMatrice_active]);
                                memory_matrice[iMatrice_active] = NULL;
                            }else{
                                printf("\nDeja vide!");
                            }
                            break;
                        case '3':
                            break;
                        default:
                            printf("Choix invalide!");
                    }
                    viderBuffer();
                }
                break;
            case '1' :
                printf("\nMatrice active a rempli: %d. %p\n", iMatrice_active+1, memory_matrice[iMatrice_active]);
                if(memory_matrice[iMatrice_active] != NULL){
                    printf("\nMatrice deja remplit");
                }else{
                    memory_matrice[iMatrice_active] = cree_matrice();
                }
                //matrice1 = cree_matrice();
                //remplirMatrice(&matrice2, 4, 3);
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '2' :
                printf("\nAffichange de matrice: %d. %p: ", iMatrice_active+1, memory_matrice[iMatrice_active]);
                if(memory_matrice[iMatrice_active] != NULL){
                    afficherMatrice(*memory_matrice[iMatrice_active]);
                }else{
                    printf("\nMatrice vide!");
                }
                //afficherMatrice(*matrice1);
                //printf("\nAffichange de matrice %p: ", &matrice2);
                //afficherMatrice(matrice2);
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '3' :
                printf("\nAffichange de matrice sous la forme de liste: %d. %p: ", iMatrice_active+1, memory_matrice[iMatrice_active]);
                if(memory_matrice[iMatrice_active] != NULL){
                    afficherMatriceListes(*memory_matrice[iMatrice_active]);
                }else{
                    printf("\nMatrice vide!");
                }
                // Ecrire ici le code pour ce choix utlisateur
                break;

            case '4' :
                printf("\nMatrice selectionner: %d. %p", iMatrice_active+1, memory_matrice[iMatrice_active]);
                if(memory_matrice[iMatrice_active] != NULL){
                    int ligne, colonne;
                    printf("\nLigne (0 - %d): ", memory_matrice[iMatrice_active]->Nlignes-1);
                    do{
                        scanf(" %d", &ligne);
                    }while(ligne < 0 || ligne > memory_matrice[iMatrice_active]->Nlignes-1);

                    printf("\nColonne (0 - %d): ", memory_matrice[iMatrice_active]->Ncolonnes-1);
                    do{
                        scanf(" %d", &colonne);
                    }while(colonne < 0 || colonne > memory_matrice[iMatrice_active]->Ncolonnes-1);

                    printf(" >>>>> [%d][%d] -> %d", ligne, colonne, rechercherValeur(*memory_matrice[iMatrice_active], ligne, colonne));
                }else{
                    printf("\nMatrice vide!");
                }
                break;

            case '5' :
                printf("\nMatrice selectionner: %d. %p", iMatrice_active+1, memory_matrice[iMatrice_active]);
                int i, j, val;
                i = j = val = -1;
                do{ printf("\nLigne (0 - %d): ", memory_matrice[iMatrice_active]->Nlignes-1);
                    scanf(" %d", &i);
                }while(i<0 || i>memory_matrice[iMatrice_active]->Nlignes-1);

                do{ printf("\nColonne (0 - %d): ", memory_matrice[iMatrice_active]->Ncolonnes-1);
                    scanf(" %d", &j);
                }while(j<0 || j>memory_matrice[iMatrice_active]->Ncolonnes-1);

                printf("Quel Valeur: ");
                scanf(" %d", &val);

                affecterValeur(*memory_matrice[iMatrice_active], i, j, val);
                break;

            case '6' :
                printf("\nMatrice #1 pour addition: %d. %p",  iMatrice_active+1, memory_matrice[iMatrice_active]);
                printf("\nSelecter le duexieme matrice...");
                int iMatrice_active2 = -1;
                for(int i=0; i<MAX_MEMORY; i++){
                    char selected;
                    selected = (i == iMatrice_active)? '>' : ' ';
                    if(memory_matrice[i])
                    printf("\n %c %d. Identifiant %p - Dimensions: %d x %d", selected, i+1,  memory_matrice[i], \
                                                                            memory_matrice[i]->Nlignes, memory_matrice[i]->Ncolonnes);
                }
                while(1){
                    printf("\n Index Matrice 2 - Choix: ");
                    scanf(" %d", &iMatrice_active2);
                    iMatrice_active2--;
                    if(iMatrice_active2>=0 && iMatrice_active2<MAX_MEMORY){
                        if(memory_matrice[iMatrice_active])
                            break;
                    }
                }
                additionerMatrices(*memory_matrice[iMatrice_active], *memory_matrice[iMatrice_active2]);
                break;

            case '7' :
                printf("\nMatrice calculer Octet Gagne: %d. %p",  iMatrice_active+1, memory_matrice[iMatrice_active]);
                int gagne = nombreOctetsGagnes(*memory_matrice[iMatrice_active]);
                if(gagne >= 0){
                    printf("\nVous avez gagne %d octet", gagne);
                }else{
                    printf("\nVous avez perdu %d octet", -gagne);
                }
                break;

            case '8' :
                for(int i=0; i<MAX_MEMORY; i++){
                    if(memory_matrice[i]){
                        free_matrice(memory_matrice[i]);
                    }

                }
                //free_matrice(*matrice1);
                //free(matrice1);
                //free_matrice(matrice2);
                printf("\n======== PROGRAMME TERMINE ========\n");
                break;

            default :
                printf("\n\nERREUR : votre choix n'est valide ! ");
        }
        printf("\n\n\n");
        viderBuffer();
    }
    free(memory_matrice);
    return 0;
}
