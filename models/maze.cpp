#include "maze.h"

Maze::Maze(QObject *parent)
	: QObject(parent)
{
}

Maze::~Maze()
{
	for(unsigned r = 0; r < _height; ++r)
		delete [] data[r];
	delete [] data;
}

void Maze::setDimensions(unsigned width, unsigned height)
{
	emit dimensionsSet(width, height);
	_width = width;
	_height = height;
	data = new Cell*[height];
	for(unsigned r = 0; r < height; ++r)
	{
		data[r] = new Cell[width];
		for(unsigned c = 0; c < width; ++c)
		{
			setWall(r, c, UP, true);
			setWall(r, c, LEFT, true);
		}
	}
}

unsigned Maze::width()
{
	return _width;
}

unsigned Maze::height()
{
	return _height;
}

inline bool Maze::validCoord(unsigned row, unsigned column) const
{
	return row < _height && column < _width;
}

void Maze::reset() {
	for (unsigned c = 0; c < _width; ++c) {
		for (unsigned r = 0; r < _height; ++r) {
			setWall(r, c, UP, true);
			setWall(r, c, LEFT, true);
		}
	}
}

void Maze::setWall(unsigned row, unsigned column, Facing direction, bool wall)
{
	if (validCoord(row, column)) {
		switch (direction) {
			case UP:
				data[row][column].wallUp = wall;
				break;
			case LEFT:
				data[row][column].wallLeft = wall;
				break;
			case DOWN:
				if (row + 1 < _height)
					data[row + 1][column].wallUp = wall;
				break;
			case RIGHT:
				if (column + 1 < _width)
					data[row][column + 1].wallLeft = wall;
				break;
			default:
				break;
		}
	}
}

bool Maze::isWall(unsigned row, unsigned column, Facing direction)
{
	if (validCoord(row, column)) {
		switch (direction) {
			case UP:
				if (row == 0)
					return (column != 0);
				else
					return data[row][column].wallUp;
				break;
			case LEFT:
				if (column == 0)
					return true;
				else
					return data[row][column].wallLeft;
				break;
			case DOWN:
				if (row + 1 == _height)
					return (column + 1 != _width);
				else
					return data[row + 1][column].wallUp;
				break;
			case RIGHT:
				if (column + 1 == _width)
					return true;
				else
					return data[row][column + 1].wallLeft;
				break;
			default:
				break;
		}
		emit cellChanged(row, column, data[row][column].wallLeft, data[row][column].wallUp, UP);
	}
	return false;
}

void Maze::setValue(unsigned row, unsigned column, int value)
{
	if (validCoord(row, column))
		data[row][column].value = value;
}

int Maze::getValue(unsigned row, unsigned column) {
	if (validCoord(row, column))
		return data[row][column].value;
	return 0;
}

Maze::Cell Maze::getCell(unsigned row, unsigned column) {
	if (validCoord(row, column))
		return data[row][column];
}

void Maze::moveSprite(unsigned row, unsigned column, Facing facing)
{
//	if(validCoord(row, column) && data[row][column] != WALL)
//	{
//		qDebug() << "moveSprite(" << row << ',' << column << ')';
//		if (data[row][column] == SPRITE)
//			setCell((unsigned)spriteLoc.y(), (unsigned)spriteLoc.x(), PATH);
//		setCell(row, column, SPRITE, facing);
//		spriteLoc.setY(row);
//		spriteLoc.setX(column);
//	}
}

void Maze::log()
{
	for (unsigned r = 0; r < _height; ++r) {
		for (unsigned c = 0; c < _width; ++c) {
			printf(" %s", (isWall(r, c, UP) ? "-" : " "));
		}
		printf("\n");
		for (unsigned c = 0; c < _width; ++c) {
			printf("%s ", (isWall(r, c, LEFT) ? "|" : " "));
		}
		printf("|\n");
	}
	for (unsigned c = 0; c < _width - 1; ++c)
		printf(" -");
	printf("\n");
		
}