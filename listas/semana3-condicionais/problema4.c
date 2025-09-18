#include <stdio.h>

int main(){
    char j1, j2;
    printf("Jogador 1, digite sua jogada \n [EM MAIÚSCULO] \n P = Pedra \n T = Tesoura \n A = Papel \n \n");
    scanf(" %c", &j1);

    printf("Jogador 2, digite sua jogada \n [EM MAIÚSCULO] \n P = Pedra \n T = Tesoura \n A = Papel \n \n");
    scanf(" %c", &j2);
    
    if(j1 == j2){
        printf("Empate técnico!");
    }
    if(j1 == 'P' && j2 == 'T' || j1 == 'T' && j2 == 'P'){
        if(j1 == 'P'){
            printf("O jogador 1 venceu.");
        }
        else{
            printf("O jogador 2 venceu.");
        }
    }
    
    if(j1 == 'T' && j2 == 'A' || j1 == 'A' && j2 == 'T'){
        if(j1 == 'T'){
            printf("O jogador 1 venceu.");
        }
        else{
            printf("O jogador 2 venceu.");
        }
    }
    
    if(j1 == 'A' && j2 == 'P' || j1 == 'P' && j2 == 'A'){
        if (j1 == 'A'){
            printf("O jogador 1 venceu.");}
        else{
            printf("O jogador 2 venceu.");
        }
    }
}
