#ifndef LINE_H
#define LINE_H
#include "shapes.h"

#include <QWidget>
#include <QtCore>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsLineItem>
#include <QPainter>

#include <QDebug>
#include <QLine>

class Line : public Shapes
{

public:

    Line(QObject *parent = 0);
    ~Line();

    QLineF setLine() const;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    float getLineLength() const;
    void setLineLength();


    QPoint getP1() const;
    void setP1(QPoint newP1);

    QPoint getP2() const;
    void setP2(QPoint newP2);

    int x1;
    int x2;
    int y1;
    int y2;


private:
    float lineLength;

    QPoint p1;
    QPoint p2;

};

#endif // LINE_H
