#include <stdio.h>
#include <math.h>

int ehPrimo(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    printf("TRIOS DE PRIMOS (x, x+2, x+6) ATÉ 50000\n\n");
    
    int contador = 0;
    
    for (int x = 2; x <= 50000 - 6; x++) {
        if (ehPrimo(x) && ehPrimo(x + 2) && ehPrimo(x + 6)) {
            printf("(%d, %d, %d)\n", x, x + 2, x + 6);
            contador++;
        }
    }
    
    printf("\n=== ESTATÍSTICAS \n");
    printf("Total de trios encontrados: %d\n", contador);
    
    return 0;
}