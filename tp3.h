//
// Created by xiangyang on 2024/10/12.
//

#ifndef LINK_LIST_TP3_H
#define LINK_LIST_TP3_H


struct Element {
    int col;
    int val;
    struct Element *suivant;
} ;

typedef struct Element element;


// TYPE LISTE_LIGNE
typedef element *liste_ligne;


// STRUCTURE MATRICE CREUSE
struct MatriceCreuse {
    int Nlignes;
    int Ncolonnes;
    liste_ligne *tab_lignes;
} ;
typedef struct MatriceCreuse matrice_creuse;


// FONCTIONS DEMANDEES
void remplirMatrice(matrice_creuse *m, int N, int M);
void afficherMatrice(matrice_creuse m);
void afficherMatriceListes(matrice_creuse m);
int rechercherValeur(matrice_creuse m, int i, int j);
void affecterValeur(matrice_creuse m, int i, int j, int val);
void additionerMatrices(matrice_creuse m1, matrice_creuse m2);
int nombreOctetsGagnes(matrice_creuse m);


// FONCTIONS SUPPLEMENTAIRES
element *creerElement(int colonne, int valeur);
void viderBuffer ();

//Notre Fonctions
matrice_creuse *cree_matrice();
void free_matrice(matrice_creuse *);
void free_contenuMatrice(matrice_creuse);

#endif //LINK_LIST_TP3_H



