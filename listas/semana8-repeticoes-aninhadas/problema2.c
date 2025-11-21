#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[15];
    int chuva;
} Mes;

int main() {
    Mes ano[12];
    
    strcpy(ano[0].nome, "Janeiro");
    strcpy(ano[1].nome, "Fevereiro");
    strcpy(ano[2].nome, "Marco");
    strcpy(ano[3].nome, "Abril");
    strcpy(ano[4].nome, "Maio");
    strcpy(ano[5].nome, "Junho");
    strcpy(ano[6].nome, "Julho");
    strcpy(ano[7].nome, "Agosto");
    strcpy(ano[8].nome, "Setembro");
    strcpy(ano[9].nome, "Outubro");
    strcpy(ano[10].nome, "Novembro");
    strcpy(ano[11].nome, "Dezembro");

    printf("Digite a quantidade de chuva para cada mes, de Janeiro a Dezembro (ex: 61 94 203 ... 25): ");
    for (int i = 0; i < 12; i++) {
        scanf("%d", &ano[i].chuva);
    }

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11 - i; j++) {
            if (ano[j].chuva < ano[j + 1].chuva) {
                Mes temp = ano[j];
                ano[j] = ano[j + 1];
                ano[j + 1] = temp;
            }
        }
    }

    printf("\nRanking de meses mais chuvosos:\n");
    for (int i = 0; i < 12; i++) {
        printf("%s %d\n", ano[i].nome, ano[i].chuva);
    }

    return 0;
}