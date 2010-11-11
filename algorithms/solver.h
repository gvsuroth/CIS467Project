#ifndef SOLVER_H
#define SOLVER_H

#include <QObject>

#include "models/maze.h"

class Solver : public QObject
{
	Q_OBJECT
public:
	explicit Solver(Maze *maze, QObject *parent = 0);

signals:

public slots:
	void rightHandRule();
	void deadEndFiller();
private:
	Maze *maze;
};

#endif // SOLVER_H
