#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, i, j;
    int colecao_completa[1001];
    int figurinhas_possuidas[1001];
    int faltantes[1001];
    int num_faltantes = 0;
    int encontrou;
    
    printf("IDENTIFICADOR DE FIGURINHAS FALTANTES:\n");
    printf("Álbum de Figurinhas dos Desenhos dos Anos 2000\n\n");
    
    printf("Digite a quantidade total de figurinhas da coleção (máximo 1000): ");
    scanf("%d", &m);
    
    if (m <= 0 || m > 1000) {
        printf("Erro: A quantidade deve estar entre 1 e 1000.\n");
        return 1;
    }
    
    printf("\nDigite os números das %d figurinhas da coleção completa:\n", m);
    for (i = 0; i < m; i++) {
        printf("Figurinha %d: ", i + 1);
        scanf("%d", &colecao_completa[i]);
    }
    
    printf("\nDigite a quantidade de figurinhas que você possui: ");
    scanf("%d", &n);
    
    if (n < 0 || n > m) {
        printf("Erro: A quantidade deve estar entre 0 e %d.\n", m);
        return 1;
    }
    
    if (n > 0) {
        printf("\nDigite os números das %d figurinhas que você possui:\n", n);
        for (i = 0; i < n; i++) {
            printf("Figurinha %d: ", i + 1);
            scanf("%d", &figurinhas_possuidas[i]);
        }
    }
    
    printf("\nANÁLISE DA COLEÇÃO\n");
    
    for (i = 0; i < m; i++) {
        encontrou = 0;
        
        for (j = 0; j < n; j++) {
            if (colecao_completa[i] == figurinhas_possuidas[j]) {
                encontrou = 1;
                break;
            }
        }
        
        if (!encontrou) {
            faltantes[num_faltantes] = colecao_completa[i];
            num_faltantes++;
        }
    }
    
    for (i = 0; i < num_faltantes - 1; i++) {
        for (j = 0; j < num_faltantes - i - 1; j++) {
            if (faltantes[j] > faltantes[j + 1]) {
                int temp = faltantes[j];
                faltantes[j] = faltantes[j + 1];
                faltantes[j + 1] = temp;
            }
        }
    }
    
    printf("Você possui: %d figurinhas de %d total\n", n, m);
    printf("Figurinhas faltantes: %d\n\n", num_faltantes);
    
    if (num_faltantes == 0) {
        printf("PARABÉNS! Sua coleção está completa!\n");
        printf("Você tem todas as figurinhas de Billy, Mandy, Du, Dudu, Edu e todos os outros!\n");
    } else {
        printf("Figurinhas que estão faltando (em ordem crescente):\n");
        for (i = 0; i < num_faltantes; i++) {
            printf("%d", faltantes[i]);
            if (i < num_faltantes - 1) {
                printf(" ");
            }
        }
        printf("\n\n");
        
        float percentual_completo = ((float)(m - num_faltantes) / m) * 100;
        printf("Progresso da coleção: %.1f%% completa\n", percentual_completo);
        
        if (percentual_completo >= 90) {
            printf("Quase lá! Faltam poucas figurinhas!\n");
        } else if (percentual_completo >= 50) {
            printf("Bom progresso! Continue coletando!\n");
        } else {
            printf("Ainda há muito para colecionar! Não desista!\n");
        }
    }
    
    char opcao;
    printf("\nDeseja analisar outra coleção? (s/n): ");
    scanf(" %c", &opcao);
    
    if (opcao == 's' || opcao == 'S') {
        system("clear || cls");
        main();
    }
    return 0;
}