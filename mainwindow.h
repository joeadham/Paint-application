#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "square.h"
#include "pen.h"
#include "shapes.h"
#include "circle.h"
#include "line.h"


#include <QMainWindow>
#include <QtGui>
#include <QDialog>
#include <QtCore>
#include <QCompleter>
#include <QGraphicsScene>
#include<QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Shapes *shape;
    Square *square;
    Circle *circle;
    Line *line;
    QPen pen;
    QColor color;



    QString l,w,n;

    QString x1,x2,y1,y2;

    std::vector<std::unique_ptr<Circle>> vcircle;
    std::vector<std::unique_ptr<Square>> vsquare;
    std::vector<std::unique_ptr<Line>> vline;





    void resizeEvent(QResizeEvent *event);


private slots:

    void on_colorButton_clicked();
    void on_squareButton_clicked();
    void on_circleButton_clicked();
    void on_lineButton_clicked();
    void on_searchButton_clicked();

};
#endif // MAINWINDOW_H
