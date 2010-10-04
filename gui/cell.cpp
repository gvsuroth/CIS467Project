#include "cell.h"

Cell::Cell(QWidget *parent, Type type)
	: QLabel(parent)
{
	QString imgName;
	switch(type)
	{
	case WALL:
		imgName = "wall";
		break;
	case SPRITE:
		imgName = "sprite";
		break;
	case PATH:
	default:
		imgName = "path";
		break;
	}
	setPixmap(QPixmap("gui/img/"+imgName+".png"));
}
