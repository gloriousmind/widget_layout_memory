#include "mybutton.h"

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
    menu = new QMenu(this);
}

void MyButton::contextMenuEvent(QContextMenuEvent *event)
{
    menu->addAction("删除部件", this, &MyButton::removebutton);
    menu->exec(event->globalPos());
    return;
}

void MyButton::removebutton()
{
    emit buttontoRemove(this);
}
