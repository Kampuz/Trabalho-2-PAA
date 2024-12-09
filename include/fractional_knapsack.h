#ifndef FRACTIONAL_KNAPSACK_H
#define FRACTIONAL_KNAPSACK_H

/**
 * @brief Structure representing an object in the fractional knapsack problem.
 * 
 * The structure contains information about the identifier, weight, value, and value/weight ratio of an object.
 */
typedef struct {
    int id;
    int weight;
    int value;
    float ratio;
} object;

/**
 * @brief Structure representing a knapsack in the fractional knapsack problem.
 * 
 * The structure contains the maximum weight of the knapsack, a list of stored fractions of objects,
 * and the identifiers of the objects that have been chosen for the knapsack.
 */
typedef struct {
    int maxWeight;
    float* fractionStored;
    int* ids;
} knapsack;

/**
 * @brief Creates an object with the given parameters.
 * 
 * This function creates an object with an identifier, weight, value, and calculates the value-to-weight ratio.
 * 
 * @param id Unique identifier of the object.
 * @param weight Weight of the object.
 * @param value Value of the object.
 * @return object The created object structure.
 */
object createObject(int id, int weight, int value);

/**
 * @brief Adds multiple objects to the system.
 * 
 * This function allocates memory for a specified number of objects and initializes their properties.
 * 
 * @param n Number of objects to be created.
 * @return object* Array of created objects.
 */
object* addObjects(int n);

/**
 * @brief Creates a knapsack with the given properties.
 * 
 * This function creates a knapsack with the specified maximum weight and the number of objects it can carry.
 * 
 * @param maxWeight Maximum weight the knapsack can carry.
 * @param n Number of objects the knapsack can carry.
 * @return knapsack The created knapsack structure.
 */
knapsack createKnapsack(int maxWeight, int n);

/**
 * @brief Sorts objects based on the value/weight ratio using the QuickSort algorithm.
 * 
 * This function sorts the objects to optimize the selection of objects to be placed in the knapsack.
 * 
 * @param array Array of objects to be sorted.
 * @param low Starting index of the array to be sorted.
 * @param high Ending index of the array to be sorted.
 */
void quickSort(object* array, int low, int high);

/**
 * @brief Fills the knapsack with objects based on the value/weight ratio and the maximum weight of the knapsack.
 * 
 * This function selects objects for the knapsack according to the value/weight sorting and fills the knapsack
 * with fractions of the objects until the maximum weight is reached.
 * 
 * @param knapsack Pointer to the knapsack structure where objects will be stored.
 * @param objects Array of available objects to be placed in the knapsack.
 * @param n Number of available objects.
 * @return int Total value of the objects placed in the knapsack.
 */
int fillKnapsack(knapsack* knapsack, object* objects, int n);

/**
 * @brief Prints the results of the knapsack problem, including the selected objects and the total value.
 * 
 * This function prints the contents of the knapsack and the total value of the objects that were selected.
 * 
 * @param knapsack Pointer to the knapsack structure containing the selected objects.
 * @param objects Array of available objects.
 * @param n Number of available objects.
 * @param totalValue Total value of the objects in the knapsack.
 */
void printResults(knapsack* knapsack, object* objects, int n, int totalValue);

/**
 * @brief Executes the fractional knapsack algorithm.
 * 
 * This function runs the full flow of the fractional knapsack algorithm, creating the objects,
 * sorting them, filling the knapsack, and printing the results.
 */
void executeKnapsack();

#endif
