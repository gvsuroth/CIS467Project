#include "gui.h"
#include "ui_gui.h"
#include "ui_newmaze.h"

#include "cell.h"

Gui::Gui(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Gui),
	newMazeUi(new Ui::Dialog)
{
	// Setup ui
	ui->setupUi(this);

	// Setup maze
	maze = new Maze(this);

	// Setup generator
	gen = new Generator(maze);
	connect(ui->action_Back_and_Forth, SIGNAL(triggered()), gen, SLOT(backAndForth()));
	connect(ui->action_Prim_s_Algorithm, SIGNAL(triggered()), gen, SLOT(prims()));
	connect(ui->action_Backtracker_Algorithm, SIGNAL(triggered()), gen, SLOT(backtracker()));
	connect(ui->action_Braid_Maze, SIGNAL(triggered()), gen, SLOT(braid()));

	// Setup solver
	solver = new Solver(maze);
	connect(ui->action_Right_Hand_Rule, SIGNAL(triggered()), solver, SLOT(rightHandRule()));
	connect(ui->action_Dead_End_Filler, SIGNAL(triggered()), solver, SLOT(deadEndFiller()));

	// Setup scene
	scene = new QGraphicsScene;
	//mazeContainer = new QGraphicsWidget;
	//mazeGrid = new QGraphicsGridLayout;
	//mazeGrid->setSpacing(0); // Make the cell spacing nothing
	//mazeContainer->setLayout(mazeGrid);
	scene->setBackgroundBrush(QBrush(QColor(210, 105, 30), Qt::SolidPattern)); // Set background color
	//scene->addItem(mazeContainer);

	// Setup maze canvas
	mc = new MazeCanvas(maze);
	//connect(maze, SIGNAL(updateAll()), mc, SLOT(updateAll()));
	connect(maze, SIGNAL(updateAll()), this, SLOT(updateAll()));
	connect(maze, SIGNAL(updateCell(uint,uint)), mc, SLOT(updateCell(uint,uint)));
	scene->addItem(mc);

	// Setup view
	view = new GraphicsView(scene);
	//view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers))); // Enable OpenGL support
	connect(scene, SIGNAL(sceneRectChanged(QRectF)), view, SLOT(zoomReset())); // Auto-reset when scene size changes
	connect(ui->action_Zoom_In, SIGNAL(triggered()), view, SLOT(zoomIn()));
	connect(ui->action_Zoom_Out, SIGNAL(triggered()), view, SLOT(zoomOut()));
	connect(ui->action_Reset, SIGNAL(triggered()), view, SLOT(zoomReset()));
	connect(ui->action_Dimensions, SIGNAL(triggered()), this, SLOT(setDimensionsDialog()));
	setCentralWidget(view);

}

Gui::~Gui()
{
	delete ui;
	delete newMazeUi;
	delete view;
	delete maze;
	delete mc;
	delete gen;
}

/*void Gui::setDimensions(unsigned width, unsigned height)
{
//	for(unsigned r = 0; r < height; ++r)
//		for(unsigned c = 0; c < width; ++c)
//			mazeGrid->addItem(new Cell(), r, c, Qt::AlignCenter);
//	Cell *cell = new Cell();
//	cell->setMaze(maze);
//	mazeGrid->addItem(cell, 0, 0, Qt::AlignCenter);
	//mc->update(mc->boundingRect());
	//view->update();
	//mc->update(0, 0, 500, 500);
	qDebug() << "setDimensions" << mc->boundingRect();
	mc->update(mc->boundingRect());
	//qDebug() << "redraw" << mc->boundingRect();
}

void Gui::redrawGui()
{
	//view->update();
	//QCoreApplication::processEvents();
	//mc->update(mc->boundingRect());
	//qDebug() << "redraw";
}

void Gui::setCell(unsigned row, unsigned column, bool wallUp, bool wallLeft, Maze::Facing facing)
{
	if(row < (unsigned)mazeGrid->rowCount() && column < (unsigned)mazeGrid->columnCount())
	{
//		qDebug() << "setCell(" << row << ',' << column << ',' << type << ',' << facing << ')';
//		Cell *_cell = (Cell*)mazeGrid->itemAt(row, column);
//		_cell->setWallUp(wallUp);
//		_cell->setWallLeft(wallLeft);
//		_cell->setFacing(facing);
	}
}*/

void Gui::setDimensionsDialog()
{
	QDialog newMazeDialog(this);
	newMazeUi->setupUi(&newMazeDialog);
	QIntValidator intVal;
	newMazeUi->rows->setValidator(&intVal);
	newMazeUi->columns->setValidator(&intVal);
	connect(newMazeUi->buttonBox, SIGNAL(accepted()), this, SLOT(setNewMazeDimensions()));
	newMazeDialog.exec();
}

void Gui::setNewMazeDimensions()
{
	bool rowsOk;
	bool columnsOk;
	unsigned rows = newMazeUi->rows->text().toUInt(&rowsOk, 10);
	unsigned columns = newMazeUi->columns->text().toUInt(&columnsOk, 10);
	if(rowsOk && columnsOk)
		maze->setDimensions(rows, columns);
	else
		QMessageBox(QMessageBox::Warning, "Maze Dimensions", "Incorrect maze dimensions").exec();
}

void Gui::updateAll()
{
	scene->setSceneRect(mc->boundingRect());
}

void Gui::changeEvent(QEvent *e)
{
	QMainWindow::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}
