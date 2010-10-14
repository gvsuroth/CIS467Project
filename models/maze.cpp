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

Maze::CellType Maze::operator()(unsigned r, unsigned c) const
{
	if(r > 0 && r < _height && c > 0 && c < _width)
		return data[r][c];
}

Maze::CellType Maze::getCell(unsigned r, unsigned c) const
{
	return operator()(r, c);
}

void Maze::setCell(unsigned r, unsigned c, Maze::CellType type)
{
	if(type != data[r][c] && r > 0 && r < _height && c > 0 && c < _width) // the new CellType must be different from the current CellType
	{
		data[r][c] = type;
		emit cellChanged(r, c, type);
	}
}
