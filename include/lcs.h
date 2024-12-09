#ifndef LCS_
#define LCS_

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

/**
 * @brief Finds the longest common subsequence (LCS) between two strings.
 * 
 * This function implements the dynamic programming algorithm to calculate the longest common
 * subsequence between two given strings and displays the resulting sequence.
 * 
 * @param str1 First string for which the LCS will be calculated.
 * @param str2 Second string for which the LCS will be calculated.
 */
void findLCS(char *str1, char *str2);

/**
 * @brief Function that executes the LCS calculation code.
 * 
 * This function starts the process of reading the strings and calls the function to find
 * and display the longest common subsequence between the two strings.
 */
void executeLCS();

#endif
