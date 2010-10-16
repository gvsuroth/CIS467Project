#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSizePolicy>
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>
#include <QGraphicsSvgItem>

#include <QDebug>

#include "models/maze.h"
#include "generator/generator.h"

namespace Ui {
	class Gui;
}

class Gui : public QMainWindow {
	Q_OBJECT
public:
	Gui(QWidget *parent = 0);
	~Gui();

protected:
	void changeEvent(QEvent *e);
	Ui::Gui *ui;
	QGridLayout *gridLayout;
	QGraphicsScene *scene;
	QGraphicsView *view;
	QGraphicsWidget *mazeContainer;
	QGraphicsGridLayout *mazeGrid;
	Maze *maze;
	Generator *gen;

signals:
	void generate(int height, int width); // Temp function

public slots:
	void setDimensions(unsigned width, unsigned height);
	void setCell(unsigned y, unsigned x, Maze::CellType type);
};

#endif // MAINWINDOW_H
