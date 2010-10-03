#include <stdio.h>
#include "cell.h"

int x,y;
void init(int rows, int cols, Cell cells[rows][cols]);

int main(int argc, char *argv[]) {
	if (argc != 3) {
		x = 10;
		y = 10;
	} else {
		x = atoi(argv[1]);
		y = atoi(argv[2]);
	}
	Cell cells[x][y];
	init(x,y,cells);

	int i,j;
	for(i=0;i<x;i++) {
		for(j=0;j<y;j++) {
			printf("%d ",cells[i][j].state);
		}
		printf("\n");
	}
	return 0;
}

void init(int rows, int cols, Cell cells[rows][cols]) {
	int a,b;
	for(a=0;a<x;a++) {
		for(b=0;b<y;b++) {
			cells[a][b].state=0;
		}
	}
}
