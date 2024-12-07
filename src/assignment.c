/**
 * @file assignment.c
 * @brief Branch & Bound - Força Bruta: Problema de Associação de Tarefas
 * @version 0.1
 * 
 * @author sayu
 * @date 2024-12-07
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Task struct:
 * It gives the related cell on the table a name
 * for the sake of presentability.
 */
typedef struct {
    char* taskName;
    int index;
} task; //kinda miscellaneous

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

table* createTable(int numberPeople, int numberTasks) {
    table* newTable = (table*)malloc(sizeof(table));
    newTable->numberPeople = numberPeople;
    newTable->numberTasks = numberTasks;
    newTable->people = (person*)malloc(numberPeople * sizeof(person));

    return newTable;
}

person* createPerson(table* table) {
    person* newPerson = (person*)malloc(sizeof(person));
    newPerson->cost = (int*)malloc(table->numberTasks * sizeof(int));
    for (int i = 0; i < table->numberTasks; i++)
        newPerson->cost[i] = -1;
    return newPerson;
}

void addPerson(table* table, person person) {
    int i;
    for (i = 0; i < table->numberPeople; i++)
        if (table->people == NULL) break;
    table->people[i] = person;
}

task* createTask(table* table, char* taskName) {
    int i;
    task* newTask = (task*)malloc(sizeof(task));
    newTask->taskName = taskName;
    for (i = 0; i < table->numberTasks; i++)
        if (table->people[0].cost[i] == -1) break;
    newTask->index = i;

    return newTask;
}

int main () {

    // :: TABLE MANIPULATION ::
    // create table();
    // create person();
    // add person to table();
    // create task();
    // assign task() = add task costs();

    // :: BRANCH AND BOUND ::
    // find best task arrangement();

    // :: DEBUG ::
    // show table();
    
}
