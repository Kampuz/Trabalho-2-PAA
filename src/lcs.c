/**
 * @file lcs.c
 * @brief  Implementar o algoritmo para encontrar a
 * Longest Common Subsequence (LCS), ou maior
 * subsequência comum, entre duas strings fornecidas
 * pelo usuário.
 * @version 1.0
 * 
 * @author Kampuz & sayu
 * @date 2024-12-08
 * 
 */

#include "../include/lcs.h"

void findLCS(char * str1, char *str2) {
    int tamanho1 = strlen(str1);
    int tamanho2 = strlen(str2);
    int matriz[tamanho1 + 1][tamanho2 + 1];

    for (int i = 0; i <= tamanho1; i++)
    {
        for (int j = 0; j <= tamanho2; j++)
        {
            if ((i == 0) || (j == 0))
            {
                matriz[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1])
            {
                matriz[i][j] = matriz[i - 1][j - 1] + 1;
            } else {
                if (matriz[i - 1][j] > matriz[i][j - 1])
                {
                    matriz[i][j] = matriz[i - 1][j];
                } else {
                    matriz[i][j] = matriz[i][j - 1];
                }
                
            }
        }
    }

    printf("Comprimento da LCS: %d\n", matriz[tamanho1][tamanho2] - 1);
    
    int index = matriz[tamanho1][tamanho2];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = tamanho1, j = tamanho2;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        } else if (matriz[i - 1][j] > matriz[i][j - 1])
        {
            i--;
        } else {
            j--;
        }
    }
        
        printf("LCS: %s\n", lcs);
}

void executeLCS() {
    char str1[MAX_CHAR];
    char str2[MAX_CHAR];

    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);

    findLCS(str1, str2);
}