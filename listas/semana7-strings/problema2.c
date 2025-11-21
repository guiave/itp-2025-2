#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[15];
    int len;
    int valido = 0;

    printf("Digite a placa (max. 10 caracteres, sem espacos) (Ex: ABC1D23 ou ABC-1234): ");
    scanf("%s", placa);
    len = strlen(placa);

    if (len == 8) {
        int padraoBR = 1;
        for (int i = 0; i < 3; i++) if (!isupper(placa[i])) padraoBR = 0;
        if (placa[3] != '-') padraoBR = 0;
        for (int i = 4; i < 8; i++) if (!isdigit(placa[i])) padraoBR = 0;
        
        if (padraoBR) {
            printf("brasileiro\n");
            valido = 1;
        }
    } 
    else if (len == 7) {
        int padraoMercosul = 1;
        for (int i = 0; i < 3; i++) if (!isupper(placa[i])) padraoMercosul = 0;
        if (!isdigit(placa[3])) padraoMercosul = 0;
        if (!isupper(placa[4])) padraoMercosul = 0;
        if (!isdigit(placa[5])) padraoMercosul = 0;
        if (!isdigit(placa[6])) padraoMercosul = 0;

        if (padraoMercosul) {
            printf("mercosul\n");
            valido = 1;
        }
    }

    if (!valido) {
        printf("invalido\n");
    }

    return 0;
}