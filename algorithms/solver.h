#ifndef SOLVER_H
#define SOLVER_H

#include <QObject>

#include "models/maze.h"

#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

class Solver;

typedef void (Solver::*SolverAlgorithm)();

class Solver : public QObject
{
	Q_OBJECT
public:
	explicit Solver(Maze *maze, QObject *parent = 0);

signals:
	void showStatistics(int time);
	void requestMazeDimensions();

public slots:
	void rightHandRule();
	void deadEndFiller();
	void breadthFirst();
	void aStar();
	void solve(SolverAlgorithm algorithm);
private:
	Maze *maze;
	void detectPath();
};

#endif // SOLVER_H
