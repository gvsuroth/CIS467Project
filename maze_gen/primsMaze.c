#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cell.h"
#include "list.h"

int x,y;
int neighbors_left;
void init(int rows, int cols, Cell * cells[rows][cols]);
void translate(int rows, int cols, Cell * cells[rows][cols]);
void addNeighbors(int x, int y, int v, int h, Cell * cell[x][y], List** list);

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

	printf("RAW: \n");
	int i,j;
	for(i=0;i<x;i++) {
		for(j=0;j<y;j++) {
			printf("%d ",cells[i][j]->state);
		}
		printf("\n");
	}
	printf("TRANSLATED: \n");
	translate(x,y,cells);
	return 0;
}

void init(int rows, int cols, Cell * cells[rows][cols]) {
	int a,b;
	neighbors_left=0;
	List * neighbors;
	List * head = NULL;
	srand(time(NULL));
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
	addNeighbors(rows,cols,v,h,cells,&head);
	while(neighbors_left>=0) {
		int r;
		int count=0;
		if (neighbors_left > 0) {
			r=rand()%neighbors_left;
		} else {
			r=0;
		}
		List * tmp = head;
		int i;
		for(i=0;i!=r;i++);
			if(tmp!=NULL && tmp->next != NULL)
				tmp = tmp->next;
			else
				printf("ERROR");
		cells[tmp->x][tmp->y]->state=1;
		
		v=tmp->x;
		h=tmp->y;
		addNeighbors(rows,cols,v,h,cells,&head);
		int escape=0;
		while(!escape){
			r=rand()%4;
			printf("%d\n",r);
			if(r==0 && v>0) {
				cells[v-1][h]->southWall=1;
				cells[v][h]->northWall=1;
				escape++;
			}
			if(r==1 && v<y-1) {
				cells[v+1][h]->northWall=1;
				cells[v][h]->southWall=1;
				escape++;
			}
			if(r==2 && h<x-1) {
				cells[v][h+1]->westWall=1;
				cells[v][h]->eastWall=1;
				escape++;
			}
			if(r==3 && h>0) {
				cells[v][h-1]->eastWall=1;
				cells[v][h]->westWall=1;
				escape++;
			}
		}
		if(tmp->prev!=NULL) tmp->prev->next=tmp->next;
		if(tmp->next!=NULL) tmp->next->prev=tmp->prev;
		tmp=NULL;
		neighbors_left--;
	}
}

void addNeighbors(int x, int y, int v, int h, Cell * cells[x][y], List** head) {
	List * neighbors;;
	if(v>0) {
		if(cells[v-1][h]!=NULL && cells[v-1][h]->state!=1) {
			cells[v-1][h]->state=2;
			neighbors = (List *)malloc(sizeof(List));
			neighbors->x=v-1;
			neighbors->y=h;
			neighbors->next=*head;
			neighbors->prev=NULL;
			if(*head!=NULL) (*head)->prev=neighbors;
			*head=neighbors;
			neighbors_left++;
		}
	}
	if(v<y-1) {
		if (cells[v+1][h]!=NULL && cells[v+1][h]->state!=1) {
			cells[v+1][h]->state=2;
			neighbors = (List *)malloc(sizeof(List));
			neighbors->x=v+1;
			neighbors->y=h;
			neighbors->next=*head;
			neighbors->prev=NULL;
			if(*head!=NULL) (*head)->prev=neighbors;
			*head=neighbors;
			neighbors_left++;
		}
	}
	if(h>0) {
		if (cells[v][h-1]!=NULL && cells[v][h-1]->state!=1) {
			cells[v][h-1]->state=2;
			neighbors = (List *)malloc(sizeof(List));
			neighbors->x=v;
			neighbors->y=h-1;
			neighbors->next=*head;
			neighbors->prev=NULL;
			if(*head!=NULL) (*head)->prev=neighbors;
			*head=neighbors;
			neighbors_left++;
		}
	}
	if(h<x-1) {
		if (cells[v][h+1]!=NULL && cells[v][h+1]->state!=1) {
			cells[v][h+1]->state=2;
			neighbors = (List *)malloc(sizeof(List));
			neighbors->x=v;
			neighbors->y=h+1;
			neighbors->next=*head;
			neighbors->prev=NULL;
			if(*head!=NULL) (*head)->prev=neighbors;
			*head=neighbors;
			neighbors_left++;
		}
	}
}
void translate(int rows, int cols, Cell * cells[rows][cols]) {
	Cell * c = (Cell *)malloc(sizeof(Cell));
	int i,j;
	cells[y-1][x-1]->southWall=1;
	cells[0][0]->northWall=1;
	for(i=0;i<y;i++) {
		for(j=0;j<x;j++) {
			c = cells[i][j];
			printf(" 0 %s",(c->northWall == 1 ? " " : "0"));
			c = NULL;
		}
		printf(" 0\n");
		for(j=0;j<x;j++) {
			c = cells[i][j];
			if(j==0) {
				printf(" %s %s %s",(c->westWall == 1 ? " " : "0"),(c->state == 1 ? " " : "0"),(c->eastWall == 1 ? " " : "0"));
			} else {
				printf(" %s %s",(c->state == 1 ? " " : "0"),(c->eastWall == 1 ? " " : "0"));
			}
			c = NULL;
		}
		printf(" \n");
	}
	for(j=0;j<x;j++) {
		c = cells[y-1][j];
		printf(" 0 %s",(c->southWall == 1 ? " " : "0"));
		c = NULL;
	}
	printf(" 0\n");
}
