# Trabalho de PAA

```txt
projeto/
│
├── src/                  # Código-fonte principal
│   ├── assignment.c            # Implementação do problema de Associação de Tarefas
│   ├── huffman.c               # Implementação do algoritmo de Huffman
│   ├── fractional_knapsack.c   # Implementação do problema da Mochila Fracionária
│   ├── boolean_knapsack.c      # Implementação do problema da Mochila Booleana
│   ├── lcs.c                   # Implementação da Subsequência Comum Máxima (LCS)
│   ├── utils.c                 # Funções auxiliares (opcional)
│   └── main.c                  # Ponto de entrada do programa
│
├── include/              # Arquivos de cabeçalho
│   ├── assignment.h            # Cabeçalho para funções do problema de Associação de Tarefas
│   ├── huffman.h               # Cabeçalho para funções do algoritmo de Huffman
│   ├── fractional_knapsack.h   # Cabeçalho para funções do problema da Mochila Fracionária
│   ├── boolean_knapsack.h      # Cabeçalho para funções do problema da Mochila Booleana
│   ├── lcs.h                   # Cabeçalho para funções da Subsequência Comum Máxima (LCS)
│   └── utils.h                 # Cabeçalho para funções auxiliares
│
└── README.md             # Documentação do projeto
```

## Divisão de Trabalhos

1. Associação de Tarefas @a-sayu
2. Codificação de Huffman @Kampuz
3. Mochila Fracionária @a-sayu
4. Mochila Booleana @Kampuz
5. Sequencia Comum Máxima @a-sayu & @Kampuz

## Metodo de Compilação

gcc src/assignment.c src/boolean_knapsack.c src/fractional_knapsack.c src/huffman.c src/lcs.c src/utils.c src/main.c -o main

## Executar

./main
