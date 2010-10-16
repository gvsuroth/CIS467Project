#ifndef CELL_H
#define CELL_H

#include <QGraphicsWidget>
#include <QGraphicsSvgItem>
#include <QPainter>

#include <QDebug>

#include "models/maze.h"

#define IMG_PATH "gui/img/"

class Cell : public QGraphicsWidget
{
public:
	Cell(QGraphicsItem *parent = 0, Maze::CellType type = Maze::PATH);
	~Cell();
	void setCellType(Maze::CellType type);
	Maze::CellType cellType() const;
protected:
	Maze::CellType _type;
	QGraphicsSvgItem *img;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CELL_H
