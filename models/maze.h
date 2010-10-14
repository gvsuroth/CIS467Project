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
		SPRITE
	};
	explicit Maze(QObject *parent = 0);
	~Maze();
	void setDimensions(unsigned width, unsigned height);
	unsigned width();
	unsigned height();
	CellType operator()(unsigned r, unsigned c) const;
	CellType getCell(unsigned r, unsigned c) const;
	void setCell(unsigned r, unsigned c, CellType type);
private:
	unsigned _height;
	unsigned _width;
	CellType **data;
signals:
	void cellChanged(unsigned r, unsigned c, Maze::CellType type);
public slots:

};

#endif // MAZE_H
