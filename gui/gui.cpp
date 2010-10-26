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

	// Setup scene
	scene = new QGraphicsScene;
	mazeContainer = new QGraphicsWidget;
	mazeGrid = new QGraphicsGridLayout;
	mazeGrid->setSpacing(0); // Make the cell spacing nothing
	mazeContainer->setLayout(mazeGrid);
	scene->setBackgroundBrush(QBrush(QColor("chocolate"), Qt::SolidPattern)); // Set background color
	scene->addItem(mazeContainer);

	// Setup view
	view = new GraphicsView(scene);
        view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers))); // Enable OpenGL support
	connect(scene, SIGNAL(sceneRectChanged(QRectF)), view, SLOT(zoomReset())); // Auto-reset when scene size changes
	connect(ui->action_Zoom_In, SIGNAL(triggered()), view, SLOT(zoomIn()));
	connect(ui->action_Zoom_Out, SIGNAL(triggered()), view, SLOT(zoomOut()));
	connect(ui->action_Reset, SIGNAL(triggered()), view, SLOT(zoomReset()));
	connect(ui->action_Dimensions, SIGNAL(triggered()), this, SLOT(setDimensionsDialog()));
	setCentralWidget(view);

	// Setup maze
	maze = new Maze();
	connect(maze, SIGNAL(cellChanged(uint,uint,Maze::CellType,Maze::Facing)), this, SLOT(setCell(uint,uint,Maze::CellType,Maze::Facing)));
	connect(maze, SIGNAL(dimensionsSet(uint,uint)), this, SLOT(setDimensions(uint,uint)));

	// Setup generator
	gen = new Generator(maze);
	connect(ui->action_Back_and_Forth, SIGNAL(triggered()), gen, SLOT(backAndForth()));
	connect(ui->action_Prim_s_Algorithm, SIGNAL(triggered()), gen, SLOT(prims()));

	// Setup solver
	solver = new Solver(maze);
	connect(ui->action_Right_Hand_Rule, SIGNAL(triggered()), solver, SLOT(rightHandRule()));
}

Gui::~Gui()
{
	delete ui;
	delete newMazeUi;
	delete scene;
	delete view;
	delete mazeContainer;
	delete mazeGrid;
	delete maze;
	delete gen;
}

void Gui::setDimensions(unsigned width, unsigned height)
{
	for(unsigned r = 0; r < height; ++r)
		for(unsigned c = 0; c < width; ++c)
			mazeGrid->addItem(new Cell(), r, c, Qt::AlignCenter);
}

void Gui::setCell(unsigned row, unsigned column, Maze::CellType type, Maze::Facing facing)
{
	if(row < (unsigned)mazeGrid->rowCount() && column < (unsigned)mazeGrid->columnCount())
	{
		qDebug() << "setCell(" << row << ',' << column << ',' << type << ',' << facing << ')';
		Cell *cell = (Cell*)mazeGrid->itemAt(row, column);
		cell->setCellType(type);
		cell->setFacing(facing);
	}
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
