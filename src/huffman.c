#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/huffman.h"

NODE *createNode(char data, unsigned freq) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void freeTree(NODE *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void findTwoSmallests(NODE *nodes[], int size, int *smallest, int *secondSmallest) {
    *smallest = -1;
    *secondSmallest = -1;

    for (int i = 0; i < size; i++)
    {
        if (nodes[i] != NULL)
        {
            if (*smallest == -1 || nodes[i]->freq < nodes[*smallest]->freq)
            {
                *secondSmallest = *smallest;
                *smallest = i;
            } else if (*secondSmallest == -1 || nodes[i]->freq < nodes[*secondSmallest]->freq)
                *secondSmallest = i;
        }
    }
}

NODE *buildTree(char data[], int freq[], int size) {
    NODE *nodes[MAX_CHAR];

    for (int i = 0; i < size; i++)
    {
        nodes[i] = createNode(data[i], freq[i]);
    }

    while (size > 1)
    {
        int smallest, secondSmallest;

        findTwoSmallests(nodes, size, &smallest, &secondSmallest);

        NODE *combined = createNode('$', nodes[smallest]->freq + nodes[secondSmallest]->freq);
        combined->left = nodes[smallest];
        combined->right = nodes[secondSmallest];

        nodes[smallest] = combined;
        nodes[secondSmallest] = nodes[size - 1];
        nodes[size - 1] = NULL;
        size--;
    }
    
    return nodes[0];
}

void generateCodes(NODE *root, char code[], int top, char codes[MAX_CHAR][MAX_CHAR]) {
    if (root->left)
    {
        code[top] = '0';
        generateCodes(root->left, code, top + 1, codes);
    }

    if (root->right)
    {
        code[top] = '1';
        generateCodes(root->right, code, top + 1, codes);
    }

    if (!root->left && !root->right)
    {
        code[top] = '\0';
        strcpy(codes[(int)root->data], code);
    }
}

void huffmanCoding(char text[]) {
    int freq[MAX_CHAR] = {0};
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        freq[(int)text[i]]++;
    }

    char data[MAX_CHAR];
    int frequencies[MAX_CHAR], size = 0;

    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (freq[i])
        {
            data[size] = (char)i;
            frequencies[size] = freq[i];
            size++;
        }
    }

    NODE *root = buildTree(data, frequencies, size);

    char codes[MAX_CHAR][MAX_CHAR] = {{0}};
    char code[MAX_CHAR];

    generateCodes(root, code, 0, codes);

    printf("Caractere | Código de Hufman\n");
    for (int i = 0; i < size; i++)
    {
        printf("    %c    | %s\n", data[i], codes[(int)data[i]]);
    }

    printf("\nTexto compactado: ");
    for (int i = 0; i < len; i++)
    {
        printf("%s", codes[(int)text[i]]);
    }
    printf("\n");

    freeTree(root);
}

void executeHuffman() {
    char text[MAX_CHAR];

    printf("Digite o texto a ser criptografado\n");

    fgets(text, sizeof(text), stdin);

    huffmanCoding(text);
}