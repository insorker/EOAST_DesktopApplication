#ifndef ZBTNLINK_H
#define ZBTNLINK_H

#include "zpushbutton.h"

class ZBtnLink : public ZPushButton
{
    Q_OBJECT

public:
    ZBtnLink(const QString &bgColor, const QString &color, const QFont &font, const QString &context,
             const QString &iconPath = "", QWidget *parent = nullptr);
protected:
    void enterEvent(QEvent *);

};

#endif // ZBTNLINK_H
