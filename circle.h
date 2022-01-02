#ifndef CIRCLE_H
#define CIRCLE_H

#include "shapes.h"
#include "pen.h"


#include "QWidget"
#include "QStyleOptionGraphicsItem"
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class Circle : public Shapes
{


public:

    Circle(QObject *parent = 0);
    ~Circle();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    void setRadius(int newRadius);
    float perimeter();
    int getRadius();



private:
    int radius;

};

#endif // CIRCLE_H
