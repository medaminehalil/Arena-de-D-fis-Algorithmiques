#include <stdio.h>
#include <string.h>
#include "Mastermind.h"
#include "score.h"
#include "robot.h"

int main() {
    arbre scores = NULL;
    charge_arbre("scores.txt", &scores);

    printf("\n=====platform de defi=====\n");
    printf("1) Jouer \n");
    printf("2) Afficher le classement\n");
    printf("Choix : ");

    int choix;
    scanf("%d", &choix);

    if (choix == 1) {
        char nom[50], prenom[50];

        printf("Nom : ");
        scanf("%s", nom);
        printf("Prenom : ");
        scanf("%s", prenom);

        int essais = defi_mastermind();

        int sc = 0;
        if (essais == -1)
            sc = 0;
        else
            sc = 100 - essais * 10;

        printf("\nScore obtenu : %d\n", sc);

        insert(&scores, nom, prenom, sc);
        save_fiche(scores, "scores.txt");
        char *s=defi_robot();
        printf("entre le chemain :");
        char str[100];
        scanf("%s",str);
        if(strcmp(s, str) == 0){printf("\nScore obtenu : 50\n");
            sc=sc+50;
        }
        else printf("votre chemain est faux");
    }

    else if (choix == 5) {
        affichage("scores.txt");
    }

    else {
        printf("Choix invalide.\n");
    }

    return 0;
}
