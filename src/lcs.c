/**
 * @file lcs.c
 * @brief Programação Dinâmica: Problema da Subsequência Comum Máxima
 * A sequencia mais longa de caracteres que aparece em duas strings na mesma ordem,
 * não necessariamente consecutiva.
 * @version 0.2
 * 
 * @author sayu
 * @date 2024-12-08
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMatrix(int** m, int line, int column) {
    printf ("  ");
    for (int j = 0; j < column; j++) {
        printf("%d  ", j);
    }
    printf("\n");
    for (int i = 0; i < line; i++) {
        printf ("%d  ", i);
        for (int j = 0; j < column; j++) {
            printf ("%d  ", m[i][j]);
        }
        printf("\n");
    }
}

int main () {
    char string1[] = "aabfga";
    char string2[] = "aabbfg";
    int** mDinamica = (int**)malloc(7*sizeof(7*sizeof(int)));
    if (mDinamica != NULL) printf("Exist\n");
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++) {
            if (i == 0 || j == 0) mDinamica[i][j] = 0;
            else if (string1[i] == string2[j]) mDinamica[i][j] = mDinamica[i-1][j-1]+1;
            else if (mDinamica[i-1][j] > mDinamica[i][j-1]) mDinamica[i][j] = mDinamica[i-1][j];
            else mDinamica[i][j] = mDinamica[i][j-1];
        }

    printMatrix(mDinamica, 7, 7);
    return 0;
}