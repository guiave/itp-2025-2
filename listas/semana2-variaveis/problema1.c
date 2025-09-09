/*Crie um programa que leia o peso (em kg) e a altura (em metros) de uma pessoa e calcule seu Índice de
Massa Corporal (IMC). O programa deve declarar todas as variáveis com tipos apropriados (float) e exibir o
resultado com 2 casas decimais.
Fórmula: IMC = peso / (altura²)*/

#include <stdio.h>

int main(){
    float peso = 0;
    float altura = 0;
    float IMC = 0;
    
    printf("Qual o seu peso? ");
    scanf("%f", &peso);
    printf("Qual é a sua altura em metros? ");
    scanf("%f", &altura);
    
    IMC = peso / (altura*altura);
    
    printf("O seu IMC é de %.2f.", IMC);
}
