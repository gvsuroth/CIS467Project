#include "solver.h"
#include <queue>

Solver::Solver(Maze *maze, QObject *parent) :
	QObject(parent)
{
	this->maze = maze;
}

void Solver::rightHandRule()
{
	Maze::Facing facing = Maze::DOWN;
	QPoint curLoc(0, 0);
	QPoint end(maze->width() - 1, maze->height() - 1);
	maze->setValue(0, 0, maze->getValue(0, 0) + 1);
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
		maze->setValue(curLoc.y(), curLoc.x(), maze->getValue(curLoc.y(), curLoc.x()) + 1);
		facing = nextFacing;
		printf("Moving (%d, %d)\n", curLoc.x(), curLoc.y());
		maze->moveSprite(curLoc.y(), curLoc.x(), facing);
	}
}

void Solver::deadEndFiller()
{
	printf("I am filling in dead ends\n");
}