#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <stdlib.h>
#include <stdio.h>
#include <QLinkedList>

#include "models/maze.h"

 #define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

class Generator;

typedef void (Generator::*GeneratorAlgorithm)();

class Generator : public QObject
{
Q_OBJECT
public:
	explicit Generator(Maze *maze, QObject *parent = 0);
signals:
	//void generationDone(unsigned height, unsigned width, Maze::CellType **maze);
	void showStatistics(int time);

public slots:
	void backAndForth();
	void prims();
	void backtracker();
	void braid();
//	void kruskals();
	void generate(GeneratorAlgorithm algorithm);

private:
	Maze *maze;
	QLinkedList<QPoint> deadEnds;
	bool backtrackerAddDeadEnds;
};

#endif // GENERATOR_H
