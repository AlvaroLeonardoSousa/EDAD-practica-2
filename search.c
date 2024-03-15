/**
* @brief it defines the DFS function
*
* @file search.c
* @version 1
* @authors Álvaro Leonardo & Diego Tabero
*/

#include "search.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Point *maze_dfs(Maze *m) {

    Point *p = NULL, *pn = NULL, *p1 = maze_getIn(m), *p2 = maze_getOut(m);
    Stack *s = stack_new();
    int i;

    if (!m || !s || !p1 || !p2) {
        return NULL;
    }

    if (stack_push(s, p1) != OK) {
        return NULL;
    }

    while (p != p2 && !stack_isEmpty(s)) {

        p = stack_pop(s);

        if (!p) {
            return NULL;
        }

        if (point_getVisited(p) == false) {

            point_setVisited(p, true);

            point_print(stdout, p);

            for (i = 0; i < 4; i++) {

                pn = maze_getNeighbor(m, p, i);

                if (pn != NULL && point_getSymbol(pn) != WALL && point_getVisited(pn) == false) {

                    if (stack_push(s, pn) != OK) {
                        return NULL;
                    }
                }
            }
        } 
    }

    stack_free(s);

    if (p == p2) {
        return p;
    }

    return NULL;
  
}
