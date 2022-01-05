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

    undoStack = new QUndoStack(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_colorButton_clicked()
{
    color = QColorDialog::getColor(Qt::black);

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

}


void MainWindow::on_squareButton_clicked()
{
    square = new Square();
    l=ui->sqLength->text();
    w=ui->sqWidth->text();
    n=ui->squareName->text();

    square->setLength(l.toInt());
    square->setWidth(w.toInt());
    square->setName(n);
    square->setColor(color);

    vsquare.emplace_back(square);

    QUndoCommand *addCommand = new AddCommand(square, scene);
    undoStack->push(addCommand);

}


void MainWindow::on_circleButton_clicked()
{
    circle = new Circle();

    l=ui->radius->text();
    n=ui->circleName->text();

    circle->setRadius(l.toInt());
    circle->setName(n);
    circle->setColor(color);


    vcircle.emplace_back(circle);

    QUndoCommand *addCommand = new AddCommand(circle, scene);
    undoStack->push(addCommand);

}

void MainWindow::on_lineButton_clicked()
{
    line = new Line();

    n=ui->lineName->text();

    x1=ui->x1->text();
    x2=ui->x2->text();
    y1=ui->y1->text();
    y2=ui->y2->text();

    line->x1 =(x1.toInt());
    line->x2 =(x2.toInt());
    line->y1 =(y1.toInt());
    line->y2 =(y2.toInt());
    line->setName(n);
    line->setColor(color);

    vline.emplace_back(line);

    QUndoCommand *addCommand = new AddCommand(line, scene);
    undoStack->push(addCommand);
}


void MainWindow::on_searchButton_clicked()
{
     n=ui->searchName->text();
     bool exist=false;


   for(int i=0; i<(int)(vcircle.size());i++){
       if(n==vcircle[i]->getName())
       {
           ui->infoname->setText(vcircle[i]->getName());
           ui->infoper->setText(QString::number(vcircle[i]->perimeter()));
           ui->infoColor->setText(vcircle[i]->getColor().name());
           exist=true;
       }

   }
   for(int i=0; i<(int)(vsquare.size());i++){
       if(n==vsquare[i]->getName())
       {
           ui->infoname->setText(vsquare[i]->getName());
           ui->infoper->setText(QString::number(vsquare[i]->perimeter()));
           ui->infoColor->setText(vsquare[i]->getColor().name(QColor::HexArgb));
           exist=true;
       }
   }
   for(int i=0; i<(int)(vline.size());i++){
       if(n==vline[i]->getName())
       {
           ui->infoname->setText(vline[i]->getName());
           ui->infoper->setText(QString::number(vline[i]->getLineLength()));
           ui->infoColor->setText(vline[i]->getColor().name());
           exist=true;
       }

   }

   if(!exist)
   {
      QMessageBox::about(this,"Shape","Doesn't exit");
   }

}



void MainWindow::on_redoButton_clicked()
{
    undoStack->redo();
}


void MainWindow::on_undoButton_clicked()
{
    undoStack->undo();
}


void MainWindow::saveAsBitmap() {
    saveDrawing("png");
}
void MainWindow::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
           return;

       // Create a new image to display and fill it with white
       QImage newImage(newSize, QImage::Format_RGB32);
newImage.fill(qRgb(255, 255, 255));

       // Draw the image
       QPainter painter(&newImage);
       painter.drawImage(QPoint(0, 0), *image);
       *image = newImage;
}
bool MainWindow::saveImage(const QString &filename, const char *fileformat)
{


        const QPixmap pixmap = ui->graphicsView->grab();
        const QString fileName("/home/pw/image.png");
        qDebug() << pixmap.save(fileName);

        if (pixmap.save(filename, fileformat)) {
           changed = false;
           return true;
        } else {
            return false;
        }
        // QImage visibleImage = image;
         //resizeImage(scene, size());

         //if (visibleImage.save(filename, fileformat)) {
           //  changed = false;
           //  return true;
       //  } else {
           //  return false;
        // }

}

bool MainWindow::saveDrawing(const QByteArray &fileFormat) {
    QString currentPath = QDir::currentPath() + "/painter." + fileFormat;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), currentPath,
              tr("%1 Files (*.%2;;All Files (*)").arg(QString::fromLatin1(fileFormat.toUpper()))
                                                  .arg(QString::fromLatin1(fileFormat)));

    if (fileName.isEmpty()) {
        return false;
    }else {
        return saveImage(fileName, fileFormat.constData());
    }
}

bool MainWindow::trySave() {
    // check for unsaved changes when we click at X button to close the paint
    if (isChanged()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Painter"),
                         tr("Your drawing has been modified.\n"
                            "Would you like to save your changes?"),
                         QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
       if (ret == QMessageBox::Save) {
           return saveDrawing("png");
       }
       else if (ret == QMessageBox::Cancel) {
           return false;
       }
    }
    return true;
}











void MainWindow::on_SaveButton_clicked()
{
  saveAsBitmap();
}
void MainWindow::closeEvent (QCloseEvent *event)
{
    trySave();
}
