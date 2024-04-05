#include "stack.h"
#include "search.h"
#include "string.h"
#include "queue.h"
#include <stdio.h>
#include <limits.h>

/**
 * The function maze_dfs performs a depth-first search in a maze to find a path from the entrance to
 * the exit.
 * 
 * @param m Maze structure containing information about the maze, including the start and end points,
 * walls, and neighbors of each point.
 * 
 * @return The `maze_dfs` function is returning a `Point` pointer. If the function successfully finds a
 * path from the entrance to the exit in the maze, it will return a pointer to the exit `Point`. If no
 * path is found or an error occurs during the process, it will return `NULL`.
 */
Point *maze_dfs(Maze *m)
{

    Stack *s;
    Point *p = NULL, *pi = NULL, *po = NULL, *paux = NULL;
    pi = maze_getIn(m);
    po = maze_getOut(m);
    int i;

    s = stack_new();

    if (!s)
    {
        return NULL;
    }

    if (stack_push(s, (void *)pi) == ERROR)
    {
        stack_free(s);
        return NULL;
    }

    while (p != po && stack_isEmpty(s) == false)
    {

        p = (Point *)stack_pop(s);

        if (point_getVisited(p) == false)
        {

            point_setVisited(p, true);

            point_print(stdout, p);

            for (i = 0; i < 4; i++)
            {
                paux = maze_getNeighbor(m, p, i);

                if (point_getVisited(paux) == false && point_getSymbol(paux) != WALL && paux!=NULL)
                {

                    if ((stack_push(s, (void *)paux)) == ERROR)
                    {
                        stack_free(s);
                        return NULL;
                    }
                }
            }
        }

    }   
    stack_free(s);

    if (p == po)
    {
        return p;
    }

    return NULL;
}

Point *maze_bfs(Maze *m)
{

    Queue *q;
    Point *p = NULL, *pi = NULL, *po = NULL, *paux = NULL;
    pi = maze_getIn(m);
    po = maze_getOut(m);
    int i;

    q = queue_new();

    if (!q)
    {
        return NULL;
    }

    if (queue_push(q, (void *)pi) == ERROR)
    {
        queue_free(q);
        return NULL;
    }

    while (p != po && queue_isEmpty(q) == false)
    {

        p = (Point *)queue_pop(q);

        if (point_getVisited(p) == false)
        {

            point_setVisited(p, true);

            point_print(stdout, p);

            for (i = 0; i < 4; i++)
            {
                paux = maze_getNeighbor(m, p, i);

                if (point_getVisited(paux) == false && point_getSymbol(paux) != WALL && paux!=NULL)
                {

                    if ((queue_push(q, (void *)paux)) == ERROR)
                    {
                        queue_free(q);
                        return NULL;
                    }
                }
            }
        }

    }   


    
    queue_free(q);

    if (p == po)
    {
        return p;
    }

    return NULL;
}   