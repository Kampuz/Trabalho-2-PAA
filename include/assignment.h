#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// :: STRUCTS ::

/**
 * @brief Structure representing a person in the assignment problem.
 * 
 * Each person has an array that associates each task with a specific cost.
 */
typedef struct {
    int* cost;
} person;

/**
 * @brief Structure representing the assignment table.
 * 
 * The table contains an array of people, considering the main problem of assigning people
 * to tasks with the lowest possible cost.
 */
typedef struct {
    person* people;
    int numberPeople;
    int numberTasks;
} table;

// :: TABLE METHODS ::

/**
 * @brief Creates a table with a specified number of people and tasks.
 * 
 * This function allocates memory for a table with the provided people and tasks.
 * 
 * @param numberPeople Number of people in the table.
 * @param numberTasks Number of tasks in the table.
 * @return table* Pointer to the created table.
 */
table* createTable(int numberPeople, int numberTasks);

/**
 * @brief Creates a person to be added to the table.
 * 
 * This function creates a person with an associated number of tasks and allocates the cost for each task.
 * 
 * @param table Pointer to the table to which the person will be added.
 * @return person The created person structure.
 */
person createPerson(table* table);

/**
 * @brief Adds the cost of a task to a person in the table.
 * 
 * This function sets the cost of a specific task for a specific person in the table.
 * 
 * @param table Pointer to the table that contains the person.
 * @param p Index of the person in the table.
 * @param t Index of the task to which the cost will be assigned.
 * @param cost Cost of the task assigned to the person.
 */
void addCost(table* table, int p, int t, int cost);

/**
 * @brief Reads the input of the table from an input source.
 * 
 * This function reads the input data to fill the table with the number of people, tasks, and costs.
 * 
 * @return table* Pointer to the table filled with input data.
 */
table* readTable();

// :: TABLE DEBUG METHODS ::

/**
 * @brief Debug: Displays the table with information about people and task costs.
 * 
 * This function is used to display the table in a readable format for debugging.
 * 
 * @param table Pointer to the table to be displayed.
 */
void debug_table(table* table);

/**
 * @brief Debug: Creates an assignment table with the specified number of people and tasks.
 * 
 * This function creates a table for debugging purposes.
 * 
 * @param numberPeople Number of people in the table.
 * @param numberTasks Number of tasks in the table.
 * @return table* Pointer to the created table for debugging.
 */
table* debug_createTable(int numberPeople, int numberTasks);

/**
 * @brief Debug: Creates a person for the assignment table.
 * 
 * This function creates a person for debugging purposes.
 * 
 * @param table Pointer to the table to which the person will be added.
 * @return person The created person structure for debugging.
 */
person debug_createPerson(table* table);

/**
 * @brief Debug: Adds a cost to a task for a person in the debug table.
 * 
 * This function assigns a cost to a specific task for a person for debugging purposes.
 * 
 * @param table Pointer to the table that contains the person.
 * @param p Index of the person in the table.
 * @param t Index of the task to which the cost will be assigned.
 * @param cost Cost of the task assigned to the person for debugging.
 */
void debug_addCost(table* table, int p, int t, int cost);

/**
 * @brief Debug: Reads the input to create the table for debugging purposes.
 * 
 * This function reads the input data to fill the debug table.
 * 
 * @return table* Pointer to the table filled for debugging purposes.
 */
table* debug_readTable();

// :: ASSIGNMENT METHODS ::

/**
 * @brief Assigns tasks to each person, represented by the indices, based on the lowest costs.
 * 
 * This function solves the assignment problem, finding the best combination of task assignments
 * for people with the lowest possible cost.
 * 
 * @param table Pointer to the table of people and tasks.
 * @return int* Array with the indices of the tasks assigned to each person.
 */
int* assignTask(table* table);

/**
 * @brief Displays the best assignment array.
 * 
 * This function prints the tasks assigned to each person and the minimum cost of the assignment.
 * 
 * @param assignment Array with the tasks assigned to each person.
 * @param table Pointer to the table containing the people and their tasks.
 */
void printAssignment(int* assignment, table* table);

/**
 * @brief Frees the memory allocated for the table.
 * 
 * This function frees all the memory that was allocated for the table, including the cost arrays
 * of the people and the table itself.
 * 
 * @param table Pointer to the table to be freed.
 */
void freeTable(table* table);

/**
 * @brief Function that executes the task assignment code.
 * 
 * This function starts the full flow of the task assignment problem, including reading
 * the data, executing the algorithm, and displaying the results.
 */
void executeAssignment();

#endif
