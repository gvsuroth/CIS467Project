#include <QtGui/QApplication>
#include "gui.h"
#include "cell.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Gui gui;

	// Test the maze display
	/*int height = 5, width = 5;
	Cell::Type mazeArr[height][width];
	for(int y = 0; y < height; ++y)
	{
		for(int x = 0; x < width; ++x)
		{
			if(x == 2 && y == 3)
				mazeArr[y][x] = Cell::SPRITE;
			else if((x+y)%3)
				mazeArr[y][x] = Cell::WALL;
			else
				mazeArr[y][x] = Cell::PATH;
		}
	}
	gui.setMaze(height, width, (Cell::Type*)mazeArr);*/

	gui.showMaximized();
	return a.exec();
}
