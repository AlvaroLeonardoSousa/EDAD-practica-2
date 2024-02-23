#include "stack.h"
#include <stdio.h>
#include <limits.h>

void do_empty_stack (FILE *fp, Stack *s, print_elem_fn print_elem);

int char_print (FILE *fp, const void * elem);

int main() {





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