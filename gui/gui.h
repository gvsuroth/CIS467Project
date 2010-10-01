#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>

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
	void setMaze(int height, int width, Cell::Type *mazeArr);

protected:
	void changeEvent(QEvent *e);

signals:
	void generate(int height, int width); // Temp function

public slots:
	void generationDone(int height, int width, Cell::Type *maze);

private:
	Ui::Gui *ui;
	QGridLayout *maze;
	Generator *gen;
};

#endif // MAINWINDOW_H
