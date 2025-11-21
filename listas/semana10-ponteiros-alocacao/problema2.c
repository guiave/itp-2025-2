#include <stdio.h>
#include <stdlib.h>

int* buscaNoVetor(int *v, int n, int valor, int *qtd) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            count++;
        }
    }

    *qtd = count;

    if (count == 0) {
        return NULL;
    }

    int *indices = (int *) malloc(count * sizeof(int));
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            indices[j] = i;
            j++;
        }
    }

    return indices;
}

int main() {
    int n;
    int *vetor;

    printf("Digite a quantidade de elementos do vetor (ex: 5): ");
    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    printf("Digite os %d elementos do vetor (ex: 2 5 2 2 1): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    int valor_buscado;
    printf("Digite o valor a ser buscado (ex: 2): ");
    scanf("%d", &valor_buscado);

    int qtd_ocorrencias;
    int *indices_resultado;

    indices_resultado = buscaNoVetor(vetor, n, valor_buscado, &qtd_ocorrencias);

    if (indices_resultado == NULL) {
        printf("Nenhuma ocorrencia\n");
    } else {
        printf("Quantidade de ocorrencias: %d\n", qtd_ocorrencias);
        printf("Indices: ");
        for (int i = 0; i < qtd_ocorrencias; i++) {
            printf("%d ", indices_resultado[i]);
        }
        printf("\n");
        free(indices_resultado);
    }
    
    free(vetor);

    return 0;
}