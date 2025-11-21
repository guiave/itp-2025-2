#include <stdio.h>

int main() {
    int m, x;

    printf("Digite o numero de usuarios M (ex: 6): ");
    scanf("%d", &m);

    int amigos[m][m];

printf("Digite a matriz de amizades.\nExemplo: Voce digitou o numero de usuarios como 6, voce deve digitar a matriz linha a linha. Input esperado:\n0 0 0 1 0 1\n0 0 0 1 1 0\n0 0 0 0 1 0\n1 1 0 0 1 1\n0 1 1 1 0 1\n1 0 0 1 1 0\n\n", m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &amigos[i][j]);
        }
    }

    printf("Digite o ID do usuario para sugestao (ex: 0): ");
    scanf("%d", &x);
    
    int primeiro_sugestao = 1;
    for (int j = 0; j < m; j++) {
        if (x == j || amigos[x][j] == 1) {
            continue;
        }

        int amigo_em_comum = 0;
        for (int k = 0; k < m; k++) {
            if (amigos[x][k] == 1 && amigos[j][k] == 1) {
                amigo_em_comum = 1;
                break;
            }
        }

        if (amigo_em_comum) {
             if (!primeiro_sugestao) {
                printf(" ");
            }
            printf("%d", j);
            primeiro_sugestao = 0;
        }
    }
    printf("\n");

    return 0;
}