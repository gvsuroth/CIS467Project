#include "cell.h"

// Initialize the Cell shared SVG renderers
QSvgRenderer Cell::wallImage(QString(IMG_PATH"wall.svg"));
QSvgRenderer Cell::spriteImage(QString(IMG_PATH"sprite.svg"));

Cell::Cell(QGraphicsItem *parent, Maze::CellType type)
	: QGraphicsLayoutItem(), QGraphicsItem(parent)
{
	img = 0;
	setGraphicsItem(this);
	setCellType(type);
}

Cell::~Cell()
{
	if(img)
		delete img;
}

void Cell::setCellType(Maze::CellType type)
{
	_type = type;
	switch(type)
	{
	case Maze::WALL:
		img = new QGraphicsSvgItem(this);
		img->setSharedRenderer(&wallImage);
		break;
	case Maze::SPRITE:
		img = new QGraphicsSvgItem(this);
		img->setSharedRenderer(&spriteImage);
		break;
	case Maze::PATH:
		delete img;
		img = NULL;
	default:
		return;
	}
	// Scale image
	qreal scaleX = boundingRect().width() / img->boundingRect().width();
	qreal scaleY = boundingRect().height() / img->boundingRect().height();
	img->setScale(scaleX > scaleY ? scaleY : scaleX);
}

Maze::CellType Cell::cellType() const
{
	return _type;
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

	painter->drawRect(boundingRect()); // Add a frame to the cell
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
