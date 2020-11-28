#ifndef ZBTNREC_H
#define ZBTNREC_H

#include "zpushbutton.h"

class ZBtnRec : public ZPushButton
{
    Q_OBJECT

public:
    ZBtnRec(const QString &bgColor, const QString &color, const QFont &font, const QString &context,
            const QString &iconPath = "", QWidget *parent = nullptr);

protected:
    void enterEvent(QEvent *);
};

#endif // ZBTNREC_H
