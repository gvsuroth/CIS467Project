#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->setWindowTitle("Maze Solver");
	maze = new QGridLayout(centralWidget());
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::setMaze(int height, int width, CellType *mazeArr)
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

void MainWindow::changeEvent(QEvent *e)
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
