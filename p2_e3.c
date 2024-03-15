#include "search.h"
#include <stdio.h>
#include <stdlib.h>

/*Programa p2_e3.c
Crea un programa p2_e3.c que utilice la función maze_dfs() para recorrer un laberinto contenido
en un fichero pasado como argumento al programa.
El programa utilizará la biblioteca estática libstack.a para gestionar una pila de puntos. El programa
deberá gestionar correctamente la memoria.*/


int main(int argc, char *argv[]) {

    Maze *maze = maze_readFromFile(argv[1]);

    if (argc != 2) {
        fprintf(stdout, "Usage: %s <maze-file>\n", argv[0]);
        return 1;
    }

    if (!maze) {
        fprintf(stdout, "Error reading maze file %s\n", argv[1]);
        return 1;
    }

    fprintf(stdout, "Maze drawing:\n");

    maze_print(stdout, maze);

    fprintf(stdout, "Maze:\n");

    maze_printPoints (stdout, maze);

    fprintf(stdout, "\nDFS traverse:\n");

    maze_dfs(maze);

    maze_free(maze);

    return 0;
}