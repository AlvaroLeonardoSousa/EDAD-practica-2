#include "stack.h"
#include "types.h"
#include <stdio.h>

#define NUM_RANGE 5

// private
int int_print(FILE *f, const void *p);

//--------------------------------------------------------------------------
int int_print(FILE *f, const void *p) { return fprintf(f, "%d ", *((int *)p)); }

//--------------------------------------------------------------------------
int main() {
  int i, array[NUM_RANGE];
  int *x;
  Stack *ps = NULL;
  Status st = OK;

  // Create new stack:
  fprintf(stdout, "Allocating memory for stack...\n");
  ps = stack_new();
  if (ps == NULL) {
    return 1;
  }

  // Print stack count (empty stack, should be 0):
  fprintf(stdout, "Stack count = %d\n", stack_count(ps));

  // Insert elements:
  fprintf(stdout, "Inserting elements into stack...\n");
  for (i = 0; i < NUM_RANGE; i++) {
    array[i] = i;
    st = stack_push(ps, &(array[i]));
    if (st == ERROR) {
      fprintf(stderr, "Error when pushing element %d\n", i);
      stack_free(ps);
      return 1;
    }
  }

  // Print stack:
  fprintf(stdout, "Printing stack...\n");
  stack_print(stdout, ps, int_print);
  fprintf(stdout, "\n");

  // Print stack count:
  fprintf(stdout, "Stack count = %d\n", stack_count(ps));

  // Pop and print elements:
  for (i = 0; i < NUM_RANGE; i++) {
    if (stack_isEmpty(ps) == false) {
      x = (int *)stack_top(ps);
      fprintf(stdout, "Top element    %d\n", *x);
      x = (int *)stack_pop(ps);
      fprintf(stdout, "Popped element %d\n", *x);
    }
  }

  // Print stack:
  fprintf(stdout, "Printing stack...\n");
  stack_print(stdout, ps, int_print);
  fprintf(stdout, "\n");

  // Print stack count:
  fprintf(stdout, "Stack count = %d\n", stack_count(ps));

  // Free stack:
  fprintf(stdout, "Freeing stack...\n");
  stack_free(ps);

  return 0;
}