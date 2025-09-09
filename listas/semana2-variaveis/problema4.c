/*Crie um programa que leia dois números inteiros e exiba:
- A soma dos números
- A diferença (primeiro menos segundo)
- O produto
- A divisão real (resultado em float)
- O resto da divisão inteira
- A média aritmética
*/

#include <stdio.h>
int main(){
    int a, b, sum, sub, prod, rest;
    float divi, med;
    
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);
    
    sum = a + b;
    sub = a - b;
    prod = a * b;
    divi = a / b;
    rest = a % b;
    med = (a + b)/2;
    
    printf("A soma destes dois números é: %d\n", sum);
    printf("A subtração destes dois números é: %d\n", sub);
    printf("A multiplicação destes dois números é: %d\n", prod);
    printf("A divisão destes dois números é: %.2f\n", divi);
    printf("A resto destes dois números é: %d\n", rest);
    printf("A média aritmética destes dois números é: %.2f\n", med);
}
