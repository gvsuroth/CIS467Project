#include "solver.h"
#include <QLinkedList>

Solver::Solver(Maze *maze, QObject *parent) :
	QObject(parent)
{
	this->maze = maze;
}

void Solver::rightHandRule()
{
	QLinkedList<QPoint> path;
	Maze::Facing facing = Maze::DOWN;
	QPoint curLoc(0, 0);
	QPoint end(maze->width() - 1, maze->height() - 1);
	maze->setValue(0, 0, maze->getValue(0, 0) + 1);
	path << QPoint(curLoc.x(), curLoc.y());
	while(curLoc != end)
	{
		Maze::Facing nextFacing = (Maze::Facing)((facing + 1) % 4);
		QPoint nextLoc(0, 0);
		while(true)
		{
			if(!maze->isWall(curLoc.y(), curLoc.x(), nextFacing))
				break;
			nextFacing = (Maze::Facing)((nextFacing + 3) % 4);
		}
		curLoc = curLoc + QPoint(nextFacing == Maze::RIGHT || nextFacing == Maze::LEFT ? -1 * (nextFacing - 2) : 0, nextFacing == Maze::UP || nextFacing == Maze::DOWN ? (nextFacing - 1) : 0);
		
		// Add point to path
		// If point already exists in path, remove all points after that point
		QPoint newPoint(curLoc.x(), curLoc.y());
		if (path.contains(newPoint)) {
			while (true) {
				QPoint tmp = path.takeLast();
				if (tmp == newPoint) break;
			}
		}
		path << QPoint(curLoc.x(), curLoc.y());
				
		maze->setValue(curLoc.y(), curLoc.x(), maze->getValue(curLoc.y(), curLoc.x()) + 1);
		facing = nextFacing;
		maze->moveSprite(curLoc.y(), curLoc.x(), facing);
	}
	while (!path.isEmpty()) {
		QPoint tmp = path.takeFirst();
		maze->setValue(tmp.y(), tmp.x(), 1000);
	}
}

void Solver::deadEndFiller()
{
	printf("I am filling in dead ends\n");
}