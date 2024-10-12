#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"
#define SPACING "%7d"

/*==============  FONCTIONS DEMANDEES ===============*/
matrice_creuse *cree_matrice(){
    //Saisir Dimension Par Utilisateur
    int ligne, col;
    ligne = col = 0;
    while(ligne<1 || col<1){
        printf("Saisir NxM: ");
        scanf(" %d %d", &ligne, &col);
    }
    matrice_creuse *matrice = (matrice_creuse *)malloc(sizeof(matrice_creuse));
    remplirMatrice(matrice, ligne, col);
    return matrice;
}

// 1.	Ecrire une fonction qui permet de remplir une matrice creuse
void remplirMatrice(matrice_creuse *matrice, int N, int M) {
    int valeur_element;
    char input[10];
    matrice->Nlignes = N;
    matrice->Ncolonnes = M;
    matrice->tab_lignes = (liste_ligne *)malloc(N*sizeof(liste_ligne));
    viderBuffer();
    for(int i=0; i<N; i++){
        char has_element = 0;
        (matrice->tab_lignes)[i] = NULL;
        element* old_element = NULL;
        printf("Ligne #%3d\n", i);
        for(int j=0; j<M; j++){
            printf("Colone #%3d\t\t element [%d; %d]: ", j, i, j);

            //scanf(" %d", valeur_element);
            //pour etre plus vite on met just retour a la ligne au lie de 0
            scanf("%c");
            gets(input);
            if(input[0] == '\0' || input[0] == '0'){
                continue;
            }
            valeur_element = (int*)atoi(input);
            element* elementJ = creerElement(j, valeur_element);
            if(old_element != NULL){
                old_element->suivant = elementJ;
            }
            old_element = elementJ;
            //Tester le premiere element pour defnire la tete de la ligne
            if(!has_element) (matrice->tab_lignes)[i] = old_element;
            has_element = 1;
        }
    }
}

/*element* cree_element(int col, int val){
    element *new_element = (element*) malloc(sizeof(element));
    new_element->col = col;
    new_element->val = val;
    new_element->suivant = NULL;
    return new_element;
}*/

// 2.	Ecrire une fonction qui permet d�afficher une matrice creuse sous forme de tableau
void afficherMatrice(matrice_creuse m){
    element* selected_element=NULL;
    printf("\nAffichange de matrice %p: ", m.tab_lignes);
    for(int i=0; i<m.Nlignes; i++){
        printf("\n");
        selected_element = m.tab_lignes[i];
        //Si tout la ligne est vide:
        if(selected_element == NULL){
            for(int j=0; j<m.Ncolonnes; j++){
                printf(SPACING, 0);
            }
            continue;
        }
        int last_indice = 0;
        while(selected_element != NULL){
            for(int j=last_indice; j<selected_element->col; j++){
                printf(SPACING, 0);
            }
            last_indice = selected_element->col+1;
            printf(SPACING, selected_element->val);
            selected_element = selected_element->suivant;
        }
        for(int j=last_indice; j<m.Ncolonnes; j++){
            printf(SPACING, 0);
        }
    }
}



// 3.	Ecrire une fonction qui permet d�afficher toutes les listes cha�n�es
void afficherMatriceListes(matrice_creuse m) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



//  4.	Ecrire une fonction qui renvoie la valeur de l'�l�ment de la ligne i et la colonne j
int rechercherValeur(matrice_creuse m, int i, int j) {
    int result = 0;
    if(i<m.Nlignes && j<m.Ncolonnes){
        element * selected_element = m.tab_lignes[i];
        while(selected_element != NULL && selected_element->col < j){
            selected_element = selected_element->suivant;
        }
        if(selected_element != NULL && selected_element->col == j) result = selected_element->val;
    }
    return result;
}



// 5.	Ecrire une fonction qui affecte une valeur donn�e � l'�l�ment de la ligne i et la colonne j
void affecterValeur(matrice_creuse m, int i, int j, int val) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



// 6.	Ecrire une fonction qui r�alise la somme de deux matrices
void additionerMatrices(matrice_creuse m1, matrice_creuse m2) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



// 7.	Ecrire une fonction qui retourne le nombre d�octets gagn�s
int nombreOctetsGagnes(matrice_creuse m) {
    int result = 0;
    /*
    * TO DO : Ecrire ici votre code
    */
    return result;
}



/*==============  FONCTIONS SUPPLEMENTAIRES ===============*/

// fonction qui renvoie un nouvel �l�ment de liste
element *creerElement(int colonne, int valeur) {
    element *nouvelElement = malloc(sizeof(element));
    nouvelElement->col = colonne;
    nouvelElement->val = valeur;
    nouvelElement->suivant = NULL;
    return nouvelElement;
}


// fonction qui permet de vider le buffer d'entr�e clavier
void viderBuffer (){
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/*========== Fonction Cree par nous ================*/
void free_matrice(matrice_creuse m){
    for(int i=0; i<m.Nlignes; i++){
        if( (m.tab_lignes)[i] == NULL) continue;
        while(((m.tab_lignes)[i])->suivant != NULL){
            element* selected_element = m.tab_lignes[i];
            element* old_selected_element = (m.tab_lignes)[i];
            while(selected_element->suivant != NULL){
                old_selected_element = selected_element;
                selected_element = selected_element->suivant;
            }
            free(selected_element);
            old_selected_element->suivant = NULL;
        }
        free((m.tab_lignes)[i]);
    }
    free(m.tab_lignes);
}
