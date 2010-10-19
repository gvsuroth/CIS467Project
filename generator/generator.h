#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>

#include "models/maze.h"

class Generator : public QObject
{
Q_OBJECT
public:
	explicit Generator(Maze *maze, QObject *parent = 0);
signals:
	//void generationDone(int height, int width, Maze::CellType **maze);

public slots:
	void prims();
	void lukes();

private:
	Maze *maze;
};

#endif // GENERATOR_H
