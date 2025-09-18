#include <stdio.h>
int main(){
    float vista = 0;
    printf("Oi, qual o valor da sua compra? ");
    scanf("%f", &vista);
    
    if(vista >= 1000){
        printf("\n Valor original: R$%.2f \n Valor do desconto: R$%.2f \n Valor final: R$%.2f \n", vista, vista*0.2, vista*0.8);
    }
    else if(vista >= 500.01){
        printf("\n Valor original: R$%.2f \n Valor do desconto: R$%.2f \n Valor final: R$%.2f \n", vista, vista*0.15, vista*0.85);}
    else if(vista >= 100.01){
        printf("\n Valor original: R$%.2f \n Valor do desconto: R$%.2f \n Valor final: R$%.2f \n", vista, vista*0.1, vista*0.9);}
    else{
        printf("\n Valor original: R$%.2f \n (Sem desconto, pois o valor da compra é menor que R$100.)", vista);
    }
}
