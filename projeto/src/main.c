#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSAO 256
#define PI 3.14159265359

// ===== ESTRUTURAS DE DADOS =====

// Representa um único registro de cálculo no histórico
typedef struct {
    char expressao[MAX_EXPRESSAO]; // Armazena a string da conta (ex: "2 + 2")
    double resultado;              // Armazena o valor final
    int valida;                    // Flag para indicar se o registro é válido (exclusão lógica)
} HistoricoItem;

// Gerenciador do array dinâmico de histórico
typedef struct {
    HistoricoItem* itens;       // Ponteiro para o início do bloco de memória alocado
    int capacidade;             // Tamanho total de memória alocada atualmente
    int contador;               // Quantidade real de itens armazenados
} HistoricoDinamico;

// Representa uma matriz de tamanho variável
typedef struct {
    double** dados;             // Ponteiro duplo para criar matrizes via alocação dinâmica
    int linhas;
    int colunas;
} Matriz;

// ===== VARIÁVEIS GLOBAIS =====
HistoricoDinamico historico = {NULL, 0, 0};

// ===== PROTÓTIPOS DE FUNÇÕES =====

// Interface
void menuPrincipal();
void exibirMenu();

// Módulos de Cálculo
void calculadoraBasica();
void calculadoraCientifica();
void calculadoraMatricial();

// Utilitários de String
void manipularStrings();
int validarExpressao(char* expr);

// Gerenciamento de Memória e Histórico
void inicializarHistorico();
void adicionarAoHistorico(char* expressao, double resultado);
void mostrarHistorico();
void limparHistorico();
void liberarHistorico();
int redimensionarHistorico();

// Lógica de Avaliação de Expressões (Shunting-Yard simplificado)
double avaliarExpressao(char* expr);
double aplicarOperacao(char operador, double a, double b);
int precedencia(char op);
int ehOperador(char c);
int ehNumero(char c);

// Funções Matemáticas Auxiliares
double calcularFuncoesTrig(char* funcao, double valor);
double calcularLogaritmos(char* funcao, double valor);

// Operações Matriciais
Matriz* criarMatriz(int linhas, int colunas);
void liberarMatriz(Matriz* m);
void preencherMatriz(Matriz* m);
void imprimirMatriz(Matriz* m);
Matriz* somarMatrizes(Matriz* a, Matriz* b);
Matriz* multiplicarMatrizes(Matriz* a, Matriz* b);
Matriz* transporMatriz(Matriz* m);

// ===== FUNÇÃO PRINCIPAL =====

int main() {
    printf("CALCULADORA CIENTIFICA AVANCADA\n");
    
    // Prepara a estrutura de dados inicial antes de entrar no loop principal
    inicializarHistorico();
    
    // Loop principal do programa
    menuPrincipal();
    
    // Limpeza obrigatória de memória antes de encerrar o programa para evitar leaks
    liberarHistorico();
    
    return 0;
}

// ===== GERENCIAMENTO DE MEMÓRIA (HISTÓRICO) =====

void inicializarHistorico() {
    historico.capacidade = 10;
    historico.contador = 0;
    
    // Aloca o bloco inicial de memória na Heap
    historico.itens = (HistoricoItem*)malloc(historico.capacidade * sizeof(HistoricoItem));
    
    if (historico.itens == NULL) {
        printf("Erro critico: Falha na alocacao de memoria inicial.\n");
        exit(1); // Encerra o programa se não houver memória
    }
}

// Função responsável por aumentar o buffer do histórico quando ele enche
int redimensionarHistorico() {
    // Estratégia de dobrar a capacidade para garantir complexidade amortizada O(1)
    int novaCapacidade = historico.capacidade * 2;
    
    // Tenta realocar o bloco de memória preservando os dados existentes
    HistoricoItem* novoArray = (HistoricoItem*)realloc(
        historico.itens, 
        novaCapacidade * sizeof(HistoricoItem)
    );
    
    if (novoArray == NULL) {
        printf("Erro: Memoria insuficiente para expandir historico.\n");
        return 0; // Falha na expansão
    }
    
    // Atualiza o ponteiro e a capacidade apenas se o realloc funcionar
    historico.itens = novoArray;
    historico.capacidade = novaCapacidade;
    
    printf("Debug: Memoria do historico expandida para %d slots.\n", novaCapacidade);
    return 1;
}

void adicionarAoHistorico(char* expressao, double resultado) {
    // Verifica overflow do buffer atual e expande se necessário
    if (historico.contador >= historico.capacidade) {
        if (!redimensionarHistorico()) {
            return; // Aborta se não conseguir mais memória
        }
    }
    
    // Acessa a posição atual via índice e copia os dados
    strcpy(historico.itens[historico.contador].expressao, expressao);
    historico.itens[historico.contador].resultado = resultado;
    historico.itens[historico.contador].valida = 1;
    
    historico.contador++;
}

void mostrarHistorico() {
    printf("\nHISTORICO DE CALCULOS\n");
    
    if (historico.contador == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }
    
    // Ponteiro auxiliar para iterar sobre o array
    HistoricoItem* ptr = historico.itens;
    
    for (int i = 0; i < historico.contador; i++) {
        if (ptr->valida) {
            printf("%3d. %-40s = %.6f\n", i + 1, ptr->expressao, ptr->resultado);
        }
        ptr++; // Aritmética de ponteiros: avança para o próximo struct na memória
    }
}

void limparHistorico() {
    if (historico.contador == 0) return;
    
    char confirmacao[10];
    printf("Confirmar limpeza total? (sim/nao): ");
    scanf("%s", confirmacao);
    
    if (strcmp(confirmacao, "sim") == 0 || strcmp(confirmacao, "s") == 0) {
        // Zera a memória de todos os itens por segurança (opcional, mas boa prática)
        // Reinicia apenas o contador, sobrescrevendo os dados futuramente (Soft delete)
        memset(historico.itens, 0, historico.capacidade * sizeof(HistoricoItem));
        historico.contador = 0;
        printf("Historico resetado.\n");
    }
}

void liberarHistorico() {
    // Libera a memória alocada dinamicamente para devolver ao SO
    if (historico.itens != NULL) {
        free(historico.itens);
        historico.itens = NULL; // Evita ponteiros pendentes (dangling pointers)
    }
}

// ===== LÓGICA DE INTERFACE =====

void exibirMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Calculadora Basica\n");
    printf("2. Calculadora Cientifica\n");
    printf("3. Operacoes Matriciais\n");
    printf("4. Testes de String\n");
    printf("5. Ver Historico\n");
    printf("6. Limpar Historico\n");
    printf("0. Sair\n");
}

void menuPrincipal() {
    int opcao;
    
    do {
        exibirMenu();
        printf("Opcao: ");
        
        // Validação básica de entrada numérica
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            while (getchar() != '\n'); // Limpa o buffer do teclado (flush)
            continue;
        }
        
        switch (opcao) {
            case 1: calculadoraBasica(); break;
            case 2: calculadoraCientifica(); break;
            case 3: calculadoraMatricial(); break;
            case 4: manipularStrings(); break;
            case 5: mostrarHistorico(); break;
            case 6: limparHistorico(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao desconhecida.\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione Enter...");
            while (getchar() != '\n');
            getchar();
        }
        
    } while (opcao != 0);
}

// ===== MÓDULO: CALCULADORA BÁSICA =====

void calculadoraBasica() {
    char expressao[MAX_EXPRESSAO];
    double resultado;
    char continuar = 's';
    
    printf("\n--- MODO BASICO ---\n");
    printf("Suporta: +, -, *, /, ^. Ex: (2 + 3) * 5\n");
    
    while (tolower(continuar) == 's') {
        printf("Expressao: ");
        // O espaço antes do % lê e descarta espaços em branco/newlines residuais
        scanf(" %[^\n]", expressao);
        
        if (!validarExpressao(expressao)) {
            printf("Sintaxe invalida (verifique parenteses ou caracteres).\n");
        } else {
            resultado = avaliarExpressao(expressao);
            
            // Verifica se o resultado é um número válido (não é NaN)
            if (!isnan(resultado)) {
                printf("= %.6f\n", resultado);
                adicionarAoHistorico(expressao, resultado);
            } else {
                printf("Erro matematico durante avaliacao.\n");
            }
        }
        
        printf("Novo calculo? (s/n): ");
        scanf(" %c", &continuar);
    }
}

// ===== MÓDULO: CALCULADORA CIENTÍFICA =====

void calculadoraCientifica() {
    char entrada[MAX_EXPRESSAO];
    double valor, resultado;
    char funcao[20];
    int opcao;
    char continuar = 's';
    
    while (tolower(continuar) == 's') {
        printf("\n1. Trig (sin/cos/tan)\n2. Log (log10/ln)\n3. Raiz (sqrt)\n4. Potencia (x^y)\n5. Fatorial (n!)\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: // Trigonometria
                printf("Funcao (sin/cos/tan) e valor: ");
                scanf("%s %lf", funcao, &valor);
                resultado = calcularFuncoesTrig(funcao, valor);
                if (!isnan(resultado)) {
                    sprintf(entrada, "%s(%.4f)", funcao, valor); // Formata string para histórico
                    printf("= %.6f\n", resultado);
                    adicionarAoHistorico(entrada, resultado);
                }
                break;
            
            case 2: // Logaritmos
                printf("Funcao (log10/ln) e valor: ");
                scanf("%s %lf", funcao, &valor);
                resultado = calcularLogaritmos(funcao, valor);
                if (!isnan(resultado)) {
                    sprintf(entrada, "%s(%.4f)", funcao, valor);
                    printf("= %.6f\n", resultado);
                    adicionarAoHistorico(entrada, resultado);
                }
                break;
            
            case 3: // Raiz Quadrada
                printf("Valor: ");
                scanf("%lf", &valor);
                if (valor >= 0) {
                    resultado = sqrt(valor);
                    sprintf(entrada, "sqrt(%.4f)", valor);
                    printf("= %.6f\n", resultado);
                    adicionarAoHistorico(entrada, resultado);
                } else {
                    printf("Erro: Dominio invalido (raiz negativa).\n");
                }
                break;
            
            case 4: { // Potência
                double exp;
                printf("Base e Expoente: ");
                scanf("%lf %lf", &valor, &exp);
                resultado = pow(valor, exp);
                sprintf(entrada, "%.4f^%.4f", valor, exp);
                printf("= %.6f\n", resultado);
                adicionarAoHistorico(entrada, resultado);
                break;
            }
            
            case 5: { // Fatorial (Iterativo)
                int n;
                printf("Inteiro (0-20): ");
                scanf("%d", &n);
                if (n >= 0 && n <= 20) {
                    long long fat = 1;
                    // Loop simples para cálculo de produtório
                    for (int i = 1; i <= n; i++) fat *= i;
                    
                    sprintf(entrada, "%d!", n);
                    printf("= %lld\n", fat);
                    adicionarAoHistorico(entrada, (double)fat);
                } else {
                    printf("Erro: Valor fora dos limites permitidos (overflow).\n");
                }
                break;
            }
            default: printf("Invalido.\n");
        }
        printf("Continuar? (s/n): ");
        scanf(" %c", &continuar);
    }
}

// Wrapper para math.h com tratamento de erros de input string
double calcularFuncoesTrig(char* funcao, double valor) {
    if (strcmp(funcao, "sin") == 0) return sin(valor);
    if (strcmp(funcao, "cos") == 0) return cos(valor);
    if (strcmp(funcao, "tan") == 0) return tan(valor);
    
    printf("Erro: Funcao trigonometrica desconhecida.\n");
    return NAN;
}

double calcularLogaritmos(char* funcao, double valor) {
    if (valor <= 0) {
        printf("Erro: Logaritmo indefinido para valor <= 0.\n");
        return NAN;
    }
    if (strcmp(funcao, "log10") == 0) return log10(valor);
    if (strcmp(funcao, "ln") == 0) return log(valor);
    
    return NAN;
}

// ===== MÓDULO: MATRIZES (ALOCAÇÃO DINÂMICA) =====

Matriz* criarMatriz(int linhas, int colunas) {
    Matriz* m = (Matriz*)malloc(sizeof(Matriz));
    if (!m) return NULL;
    
    m->linhas = linhas;
    m->colunas = colunas;
    
    // 1. Aloca um array de ponteiros (as "linhas")
    m->dados = (double**)malloc(linhas * sizeof(double*));
    if (!m->dados) {
        free(m);
        return NULL;
    }
    
    // 2. Para cada linha, aloca o array de doubles (as "colunas")
    for (int i = 0; i < linhas; i++) {
        m->dados[i] = (double*)malloc(colunas * sizeof(double));
        // Tratamento de erro: se falhar no meio, libera tudo que já foi alocado
        if (!m->dados[i]) {
            for (int j = 0; j < i; j++) free(m->dados[j]);
            free(m->dados);
            free(m);
            return NULL;
        }
    }
    return m;
}

void liberarMatriz(Matriz* m) {
    if (m) {
        // Libera de dentro para fora: primeiro as linhas, depois o array de ponteiros, depois a struct
        for (int i = 0; i < m->linhas; i++) {
            free(m->dados[i]);
        }
        free(m->dados);
        free(m);
    }
}

void preencherMatriz(Matriz* m) {
    printf("Insira valores para matriz %dx%d:\n", m->linhas, m->colunas);
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%lf", &m->dados[i][j]); // Acesso direto via aritmética de ponteiros implícita
        }
    }
}

void imprimirMatriz(Matriz* m) {
    printf("\n");
    for (int i = 0; i < m->linhas; i++) {
        printf("| ");
        for (int j = 0; j < m->colunas; j++) {
            printf("%8.2f ", m->dados[i][j]);
        }
        printf("|\n");
    }
}

Matriz* somarMatrizes(Matriz* a, Matriz* b) {
    if (a->linhas != b->linhas || a->colunas != b->colunas) {
        printf("Erro: Dimensoes incompativeis para soma.\n");
        return NULL;
    }
    
    Matriz* res = criarMatriz(a->linhas, a->colunas);
    if (!res) return NULL;
    
    for (int i = 0; i < a->linhas; i++) {
        for (int j = 0; j < a->colunas; j++) {
            res->dados[i][j] = a->dados[i][j] + b->dados[i][j];
        }
    }
    return res;
}

Matriz* multiplicarMatrizes(Matriz* a, Matriz* b) {
    // Regra: Colunas de A deve ser igual a Linhas de B
    if (a->colunas != b->linhas) {
        printf("Erro: Dimensoes incompativeis para produto.\n");
        return NULL;
    }
    
    Matriz* res = criarMatriz(a->linhas, b->colunas);
    if (!res) return NULL;
    
    // Algoritmo clássico O(n^3)
    for (int i = 0; i < a->linhas; i++) {
        for (int j = 0; j < b->colunas; j++) {
            res->dados[i][j] = 0;
            // Produto escalar da linha de A pela coluna de B
            for (int k = 0; k < a->colunas; k++) {
                res->dados[i][j] += a->dados[i][k] * b->dados[k][j];
            }
        }
    }
    return res;
}

Matriz* transporMatriz(Matriz* m) {
    // A transposta inverte linhas por colunas
    Matriz* t = criarMatriz(m->colunas, m->linhas);
    if (!t) return NULL;
    
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            t->dados[j][i] = m->dados[i][j]; // Inversão de índices
        }
    }
    return t;
}

void calculadoraMatricial() {
    int op, l, c, l2, c2;
    printf("\n1. Soma\n2. Produto\n3. Transposta\nOpcao: ");
    scanf("%d", &op);
    
    switch(op) {
        case 1: { // Soma
            printf("Dimensao (L C): "); scanf("%d %d", &l, &c);
            Matriz* a = criarMatriz(l, c);
            Matriz* b = criarMatriz(l, c);
            if(a && b) {
                preencherMatriz(a);
                preencherMatriz(b);
                Matriz* res = somarMatrizes(a, b);
                if(res) { imprimirMatriz(res); liberarMatriz(res); }
            }
            liberarMatriz(a); liberarMatriz(b);
            break;
        }
        case 2: { // Produto
            printf("Matriz A (L C): "); scanf("%d %d", &l, &c);
            printf("Matriz B (L C): "); scanf("%d %d", &l2, &c2);
            if (c != l2) { printf("Erro de dimensao.\n"); break; }
            
            Matriz* a = criarMatriz(l, c);
            Matriz* b = criarMatriz(l2, c2);
            if(a && b) {
                preencherMatriz(a);
                preencherMatriz(b);
                Matriz* res = multiplicarMatrizes(a, b);
                if(res) { imprimirMatriz(res); liberarMatriz(res); }
            }
            liberarMatriz(a); liberarMatriz(b);
            break;
        }
        case 3: { // Transposta
            printf("Dimensao (L C): "); scanf("%d %d", &l, &c);
            Matriz* a = criarMatriz(l, c);
            if(a) {
                preencherMatriz(a);
                Matriz* t = transporMatriz(a);
                if(t) { imprimirMatriz(t); liberarMatriz(t); }
                liberarMatriz(a);
            }
            break;
        }
    }
}

// ===== MÓDULO: MANIPULAÇÃO DE STRINGS =====

void manipularStrings() {
    char s1[256], s2[256];
    int op;
    
    printf("\n1. Comparar\n2. Copiar\n3. Concatenar\n4. Tamanho/Analise\n5. Inverter\n");
    scanf("%d", &op);
    getchar(); // Flush do newline
    
    switch(op) {
        case 1: // Comparação Lexicográfica
            printf("String 1: "); fgets(s1, 256, stdin); s1[strcspn(s1, "\n")] = 0;
            printf("String 2: "); fgets(s2, 256, stdin); s2[strcspn(s2, "\n")] = 0;
            int r = strcmp(s1, s2);
            if(r == 0) printf("Iguais.\n");
            else printf(r < 0 ? "String 1 vem antes.\n" : "String 1 vem depois.\n");
            break;
            
        case 2: // Cópia de memória
            printf("Origem: "); fgets(s1, 256, stdin); s1[strcspn(s1, "\n")] = 0;
            strcpy(s2, s1); // Cópia byte a byte até encontrar \0
            printf("Copia: %s\n", s2);
            break;
            
        case 3: // Concatenação
            printf("S1: "); fgets(s1, 256, stdin); s1[strcspn(s1, "\n")] = 0;
            printf("S2: "); fgets(s2, 256, stdin); s2[strcspn(s2, "\n")] = 0;
            strcat(s1, s2); // Busca o fim de s1 e anexa s2
            printf("Resultado: %s\n", s1);
            break;
            
        case 4: // Análise de conteúdo
            printf("String: "); fgets(s1, 256, stdin); s1[strcspn(s1, "\n")] = 0;
            printf("Tamanho: %zu chars.\n", strlen(s1));
            
            // Varredura linear para contagem
            int vog=0, cons=0;
            for(char* p = s1; *p; p++) {
                if(isalpha(*p)) {
                    char c = tolower(*p);
                    if(strchr("aeiou", c)) vog++; else cons++;
                }
            }
            printf("Vogais: %d, Consoantes: %d\n", vog, cons);
            break;
            
        case 5: // Algoritmo de inversão "in-place"
            printf("String: "); fgets(s1, 256, stdin); s1[strcspn(s1, "\n")] = 0;
            
            // Usa dois ponteiros (início e fim) que caminham em direção ao centro
            char *inicio = s1, *fim = s1 + strlen(s1) - 1;
            while (inicio < fim) {
                char temp = *inicio;
                *inicio++ = *fim;
                *fim-- = temp;
            }
            printf("Invertida: %s\n", s1);
            break;
    }
}

// ===== ALGORITMO DE AVALIAÇÃO (PARSER) =====

int validarExpressao(char* expr) {
    int parenteses = 0;
    // Validação simples de balanceamento de parênteses
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(') parenteses++;
        else if (expr[i] == ')') {
            parenteses--;
            if (parenteses < 0) return 0; // Fechou parêntese sem abrir
        }
        else if (!isdigit(expr[i]) && !ehOperador(expr[i]) && expr[i] != '.' && expr[i] != ' ') {
            return 0; // Caractere ilegal
        }
    }
    return parenteses == 0;
}

// Implementação do Shunting-Yard para converter e calcular expressão infixa
double avaliarExpressao(char* expr) {
    // Pilhas para operandos e operadores
    double numeros[MAX_EXPRESSAO];
    char ops[MAX_EXPRESSAO];
    int topNum = -1, topOp = -1;
    
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == ' ') continue;
        
        // Parsing de números (incluindo decimais)
        if (isdigit(expr[i])) {
            double val = 0;
            int decimal = 0;
            double divisor = 1;
            
            while (isdigit(expr[i]) || expr[i] == '.') {
                if (expr[i] == '.') {
                    decimal = 1;
                } else if (!decimal) {
                    val = val * 10 + (expr[i] - '0');
                } else {
                    divisor *= 10;
                    val += (expr[i] - '0') / divisor;
                }
                i++;
            }
            i--; // Corrige incremento extra do loop interno
            numeros[++topNum] = val; // Push na pilha de números
        }
        
        else if (expr[i] == '(') {
            ops[++topOp] = expr[i];
        }
        
        else if (expr[i] == ')') {
            // Resolve tudo até encontrar o parêntese de abertura correspondente
            while (topOp >= 0 && ops[topOp] != '(') {
                if(topNum < 1) return NAN; // Erro de sintaxe
                double b = numeros[topNum--];
                double a = numeros[topNum--];
                numeros[++topNum] = aplicarOperacao(ops[topOp--], a, b);
            }
            topOp--; // Remove o '(' da pilha
        }
        
        else if (ehOperador(expr[i])) {
            // Verifica precedência para resolver operações pendentes mais prioritárias
            while (topOp >= 0 && ops[topOp] != '(' && 
                   precedencia(ops[topOp]) >= precedencia(expr[i])) {
                if(topNum < 1) return NAN;
                double b = numeros[topNum--];
                double a = numeros[topNum--];
                numeros[++topNum] = aplicarOperacao(ops[topOp--], a, b);
            }
            ops[++topOp] = expr[i]; // Push operador atual
        }
    }
    
    // Resolve o restante das operações na pilha
    while (topOp >= 0) {
        if(topNum < 1) return NAN;
        double b = numeros[topNum--];
        double a = numeros[topNum--];
        numeros[++topNum] = aplicarOperacao(ops[topOp--], a, b);
    }
    
    return numeros[topNum];
}

double aplicarOperacao(char op, double a, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b == 0 ? NAN : a / b;
        case '^': return pow(a, b);
        default: return NAN;
    }
}

int precedencia(char op) {
    // Define a hierarquia das operações matemáticas
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int ehOperador(char c) {
    return strchr("+-*/^", c) != NULL;
}
