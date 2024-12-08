#include <stdio.h>
#include "../include/assignment.h"

int main() {
    int option = -1;

    do {
        printf("Escolha uma opção:\n");
        printf("1. Problema de Associação de Tarefas\n");
        printf("2. Codificação de Huffman\n");
        printf("3. Mochila Fracionária\n");
        printf("4. Mochila Booleana\n");
        printf("5. Subsequência Comum Máxima\n");
        printf("0. Sair\n");
        scanf("%d", &option);
        
        switch(option) {
            case 0: break;
            case 1:
            executeAssignment();
            break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            default: break;
        }
    } while (option != 0);
    
}