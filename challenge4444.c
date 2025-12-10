#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAILLE 10
#define MAX_ECHANGES 25  // Limite d'opérations

typedef struct {
    int num[TAILLE];
    int size;
} Tableau;

// Affiche le tableau avec indices pour faciliter les échanges
void afficher(const Tableau *t) {
    printf("Tableau : ");
    for (int i = 0; i < t->size; i++) {
        printf("%d ", t->num[i]);
    }
    printf("\nIndices : ");
    for (int i = 0; i < t->size; i++) {
        printf("%d ", i);
    }
    printf("\n");
}


bool est_trie(const Tableau *t) {
    for (int i = 0; i < t->size - 1; i++) {
        if (t->num[i] > t->num[i + 1]) {
            return false;
        }
    }
    return true;
}


void echanger(Tableau *t, int i, int j) {
    int tmp = t->num[i];
    t->num[i] = t->num[j];
    t->num[j] = tmp;
}

int main() {
    Tableau t = {.size = TAILLE};
    
    printf("===   DÉFI : TRI ULTIME ===\n");
    printf("Vous devez trier le tableau en effectuant des échanges manuels.\n");
    printf("Vous avez droit à %d échanges maximum.\n\n", MAX_ECHANGES);

    printf("Entrez %d nombres :\n", TAILLE);
    for (int i = 0; i < TAILLE; i++) {
        scanf("%d", &t.num[i]);
    }

    // Sauvegarde de la version triée pour info en cas d'échec (optionnel)
    int trie[TAILLE];
    for (int i = 0; i < TAILLE; i++) {
        trie[i] = t.num[i];
    }
    // Tri rapide de la sauvegarde
    for (int i = 0; i < TAILLE - 1; i++) {
        for (int j = i + 1; j < TAILLE; j++) {
            if (trie[i] > trie[j]) {
                int tmp = trie[i];
                trie[i] = trie[j];
                trie[j] = tmp;
            }
        }
    }

    int nb_echanges = 0;
    int idx1, idx2;

    while (nb_echanges < MAX_ECHANGES) {
        printf("\n--- Tour %d/%d ---\n", nb_echanges + 1, MAX_ECHANGES);
        afficher(&t);

        if (est_trie(&t)) {
            printf("\n🎉 Bravo ! Vous avez trié le tableau en %d échange(s) !\n", nb_echanges);
            return 0;
        }

        printf("Entrez deux indices à échanger (ex: 2 5) : ");
        if (scanf("%d %d", &idx1, &idx2) != 2) {
            printf("Entrée invalide. Réessayez.\n");
            while (getchar() != '\n'); // vider le buffer
            continue;
        }

        if (idx1 < 0 || idx1 >= TAILLE || idx2 < 0 || idx2 >= TAILLE) {
            printf("Indices hors limites (0 à %d). Réessayez.\n", TAILLE - 1);
            continue;
        }

        if (idx1 == idx2) {
            printf("Même indice → pas d'échange effectué.\n");
            continue;
        }

        echanger(&t, idx1, idx2);
        nb_echanges++;
    }

    // Vérification finale
    if (est_trie(&t)) {
        printf("\n🎉 Vous avez réussi au dernier coup !\n");
    } else {
        printf("\n💥 Échec ! Vous avez dépassé la limite de %d échanges.\n", MAX_ECHANGES);
        printf("Le tableau trié était : ");
        for (int i = 0; i < TAILLE; i++) {
            printf("%d ", trie[i]);
        }
        printf("\n");
    }

    return 0;

}
