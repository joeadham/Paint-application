#include "pen.h"
#include <QWidget>
#include <QList>

Pen::Pen(QWidget *parent) : QWidget(parent)
{
    scribbling = false;
    PenWidth = 1;
    PenColor = Qt::blue;
}

void Pen::setPenWidth(int newWidth){
    PenWidth = newWidth;
}

void Pen::setPenColor(const QColor &newColor)
{
    PenColor = newColor;
}
void Pen::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        scribbling = true;
    }
}

void Pen::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling)
        drawLineTo(event->pos());
}


void Pen::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
        drawLineTo(event->pos());
        scribbling = false;
    }
}

void Pen::paintEvent(QPaintEvent *event)
{
        QPainter painter(this);

        // Returns the rectangle that needs to be updated
        QRect dirtyRect = event->rect();

        // Draws the rectangle where the image needs to
        // be updated
        painter.drawImage(dirtyRect, image, dirtyRect);

}

void Pen::drawLineTo(const QPoint &endPoint)
{
    // Used to draw on the widget
    QPainter painter(&image);

    // Set the current settings for the pen
    painter.setPen(QPen(PenColor, PenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    // Draw a line from the last registered point to the current
    painter.drawLine(lastPoint, endPoint);

    // Set that the image hasn't been saved
    modified = true;

    int rad = (PenWidth / 2) + 2;

    // Call to update the rectangular space where we drew
    update(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));

    // Update the last position where we left off drawing
    lastPoint = endPoint;
}
