#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGLWidget>
#include <QIntValidator>
#include <QMessageBox>

#include <QDebug>

#include "gui/graphicsview.h"
#include "models/maze.h"
#include "gui/mazecanvas.h"
#include "generator/generator.h"
#include "algorithms/solver.h"

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
	Maze *maze;
	MazeCanvas *mc;
	Generator *gen;
	Solver *solver;

public slots:
	void setDimensionsDialog();
	void setNewMazeDimensions();
	void updateAll();
};

#endif // GUI_H
