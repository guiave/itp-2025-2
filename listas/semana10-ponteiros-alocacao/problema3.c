#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* misturar(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *resultado = (char *) malloc((len1 + len2 + 1) * sizeof(char));

    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        resultado[k++] = str1[i++];
        resultado[k++] = str2[j++];
    }

    while (i < len1) {
        resultado[k++] = str1[i++];
    }

    while (j < len2) {
        resultado[k++] = str2[j++];
    }

    resultado[k] = '\0';
    return resultado;
}

int main() {
    char str1[101];
    char str2[101];

    printf("Digite a primeira string (ex: teste): ");
    fgets(str1, 101, stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Digite a segunda string (ex: algo): ");
    fgets(str2, 101, stdin);
    str2[strcspn(str2, "\n")] = 0;

    char *resultado_mistura = misturar(str1, str2);

    printf("String misturada: %s\n", resultado_mistura);

    free(resultado_mistura);

    return 0;
}