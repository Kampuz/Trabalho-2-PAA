#ifndef BOOLEAN_KNAPSACK_
#define BOOLEAN_KNAPSACK_

/**
 * @brief Represents an item that can be placed in the backpack.
 * 
 * @param weight Weight of the item.
 * @param value Value of the item.
 */
typedef struct {
    int value, weight;
} ITEM;

/**
 * @brief Represents a backpack used in the knapsack problem.
 * 
 * @param value Total value of the items in the backpack.
 * @param capacity Maximum weight the backpack can hold.
 * @param itemCount Number of the items in the backpack.
 * @param items Pointer to the list of items in the backpack.
 */
typedef struct {
    int value, capacity, itemCount;
    ITEM *items;
} BACKPACK;

/**
 *  @brief Creates a backpack with specified capacity and item count.
 * 
 *  @param capacity Maximum weight the backpack can hold.
 *  @param numItems Number of items that will be considered for the backpack.
 *  @return BACKPACK* Pointer to the newly created backpack.
 */
BACKPACK *createBackpack(int capacity, int numItems);

/**
 *  @brief Reads item data and creates a list of items.
 * 
 *  @param numItems Number of items to be created.
 *  @return ITEM* Pointer to the list of created items.
 */
ITEM *readItems(int numItems);

/**
 *  @brief Finds the maximum of two integers.abort
 * 
 *  @param a First integer value.
 *  @param b Second integer value.
 *  @return int The larger of the two values.
 */
int max(int a, int b);

/**
 *  @brief Optimizes the backpack value using dynamic programming.
 * 
 *  @param backpack Pointer to the backpack structure.
 *  @param items Pointer to the list of items
 *  @param numItems Number of items in the list.
 *  @return int Maximum value that can be achieved.
 */
int backpackDP(BACKPACK *backpack, ITEM *items, int numItens);

/**
 *  @brief Prints the result to the knapsack problem
 * 
 *  @param backpack Pointer to the optimized backpack.
 */
void printResult(BACKPACK *backpack);

/**
 * @brief Executes the main workflow for solving the problem.
 */
void executeBooleanKnapsack();

#endif