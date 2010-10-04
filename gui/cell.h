#ifndef CELL_H
#define CELL_H

#include <QGraphicsWidget>
#include <QGraphicsSvgItem>
//#include <QSizeF>

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
	Cell(QGraphicsItem *parent = 0, Type type = PATH);
protected:
	//QSizeF sizeHint(Qt::SizeHint which, const QSizeF& constraint = QSizeF()) const;
	QGraphicsSvgItem *img;
};

#endif // CELL_H
