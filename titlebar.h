#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QLabel>
#include "PushButton/zbtnnor.h"

class TitleBar : public QLabel
{
    Q_OBJECT
public:
    TitleBar(const QString &bgColor, const QString &color, const QFont &font, const QString &iconPath = "", QWidget *parent = nullptr);
    void init();
signals:
    void emitMenuSwitch(int index);
protected:
    void paintEvent(QPaintEvent *);
private:
    void placeMenu(ZBtnNor* const btn, const int height, const int width = 100);
    void btnClicked(int index);
private:
    int _nextPos;
    QString _bgColor;
    QString _iconPath;
    QLabel *_iconLabel;

    ZBtnNor *_index;
    ZBtnNor *_library;
    ZBtnNor *_video;
    ZBtnNor *_blog;
    ZBtnNor *_exhibition;
    ZBtnNor *_about;
    int _totalTag;
};

#endif // TITLEBAR_H
