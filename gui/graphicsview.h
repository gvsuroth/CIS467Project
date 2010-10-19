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
	void zoomIn();
	void zoomOut();
	void zoomReset();
	//void zoomReset();
protected:
	//void resizeEvent(QResizeEvent *event);
	//void showEvent(QShowEvent *event);
	void wheelEvent(QWheelEvent *event);
};

#endif // GRAPHICSVIEW_H
