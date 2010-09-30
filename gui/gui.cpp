#include "gui.h"
#include "ui_gui.h"

Gui::Gui(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Gui)
{
	ui->setupUi(this);
	maze = new QGridLayout(centralWidget());
}

Gui::~Gui()
{
	delete ui;
}

void Gui::setMaze(int height, int width, CellType *mazeArr)
{
	QString name;
	for(int y = 0; y < height; ++y)
	{
		for(int x = 0; x < width; ++x)
		{
			if(mazeArr[y*height+x] == WALL)
				name = "Wall";
			else
				name = "Nothing";
			maze->addWidget(new QLabel(name),y,x);
		}
	}
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
