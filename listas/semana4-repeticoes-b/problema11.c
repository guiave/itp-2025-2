#include <stdio.h>
#include <stdlib.h>

int main() {
    int c1, c2, c3, c4;
    int solucoes = 0;

    printf("Solucoes para o problema das 4 rainhas:\n");

    for (c1 = 1; c1 <= 4; c1++) {
        for (c2 = 1; c2 <= 4; c2++) {
            for (c3 = 1; c3 <= 4; c3++) {
                for (c4 = 1; c4 <= 4; c4++) {

                    if (c1 == c2 || c1 == c3 || c1 == c4 ||
                        c2 == c3 || c2 == c4 ||
                        c3 == c4) {
                        continue;
                    }


                    if (abs(1 - 2) == abs(c1 - c2) ||
                        abs(1 - 3) == abs(c1 - c3) ||
                        abs(1 - 4) == abs(c1 - c4) ||
                        abs(2 - 3) == abs(c2 - c3) ||
                        abs(2 - 4) == abs(c2 - c4) ||
                        abs(3 - 4) == abs(c3 - c4)) {
                        continue; 
                    }


                    solucoes++;
                    printf("\nSolucao #%d:\n", solucoes);
                    printf("Linha 1, Coluna %d\n", c1);
                    printf("Linha 2, Coluna %d\n", c2);
                    printf("Linha 3, Coluna %d\n", c3);
                    printf("Linha 4, Coluna %d\n", c4);
                }
            }
        }
    }
    return 0;
}