#include "circle.h"


Circle::Circle(QPointF point,QObject *parent): Shapes(point,parent)
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
    double r = sqrt(pow(startPoint().x() - endPoint().x(), 2) + pow(startPoint().y() - endPoint().y(), 2));
    double d;
    int x, y;

    x=0; y=r; d=1.25-r;
    painter->setPen(shapeColor);

    while (x <= y)
            {
              painter->drawPoint(startPoint().x() + x, startPoint().y() + y);
              painter->drawPoint(startPoint().x() - x, startPoint().y() + y);
              painter->drawPoint(startPoint().x() + x, startPoint().y() - y);
              painter->drawPoint(startPoint().x() - x, startPoint().y() - y);
              painter->drawPoint(startPoint().x() + y, startPoint().y() + x);
              painter->drawPoint(startPoint().x() - y, startPoint().y() + x);
              painter->drawPoint(startPoint().x() + y, startPoint().y() - x);
              painter->drawPoint(startPoint().x() - y, startPoint().y() - x);
                x++;
                if (d < 0)
                {
                    d += 2 * x + 3;
                }
                else
                {
                    y--;
                    d += 2 * (x - y) + 5;
                }
    }

    setS(2*3.14*r);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Circle::setRadius(int newRadius)
{
    radius = newRadius;
}



int Circle::getRadius(){return radius;}
