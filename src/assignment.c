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

/* Useless
typedef struct {
    char* taskName;
    int index;
} task; //kinda miscellaneous
*/

// TABLE

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

person createPerson(table* table) {
    person newPerson;
    newPerson.cost = (int*)malloc(table->numberTasks * sizeof(int));
    for (int i = 0; i < table->numberTasks; i++)
        newPerson.cost[i] = -1;
    return newPerson;
}

/* Useless
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
*/

void addCost(table* table, int p, int t, int cost) {
    table->people[p].cost[t] = cost;
}

table* readTable() {
    int n, c;
    printf ("Number of people/tasks = ");
    scanf ("%d", &n);
    getchar();
    table* table = createTable(n, n);
    for (int i = 0; i < n; i++)
        table->people[i] = createPerson(table);
    for (int i = 0; i < n; i++) {
        printf ("Person %d\n", i);
        for (int j = 0; j < n; j++) {
            printf ("Cost to task %d = ", j);
            scanf ("%d", &c);
            addCost(table, i, j, c);
        }
    }
    return table;
}

// DEBUG TABLE

void debug_table(table* table) {
    printf ("\n:: DEBUG TABLE ::\n");
    if (table != NULL) printf ("Table Exists\n");
    else return;
    printf ("Number People: %d\n", table->numberPeople);
    printf ("Number Tasks: %d\n", table->numberTasks);
    if (table->people != NULL) printf ("There are people\n");
    else return;
    for (int i = 0; i < table->numberPeople; i++) {
        if (&(table)->people[i] == NULL) break;
        printf ("Person %d\n", i);
        for (int j = 0; j < table->numberTasks; j++) {
            printf ("Task %d: %d\n", j, table->people[i].cost[j]);
        }
    }
}

table* debug_createTable(int numberPeople, int numberTasks) {
    printf ("\n:: DEBUG CREATE TABLE ::\n");
    printf ("People: %d Tasks: %d\n", numberPeople, numberTasks);
    table* newTable = (table*)malloc(sizeof(table));
    if (newTable != NULL ) printf ("Table Allocated\n");
    newTable->numberPeople = numberPeople;
    printf ("numPeople: %d\n", newTable->numberPeople);
    newTable->numberTasks = numberTasks;
    printf ("numTasks: %d\n", newTable->numberTasks);
    newTable->people = (person*)malloc(numberPeople * sizeof(person));
    if (newTable->people != NULL) printf ("People Allocated\n");

    return newTable;
}

person debug_createPerson(table* table) {
    printf ("\n:: DEBUG CREATE PERSON ::\n");
    person newPerson;
    newPerson.cost = (int*)malloc(table->numberTasks * sizeof(int));
    if (newPerson.cost != NULL) printf("Cost Array Allocated\n");
    for (int i = 0; i < table->numberTasks; i++) {
        newPerson.cost[i] = -1;
        printf("Task Added\n");
    }
    return newPerson;
}

void debug_addCost(table* table, int p, int t, int cost) {
    printf ("\n:: DEBUG ADD COST ::\n");
    printf ("People %d, Task %d\n", p, t);;
    table->people[p].cost[t] = cost;
    if (table->people[p].cost[t] == cost) printf ("Cost %d Added\n", cost);
}

table* debug_readTable() {
    printf ("\n:: DEBUG READ TABLE ::\n");
    int n, c;
    printf ("Number of people/tasks = ");
    scanf ("%d", &n);
    getchar();
    printf ("Number People: %d, Number Tasks: %d\n", n, n);
    table* table = debug_createTable(n, n);
    if (table != NULL) printf ("Table Exists\n");
    for (int i = 0; i < n; i++) {
        printf ("Current Person: %d\n", i);
        table->people[i] = debug_createPerson(table);
    }
    for (int i = 0; i < n; i++) {
        printf ("Current Person: %d\n", i);
        for (int j = 0; j < n; j++) {
            printf ("Current Task: %d\n", i);
            printf ("Cost to current task = ");
            scanf ("%d", &c);
            debug_addCost(table, i, j, c);
        }
    }
    return table;
}

int main () {
    table* newTable;
    /* RAW TEST
    newTable = debug_createTable(2, 2);
    newTable->people[0] = debug_createPerson(newTable);
    newTable->people[1] = debug_createPerson(newTable);
    debug_addCost(newTable, 0, 0, 2);
    debug_table(newTable);
    */

   newTable = debug_readTable();
   debug_table(newTable);
    
    return 0;
}

    // PLAN:
    // :: TABLE MANIPULATION ::
    // create table();
    // create person();
    // add person to table();
    // create task();
    // assign task() = add task costs();
    // read table();

    // :: BRANCH AND BOUND ::
    // find best task arrangement();

    // :: DEBUG ::
    // show table();
