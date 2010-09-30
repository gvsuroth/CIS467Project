#include <QtGui/QApplication>
#include "gui.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Gui gui;

	// Test the maze display
	int height = 5, width = 5;
	Gui::CellType mazeArr[height][width];
	for(int y = 0; y < height; ++y)
	{
		for(int x = 0; x < width; ++x)
		{
			if((x+y)%3)
					mazeArr[y][x] = Gui::WALL;
			else
				mazeArr[y][x] = Gui::NOTHING;
		}
	}
	gui.setMaze(height, width, (Gui::CellType*)mazeArr);

	gui.show();
	return a.exec();
}
