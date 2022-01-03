#ifndef COMMANDS_H
#define COMMANDS_H

#include<QUndoCommand>
#include<QGraphicsScene>
#include<shapes.h>

class AddCommand : public QUndoCommand
{
public:

    AddCommand(Shapes *item, QGraphicsScene *scene,
               QUndoCommand *parent = nullptr);

    ~AddCommand();

    void undo() override;
    void redo() override;

private:
    Shapes *myItem;
    QGraphicsScene *myGraphicsScene;
};

#endif // COMMANDS_H
