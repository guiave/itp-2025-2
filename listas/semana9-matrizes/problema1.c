#include <stdio.h>

int main() {
    int m, n;

    printf("Digite as dimensoes da matriz M e N (ex: 4 6): ");
    scanf("%d %d", &m, &n);

    int campo[m][n];
    int irrigado[m][n];

    printf("Digite os %d elementos da matriz.\nExemplo: Voce digitou as dimensoes da matriz como 4 6, voce digite a matriz linha a linha. Input esperado:\n0 0 0 1 1 0\n0 2 2 1 1 0\n1 0 2 1 2 0\n1 1 1 0 0 0\n\n", m * n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &campo[i][j]);
            irrigado[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (campo[i][j] == 2) {
                // Norte, Sul, Leste, Oeste
                irrigado[i - 1][j] = 1;
                irrigado[i + 1][j] = 1;
                irrigado[i][j + 1] = 1;
                irrigado[i][j - 1] = 1;
            }
        }
    }

    int ferteis_irrigados = 0;
    int ferteis_nao_irrigados = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (campo[i][j] == 1) {
                if (irrigado[i][j] == 1) {
                    ferteis_irrigados++;
                } else {
                    ferteis_nao_irrigados++;
                }
            }
        }
    }

    printf("\n\n%d %d\n", ferteis_irrigados, ferteis_nao_irrigados);

    return 0;
}