#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void stat(char fiche[]) {
    FILE *f = fopen(fiche, "r");
    if (f==NULL) {
        printf("Aucun fichier.\n");
        return;
    }

    char nom[50], prenom[50];
    int sc;

    long total = 0;
    long sum = 0;

    int max= -1;
    int min= -1;

    while (fscanf(f, "%99s %99s %d", nom, prenom, &sc) == 3) {
        total++;
        sum += sc;

        if (max == -1 || sc > max) max = sc;
        if (min == -1 || sc < min) min= sc;
    }

    fclose(f);

    if (total == 0) {
        printf("Aucun enregistrement dans %s\n", fiche);
        return;
    }

    double avg = (double)sum / (double)total;

    printf("\n==== STATISTIQUES GLOBALES ====\n");
    printf("Total parties : %d\n", total);
    printf("Meilleur score : %d\n", max);
    printf("Pire score     : %d\n", min);
    printf("Score moyen    : %f\n", avg);
    
}