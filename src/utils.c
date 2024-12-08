#include <stdio.h>
#include <stdlib.h>

void proceed() {
    printf("Digite [ENTER] para continuar");
    getchar();
    return;
}

void menu(int *option) {
        printf("Escolha uma opção:\n");
        printf("1. Problema de Associação de Tarefas\n");
        printf("2. Codificação de Huffman\n");
        printf("3. Mochila Fracionária\n");
        printf("4. Mochila Booleana\n");
        printf("5. Subsequência Comum Máxima\n");
        printf("0. Sair\n");
        printf ("= ");
        scanf("%d", &option);
        getchar();
}