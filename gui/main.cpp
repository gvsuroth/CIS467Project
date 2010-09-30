#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;

	// Test the maze display
	int height = 5, width = 5;
	MainWindow::CellType mazeArr[height][width];
	for(int y = 0; y < height; ++y)
	{
		for(int x = 0; x < width; ++x)
		{
			if((x+y)%3)
					mazeArr[y][x] = MainWindow::WALL;
			else
				mazeArr[y][x] = MainWindow::NOTHING;
		}
	}
	w.setMaze(height, width, (MainWindow::CellType*)mazeArr);

	w.show();
	return a.exec();
}
