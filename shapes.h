#ifndef SHAPES_H
#define SHAPES_H

#include "pen.h"
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class Shapes : public QObject , public QGraphicsItem
{

    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Shapes(QObject *parent = 0);
    ~Shapes();



    const QColor &getColor() const;
    void setColor(const QColor &newColor);

    void setName(QString n);
    QString getName();
    float perimeter();
    void setS(float m);

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QColor shapeColor = Qt::black;
    QPen pen;
    bool pressed;


private slots:
//    void itemSelected(QGraphicsItem *item);
//    void textInserted(QGraphicsTextItem *item);
//    void deleteItem();

private:
    QString name;
    float s;

};

#endif // SHAPES_H
