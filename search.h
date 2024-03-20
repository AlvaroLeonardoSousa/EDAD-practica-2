
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