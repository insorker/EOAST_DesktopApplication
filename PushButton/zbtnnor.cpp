#include "zbtnnor.h"

ZBtnNor::ZBtnNor(const QString &bgColor, const QString &color, const QFont &font, const QString &context, const QString &iconPath, QWidget *parent)
    : ZPushButton(bgColor, color, font, context, iconPath, parent)
{
    setStyleSheet(QString("%1%2%3").arg(getstylesheet("text-align:center center;")).arg(
                      getstylesheet("text-align:center center;background-color:rgb(62,66,73);", ":hover")));
}
