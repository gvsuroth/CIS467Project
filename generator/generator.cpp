#include "generator.h"

Generator::Generator(Maze *maze, QObject *parent) :
	QObject(parent)
{
	this->maze = maze;
}

void Generator::backAndForth()
{
	// Back and forth
	bool dir = true;
	unsigned width = maze->width(), height = maze->height();
	for(unsigned c = 1; c < width; c+=2)
	{
		for(unsigned r = 0; r < height - 1; ++r)
			maze->setCell(dir ? r : height-r-1, c, Maze::WALL);
		dir=!dir;
	}
	maze->setCell(0, 0, Maze::SPRITE);
	maze->setCell(height - 1, width - 1, Maze::PATH);
}

void Generator::prims()
{
//	void init(int rows, int cols, Cell * cells[rows][cols]) {
	int y = maze->height(), x = maze->width();
	int rows = y, cols = x;
		int a,b;
		neighbors_left=0;
		List * neighbors;
		List * head = NULL;
		srand(time(NULL));
		//Cell cells[maze->height()][maze->width()];
		cells = new Cell**[y];
		for(a=0;a<x;a++) {
			cells[a] = new Cell*[x];
			for(b=0;b<y;b++) {
				cells[a][b] = (Cell *)malloc(sizeof(Cell));
			}
		}
		for(b=0;b<y;b++) {
			for(a=0;a<x;a++) {
				cells[a][b]->state=Maze::WALL;
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
		cells[v][h]->state=Maze::PATH;
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
			cells[tmp->x][tmp->y]->state=Maze::PATH;

			v=tmp->x;
			h=tmp->y;
			addNeighbors(rows,cols,v,h,cells,&head);
			int escape=0;
			while(!escape){
				r=rand()%4;
				printf("%d\n",r);
				if(r==0 && v>0) {
					cells[v-1][h]->southWall=Maze::PATH;
					cells[v][h]->northWall=Maze::PATH;
					escape++;
				}
				if(r==1 && v<y-1) {
					cells[v+1][h]->northWall=Maze::PATH;
					cells[v][h]->southWall=Maze::PATH;
					escape++;
				}
				if(r==2 && h<x-1) {
				if(r==2 && h<x-1) {
					cells[v][h+1]->westWall=Maze::PATH;
					cells[v][h]->eastWall=Maze::PATH;
					escape++;
				}
				if(r==3 && h>0) {
					cells[v][h-1]->eastWall=Maze::PATH;
					cells[v][h]->westWall=Maze::PATH;
					escape++;
				}
			}
			if(tmp->prev!=NULL) tmp->prev->next=tmp->next;
			if(tmp->next!=NULL) tmp->next->prev=tmp->prev;
			tmp=NULL;
			neighbors_left--;
		}
		translate(rows, cols, cells);
}

void Generator::addNeighbors(int x, int y, int v, int h, Cell ***cells, List** head) {
	List * neighbors;;
	if(v>0) {
		if(cells[v-1][h]!=NULL && cells[v-1][h]->state!=Maze::PATH) {
			cells[v-1][h]->state=Maze::FRONTIER;
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
		if (cells[v+1][h]!=NULL && cells[v+1][h]->state!=Maze::PATH) {
			cells[v+1][h]->state=Maze::FRONTIER;
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
		if (cells[v][h-1]!=NULL && cells[v][h-1]->state!=Maze::PATH) {
			cells[v][h-1]->state=Maze::FRONTIER;
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
		if (cells[v][h+1]!=NULL && cells[v][h+1]->state!=Maze::PATH) {
			cells[v][h+1]->state=Maze::FONTIER;
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

void Generator::translate(int rows, int cols, Cell ***cells) {
	int x = cols, y = rows;
	Cell * c = (Cell *)malloc(sizeof(Cell));
	int i,j;
	cells[y-1][x-1]->southWall=Maze::PATH;
	cells[0][0]->northWall=Maze::PATH;
	for(i=0;i<y;i++) {
		for(j=0;j<x;j++) {
			c = cells[i][j];
			printf(" %u %d",Maze::WALL, c->northWall);
			c = NULL;
		}
		printf(" 0\n");
		for(j=0;j<x;j++) {
			c = cells[i][j];
			if(j==0) {
				printf(" %d %d %d",c->westWall,c->state,c->eastWall);
			} else {
				printf(" %d %d",c->state,c->eastWall);
			}
			c = NULL;
		}
		printf(" \n");
	}
	for(j=0;j<x;j++) {
		c = cells[y-1][j];
		printf(" 0 %d",c->southWall);
		c = NULL;
	}
	printf(" 0\n");
}

void Generator::recursive()
{

}
