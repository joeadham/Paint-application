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

    bool pressed;
    QColor ShapeColor;

    const QColor &getShapeColor() const;

    void setShapeColor(const QColor &newShapeColor);
    void setName(QString n);
    QString getName();

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private slots:
//    void itemSelected(QGraphicsItem *item);
//    void textInserted(QGraphicsTextItem *item);
//    void deleteItem();
private:
    QString name;

};

#endif // SHAPES_H
