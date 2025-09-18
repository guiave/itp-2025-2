#include <stdio.h>

int main(){
    int kWh = 0;
    char consu;
    float R, C, I = 0;
    
    printf("Oi, quantos kWh foram consumidos? ");
    scanf("%d", &kWh);
    
    printf("Você faz parte de que tipo de consumidor? (R para residencial, C para comercial, I para industrial) ");
    scanf(" %c", &consu);
    
    R = 0.6*kWh + 15;
    C = 0.48*kWh + 15;
    I = 1.29*kWh + 15;
    if(consu == 'R' || consu == 'r'){
        printf("O valor total da conta calculado é de R$%.2f.", R);
    }
    if(consu == 'C' || consu == 'c'){
        printf("O valor total da conta calculado é de R$%.2f.", C);
    }
    if(consu == 'I' || consu == 'i'){
        printf("O valor total da conta calculado é de R$%.2f.", I);
    }
}
