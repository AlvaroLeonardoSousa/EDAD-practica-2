
#include "maze.h"


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
Point *maze_dfs(Maze *m);


/**
 * The function maze_bfs performs a breadth-first search in a maze to find a path from the entrance to
 * the exit.
 * 
 * @param m The function `maze_bfs` takes a pointer to a `Maze` structure as input. The `Maze`
 * structure likely represents a maze with various properties such as the maze layout, starting point,
 * and exit point. The function performs a breadth-first search (BFS) traversal on the
 * 
 * @return The function `maze_bfs` is returning a `Point` pointer. If the function successfully finds a
 * path from the entrance to the exit in the maze, it will return a pointer to the exit `Point`. If it
 * does not find a path or encounters an error, it will return `NULL`.
 */
Point *maze_bfs(Maze *m);