//
// Created by xiangyang on 2024/10/12.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"


/*==============  FONCTIONS DEMANDEES ===============*/

// 1.	Ecrire une fonction qui permet de remplir une matrice creuse
void remplirMatrice(matrice_creuse *m, int N, int M) {
    m->tab_lignes = (liste_ligne*)malloc(m->Nlignes * sizeof(liste_ligne));
    for(int i=0 ; i < m->Nlignes ; i++){
        for(int j=0 ; j < m->Ncolonnes ; j++){
            printf("entrer l'element[%d][%d]",i,j);
            int temp=0;
            viderBuffer();
            scanf("d", &temp);
            if(j!=0)
                m->tab_lignes[i][j].suivant = creerElement(j, temp);
            else
                m->tab_lignes[i]=creerElement(j, temp);
        }
    }
}



// 2.	Ecrire une fonction qui permet d’afficher une matrice creuse sous forme de tableau
void afficherMatrice(matrice_creuse m){
    /*
    * TO DO : Ecrire ici votre code
    */
}



// 3.	Ecrire une fonction qui permet d’afficher toutes les listes chaînées
void afficherMatriceListes(matrice_creuse m) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



//  4.	Ecrire une fonction qui renvoie la valeur de l'élément de la ligne i et la colonne j
int rechercherValeur(matrice_creuse m, int i, int j) {
    int result = 0;
    /*
    * TO DO : Ecrire ici votre code
    */
    return result;
}



// 5.	Ecrire une fonction qui affecte une valeur donnée à l'élément de la ligne i et la colonne j
void affecterValeur(matrice_creuse m, int i, int j, int val) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



// 6.	Ecrire une fonction qui réalise la somme de deux matrices
void additionerMatrices(matrice_creuse m1, matrice_creuse m2) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



// 7.	Ecrire une fonction qui retourne le nombre d’octets gagnés
int nombreOctetsGagnes(matrice_creuse m) {
    int result = 0;
    /*
    * TO DO : Ecrire ici votre code
    */
    return result;
}



/*==============  FONCTIONS SUPPLEMENTAIRES ===============*/

// fonction qui renvoie un nouvel élément de liste
element *creerElement(int colonne, int valeur) {
    element *nouvelElement = malloc(sizeof(element));
    nouvelElement->col = colonne;
    nouvelElement->val = valeur;
    nouvelElement->suivant = NULL;
    return nouvelElement;
}


// fonction qui permet de vider le buffer d'entrée clavier
void viderBuffer (){
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/*==============  FONCTIONS utilisateur ===============*/
matrice_creuse *creerMatrice() {
    printf("entrer la taille de la matrice,s'il vous plaîs\n");

    int ligne=0,colone=0;
    printf("nombre de la ligne:");
    scanf("%d",&ligne);
    printf("nombre de la colone:");
    scanf("%d",&colone);
    printf("\n");
    matrice_creuse *p=(matrice_creuse *)malloc(sizeof(matrice_creuse));
    p->Nlignes = ligne;
    p->Ncolonnes = colone;
    p->tab_lignes = (liste_ligne*)malloc(colone*sizeof(liste_ligne));
    return p;
}
