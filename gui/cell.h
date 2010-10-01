#ifndef CELL_H
#define CELL_H

#include <QLabel>
#include <QPixmap>

class Cell : public QLabel
{
public:
	enum Type
	{
		PATH,
		WALL,
		SPRITE
	};
	Cell(QWidget *parent = 0, Type type = SPRITE);
};

#endif // CELL_H
