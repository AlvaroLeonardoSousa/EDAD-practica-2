#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sorted_queue.h"
#include "maze.h"


int point_cmp(const void *elem1, const void *elem2){

    int x1,x2,y1,y2,d1,d2;
    char s1, s2;

    x1=point_getX(elem1);
    x2=point_getX(elem2);
    y1=point_getY(elem1);
    y2=point_getY(elem2);
    s1=point_getSymbol(elem1);
    s2=point_getSymbol(elem2);

    d1= pow(x1,2)+pow(y1,2);
    d2= pow(x2,2)+pow(y2,2);

    if(d1!=d2){
        return d1-d2;
    }

    else if(s1!=s2){
        return s1-s2;
    }

    else{
        return 0;
    }



}

SortedQueue *squeue_new() {
    return queue_new();
}

void squeue_free(SortedQueue *q) {
    queue_free(q);
}

bool squeue_isEmpty(const SortedQueue *q) {
    return queue_isEmpty(q);
}

void *squeue_pop(SortedQueue *q) {
    return queue_pop(q);
}

void *squeue_getFront(const SortedQueue *q) {
    return queue_getFront(q);
}

void *squeue_getBack(const SortedQueue *q) {
    return queue_getBack(q);
}

size_t squeue_size(const SortedQueue *q) {
    return queue_size(q);
}

int squeue_print(FILE *fp, const SortedQueue *q, print_elem_fn print_elem) {
    return queue_print(fp, q, print_elem);
}

Status squeue_push(SortedQueue *q, void *elem, compare_elem_fn cmp){

    void *aux1 = NULL, *aux2 = NULL;

    if (!q|| !elem) {
        return ERROR;
    }

    aux2=queue_getFront(q);

    while (queue_isEmpty(q)==false && (cmp(elem, queue_getFront(q)) >= 0)) {
        aux1 = queue_pop(q);
        if(queue_push(q, aux1) == ERROR) {
            return ERROR;
        }

        if(aux2==queue_getFront(q)){
            break;
        }

    }

    if(queue_push(q, elem) == ERROR) {
        return ERROR;
    }

    aux2=queue_getFront(q);

    while (queue_isEmpty(q)==false && (cmp(elem, queue_getFront(q)) < 0) ){
        aux1 = queue_pop(q);
        if(queue_push(q, aux1) == ERROR){
            return ERROR;
        }

        if(aux2==queue_getFront(q)){
            break;
        }


    }

    return OK;

}