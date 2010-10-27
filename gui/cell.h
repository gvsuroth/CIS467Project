#ifndef CELL_H
#define CELL_H

#include <QGraphicsItem>
#include <QGraphicsLayoutItem>
#include <QGraphicsSvgItem>
#include <QSvgRenderer>
#include <QPainter>

#include <QDebug>

#include "models/maze.h"

#define IMG_PATH ":/gui/img/"

class Cell : public QGraphicsLayoutItem, public QGraphicsItem
{
public:
	Cell(QGraphicsItem *parent = 0, Maze::CellType type = Maze::PATH);
	~Cell();
	void setCellType(Maze::CellType type);
	Maze::CellType cellType() const;
	void setFacing(Maze::Facing facing);

	// Inherited from QGraphicsLayoutItem
	QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;
	void setGeometry(const QRectF &rect);

	// Inherited from QGraphicsItem
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
private:
	Maze::CellType _type;
	QGraphicsSvgItem *img;
	static QSvgRenderer wallImage;// = new QGraphicsSvgItem(IMG_PATH"wall.svg");
	static QSvgRenderer spriteImage;// = new QGraphicsSvgItem(IMG_PATH"sprite.svg");
};

#endif // CELL_H
