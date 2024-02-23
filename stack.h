#ifndef STACK_H
#define STACK_H

#include "elements.h"
#include "types.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Structure to implement a stack. To be defined in stack_.c
 *
 **/
typedef struct _Stack Stack;

// /**
//  * @brief Typedef for a function pointer to print a stack element at stream
//  **/
typedef int (*print_elem_fn)(FILE *, const void *);

/**
 * @brief Create empty stack.
 *
 * @return   This function returns a pointer to the stack or a null pointer
 * if insufficient memory is available to create the stack.
 *  */
Stack *stack_new();

/**
 * @brief  Free the memory used by the stack.
 * @param s A pointer to the stack
 *  */
void stack_free(Stack *s);

/**
 * @brief Insert an element at the top of the stack, increasing the stack's size
 * if neededed
 *
 * @param s A pointer to the stack.
 * @param elem A pointer to the element to be inserted
 * @return This function returns OK on success or ERROR if the stack is full.
 *  */
Status stack_push(Stack *s, const void *elem);

/**
 * @brief  Extract element from top of the stack.
 *
 * @param s A pointer to the stack.
 * @return A pointer to the extracted element on success
 * or null when the stack is empty.
 * */
void *stack_pop(Stack *s);

/**
 * @brief  Return a pointer to the top stack element, without removing it from
 * the stack
 *
 * @param s A pointer to the stack.
 * @return Pointer to top stack element.
 * */
void *stack_top(const Stack *s);

/**
 * @brief Return whether the stack is empty
 * @param s A pointer to the stack.
 * @return boolean
 */
bool stack_isEmpty(const Stack *s);

/**
 * @brief Return the number of elements in the stack.
 *
 * @param s A pointer to the stack.
 * @return number of elements currently in the stack
 */
int stack_count(const Stack *s);

/**
 * @brief  This function writes the elements of the stack to the stream.
 * @param fp A pointer to the stream
 * @param s A pointer to the element to the stack
 * @return Upon successful return, these function returns the number of
 * characters writted. The function returns a negative value if there was a
 * problem writing to the file.
 *  */
int stack_print(FILE *fp, const Stack *s, print_elem_fn print);

#endif /* STACK_FDOBLE_H */
