#ifndef ZPUSHBUTTON_H
#define ZPUSHBUTTON_H

#include <QPushButton>

class ZPushButton : public QPushButton
{
    Q_OBJECT

public:
    ZPushButton(QWidget *parent = nullptr)
        : QPushButton(parent), _bgColor(), _context(), _iconPath("") { }
    ZPushButton(const QString &bgColor, const QString &color, const QFont &font, const QString &context, const QString &iconPath = "", QWidget *parent = nullptr);

public:
    void setBgColor(const QString &c);
    void setContext(const QString &ct);

protected:
    void setSize(int marginX, int marginY);
    QString getstylesheet(const QString &append = "", const QString &model = "");

private:
    int getTextLength();
    int getTextHeight();

private:
    QString _bgColor;
    QString _color;
    QString _context;
    QString _iconPath;
};

#endif // ZPUSHBUTTON_H
