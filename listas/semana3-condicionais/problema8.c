#include <stdio.h>
#include <math.h>

int main(){
    int a = 0, b = 0, c = 0;
    printf("Digite o primeiro lado: ");
    scanf("%d", &a);
    printf("Digite o segundo lado: ");
    scanf("%d", &b);
    printf("Digite o terceiro lado: ");
    scanf("%d", &c);

    if(a >= b + c || b >= a + c || c >= a + b){
        printf("Não é um triângulo. Digite os lados corretamente.");
        return 1;
    }

    if(a == b && b == c){
        printf("\n\nEste triângulo é equilátero");
    } else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a)){
        printf("\n\nEste triângulo é isósceles");
    } else {
        printf("\n\nEste triângulo é escaleno");
    }

    if(a >= b && a >= c){
        if(a * a == b * b + c * c){
            printf(" e retângulo.");
        } else if(a * a > b * b + c * c){
            printf(" e obtusângulo.");
        } else {
            printf(" e acutângulo.");
        }
    } else if(b >= a && b >= c){
        if(b * b == a * a + c * c){
            printf(" e retângulo.");
        } else if(b * b > a * a + c * c){
            printf(" e obtusângulo.");
        } else {
            printf(" e acutângulo.");
        }
    } else if(c >= b && c >= a){
        if(c * c == b * b + a * a){
            printf(" e retângulo.");
        } else if(c * c > b * b + a * a){
            printf(" e obtusângulo.");
        } else {
            printf(" e acutângulo.");
        }
    }
}
