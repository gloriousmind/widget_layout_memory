#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QMenu>
#include <QContextMenuEvent>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QWidget *parent = nullptr);
signals:
    void buttontoRemove(MyButton *button);
public:
    QMenu *menu;
    int index_in_QMap = -1;
private:
    void contextMenuEvent(QContextMenuEvent *event);
private slots:
    void removebutton();
};

#endif // MYBUTTON_H
