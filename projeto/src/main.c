#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_HISTORICO 100
#define MAX_EXPRESSAO 256
#define PI 3.14159265359

// Estrutura para armazenar histórico da calculadora
typedef struct {
    char expressao[MAX_EXPRESSAO];
    double resultado;
    int valida;
} HistoricoItem;

// Variáveis globais
HistoricoItem historico[MAX_HISTORICO];
int contadorHistorico = 0;

// Protótipos das funções que estão disponíveis ao usuário escolher
void menuPrincipal();
void calculadoraBasica();
void calculadoraCientifica();
void mostrarHistorico();
void limparHistorico();
double avaliarExpressao(char* expr);
double aplicarOperacao(char operador, double a, double b);
int precedencia(char op);
int ehOperador(char c);
int ehNumero(char c);
void adicionarAoHistorico(char* expressao, double resultado);
double calcularFuncoesTrig(char* funcao, double valor);
double calcularLogaritmos(char* funcao, double valor);
void exibirMenu();
int validarExpressao(char* expr);

int main() {
    printf("=== CALCULADORA CIENTÍFICA COM HISTÓRICO ===\n");    
    menuPrincipal();
    
    return 0;
}

// Menu interativo com o usuário
void menuPrincipal() {
    int opcao;
    
    do {
        exibirMenu();
        printf("Escolha uma opção: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Erro: Digite um número válido!\n");
            while (getchar() != '\n'); // Limpar buffer
            continue;
        }
        
        switch (opcao) {
            case 1:
                calculadoraBasica();
                break;
            case 2:
                calculadoraCientifica();
                break;
            case 3:
                mostrarHistorico();
                break;
            case 4:
                limparHistorico();
                break;
            case 0:
                printf("Encerrando calculadora...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            while (getchar() != '\n');
            getchar();
        }
        
    } while (opcao != 0);
}

// Menu visível para o usuário
void exibirMenu() {
    printf("\n==================================================\n");
    printf("            MENU PRINCIPAL\n");
    printf("==================================================\n");
    printf("1. Calculadora Básica\n");
    printf("2. Calculadora Científica\n");
    printf("3. Mostrar Histórico\n");
    printf("4. Limpar Histórico\n");
    printf("0. Sair\n");
    printf("==================================================\n");
}

// Função para caso o usuário tenha escolhido Calculadora Básica
void calculadoraBasica() {
    char expressao[MAX_EXPRESSAO];
    double resultado;
    char continuar = 's';
    
    printf("\n=== CALCULADORA BÁSICA ===\n");
    printf("Operações disponíveis: +, -, *, /, ^(potência)\n");
    printf("Exemplo: 2 + 3 * 4\n\n");
    
    while (continuar == 's' || continuar == 'S') {
        printf("Digite a expressão: ");
        scanf(" %[^\n]", expressao);
        
        if (!validarExpressao(expressao)) {
            printf("Erro: Expressão inválida!\n");
            printf("Continuar? (s/n): ");
            scanf(" %c", &continuar);
            continue;
        }
        
        resultado = avaliarExpressao(expressao);
        
        if (!isnan(resultado)) {
            printf("Resultado: %.6f\n", resultado);
            adicionarAoHistorico(expressao, resultado);
        } else {
            printf("Erro no cálculo da expressão!\n");
        }
        
        printf("Continuar? (s/n): ");
        scanf(" %c", &continuar);
    }
}

// Função para caso o usuário tenha escolhido Calculadora Científica
void calculadoraCientifica() {
    char entrada[MAX_EXPRESSAO];
    double valor, resultado;
    char funcao[20];
    int opcao;
    char continuar = 's';
    
    printf("\n=== CALCULADORA CIENTÍFICA ===\n");
    
    while (continuar == 's' || continuar == 'S') {
        printf("\nFunções disponíveis:\n");
        printf("1. Funções Trigonométricas (sin, cos, tan)\n");
        printf("2. Logaritmos (log10, ln)\n");
        printf("3. Raiz Quadrada\n");
        printf("4. Potenciação\n");
        printf("5. Fatorial\n");
        printf("Escolha (1-5): ");
        
        scanf("%d", &opcao);
        // Caso o usuário tenha escolhido função trigonométrica
        switch (opcao) {
            case 1:
                printf("Digite a função (sin/cos/tan): ");
                scanf("%s", funcao);
                printf("Digite o valor (em radianos): ");
                scanf("%lf", &valor);
                
                resultado = calcularFuncoesTrig(funcao, valor);
                if (!isnan(resultado)) {
                    sprintf(entrada, "%s(%.4f)", funcao, valor);
                    printf("Resultado: %.6f\n", resultado);
                    adicionarAoHistorico(entrada, resultado);
                }
                break;
            
			// Caso o usuário tenha escolhido função logarítmica
            case 2:
                printf("Digite a função (log10/ln): ");
                scanf("%s", funcao);
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                
                resultado = calcularLogaritmos(funcao, valor);
                if (!isnan(resultado)) {
                    sprintf(entrada, "%s(%.4f)", funcao, valor);
                    printf("Resultado: %.6f\n", resultado);
                    adicionarAoHistorico(entrada, resultado);
                }
                break;
            
            // Caso o usuário tenha escolhido raiz quadrada
            case 3:
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                if (valor >= 0) {
                    resultado = sqrt(valor);
                    sprintf(entrada, "sqrt(%.4f)", valor);
                    printf("Resultado: %.6f\n", resultado);
                    adicionarAoHistorico(entrada, resultado);
                } else {
                    printf("Erro: Raiz de número negativo!\n");
                }
                break;
            
            // Caso o usuário tenha escolhido potenciação
            case 4:
                printf("Digite a base: ");
                scanf("%lf", &valor);
                double expoente;
                printf("Digite o expoente: ");
                scanf("%lf", &expoente);
                resultado = pow(valor, expoente);
                sprintf(entrada, "%.4f^%.4f", valor, expoente);
                printf("Resultado: %.6f\n", resultado);
                adicionarAoHistorico(entrada, resultado);
                break;
            
            // Caso o usuário tenha escolhido fatorial
            case 5:
                printf("Digite um número inteiro: ");
                int n;
                scanf("%d", &n);
                if (n >= 0 && n <= 20) {
                    long long fat = 1;
                    for (int i = 1; i <= n; i++) {
                        fat *= i;
                    }
                    sprintf(entrada, "%d!", n);
                    printf("Resultado: %lld\n", fat);
                    adicionarAoHistorico(entrada, (double)fat);
                } else {
                    printf("Erro: Número deve estar entre 0 e 20!\n");
                }
                break;
                
            default:
                printf("Opção inválida!\n");
        }
        
        printf("Continuar? (s/n): ");
        scanf(" %c", &continuar);
    }
}

// Função que calcula função trigonométrica
double calcularFuncoesTrig(char* funcao, double valor) {
    if (strcmp(funcao, "sin") == 0) {
        return sin(valor);
    } else if (strcmp(funcao, "cos") == 0) {
        return cos(valor);
    } else if (strcmp(funcao, "tan") == 0) {
        return tan(valor);
    } else {
        printf("Erro: Função trigonométrica inválida!\n");
        return NAN;
    }
}

// Função que calcula função logaritmos
double calcularLogaritmos(char* funcao, double valor) {
    if (valor <= 0) {
        printf("Erro: Logaritmo de número não positivo!\n");
        return NAN;
    }
    
    if (strcmp(funcao, "log10") == 0) {
        return log10(valor);
    } else if (strcmp(funcao, "ln") == 0) {
        return log(valor);
    } else {
        printf("Erro: Função logarítmica inválida!\n");
        return NAN;
    }
}

// Função que mostra o histórico do usuário
void mostrarHistorico() {
    printf("\n=== HISTÓRICO DE CÁLCULOS ===\n");
    
    if (contadorHistorico == 0) {
        printf("Nenhum cálculo no histórico.\n");
        return;
    }
    
    printf("Total de cálculos: %d\n", contadorHistorico);
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < contadorHistorico; i++) {
        if (historico[i].valida) {
            printf("%3d. %s = %.6f\n", 
                   i + 1, 
                   historico[i].expressao, 
                   historico[i].resultado);
        }
    }
    printf("------------------------------------------------------------\n");
}

// Função que limpa o histórico do usuário
void limparHistorico() {
    char confirmacao;
    
    if (contadorHistorico == 0) {
        printf("Histórico já está vazio.\n");
        return;
    }
    
    printf("Tem certeza que deseja limpar o histórico? (s/n): ");
    scanf(" %c", &confirmacao);
    
    if (confirmacao == 's' || confirmacao == 'S') {
        for (int i = 0; i < contadorHistorico; i++) {
            historico[i].valida = 0;
            memset(historico[i].expressao, 0, MAX_EXPRESSAO);
            historico[i].resultado = 0.0;
        }
        contadorHistorico = 0;
        printf("Histórico limpo com sucesso!\n");
    } else {
        printf("Operação cancelada.\n");
    }
}

// Responsável por pegar o cálculo feito e adicionar ao histórico.
void adicionarAoHistorico(char* expressao, double resultado) {
    if (contadorHistorico < MAX_HISTORICO) {
        strcpy(historico[contadorHistorico].expressao, expressao);
        historico[contadorHistorico].resultado = resultado;
        historico[contadorHistorico].valida = 1;
        contadorHistorico++;
    } else {
        // Shift do array para remover o mais antigo
        for (int i = 0; i < MAX_HISTORICO - 1; i++) {
            historico[i] = historico[i + 1];
        }
        strcpy(historico[MAX_HISTORICO - 1].expressao, expressao);
        historico[MAX_HISTORICO - 1].resultado = resultado;
        historico[MAX_HISTORICO - 1].valida = 1;
    }
}

// Garante que a string digitada pelo usuário é uma expressão matemática sintaticamente válida.
int validarExpressao(char* expr) {
    int len = strlen(expr);
    int parenteses = 0;
    
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        
        if (c == '(') {
            parenteses++;
        } else if (c == ')') {
            parenteses--;
            if (parenteses < 0) return 0;
        } else if (!ehNumero(c) && !ehOperador(c) && c != '.' && c != ' ') {
            return 0;
        }
    }
    
    return parenteses == 0;
}

// Esta função AVALIA e CALCULA o resultado de uma expressão matemática
// (como "2 + 3 * 4") usando o algoritmo Shunting-Yard para
// respeitar a Ordem de Precedência de Operadores.

// As duas pilhas são inicializadas como vazias (topo em -1).
// A lógica inteira do cálculo é baseada em adicionar ou remover elementos dessas pilhas.
double avaliarExpressao(char* expr) {
    double pilhaNumeros[MAX_EXPRESSAO];
    char pilhaOperadores[MAX_EXPRESSAO];
    int topoNumeros = -1;
    int topoOperadores = -1;
    int i = 0;
    int len = strlen(expr);
    
// O while (i < len) percorre a string de
// entrada (expr) caractere por caractere, ignorando
// espaços (if (expr[i] == ' ')).
    while (i < len) {
        if (expr[i] == ' ') {
            i++;
            continue;
        }
        
// Quando um dígito é encontrado, a função lê o número inteiro
// (incluindo casas decimais), o convertendo de caracteres
// ('5') para um valor numérico (5.0)
        if (ehNumero(expr[i])) {
            double num = 0;
            double decimal = 0;
            int casasDecimais = 0;
            int temPonto = 0;
            
            while (i < len && (ehNumero(expr[i]) || expr[i] == '.')) {
                if (expr[i] == '.') {
                    if (temPonto) return NAN;
                    temPonto = 1;
                } else {
                    if (!temPonto) {
                        num = num * 10 + (expr[i] - '0');
                    } else {
                        decimal = decimal * 10 + (expr[i] - '0');
                        casasDecimais++;
                    }
                }
                i++;
            }
            
            if (casasDecimais > 0) {
                num += decimal / pow(10, casasDecimais);
            }
            
            pilhaNumeros[++topoNumeros] = num;
        }

// O parêntese de abertura é simplesmente empilhado na pilhaOperadores.
// Ele serve como um "limite" de baixa prioridade.
        else if (expr[i] == '(') {
            pilhaOperadores[++topoOperadores] = expr[i];
            i++;
        }
        
// Quando um ) é encontrado, o programa sabe que
// todos os cálculos dentro desse par de parênteses devem ser feitos imediatamente.
        else if (expr[i] == ')') {
            while (topoOperadores >= 0 && pilhaOperadores[topoOperadores] != '(') {
                if (topoNumeros < 1) return NAN;
                
                double b = pilhaNumeros[topoNumeros--];
                double a = pilhaNumeros[topoNumeros--];
                char op = pilhaOperadores[topoOperadores--];
                
                double resultado = aplicarOperacao(op, a, b);
                if (isnan(resultado)) return NAN;
                
                pilhaNumeros[++topoNumeros] = resultado;
            }
            if (topoOperadores >= 0) topoOperadores--;
            i++;
        }
        
// O while interno verifica se há operadores na pilha
// que têm precedência maior ou igual ao operador atual (expr[i]).
// Se houver, esses operadores de alta precedência são executados imediatamente
        else if (ehOperador(expr[i])) {
            while (topoOperadores >= 0 && 
                   pilhaOperadores[topoOperadores] != '(' &&
                   precedencia(pilhaOperadores[topoOperadores]) >= precedencia(expr[i])) {
                
                if (topoNumeros < 1) return NAN;
                
                double b = pilhaNumeros[topoNumeros--];
                double a = pilhaNumeros[topoNumeros--];
                char op = pilhaOperadores[topoOperadores--];
                
                double resultado = aplicarOperacao(op, a, b);
                if (isnan(resultado)) return NAN;
                
                pilhaNumeros[++topoNumeros] = resultado;
            }
            pilhaOperadores[++topoOperadores] = expr[i];
            i++;
        } else {
            i++;
        }
    }
    
// Após o percurso completo da expressão, as operações restantes
// (geralmente de baixa precedência) são desempilhadas e aplicadas.
// Se tudo correr bem, o resultado final da expressão será o único
// número na pilha. Em caso de erro (como expressão malformada ou divisão por zero),
// a função retorna NAN.
    while (topoOperadores >= 0) {
        if (topoNumeros < 1) return NAN;
        
        double b = pilhaNumeros[topoNumeros--];
        double a = pilhaNumeros[topoNumeros--];
        char op = pilhaOperadores[topoOperadores--];
        
        double resultado = aplicarOperacao(op, a, b);
        if (isnan(resultado)) return NAN;
        
        pilhaNumeros[++topoNumeros] = resultado;
    }
    
    return (topoNumeros == 0) ? pilhaNumeros[0] : NAN;
}

// Caso seja a [operação] b, sendo uma conta com dois elementos,
// realizar essa função abaixo:
double aplicarOperacao(char operador, double a, double b) {
    switch (operador) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                printf("Erro: Divisão por zero!\n");
                return NAN;
            }
            return a / b;
        case '^': return pow(a, b);
        default:
            printf("Erro: Operador inválido!\n");
            return NAN;
    }
}

int precedencia(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int ehNumero(char c) {
    return (c >= '0' && c <= '9');
}
