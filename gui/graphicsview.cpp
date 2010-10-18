#include "graphicsview.h"

GraphicsView::GraphicsView(QGraphicsScene *scene, QWidget *parent) :
	QGraphicsView(scene, parent)
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
	fitInView(sceneRect(), Qt::KeepAspectRatio);
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
	if(event->orientation() == Qt::Vertical && (event->modifiers() & Qt::ControlModifier))
	{
		int numDegrees = event->delta() / 8;
		int numSteps = numDegrees / 15;
		scale(1 + .1 * numSteps, 1 + .1 * numSteps);
		qDebug() << numSteps;
		event->accept();
	}
	else
		event->ignore();
}
