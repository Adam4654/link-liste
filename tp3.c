
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
    //allocate l'espace memoire
    matrice_creuse *matrice = (matrice_creuse *)malloc(sizeof(matrice_creuse));
    //Appele Remplire le matrice
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
                //Obtenir le valeur
            printf("Colone #%3d\t\t element [%d; %d]: ", j, i, j);
                //pour etre plus vite on met just retour a la ligne au lie de 0
            scanf("%c");
            gets(input);
            if(input[0] == '\0' || input[0] == '0'){
                continue;
            }
                //converter le valeur en int
            valeur_element = (int*)atoi(input);
            element* elementJ = creerElement(j, valeur_element);
            if(old_element != NULL){
                old_element->suivant = elementJ;
            }
            old_element = elementJ;
            //Tester le premiere element pour definire la tete de la ligne
            if(!has_element) (matrice->tab_lignes)[i] = old_element;
            has_element = 1;
        }
    }
}


// 2.	Ecrire une fonction qui permet d’afficher une matrice creuse sous forme de tableau
void afficherMatrice(matrice_creuse m){
    element* selected_element=NULL;
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
        //sinon
        int last_indice = 0;
        while(selected_element != NULL){
            for(int j=last_indice; j<selected_element->col; j++){
                printf(SPACING, 0);
                //imprimer des zeros avant l'element non nul
            }
            //imprimer le element non nul
            printf(SPACING, selected_element->val);
            //avancer le derniere indice de 0s
            last_indice = selected_element->col+1;
            selected_element = selected_element->suivant;
        }
        //print les nuls qui continue jusqu'a la fin
        for(int j=last_indice; j<m.Ncolonnes; j++){
            printf(SPACING, 0);
        }
    }
}



// 3.	Ecrire une fonction qui permet d’afficher toutes les listes chaînées
void afficherMatriceListes(matrice_creuse m) {
    element* selected_element=NULL;
    for(int i=0; i<m.Nlignes; i++){
        printf("\nligne %d -> ",i);
        selected_element = m.tab_lignes[i];
        //Si tout la ligne est vide:
        if(selected_element == NULL){
            continue;
        }
        while(selected_element != NULL){
            printf("[%d] : %d",selected_element->col,selected_element->val);
            selected_element = selected_element->suivant;
            if (selected_element)
                //print(SPACING);
                printf("  ----->  ");
        }
        if (i>=0 && i<m.Nlignes-1)
            printf("\n|\nv\n");
    }
}



//  4.	Ecrire une fonction qui renvoie la valeur de l'élément de la ligne i et la colonne j
int rechercherValeur(matrice_creuse m, int i, int j) {
    int result = 0; //initialisation par defaut
    if(i<m.Nlignes && j<m.Ncolonnes){
        element * selected_element = m.tab_lignes[i];
        //Passer les element de colone plus petit
        while(selected_element != NULL && selected_element->col < j){
            selected_element = selected_element->suivant;
        }
        //Tester si on a arriver dans le derniere element
        if(selected_element != NULL && selected_element->col == j) result = selected_element->val;
    }else{
        printf("Fatal error max [%d][%d]", m.Nlignes, m.Ncolonnes);
    }
    return result;
}



// 5.	Ecrire une fonction qui affecte une valeur donnée à l'élément de la ligne i et la colonne j
void affecterValeur(matrice_creuse m, int i, int j, int val) {
    element* selected_element=m.tab_lignes[i];
    element* old_element = NULL;
    if(selected_element==NULL && val != 0) {  //CASE 1         //cas ligne est vide et on ajout element non nul si nul on fait riens
        //metre a jour la tete
        m.tab_lignes[i] = creerElement(j, val);

    }else{                                 //cas ligne pas vide
        while(selected_element != NULL && selected_element->col < j){ //Parcurire les elements avant notre colonne, stocker le plus proche en gauche dans old
            old_element = selected_element;
            selected_element=selected_element->suivant;
        }                                   // essayer à trouver cet element
        if(selected_element != NULL && selected_element->col == j){      //CASE 4 - colone est deja dans la list
            if(val!=0) selected_element->val=val;   //affectuer une nouvelle valeur non nulle
            else{ //supprimer cette element si la nouvelle valeur est nulle
                if(old_element == NULL){ //si le premiere element de la ligneliste
                    m.tab_lignes[i] = selected_element->suivant;
                }
                else{   //si pas la tete
                    old_element->suivant = selected_element->suivant;
                }
                free(selected_element);
            }
        }
        else if(val != 0){//pas besoins d'entre si on a passe le cas de mise a jour.
            element  *temp= creerElement(j, val);
            if(old_element == NULL){//CASE 2 - Avant tous les elements
                m.tab_lignes[i] = temp;
            }
            else{ //CASE 3 fin de la liste ou milieux
                old_element->suivant = temp;
            }
            temp->suivant = selected_element;
        }
    }
}



// 6.	Ecrire une fonction qui réalise la somme de deux matrices
void additionerMatrices(matrice_creuse m1, matrice_creuse m2) {
    if(m1.Ncolonnes == m2.Ncolonnes && m1.Nlignes == m2.Nlignes){
        afficherMatrice(m1);
        printf("\n+\n");
        afficherMatrice(m2);
        for(int i=0; i<m1.Nlignes; i++){
            element* ligne1 = (m1.tab_lignes)[i];
            element* ligne2 = (m2.tab_lignes)[i];
            element* old1 = ligne1;
            if(ligne1 == NULL && ligne2==NULL) continue;    //cas ligne nulle
            while( (ligne1 != NULL) && (ligne2 != NULL)){
                if(ligne1->col == ligne2->col){
                    ligne1->val += ligne2->val;
                    old1 = ligne1;
                    ligne1 = ligne1->suivant;
                    ligne2 = ligne2->suivant;
                }else if(ligne2->col < ligne1->col){
                    //colone de 2 viens avant colonne de 1
                    element* ajout_element = creerElement(ligne2->col, ligne2->val);
                    ajout_element->suivant = ligne1;
                    if(old1 != ligne1){//pas le premiere element en question
                        old1->suivant = ajout_element;
                    }else{
                        //le tout premiere element dois etre obtenu par ligne2
                        m1.tab_lignes[i] = ajout_element;
                    }
                    old1 = ajout_element;
                    ligne2 = ligne2->suivant;
                }else{
                    //Si colonne de ligne1 avant colonne de ligne 2
                    old1 = ligne1;
                    ligne1 = ligne1->suivant;
                }

            }
            if(ligne1 == NULL && ligne2!=NULL){
                if(old1 == (m1.tab_lignes)[i]){ //toute ligne 1 est vide faut ajouter le premiere element
                    element * ajout_element = creerElement(ligne2->col, ligne2->val);
                    (m1.tab_lignes)[i] = ajout_element;
                    old1 = ajout_element;
                    ligne2 = ligne2->suivant;
                }
                while(ligne2 != NULL){//tous **le reste** de ligne 1 est vide
                    element * ajout_element = creerElement(ligne2->col, ligne2->val);
                    old1->suivant = ajout_element;
                    old1 = ajout_element;
                    ligne2 = ligne2->suivant;
                }
            }
        }
        printf("\n=\n");
        afficherMatrice(m1);
    }else{
        printf("Erreur Fatal. Les matrice ne sont pas de meme taille. Aucune operation affectuee");
    }

}



// 7.	Ecrire une fonction qui retourne le nombre d’octets gagnés
int nombreOctetsGagnes(matrice_creuse m) {
    int result = 0;
    int counter=0;
    int ligne = m.Nlignes;
    int colone = m.Ncolonnes;
    element* selected_element = NULL;
    for(int i=0; i<ligne;i++){
        selected_element=m.tab_lignes[i];
        while(selected_element) {
            selected_element = selected_element->suivant;
            counter++;
        }
    }
    result=ligne*colone*sizeof(int)-(counter*sizeof(element)+ ligne*sizeof(element*)+sizeof(matrice_creuse));
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

/*========== Fonction Cree par nous ================*/
void free_matrice(matrice_creuse* m){
    free_contenuMatrice(*m);
    free(m);
}

void free_contenuMatrice(matrice_creuse m){
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
        }//le suivente est null mais on a pas libere notre element de tete
        free((m.tab_lignes)[i]);
    }
    free(m.tab_lignes);
}
