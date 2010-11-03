#include "maze.h"
#include "gui/gui.h"

Maze::Maze(Gui *gui, QObject *parent)
	: QObject(parent), spriteLoc(0, 0)
{
        this->gui = gui;
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
		{
			data[r][c] = ERROR;
			setCell(r, c, PATH);
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

Maze::CellType Maze::operator()(unsigned row, unsigned column) const
{
	if(validCoord(row, column))
		return data[row][column];
	return Maze::ERROR;
}

Maze::CellType Maze::getCell(unsigned row, unsigned column) const
{
	return operator()(row, column);
}

void Maze::setCell(unsigned row, unsigned column, Maze::CellType type, Facing facing)
{
	if(type != data[row][column] && validCoord(row, column)) // the new CellType must be different from the current CellType
	{
		data[row][column] = type;
                emit cellChanged(row, column, type, facing);
                //this->gui->setCell(row, column, type, facing);
	}
}

void Maze::moveSprite(unsigned row, unsigned column, Facing facing)
{
	if(validCoord(row, column) && data[row][column] != WALL)
	{
		qDebug() << "moveSprite(" << row << ',' << column << ')';
		setCell((unsigned)spriteLoc.y(), (unsigned)spriteLoc.x(), PATH);
		setCell(row, column, SPRITE, facing);
		spriteLoc.setY(row);
		spriteLoc.setX(column);
	}
}
