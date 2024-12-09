#include <stdio.h>
#include <stdlib.h>

#include "../include/fractional_knapsack.h"
#include "../include/boolean_knapsack.h"
#include "../include/assignment.h"
#include "../include/huffman.h"
#include "../include/lcs.h"
#include "../include/../include/utils.h"

int main() {
    int option = -1;

    do {
        option = menu();

        switch(option) {
            case 0:
                printf ("Saindo...\n");
                break;
            case 1:
                executeAssignment();
                break;
            case 2: 
                executeHuffman();
                break;
            case 3: 
                executeKnapsack();
                break;
            case 4:
                executeBooleanKnapsack();
                break;
            case 5: 
                executeLCS();
                break;
            default:
                printf ("Opcao Invalida\n");
                break;
        }

        proceed();
    } while (option != 0);
    
}