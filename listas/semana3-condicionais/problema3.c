#include <stdio.h>

int main(){
    float a, b, c, d, e = 0;
    printf("Oi, qual foi a primeira nota? ");
    scanf("%f", &a);
    printf("Oi, qual foi a segunda nota? ");
    scanf("%f", &b);
    printf("Oi, qual foi a terceira nota? ");
    scanf("%f", &c);;

d = (a + b + c)/3;
e = 10 - d;

if (d >= 7){
    printf("Parabéns, foi aprovado!");
}
else if (d >= 4){
    printf("Infelizmente você está de recuperação. Assim, na prova final, você deve tirar, no mínimo, a nota de %.1f. Boa sorte!", e);
}
else{
    printf("Infelizmente você foi reprovado. Boa sorte no próximo ano!");
}
}
