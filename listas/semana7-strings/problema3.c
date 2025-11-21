#include <stdio.h>
#include <string.h>

int main() {
    char linha_inteira[1005];
    char nome_alvo[15];
    char* token;
    int total_aulas = 0;
    int presencas = 0;

    printf("Digite o nome do aluno e a lista de presenca na mesma linha (Ex: Priscila 02/04 Mateus Priscila Alberto 04/04 Mateus):\n");

    fgets(linha_inteira, 1005, stdin);

    token = strtok(linha_inteira, " \n");

    if (token != NULL) {
        strcpy(nome_alvo, token);
    } else {
        printf("0\n");
        return 0;
    }
    
    while ((token = strtok(NULL, " \n")) != NULL) {
        
        if (strchr(token, '/') != NULL) {
            total_aulas++;
        } else {
            if (strcmp(token, nome_alvo) == 0) {
                presencas++;
            }
        }
    }

    printf("%d\n", total_aulas - presencas);

    return 0;
}