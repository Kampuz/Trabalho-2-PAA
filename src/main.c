#include <stdio.h>
#include <stdlib.h>

#include "../include/boolean_knapsack.h"
#include "../include/assignment.h"
#include "../include/huffman.h"

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
        printf ("= ");
        scanf("%d", &option);
        getchar();
        
        switch(option) {
            case 0:
                printf ("Saindo...\n");
                break;
            case 1:
                executeAssignment();
                break;
            case 2: 
                huffman();
                break;
            case 3: break;
            case 4:
                booleanKnapsack();
                break;
            case 5: break;
            default:
                printf ("Opcao Inválida\n");
                break;
        }
        printf("Digite [ENTER] para continuar");
        getchar();
    } while (option != 0);
    
}