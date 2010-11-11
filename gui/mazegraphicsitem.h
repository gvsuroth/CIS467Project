/*
 *  mazegraphicsitem.h
 *  CIS467Project
 *
 *  Created by Joseph Roth on 11/11/10.
 *  Copyright 2010 Atomic Object. All rights reserved.
 *
 */

#ifndef MAZE_GRAPHICS_ITEM_H
#define MAZE_GRAPHICS_ITEM_H

#include <QGraphicsItem>
#include <QGraphicsLayoutItem>
#include <QPainter>

class Maze;

class MazeGraphicsItem : public QGraphicsLayoutItem, public QGraphicsItem
{
public:
	MazeGraphicsItem(QGraphicsItem *parent = 0, Maze *maze = 0);
	~MazeGraphicsItem();
	
	// Inherited from QGraphicsItem
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
private:
	Maze *_maze;
};

#endif // MAZE_GRAPHICS_ITEM_H