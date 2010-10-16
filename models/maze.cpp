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
	data = new CellType*[height];

	for(unsigned r = 0; r < height; ++r)
	{
		data[r] = new CellType[width];
		for(unsigned c = 0; c < width; ++c)
			setCell(r, c, PATH);
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

bool Maze::validCoord(unsigned row, unsigned column) const
{
	return row >= 0 && row < _height && column >= 0 && column < _width;
}

Maze::CellType Maze::operator()(unsigned row, unsigned column) const
{
	if(validCoord(row, column))
		return data[row][column];
}

Maze::CellType Maze::getCell(unsigned row, unsigned column) const
{
	return operator()(row, column);
}

void Maze::setCell(unsigned row, unsigned column, Maze::CellType type)
{
	if(type != data[row][column] && validCoord(row, column)) // the new CellType must be different from the current CellType
	{
		data[row][column] = type;
		emit cellChanged(row, column, type);
	}
}
