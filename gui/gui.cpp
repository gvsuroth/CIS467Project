#include "gui.h"
#include "ui_gui.h"
#include "cell.h"

Gui::Gui(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Gui)
{
	// Setup gui
	ui->setupUi(this);

	//gridLayout = new QGridLayout(centralWidget());
	scene = new QGraphicsScene;
	view = new GraphicsView(scene);
	//view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers))); // Enable OpenGL support
	mazeContainer = new QGraphicsWidget;
	mazeGrid = new QGraphicsGridLayout;

	//mazeGrid->setContentsMargins(0, 0, 0, 0);
	mazeGrid->setSpacing(0); // Make the cell spacing nothing
	//centralWidget()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	//view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	//mazeContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	//mazeGrid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	mazeContainer->setLayout(mazeGrid);
	scene->setBackgroundBrush(QBrush(QColor("chocolate"), Qt::SolidPattern)); // Set background color
	scene->addItem(mazeContainer);
	//gridLayout->addWidget(view);
	setCentralWidget(view);

	// Generator / maze setup
	maze = new Maze();
	connect(maze, SIGNAL(cellChanged(uint,uint,Maze::CellType)), this, SLOT(setCell(uint,uint,Maze::CellType)));
	connect(maze, SIGNAL(dimensionsSet(uint,uint)), this, SLOT(setDimensions(uint,uint)));
	qDebug() << scene->width() << scene->height() << scene->sceneRect() << scene->itemsBoundingRect();
	//maze->setDimensions(5, 5);
	maze->setDimensions(20, 20);
	gen = new Generator(maze);
	gen->prims();
	//gen->lukes();
	//qDebug() << view->width() << mazeContainer->geometry().width();
	//view->scale(view->width() / scene->sceneRect().width(), view->height() / scene->sceneRect().height());
	//view->scale(scene->sceneRect().width() / view->width(), view->height() / scene->sceneRect().height());
	//view->scale(view->width() / mazeContainer->preferredWidth(), view->height() / mazeContainer->preferredHeight());
	//view->setSceneRect(0, 0, view->width(), view->height());
	//view->resize(scene->itemsBoundingRect().size().toSize());
	//view->resize(500, 500);
	//qDebug() << view->sceneRect();
	//qDebug() << scene->width() << scene->height() << scene->sceneRect() << scene->itemsBoundingRect();
	//qDebug() << "here";
	//view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
	//qDebug() << "finished";
}

Gui::~Gui()
{
	delete ui;
	//delete gridLayout;
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
