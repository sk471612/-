#include "maze.h"
 
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int j,i,c,r;
void initMaze(char maze[HEIGHT][WIDTH]) {
    for (i = 0; i < HEIGHT; i++)
        for (j = 0; j < WIDTH; j++)
            maze[i][j] = WALL;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            maze[2*r+1][2*c+1] = PATH;
}
 
void printMaze(char maze[HEIGHT][WIDTH]) {
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
        	switch (maze[i][j]) {
				case WALL:  printf("[]"); break;
				case PATH:  printf("  "); break;
				case START: printf("S "); break;
				case END:   printf("E "); break;
				case ROUTE: printf(". "); break;
				default:    printf("%c ", maze[i][j]);
			}
		}
        printf("\n");
    }
}

