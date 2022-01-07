#include "line.h"
#include <cmath>
Line::Line(QObject *parent)
{

}

Line::~Line()
{

}

QRectF Line::boundingRect() const
{
    return QRectF(x1,y1,x2,y2);
}

QLineF Line::setLine() const
{
    return QLineF(x1,y1,x2,y2);
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLineF line = setLine();

    painter->setPen(shapeColor);
    painter->drawLine(line);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

float Line::getLineLength() const
{
    return lineLength;
}

void Line::setLineLength()
{
    lineLength =sqrt(pow((x1-x2),2)-pow((y1-y2),2));
}

QPoint Line::getP1() const
{
    return p1;
}

void Line::setP1(QPoint newP1)
{
    p1 = newP1;
    p1.setX(x1);
    p1.setY(y1);
}

QPoint Line::getP2() const
{
    return p2;
}

void Line::setP2(QPoint newP2)
{
    p2 = newP2;
    p2.setX(x2);
    p2.setY(y2);
}


