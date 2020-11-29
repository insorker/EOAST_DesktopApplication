#ifndef BLOGPAGE_H
#define BLOGPAGE_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QScrollArea>
#include "Microblog/microblog.h"
#include "settings.h"

#include <QDebug>

class BlogInPage : public QWidget
{
    Q_OBJECT
public:
    explicit BlogInPage(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *);
    void setSize();
    void modifylbl(int index);
private:
    int _numofvec;
    QVector<Microblog *> _mbVector;
};

class BlogPage : public QWidget
{
    Q_OBJECT
public:
    explicit BlogPage(QWidget *parent = nullptr)
        : QWidget(parent),
          _scrollArea(new QScrollArea(this)),
          _bloginpage(new BlogInPage(this)),
          _bgPath("")
    {
        // https://blog.csdn.net/qq_23903863/article/details/79759105 这位兄弟是真的nb，scrollArea可以透明了
        _scrollArea->setStyleSheet("QScrollArea{background-color:transparent;}");
        _scrollArea->viewport()->setStyleSheet("background-color:transparent;");
        _scrollArea->setFrameShape(QFrame::NoFrame);
        _scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        _scrollArea->setWidget(_bloginpage);
    }
public:
    void setBackgroundPic(const QString &bgPath)
    { _bgPath = bgPath; }
protected:
    void resizeEvent(QResizeEvent *)
    {
        _scrollArea->setGeometry(0, 0, this->width(), this->height());
        _bloginpage->resize(this->width(), this->height() * 3);
    }
    void paintEvent(QPaintEvent *)
    {
        QPainter p(this);
        if (_bgPath == "")
        {
            p.setPen(Qt::NoPen);
            p.setBrush(QColor(200, 200, 169));
            p.drawRect(this->rect());
            qDebug() << _bgPath;
        }
        else p.drawPixmap(rect(), QPixmap(_bgPath));
    }
private:
    QScrollArea *_scrollArea;
    QScrollBar  *_scrollBar;
    BlogInPage *_bloginpage;
    QString _bgPath;
};

#endif // BLOGPAGE_H
