#include "mazecanvas.h"

#define CELL_EDGE 5
#define PADDING 1

MazeCanvas::MazeCanvas(Maze *maze, QGraphicsItem *parent) :
		QGraphicsObject(parent)
{
	this->maze = maze;
}

QRectF MazeCanvas::boundingRect() const
{
	return QRectF(0, 0, maze->width() * CELL_EDGE, maze->height() * CELL_EDGE);
}

void MazeCanvas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);
	Q_UNUSED(option);

	/*unsigned deltaX = geometry().size().width() / _maze->width();
	unsigned deltaY = geometry().size().height() / _maze->height();
	unsigned deltaX;
	unsigned deltaY;
	deltaX = deltaY = CELL_EDGE;
	printf("Drawing Maze: (%d, %d)\n", deltaX, deltaY);

	for (unsigned r = 0; r < maze->height(); ++r) {
		for (unsigned c = 0; c < maze->width(); ++c) {
			if (maze->isWall(r, c, Maze::UP))
				painter->drawLine(QPoint(c * deltaX, r * deltaY), QPoint(c * deltaX + deltaX, r * deltaY));
			int val = maze->getValue(r, c);
			if (val == 1000)
				painter->fillRect(QRectF(QPointF(c * deltaX + 1, r * deltaY + 1), QPointF(c*deltaX + deltaX - 1, r*deltaY+deltaY - 1)), Qt::red);
			else if (val > 0)
				painter->fillRect(QRectF(QPointF(c * deltaX + 1, r * deltaY + 1), QPointF(c*deltaX + deltaX - 1, r*deltaY+deltaY - 1)), QColor(210-2*val, 105-2*val, 30-val));
		}
		for (unsigned c = 0; c < maze->width(); ++c) {
			if (maze->isWall(r, c, Maze::LEFT))
				painter->drawLine(QPoint(c * deltaX, r * deltaY), QPoint(c * deltaX, r * deltaY + deltaY));
		}
	}*/
	QPointF upperLeft;
	int val;
	const QSizeF fillSize(CELL_EDGE - 2 * PADDING, CELL_EDGE - 2 * PADDING);
	for(unsigned r = 0; r < maze->height(); ++r)
	{
		for(unsigned c = 0; c < maze->width(); ++c)
		{
			upperLeft = QPointF(c * CELL_EDGE, r * CELL_EDGE);
			if(maze->isWall(r, c, Maze::UP)) // Upper wall
				painter->drawLine(upperLeft, upperLeft + QPointF(CELL_EDGE, 0));
			if(maze->isWall(r, c, Maze::LEFT)) // Left wall
				painter->drawLine(upperLeft, upperLeft + QPointF(0, CELL_EDGE));
			val = maze->getValue(r, c);
			if(val) // Color of the cell
//				painter->fillRect(QRectF(upperLeft + QPointF(PADDING, PADDING), fillSize), val < MAGIC ? (val < 6 ? QColor(255-20*val, 255-20*val, 255-20*val) : QColor(110, 50, 0)) : Qt::red);
			painter->fillRect(QRectF(upperLeft + QPointF(PADDING, PADDING), fillSize), val < MAGIC ? (QColor(255-10*val, 255-10*val, 255-10*val)) : Qt::red);
		}
	}
	if (maze->height() > 0) {
		painter->drawLine(QPointF(0, maze->height() * CELL_EDGE), QPointF(maze->width() * CELL_EDGE - CELL_EDGE, maze->height() * CELL_EDGE));
		painter->drawLine(QPointF(maze->width() * CELL_EDGE, 0), QPointF(maze->width() * CELL_EDGE, maze->height() * CELL_EDGE));
	}
}

void MazeCanvas::updateAll()
{
	qDebug() << boundingRect();
	update(boundingRect());
	QCoreApplication::processEvents();
}

void MazeCanvas::updateCell(unsigned row, unsigned column)
{
	update(column * CELL_EDGE, row * CELL_EDGE, CELL_EDGE, CELL_EDGE);
	QCoreApplication::processEvents();
}
