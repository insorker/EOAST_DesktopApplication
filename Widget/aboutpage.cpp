#include "aboutpage.h"
#include <QDebug>

AboutPage::AboutPage(QWidget *parent)
    : QWidget(parent),
      _logo(new QLabel("LOGO", this)),
      _Cthlhu(new QLabel("CTHLHU", this)),
      _test1(new ZBtnLink("rgb(255,255,255)", "rgb(254,67,101)", QFont("Microsoft YaHei", 16), "Preferences", "", this)),
      _test2(new ZBtnLink("rgb(255,255,255)", "rgb(254,67,101)", QFont("Microsoft YaHei", 16), "Manage Profiles", "", this))
{
}

void AboutPage::resizeEvent(QResizeEvent *)
{
    QPixmap logo(":/img/logo_3.png");
    int startX = this->width() / 2 - logo.width() / 2;
    int startY = 50 + logo.height();
    _logo->setPixmap(logo);
    _logo->move(startX, 0);
    _Cthlhu->move(startX - 100, startY);
    _Cthlhu->setFont(QFont("Microsoft YaHei", 24, QFont::Black));
    _Cthlhu->setStyleSheet("QLabel{background-color:transparent;}");
    _test1->move(startX - 50, startY + 80);
    _test2->move(startX - 50, startY + 140);
}

void AboutPage::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::white);
    p.drawRect(this->rect());
}
