#include "cell.h"

Cell::Cell(QGraphicsItem *parent, Maze::CellType type)
	: QGraphicsLayoutItem(), QGraphicsItem(parent)
{
	img = 0;
	setGraphicsItem(this);
	//setPreferredSize(70, 70);
	setCellType(type);
	//setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
	//QGraphicsLayoutItem::setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	//setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	updateGeometry();
	//qDebug() << geometry().size() << boundingRect();
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
		//img->scale(preferredWidth() / img->boundingRect().width(), preferredHeight() / img->boundingRect().height());
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
	//img->scale(geometry().width() / img->boundingRect().width(), geometry().height() / img->boundingRect().height());
	/*if(img)
	{
		qreal scaleX = geometry().width() / img->boundingRect().width();
		qreal scaleY = geometry().height() / img->boundingRect().height();
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
		return QSizeF(70, 70);
	case Qt::MaximumSize:
		return QSizeF(1000, 1000);
	default:
		break;
	}
	return constraint;
}

void Cell::setGeometry(const QRectF &rect)
{
	//qDebug() << "setGeom" << rect;
	prepareGeometryChange();
	QGraphicsLayoutItem::setGeometry(rect);
	setPos(rect.topLeft());
	if(img)
	{
		//img->scale(rect.width() / img->boundingRect().width(), rect.height() / img->boundingRect().height());
		qreal scaleX = rect.width() / img->boundingRect().width();
		qreal scaleY = rect.height() / img->boundingRect().height();
		img->setScale(scaleX > scaleY ? scaleY : scaleX);
		//qDebug() << scaleX << scaleY;
		//qDebug() << rect.width();
	}
}
