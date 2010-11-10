#ifndef MAZE_H
#define MAZE_H

#include <QObject>
#include <QPoint>

#include <QDebug>

class Maze : public QObject
{
Q_OBJECT
public:
	struct Cell {
		bool wallUp, wallLeft;
		int data;
	};
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
	void setWall(unsigned row, unsigned column, Facing direction, bool wall);
	void moveSprite(unsigned row, unsigned column, Facing facing = UP);
	void reset();
	void log();
private:
	unsigned _height;
	unsigned _width;
	Cell **data;
	bool validCoord(unsigned row, unsigned column) const;
signals:
	void dimensionsSet(unsigned width, unsigned height);
	void cellChanged(unsigned row, unsigned column, Maze::CellType type, Maze::Facing facing);
};

#endif // MAZE_H
