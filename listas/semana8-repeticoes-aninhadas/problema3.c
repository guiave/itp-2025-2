#include <stdio.h>

int main() {
    int n;

    printf("Digite o numero de pilotos (ex: 5): ");
    scanf("%d", &n);

    int largada[n];
    int chegada[n];
    int pos_largada[n + 1];
    int pos_chegada[n + 1];

    printf("Digite a ordem de largada (ex: 2 5 3 4 1): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &largada[i]);
        pos_largada[largada[i]] = i + 1;
    }

    printf("Digite a ordem de chegada (ex: 1 5 2 3 4): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &chegada[i]);
        pos_chegada[chegada[i]] = i + 1;
    }

    int max_ganho = 0;
    int piloto_vencedor = -1;
    int contador_vencedores = 0;

    for (int id = 1; id <= n; id++) {
        int ganho = pos_largada[id] - pos_chegada[id];

        if (ganho > max_ganho) {
            max_ganho = ganho;
            piloto_vencedor = id;
            contador_vencedores = 1;
        } else if (ganho == max_ganho && max_ganho > 0) {
            contador_vencedores++;
        }
    }

    printf("Piloto que mais ganhou posicoes: ");
    if (max_ganho > 0 && contador_vencedores == 1) {
        printf("%d\n", piloto_vencedor);
    } else {
        printf("empate\n");
    }

    return 0;
}