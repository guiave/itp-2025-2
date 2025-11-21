#include <stdio.h>

int main() {
    int m;

    printf("Digite o numero de times M (ex: 6): ");
    scanf("%d", &m);

    int resultados[m][m];

printf("Digite a matriz de resultados.\nExemplo: Voce digitou o numero de times como 6, voce deve digitar a matriz linha a linha. Input esperado:\n0 2 2 1 3 2\n0 0 3 3 5 2\n3 2 0 1 3 1\n3 2 2 0 0 6\n3 6 0 0 0 2\n3 3 3 0 2 0\n\n", m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &resultados[i][j]);
        }
    }

    int empates = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (resultados[i][j] == resultados[j][i]) {
                empates++;
            }
        }
    }

    printf("%d\n", empates);

    return 0;
}