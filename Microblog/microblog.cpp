#include "microblog.h"

Microblog::Microblog(const QString &title, const QString &link, const QString &mode, QWidget *parent)
    : QLabel(parent),
      _title(title),
      _mode(mode),
      _height(0),
      _titleHeight(50),
      _contentHeight(300),
      _interactHeight(30)
{
    createBlog(link);
}

void Microblog::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(Qt::white);
    p.setBrush(Qt::white);
    p.drawRect(this->rect());

    p.setPen(QPen(QColor(120, 120, 120), 1, Qt::SolidLine));
    p.drawLine(20, _titleHeight, this->width() - 20, _titleHeight);

    p.setPen(QPen(QColor(222, 156, 83), 1, Qt::SolidLine));
    p.drawLine(20, _contentHeight + _titleHeight, this->width() - 20, _contentHeight + _titleHeight);

    p.setPen(QPen(QColor(222, 156, 83), 1, Qt::SolidLine));
    p.drawLine(20, _contentHeight + _titleHeight + _interactHeight, this->width() - 20, _contentHeight + _titleHeight + _interactHeight);

    p.setFont(QFont("Microsoft YaHei", 16));
    p.setPen(QPen(QColor(120, 120, 120), 1, Qt::SolidLine));
    p.drawText(QRect(20, 0, 50, _titleHeight), Qt::AlignVCenter, _title);
}

void Microblog::createBlog(const QString &link)
{
//    _avatar(new QPushButton()),
//    _username(new ZBtnLink()),
//    _moreContent(new ZBtnLink()),
//    _like(new ZBtnNor()),
//    _comment(new ZBtnNor()),
//    _share(new ZBtnNor())
}

void Microblog::setSize(int w)
{
    _height = _titleHeight + _contentHeight + _interactHeight + 20;
    this->resize(w, _height);
}
