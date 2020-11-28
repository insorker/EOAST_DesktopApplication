#ifndef ZBTNNOR_H
#define ZBTNNOR_H

#include "zpushbutton.h"

class ZBtnNor : public ZPushButton
{
public:
    ZBtnNor(const QString &bgColor, const QString &color, const QFont &font, const QString &context,
            const QString &iconPath = "", QWidget *parent = nullptr);
};

#endif // ZBTNNOR_H
