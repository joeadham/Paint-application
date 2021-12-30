#include "circle.h"


Circle::Circle(QObject *parent)
{

}

Circle::~Circle()
{

}

QRectF Circle::boundingRect() const
{
    return QRectF(0,0,radiusx,radiusy);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF ellipse= boundingRect();
    QBrush brush(getShapeColor());

    painter->drawEllipse(ellipse);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Circle::setRadiusx(int newRadiusx)
{
    radiusx = newRadiusx;
}

void Circle::setRadiusy(int newRadiusy)
{
    radiusy = newRadiusy;
}
