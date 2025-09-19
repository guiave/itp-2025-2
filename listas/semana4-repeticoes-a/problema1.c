#include <stdio.h>

int main(){
float comprimento, largura_p, largura_b;
int dobras = 1;

    printf("Qual o comprimento inicial do papel? ");
    scanf("%f", &comprimento);
    printf("Qual a largura inicial do papel? ");
    scanf("%f", &largura_p);
    printf("Qual a largura inicial do bolso? ");
    scanf("%f", &largura_b);
    
    while(comprimento >= largura_b && largura_p >= largura_b){
        if(comprimento > largura_p){
            comprimento = comprimento / 2;
        }
        else{
            largura_p = largura_p / 2;
        }
    printf(" \n\nDobra: %d\nComprimento: %.2f\nLargura: %.2f \n\n", dobras, comprimento, largura_p);
    dobras++;
    }
}
