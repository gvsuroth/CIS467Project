#ifndef CELL_H
#define CELL_H

#include <QGraphicsWidget>
#include <QGraphicsSvgItem>
#include <QPainter>

#include <QDebug>

#define IMG_PATH "gui/img/"

class Cell : public QGraphicsWidget
{
public:
	enum Type
	{
		PATH,
		WALL,
		SPRITE
	};
	Cell(QGraphicsItem * = 0, Type = PATH);
	~Cell();
protected:
	QGraphicsSvgItem *img;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CELL_H
