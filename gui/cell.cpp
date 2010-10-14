#include "cell.h"

Cell::Cell(QGraphicsItem *parent, Maze::CellType type)
	: QGraphicsWidget(parent)
{
	QString imgName;
	switch(type)
	{
	case Maze::WALL:
		imgName = "wall";
		break;
	case Maze::SPRITE:
		imgName = "sprite";
		break;
	case Maze::PATH:
		break;
	}
	setPreferredSize(70, 70);
	//setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
	updateGeometry();
	if(!imgName.isNull())
	{
		img = new QGraphicsSvgItem(IMG_PATH+imgName+".svg", this);
		img->scale(preferredWidth() / img->boundingRect().width(), preferredHeight() / img->boundingRect().height());
	}
}

Cell::~Cell()
{
	delete img;
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QPoint topLeft(0,0), bottomLeft(0,boundingRect().height()), bottomRight(boundingRect().width(),boundingRect().height()), topRight(boundingRect().width(),0);
	//qDebug() << painter->background();
	//painter->setBackground(QBrush(QColor(55, 55, 55), Qt::SolidPattern));
	painter->drawLine(topLeft, bottomLeft);
	painter->drawLine(bottomLeft, bottomRight);
	painter->drawLine(bottomRight, topRight);
	painter->drawLine(topRight, topLeft);
}
