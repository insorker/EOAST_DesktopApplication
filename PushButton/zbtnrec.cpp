#include "zbtnrec.h"

ZBtnRec::ZBtnRec(const QString &bgColor, const QString &color, const QFont &font, const QString &context, const QString &iconPath, QWidget *parent)
    : ZPushButton(bgColor, color, font, context, iconPath, parent)
{
    setStyleSheet(QString("%1%2").arg(getstylesheet("border:2px solid #323A49;")).arg(getstylesheet("background-color:rgb(62,66,73);border:2px solid #323A49;", ":hover")));
}

void ZBtnRec::enterEvent(QEvent *)
{
    setCursor(QCursor(Qt::PointingHandCursor));
}
