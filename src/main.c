#include <stdio.h>

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

        
    } while (option != 0);
    
}