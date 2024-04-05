#include "sorted_queue.h"
#include "maze.h"


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10


int main() {
    SortedQueue *squeue = NULL;
    char* strings[MAX_SIZE] = {"perro", "coche", "alas", "astronauta", "supercalifragilistico", "salida", "pregunta", "coche", "no", "datos"};
    int numbers[MAX_SIZE] = {33, 7, 12, 45, 91, 1, 123, 6, 6, 77};
    Point* points[MAX_SIZE] = {point_new(2, 5, WALL), point_new(1, 1, IN), point_new(1, 1, SPACE), point_new(2, 1, WALL), point_new(3, 3, OUT), point_new(1, 1, IN), point_new(1, 2, SPACE), point_new(14, 33, WALL), point_new(1, 1, OUT), point_new(2 , 3, IN)};
    int i;

    squeue = squeue_new();

    fprintf(stdout, "Introducimos cadenas a squeue\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        fprintf(stdout, "%s\n", strings[i]);
        if(squeue_push(squeue, strings[i], str_cmp) == ERROR) {
            squeue_free(squeue);
            for(i=0; i<MAX_SIZE; i++){
                point_free(points[i]);
                points[i]=NULL;
            }
            return 1;
        }
    }

    fprintf(stdout, "Cola ordenada: \n");

    squeue_print(stdout, squeue, string_print);

    squeue_free(squeue);

    /* Lo mismo con los enteros*/

    squeue = squeue_new();

    fprintf(stdout, "Introducimos enteros a squeue\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        fprintf(stdout, "%d\n", numbers[i]);
        if(squeue_push(squeue, &numbers[i], int_cmp) == ERROR) {
            squeue_free(squeue);
             for(i=0; i<MAX_SIZE; i++){
                point_free(points[i]);
                points[i]=NULL;
            }
            return 1;
        }
    }

    fprintf(stdout, "Cola ordenada: \n");

    squeue_print(stdout, squeue, int_print);

    squeue_free(squeue);

    /*Lo mismo con los puntos*/

    squeue = squeue_new();

    fprintf(stdout, "Introducimos puntos a squeue\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        fprintf(stdout, "[(%d, %d): %c]\n", point_getX(points[i]), point_getY(points[i]), point_getSymbol(points[i]));
        if(squeue_push(squeue, points[i], point_cmp) == ERROR) {
            for(i=0; i<MAX_SIZE; i++){
                point_free(points[i]);
                points[i]=NULL;
            }
            squeue_free(squeue);
            return 1;
        }
    }

    fprintf(stdout, "Cola ordenada: \n");

    squeue_print(stdout, squeue, point_print);

    squeue_free(squeue);

    for(i=0; i<MAX_SIZE; i++){
        point_free(points[i]);
    }

    return 0;

}