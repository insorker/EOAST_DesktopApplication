#include "blogpage.h"

#include <QDebug>

BlogInPage::BlogInPage(QWidget *parent)
    : QWidget(parent),
      _numofvec(5)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    for (int i = 0; i < _numofvec; i ++ )
    {
        // read info
        Microblog *mb = new Microblog("title", "link", "mode", this);
        _mbVector.push_back(mb);
    }
    setSize();
}

void BlogInPage::paintEvent(QPaintEvent *)
{
    for (int i = 0; i < _numofvec; i ++ ) modifylbl(i);
}

void BlogInPage::modifylbl(int index)
{
    if (index >= _numofvec) return;

    int w = this->width() / 2;
    int h = g_titleBarHeight;
    int startX = this->width() / 4;
    for (auto it = _mbVector.begin(); it != &_mbVector[index]; ++ it )
        h += (*it)->height() + 100;

    _mbVector[index]->move(startX, h);
    _mbVector[index]->setSize(w);
//    _scrollArea->setGeometry(this->width() - _scrollArea->width(), g_titleBarHeight, _scrollArea->width(), 0);
}

void BlogInPage::setSize()
{

}
