#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    main_layout = new QVBoxLayout(this);
    buttons_area = new QScrollArea(this);
    fixed_button_layout = new QHBoxLayout();
    main_layout->addWidget(buttons_area);
    main_layout->addLayout(fixed_button_layout);

    scroll_content = new QWidget();
    scroll_content_layout = new QGridLayout(scroll_content);

    buttons_area->setWidget(scroll_content);
    buttons_area->setWidgetResizable(true);

    addWidget_button = new MyButton(this);
    addWidget_button->setText("添加控件");
    removeWidget_button = new MyButton(this);
    removeWidget_button->setText("删除部件");
    removeAll_button = new MyButton(this);
    removeAll_button->setText("全部删除");
    fixed_button_layout->addWidget(addWidget_button);
    fixed_button_layout->addWidget(removeWidget_button);
    fixed_button_layout->addWidget(removeAll_button);

    connect(addWidget_button, &MyButton::clicked, this, &MyWidget::addWidget);
    connect(removeWidget_button, &MyButton::clicked, this, &MyWidget::removeWidget);
    connect(removeAll_button, &MyButton::clicked, this, &MyWidget::removeAllWidget);
}

void MyWidget::addWidget()
{
    MyButton *newbutton = new MyButton();
    scroll_content_layout->addWidget(newbutton, grid_next_row, grid_next_column);
    if (grid_next_column + 1 == grid_column_num)
    {
        grid_next_column = 0;
        grid_next_row++;
    }
    else
        grid_next_column++;
    connect(newbutton, &MyButton::buttontoRemove, this, &MyWidget::removeChosenWidget);
    newbutton->setText(QString("button%1").arg(label_index));
    label_index++;
    int map_index = index_buttons.size();
    index_buttons[map_index] = newbutton;
    newbutton->index_in_QMap = map_index;
    newbutton->show();
}

void MyWidget::removeWidget()
{
    if (index_buttons.empty())
    {
        QMessageBox::warning(this, "警告", QString("没有更多部件移除"));
        return;
    }
    int largest_map_index = index_buttons.lastKey();
    MyButton *removebutton = index_buttons[largest_map_index];
    index_buttons.remove(largest_map_index);
    delete removebutton;
    return;
}

void MyWidget::removeChosenWidget(MyButton *button)
{
    if (index_buttons.empty())
    {
        QMessageBox::warning(this, "警告", QString("没有更多部件移除"));
        return;
    }
    int remove_index = button->index_in_QMap;
    index_buttons.remove(remove_index);
    delete button;
}

void MyWidget::removeAllWidget()
{
    if (index_buttons.empty())
    {
        QMessageBox::warning(this, "警告", QString("没有更多部件移除"));
        return;
    }
    for (auto c = index_buttons.begin(); c != index_buttons.end(); c++)
        delete c.value();
    index_buttons.clear();
}

MyWidget::~MyWidget()
{
    delete ui;
}
