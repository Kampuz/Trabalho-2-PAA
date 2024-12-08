/**
 * @file assignment.c
 * @brief Branch & Bound - Força Bruta: Problema de Associação de Tarefas
 * @version 0.5
 * 
 * @author sayu
 * @date 2024-12-07
 * 
 */

#include "../include/assignment.h"

// TABLE

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
            getchar();
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
            getchar();
            debug_addCost(table, i, j, c);
        }
    }
    return table;
}

// ASSIGNMENT PROBLEM

void assignRecursive(table* table, int* assigned, int currentTask, int* bestCost, int currentCost, int* bestAssignment);

int* assignTask(table* table) {
    int n = table->numberTasks, totalCost = 0;
    int* assigned = malloc(n * sizeof(int));
    int* bestAssignment = malloc(n*sizeof(int));
    int bestCost = INT_MAX;
    for (int i = 0; i < n; i++) assigned[i] = -1;
    for (int i = 0; i < n; i++) bestAssignment[i] = -1;
    assignRecursive(table, assigned, 0, &bestCost, 0, bestAssignment);

    return bestAssignment;
}

void assignRecursive(table* table, int* assigned, int currentTask, int* bestCost, int currentCost, int* bestAssignment) {
    if (currentTask == table->numberTasks) {
        if (currentCost < *bestCost) {
            *bestCost = currentCost;
            for(int i = 0; i < table->numberTasks; i++) bestAssignment[i] = assigned[i];
        }
        return;
    }

    for (int i = 0; i < table->numberPeople; i++) {
        if (assigned[i] == -1) {
            assigned[i] = currentTask;
            currentCost = currentCost + table->people[i].cost[currentTask];
            if (currentCost < *bestCost) {
                assignRecursive(table, assigned, currentTask+1, bestCost, currentCost, bestAssignment);
            }
            assigned[i] = -1;
            currentCost = currentCost - table->people[i].cost[currentTask];
        }
    }
}

void printAssignment(int* assignment, table* table) {
    printf ("\nBest Assigment:\n");
    int totalCost = 0;
    for (int i = 0; i < table->numberPeople; i++) {
        printf ("Person %d -> Task %d (Cost: %d)\n", i, assignment[i], table->people[i].cost[assignment[i]]);
        totalCost += table->people[i].cost[assignment[i]];
    }
    printf("Total Cost: %d\n", totalCost);
}

void executeAssignment() {
    table* newTable = readTable();
    printf ("Table Read!\n");
    int* assignment = assignTask(newTable);
    printAssignment(assignment, newTable);
    free(assignment);
    freeTable(newTable);
}

void freeTable(table* table) {
    if (table == NULL) return;

    for (int i = 0; i < table->numberPeople; i++) {
        free(table->people[i].cost);
    }

    free(table->people);

    free(table);
}