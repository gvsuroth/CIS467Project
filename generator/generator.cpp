#include "generator.h"
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define FRONTIER 5
#define AVAIL_UP 8
#define AVAIL_LEFT 16
#define AVAIL_DOWN 32
#define AVAIL_RIGHT 64

Generator::Generator(Maze *maze, QObject *parent) :
	QObject(parent)
{
	this->maze = maze;
}

void Generator::backAndForth()
{
	// Back and forth
	bool dir = true;
	unsigned width = maze->width(), height = maze->height();
	for (unsigned c = 0; c < width; ++c)
		for (unsigned r = 0; r < height; ++r)
			maze->setCell(r, c, Maze::PATH);
	for(unsigned c = 1; c < width; c+=2)
	{
		for(unsigned r = 0; r < height - 1; ++r)
			maze->setCell(dir ? r : height-r-1, c, Maze::WALL);
		dir=!dir;
	}
	maze->setCell(0, 0, Maze::SPRITE);
	maze->setCell(height - 1, width - 1, Maze::PATH);
}

void Generator::prims()
{
	// The spanning tree is half as large as the grid
	unsigned width = (maze->width() + 1) / 2, height = (maze->height() + 1) / 2;
	// Holds info about which nodes are untouched
	unsigned **tree = new unsigned*[height];
	for (unsigned i = 0; i < height; i++) {
		tree[i] = new unsigned[width];
		for (unsigned j = 0; j < width; j++)
			tree[i][j] = 0;
	}
	// Count of remaining frontier nodes
	int numFrontier = 0, nodeX = 0, nodeY = 0, frontSel = 0;
	
	for (unsigned i = 0; i < width * height; i++) {

		if (i == 0) {
			// First node must be top left
			tree[0][0] = UP;
			tree[0][1] = FRONTIER;
			tree[1][0] = FRONTIER;
			numFrontier = 2;
		} else {
			// Pick a random frontier node
			frontSel = rand()%numFrontier;
			for (unsigned r = 0; r < height; r++) {
				for (unsigned c = 0; c < width; c++) {
					if (tree[r][c] == FRONTIER) {
						frontSel--;
						if (frontSel < 0) {
							nodeX = c;
							nodeY = r;
							break;
						}
					}
				}
				if (frontSel < 0) break;
			}
			
			// Pick a direction to an open cell
			int dir = 0;
			bool flag = false;
			while (!flag) {
				dir = rand()%4 + 1;
				switch (dir) {
					case UP:
						if (nodeY - 1 >= 0 && tree[nodeY - 1][nodeX] > 0 && tree[nodeY - 1][nodeX] < 5) {
							tree[nodeY][nodeX] = UP;
							flag = true;
						}
						break;
					case DOWN:
						if (nodeY + 1 < height && tree[nodeY + 1][nodeX] > 0 && tree[nodeY + 1][nodeX] < 5) {
							tree[nodeY][nodeX] = DOWN;
							flag = true;
						}
						break;
					case RIGHT:
						if (nodeX + 1 < width && tree[nodeY][nodeX + 1] > 0 && tree[nodeY][nodeX + 1] < 5) {
							tree[nodeY][nodeX] = RIGHT;
							flag = true;
						}
						break;
					case LEFT:
						if (nodeX - 1 >= 0 && tree[nodeY][nodeX - 1] > 0 && tree[nodeY][nodeX - 1] < 5) {
							tree[nodeY][nodeX] = LEFT;
							flag = true;
						}
						break;
				} // switch
			} // while
			--numFrontier;
			
			// Add frontier nodes
			if (nodeY - 1 >= 0 && tree[nodeY - 1][nodeX] == 0) {
				++numFrontier;
				tree[nodeY - 1][nodeX] = FRONTIER;
			}
			if (nodeY + 1 < height && tree[nodeY + 1][nodeX] == 0) {
				++numFrontier;
				tree[nodeY + 1][nodeX] = FRONTIER;
			}
			if (nodeX - 1 >= 0 && tree[nodeY][nodeX - 1] == 0) {
				++numFrontier;
				tree[nodeY][nodeX - 1] = FRONTIER;
			}
			if (nodeX + 1 < width && tree[nodeY][nodeX + 1] == 0) {
				++numFrontier;
				tree[nodeY][nodeX + 1] = FRONTIER;
			}
		} // else
	} // for
	
	// transform tree to maze
	for (unsigned i = 0; i < height; i++) {
		for (unsigned j = 0; j < width; j++) {
			maze->setCell(2*i, 2*j, Maze::PATH);
			maze->setCell(2*i + 1, 2*j, Maze::WALL);
			maze->setCell(2*i, 2*j + 1, Maze::WALL);
			maze->setCell(2*i + 1, 2*j + 1, Maze::WALL);
			if (tree[i][j] == UP) maze->setCell(2*i - 1, 2*j, Maze::PATH);
			else if (tree[i][j] == DOWN) maze->setCell(2*i + 1, 2*j, Maze::PATH);
			else if (tree[i][j] == LEFT) maze->setCell(2*i, 2*j - 1, Maze::PATH);
			else if (tree[i][j] == RIGHT) maze->setCell(2*i, 2*j + 1, Maze::PATH);
		}
	}
		
	for (unsigned i = 0; i < height; i++)
		delete [] tree[i];
	delete [] tree;
	
	maze->setCell(0, 0, Maze::SPRITE);
	maze->setCell(maze->height() - 1, maze->width() - 1, Maze::PATH);
	if (maze->height() % 2 == 0 && maze->width() % 2 == 0)
		maze->setCell(maze->height() - 2, maze->width() - 1, Maze::PATH);
}

void Generator::recursive()
{

}
