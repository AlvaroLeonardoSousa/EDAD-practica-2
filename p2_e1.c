#include "stack.h"
#include "maze.h"
#include <stdio.h>
#include <limits.h>

#define TOT_POINTS 3
#define LEN_WORD 4

void do_empty_stack (FILE *fp, Stack *s, print_elem_fn print_elem);

int char_print (FILE *fp, const void * elem);

int main() {

    int i;
    Stack *stack;
    char word[LEN_WORD];

    Point *p[TOT_POINTS];

    p[0] = point_new (0, 0, WALL);
    p[1] = point_new (0, 1, SPACE);
    p[2] = point_new (0, 2, IN);

    stack = stack_new();

    for (i=0; i<TOT_POINTS; i++) {

        if(!p[i]) {
            return 0;
        }

        if(stack_push(stack, p[i]) == ERROR) {
            return 0;
        }
    }

    stack_print(stdout, stack, point_print);

    do_empty_stack(stdout, stack, point_print);

    strcpy(word, 'hola');

    for (i=0; i<LEN_WORD; i++) {
        
        if(stack_push(stack, (void*)word[i]) == ERROR) {
            return 0;

        }
    }

    stack_print(stdout, stack, char_print);

    do_empty_stack(stdout, stack, char_print);

    return 0;
}

void do_empty_stack (FILE *fp, Stack *s, print_elem_fn print_elem) {

    int i, tot_elem;
    void* removed;

    if (!fp || !s || stack_isEmpty(s)) {

        return;
        
    }

    tot_elem = stack_count(s);

    for (i=0; i<tot_elem; i++) {

        removed = stack_pop(s);

        if (!removed) {
            return;
        }

        print_elem (stdout, removed);

    }

}

int char_print (FILE *fp, const void * elem) {

    char *charr=NULL;
    
    if (!fp || !elem) {
        return ERROR;
    }

    charr = (char*)elem;

    return fprintf (stdout, "%c", elem);

}