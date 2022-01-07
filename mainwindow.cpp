#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sortlist.h"

#include <algorithm>
#include <QtAlgorithms>
#include <QtWidgets>
#include <QList>
#include <QResizeEvent>
#include <QDebug>
#include <QVector>

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

    bool exist=false;
    square = new Square();
    l=ui->sqLength->text();
    w=ui->sqWidth->text();
    n=ui->squareName->text();

    if(l==""||n==""||w==""){
        QMessageBox::about(this,"Paint","Please fill all shape information");



    }
else{

    if(vshapes.size()==0){

    square->setLength(l.toInt());
    square->setWidth(w.toInt());
    square->setName(n);
    square->setColor(color);
    square->setS((l.toInt()+w.toInt())*2);

    vshapes.emplace_back(square);

    QUndoCommand *addCommand = new AddCommand(square, scene);
    undoStack->push(addCommand);}


    else{

    for(int i=0; i<(int)( vshapes.size());i++){

        if(n==vshapes[i]->getName())
        {exist=true;}}
    if(exist)
        {
            QMessageBox::about(this,"Name","this name is already exist...try different name");


        }
    else{
        square->setLength(l.toInt());
        square->setWidth(w.toInt());
        square->setName(n);
        square->setColor(color);
        square->setS((l.toInt()+w.toInt())*2);

        vshapes.emplace_back(square);

        QUndoCommand *addCommand = new AddCommand(square, scene);
        undoStack->push(addCommand);
    }


}
}}


void MainWindow::on_circleButton_clicked()
{

    bool exist=false;
    circle = new Circle();

    l=ui->radius->text();
    n=ui->circleName->text();

    if(l==""||n==""){
        QMessageBox::about(this,"Paint","Please fill all shape information");



    }
else{

    if(vshapes.size()==0){
        circle->setRadius(l.toInt());
        circle->setS(3.14*2*l.toFloat());
        circle->setName(n);
        circle->setColor(color);



         vshapes.emplace_back(circle);

        QUndoCommand *addCommand = new AddCommand(circle, scene);
        undoStack->push(addCommand);}

    else{

    for(int i=0; i<(int)( vshapes.size());i++){

        if(n==vshapes[i]->getName())
        {exist=true;}}

    if(exist)
        {
            QMessageBox::about(this,"Name","this name is already exist...try different name");


        }

    else{
    circle->setRadius(l.toInt());
    circle->setS(3.14*2*l.toFloat());
    circle->setName(n);
    circle->setColor(color);



     vshapes.emplace_back(circle);

    QUndoCommand *addCommand = new AddCommand(circle, scene);
    undoStack->push(addCommand);}}



}
}

void MainWindow::on_lineButton_clicked()
{
     bool exist=false;

    line = new Line();

    n=ui->lineName->text();

    x1=ui->x1->text();
    x2=ui->x2->text();
    y1=ui->y1->text();
    y2=ui->y2->text();
    if(x1==""||n==""||x2==""||y1==""||y2==""){
        QMessageBox::about(this,"Paint","Please fill all shape information");



    }
else{
if(vshapes.size()==0){
    line->x1 =(x1.toInt());
    line->x2 =(x2.toInt());
    line->y1 =(y1.toInt());
    line->y2 =(y2.toInt());
    line->setName(n);
    line->setColor(color);
    line->setLineLength();
    line->setS(line->getLineLength());

     vshapes.emplace_back(line);

    QUndoCommand *addCommand = new AddCommand(line, scene);
    undoStack->push(addCommand);}

else{

for(int i=0; i<(int)( vshapes.size());i++){

    if(n==vshapes[i]->getName())
    {exist=true;}}

if(exist)
    {
        QMessageBox::about(this,"Name","this name is already exist...try different name");


    }

else{    line->x1 =(x1.toInt());
    line->x2 =(x2.toInt());
    line->y1 =(y1.toInt());
    line->y2 =(y2.toInt());
    line->setName(n);
    line->setColor(color);
    line->setLineLength();
    line->setS(line->getLineLength());

     vshapes.emplace_back(line);

    QUndoCommand *addCommand = new AddCommand(line, scene);
    undoStack->push(addCommand);}





}}}


void MainWindow::on_searchButton_clicked()
{
     n=ui->searchName->text();


     if(n==""){
         QMessageBox::about(this,"Paint","Please enter tha shape name");
     }
     else{

     bool exist=false;


   for(int i=0; i<(int)( vshapes.size());i++){
       if(n==vshapes[i]->getName())
       {
           ui->infoname->setText(vshapes[i]->getName());
           ui->infoper->setText(QString::number(vshapes[i]->perimeter()));
           ui->infoColor->setText(vshapes[i]->getColor().name());
           exist=true;
       }

   }


   if(!exist)
   {
      QMessageBox::about(this,"Shape","Doesn't exit");
   }

}
}


void MainWindow::on_redoButton_clicked()
{
    if (vundo.size()!=0){
    vshapes.emplace_back(vundo[vundo.size()-1]);
    vundo.pop_back();}

    undoStack->redo();
}


void MainWindow::on_undoButton_clicked()
{
    if(vshapes.size()==0)
    {
       QMessageBox::about(this,"Paint","No shapes");
    }
else{
    vundo.emplace_back(vshapes[vshapes.size()-1]);
    vshapes.pop_back();


    undoStack->undo();}

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

void MainWindow::on_sortAsButton_clicked()
{
    if ((int)(vshapes.size())==0){
         QMessageBox::about(this,"Paint","No shapes found");
    }
    else {
        SORTLIST AS;
        AS.tabledisplay((int)(vshapes.size()));


       for(int i=0 ; i<(int)(vshapes.size()) ; i++){
          objects.emplace_back(vshapes[i]->perimeter());
       }

       std::sort(objects.begin(),objects.end());

         for(int j=0; j<(int)(objects.size());j++){
             for(int i=0; i<(int)(vshapes.size());i++){

               if (objects[j] == vshapes[i]->perimeter()){
                   AS.info(j, vshapes[i]->getName(), vshapes[i]->perimeter() , vshapes[i]->getColor().name() );
                 }


   }
}

         AS.setModal(true);
         AS.exec();
    }
    objects.clear();
}


void MainWindow::on_sortDsButton_clicked()
{
    if ((int)(vshapes.size())==0){
         QMessageBox::about(this,"Paint","No shapes found");
    }
    else {
          SORTLIST DS;
          DS.tabledisplay((int)(vshapes.size()));

       for(int i=0 ; i<(int)(vshapes.size()) ; i++){
          objects.emplace_back(vshapes[i]->perimeter());
       }

       std::sort(objects.rbegin(),objects.rend());

         for(int j=0 ; j<(int)(objects.size()) ; j++){
             for(int i=0; i<(int)(vshapes.size());i++){

               if (objects[j] == vshapes[i]->perimeter()){
                    DS.info(j, vshapes[i]->getName(),vshapes[i]->perimeter() , vshapes[i]->getColor().name() );
                 }
              }
        }
          DS.setModal(true);
          DS.exec();
    }
    objects.clear();
}


