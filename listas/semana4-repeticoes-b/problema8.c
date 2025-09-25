#include <stdio.h>

int main() {
    float preco1, preco2, dinheiroDisponivel;
    
    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%f", &preco1);
    printf("Digite o preco do segundo fornecedor: ");
    scanf("%f", &preco2);
    printf("Digite a quantia disponivel: ");
    scanf("%f", &dinheiroDisponivel);
    printf("\n--- Possibilidades de Compra ---\n");

    for (int qtd1 = 0; qtd1 <= 10; qtd1++) {
        for (int qtd2 = 0; qtd2 <= 10; qtd2++) {
            float custoTotal = (qtd1 * preco1) + (qtd2 * preco2);

            if (custoTotal <= dinheiroDisponivel) {
                float resto = dinheiroDisponivel - custoTotal;
                printf("Comprando %d do primeiro e %d do segundo resta: %.2f\n", qtd1, qtd2, resto);
            }
        }
    }

    return 0;
}