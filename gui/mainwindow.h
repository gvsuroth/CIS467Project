#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
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
	Ui::MainWindow *ui;
	QGridLayout *maze;
};

#endif // MAINWINDOW_H
