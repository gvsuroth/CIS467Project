#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include <QGraphicsGridLayout>
#include <QGLWidget>
#include <QSizePolicy>
#include <QIntValidator>
#include <QMessageBox>
#include <QIcon>

#include <QDebug>

#include "models/maze.h"
#include "generator/generator.h"
#include "algorithms/solver.h"
#include "gui/graphicsview.h"
#include "gui/mazecanvas.h"

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
	MazeCanvas *mc;
	Generator *gen;
	Solver *solver;

public slots:
	//void setDimensions(unsigned width, unsigned height);
	//void redrawGui();
	//void setCell(unsigned y, unsigned x, bool wallUp, bool wallLeft, Maze::Facing facing = Maze::UP);
	void setDimensionsDialog();
	void setNewMazeDimensions();
	void updateAll();
};

#endif // MAINWINDOW_H
