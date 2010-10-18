#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QDebug>

class GraphicsView : public QGraphicsView
{
Q_OBJECT
public:
	explicit GraphicsView(QGraphicsScene *scene, QWidget *parent = 0);

signals:

public slots:

protected:
	void resizeEvent(QResizeEvent *event);
	//void keyPressEvent(QKeyEvent *event);
	//void keyReleaseEvent(QKeyEvent *event);
	void wheelEvent(QWheelEvent *event);
};

#endif // GRAPHICSVIEW_H
