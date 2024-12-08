#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// :: STRUCTS ::

/**
 * @brief Person struct:
 * Each person has an array for the task associated
 * with each index, each index has a cost attributed.
 */
typedef struct {
    int* cost;
} person;

/**
 * @brief Table struct:
 * An array of people, as to consider the main problem
 * that is assigning people to do the tasks with the
 * least cost possible.
 */
typedef struct {
    person* people;
    int numberPeople;
    int numberTasks;
} table;

// :: TABLE METHODS ::

/**
 * @brief Create a Table object
 * 
 * @param numberPeople 
 * @param numberTasks 
 * @return table* 
 */
table* createTable(int numberPeople, int numberTasks);
/**
 * @brief Create a Person object
 * 
 * @param table 
 * @return person 
 */
person createPerson(table* table);
/**
 * @brief Add Cost to a Task of a Person
 * 
 * @param table 
 * @param p 
 * @param t 
 * @param cost 
 */
void addCost(table* table, int p, int t, int cost);
/**
 * @brief Read table input
 * 
 * @return table* 
 */
table* readTable();

// :: TABLE DEBUG METHODS ::

/**
 * @brief Debug: Show Table
 * 
 * @param table 
 */
void debug_table(table* table);
/**
 * @brief Debug: Create a Table Object
 * 
 * @param numberPeople 
 * @param numberTasks 
 * @return table* 
 */
table* debug_createTable(int numberPeople, int numberTasks);
/**
 * @brief Debug: Create a Person Object
 * 
 * @param table 
 * @return person 
 */
person debug_createPerson(table* table);
/**
 * @brief Debug: Add Cost to a Task of a Person
 * 
 * @param table 
 * @param p 
 * @param t 
 * @param cost 
 */
void debug_addCost(table* table, int p, int t, int cost);
/**
 * @brief Debug: Read table input
 * 
 * @return table* 
 */
table* debug_readTable();

// :: ASSIGNMENT METHODS ::

/**
 * @brief Assign a task for each index, representing
 * each person
 * 
 * @param table 
 * @return int* 
 */
int* assignTask(table* table);
/**
 * @brief Show Best Assigment Array
 * 
 * @param assignment 
 * @param table 
 */
void printAssignment(int* assignment, table* table);

/**
 * @brief Free a Table
 * 
 * @param table 
 */
void freeTable(table* table);

/**
 * @brief Function to execute the code
 * 
 */
void executeAssignment();

#endif