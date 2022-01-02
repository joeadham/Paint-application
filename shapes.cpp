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

const QColor &Shapes::getColor() const
{
    return shapeColor;
}

void Shapes::setColor(const QColor &newColor)
{
    shapeColor = newColor;
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

void Shapes:: setName(QString n){
    name=n;
}

QString Shapes::getName(){
    return name;
}
