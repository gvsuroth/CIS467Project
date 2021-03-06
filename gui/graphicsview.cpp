#include "graphicsview.h"

GraphicsView::GraphicsView(QGraphicsScene *scene, QWidget *parent) :
	QGraphicsView(scene, parent)
{
}

void GraphicsView::zoomIn()
{
	scale(1.2, 1.2);
}

void GraphicsView::zoomOut()
{
	scale(1 / 1.2, 1 / 1.2);
}

void GraphicsView::zoomReset()
{
	fitInView(sceneRect(), Qt::KeepAspectRatio);
	scale(1 / 1.1, 1 / 1.1);
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
	if(event->orientation() == Qt::Vertical && event->modifiers() & Qt::ControlModifier)
	{
		qreal factor = 1 / (1 - (qreal)event->delta() / 600); // 1 /*normalize*/ / (1 /*add 100%*/ - (qreal)event->delta() /*mouse wheel*/ / 8 /*now in degrees*/ / 15 /*now in "steps"*/ / 5 /*now in fifths of steps*/
		scale(factor,factor);
		event->accept();
	}
	else
		QGraphicsView::wheelEvent(event);
}
