#include <stdio.h>
#include <stdlib.h>

#define MAX_N 30
#define MAX_COL 100

int main() {
    int n, i, j;
    int terreno[MAX_N][MAX_COL];
    int num_colunas = 0;
    int altura_maxima_esquerda = 0, altura_maxima_direita = 0;
    int pos_esquerda = -1, pos_direita = -1;
    int comprimento_ponte;
    
    printf("CALCULADORA DE PONTE:\n");
    printf("Digite o numero de linhas do terreno (maximo %d): ", MAX_N);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_N) {
        printf("Erro: Numero de linhas deve estar entre 1 e %d\n", MAX_N);
        return 1;
    }
    
    printf("\nDigite as linhas do terreno (uma linha por vez):\n");
    printf("(Digite apenas um numero por linha - a altura naquela posicao)\n");
    
    for (i = 0; i < n; i++) {
        printf("Altura da posicao %d: ", i + 1);
        scanf("%d", &terreno[0][i]);
    }
    
    num_colunas = n;
    
    for (j = 0; j < num_colunas; j++) {
        if (terreno[0][j] > altura_maxima_esquerda) {
            altura_maxima_esquerda = terreno[0][j];
            pos_esquerda = j;
        }
    }
    
    for (j = 0; j < num_colunas; j++) {
        if (j != pos_esquerda && terreno[0][j] > altura_maxima_direita) {
            altura_maxima_direita = terreno[0][j];
            pos_direita = j;
        }
    }
    
    if (altura_maxima_direita == altura_maxima_esquerda) {
        
        for (j = 0; j < num_colunas; j++) {
            if (terreno[0][j] == altura_maxima_esquerda) {
                pos_esquerda = j;
                break;
            }
        }
        
        for (j = num_colunas - 1; j >= 0; j--) {
            if (terreno[0][j] == altura_maxima_esquerda && j != pos_esquerda) {
                pos_direita = j;
                break;
            }
        }
    }
    
    if (pos_esquerda > pos_direita) {
        int temp = pos_esquerda;
        pos_esquerda = pos_direita;
        pos_direita = temp;
        
        temp = altura_maxima_esquerda;
        altura_maxima_esquerda = altura_maxima_direita;
        altura_maxima_direita = temp;
    }
    
    if (pos_esquerda != -1 && pos_direita != -1 && pos_esquerda != pos_direita) {
        comprimento_ponte = pos_direita - pos_esquerda - 1;
        if (comprimento_ponte < 0) comprimento_ponte = 0;
    } else {
        comprimento_ponte = 0;
    }
    
    printf("\nRESULTADOS:\n");
    printf("Terreno analisado:\n");
    printf("Posicoes: ");
    for (j = 0; j < num_colunas; j++) {
        printf("%2d ", j + 1);
    }
    printf("\nAlturas:  ");
    for (j = 0; j < num_colunas; j++) {
        printf("%2d ", terreno[0][j]);
    }
    printf("\n");
    
    if (pos_esquerda != -1 && pos_direita != -1 && pos_esquerda != pos_direita) {
        printf("\nPonto de ancoragem esquerdo: posicao %d (altura %d)\n",
               pos_esquerda + 1, altura_maxima_esquerda);
        printf("Ponto de ancoragem direito: posicao %d (altura %d)\n",
               pos_direita + 1, altura_maxima_direita);
        printf("\nComprimento minimo da ponte: %d unidades\n", comprimento_ponte);
        
        if (comprimento_ponte > 0) {
            printf("A ponte conectara as posicoes %d e %d, passando sobre %d posicoes intermediarias.\n",
                   pos_esquerda + 1, pos_direita + 1, comprimento_ponte);
        } else {
            printf("As posicoes estao adjacentes, nao eh necessaria ponte.\n");
        }
    } else {
        printf("\nNao foi possivel determinar dois pontos distintos para a ponte.\n");
        printf("Comprimento da ponte: %d\n", comprimento_ponte);
    }
    
    return 0;
}