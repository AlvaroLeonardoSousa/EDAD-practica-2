#include "queue.h"
#include "maze.h"
#include "string.h"
#include "search.h"
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[]){

    Maze *maze=NULL;


    maze=maze_readFromFile(argv[1]);

    if(!maze){
        return ERROR;
    }

    maze_printPoints(stdout, maze);

    fprintf(stdout, "\n-------BFS TRANSVERSE-------\n" );

    maze_bfs(maze);

    maze_free(maze);

    return 0;
}