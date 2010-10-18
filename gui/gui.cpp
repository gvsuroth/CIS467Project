#include "gui.h"
#include "ui_gui.h"
#include "cell.h"

Gui::Gui(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Gui)
{
	// Setup gui
	ui->setupUi(this);

	scene = new QGraphicsScene;
	view = new GraphicsView(scene);
	connect(ui->actionZoom_In, SIGNAL(activated()), view, SLOT(zoomIn()));
	connect(ui->actionZoom_Out, SIGNAL(activated()), view, SLOT(zoomOut()));
	connect(ui->action_Reset, SIGNAL(activated()), view, SLOT(zoomReset()));
	//view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers))); // Enable OpenGL support
	mazeContainer = new QGraphicsWidget;
	mazeGrid = new QGraphicsGridLayout;

	//mazeGrid->setContentsMargins(0, 0, 0, 0);
	mazeGrid->setSpacing(0); // Make the cell spacing nothing

	mazeContainer->setLayout(mazeGrid);
	scene->setBackgroundBrush(QBrush(QColor("chocolate"), Qt::SolidPattern)); // Set background color
	scene->addItem(mazeContainer);
	setCentralWidget(view);

	// Generator / maze setup
	maze = new Maze();
	connect(maze, SIGNAL(cellChanged(uint,uint,Maze::CellType)), this, SLOT(setCell(uint,uint,Maze::CellType)));
	connect(maze, SIGNAL(dimensionsSet(uint,uint)), this, SLOT(setDimensions(uint,uint)));
	//maze->setDimensions(5, 5);
	maze->setDimensions(10, 10);
	gen = new Generator(maze);
	gen->prims();
	//gen->lukes();
}

Gui::~Gui()
{
	delete ui;
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
	((Cell*)mazeGrid->itemAt(row, column))->setCellType(type);
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
