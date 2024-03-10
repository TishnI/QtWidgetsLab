#ifndef WIN_H
#define WIN_H

#include <QtWidgets>

class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString &contents, QWidget *parent = nullptr): QLineEdit(contents, parent){}
signals:
    void tick_signal();
public slots:
    void add_one()
    {
        QString str = text();
        int r = str.toInt();
        if(r != 0 && r%5 == 0) emit tick_signal();
        r++;
        str.setNum(r);
        setText(str);
    }
};

class Win : public QWidget
{
    Q_OBJECT
protected:
    QLabel *label1, *label2;
    Counter *edit1, *edit2;
    QPushButton *calcButton;
    QPushButton *exitButton;
public:
    explicit Win(QWidget *parent = nullptr);
};

#endif // WIN_H
