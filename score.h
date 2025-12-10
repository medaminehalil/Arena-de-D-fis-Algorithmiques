#ifndef SCORE_H
#define SCORE_H

typedef struct score
{
    char nom[50];
    char prenom[50];
    int score;
    struct score *left;
    struct score *right;
} score;

typedef score* arbre;

arbre creat_score(char nom[], char prenom[], int sc);
void insert(arbre *arb, char nom[], char prenom[], int sc);
void charge_arbre(char fiche[], arbre *arb);
void save_fiche(arbre arb, char fiche[]);
void affichage(char fiche[]);

#endif
