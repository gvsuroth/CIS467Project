#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSizePolicy>
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>
#include <QGraphicsSvgItem>

#include <QDebug>

#include "cell.h"
#include "generator/generator.h"

namespace Ui {
	class Gui;
}

class Gui : public QMainWindow {
	Q_OBJECT
public:
	Gui(QWidget *parent = 0);
	~Gui();
	inline void setCell(int y, int x, Cell::Type type);

protected:
	void changeEvent(QEvent *e);
	Ui::Gui *ui;
	QGridLayout *gridLayout;
	QGraphicsScene *scene;
	QGraphicsView *view;
	QGraphicsWidget *mazeContainer;
	QGraphicsGridLayout *mazeGrid;
	Generator *gen;

signals:
	void generate(int height, int width); // Temp function

public slots:
	void setMaze(int height, int width, Cell::Type **mazeArr);
};

#endif // MAINWINDOW_H
