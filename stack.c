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

#define INIT_CAPACITY 8 // initial capacity of stack
#define GROWTH_FACTOR 2 // increase capacity by multiplying it by this

struct _Stack
{
    void **data;
    int top;
    int capacity;
};

// ******* Private functions ************


/*
Status _stack_grow(Stack *s)
{
    void **new_data = NULL;

    int i, j, new_size;

    if (!s)
        return ERROR;

    new_size = s->capacity * GROWTH_FACTOR;

    new_data = malloc(sizeof(void *) * new_size);

    if (!new_data)
        return ERROR;

    j = 0;
    for (i = 0; s->data[i] != NULL; i++)
    {
        new_data[j++] = s->data[i];
    }

    free(s->data);

    s->data = new_data;

    s->capacity = new_size;

    return OK;
}
*/


Status _stack_grow(Stack *s)
{

    int new_size;
    void ** new_data;

    if (!s || !s->data)
        return ERROR;

    new_size = s->capacity * GROWTH_FACTOR;

    new_data = realloc(s->data, new_size*sizeof(void *) );

    if (!new_data)
        return ERROR;


    s->capacity = new_size;
    s->data=new_data;

    return OK;
}

bool _stack_isFull(const Stack *s)
{
    if (!s)
    {
        return true;
    }

    return s->top == s->capacity - 1;
}


//***********  Public Interface *************

Stack *stack_new()
{

    Stack *stack=NULL;
    
    stack= (Stack*)calloc(1, sizeof(Stack));

    if (stack == NULL)
    {
        return NULL;
    }

    stack->data = calloc(INIT_CAPACITY , sizeof(void *));
    if (stack->data == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->top = -1;
    stack->capacity = INIT_CAPACITY;

    return stack;
}

void stack_free(Stack *s)
{
    free(s->data);
    free(s);
}

Status stack_push(Stack *s, const void *ele)
{
    if (!s || !ele)
    {
        return ERROR;
    }

    if (_stack_isFull(s))
    {
        if (_stack_grow(s) == ERROR)
        {
            return ERROR;
        }
    }

    s->data[++s->top] = (void *)ele;

    return OK;
}


void *stack_pop(Stack *s)
{
    void *ele;

    if (stack_isEmpty(s) == true) // return true if s == NULL
        return NULL;

    ele = s->data[s->top];
    s->data[s->top] = NULL;
    s->top--;

    return ele;
}

int stack_count(const Stack *s) { return (s->top + 1); }

bool stack_isEmpty(const Stack *s)
{
    if (!s)
        return true;

    if (s->top == -1)
        return true;

    return false;
}

void *stack_top(const Stack *s)
{
    /*Control de errores*/
    if (s == NULL)
        return NULL;

    /*Si está vacía no hay elementos*/
    if (stack_isEmpty(s) == true)
        return NULL;

    return (s->data[s->top]);
}

int stack_print(FILE *pf, const Stack *s, print_elem_fn fprintEle)
{
    int i, n = 0;

    if (!pf || !s || !fprintEle)
        return -1;

    n = fprintf(pf, "SIZE: %d\n", s->top + 1);
    for (i = s->top; i >= 0; i--)
    {
        n += fprintEle(pf, s->data[i]);
        n += fprintf(pf, " ");
    }
    n += fprintf(pf, "\n");
    return n;
}