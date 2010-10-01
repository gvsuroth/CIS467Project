#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include "cell.h"

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

private:
	Ui::Gui *ui;
	QGridLayout *maze;
};

#endif // MAINWINDOW_H
