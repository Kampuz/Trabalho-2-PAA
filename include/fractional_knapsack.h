#ifndef FRACTIONAL_KNAPSACK_H
#define FRACTIONAL_KNAPSACK_H

typedef struct {
    int id;
    int weight;
    int value;
    float ratio;
} object;

typedef struct {
    int maxWeight;
    float* fractionStored;
    int* ids;
} knapsack;

object createObject(int id, int weight, int value);
object* addObjects(int n);
knapsack createKnapsack(int maxWeight, int n);
void quickSort(object* array, int low, int high);
int fillKnapsack(knapsack* knapsack, object* objects, int n);
void printResults(knapsack* knapsack, object* objects, int n, int totalValue);
void executeKnapsack();

#endif