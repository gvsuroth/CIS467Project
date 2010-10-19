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
	//mazeGrid->setContentsMargins(0, 0, 0, 0);
	mazeGrid->setSpacing(0); // Make the cell spacing nothing
	mazeContainer->setLayout(mazeGrid);
	scene->setBackgroundBrush(QBrush(QColor("chocolate"), Qt::SolidPattern)); // Set background color
	scene->addItem(mazeContainer);

	// Setup view
	view = new GraphicsView(scene);
	//view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers))); // Enable OpenGL support
	connect(scene, SIGNAL(sceneRectChanged(QRectF)), view, SLOT(zoomReset())); // Auto-reset when scene size changes
	connect(ui->action_Zoom_In, SIGNAL(activated()), view, SLOT(zoomIn()));
	connect(ui->action_Zoom_Out, SIGNAL(activated()), view, SLOT(zoomOut()));
	connect(ui->action_Reset, SIGNAL(activated()), view, SLOT(zoomReset()));
	connect(ui->action_New, SIGNAL(activated()), this, SLOT(showNewMazeDialog()));
	setCentralWidget(view);

	// Setup maze
	maze = new Maze();
	connect(maze, SIGNAL(cellChanged(uint,uint,Maze::CellType)), this, SLOT(setCell(uint,uint,Maze::CellType)));
	connect(maze, SIGNAL(dimensionsSet(uint,uint)), this, SLOT(setDimensions(uint,uint)));

	// Setup generator
	gen = new Generator(maze);
	connect(ui->action_Prims, SIGNAL(activated()), gen, SLOT(prims()));
	// Temp stuff (this will be done by menus later)
	//gen = new Generator(maze);
	//maze->setDimensions(20, 20);
	//gen->prims();
	//gen->lukes();
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

void Gui::setCell(unsigned row, unsigned column, Maze::CellType type)
{
	if(row < (unsigned)mazeGrid->rowCount() && column < (unsigned)mazeGrid->columnCount())
		((Cell*)mazeGrid->itemAt(row, column))->setCellType(type);
}

void Gui::showNewMazeDialog()
{
	QDialog newMazeDialog(this);
	newMazeUi->setupUi(&newMazeDialog);
	connect(newMazeUi->buttonBox, SIGNAL(accepted()), this, SLOT(setNewMazeDimensions()));
	//qDebug() << "showNewMazeDialog";
	//newMazeDialog->show();
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
		qDebug() << "You suck.";
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
