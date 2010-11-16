#ifndef MAZE_H
#define MAZE_H

#include <QObject>
#include <QPoint>

#include <QDebug>

class Maze : public QObject
{
Q_OBJECT
public:
	struct Cell
	{
		bool wallUp, wallLeft;
		int value;
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
	bool isWall(unsigned row, unsigned column, Facing direction);
	void setValue(unsigned row, unsigned column, int value);
	int getValue(unsigned row, unsigned column);
	void moveSprite(unsigned row, unsigned column, Facing facing = UP);
	Cell getCell(unsigned row, unsigned column);
	void reset();
	void resetValues();
	void log();
private:
	unsigned _height;
	unsigned _width;
	Cell **data;
	bool validCoord(unsigned row, unsigned column) const;
signals:
	void updateAll();
	void updateCell(unsigned row, unsigned column);
};

#endif // MAZE_H
