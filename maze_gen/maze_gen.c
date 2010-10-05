#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cell.h"

int x,y;
void init(int rows, int cols, Cell * cells[rows][cols]);

int main(int argc, char *argv[]) {
	if (argc != 3) {
		x = 10;
		y = 10;
	} else {
		x = atoi(argv[1]);
		y = atoi(argv[2]);
	}
	Cell * cells[x][y];
	init(x,y,cells);
	srand(time(NULL));

	int i,j;
	for(i=0;i<x;i++) {
		for(j=0;j<y;j++) {
			printf("%d ",cells[i][j]->state);
		}
		printf("\n");
	}
	return 0;
}

void init(int rows, int cols, Cell * cells[rows][cols]) {
	int a,b;
	for(a=0;a<x;a++) {
		for(b=0;b<y;b++) {
			cells[a][b] = (Cell *)malloc(sizeof(Cell));
		}
	}
	for(b=0;b<y;b++) {
		for(a=0;a<x;a++) {
			cells[a][b]->state=0;
			if(a!=0)
				cells[a][b]->west = cells[b][a-1];
			else
				if (a<x-1)
					cells[a][b]->east = cells[b][a+1];
				else
					if (b!=0)
						cells[a][b]->north = cells[b-1][a];
					else
						if (b<y-1)
							cells[a][b]->south = cells[b+1][a];
		}
	}
	int h,v;
	h=rand()%x;
	v=rand()%y;
	cells[v][h]->state=1;
	if(v>0) {
		cells[v-1][h]->state=2;
	}
	if(v<y-1) {
		cells[v+1][h]->state=2;
	}
	if(h>0) {
		cells[v][h-1]->state=2;
	}
	if(h<x-1) {
		cells[v][h+1]->state=2;
	}
}
