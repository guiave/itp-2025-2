# Introdução a Técnicas de Programação - Unidade 1
**Aluno**: Guilherme Avelino Macedo
**Matrícula**: 20250026942
**Período**: 2025.2

## 📁 Estrutura do Projeto

- `projeto/`: Projeto principal da unidade
- `listas/`: Soluções das listas de exercícios
- `README.md`: Este arquivo

## 🚀 Projeto: Calculadora Científica Avançada

**Descrição**: Esta é uma evolução significativa da calculadora científica original, reestruturada para incorporar conceitos avançados de programação em C. O núcleo de cálculo ainda utiliza o robusto algoritmo *Shunting-Yard* para avaliar expressões, mas o projeto foi expandido com gerenciamento de memória dinâmica, tornando o histórico de cálculos flexível e escalável.

Além das funcionalidades científicas, foram adicionados dois novos módulos: um para operações com matrizes (soma, multiplicação e transposição) e outro para manipulação de strings, demonstrando um domínio mais profundo sobre ponteiros e alocação de memória. O código foi refatorado para maior modularidade e clareza, com tratamento de erros aprimorado.

**Repositório**: https://github.com/guiave/itp-2025-2/tree/main

**Vídeo de Demonstração**: https://www.youtube.com/watch?v=XYJDAYGmW1E

### Funcionalidades Implementadas:
- **Calculadora Básica**: Operações aritméticas com respeito à precedência de operadores.
- **Calculadora Científica**:
  - Funções trigonométricas (seno, cosseno, tangente)
  - Logaritmos (log₁₀ e ln)
  - Raiz quadrada
  - Potenciação
  - Fatorial
- **Operações com Matrizes**:
  - Criação de matrizes com dimensões definidas pelo usuário.
  - Soma, multiplicação e transposição de matrizes.
- **Manipulação de Strings**:
  - Comparação, cópia, concatenação, análise (tamanho, vogais) e inversão de strings.
- **Gerenciamento de Histórico**:
  - Mostrar histórico de todos os cálculos.
  - Limpar o histórico.

### Conceitos da U2 Aplicados:

- **Alocação Dinâmica de Memória:** Este é o principal avanço do projeto. Em vez de um vetor estático com limite fixo, o histórico de cálculos agora é gerenciado com **`malloc`**, **`realloc`** e **`free`**. Isso permite que o histórico cresça conforme a necessidade do usuário, limitado apenas pela memória do sistema. O módulo de matrizes também depende inteiramente da alocação dinâmica para criar matrizes de tamanhos variados.

- **Ponteiros e Aritmética de Ponteiros:** Os ponteiros são usados extensivamente para gerenciar a memória alocada dinamicamente. O projeto utiliza ponteiros para ponteiros (`double**`) para a criação da estrutura de dados da matriz, ponteiros para `structs` para gerenciar o histórico, e ponteiros de `char` para algoritmos eficientes de manipulação de strings, como a inversão "in-place".

- **Structs e Tipos de Dados Personalizados (`typedef`):** O projeto agora utiliza `structs` mais complexas para modelar dados. A `struct Matriz` encapsula os dados e dimensões, enquanto a `struct HistoricoDinamico` gerencia o ponteiro para os itens do histórico, sua capacidade e contagem. O uso de `typedef` torna o código mais limpo e legível.

- **Modularidade e Organização de Código:** O código foi organizado em seções lógicas claras (Interface, Gerenciamento de Memória, Módulo de Matrizes, etc.), promovendo uma alta modularidade. Cada função tem uma responsabilidade única, o que facilita a manutenção e a expansão do projeto.

- **Estruturas Condicionais e de Repetição:** `if-else`, `switch-case`, `for`, `while` e `do-while` continuam sendo a base para o fluxo de controle, menus interativos, validação de entradas, processamento de expressões e algoritmos de cálculo, agora aplicados também nos novos módulos de matrizes e strings.

- **Funções e Vetores:** O projeto é composto por dezenas de funções especializadas. Vetores (arrays) ainda são utilizados para armazenar strings e como base para as pilhas do algoritmo Shunting-Yard, mas o destaque é a transição de vetores estáticos para dinâmicos nas estruturas de dados principais.

## 📚 Listas de Exercícios

### Semana 2 - Variáveis, Tipos e Operadores:
- ✅ Problema 1: Calculadora de IMC
- ✅ Problema 2: Conversão de temperatura
- ✅ Problema 3: Cálculo de juros compostos
- ✅ Problema 4: Operações aritméticas básicas

### Semana 3 - Condicionais:
- ✅ Problema 1: Classificação de IMC
- ✅ Problema 2: Calculadora de energia elétrica
- ✅ Problema 3: Sistema de notas
- ✅ Problema 4: Pedra, papel, tesoura
- ✅ Problema 5: Calculadora de desconto progressivo
- ✅ Problema 6: Diagnóstico médico simples
- ✅ Problema 7: Sistema de equações do 2º grau
- ✅ Problema 8: Validador de triângulos

### Semana 4A - Repetições:
- ✅ Problema 1: Dobrar folha
- ✅ Problema 2: Homem Aranha
- ✅ Problema 3: Números colegas
- ✅ Problema 4: Jogo de dardos

### Semana 4B - Análise e Padrões:
- ✅ Questões 1-4: Análise de código
- ✅ Questões 5-11: Implementações

### Semana 5 - Funções (Parte 1):
- ✅ Problema 1: Horários das rondas
- ✅ Problema 2: Primos triplos
- ✅ Problema 3: Pousando a sonda espacial

### Semana 6 - Vetores:
- ✅ Problema 1: MEC - Correção ENEM
- ✅ Problema 2: Álbum de figurinhas
- ✅ Problema 3: A construção da ponte
- ✅ Problema 4: Em busca do tesouro perdido

### Semana 7 - Strings:
- ✅ Problema 1: Campo minado 1D
- ✅ Problema 2: Detecção de placas
- ✅ Problema 3: OpenMeet

### Semana 8 - Repetições Aninhadas:
- ✅ Problema 1: Estou com sorte (ou não)
- ✅ Problema 2: Os dias mais chuvosos
- ✅ Problema 3: Esse sim é piloto

### Semana 9 - Matrizes
- ✅ Problema 1: Campo agrícola
- ✅ Problema 2: Sugestão de amigos
- ✅ Problema 3: Campeonato de empates
- ✅ Problema 4: Uma pechincha

### Semana 10 - Ponteiros (alocação)
- ✅ Problema 1: Soma de vetores
- ✅ Problema 2: Ocorrência de vetores
- ✅ Problema 3: Sopa de letrinhas

## 🎯 Principais Aprendizados
A evolução deste projeto solidificou e expandiu meus aprendizados:
- A diferença fundamental entre alocação de memória estática e dinâmica.
- A importância do gerenciamento manual de memória: a necessidade de usar `free` para evitar vazamentos de memória.
- Como modelar estruturas de dados complexas, como matrizes de tamanho variável, usando ponteiros para ponteiros.
- O poder e a flexibilidade de `realloc` para criar estruturas de dados que se adaptam ao uso.
- A aplicação prática de ponteiros para criar algoritmos mais eficientes.
- A importância de organizar o código em módulos lógicos para lidar com projetos maiores.
- Quando estiver fácil é porque estou fazendo errado, ou seja, não subestimar os problemas dados.
- A Internet é uma ferramenta maravilhosa para auxiliar o programador nas suas dificuldades.

## 🔧 Ambiente de Desenvolvimento
- **SO**: Windows 10
- **Compilador**: TDM-GCC versão 9.2.0 64-bit
- **Editor**: Embarcadero Dev-C++ 6.3
