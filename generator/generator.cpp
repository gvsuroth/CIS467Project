#include "generator.h"

#define _UP 1
#define _LEFT 2
#define _DOWN 3
#define _RIGHT 4
#define FRONTIER 5

Generator::Generator(Maze *maze, QObject *parent) :
	QObject(parent)
{
	this->maze = maze;
}

void Generator::backAndForth()
{
//	// Back and forth
//	bool dir = true;
//	unsigned width = maze->width(), height = maze->height();
//	maze->reset();
//	for(unsigned c = 1; c < width; c+=2)
//	{
//		for(unsigned r = 0; r < height - 1; ++r)
//			maze->setCell(dir ? r : height-r-1, c, Maze::WALL);
//		dir=!dir;
//	}
//	maze->setCell(0, 0, Maze::SPRITE);
//	maze->setCell(height - 1, width - 1, Maze::PATH);
}

void Generator::prims()
{
	srand((unsigned)time(NULL));
	unsigned width = maze->width(), height = maze->height();
	// Holds info about which nodes are untouched
	for (unsigned i = 0; i < height; i++) {
		for (unsigned j = 0; j < width; j++) {
			maze->setWall(i, j, Maze::UP, true);
			maze->setWall(i, j, Maze::LEFT, true);
			maze->setValue(i, j, 0);
		}
	}
	// Count of remaining frontier nodes
	int numFrontier = 0, frontSel = 0;
	unsigned nodeX = 0, nodeY = 0;
	
	for (unsigned i = 0; i < width * height; i++) {

		if (i == 0) {
			// First node must be top left
			maze->setValue(0, 0, _UP);
			maze->setValue(0, 1, FRONTIER);
			maze->setValue(1, 0, FRONTIER);
			numFrontier = 2;
		} else {
			// Pick a random frontier node
			frontSel = rand()%numFrontier;
			for (unsigned r = 0; r < height; r++) {
				for (unsigned c = 0; c < width; c++) {
					if (maze->getValue(r, c) == FRONTIER) {
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
					case _UP:
						if (nodeY > 0 && maze->getValue(nodeY - 1, nodeX) > 0 && maze->getValue(nodeY - 1, nodeX) < 5) {
							maze->setValue(nodeY, nodeX, _UP);
							maze->setWall(nodeY, nodeX, Maze::UP, false);
							flag = true;
						}
						break;
					case _DOWN:
						if (nodeY + 1 < height && maze->getValue(nodeY + 1, nodeX) > 0 && maze->getValue(nodeY + 1, nodeX) < 5) {
							maze->setValue(nodeY, nodeX, _DOWN);
							maze->setWall(nodeY, nodeX, Maze::DOWN, false);
							flag = true;
						}
						break;
					case _RIGHT:
						if (nodeX + 1 < width && maze->getValue(nodeY, nodeX + 1) > 0 && maze->getValue(nodeY, nodeX + 1) < 5) {
							maze->setValue(nodeY, nodeX, _RIGHT);
							maze->setWall(nodeY, nodeX, Maze::RIGHT, false);
							flag = true;
						}
						break;
					case _LEFT:
						if (nodeX > 0 && maze->getValue(nodeY, nodeX - 1) > 0 && maze->getValue(nodeY, nodeX - 1) < 5) {
							maze->setValue(nodeY, nodeX, _LEFT);
							maze->setWall(nodeY, nodeX, Maze::LEFT, false);
							flag = true;
						}
						break;
				} // switch
			} // while
			--numFrontier;
			
			// Add frontier nodes
			if (nodeY > 0 && maze->getValue(nodeY - 1, nodeX) == 0) {
				++numFrontier;
				maze->setValue(nodeY - 1, nodeX, FRONTIER);
			}
			if (nodeY + 1 < height && maze->getValue(nodeY + 1, nodeX) == 0) {
				++numFrontier;
				maze->setValue(nodeY + 1, nodeX, FRONTIER);
			}
			if (nodeX > 0 && maze->getValue(nodeY, nodeX - 1) == 0) {
				++numFrontier;
				maze->setValue(nodeY, nodeX - 1, FRONTIER);
			}
			if (nodeX + 1 < width && maze->getValue(nodeY, nodeX + 1) == 0) {
				++numFrontier;
				maze->setValue(nodeY, nodeX + 1, FRONTIER);
			}
		} // else
	} // for
		
	maze->log();
}

void Generator::recursive()
{

}

void Generator::braid()
{
	maze->reset();
}