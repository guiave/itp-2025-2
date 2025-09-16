#include <stdio.h>
#include <math.h>
int main(){
    float p, a;
    printf("Qual é o seu peso (kg): ");
    scanf("%f", &p);
    printf("Qual é a sua altura (m) (ao invés de vírgula, utilize ponto, por favor): ");
    scanf("%f", &a);
    float IMC = p/pow(a,2);
    if(IMC > 30){
        printf("Você está obeso.");
    }
    else if(IMC >= 25){
        printf("Você está com sobrepeso.");
    }
    else if(IMC >= 18.5){
        printf("Você está com peso normal :)");
    }
    else{
        printf("Você está abaixo do peso");
    }
}
