//按钮样式yyou hua优化 - 流程llian xi练习

#include "mybutton.h"

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
    menu = new QMenu(this);
}

void MyButton::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();
    menu->addAction("删除部件", this, &MyButton::removebutton);
    menu->exec(event->globalPos());
    return;
}

void MyButton::removebutton()
{
    emit buttontoRemove(this);
}
