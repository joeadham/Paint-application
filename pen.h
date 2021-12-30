#ifndef PEN_H
#define PEN_H
#include <QtGui>
#include <QtCore>
#include <QCompleter>
#include <QGraphicsScene>
#include <QWidget>

class Pen : public QWidget
{
    Q_OBJECT
public:
    Pen(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);

    void drawLineTo(const QPoint &endPoint);
    void setPenWidth(int newWidth);
    void setPenColor(const QColor &newColor);
    bool isModified() const { return modified; }
    QColor penColor() const { return PenColor; }
       int penWidth() const { return PenWidth; }

private:
    bool scribbling;
    int PenWidth;
    QColor PenColor;
    QPoint lastPoint;
    QPoint endPoint;
    QImage image;
    bool modified;

protected:
    void mousePressEvent(QMouseEvent *event) ;
    void mouseMoveEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event) ;


};

#endif // PEN_H
