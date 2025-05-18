#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mybutton.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QScrollArea>
#include "mybutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MyWidget;
}
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    Ui::MyWidget *ui;

    QVBoxLayout *main_layout;
    QHBoxLayout *fixed_button_layout;
    QScrollArea *buttons_area;
    QWidget *scroll_content;
    QGridLayout *scroll_content_layout;
    int grid_next_row = 0;
    int grid_next_column = 0;
    int grid_column_num = 10;

    MyButton *addWidget_button;
    MyButton *removeWidget_button;
    MyButton *removeAll_button;

    QMap<int, MyButton*> index_buttons;
    int label_index = 0;

private slots:
    void addWidget();
    void removeWidget();
    void removeChosenWidget(MyButton *button);
    void removeAllWidget();
};
#endif // MYWIDGET_H
