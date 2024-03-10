#include "win.h"

Win::Win(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Возведение в квадрат");
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);
    inputLabel = new QLabel("Введите число:", this);
    inputEdit = new QLineEdit("", this);
    StrValidator v = new StrValidator(inputEdit);
    inputEdit->setValidator(&v);
    outputLabel = new QLabel("Результат:", this);
    outputEdit = new QLineEdit("",this);
    nextButton = new QPushButton("Следующее", this);
    exitButton = new QPushButton("Выход", this);

    QVBoxLayout *frameLayout = new QVBoxLayout(frame);
    frameLayout->addWidget(inputLabel);
    frameLayout->addWidget(inputEdit);
    frameLayout->addWidget(outputLabel);
    frameLayout->addWidget(outputEdit);
    frameLayout->addStretch();

    QVBoxLayout *buttonLayout = new QVBoxLayout();
    buttonLayout->addWidget(nextButton);
    buttonLayout->addWidget(exitButton);
    buttonLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(frame);
    mainLayout->addLayout(buttonLayout);

    begin();

    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(nextButton,SIGNAL(clicked(bool)),SLOT(begin()));
    connect(inputEdit,SIGNAL(returnPressed()), SLOT(calc()));
}

void Win::begin()
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void Win::calc()
{
    bool Ok = true;
    float r, a;
    QString str = inputEdit->text();
    a = str.toDouble(&Ok);
    if(Ok)
    {
        r = a*a;
        str.setNum(r);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else{
        if(!str.isEmpty()){
            QMessageBox msgBox(QMessageBox::Information,
                               "Squaring",
                               "Invalid value entered.",
                               QMessageBox::Ok);
            msgBox.exec();
        }
    }
}
