#include "shapes.h"


Shapes::Shapes(QObject *parent)
{
    pressed=false;
    setFlag(ItemIsMovable);

    Q_UNUSED(parent)


}

Shapes::~Shapes()
{

}

void Shapes::setShapeColor(const QColor &newShapeColor)
{
    ShapeColor = newShapeColor;
}

const QColor &Shapes::getShapeColor() const
{
    return ShapeColor;
}

void Shapes::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pressed=true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Shapes::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed=false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
