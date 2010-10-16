#include "gui.h"
#include "ui_gui.h"
#include "cell.h"

Gui::Gui(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Gui)
{
	// Setup gui
	ui->setupUi(this);
	showMaximized(); // Default to maximized

	gridLayout = new QGridLayout(centralWidget());
	scene = new QGraphicsScene;
	view = new QGraphicsView(scene);
	mazeContainer = new QGraphicsWidget;
	mazeGrid = new QGraphicsGridLayout;

	//mazeContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	//mazeGrid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	//mazeGrid->setContentsMargins(0, 0, 0, 0);
	mazeContainer->setLayout(mazeGrid);
	scene->setBackgroundBrush(QBrush(QColor("chocolate"), Qt::SolidPattern)); // Set background color
	scene->addItem(mazeContainer);
	gridLayout->addWidget(view);

	// Generator / maze setup
	maze = new Maze();
	connect(maze, SIGNAL(cellChanged(uint,uint,Maze::CellType)), this, SLOT(setCell(uint,uint,Maze::CellType)));
	connect(maze, SIGNAL(dimensionsSet(uint,uint)), this, SLOT(setDimensions(uint,uint)));
	maze->setDimensions(10, 10);
	gen = new Generator(maze);
	gen->prims();
	//gen->lukes();
}

Gui::~Gui()
{
	delete ui;
	delete gridLayout;
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
			mazeGrid->addItem(new Cell(), r, c);
}

void Gui::setCell(unsigned row, unsigned column, Maze::CellType type)
{
	/*QGraphicsLayoutItem *item = mazeGrid->itemAt(y, x);
	if(item)
		item = new Cell(0, type);
	else*/
	//mazeGrid->addItem(new Cell(0, type), y, x);
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
