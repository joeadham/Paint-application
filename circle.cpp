#include "circle.h"


Circle::Circle(QObject *parent)
{

}

Circle::~Circle()
{

}

QRectF Circle::boundingRect() const
{
    return QRectF(0,0,radius,radius);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF ellipse = boundingRect();
    painter->setPen(shapeColor);
    painter->drawEllipse(ellipse);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Circle::setRadius(int newRadius)
{
    radius = newRadius;
}

float Circle::perimeter(){
    return (3.14*2*radius);
}

int Circle::getRadius(){return radius;}
