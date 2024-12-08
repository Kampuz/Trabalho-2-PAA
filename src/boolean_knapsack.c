#include <stdio.h>
#include <stdlib.h>

#include "../include/boolean_knapsack.h"


BACKPACK *createBackpack(int capacity, int numItems) {
    BACKPACK *newBackpack = (BACKPACK*)malloc(sizeof(BACKPACK));
    
    newBackpack->capacity = capacity;
    
    newBackpack->value = 0;
    newBackpack->itemCount = 0;
    
    newBackpack->items = (ITEM*)malloc(numItems * sizeof(ITEM));

    return newBackpack;

}

ITEM *readItems(int numItems) {
    ITEM *items = (ITEM*)malloc(numItems * sizeof(ITEM));

    for (int i = 0; i < numItems; i++)
    {
        printf("Digte o valor e peso do item %d (i. e. 0 0): ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    return items;
}

int max(int a, int b) {
    if (a > b)
    {
        return a;
    } else 
    {
        return b;
    }
    
}

int backpackDP(BACKPACK *backpack, ITEM *items, int numItens) {
    int capacity = backpack->capacity;

    int dp[numItens + 1][capacity + 1];

    for (int i = 0; i <= numItens; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if ((i == 0) || (w == 0))
            {
                dp[i][w] = 0;
            } else if (items[i - 1].weight <= w)
            {
                dp[i][w] = max(dp[i - 1][w],
                            dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else
            {
                dp[i][w] = dp[i - 1][w];
            }
            
        }
        
    }
    
    backpack->value = dp[numItens][capacity];

    int w = capacity;

    for (int i = numItens; ((i > 0) && (w > 0)); i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            backpack->items[backpack->itemCount++] = items[i - 1];
            w -= items[i - 1].weight;
        }
        
    }

    return backpack->value;
}

void printResult(BACKPACK *backpack) {
    printf("Value of the backpack: %d\n", backpack->value);
    printf("Items choosen:\n");
    for (int i = 0; i < backpack->itemCount; i++)
    {
        printf("Item %d - Valor: %d, Peso: %d\n", i + 1, backpack->items[i].value, backpack->items[i].weight);
    }
    
}


void booleanKnapsack() {

    int capacity = 0, numItems = 0;

    printf("Capacity of the backpack: ");
    scanf("%d", &capacity);

    printf("Number of the items to be inserted: ");
    scanf("%d", &numItems);

    system("clear");

    ITEM *itens = readItems(numItems);

    BACKPACK *backpack = createBackpack(capacity, numItems);

    backpackDP(backpack, itens, numItems);

    printResult(backpack);

    free(itens);
    free(backpack->items);

}


