#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Item struct
 * An Item has a value and a weight
 */
typedef struct {
    int value, weight;
} item;

/**
 * @brief backpack struct
 * A backpack has 
 *      capacity (input inserted on the time of creation)
 *      value (defined by the value of the items it has)
 *      items (a list of itens (the objective is to put the items in a way it gives the backpack max value))
 */
typedef struct {
    int value, capacity;
    item *items;
} backpack;

backpack *createBackpack(int capacity) {
    backpack *newBackpack = (backpack *)malloc(sizeof(backpack));

    newBackpack->capacity = capacity;
    
    newBackpack->value = 0;
    
    newBackpack->items = (item*)malloc(capacity * sizeof(int));

    return newBackpack;
}


int main() {
    backpack *back;

    int maxCapacity = 0, numItems = 0;

    printf("Digite o número máximo de itens: ");
    scanf("%d", &maxCapacity);

    back = createBackpack(maxCapacity);

    printf("Digite o número de itens a serem inseridos: ");
    scanf("%d", &numItems);

    item itens[numItems];

    for (int i = 0; i < numItems; i++)
    {
        
        printf("Digite o peso: ");
        scanf("%d", &itens[i].value);

        printf("Digite o valor: ");
        scanf("%d", &itens[i].weight);
    }


}


