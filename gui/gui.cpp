#include "gui.h"
#include "ui_gui.h"
#include "ui_newmaze.h"

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
	connect(ui->action_Breadth_First, SIGNAL(triggered()), solver, SLOT(breadthFirst()));
	connect(ui->action_A_Star, SIGNAL(triggered()), solver, SLOT(aStar()));

	// Setup scene
	scene = new QGraphicsScene;
	scene->setBackgroundBrush(QBrush(QColor(210, 105, 30), Qt::SolidPattern)); // Set background color

	// Setup maze canvas
	mc = new MazeCanvas(maze);
	connect(maze, SIGNAL(updateAll()), this, SLOT(updateAll()));
//	connect(maze, SIGNAL(updateCell(uint,uint)), mc, SLOT(updateCell(uint,uint)));
	scene->addItem(mc);

	// Setup view
	view = new GraphicsView(scene);
	view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers))); // Enable OpenGL support
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
	scene->setSceneRect(mc->boundingRect()); // Setting the sceneRect is quicker than letting the scene find its own boundaries, and also triggers the signal sceneRectChanged, which activates the auto-zoom from the view
	mc->updateAll();
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
