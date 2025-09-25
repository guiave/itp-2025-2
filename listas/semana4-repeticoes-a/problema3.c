#include <stdio.h>
#include <math.h>

int somaDivisoresProprios(int n) {
    int soma = 1;
    
    if (n == 1) {
        return 0;
    }
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            soma += i;
            if (i != n / i) {
                soma += n / i;
            }
        }
    }
    
    return soma;
}

int saoAmigos(int a, int b) {
    int somaA = somaDivisoresProprios(a);
    int somaB = somaDivisoresProprios(b);
    
    return (somaA == b && somaB == a);
}

int saoColegas(int a, int b) {
    int somaA = somaDivisoresProprios(a);
    int somaB = somaDivisoresProprios(b);
    
    return (abs(somaA - b) <= 2 && abs(somaB - a) <= 2);
}

int main() {
    int num1, num2;
    
    printf("PROGRAMA PARA VERIFICAR NÚMEROS COLEGAS\n\n");
    
    printf("Digite dois números inteiros diferentes: ");
    scanf("%d %d", &num1, &num2);
    
    if (num1 == num2) {
        printf("Por favor, digite números diferentes.\n");
        return 1;
    }
    
    int soma1 = somaDivisoresProprios(num1);
    int soma2 = somaDivisoresProprios(num2);
    
    printf("\n RESULTADOS\n");
    printf("Soma dos divisores próprios de %d: %d\n", num1, soma1);
    printf("Soma dos divisores próprios de %d: %d\n", num2, soma2);
    
    if (saoAmigos(num1, num2)) {
        printf("\nOs números %d e %d são AMIGOS!\n", num1, num2);
        printf("(A soma dos divisores de cada um é igual ao outro número)\n");
    }
    
    if (saoColegas(num1, num2)) {
        printf("\nRESULTADO: S - Os números %d e %d são COLEGAS!\n", num1, num2);
        printf("Diferença entre soma(%d) e %d: %d\n", num1, num2, abs(soma1 - num2));
        printf("Diferença entre soma(%d) e %d: %d\n", num2, num1, abs(soma2 - num1));
        printf("Ambas as diferenças são <= 2\n");
    } else {
        printf("\nRESULTADO: N - Os números %d e %d NÃO são colegas.\n", num1, num2);
        printf("Diferença entre soma(%d) e %d: %d\n", num1, num2, abs(soma1 - num2));
        printf("Diferença entre soma(%d) e %d: %d\n", num2, num1, abs(soma2 - num1));
        printf("Pelo menos uma das diferenças é > 2\n");
    }
    
    return 0;
}

void mostrarDivisores(int n) {
    printf("Divisores próprios de %d: ", n);
    if (n == 1) {
        printf("(nenhum)\n");
        return;
    }
    
    printf("1");
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            printf(", %d", i);
            if (i != n / i) {
                printf(", %d", n / i);
            }
        }
    }
    printf("\n");
}
