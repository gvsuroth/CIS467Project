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

void Cell::setMaze(Maze *maze) {
	_maze = maze;
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

	unsigned deltaX = geometry().size().width() / _maze->width();
	unsigned deltaY = geometry().size().height() / _maze->height();
	printf("Drawing Maze: (%d, %d)\n", deltaX, deltaY);
	
	for (unsigned r = 0; r < _maze->height(); ++r) {
		for (unsigned c = 0; c < _maze->width(); ++c) {
			if (_maze->isWall(r, c, Maze::UP))
				painter->drawLine(QPoint(c * deltaX, r * deltaY), QPoint(c * deltaX + deltaX, r * deltaY));
			int val = _maze->getValue(r, c);
			if (val > 0)
				painter->fillRect(QRectF(QPointF(c * deltaX + 1, r * deltaY + 1), QPointF(c*deltaX + deltaX - 1, r*deltaY+deltaY - 1)), QColor(255-50*val, 255-50*val, 255-50*val));
		}
		for (unsigned c = 0; c < _maze->width(); ++c) {
			if (_maze->isWall(r, c, Maze::LEFT))
				painter->drawLine(QPoint(c * deltaX, r * deltaY), QPoint(c * deltaX, r * deltaY + deltaY));
		}
	}
	// Right wall
	painter->drawLine(QPoint(_maze->width() * deltaX, 0), QPoint(_maze->width() * deltaX, _maze->height() * deltaY));
	// Bottom row
	painter->drawLine(QPoint(0, _maze->height() * deltaY), QPoint((_maze->width() - 1) * deltaX, _maze->height() * deltaY));
	
//	painter->drawRect(boundingRect()); // Add a frame to the cell
//	if (_wallUp)
//		painter->drawLine(QPointF(0, 0), QPointF(geometry().size().width(), 0));
//	if (_wallLeft)
//		painter->drawLine(QPointF(0, 0), QPointF(0, geometry().size().height()));
}

QSizeF Cell::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
	switch(which)
	{
	case Qt::MinimumSize:
		return QSizeF(_maze->width() * 4, _maze->height() * 4);
	case Qt::PreferredSize:
		return QSizeF(100, 100);
	case Qt::MaximumSize:
		return QSizeF(100000, 100000);
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
