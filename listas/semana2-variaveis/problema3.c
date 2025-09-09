/*Escreva um programa que leia o capital inicial, a taxa de juros (em porcentagem) e o tempo (em anos).
Calcule e exiba o montante final usando a fórmula de juros compostos. Declare as variáveis com tipos
apropriados.
Fórmula: Montante = Capital × (1 + taxa/100)^tempo
Dica: Use a função pow() da biblioteca math.h
*/

#include <stdio.h>
#include <math.h>
int main(){
    float M = 0;
    float c = 0;
    int porcento = 0;
    int tempo = 0;
    
    printf("Bem-vindo à calculadora de juros compostos! \n Para descobrir o montante, digite quanto é o capital inicial (sem a cifra (R$)): ");
    scanf("%f", &c);
    printf("Boa, agora quantos porcento ao ano? ");
    scanf("%d", &porcento);
    printf("Por quantos anos? ");
    scanf("%d", &tempo);
    
    M = c * pow(1 + porcento/100.0, tempo);
    
    printf("O seu montante total é de R$%.2f", M);
}
