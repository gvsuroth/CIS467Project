#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include "models/maze.h"

class Generator : public QObject
{
Q_OBJECT
public:
	explicit Generator(Maze *maze, QObject *parent = 0);
signals:
	//void generationDone(unsigned height, unsigned width, Maze::CellType **maze);

public slots:
	void backAndForth();
	void prims();
	void recursive();

private:
	Maze *maze;
	typedef struct list {
		unsigned x,y;
		struct list * next;
		struct list * prev;
	} List;
	struct cell {
		int state;
		int northWall;
		int southWall;
		int westWall;
		int eastWall;
		struct cell * north;
		struct cell * south;
		struct cell * east;
		struct cell * west;
	};
	typedef struct cell Cell;
	Cell ***cells;
	int neighbors_left;
	void addNeighbors(int x, int y, int v, int h, Cell ***cells, List** head);
	void translate(int rows, int cols, Cell ***cells);
};

#endif // GENERATOR_H
