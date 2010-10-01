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
	for(int y = 0; y < height; ++y)
		for(int x = 0; x < width; ++x)
			maze[y][x] = Cell::PATH;
	// END MAZE GENERATION CODE

	emit generationDone(height, width, maze);
}
