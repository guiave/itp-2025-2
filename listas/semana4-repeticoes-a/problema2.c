#include <stdio.h>
#include <math.h>

int main() {
    double xa, ya;
    double xh, yh;
    double comprimento_teia;
    
    printf("Digite a coordenada inicial da aranha (xa ya): ");
    scanf("%lf %lf", &xa, &ya);
    
    printf("Digite o comprimento máximo da teia: ");
    scanf("%lf", &comprimento_teia);
    
    printf("Digite a coordenada do alvo (xh yh): ");
    scanf("%lf %lf", &xh, &yh);
    
    double distancia = sqrt(pow(xh - xa, 2) + pow(yh - ya, 2));
    
    printf("\n RESULTADO:\n");
    printf("Posição inicial da aranha: (%.2f, %.2f)\n", xa, ya);
    printf("Posição do alvo: (%.2f, %.2f)\n", xh, yh);
    printf("Comprimento máximo da teia: %.2f\n", comprimento_teia);
    printf("Distância até o alvo: %.2f\n", distancia);
    
    if (distancia <= comprimento_teia) {
        printf("RESULTADO: A aranha PODE alcançar o alvo!\n");
        
        printf("Nova coordenada da aranha: (%.2f, %.2f)\n", xh, yh);
    } else {
        printf("RESULTADO: A aranha NÃO pode alcançar o alvo!\n");

        double dx = xh - xa;
        double dy = yh - ya;
        double norma = sqrt(dx*dx + dy*dy);
        
        dx = dx / norma;
        dy = dy / norma;
        
        double xf = xa + dx * comprimento_teia;
        double yf = ya + dy * comprimento_teia;
        
        printf("Nova coordenada da aranha (máximo alcançável): (%.2f, %.2f)\n", xf, yf);
        printf("Distância restante até o alvo: %.2f\n", distancia - comprimento_teia);
    }
    
    return 0;
}
