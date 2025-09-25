#include <stdio.h>

int main() {
    float p, q;

    printf("Digite o preco de venda p: ");
    scanf("%f", &p);
    printf("Digite o preco de producao q: ");
    scanf("%f", &q);

    float maxRazao = 0.0;
    int melhorX = 0, melhorY = 0;

    for (int x = 2; x <= 10; x++) {
        for (int y = 1; y < x; y++) {
            if ((y * p) >= (x * q)) {
                float razaoAtual = (float)x / y;
                if (razaoAtual > maxRazao) {
                    maxRazao = razaoAtual;
                    melhorX = x;
                    melhorY = y;
                }
            }
        }
    }

    if (melhorX > 0) {
        printf("\nA melhor promocao eh: leve %d pague %d\n", melhorX, melhorY);
    } else {
        printf("\nNenhuma promocao viavel foi encontrada.\n");
    }

    return 0;
}