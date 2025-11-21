#include <stdio.h>

int main() {
    char campo[21];
    int indice;
    int bombas = 0;

    printf("Digite o campo (max. 20 caracteres) e o indice separados por espaco (Ex: ..xx..x..x.. 0): ");
    scanf("%s %d", campo, &indice);

    if (campo[indice] == 'x') {
        printf("bum!\n");
    } else {
        if (indice > 0 && campo[indice - 1] == 'x') {
            bombas++;
        }
        if (campo[indice + 1] != '\0' && campo[indice + 1] == 'x') {
            bombas++;
        }
        printf("%d\n", bombas);
    }

    return 0;
}