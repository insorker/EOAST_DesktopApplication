#include "titlebar.h"

#include <QDebug>

TitleBar::TitleBar(const QString &bgColor, const QString &color, const QFont &font, const QString &iconPath, QWidget *parent)
    : QLabel(parent),
      _nextPos(0),
      _bgColor(bgColor),
      _iconPath(iconPath),
      _iconLabel(new QLabel(this)),
      _index(new ZBtnNor(bgColor, color, font, "首页", "", this)),
      _library(new ZBtnNor(bgColor, color, font, "资料", "", this)),
      _video(new ZBtnNor(bgColor, color, font, "视频", "", this)),
      _blog(new ZBtnNor(bgColor, color, font, "博客", "", this)),
      _exhibition(new ZBtnNor(bgColor, color, font, "成就", "", this)),
      _about(new ZBtnNor(bgColor, color, font, "关于", "", this)),
      _totalTag(6),
      _account(new QPushButton(this)),
      _settings(new QPushButton(this))
{
    setStyleSheet(QString("QLabel{background-color:%1;}").arg(_bgColor));
    setMinimumWidth(1100);
    init();

    connect(_index, &QPushButton::clicked, [=]{ menuSwitch(0); });
    connect(_library, &QPushButton::clicked, [=]{ menuSwitch(1); });
    connect(_video, &QPushButton::clicked, [=]{ menuSwitch(2); });
    connect(_blog, &QPushButton::clicked, [=]{ menuSwitch(3); });
    connect(_exhibition, &QPushButton::clicked, [=]{ menuSwitch(4); });
    connect(_about, &QPushButton::clicked, [=]{ menuSwitch(5); });
    connect(_settings, &QPushButton::clicked, this, &TitleBar::changeBackground);
}

void TitleBar::paintEvent(QPaintEvent *)
{
    init();
}

void TitleBar::init()
{
    const int height = this->height();
    const int width  = this->width();
    const int menuWidth = 100;
    _nextPos = 50;

    if (_iconPath != "")
    {
        // 这里手动改代码要好一点，但也无所谓了
        int w = QPixmap(_iconPath).width(), h = QPixmap(_iconPath).height();
        _iconLabel->resize(w * height / h, height);
        _iconLabel->move(_nextPos, 0);
        _iconLabel->setStyleSheet(QString("QLabel{background-color:%1;border-image:url(%2);}")
                                  .arg(_bgColor).arg(_iconPath));
        _nextPos = width / 2 - _totalTag * (menuWidth + 20) / 2;
    }

    placeMenu(_index, height, menuWidth);
    placeMenu(_library, height, menuWidth);
    placeMenu(_video, height, menuWidth);
    placeMenu(_blog, height, menuWidth);
    placeMenu(_exhibition, height, menuWidth);
    placeMenu(_about, height, menuWidth);

    _account->setStyleSheet(QString("QPushButton{border-image:url(:/img/account.png);background-color:%1}").arg(_bgColor));
    _account->resize(g_titleBarHeight - 20, g_titleBarHeight - 20);
    _account->move(this->width() - g_titleBarHeight - 100, 10);
    _settings->setStyleSheet(QString("QPushButton{border-image:url(:/img/settings.png);background-color:%1}").arg(_bgColor));
    _settings->resize(g_titleBarHeight - 20, g_titleBarHeight - 20);
    _settings->move(this->width() - 100, 10);
}

void TitleBar::placeMenu(ZBtnNor *const btn, const int height, const int width)
{
    btn->resize(width, height);
    btn->move(_nextPos, 0);
    _nextPos += width + 20;
}

void TitleBar::menuSwitch(int index)
{
    emit emitMenuSwitch(index);
}

void TitleBar::changeBackground()
{
    QString bgPath = QFileDialog::getOpenFileName(this, "打开图片", ".", "Text(*.png *.jpg *.bmp)");

    if (bgPath.isEmpty())
    {
          QMessageBox mesg;
          mesg.warning(this, "警告", "打开图片失败!");
          return;
     }
     else
     {
        emitChangeBackground(bgPath);
     }
}
