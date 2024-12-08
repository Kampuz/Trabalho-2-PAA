#ifndef HUFFMAN_
#define HUFFMAN_

#define MAX_CHAR 256

typedef struct node {
    char data;
    unsigned freq;
    struct node *right, *left;
} NODE;

NODE *createNode(char data, unsigned freq);

void freeTree(NODE *root);

void findTwoSmallests(NODE *nodes[], int size, int *smallest, int *secondSmallest);

NODE *buildTree(char data[], int freq[], int size);

void generateCodes(NODE *root, char code[], int top, char codes[MAX_CHAR][MAX_CHAR]);

void huffmanCoding(char text[]);

void huffman();

#endif