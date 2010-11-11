/*
 *  mazegraphicsitem.cpp
 *  CIS467Project
 *
 *  Created by Joseph Roth on 11/11/10.
 *  Copyright 2010 Atomic Object. All rights reserved.
 *
 */

#include "mazegraphicsitem.h"
#include "models/maze.h"

MazeGraphicsItem::MazeGraphicsItem(QGraphicsItem *parent, Maze *maze)
	: QGraphicsLayoutItem(), QGraphicsItem(parent)
{
	setGraphicsItem(this);
	_maze = maze;
}

MazeGraphicsItem::~MazeGraphicsItem()
{

}

QRectF MazeGraphicsItem::boundingRect() const
{
	return QRectF(QPointF(0, 0), geometry().size());
}

void MazeGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);
	Q_UNUSED(option);
	
	unsigned deltaX = geometry().size().width() / _maze->width();
	unsigned deltaY = geometry().size().height() / _maze->height();

	for (unsigned r = 0; r < _maze->height(); ++r) {
		for (unsigned c = 0; c < _maze->width(); ++c) {
			if (_maze->isWall(r, c, Maze::UP))
				painter->drawLine(QPoint(c * deltaX, r * deltaY), QPoint(c * deltaX + deltaX, r * deltaY));
		}
		for (unsigned c = 0; c < _maze->width(); ++c) {
			if (_maze->isWall(r, c, Maze::LEFT))
				painter->drawLine(QPoint(c * deltaX, r * deltaY), QPoint(c * deltaX, r * deltaY + deltaY));
		}
	}
	painter->drawLine(QPoint(0, _maze->height() * deltaY), QPoint((_maze->width() - 1) * deltaX, _maze->height() * deltaY));
}