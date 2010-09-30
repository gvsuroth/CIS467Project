#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>

namespace Ui {
	class Gui;
}

class Gui : public QMainWindow {
	Q_OBJECT
public:
	Gui(QWidget *parent = 0);
	~Gui();
	enum CellType
	{
		NOTHING,
		WALL,
		MOUSE,
		START,
		END
	};
	void setMaze(int height, int width, CellType *mazeArr);

protected:
	void changeEvent(QEvent *e);

private:
	Ui::Gui *ui;
	QGridLayout *maze;
};

#endif // MAINWINDOW_H
