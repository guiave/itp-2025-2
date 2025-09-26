#include <stdio.h>
#include <math.h>

double calcularAltura(double x, double y) {
    return sin(cos(y)) + x + cos(y + sin(x));
}

int ehPontoSeguro(double x, double y) {
    double altura_centro = calcularAltura(x, y);
    
    double pontos_vizinhos[4][2] = {
        {x + 0.2, y + 0.2}, 
        {x - 0.2, y + 0.2},
        {x + 0.2, y - 0.2},
        {x - 0.2, y - 0.2}
    };
    
    for (int i = 0; i < 4; i++) {
        double altura_vizinho = calcularAltura(pontos_vizinhos[i][0], pontos_vizinhos[i][1]);
        
        if (fabs(altura_centro - altura_vizinho) > 2.0) {
            return 0;
        }
    }
    
    return 1; 
}

char* classificarLocal(double x, double y) {
    if (!ehPontoSeguro(x, y)) {
        return "inseguro";
    }
    
    double pontos_vizinhos[4][2] = {
        {x + 0.2, y + 0.2},
        {x - 0.2, y + 0.2},
        {x + 0.2, y - 0.2},
        {x - 0.2, y - 0.2} 
    };
    
    int pontos_seguros = 0;
    for (int i = 0; i < 4; i++) {
        if (ehPontoSeguro(pontos_vizinhos[i][0], pontos_vizinhos[i][1])) {
            pontos_seguros++;
        }
    }
    
    if (pontos_seguros == 0) {
        return "troque de coordenada";
    } else if (pontos_seguros >= 1 && pontos_seguros <= 2) {
        return "relativamente seguro";
    } else {
        return "seguro";
    }
}

int main() {
    printf("SISTEMA DE CLASSIFICAÇÃO DE POUSO - SONDA DE SATURNO\n\n");
    printf("Função de altura: f(x,y) = sin(cos(y)) + x + cos(y + sin(x))\n");
    printf("Critério de segurança: diferença de altura ≤ 2 entre pontos vizinhos\n\n");
    
    double x, y;
    char continuar;
    
    do {
        printf("Digite as coordenadas do ponto de pouso (x y): ");
        scanf("%lf %lf", &x, &y);
        
        double altura = calcularAltura(x, y);
        
        char* classificacao = classificarLocal(x, y);
        
        printf("\nRESULTADO DA ANÁLISE\n");
        printf("Coordenadas: (%.2f, %.2f)\n", x, y);
        printf("Altura do terreno: %.6f\n", altura);
        printf("Classificação: %s\n", classificacao);
        
        if (strcmp(classificacao, "inseguro") == 0) {
            printf("⚠️  ATENÇÃO: Local apresenta variações de altura > 2 unidades!\n");
        } else if (strcmp(classificacao, "troque de coordenada") == 0) {
            printf("🔄 Recomendação: Busque coordenadas alternativas.\n");
        } else if (strcmp(classificacao, "relativamente seguro") == 0) {
            printf("⚡ Status: Pouso possível com precauções.\n");
        } else {
            printf("✅ Status: Local ideal para pouso!\n");
        }
        
        printf("\nDeseja analisar outro ponto? (s/n): ");
        scanf(" %c", &continuar);
        printf("\n");
        
    } while (continuar == 's' || continuar == 'S');
    
    printf("TESTE COM EXEMPLOS DO PROBLEMA\n\n");
    
    double exemplos[][2] = {
        {0.0, 0.0},
        {3.1, 4.2},
        {8.4, 4.8}
    };
    
    for (int i = 0; i < 3; i++) {
        double ex_x = exemplos[i][0];
        double ex_y = exemplos[i][1];
        char* ex_class = classificarLocal(ex_x, ex_y);
        
        printf("Coordenadas: (%.1f, %.1f) -> %s\n", ex_x, ex_y, ex_class);
    }
    
    printf("\nAnálise concluída. Missão segura! \n");
    
    return 0;
};