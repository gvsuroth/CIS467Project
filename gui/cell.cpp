#include "cell.h"

// Initialize the Cell shared SVG renderes
//QSvgRenderer Cell::wallImage(QString(IMG_PATH"wall.svg"));
//QSvgRenderer Cell::spriteImage(QString(IMG_PATH"sprite.svg"));

Cell::Cell(QGraphicsItem *parent, bool wallUp, bool wallLeft)
	: QGraphicsLayoutItem(), QGraphicsItem(parent)
{
        //img = 0;
	setGraphicsItem(this);
	setWallUp(wallUp);
	setWallLeft(wallLeft);
}

Cell::~Cell()
{
        //if(img)
                //delete img;
}

void Cell::setWallUp(bool wallUp)
{
	_wallUp = wallUp;
}

bool Cell::wallUp() const
{
	return _wallUp;
}

void Cell::setWallLeft(bool wallLeft)
{
	_wallLeft = wallLeft;
}

bool Cell::wallLeft() const
{
	return _wallLeft;
}

void Cell::setFacing(Maze::Facing facing)
{
	setRotation(facing * 90);
}

QRectF Cell::boundingRect() const
{
	return QRectF(QPointF(0, 0), geometry().size());
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);
	Q_UNUSED(option);

//	painter->drawRect(boundingRect()); // Add a frame to the cell
	if (_wallUp)
		painter->drawLine(QPointF(0, 0), QPointF(geometry().size().width(), 0));
	if (_wallLeft)
		painter->drawLine(QPointF(0, 0), QPointF(0, geometry().size().height()));
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
	setTransformOriginPoint(rect.width() / 2, rect.height() / 2); // For rotation
}
