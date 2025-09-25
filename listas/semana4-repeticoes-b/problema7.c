#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool ehPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; 
        }
    }
    return true; 
}

int main() {
    int a, b;

    do {
        printf("Digite dois numeros inteiros a e b (com a > b):\n");
        printf("a: ");
        scanf("%d", &a);
        printf("b: ");
        scanf("%d", &b);
        if (a <= b) {
            printf("Erro: 'a' deve ser maior que 'b'. Tente novamente.\n\n");
        }
    } while (a <= b);

    printf("\nNumeros primos entre %d e %d:\n", b, a);
    for (int i = b; i <= a; i++) {
        if (ehPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}