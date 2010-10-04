#include "cell.h"

Cell::Cell(QGraphicsItem *parent, Type type)
	: QGraphicsWidget(parent)
{
	img = 0; // If I don't set the pointer to null, sizeHint will fail
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
		break;
	}
	setPreferredSize(70, 70);
	setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	if(!imgName.isNull())
	{
		img = new QGraphicsSvgItem(IMG_PATH+imgName+".svg", this);
		img->scale(preferredWidth() / img->boundingRect().width(), preferredHeight() / img->boundingRect().height());
	}
}

/*QSizeF Cell::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
	return img ? QSizeF(img->boundingRect().size()) : QSizeF();
}*/
