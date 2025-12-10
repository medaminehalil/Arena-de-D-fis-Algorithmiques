
#include <stdio.h>

int main() {
    int v[6], cible;
    printf("Donner le cible : ");
    scanf("%d", &cible);
    for (int i = 0; i < 6; i++) {
        printf("donner l'entier numéro %d :",i+1);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == j) continue;
            int a = v[i], b = v[j];
            if (a + b == cible) { printf("%d+%d=%d\n", a, b, cible); return 0; }
            if (a - b == cible && a > b) { printf("%d-%d=%d\n", a, b, cible); return 0; }
            if (a * b == cible) { printf("%d*%d=%d\n", a, b, cible); return 0; }
            if (b != 0 && a % b == 0 && a / b == cible) { printf("%d/%d=%d\n", a, b, cible); return 0; }
        }
    }

    for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++) if (i != j)
    for (int k = 0; k < 6; k++) if (k != i && k != j) {
        int a = v[i], b = v[j], c = v[k];
        int r;
        r = a + b;
        if (r + c == cible) { printf("%d+%d=%d, %d+%d=%d\n", a,b,r, r,c,cible); return 0; }
        if (r - c == cible && r > c) { printf("%d+%d=%d, %d-%d=%d\n", a,b,r, r,c,cible); return 0; }
        if (r * c == cible) { printf("%d+%d=%d, %d*%d=%d\n", a,b,r, r,c,cible); return 0; }
        if (c != 0 && r % c == 0 && r / c == cible) { printf("%d+%d=%d, %d/%d=%d\n", a,b,r, r,c,cible); return 0; }
        if (a > b) {
            r = a - b;
            if (r + c == cible) { printf("%d-%d=%d, %d+%d=%d\n", a,b,r, r,c,cible); return 0; }
            if (r - c == cible && r > c) { printf("%d-%d=%d, %d-%d=%d\n", a,b,r, r,c,cible); return 0; }
            if (r * c == cible) { printf("%d-%d=%d, %d*%d=%d\n", a,b,r, r,c,cible); return 0; }
            if (c != 0 && r % c == 0 && r / c == cible) { printf("%d-%d=%d, %d/%d=%d\n", a,b,r, r,c,cible); return 0; }
        }
        r = a * b;
        if (r + c == cible) { printf("%d*%d=%d, %d+%d=%d\n", a,b,r, r,c,cible); return 0; }
        if (r - c == cible && r > c) { printf("%d*%d=%d, %d-%d=%d\n", a,b,r, r,c,cible); return 0; }
        if (r * c == cible) { printf("%d*%d=%d, %d*%d=%d\n", a,b,r, r,c,cible); return 0; }
        if (c != 0 && r % c == 0 && r / c == cible) { printf("%d*%d=%d, %d/%d=%d\n", a,b,r, r,c,cible); return 0; }
        if (b != 0 && a % b == 0) {
            r = a / b;
            if (r + c == cible) { printf("%d/%d=%d, %d+%d=%d\n", a,b,r, r,c,cible); return 0; }
            if (r - c == cible && r > c) { printf("%d/%d=%d, %d-%d=%d\n", a,b,r, r,c,cible); return 0; }
            if (r * c == cible) { printf("%d/%d=%d, %d*%d=%d\n", a,b,r, r,c,cible); return 0; }
            if (c != 0 && r % c == 0 && r / c == cible) { printf("%d/%d=%d, %d/%d=%d\n", a,b,r, r,c,cible); return 0; }
        }
    }
    for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++) if (i != j)
    for (int k = 0; k < 6; k++) if (k != i && k != j)
    for (int l = 0; l < 6; l++) if (l != i && l != j && l != k) {
        int a = v[i], b = v[j], c = v[k], d = v[l];
        int r1, r2;

        r1 = a * b;
        r2 = r1 + c;
        if (r2 - d == cible && r2 > d) {
            printf("%d*%d=%d, %d+%d=%d, %d-%d=%d\n", a,b,r1, r1,c,r2, r2,d,cible);
            return 0;
        }
        r2 = r1 - c;
        if (r2 > 0 && r2 + d == cible) {
            printf("%d*%d=%d, %d-%d=%d, %d+%d=%d\n", a,b,r1, r1,c,r2, r2,d,cible);
            return 0;
        }
    }
    for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++) if (i != j)
    for (int k = 0; k < 6; k++) if (k != i && k != j)
    for (int l = 0; l < 6; l++) if (l != i && l != j && l != k) {
        int a = v[i], b = v[j], c = v[k], d = v[l];
        int r1, r2;

        r1 = a / b;
        r2 = r1 + c;
        if (r2 - d == cible && r2 > d) {
            printf("%d/%d=%d, %d+%d=%d, %d-%d=%d\n", a,b,r1, r1,c,r2, r2,d,cible);
            return 0;
        }
        r2 = r1 - c;
        if (r2 > 0 && r2 + d == cible) {
            printf("%d/%d=%d, %d-%d=%d, %d+%d=%d\n", a,b,r1, r1,c,r2, r2,d,cible);
            return 0;
        }
    }
    printf("Aucune solution trouvee.\n");
    return 0;
}
