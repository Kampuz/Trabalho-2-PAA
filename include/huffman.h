#ifndef HUFFMAN_
#define HUFFMAN_

#define MAX_CHAR 256

/**
 * @brief A structure representing a node in the Huffman tree.
 * @param data Character stored in the node.
 * @param req Frequency of the character in the input text.
 * @param right Pointer to the right child node.
 * @param left Pointer to the left child node.
 */
typedef struct node {
    char data;
    unsigned freq;
    struct node *right, *left;
} NODE;

/**
 * @brief Creates a new node for the Huffman tree.
 * 
 * @param data The character to be stored in the node.
 * @param freq The frequency of the character.
 * @return NODE* A pointer to the newly created node.
 */
NODE *createNode(char data, unsigned freq);

/**
 * @brief Frees the memory allocated for a Huffman tree.
 * 
 * @param root Pointer to the root node of the Huffman tree.
 */
void freeTree(NODE *root);

/**
 * @brief Finds the two smallest frequency nodes in an array of nodes.
 * 
 * @param nodes Array of pointers to nodes.
 * @param size Number of nodes in the array.
 * @param smallest Pointer to store the index of the smallest frequency node.
 * @param secondSmallest Pointer to store the index of the second smallest frequency node.
 */
void findTwoSmallests(NODE *nodes[], int size, int *smallest, int *secondSmallest);

/**
 * @brief Builds a Huffman tree from given characters and their frequencies.
 * 
 * @param data Array of characters.
 * @param freq Array of frequencies corresponding to the characters.
 * @param size Number of characters in the input arrays.
 * @return NODE* Pointer to the root node of the constructed Huffman tree.
 */
NODE *buildTree(char data[], int freq[], int size);

/**
 * @brief Generates Huffman codes for all characters in the tree.
 * 
 * @param root Pointer to the root node of the Huffman tree.
 * @param code Array used for storing the current code during traversal.
 * @param top Current depth of the code in the tree.
 * @param codes Array to store the Huffman codes for all characters.
 */
void generateCodes(NODE *root, char code[], int top, char codes[MAX_CHAR][MAX_CHAR]);

/**
 * @brief Encodes a given text using Huffman coding.
 * 
 * @param text The input text to be encoded.
 */
void huffmanCoding(char text[]);

/**
 * @brief Executes the Huffman coding process with user input.
 */
void executeHuffman();

#endif