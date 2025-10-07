# Introdução a Técnicas de Programação - Unidade 1
**Aluno**: Guilherme Avelino Macedo
**Matrícula**: 20250026942
**Período**: 2025.2

## 📁 Estrutura do Projeto

- `projeto/`: Projeto principal da unidade
- `listas/`: Soluções das listas de exercícios
- `README.md`: Este arquivo

## 🚀 Projeto: Calculadora Científica

**Descrição**: Desenvolvido inteiramente em linguagem C, essa calculadora científica destaca-se pela implementação do robusto algoritmo *Shunting-Yard* para a avaliação de expressões matemáticas. Através do uso de pilhas para gerenciar operadores e operandos, o sistema analisa e resolve corretamente equações complexas, respeitando a ordem de precedência e o uso de parênteses. A lógica da interface de linha de comando, o motor de cálculo e o sistema de gerenciamento de histórico, que contém um *array* de *structs* são organizados corretamente no código. Há cuidado na validação de entrada e tratamento de erros.

**Repositório**: https://github.com/guiave/itp-2025-2/tree/main

**Vídeo de Demonstração**: https://youtu.be/QiHkNAPs-HE

### Funcionalidades Implementadas:
- Calculadora básica
- Calculadora científica
  - Função trigonométrica
  - Logarítmos (log₁₀ ou ln)
  - Raiz quadrada
  - Potenciação
  - Fatorial
- Mostrar histórico
- Limpar histórico

### Conceitos da U1 Aplicados:

- **Estruturas condicionais:** As estruturas condicionais (`if-else`, `switch-case`) são o coração do fluxo de controle do programa. Elas são utilizadas extensivamente para a tomada de decisões, como na função `menuPrincipal`, que usa um `switch` para direcionar o usuário à funcionalidade escolhida; na função `avaliarExpressao`, onde uma série de `if-else if` distingue entre números, operadores e parênteses; e em funções de cálculo como `aplicarOperacao` e `calcularFuncoesTrig`, que utilizam `switch` e `if` para selecionar a operação matemática correta com base na entrada do usuário e para validar condições, como a divisão por zero ou o logaritmo de um número negativo.

- **Estruturas de repetição:** As estruturas de repetição (`for`, `while`, `do-while`) são fundamentais para a interatividade e o processamento de dados. Um laço `do-while` em `menuPrincipal` mantém o menu principal em execução até que o usuário decida sair. Laços `while` são usados dentro das calculadoras básica e científica para permitir que o usuário realize múltiplos cálculos em sequência. Já os laços `for` são empregados para percorrer os vetores, como na exibição e limpeza do histórico de cálculos e, de forma crucial, na implementação do fatorial. Além disso, a função `avaliarExpressao` depende de múltiplos laços `while` para processar a string da expressão caractere por caractere e para manipular as pilhas de operadores e números.

- **Vetores:** Os vetores são utilizados como a principal estrutura de dados do projeto para três finalidades distintas. Primeiramente, vetores de caracteres (`char[]`) são usados para armazenar strings, como a expressão matemática digitada pelo usuário (`expressao`) e os nomes das funções científicas. Em segundo lugar, um vetor global de `structs` (`historico[MAX_HISTORICO]`) armazena de forma persistente o histórico de todos os cálculos realizados durante a sessão. Por fim, de maneira mais complexa, dois vetores locais (`pilhaNumeros` e `pilhaOperadores`) na função `avaliarExpressao` são usados para implementar as pilhas necessárias para o funcionamento do algoritmo Shunting-Yard, que processa e calcula o resultado da expressão.

- **Funções:** Este código é altamente modularizado através do uso de 16 funções distintas, cada uma com uma responsabilidade bem definida, promovendo a reutilização e a clareza do código. Elas podem ser agrupadas em categorias: funções de interface com o usuário (`menuPrincipal`, `exibirMenu`), funções que implementam os modos de cálculo (`calculadoraBasica`, `calculadoraCientifica`), funções para gerenciamento de dados (`mostrarHistorico`, `limparHistorico`, `adicionarAoHistorico`), funções que compõem o núcleo do motor de cálculo (`avaliarExpressao`, `aplicarOperacao`, `precedencia`) e funções auxiliares para cálculos específicos e validações (`calcularFuncoesTrig`, `validarExpressao`, `ehNumero`).

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

## 🎯 Principais Aprendizados
Aprendi muitas coisas durante a realização do curso.
- Quando estiver fácil é porque estou fazendo errado, ou seja, não subestimar os problemas dados.
- A Internet é uma ferramenta maravilhosa para auxiliar o programador nas suas dificuldades.
- Se importar com prazo de entrega.
- Não ficar somente no superficial em qualquer assunto.

## 🔧 Ambiente de Desenvolvimento
- **SO**: Windows 10
- **Compilador**: TDM-GCC versão 9.2.0 64-bit
- **Editor**: Embarcadero Dev-C++ 6.3
