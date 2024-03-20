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
    char word[LEN_WORD+1];

    Point *p[TOT_POINTS];

    if(!(p[0] = point_new (0, 0, WALL))){
        return 1;
    }
    if(!(p[1] = point_new (0, 1, SPACE))){
        free(p[0]);
        return 1;
    }
    if(!(p[2] = point_new (0, 2, IN))){
        free (p[0]);
        free(p[1]);
        return 1;
    }


    puts("Array de puntos inicial:");

    for (i=0; i<TOT_POINTS; i++) {

        if(point_print(stdout, p[i])<0){
            for(i=0; i<TOT_POINTS; i++){
            point_free(p[i]);
            }
            return 1;
        }

    }

    if(!(stack = stack_new())){
        for(i=0; i<TOT_POINTS; i++){
            point_free(p[i]);
        }
        return 1;
    }

    for (i=0; i<TOT_POINTS; i++) {

        if((stack_push(stack, (void*)p[i]))==ERROR){
            for(i=0; i<TOT_POINTS; i++){
            point_free(p[i]);
            }
            stack_free(stack);
            return 1;
        }
    }

    puts("\nPila de puntos inicial:");

    stack_print(stdout, stack, point_print);

    do_empty_stack(stdout, stack, point_print);

    strcpy(word, "hola");

    puts("\nArray de chars inicial:");


    for (i=0; i<LEN_WORD; i++) {

        if(char_print(stdout, word+i) <0 ) {
            for(i=0; i<TOT_POINTS; i++){
                point_free(p[i]);
            }
            stack_free(stack);
            return 1;
        }
    }

    for (i=0; i<LEN_WORD; i++) {
        
        if(stack_push(stack, (void*)(word+i)) == ERROR) {
            stack_free(stack);
            for(i=0; i<TOT_POINTS; i++){
                point_free(p[i]);
            }
            
            return 1;

        }
    }   
    
    puts("\nPila de chars inicial:");

    stack_print(stdout, stack, char_print);

    do_empty_stack(stdout, stack, char_print);

    stack_free(stack);
    
    for(i=0; i<TOT_POINTS; i++){
        point_free(p[i]);
    }

    return 0;
}

void do_empty_stack (FILE *fp, Stack *s, print_elem_fn print_elem) {

    int i, tot_elem;
    void* removed;

    fprintf(stdout, "Extrayendo elementos de la pila:\n");

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
        fprintf(stdout, "\n");

    }

    fprintf(stdout, "Pila final: \nSIZE:%d\n", stack_count(s));
    

}

int char_print (FILE *fp, const void * elem) {

    char *charr=NULL;
    
    if (!fp || !elem) {
        return ERROR;
    }

    charr = (char*)elem;

    return fprintf (stdout, "%c", *charr);

}