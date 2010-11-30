#include "generator.h"
#include <QList>
#include <QSet>

#define _UP 1
#define _LEFT 2
#define _DOWN 3
#define _RIGHT 4
#define FRONTIER 5
#define VISITED 1

Generator::Generator(Maze *maze, QObject *parent) :
	QObject(parent)
{
	this->maze = maze;
}

void Generator::backAndForth()
{
	maze->reset();
	// Back and forth
	bool dir = true;
	unsigned width = maze->width(), height = maze->height();
	for(unsigned c = 0; c < width; ++c)
	{
		for(unsigned r = 1; r < height; ++r)
			maze->setWall(r, c, Maze::UP, false);
		maze->setWall(dir ? height - 1 : 0, c, Maze::RIGHT, false);
		dir=!dir;
	}
}

void Generator::prims()
{
	srand((unsigned)time(NULL));
	unsigned width = maze->width(), height = maze->height();
	maze->reset();
	QList<QPoint> frontier;

	// Count of remaining frontier nodes
	int frontSel = 0;
	unsigned nodeX = 0, nodeY = 0;
	maze->setValue(0, 0, _UP);
	maze->setValue(0, 1, FRONTIER);
	maze->setValue(1, 0, FRONTIER);
	frontier.append(QPoint(0, 1));
	frontier.append(QPoint(1, 0));

	for (unsigned i = 1; i < width * height; i++) {
		// Pick a random frontier node
		frontSel = rand() % frontier.size();
		QPoint nextNode = frontier.takeAt(frontSel);
		nodeX = nextNode.x();
		nodeY = nextNode.y();

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

		// Add frontier nodes
		if (nodeY > 0 && maze->getValue(nodeY - 1, nodeX) == 0) {
			frontier.append(QPoint(nodeX, nodeY - 1));
			maze->setValue(nodeY - 1, nodeX, FRONTIER);
		}
		if (nodeY + 1 < height && maze->getValue(nodeY + 1, nodeX) == 0) {
			frontier.append(QPoint(nodeX, nodeY + 1));
			maze->setValue(nodeY + 1, nodeX, FRONTIER);
		}
		if (nodeX > 0 && maze->getValue(nodeY, nodeX - 1) == 0) {
			frontier.append(QPoint(nodeX - 1, nodeY));
			maze->setValue(nodeY, nodeX - 1, FRONTIER);
		}
		if (nodeX + 1 < width && maze->getValue(nodeY, nodeX + 1) == 0) {
			frontier.append(QPoint(nodeX + 1, nodeY));
			maze->setValue(nodeY, nodeX + 1, FRONTIER);
		}
	} // for
	maze->resetValues();
}

void Generator::backtracker(bool addDeadEnds)
{
	maze->reset();
	QLinkedList<QPoint> cue;
	cue.append(QPoint(0, 0));
	maze->setValue(0, 0, VISITED);
	QPoint curLoc = QPoint(0, 0);
	bool haveEaten = false;

	while (!cue.isEmpty()) {
		// Find neighbors
		int neighbors[4][3];
		int numNeighbors = 0;
		if (maze->getValue(curLoc.y() - 1, curLoc.x()) == 0) {
			neighbors[numNeighbors][0] = curLoc.y() - 1;
			neighbors[numNeighbors][1] = curLoc.x();
			neighbors[numNeighbors++][2] = Maze::UP;
		}
		if (maze->getValue(curLoc.y() + 1, curLoc.x()) == 0) {
			neighbors[numNeighbors][0] = curLoc.y() + 1;
			neighbors[numNeighbors][1] = curLoc.x();
			neighbors[numNeighbors++][2] = Maze::DOWN;
		}
		if (maze->getValue(curLoc.y(), curLoc.x() - 1) == 0) {
			neighbors[numNeighbors][0] = curLoc.y();
			neighbors[numNeighbors][1] = curLoc.x() - 1;
			neighbors[numNeighbors++][2] = Maze::LEFT;
		}
		if (maze->getValue(curLoc.y(), curLoc.x() + 1) == 0) {
			neighbors[numNeighbors][0] = curLoc.y();
			neighbors[numNeighbors][1] = curLoc.x() + 1;
			neighbors[numNeighbors++][2] = Maze::RIGHT;
		}

		if (numNeighbors > 0) {
			haveEaten = true;
			// Pick a random neighbor
			int randNeighbor = rand() % numNeighbors;
			QPoint newPoint = QPoint(neighbors[randNeighbor][1], neighbors[randNeighbor][0]);
			cue.append(newPoint);
			maze->setValue(neighbors[randNeighbor][0], neighbors[randNeighbor][1], VISITED);
			maze->setWall(curLoc.y(), curLoc.x(), (Maze::Facing)neighbors[randNeighbor][2], false);
			curLoc = newPoint;
		} else {
			// Find point on cue with neighbors - backtrack
			if (addDeadEnds && haveEaten) deadEnds.append(curLoc);
			curLoc = cue.takeFirst();
			haveEaten = false;
		}
	}
	maze->resetValues();
}

void Generator::braid()
{
	deadEnds.empty();
	backtracker(true);
	while (!deadEnds.isEmpty()) {
		QPoint loc = deadEnds.takeFirst();
		// Find neighbors that have walls that we can break down
		Maze::Facing neighbors[4];
		int numNeighbors = 0;
		if (loc.y() > 0 && maze->isWall(loc.y(), loc.x(), Maze::UP))
			neighbors[numNeighbors++] = Maze::UP;
		if ((unsigned)loc.y() < maze->height() - 1 && maze->isWall(loc.y(), loc.x(), Maze::DOWN))
			neighbors[numNeighbors++] = Maze::DOWN;
		if (loc.x() > 0 && maze->isWall(loc.y(), loc.x(), Maze::LEFT))
			neighbors[numNeighbors++] = Maze::LEFT;
		if ((unsigned)loc.x() < maze->width() - 1 && maze->isWall(loc.y(), loc.x(), Maze::RIGHT))
			neighbors[numNeighbors++] = Maze::RIGHT;

		// Break down a random wall
		int randWall = rand() % numNeighbors;
		maze->setWall(loc.y(), loc.x(), neighbors[randWall], false);
	}
}

//void Generator::kruskals()
//{
//	int width = maze->width(), height = maze->height();
//	QList<int> walls;
//	for (int i = 0; i < maze->height() * maze->width() * 2 - maze->width(); ++i)
//		if (i % (width * 2) != width - 1) walls.append(i);
//	
//	int row1, row2, col1, col2;
//	while (true) {
//		int wall = walls.takeAt(rand() % (walls.size()));
//		int mod = wall % (width * 2);
//		int div = wall / (width * 2);
//		if (mod < width) {
//			row1 = row2 = div;
//			col1 = mod;
//			col2 = mod + 1;
//		} else {
//			col1 = col2 = mod;
//			row1 = div;
//			row2 = div + 1;
//		}
//		
//	}
//	QList< QSet<int [2]> > sets;
//	for (unsigned r = 0; r < maze->height(); ++r) {
//		for (unsigned c = 0; c < maze->width(); ++c) {
//			QSet<int [2]> set;
//			int point[2];
//			point[0] = r;
//			point[1] = c;
//			set.insert(point);
//			sets.append(set);
//		}
//	}
//	
//}