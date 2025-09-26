#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    int gabarito[21];
    int respostas[21];
    int acertos = 0;
    
    printf("CORRETOR AUTOMÁTICO DE PROVAS ENEM\n\n");
    
    printf("Digite o número de questões (1 a 20): ");
    scanf("%d", &n);
    
    if (n < 1 || n > 20) {
        printf("Erro: O número de questões deve estar entre 1 e 20.\n");
        return 1;
    }
    
    printf("\nENTRADA DO GABARITO\n");
    printf("Digite o gabarito (alternativas de 1 a 5):\n");
    for (i = 1; i <= n; i++) {
        printf("Questão %d: ", i);
        scanf("%d", &gabarito[i]);
        
        if (gabarito[i] < 1 || gabarito[i] > 5) {
            printf("Erro: Alternativa deve estar entre 1 e 5.\n");
            i--;
        }
    }
    
    printf("\nENTRADA DAS RESPOSTAS DO ALUNO\n");
    printf("Digite as respostas do aluno (alternativas de 1 a 5):\n");
    for (i = 1; i <= n; i++) {
        printf("Questão %d: ", i);
        scanf("%d", &respostas[i]);
        
        if (respostas[i] < 1 || respostas[i] > 5) {
            printf("Erro: Alternativa deve estar entre 1 e 5.\n");
            i--;
        }
    }
    
    printf("\nCORREÇÃO DA PROVA\n");
    for (i = 1; i <= n; i++) {
        if (gabarito[i] == respostas[i]) {
            acertos++;
            printf("Questão %2d: CORRETA (Gabarito: %d, Resposta: %d)\n",
                       i, gabarito[i], respostas[i]);
        } else {
            printf("Questão %2d: ERRADA  (Gabarito: %d, Resposta: %d)\n",
                       i, gabarito[i], respostas[i]);
        }
    }
    
    printf("\nRESULTADO FINAL\n");
    if (acertos == 1) {
        printf("Resultado: %d acerto\n", acertos);
    } else {
        printf("Resultado: %d acertos\n", acertos);
    }
    
    printf("Aproveitamento: %.1f%% (%d de %d questões)\n",
               (float)acertos * 100.0 / n, acertos, n);
    
    char opcao;
    printf("\nDeseja corrigir outra prova? (s/n): ");
    scanf(" %c", &opcao);
    
    if (opcao == 's' || opcao == 'S') {
        system("clear || cls");
        main();
    }
    
    printf("\nPrograma finalizado. Obrigado por usar o Corretor ENEM!\n");
    return 0;
}