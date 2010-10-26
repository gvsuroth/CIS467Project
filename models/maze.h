#ifndef MAZE_H
#define MAZE_H

#include <QObject>
#include <QPoint>

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
	enum Facing
	{
		UP,
		RIGHT,
		DOWN,
		LEFT
	};

	explicit Maze(QObject *parent = 0);
	~Maze();
	void setDimensions(unsigned width, unsigned height);
	unsigned width();
	unsigned height();
	CellType operator()(unsigned row, unsigned column) const;
	CellType getCell(unsigned row, unsigned column) const;
	void setCell(unsigned row, unsigned column, CellType type, Facing facing = UP);
	void moveSprite(unsigned row, unsigned column, Facing facing = UP);
private:
	unsigned _height;
	unsigned _width;
	CellType **data;
	QPoint spriteLoc;
	bool validCoord(unsigned row, unsigned column) const;
signals:
	void dimensionsSet(unsigned width, unsigned height);
	void cellChanged(unsigned row, unsigned column, Maze::CellType type, Maze::Facing facing);
};

#endif // MAZE_H
