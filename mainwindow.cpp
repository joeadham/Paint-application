#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QtWidgets>
#include <QList>
#include <QResizeEvent>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);



}

MainWindow::~MainWindow()
{
    delete ui;
}



//void MainWindow::on_colorButton_clicked()
//{
//    QColor color = QColorDialog::getColor();
//    if(color.isValid())
//    {
//        sq->setShapeColor(color);
//        circle->setShapeColor(color);
//    }

//}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

}


void MainWindow::on_squareButton_clicked()
{
    sq = new Square();
    l=ui->sqLength->text();
    w=ui->sqWidth->text();

    sq->setLength(l.toInt());
    sq->setWidth(w.toInt());

    scene->addItem(sq);


}


void MainWindow::on_circleButton_clicked()
{
    circle= new Circle();
    l=ui->radiusX->text();
    w=ui->radiusY->text();

    circle->setRadiusx(l.toInt());
    circle->setRadiusy(w.toInt());

    scene->addItem(circle);
}


void MainWindow::on_lineButton_clicked()
{
    line = new Line();

    QPen myPen (Qt::green);
    myPen.setWidth(10);

    x1=ui->x1->text();
    x2=ui->x2->text();
    y1=ui->y1->text();
    y2=ui->y2->text();

    line->x1 =(x1.toInt());
    line->x2 =(x2.toInt());
    line->y1 =(y1.toInt());
    line->y2 =(y2.toInt());

    scene->addLine(line->setLine(),myPen);
}

