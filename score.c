#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct score
{   char nom[50];
    char prenom[50];
    int score ;
    struct score *left;
    struct score *right;
} score ;

typedef score* arbre ;

arbre creat_score(char nom[],char prenom[],int sc ){
    score *nouv;
    nouv =malloc(sizeof(score));
    strcpy(nouv ->nom,nom);
    strcpy(nouv->prenom,prenom);
    nouv->score=sc;
    nouv->left=NULL;
    nouv->right=NULL;
    return nouv;
}
void insert(arbre *arb,char nom[],char prenom[],int sc ){
    if(*arb==NULL){
        *arb=creat_score(nom,prenom,sc);
    }
    else if((*arb)->score <sc){
        insert(&(*arb)->left,nom,prenom,sc);
    }
    else 
        insert(&(*arb)->right,nom,prenom,sc);
       
}

void charge_arbre(char fiche[],arbre *arb ) {
    FILE *f = fopen(fiche, "r");
    if (f==NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", fiche);
        return;
    }
    int score;
    char nom[50];
    char prenom[50];
    while (fscanf(f, "%s %s %d", nom, prenom, &score) == 3) {
        insert(arb,nom,prenom, score);
    }

    fclose(f);
}
void save(arbre arb, FILE *f) {
    if (arb ==NULL) return;
    save(arb->right, f);
    fprintf(f, "%s %s %d\n", arb->nom, arb->prenom,arb->score);
    save(arb->left, f);
}

void save_fiche(arbre arb, char fiche[]) {
    FILE *f = fopen(fiche, "w");
    if (f==NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", fiche);
        return;
    }
    save(arb, f);
    fclose(f);
}
void affichage (char fiche[]){
    FILE *f= fopen(fiche,"r");
     if (f==NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", fiche);
        return;
    } 
    char nom[50],prenom[50];
    int sc;
    int i=1;
    while (fscanf(f, "%s %s %d", nom, prenom,&sc) == 3) {
        printf("%d:%s %s %d\n",i,nom, prenom, sc);
        i++;
        
    }
    fclose(f);





}