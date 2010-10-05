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
	/*for(int y = 0; y < height; ++y)
		for(int x = 0; x < width; ++x)
			maze[y][x] = Cell::PATH;*/
	/*maze[0][0]=Cell::WALL;
	maze[0][1]=Cell::PATH;
	maze[0][2]=Cell::WALL;
	maze[0][3]=Cell::WALL;
	maze[0][4]=Cell::WALL;
	maze[0][5]=Cell::WALL;
	maze[0][6]=Cell::WALL;
	maze[0][7]=Cell::WALL;
	maze[0][8]=Cell::WALL;
	maze[0][9]=Cell::WALL;
	maze[1][0]=Cell::WALL;
	maze[1][1]=Cell::PATH;
	maze[1][2]=Cell::WALL;
	maze[1][3]=Cell::WALL;
	maze[1][4]=Cell::PATH;
	maze[1][5]=Cell::PATH;
	maze[1][6]=Cell::WALL;
	maze[1][7]=Cell::WALL;
	maze[1][8]=Cell::PATH;
	maze[1][9]=Cell::WALL;
	maze[2][0]=Cell::WALL;
	maze[2][1]=Cell::PATH;
	maze[2][2]=Cell::WALL;
	maze[2][3]=Cell::PATH;
	maze[2][4]=Cell::PATH;
	maze[2][5]=Cell::WALL;
	maze[2][6]=Cell::WALL;
	maze[2][7]=Cell::PATH;
	maze[2][8]=Cell::PATH;
	maze[2][9]=Cell::WALL;
	maze[3][0]=Cell::WALL;
	maze[3][1]=Cell::PATH;
	maze[3][2]=Cell::PATH;
	maze[3][3]=Cell::PATH;
	maze[3][4]=Cell::PATH;
	maze[3][5]=Cell::PATH;
	maze[3][6]=Cell::PATH;
	maze[3][7]=Cell::PATH;
	maze[3][8]=Cell::PATH;
	maze[3][9]=Cell::WALL;
	maze[4][0]=Cell::WALL;
	maze[4][1]=Cell::PATH;
	maze[4][2]=Cell::WALL;
	maze[4][3]=Cell::PATH;
	maze[4][4]=Cell::PATH;
	maze[4][5]=Cell::WALL;
	maze[4][6]=Cell::WALL;
	maze[4][7]=Cell::WALL;
	maze[4][8]=Cell::PATH;
	maze[4][9]=Cell::WALL;
	maze[5][0]=Cell::WALL;
	maze[5][1]=Cell::PATH;
	maze[5][2]=Cell::WALL;
	maze[5][3]=Cell::WALL;
	maze[5][4]=Cell::PATH;
	maze[5][5]=Cell::WALL;
	maze[5][6]=Cell::PATH;
	maze[5][7]=Cell::WALL;
	maze[5][8]=Cell::WALL;
	maze[5][9]=Cell::WALL;
	maze[6][0]=Cell::WALL;
	maze[6][1]=Cell::PATH;
	maze[6][2]=Cell::WALL;
	maze[6][3]=Cell::PATH;
	maze[6][4]=Cell::PATH;
	maze[6][5]=Cell::WALL;
	maze[6][6]=Cell::PATH;
	maze[6][7]=Cell::PATH;
	maze[6][8]=Cell::PATH;
	maze[6][9]=Cell::PATH;
	maze[7][0]=Cell::WALL;
	maze[7][1]=Cell::PATH;
	maze[7][2]=Cell::WALL;
	maze[7][3]=Cell::WALL;
	maze[7][4]=Cell::PATH;
	maze[7][5]=Cell::PATH;
	maze[7][6]=Cell::PATH;
	maze[7][7]=Cell::WALL;
	maze[7][8]=Cell::PATH;
	maze[7][9]=Cell::WALL;
	maze[8][0]=Cell::WALL;
	maze[8][1]=Cell::PATH;
	maze[8][2]=Cell::PATH;
	maze[8][3]=Cell::WALL;
	maze[8][4]=Cell::PATH;
	maze[8][5]=Cell::WALL;
	maze[8][6]=Cell::WALL;
	maze[8][7]=Cell::WALL;
	maze[8][8]=Cell::PATH;
	maze[8][9]=Cell::WALL;
	maze[9][0]=Cell::WALL;
	maze[9][1]=Cell::WALL;
	maze[9][2]=Cell::WALL;
	maze[9][3]=Cell::WALL;
	maze[9][4]=Cell::WALL;
	maze[9][5]=Cell::WALL;
	maze[9][6]=Cell::WALL;
	maze[9][7]=Cell::WALL;
	maze[9][8]=Cell::PATH;
	maze[9][9]=Cell::WALL;*/
	// END MAZE GENERATION CODE

	emit generationDone(height, width, maze);
}
