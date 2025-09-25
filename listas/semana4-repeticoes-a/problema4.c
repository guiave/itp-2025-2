#include <stdio.h>
#include <math.h>

double calcularDistancia(double x, double y) {
    return sqrt(x * x + y * y);
}

int pontuacaoPrincipal(double distancia) {
    if (distancia <= 1.0) {
        return 10;
    } else if (distancia <= 2.0) {
        return 6;
    } else if (distancia <= 3.0) {
        return 4;
    } else {
        return 0;
    }
}

int pontuacaoBonus(double distancia) {
    if (distancia <= 1.0) {
        return 5;
    } else if (distancia <= 2.0) {
        return 3;
    } else if (distancia <= 3.0) {
        return 2;
    } else {
        return 0;
    }
}

int estaMaisProximo(double distanciaAtual, double distanciaAnterior) {
    return distanciaAtual < distanciaAnterior;
}

int main() {
    double x, y;
    double distancia;
    int pontosPrincipal, pontosBonus, pontosTotal = 0;
    double menorDistancia = -1;
    int lancamento;
    
    printf("JOGO DE DARDOS: \n");
    printf("Centro do alvo: (0, 0)\n");
    printf("Tabela de pontuação:\n");
    printf("Distância [0, 1]: 10 pts principais + 5 pts bônus\n");
    printf("Distância ]1, 2]: 6 pts principais + 3 pts bônus\n");
    printf("Distância ]2, 3]: 4 pts principais + 2 pts bônus\n");
    printf("Distância > 3: 0 pts\n\n");
    
    printf("Regras especiais:\n");
    printf("- Bônus: ganho quando acerta mais perto que o último lançamento\n");
    printf("- Não há bônus no primeiro lançamento\n\n");
    printf("- Será 10 lançamentos. \n\n");
    
    for (lancamento = 1; lancamento <= 10; lancamento++) {
        printf("Lançamento %d - Digite as coordenadas (x y): ", lancamento);
        scanf("%lf %lf", &x, &y);
        
        distancia = calcularDistancia(x, y);
        
        pontosPrincipal = pontuacaoPrincipal(distancia);
        
        pontosBonus = 0;
        if (lancamento > 1 && estaMaisProximo(distancia, menorDistancia)) {
            pontosBonus = pontuacaoBonus(distancia);
        }
        
        if (menorDistancia == -1 || distancia < menorDistancia) {
            menorDistancia = distancia;
        }
        
        pontosTotal += pontosPrincipal + pontosBonus;
        
        printf("  Coordenadas: (%.2f, %.2f)\n", x, y);
        printf("  Distância do centro: %.3f\n", distancia);
        printf("  Pontos principais: %d\n", pontosPrincipal);
        
        if (lancamento == 1) {
            printf("  Pontos bônus: 0 (primeiro lançamento)\n");
        } else {
            if (pontosBonus > 0) {
                printf("  Pontos bônus: %d (mais próximo que o anterior!)\n", pontosBonus);
            } else {
                printf("  Pontos bônus: 0 (não melhorou a precisão)\n");
            }
        }
        
        printf("  Total do lançamento: %d pontos\n", pontosPrincipal + pontosBonus);
        printf("  Pontuação acumulada: %d pontos\n", pontosTotal);
        
        if (distancia == 0.0) {
            printf("  *** ACERTOU NO CENTRO! ***\n");
        }
        
        printf("\n");
    }
    
    printf("RESULTADO FINAL: \n");
    printf("Pontuação total após 10 lançamentos: %d pontos\n\n", pontosTotal);
    
    if (pontosTotal >= 90) {
        printf("Desempenho: EXCELENTE! 🎯\n");
    } else if (pontosTotal >= 70) {
        printf("Desempenho: MUITO BOM! 👍\n");
    } else if (pontosTotal >= 50) {
        printf("Desempenho: BOM 👌\n");
    } else if (pontosTotal >= 30) {
        printf("Desempenho: REGULAR 😐\n");
    } else {
        printf("Desempenho: PRECISA TREINAR MAIS 😅\n");
    }
    
    return 0;
}


void exemploCalculo() {
    printf("\n EXEMPLOS DE CÁLCULO: \n");
    

    printf("Lançamento em (0, 0):\n");
    printf("  Distância = 0.000\n");
    printf("  Pontos = 10 + 0 (sem bônus no 1º) = 10\n\n");
    

    printf("Lançamento em (0.5, 0.5):\n");
    printf("  Distância = %.3f\n", sqrt(0.5*0.5 + 0.5*0.5));
    printf("  Pontos = 10 + bônus(se melhor) = 10 + 5 = 15\n\n");
    

    printf("Lançamento em (1.5, 1.5):\n");
    printf("  Distância = %.3f\n", sqrt(1.5*1.5 + 1.5*1.5));
    printf("  Pontos = 6 + bônus(se melhor) = 6 + 3 = 9\n\n");
    

    printf("Lançamento em (2.5, 1.5):\n");
    printf("  Distância = %.3f\n", sqrt(2.5*2.5 + 1.5*1.5));
    printf("  Pontos = 4 + bônus(se melhor) = 4 + 2 = 6\n\n");
}
