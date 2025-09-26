#include <stdio.h>
#include <stdbool.h>

#define MAX_ILHAS 10

int main() {
    int sugestoes[MAX_ILHAS];
    bool visitado[MAX_ILHAS] = {false};
    int ilha_atual, proxima_ilha;
    int primeira_repetida = -1;
    
    printf("CACADOR DE TESOUROS - CHEQUE ESPERTO:\n");
    printf("Digite as sugestoes dos nativos para as 10 ilhas (0 a 9):\n");
    printf("(Cada numero representa para qual ilha o nativo da ilha atual aponta)\n\n");
    
    for (int i = 0; i < MAX_ILHAS; i++) {
        printf("Sugestao do nativo da ilha %d: ", i);
        scanf("%d", &sugestoes[i]);
        
        if (sugestoes[i] < 0 || sugestoes[i] >= MAX_ILHAS) {
            printf("Erro: A sugestao deve ser um numero entre 0 e 9.\n");
            i--;
            continue;
        }
    }
    
    printf("\nMAPA DAS SUGESTOES:\n");
    for (int i = 0; i < MAX_ILHAS; i++) {
        printf("Ilha %d -> Ilha %d\n", i, sugestoes[i]);
    }
    
    printf("\nCAMINHO DO PIRATA:\n");
    
    ilha_atual = 0;
    printf("Cheque Esperto comeca na ilha %d\n", ilha_atual);
    
    while (true) {
        if (visitado[ilha_atual]) {
            primeira_repetida = ilha_atual;
            printf("Ilha %d ja foi visitada anteriormente!\n", ilha_atual);
            printf("*** TESOURO ENCONTRADO NA ILHA %d! ***\n", primeira_repetida);
            break;
        }
        
        visitado[ilha_atual] = true;
        printf("Visitando ilha %d (primeira vez)\n", ilha_atual);
        
        proxima_ilha = sugestoes[ilha_atual];
        printf("Nativo da ilha %d sugere ir para a ilha %d\n", ilha_atual, proxima_ilha);
        
        ilha_atual = proxima_ilha;
        printf("Navegando para a ilha %d...\n\n", ilha_atual);
    }
    
    printf("\nRESULTADO FINAL:\n");
    printf("A primeira ilha visitada uma segunda vez foi: %d\n", primeira_repetida);
    printf("O tesouro esta na ilha: %d\n", primeira_repetida);
    
    printf("\nCAMINHO COMPLETO:\n");
    printf("Caminho percorrido: ");
    
    bool temp_visitado[MAX_ILHAS] = {false};
    int temp_ilha = 0;
    
    while (!temp_visitado[temp_ilha]) {
        printf("%d -> ", temp_ilha);
        temp_visitado[temp_ilha] = true;
        temp_ilha = sugestoes[temp_ilha];
    }
    printf("%d (TESOURO!)\n", temp_ilha);
    
    return 0;
}