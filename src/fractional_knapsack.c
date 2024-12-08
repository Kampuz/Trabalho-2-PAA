/**
 * @file fractional_knapsack.c
 * @brief Algoritmo Guloso: Problema da Mochila Fracionária.
 * 1. Conjunto de Objetos a serem adicionados à uma Mochila.
 * 2. Cada Objeto tem um peso(ocupação na mochila) e um valor
 * 3. É possivel fracionar objetos.
 * 4. A mochila tem um peso máximo.
 * @version 0.1
 * 
 * @author sayu
 * @date 2024-12-08
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/fractional_knapsack.h"

int partition(object* array, int low, int high) {
    float pivot = array[high].ratio;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j].ratio > pivot) {
            i++;
            object temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    object temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

void quickSort(object* array, int low, int high) {
    if (low < high) {
        int partition_index = partition(array, low, high);

        quickSort(array, low, partition_index - 1);
        quickSort(array, partition_index + 1, high);
    }
}

knapsack createKnapsack(int maxWeight, int n) {
    knapsack newKnapsack;
    newKnapsack.maxWeight = maxWeight;
    newKnapsack.fractionStored = (float*)malloc(n*sizeof(float));
    return newKnapsack;
}

object createObject(int w, int v) {
    object newObject;
    newObject.weight = w;
    newObject.value = v;
    newObject.ratio = (float)v/w;
    return newObject;
}

object* addObjects(int n) {
    int w, v, i = 0;
    object* arrayObjects = (object*)malloc(n*sizeof(object));
    do {
        printf("Object %d\n", i);
        printf ("Weight: ");
        scanf("%d", &w);
        getchar();
        printf ("Value: ");
        scanf("%d", &v);
        getchar();
        if (w <= 0 || v < 0) break;
        arrayObjects[i] = createObject(w, v);
        i++;
    } while (i != n);
    quickSort(arrayObjects, 0, n-1);

    return arrayObjects;
}

int fillKnapsack(knapsack* knapsack, object* objects, int n) {
    int currentWeight = knapsack->maxWeight;
    int totalValue = 0;

    for (int i = 0; i < n; i++) {
        if(objects[i].weight <= currentWeight) {
            knapsack->fractionStored[i] = 1.0;
            currentWeight -= objects[i].weight;
            totalValue += objects[i].value;
        } else if (currentWeight > 0) {
            knapsack->fractionStored[i] = (float)currentWeight / objects[i].weight;
            totalValue += objects[i].value * knapsack->fractionStored[i];
            break;
        }
    }

    return totalValue;
}

void printResults(knapsack* knapsack, object* object, int n, int totalValue) {
    printf("Capacidade total da mochila: %d\n", knapsack->maxWeight);
    printf("Valor total da mochila: %d\n", totalValue);
    printf("Fracoes dos objetos na mochila:\n");
    for (int i = 0; i < n; i++) {
        if (knapsack->fractionStored[i] > 0)
            printf("Object %d: %f\n", i, knapsack->fractionStored[i]);
    }
}

void executeKnapsack() {
    int n, m;
    printf ("Object Number = ");
    scanf("%d", &n);
    getchar();
    printf ("Knapsack Max Weight = ");
    scanf("%d", &m);
    getchar();

    object* arrayObjects = addObjects(n);
    knapsack newKnapsack = createKnapsack(m, n);

    int totalValue = fillKnapsack(&newKnapsack, arrayObjects, n);
    printResults(&newKnapsack, arrayObjects, n, totalValue);

    free(arrayObjects);
    free(newKnapsack.fractionStored);
}

