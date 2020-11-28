#include "zbtnlink.h"

#include <QDebug>

ZBtnLink::ZBtnLink(const QString &bgColor, const QString &color, const QFont &font, const QString &context, const QString &iconPath, QWidget *parent)
    : ZPushButton(bgColor, color, font, context, iconPath, parent)
{
    setSize(5, 3);
    setStyleSheet(QString("%1%2").arg(getstylesheet()).arg(getstylesheet("text-decoration:underline;", ":hover")));
}

void ZBtnLink::enterEvent(QEvent *)
{
    setCursor(QCursor(Qt::PointingHandCursor));
}
