#include "solver.h"
#include "mazecanvas.h"
#include <QLinkedList>

Solver::Solver(Maze *maze, QObject *parent) :
	QObject(parent)
{
	this->maze = maze;
}

void Solver::rightHandRule()
{
	maze->resetValues();
	QLinkedList<QPoint> path;
	Maze::Facing facing = Maze::DOWN;
	QPoint curLoc(0, 0);
	QPoint end(maze->width() - 1, maze->height() - 1);
	maze->setValue(0, 0, maze->getValue(0, 0) + 1);
	path << QPoint(curLoc.x(), curLoc.y());
	maze->setValue(curLoc.y(), curLoc.x(), MazeCanvas::MAGIC);
	
	while(curLoc != end)
	{
		Maze::Facing nextFacing = (Maze::Facing)((facing + 1) % 4);
		QPoint nextLoc(0, 0);
		while (maze->isWall(curLoc.y(), curLoc.x(), nextFacing))
			nextFacing = (Maze::Facing)((nextFacing + 3) % 4);
		curLoc = curLoc + QPoint(nextFacing == Maze::RIGHT || nextFacing == Maze::LEFT ? -1 * (nextFacing - 2) : 0, nextFacing == Maze::UP || nextFacing == Maze::DOWN ? (nextFacing - 1) : 0);

		// Add point to path
		// If point already exists in path, remove all points after that point
		QPoint newPoint(curLoc.x(), curLoc.y());
		if (path.contains(newPoint)) {
			QPoint tmp;
			do {
				QPoint tmp = path.takeLast();
				maze->setValue(tmp.y(), tmp.x(), maze->getValue(tmp.y(), tmp.x()) - MazeCanvas::MAGIC);
				if (tmp == newPoint) break;
			} while (tmp != newPoint);
		}
		path << QPoint(curLoc.x(), curLoc.y());

		maze->setValue(curLoc.y(), curLoc.x(), maze->getValue(curLoc.y(), curLoc.x()) + MazeCanvas::MAGIC + 1);
		facing = nextFacing;
	}
}

void Solver::deadEndFiller()
{
	bool flag = true;
	while (flag) {
		flag = false;
		// Find all dead ends, fill them by adding the remaining wall.
		for (unsigned r = 0; r < maze->height(); ++r) {
			for (unsigned c = 0; c < maze->width(); ++c) {
				int numWalls = 0;
				if (maze->isWall(r, c, Maze::UP)) ++numWalls;
				if (maze->isWall(r, c, Maze::DOWN)) ++numWalls;
				if (maze->isWall(r, c, Maze::LEFT)) ++numWalls;
				if (maze->isWall(r, c, Maze::RIGHT)) ++numWalls;
				if (numWalls == 3) {
					// Dead end
					maze->setWall(r, c, Maze::UP, true);
					maze->setWall(r, c, Maze::DOWN, true);
					maze->setWall(r, c, Maze::LEFT, true);
					maze->setWall(r, c, Maze::RIGHT, true);
					flag = true;
				}
			}
		}
	}
}

void Solver::breadthFirst()
{
	maze->resetValues();
	QLinkedList<QPoint> path;
	QPoint end(maze->width() - 1, maze->height() - 1);
	int i = 0;

	maze->setValue(0, 0, 1);
	path.append(QPoint(0, 0));
	while (!path.empty()) {
		QPoint curLoc = path.takeFirst();
		if (maze->getValue(curLoc.y(), curLoc.x()) > i) ++i;
		if (!maze->isWall(curLoc.y(), curLoc.x(), Maze::UP) && maze->getValue(curLoc.y() - 1, curLoc.x()) == 0) {
			path.append(QPoint(curLoc.x(), curLoc.y() - 1));
			maze->setValue(curLoc.y() - 1, curLoc.x(), i + 1);
			if (path.last() == end) break;
		}
		if (!maze->isWall(curLoc.y(), curLoc.x(), Maze::DOWN) && maze->getValue(curLoc.y() + 1, curLoc.x()) == 0) {
			path.append(QPoint(curLoc.x(), curLoc.y() + 1));
			maze->setValue(curLoc.y() + 1, curLoc.x(), i + 1);
			if (path.last() == end) break;
		}
		if (!maze->isWall(curLoc.y(), curLoc.x(), Maze::LEFT) && maze->getValue(curLoc.y(), curLoc.x() - 1) == 0) {
			path.append(QPoint(curLoc.x() - 1, curLoc.y()));
			maze->setValue(curLoc.y(), curLoc.x() - 1, i + 1);
			if (path.last() == end) break;
		}
		if (!maze->isWall(curLoc.y(), curLoc.x(), Maze::RIGHT) && maze->getValue(curLoc.y(), curLoc.x() + 1) == 0) {
			path.append(QPoint(curLoc.x() + 1, curLoc.y()));
			maze->setValue(curLoc.y(), curLoc.x() + 1, i + 1);
			if (path.last() == end) break;
		}
	}
	detectPath();
}

void Solver::aStar()
{
	maze->resetValues();
	QList<QPoint> potential;
	int width = maze->width() - 1, height = maze->height() - 1;
	QPoint end(width, height);
	potential.append(QPoint(0, 0));
	maze->setValue(0, 0, 1);
	
	QPoint curLoc, nextLoc, testLoc;
	int curVal, nextVal, i;
	while (!potential.empty()) {
		curLoc = potential.takeFirst();
		curVal = maze->getValue(curLoc.y(), curLoc.x());
		if (!maze->isWall(curLoc.y(), curLoc.x(), Maze::UP) && maze->getValue(curLoc.y() - 1, curLoc.x()) == 0) {
			nextLoc = QPoint(curLoc.x(), curLoc.y() - 1);
			maze->setValue(curLoc.y() - 1, curLoc.x(), curVal + 1);
			nextVal = curVal + 1 + (width - nextLoc.x()) + (height - nextLoc.y());
			if (nextLoc == end) break;
			i = -1;
			do {
				++i;
				if (i >= potential.size()) break;
				testLoc = potential.at(i);
			} while (maze->getValue(testLoc.y(), testLoc.x()) + (width - testLoc.x()) + (height - testLoc.y()) < nextVal);
			potential.insert(i, nextLoc);
		}
		if (!maze->isWall(curLoc.y(), curLoc.x(), Maze::DOWN) && maze->getValue(curLoc.y() + 1, curLoc.x()) == 0) {
			nextLoc = QPoint(curLoc.x(), curLoc.y() + 1);
			maze->setValue(curLoc.y() + 1, curLoc.x(), curVal + 1);
			nextVal = curVal + 1 + (width - nextLoc.x()) + (height - nextLoc.y());
			if (nextLoc == end) break;
			i = -1;
			do {
				++i;
				if (i >= potential.size()) break;
				testLoc = potential.at(i);
			} while (maze->getValue(testLoc.y(), testLoc.x()) + (width - testLoc.x()) + (height - testLoc.y()) < nextVal);
			potential.insert(i, nextLoc);
		}
		if (!maze->isWall(curLoc.y(), curLoc.x(), Maze::LEFT) && maze->getValue(curLoc.y(), curLoc.x() - 1) == 0) {
			nextLoc = QPoint(curLoc.x() - 1, curLoc.y());
			maze->setValue(curLoc.y(), curLoc.x() - 1, curVal + 1);
			nextVal = curVal + 1 + (width - nextLoc.x()) + (height - nextLoc.y());
			if (nextLoc == end) break;
			i = -1;
			do {
				++i;
				if (i >= potential.size()) break;
				testLoc = potential.at(i);
			} while (maze->getValue(testLoc.y(), testLoc.x()) + (width - testLoc.x()) + (height - testLoc.y()) < nextVal);
			potential.insert(i, nextLoc);
		}
		if (!maze->isWall(curLoc.y(), curLoc.x(), Maze::RIGHT) && maze->getValue(curLoc.y(), curLoc.x() + 1) == 0) {
			nextLoc = QPoint(curLoc.x() + 1, curLoc.y());
			maze->setValue(curLoc.y(), curLoc.x() + 1, curVal + 1);
			nextVal = curVal + 1 + (width - nextLoc.x()) + (height - nextLoc.y());
			if (nextLoc == end) break;
			i = -1;
			do {
				++i;
				if (i >= potential.size()) break;
				testLoc = potential.at(i);
			} while (maze->getValue(testLoc.y(), testLoc.x()) + (width - testLoc.x()) + (height - testLoc.y()) < nextVal);
			potential.insert(i, nextLoc);
		}		
	}
	detectPath();
}

void Solver::detectPath()
{
	int col = maze->width() - 1;
	int row = maze->height() - 1;
	int curVal = maze->getValue(row, col);
	
	while (true) {
		--curVal;
		maze->setValue(row, col, MazeCanvas::MAGIC);
		if (row == 0 && col == 0) break;
		if (!maze->isWall(row, col, Maze::UP) && maze->getValue(row - 1, col) == curVal) {
			row -= 1;
			continue;
		}
		if (!maze->isWall(row, col, Maze::DOWN) && maze->getValue(row + 1, col) == curVal) {
			row += 1;
			continue;
		}
		if (!maze->isWall(row, col, Maze::LEFT) && maze->getValue(row, col - 1) == curVal) {
			col -= 1;
			continue;
		}
		if (!maze->isWall(row, col, Maze::RIGHT) && maze->getValue(row, col + 1) == curVal) {
			col += 1;
			continue;
		}
	}
}