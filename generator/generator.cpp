#include "generator.h"

Generator::Generator(Maze *maze, QObject *parent) :
	QObject(parent)
{
	this->maze = maze;
}

void Generator::prims()
{
	// Disclaimer: THIS IS NOT PRIM'S, IT'S JUST A TEST
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

void Generator::lukes()
{
	maze->setCell(0, 0, Maze::WALL);
	maze->setCell(0, 1, Maze::PATH);
	maze->setCell(0, 2, Maze::WALL);
	maze->setCell(0, 3, Maze::WALL);
	maze->setCell(0, 4, Maze::WALL);
	maze->setCell(0, 5, Maze::WALL);
	maze->setCell(0, 6, Maze::WALL);
	maze->setCell(0, 7, Maze::WALL);
	maze->setCell(0, 8, Maze::WALL);
	maze->setCell(0, 9, Maze::WALL);
	maze->setCell(1, 0, Maze::WALL);
	maze->setCell(1, 1, Maze::PATH);
	maze->setCell(1, 2, Maze::WALL);
	maze->setCell(1, 3, Maze::WALL);
	maze->setCell(1, 4, Maze::PATH);
	maze->setCell(1, 5, Maze::PATH);
	maze->setCell(1, 6, Maze::WALL);
	maze->setCell(1, 7, Maze::WALL);
	maze->setCell(1, 8, Maze::PATH);
	maze->setCell(1, 9, Maze::WALL);
	maze->setCell(2, 0, Maze::WALL);
	maze->setCell(2, 1, Maze::PATH);
	maze->setCell(2, 2, Maze::WALL);
	maze->setCell(2, 3, Maze::PATH);
	maze->setCell(2, 4, Maze::PATH);
	maze->setCell(2, 5, Maze::WALL);
	maze->setCell(2, 6, Maze::WALL);
	maze->setCell(2, 7, Maze::PATH);
	maze->setCell(2, 8, Maze::PATH);
	maze->setCell(2, 9, Maze::WALL);
	maze->setCell(3, 0, Maze::WALL);
	maze->setCell(3, 1, Maze::PATH);
	maze->setCell(3, 2, Maze::PATH);
	maze->setCell(3, 3, Maze::PATH);
	maze->setCell(3, 4, Maze::PATH);
	maze->setCell(3, 5, Maze::PATH);
	maze->setCell(3, 6, Maze::PATH);
	maze->setCell(3, 7, Maze::PATH);
	maze->setCell(3, 8, Maze::PATH);
	maze->setCell(3, 9, Maze::WALL);
	maze->setCell(4, 0, Maze::WALL);
	maze->setCell(4, 1, Maze::PATH);
	maze->setCell(4, 2, Maze::WALL);
	maze->setCell(4, 3, Maze::PATH);
	maze->setCell(4, 4, Maze::PATH);
	maze->setCell(4, 5, Maze::WALL);
	maze->setCell(4, 6, Maze::WALL);
	maze->setCell(4, 7, Maze::WALL);
	maze->setCell(4, 8, Maze::PATH);
	maze->setCell(4, 9, Maze::WALL);
	maze->setCell(5, 0, Maze::WALL);
	maze->setCell(5, 1, Maze::PATH);
	maze->setCell(5, 2, Maze::WALL);
	maze->setCell(5, 3, Maze::WALL);
	maze->setCell(5, 4, Maze::PATH);
	maze->setCell(5, 5, Maze::WALL);
	maze->setCell(5, 6, Maze::PATH);
	maze->setCell(5, 7, Maze::WALL);
	maze->setCell(5, 8, Maze::WALL);
	maze->setCell(5, 9, Maze::WALL);
	maze->setCell(6, 0, Maze::WALL);
	maze->setCell(6, 1, Maze::PATH);
	maze->setCell(6, 2, Maze::WALL);
	maze->setCell(6, 3, Maze::PATH);
	maze->setCell(6, 4, Maze::PATH);
	maze->setCell(6, 5, Maze::WALL);
	maze->setCell(6, 6, Maze::PATH);
	maze->setCell(6, 7, Maze::PATH);
	maze->setCell(6, 8, Maze::PATH);
	maze->setCell(6, 9, Maze::PATH);
	maze->setCell(7, 0, Maze::WALL);
	maze->setCell(7, 1, Maze::PATH);
	maze->setCell(7, 2, Maze::WALL);
	maze->setCell(7, 3, Maze::WALL);
	maze->setCell(7, 4, Maze::PATH);
	maze->setCell(7, 5, Maze::PATH);
	maze->setCell(7, 6, Maze::PATH);
	maze->setCell(7, 7, Maze::WALL);
	maze->setCell(7, 8, Maze::PATH);
	maze->setCell(7, 9, Maze::WALL);
	maze->setCell(8, 0, Maze::WALL);
	maze->setCell(8, 1, Maze::PATH);
	maze->setCell(8, 2, Maze::PATH);
	maze->setCell(8, 3, Maze::WALL);
	maze->setCell(8, 4, Maze::PATH);
	maze->setCell(8, 5, Maze::WALL);
	maze->setCell(8, 6, Maze::WALL);
	maze->setCell(8, 7, Maze::WALL);
	maze->setCell(8, 8, Maze::PATH);
	maze->setCell(8, 9, Maze::WALL);
	maze->setCell(9, 0, Maze::WALL);
	maze->setCell(9, 1, Maze::WALL);
	maze->setCell(9, 2, Maze::WALL);
	maze->setCell(9, 3, Maze::WALL);
	maze->setCell(9, 4, Maze::WALL);
	maze->setCell(9, 5, Maze::WALL);
	maze->setCell(9, 6, Maze::WALL);
	maze->setCell(9, 7, Maze::WALL);
	maze->setCell(9, 8, Maze::PATH);
	maze->setCell(9, 9, Maze::WALL);
}
