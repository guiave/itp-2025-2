#include <stdio.h>

int main() {
    int m, x, z;

    printf("Digite o numero de cidades M (ex: 3): ");
    scanf("%d", &m);

    int precos[m][m];

printf("Digite a matriz de precos.\nExemplo: Voce digitou o numero de cidades como 3, voce deve digitar a matriz linha a linha. Input esperado:\n0 5 9\n0 0 2\n0 0 0\n\n", m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &precos[i][j]);
        }
    }

    printf("Digite a cidade de origem X e destino Z (ex: 0 2): ");
    scanf("%d %d", &x, &z);

    int min_custo = precos[x][z];
    int cidade_intermediaria = -1;

    for (int y = 0; y < m; y++) {
        int custo_atual = precos[x][y] + precos[y][z];
        if (custo_atual < min_custo) {
            min_custo = custo_atual;
            cidade_intermediaria = y;
        }
    }

    if (cidade_intermediaria == -1) {
        printf("%d-%d R$%d\n", x, z, min_custo);
    } else {
        printf("%d-%d-%d R$%d\n", x, cidade_intermediaria, z, min_custo);
    }

    return 0;
}