#include "zpushbutton.h"

ZPushButton::ZPushButton(const QString &bgColor, const QString &color, const QFont &font, const QString &context, const QString &iconPath, QWidget *parent)
    : QPushButton(parent),
      _bgColor(bgColor),
      _color(color),
      _context(context),
      _iconPath(iconPath)

{
    setFont(font);
    setBgColor(bgColor);
    setContext(context);
    if (iconPath != "") setIcon(QIcon(iconPath));
    setStyleSheet(getstylesheet(""));
}

void ZPushButton::setBgColor(const QString &c)
{
    _bgColor = c;
}

void ZPushButton::setContext(const QString &ct)
{
    this->setText(ct);
}

void ZPushButton::setSize(int marginX = 0, int marginY = 0)
{
    resize(getTextLength() + marginX, getTextHeight() + marginY);
}

int ZPushButton::getTextLength()
{
    QFontMetrics fm(this->font());
    return fm.horizontalAdvance(_context);
}

int ZPushButton::getTextHeight()
{
    QFontMetrics fm(this->font());
    return fm.height();
}

QString ZPushButton::getstylesheet(const QString &append, const QString &model)
{
    return QString("QPushButton%1{background-color:%2;color:%3;text-align:left center;padding-left:2px;border:none;%4}")
            .arg(model).arg(_bgColor).arg(_color).arg(append);
}
