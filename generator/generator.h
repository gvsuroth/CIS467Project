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
	void braid();

private:
	Maze *maze;
	bool deadEnd(unsigned r, unsigned c);
};

#endif // GENERATOR_H
