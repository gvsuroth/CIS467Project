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
				painter->fillRect(QRectF(upperLeft + QPointF(PADDING, PADDING), fillSize), val < MAGIC ? (val < 6 ? QColor(210-20*val, 105-10*val, 30-5*val) : QColor(110, 50, 0)) : Qt::red);
		}
	}
	if (maze->height() > 0) {
		painter->drawLine(QPointF(0, maze->height() * CELL_EDGE), QPointF(maze->width() * CELL_EDGE - CELL_EDGE, maze->height() * CELL_EDGE));
		painter->drawLine(QPointF(maze->width() * CELL_EDGE, 0), QPointF(maze->width() * CELL_EDGE, maze->height() * CELL_EDGE));
	}
}

void MazeCanvas::updateAll()
{
	update(boundingRect());
	QCoreApplication::processEvents();
}

void MazeCanvas::updateCell(unsigned row, unsigned column)
{
	update(column * CELL_EDGE, row * CELL_EDGE, CELL_EDGE, CELL_EDGE);
	QCoreApplication::processEvents();
}
