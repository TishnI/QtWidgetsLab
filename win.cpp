#include "win.h"

Win::Win(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Счетчик");
    label1 = new QLabel("Счет по 1", this);
    label2 = new QLabel("Счет по 5", this);
    edit1 = new Counter("0", this);
    edit2 = new Counter("0", this);
    calcButton = new QPushButton("+1", this);
    exitButton = new QPushButton("Выход", this);

    QHBoxLayout *labelLayout = new QHBoxLayout();
    labelLayout->addWidget(label1);
    labelLayout->addWidget(label2);

    QHBoxLayout *editLayout = new QHBoxLayout();
    editLayout->addWidget(edit1);
    editLayout->addWidget(edit2);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(calcButton);
    buttonLayout->addWidget(exitButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(labelLayout);
    mainLayout->addLayout(editLayout);
    mainLayout->addLayout(buttonLayout);

    connect(calcButton, SIGNAL(clicked(bool)), edit1, SLOT(add_one()));
    connect(edit1, SIGNAL(tick_signal()), edit2, SLOT(add_one()));
    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}
