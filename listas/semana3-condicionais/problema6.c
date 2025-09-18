#include <stdio.h>
int main(){
char febre, cabeca, corpo, tosse;
    printf("Olá, você tem febre? (Digite 'S' ou 'N') ");
    scanf(" %c", &febre);
    printf("Dor de cabeça? ");
    scanf(" %c", &cabeca);
    printf("Dor no corpo? ");
    scanf(" %c", &corpo);
    printf("Tosse? ");
    scanf(" %c", &tosse);
    
if (febre == 'S' && cabeca == 'S' && corpo == 'S'){
    printf("Você tem possível gripe.");}
else if(tosse == 'S' && febre == 'S' && cabeca == 'N' && corpo == 'N'){
    printf("Você tem possível resfriado.");}
else if(cabeca == 'S' && febre == 'N' && corpo == 'N' && tosse == 'N'){
    printf("Você tem possível enxaqueca.");}
else if(febre == 'S' && cabeca == 'N' && corpo == 'N' && tosse == 'N'){
    printf("Você necessita ir ao médico.");}
else if(febre == 'N' && cabeca == 'N' && corpo == 'N' && tosse == 'N'){
    printf("Você aparentemente está bem.");}
else{
    printf("Procure um médico para avaliação.");}
}
