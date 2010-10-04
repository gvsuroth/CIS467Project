#include "gui.h"
#include "ui_gui.h"
#include "generator/generator.h"
#include "cell.h"

Gui::Gui(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Gui)
{
	ui->setupUi(this);
	showMaximized(); // Default to maximized

	gridLayout = new QGridLayout(centralWidget());
	scene = new QGraphicsScene;
	view = new QGraphicsView(scene);
	mazeContainer = new QGraphicsWidget;
	mazeGrid = new QGraphicsGridLayout;

	mazeContainer->setLayout(mazeGrid);
	scene->addItem(mazeContainer);
	gridLayout->addWidget(view);

	gen = new Generator();
	connect(this, SIGNAL(generate(int,int)), gen, SLOT(generate(int,int)));
	connect(gen, SIGNAL(generationDone(int,int,Cell::Type**)), this, SLOT(setMaze(int,int,Cell::Type**)));
	emit generate(8,8);
}

Gui::~Gui()
{
	delete ui;
	delete gridLayout;
	delete scene;
	delete view;
	delete mazeContainer;
	delete mazeGrid;
	delete gen;
}

inline void Gui::setCell(int y, int x, Cell::Type type)
{
	//mazeGrid->addWidget(new Cell(0,type),y,x);
	mazeGrid->addItem(new Cell(0, type), y, x);
	//QGraphicsWidget *widget = new QGraphicsWidget;
	//QGraphicsSvgItem *svg = new QGraphicsSvgItem("gui/img/sprite.svg", widget);
	//mazeGrid->addItem(widget, y, x);
}

void Gui::setMaze(int height, int width, Cell::Type **mazeArr)
{
	QString name;
	for(int y = 0; y < height; ++y)
		for(int x = 0; x < width; ++x)
			setCell(y, x, mazeArr[y][x]);
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
