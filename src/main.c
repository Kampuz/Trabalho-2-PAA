#include <stdio.h>

#include "../include/boolean_knapsack.h"

int main() {
    int option = -1;

    do
    {
        do
        {
            printf("Escolha uma opção:\n");
            printf("1. Problema de Associação de Tarefas\n");
            printf("2. Codificação de Huffman\n");
            printf("3. Mochila Fracionária\n");
            printf("4. Mochila Booleana\n");
            printf("5. Subsequência Comum Máxima\n");
            printf("0. Sair\n");
            scanf("%d", option);
        } while ((option > 5) || (option < 0));

        switch (option)
        {
        case 1:
            /* code */
            break;
        
        case 2:
            /* code */
            break;
        
        case 3:
            /* code */
            break;
        
        case 4:
            booleanKnapsack();
            break;
        
        case 5:
            /* code */
            break;
        
        case 0:
            printf("Saindo...\n");
            break;
        
        default:
            printf("Opção Inválida!\n");
            break;
        }
        
    } while (option != 0);
    
}