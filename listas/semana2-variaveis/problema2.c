/*Desenvolva um programa que leia uma temperatura em graus Celsius e converta para Fahrenheit e Kelvin.
Use variáveis do tipo float e exiba os resultados com 1 casa decimal.
Fórmulas:
Fahrenheit = (Celsius × 9/5) + 32
Kelvin = Celsius + 273.15*/

#include <stdio.h>
int main(){
    float celsius = 0;
    float fahrenheit = 0;
    float kelvin = 0;
    
    printf("Digite a temperatura em Celsius no qual queres converter em Fahrenheit e Kelvin (apenas o número, sem espaços): ");
    scanf("%f", &celsius);
    
    fahrenheit = (celsius * 9/5) + 32;
    kelvin = celsius + 273.15;
    
    printf("%.1fºC em Fahrenheit: %.1fºF\n", celsius, fahrenheit);
    printf("%.1fºK em Kelvin: %.1fºK", celsius, kelvin);
}
