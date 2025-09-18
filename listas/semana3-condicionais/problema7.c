#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    float d_mais, d_menos, det;
    printf("Bem-vindo ao sistema que soluciona equações do segundo grau para você ;)\n Digite o termo 'a' da equação: ");
    scanf("%d", &a);
    if(a == 0){
        printf("Equação inválida. 'a' não pode ser igual a zero.");
    return 1;}
    printf("Digite o termo 'b' da equação: ");
    scanf("%d", &b);
    printf("Digite o termo 'c' da equação: ");
    scanf("%d", &c);
    
det = pow(b,2)-(4*a*c);
d_mais = (-b+sqrt(det))/(2*a);
d_menos = (-b-sqrt(det))/(2*a);

if(det>0){
    printf("\nA equação fornecida tem duas raizes:\n");
    printf("A raiz 1 é %.2f\n", d_mais);
    printf("A raiz 2 é %.2f\n", d_menos);
    printf("O discriminante é %.2f", det);
}
else if(det == 0){
    printf("\nA equação fornecida tem uma raiz real:\n");
    printf("A raiz é %.2f\n", d_mais);
    printf("O discriminante é %.2f", det);
}
else{
    printf("\nA equação fornecida não tem raiz real\n");
}
}
