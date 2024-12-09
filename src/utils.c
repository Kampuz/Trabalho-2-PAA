#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"

void proceed() {
    printf("Digite [ENTER] para continuar");
    getchar();
    return;
}

int menu() {
    int option = -1;

    printf("Escolha uma opcao:\n");
    printf("1. Problema de Associacao de Tarefas\n");
    printf("2. Codificacao de Huffman\n");
    printf("3. Mochila Fracionaria\n");
    printf("4. Mochila Booleana\n");
    printf("5. Subsequência Comum Maxima\n");
    printf("0. Sair\n");
    printf ("= ");
    scanf("%d", &option);
    getchar();

    return option;
}