#ifndef BOOLEAN_KNAPSACK_
#define BOOLEAN_KNAPSACK_

/**
 * @brief an item that will be put inside the backpack;
 * @param weight how much the item weights;
 * @param value how much the item is worth;
 */
typedef struct {
    int value, weight;
} ITEM;

/**
 * @brief an backpack that will carry the items;
 * @param int Capacity = how much weight the backpack can handle;
 * @param int Value = how much the items inside the backpack are worth;
 * @param ITEM* Items =  the items inside the backpack;
 */
typedef struct {
    int value, capacity, itemCount;
    ITEM *items;
} BACKPACK;

/**
 *  @brief creates a backpack
 * 
 *  Assigns memory and default values to it
 * 
 *  @param int Capacity - how much weight the backpack can handle;
 *  @param int NumItems - the number of items that will be put inside the backpack;
 *  @return BACKPACK* (The backpack created)
 */
BACKPACK *createBackpack(int capacity, int numItems);

/**
 *  @brief reads and creates the item list
 * 
 *  Recieve the input, creates the item and put it in a list
 * 
 *  @param int NumItems - the number of items that will be put inside the backpack;
 *  @return ITEM* (The list of items created)
 */
ITEM *readItems(int numItems);

/**
 *  @brief calculates the bigger of two values
 * 
 *  @param int a number
 *  @param int a number
 *  @return int - the bigger number
 */
int max(int a, int b);

/**
 *  @brief does the optimization of the backpack (value to weight)
 * 
 *  @param BACKPACK* pointer to the backpack
 *  @param ITEM* list of items
 *  @param int number of items
 *  @return int
 */
int backpackDP(BACKPACK *backpack, ITEM *items, int numItens);

/**
 *  @brief prints the result to the problem
 * 
 *  @param BACKPACK* the address to the optimized backpack;
 *  @return Void
 */
void printResult(BACKPACK *backpack);

/**
 * @brief the main code of the boolean knapsack problem;
 * @return Void
 */
void executeBooleanKnapsack();

#endif