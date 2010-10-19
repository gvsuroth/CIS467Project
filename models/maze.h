#ifndef MAZE_H
#define MAZE_H

#include <QObject>

#include <QDebug>

class Maze : public QObject
{
Q_OBJECT
public:
	enum CellType
	{
		PATH,
		WALL,
		SPRITE,
		ERROR
	};
	explicit Maze(QObject *parent = 0);
	~Maze();
	void setDimensions(unsigned width, unsigned height);
	unsigned width();
	unsigned height();
	CellType operator()(unsigned row, unsigned column) const;
	CellType getCell(unsigned row, unsigned column) const;
	void setCell(unsigned row, unsigned column, CellType type);
private:
	unsigned _height;
	unsigned _width;
	CellType **data;
	bool validCoord(unsigned row, unsigned column) const;
signals:
	void dimensionsSet(unsigned width, unsigned height);
	void cellChanged(unsigned row, unsigned column, Maze::CellType type);
};

#endif // MAZE_H
