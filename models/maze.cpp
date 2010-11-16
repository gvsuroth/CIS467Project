#include "maze.h"

Maze::Maze(QObject *parent)
	: QObject(parent)
{
	_width = 0;
	_height = 0;
	data = NULL;
}

Maze::~Maze()
{
	cleanUp();
}

void Maze::setDimensions(unsigned width, unsigned height)
{
	cleanUp();
	_width = width;
	_height = height;
	data = new Cell*[height];
	for(unsigned r = 0; r < height; ++r)
	{
		data[r] = new Cell[width];
		for(unsigned c = 0; c < width; ++c)
		{
			data[r][c].wallUp = true;
			data[r][c].wallLeft = true;
			data[r][c].value = 0;
		}
	}
	emit updateAll();
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
			data[r][c].wallUp = true;
			data[r][c].wallLeft = true;
			data[r][c].value = 0;
		}
	}
	emit updateAll();
}

void Maze::resetValues() {
	for (unsigned c = 0; c < _width; ++c) {
		for (unsigned r = 0; r < _height; ++r) {
			data[r][c].value = 0;
		}
	}
	emit updateAll();
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
	emit updateCell(row, column);
}

bool Maze::isWall(unsigned row, unsigned column, Facing direction)
{
	if (validCoord(row, column)) {
		switch (direction) {
			case UP:
				if (row == 0)
					return (column != 0);
				return data[row][column].wallUp;
				break;
			case LEFT:
				if (column == 0)
					return true;
				return data[row][column].wallLeft;
				break;
			case DOWN:
				if (row + 1 == _height)
					return (column + 1 != _width);
				return data[row + 1][column].wallUp;
				break;
			case RIGHT:
				if (column + 1 == _width)
					return true;
				return data[row][column + 1].wallLeft;
				break;
			default:
				break;
		}
	}
	return false;
}

void Maze::setValue(unsigned row, unsigned column, int value)
{
	if (validCoord(row, column))
		data[row][column].value = value;
	emit updateCell(row, column);
}

int Maze::getValue(unsigned row, unsigned column) {
	if (validCoord(row, column))
		return data[row][column].value;
	return -1;
}

Maze::Cell& Maze::getCell(unsigned row, unsigned column)
{
	if (validCoord(row, column))
		return data[row][column];
}

/*void Maze::moveSprite(unsigned row, unsigned column, Facing facing)
{
	if(validCoord(row, column) && data[row][column] != WALL)
	{
		qDebug() << "moveSprite(" << row << ',' << column << ')';
		if (data[row][column] == SPRITE)
			setCell((unsigned)spriteLoc.y(), (unsigned)spriteLoc.x(), PATH);
		setCell(row, column, SPRITE, facing);
		spriteLoc.setY(row);
		spriteLoc.setX(column);
	}
}*/

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

void Maze::cleanUp()
{
	if(data)
	{
		for(unsigned r = 0; r < _height; ++r)
			delete [] data[r];
		delete [] data;
	}
}
