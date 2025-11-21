#include <stdio.h>

int main() {
    int m, n;

    printf("Digite a quantidade de numeros sorteados e a quantidade de numeros da aposta (ex: 6 6): ");
    scanf("%d %d", &m, &n);

    int sorteados[m];
    int apostados[n];

    printf("Digite os %d numeros sorteados (ex: 1 37 18 25 43 39): ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &sorteados[i]);
    }

    printf("Digite os %d numeros da sua aposta (ex: 4 28 14 1 55 37): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &apostados[i]);
    }

    int acertos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (apostados[i] == sorteados[j]) {
                acertos++;
                break;
            }
        }
    }

    printf("Voce acertou: %d\n", acertos);

    return 0;
}