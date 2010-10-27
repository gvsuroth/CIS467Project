#include <QtGui/QApplication>
#include "gui.h"

int main(int argc, char *argv[])
{
	QApplication::setOrganizationName("GVSU_CIS467");
	QApplication::setOrganizationDomain("maze-solver.cis.gvsu.edu");
	QApplication::setApplicationName("Maze Solver");
	QApplication a(argc, argv);
	Gui gui;
	gui.showMaximized();
	return a.exec();
}
