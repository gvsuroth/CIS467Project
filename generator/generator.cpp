#include "generator.h"

Generator::Generator(QObject *parent) :
	QObject(parent)
{
}

void Generator::generate(const int height, const int width)
{
	Cell::Type **maze = new Cell::Type*[height];
	for(int y = 0; y < height; ++y)
		maze[y] = new Cell::Type[width];

	// BEGIN MAZE GENERATION CODE
	bool dir = true;
	for(int x = 1; x < width; x+=2)
	{
		for(int y = 0; y < height - 1; ++y)
			maze[dir ? y : height-y-1][x] = Cell::WALL;
		dir=!dir;
	}
	/*for(int y = 0; y < height; ++y)
	{
		for(int x = 0; x < width; ++x)
		{
			if(y == 2)
				maze[y][x] = Cell::WALL;
		}
	}*/
	maze[0][0] = Cell::SPRITE;
	maze[height-1][width-1] = Cell::PATH;
	// END MAZE GENERATION CODE

	emit generationDone(height, width, maze);
}
