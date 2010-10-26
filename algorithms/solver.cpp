#include "solver.h"

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
	while(curLoc != end)
	{
		Maze::Facing nextFacing = (Maze::Facing)((facing + 1) % 4);
		QPoint nextLoc(0, 0);
		while(true)
		{
			nextLoc = curLoc + QPoint(nextFacing == Maze::RIGHT || nextFacing == Maze::LEFT ? -1 * (nextFacing - 2) : 0, nextFacing == Maze::UP || nextFacing == Maze::DOWN ? -1 * (nextFacing - 1) : 0);
			qDebug() << nextLoc;
			if(maze->getCell(nextLoc.y(), nextLoc.x()) == Maze::PATH)
				break;
			nextFacing = (Maze::Facing)((nextFacing - 1) % 4);
		}
		curLoc = nextLoc;
		facing = nextFacing;
		maze->moveSprite(curLoc.y(), curLoc.x(), facing);
	}
}
