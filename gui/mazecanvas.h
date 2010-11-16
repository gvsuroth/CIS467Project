#ifndef MAZECANVAS_H
#define MAZECANVAS_H

#include <QGraphicsObject>
#include <QPainter>
#include <QCoreApplication>

#include <models/maze.h>

class MazeCanvas : public QGraphicsObject
{
	Q_OBJECT
public:
	explicit MazeCanvas(Maze *maze, QGraphicsItem *parent = 0);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	Maze *maze;

public slots:
	void updateCell(unsigned row, unsigned column);
	void updateAll();
};

#endif // MAZECANVAS_H
