/* Renombrar este fichero como stack.c */
/* IMPLEMENTAR stack_new, stack_free y stack_push */
/* Probar la implementación tal como se indica en el enunciado */
/* Es decir, generar ejecutables para p2_e1.c p2_e2.c y p2_e3.c compilados con
 * el stack.o obtenido a partir de este fichero en vez de usando libstack.a
 */

#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct _Stack {
  void **data;
  int top;
  int capacity;
};

// ******* Private functions ************

//***********  Public Interface *************

Stack *stack_new() {}

void stack_free(Stack *s) {}

Status stack_push(Stack *s, const void *ele) {}

void *stack_pop(Stack *s) {
  void *ele;

  if (stack_isEmpty(s) == true) // return true if s == NULL
    return NULL;

  ele = s->data[s->top];
  s->data[s->top] = NULL;
  s->top--;

  return ele;
}

int stack_count(const Stack *s) { return (s->top + 1); }

bool stack_isEmpty(const Stack *s) {
  if (!s)
    return true;

  if (s->top == -1)
    return true;
  return false;
}

void *stack_top(const Stack *s) {
  /*Control de errores*/
  if (s == NULL)
    return NULL;

  /*Si está vacía no hay elementos*/
  if (stack_isEmpty(s) == true)
    return NULL;

  return (s->data[s->top]);
}

int stack_print(FILE *pf, const Stack *s, print_elem_fn fprintEle) {
  int i, n = 0;

  if (!pf || !s || !fprintEle)
    return -1;

  n = fprintf(pf, "SIZE: %d\n", s->top + 1);
  for (i = s->top; i >= 0; i--) {
    n += fprintEle(pf, s->data[i]);
    n += fprintf(pf, " ");
  }
  n += fprintf(pf, "\n");
  return n;
}