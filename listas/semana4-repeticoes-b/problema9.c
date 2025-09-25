#include <stdio.h>
#include <float.h> // Para usar FLT_MAX

int main() {
    float preco1, preco2, dinheiroDisponivel;
    
    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%f", &preco1);
    printf("Digite o preco do segundo fornecedor: ");
    scanf("%f", &preco2);
    printf("Digite a quantia disponivel: ");
    scanf("%f", &dinheiroDisponivel);

    float menorResto = FLT_MAX; // Inicia com o maior valor float possível
    int melhorQtd1 = 0;
    int melhorQtd2 = 0;

    for (int qtd1 = 0; qtd1 <= 10; qtd1++) {
        for (int qtd2 = 0; qtd2 <= 10; qtd2++) {
            float custoTotal = (qtd1 * preco1) + (qtd2 * preco2);

            if (custoTotal <= dinheiroDisponivel) {
                float restoAtual = dinheiroDisponivel - custoTotal;
                if (restoAtual < menorResto) {
                    menorResto = restoAtual;
                    melhorQtd1 = qtd1;
                    melhorQtd2 = qtd2;
                }
            }
        }
    }

    printf("\nResta menos comprando %d do primeiro e %d do segundo\n", melhorQtd1, melhorQtd2);
    printf("Resto: %.2f\n", menorResto);

    return 0;
}