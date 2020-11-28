#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include "PushButton/zbtnlink.h"

class AboutPage : public QWidget
{
    Q_OBJECT
public:
    explicit AboutPage(QWidget *parent = nullptr);
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    QLabel *_logo;
    QLabel *_Cthlhu;
    ZBtnLink *_test1;
    ZBtnLink *_test2;
};

#endif // ABOUTPAGE_H
