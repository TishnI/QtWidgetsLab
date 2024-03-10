#ifndef WIN_H
#define WIN_H

#include "area.h"
class Win : public QWidget
{
    Q_OBJECT
protected:
    Area * area;
    QPushButton * btn;
public:
    explicit Win(QWidget *parent = nullptr);

signals:
};

#endif // WIN_H
