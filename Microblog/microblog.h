#ifndef MICROBLOG_H
#define MICROBLOG_H

#include <QLabel>
#include <QPushButton>
#include <QPainter>
#include <QPlainTextEdit>
#include "PushButton/zbtnlink.h"
#include "PushButton/zbtnnor.h"

class Microblog : public QLabel
{
    Q_OBJECT
public:
    Microblog(const QString &title, const QString &link, const QString &mode = "", QWidget *parent = nullptr);
public:
    void setSize(int w);
protected:
    void paintEvent(QPaintEvent *);
    void createBlog(const QString &link);
private:
    QString _title;
    QString _mode;
    int _height;
    const int _titleHeight;
    const int _contentHeight;
    const int _interactHeight;
//    QPushButton *_avatar;
//    ZBtnLink *_username;
//    ZBtnLink *_moreContent;
//    QPlainTextEdit *_content;
//    ZBtnNor *_like;
//    ZBtnNor *_comment;
//    ZBtnNor *_share;
};

#endif // MICROBLOG_H
