#ifndef CTHULHU_H
#define CTHULHU_H

#include <QWidget>
#include <QLabel>
#include <QTabWidget>
#include <QStackedWidget>
#include <QTabBar>
#include <QFrame>

#include "PushButton/zbtnlink.h"
#include "PushButton/zbtnrec.h"
#include "PushButton/zbtnnor.h"
#include "titlebar.h"
#include "Widget/indexpage.h"
#include "Widget/librarypage.h"
#include "Widget/videopage.h"
#include "Widget/blogpage.h"
#include "Widget/exhibitionpage.h"
#include "Widget/aboutpage.h"

class Cthulhu : public QWidget
{
    Q_OBJECT

public:
    Cthulhu(QWidget *parent = nullptr);
    ~Cthulhu();
public slots:
    void pageSwitch(int index);
protected:
    void paintEvent(QPaintEvent *);
private:
    QString _bgColor;
    int _titleBarHeight;
    ZBtnLink *btn_test1;
    ZBtnRec *btn_test2;
    ZBtnNor *btn_test3;

    // 标题栏
    TitleBar *_titleBar;
//    QPushButton *_btnClose;
//    QPushButton *_btnMinimize;
//    bool _move = false;
//    QPoint _startPoint;
//    QPoint _windowPoint;

    // 主页面
    QTabWidget *_tabWidget;
    IndexPage *_indexPage;
    LibraryPage *_libraryPage;
    VideoPage *_videoPage;
    BlogPage *_blogPage;
    ExhibitionPage *_exhibitionPage;
    AboutPage *_aboutPage;
};
#endif // CTHULHU_H
