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
	connect(ui->action_Back_and_Forth, SIGNAL(triggered()), this, SLOT(genBackAndForth()));
	connect(ui->action_Prim_s_Algorithm, SIGNAL(triggered()), this, SLOT(genPrims()));
	connect(ui->action_Backtracker_Algorithm, SIGNAL(triggered()), this, SLOT(genBacktracker()));
	connect(ui->action_Braid_Maze, SIGNAL(triggered()), this, SLOT(genBraid()));
	connect(gen, SIGNAL(showStatistics(int)), this, SLOT(showStatistics(int)));

	// Setup solver
	solver = new Solver(maze);
	connect(ui->action_Right_Hand_Rule, SIGNAL(triggered()), this, SLOT(solveRightHandRule()));
	connect(ui->action_Dead_End_Filler, SIGNAL(triggered()), this, SLOT(solveDeadEndFiller()));
	connect(ui->action_Breadth_First, SIGNAL(triggered()), this, SLOT(solveBreadthFirst()));
	connect(ui->action_A_Star, SIGNAL(triggered()), this, SLOT(solveAStar()));
	connect(solver, SIGNAL(showStatistics(int)), this, SLOT(showStatistics(int)));

	// Setup scene
	scene = new QGraphicsScene;
	scene->setBackgroundBrush(QBrush(QColor(210, 105, 30), Qt::SolidPattern)); // Set background color

	// Setup maze canvas
	mc = new MazeCanvas(maze);
	connect(maze, SIGNAL(updateAll()), this, SLOT(updateAll()));
	connect(maze, SIGNAL(updateCell(uint,uint)), mc, SLOT(updateCell(uint,uint))); // Connection which is turned on and off by animation check menu item
	scene->addItem(mc);

	// Setup view
	view = new GraphicsView(scene);
	view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers))); // Enable OpenGL support
	connect(scene, SIGNAL(sceneRectChanged(QRectF)), view, SLOT(zoomReset())); // Auto-reset when scene size changes
	connect(ui->action_Animation, SIGNAL(toggled(bool)), this, SLOT(toggleAnimation(bool)));
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
	{
		maze->setDimensions(rows, columns);
		// Refit the canvas
		scene->setSceneRect(mc->boundingRect()); // Setting the sceneRect is quicker than letting the scene find its own boundaries, and also triggers the signal sceneRectChanged, which activates the auto-zoom from the view
	}
	else
		QMessageBox(QMessageBox::Warning, "Maze Dimensions", "Incorrect maze dimensions").exec();
}

void Gui::toggleAnimation(bool show)
{
	if(show)
		connect(maze, SIGNAL(updateCell(uint,uint)), mc, SLOT(updateCell(uint,uint)));
	else
		disconnect(maze, SIGNAL(updateCell(uint,uint)), mc, SLOT(updateCell(uint,uint)));
}

void Gui::showStatistics(int time)
{
	ui->statusBar->showMessage("Algorithm time: " + QString::number(time) + " msecs"); // QString::number(time)
}

void Gui::updateAll()
{
	mc->updateAll();
}

void Gui::genBackAndForth()
{
	gen->generate(&Generator::backAndForth);
}

void Gui::genPrims()
{
	gen->generate(&Generator::prims);
}

void Gui::genBacktracker()
{
	gen->generate(&Generator::backtracker);
}

void Gui::genBraid()
{
	gen->generate(&Generator::braid);
}

void Gui::solveRightHandRule()
{
	solver->solve(&Solver::rightHandRule);
}

void Gui::solveDeadEndFiller()
{
	solver->solve(&Solver::deadEndFiller);
}

void Gui::solveBreadthFirst()
{
	solver->solve(&Solver::breadthFirst);
}

void Gui::solveAStar()
{
	solver->solve(&Solver::aStar);
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
