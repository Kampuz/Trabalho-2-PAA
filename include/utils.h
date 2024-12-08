#ifndef UTILS_
#define UTILS_

/**
 *  @brief Pauses the program and waits for the user to press [ENTER].
 */
void proceed();


/**
 *  @brief Displays a menu for problem selection and captures the user's choice.
 * 
 *  @param option Pointer to an integer where the selected menu option will be stored.
 */
void menu(int *option);

#endif