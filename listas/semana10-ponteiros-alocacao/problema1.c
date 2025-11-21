#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2;
    int *u, *v;

    printf("Digite as dimensoes n1 e n2 dos vetores (ex: 3 3): ");
    scanf("%d %d", &n1, &n2);

    if (n1 != n2) {
        printf("dimensoes incompativeis\n");
        return 0;
    }

    u = (int *) malloc(n1 * sizeof(int));
    v = (int *) malloc(n2 * sizeof(int));

    printf("Digite os %d elementos do primeiro vetor (ex: 3 -2 1): ", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &u[i]);
    }

    printf("Digite os %d elementos do segundo vetor (ex: 4 -2 5): ", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &v[i]);
    }
    
    printf("Vetor resultante da soma: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", u[i] + v[i]);
    }
    printf("\n");

    free(u);
    free(v);

    return 0;
}