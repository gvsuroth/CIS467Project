#include "gui.h"
#include "ui_gui.h"
#include "generator/generator.h"

Gui::Gui(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Gui)
{
	ui->setupUi(this);
	maze = new QGridLayout(centralWidget());
	gen = new Generator();
	connect(this, SIGNAL(generate(int,int)), gen, SLOT(generate(int,int)));
	connect(gen, SIGNAL(generationDone(int,int,Cell::Type**)), this, SLOT(generationDone(int,int,Cell::Type**)));
	emit generate(8,8);
}

Gui::~Gui()
{
	delete ui;
	delete maze;
	delete gen;
}

inline void Gui::setCell(int y, int x, Cell::Type type)
{
	maze->addWidget(new Cell(0,type),y,x);
}

void Gui::setMaze(int height, int width, Cell::Type **mazeArr)
{
	QString name;
	for(int y = 0; y < height; ++y)
		for(int x = 0; x < width; ++x)
			setCell(y, x, mazeArr[y][x]);
}

void Gui::generationDone(int height, int width, Cell::Type **maze)
{
	setMaze(height, width, maze);
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
