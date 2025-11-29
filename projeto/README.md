### **Guia de Utilização: Calculadora Científica Avançada**

Bem-vindo à sua nova calculadora! Este software foi desenvolvido em C para oferecer desde cálculos simples até operações complexas com matrizes e manipulação de texto. Este guia irá ajudá-lo a explorar todas as ferramentas disponíveis.

#### **Navegando pelo Menu Principal**

Ao iniciar o programa, o terminal exibirá o **Menu Principal**. Ele é o centro de comando para todas as funcionalidades.

```
==================================================
                 MENU PRINCIPAL
==================================================
1. Calculadora Básica
2. Calculadora Científica
3. Operações Matriciais
4. Testes de String (Texto)
5. Mostrar Histórico
6. Limpar Histórico
0. Sair
==================================================
```
#### Comando para compilar o código:
```bash
gcc main.c -o calculadora -lm
```

#### Execução:

```bash
./calculadora
```

Para selecionar uma ferramenta, digite o número correspondente e pressione **Enter**.

> **Dica de Navegação:** Após concluir uma tarefa em qualquer modo, o programa perguntará se deseja continuar naquela função (`s` para sim, `n` para não). Ao escolher `n`, você retornará automaticamente para este menu.

---

### **1. Calculadora Básica (Opção 1)**

Ideal para o dia a dia. Esta função processa expressões matemáticas completas respeitando a precedência de operadores.

**Como usar:**
1.  Escolha a **Opção 1**.
2.  Digite a expressão completa na mesma linha.
3.  Pressione **Enter**.

**Operadores Suportados:**
*   `+` (Soma)
*   `-` (Subtração)
*   `*` (Multiplicação)
*   `/` (Divisão)
*   `^` (Potência)
*   `( )` (Parênteses para agrupar)

**Exemplos:**
*   `2 + 2`
*   `(10 * 5) / 2 + 3^2`
*   `4.5 * 2 - 1`

---

### **2. Calculadora Científica (Opção 2)**

Ferramentas avançadas para engenharia e matemática. Aqui você seleciona primeiro o tipo de cálculo e depois insere os valores.

**Menu Interno:**
1.  **Trigonometria:**
    *   Digite a função (`sin`, `cos`, `tan`) e o ângulo em **radianos**.
    *   *Exemplo:* `sin 1.57`
2.  **Logaritmos:**
    *   Digite o tipo (`log10`, `ln`) e o valor positivo.
    *   *Exemplo:* `log10 100`
3.  **Raiz Quadrada:**
    *   Digite apenas o número (deve ser positivo).
4.  **Potenciação:**
    *   Digite a base e o expoente separados por espaço.
    *   *Exemplo:* `2 3` (resulta em 8).
5.  **Fatorial (!):**
    *   Digite um número inteiro entre 0 e 20.

---

### **3. Operações Matriciais (Opção 3)**

Realiza cálculos de álgebra linear com matrizes de tamanho dinâmico (você define o tamanho).

**Funcionalidades:**

*   **1. Soma de Matrizes:**
    *   Soma duas matrizes (A + B).
    *   **Requisito:** As duas matrizes devem ter exatamente o mesmo número de linhas e colunas.

*   **2. Multiplicação de Matrizes:**
    *   Multiplica duas matrizes (A × B).
    *   **Requisito:** O número de **colunas** da Matriz A deve ser igual ao número de **linhas** da Matriz B.

*   **3. Transposição:**
    *   Inverte as linhas pelas colunas de uma matriz.

**Como preencher:**
1.  O programa pedirá as dimensões: digite `Linhas Colunas` (ex: `2 2` para uma matriz 2x2).
2.  Em seguida, preencha valor por valor conforme solicitado na tela (`[0][0]`, `[0][1]`, etc).

---

### **4. Testes de String (Opção 4)**

Um módulo dedicado à manipulação e análise de textos (strings).

**Funcionalidades:**

1.  **Comparar:** Verifica se dois textos são iguais ou qual vem primeiro alfabeticamente.
2.  **Copiar:** Cria uma cópia exata de um texto na memória.
3.  **Concatenar:** Junta dois textos em um só.
4.  **Tamanho/Análise:** Conta quantos caracteres existem e informa a quantidade de **Vogais** e **Consoantes**.
5.  **Inverter:** Escreve o texto de trás para frente (ex: "ROMA" vira "AMOR").

---

### **5. Mostrar Histórico (Opção 5)**

Visualize uma lista de todos os cálculos bem-sucedidos realizados durante a sessão atual.

**Detalhes:**
*   O histórico é **dinâmico**: ele cresce automaticamente conforme você realiza mais contas, sem limite fixo inicial.
*   Exibe a expressão original e o resultado final.

---

### **6. Limpar Histórico (Opção 6)**

Apaga todos os registros salvos na memória para reiniciar a listagem.

**Segurança:**
*   O programa pedirá uma confirmação (`sim` ou `s`).
*   Se confirmado, a memória é liberada e o contador volta a zero.

---

**Desenvolvido com:** Linguagem C (Padrão C99)
**Recursos Técnicos:** Alocação Dinâmica, Ponteiros, Structs e Manipulação de Arquivos.
