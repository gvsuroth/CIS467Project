#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include <QGraphicsGridLayout>
#include <QGLWidget>
#include <QSizePolicy>

#include <QDebug>

#include "models/maze.h"
#include "generator/generator.h"
#include "gui/graphicsview.h"

namespace Ui {
	class Gui;
	class Dialog;
}

class Gui : public QMainWindow {
	Q_OBJECT
public:
	Gui(QWidget *parent = 0);
	~Gui();

private:
	void changeEvent(QEvent *e);
	Ui::Gui *ui;
	Ui::Dialog *newMazeUi;
	QGraphicsScene *scene;
	GraphicsView *view;
	QGraphicsWidget *mazeContainer;
	QGraphicsGridLayout *mazeGrid;
	Maze *maze;
	Generator *gen;

signals:
	void generate(int height, int width);

public slots:
	void setDimensions(unsigned width, unsigned height);
	void setCell(unsigned y, unsigned x, Maze::CellType type);
	void showNewMazeDialog();
	void setNewMazeDimensions();
};

#endif // MAINWINDOW_H
