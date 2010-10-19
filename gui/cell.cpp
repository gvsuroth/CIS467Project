#include "cell.h"

Cell::Cell(QGraphicsItem *parent, Maze::CellType type)
	: QGraphicsLayoutItem(), QGraphicsItem(parent)
{
	//qDebug() << "Cell constructor";
	img = 0;
	setGraphicsItem(this);
	setCellType(type);
}

Cell::~Cell()
{
	delete img;
}

void Cell::setCellType(Maze::CellType type)
{
	_type = type;
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
	default:
		return;
	}
	img = new QGraphicsSvgItem(IMG_PATH+imgName+".svg", this);
	//img->scale(rect.width() / img->boundingRect().width(), rect.height() / img->boundingRect().height());
	qreal scaleX = boundingRect().width() / img->boundingRect().width();
	qreal scaleY = boundingRect().height() / img->boundingRect().height();
	img->setScale(scaleX > scaleY ? scaleY : scaleX);
}

Maze::CellType Cell::cellType() const
{
	return _type;
}

QRectF Cell::boundingRect() const
{
	return QRectF(QPointF(0, 0), geometry().size());
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);
	Q_UNUSED(option);

	painter->drawRect(boundingRect()); // Add a frame to the cell

	/*if(img)
	{
		//img->scale(rect.width() / img->boundingRect().width(), rect.height() / img->boundingRect().height());
		qreal scaleX = boundingRect().width() / img->boundingRect().width();
		qreal scaleY = boundingRect().height() / img->boundingRect().height();
		img->setScale(scaleX > scaleY ? scaleY : scaleX);
	}*/
}

QSizeF Cell::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
	switch(which)
	{
	case Qt::MinimumSize:
		return QSizeF(20, 20);
	case Qt::PreferredSize:
		return QSizeF(100, 100);
	case Qt::MaximumSize:
		return QSizeF(1000, 1000);
	default:
		break;
	}
	return constraint;
}

void Cell::setGeometry(const QRectF &rect)
{
	prepareGeometryChange();
	QGraphicsLayoutItem::setGeometry(rect);
	setPos(rect.topLeft());
	/*if(img)
	{
		//img->scale(rect.width() / img->boundingRect().width(), rect.height() / img->boundingRect().height());
		qreal scaleX = rect.width() / img->boundingRect().width();
		qreal scaleY = rect.height() / img->boundingRect().height();
		img->setScale(scaleX > scaleY ? scaleY : scaleX);
	}*/
}
