#include "paintscene.h"
#include "mainwindow.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{
    undoStack = new QUndoStack(this);

}
PaintScene::~PaintScene()
{

}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    temp->setEndPoint(event->scenePos());

    this->update(QRectF(0,0,this->width(), this->height()));
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    temp->setEndPoint(event->scenePos());

    this->update(QRectF(0,0,this->width(), this->height()));


}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    switch (m_typeShape){

    case SquareType: {
        Square *square = new Square(event->scenePos());
        square->setPos(event->pos());
        square->setColor(penColor);
        square->setName(name);
        vshapes.emplace_back(square);
        temp = square;
        QUndoCommand *drawSquare = new AddCommand(temp, this);
        undoStack->push(drawSquare);
        this->update();
        break;
        }
    case CircleType: {
        Circle *circle = new Circle(event->scenePos());
        circle->setPos(event->pos());
        circle->setColor(penColor);
        circle->setName(name);
        vshapes.emplace_back(circle);
        temp = circle;
        QUndoCommand *drawCircle = new AddCommand(temp, this);
        undoStack->push(drawCircle);
        this->update();
        break;
    }
    case LineType:{
        Line *line = new Line(event->scenePos());
        line->setPos(event->pos());
        line->setColor(penColor);
        line->setName(name);
        vshapes.emplace_back(line);
        temp = line;
        QUndoCommand *drawLine = new AddCommand(temp, this);
        undoStack->push(drawLine);
        this->update();
        break;
    }
    }


}

int PaintScene::typeFigure() const
{
    return m_typeShape;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeShape = type;
}

void PaintScene::getShapeName(QString n)
{
   name = n;
}

