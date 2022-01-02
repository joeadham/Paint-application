#include "square.h"

Square::Square(QObject *parent)
{
}

Square::~Square()
{

}

QRectF Square::boundingRect() const
{
    return QRectF(0,0,length,width);
}


void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(getShapeColor());


    painter->fillRect(rec,brush);
    painter->drawRect(rec);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Square::setLength(int newLength)
{
 length = newLength;
}

void Square::setWidth(int newWidth)
{
 width = newWidth;
}
float Square::perimeter(){
    return ((length+width)*2);
}
