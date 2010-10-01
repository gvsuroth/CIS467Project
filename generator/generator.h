#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>

#include "gui/cell.h"

class Generator : public QObject
{
Q_OBJECT
public:
	explicit Generator(QObject *parent = 0);

signals:
	void generationDone(int height, int width, Cell::Type *maze);

public slots:
	void generate(int height, int width);

};

#endif // GENERATOR_H
