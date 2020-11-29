#include "cthulhu.h"

/*rgb(240,240,240)
 *rgb(40,44,52)
 *rgb(33,33,33)
 */

#include <QDebug>

Cthulhu::Cthulhu(QWidget *parent)
    : QWidget(parent),
      _bgColor("rgb(240,240,240)"),
      _titleBar(new TitleBar("rgb(33,33,33)", "rgb(153,161,177)", QFont("幼圆", 16), "://img/logo_1.png", this)),
      _tabWidget(new QTabWidget(this)),
      _indexPage(new IndexPage(this)),
      _libraryPage(new LibraryPage(this)),
      _videoPage(new VideoPage(this)),
      _blogPage(new BlogPage(this)),
      _exhibitionPage(new ExhibitionPage(this)),
      _aboutPage(new AboutPage(this))
{
    resize(1530, 920);
    setMinimumWidth(1100);
    setStyleSheet(QString("QWidget{background-color:%1;}").arg(_bgColor));
    _titleBar->resize(this->width(), g_titleBarHeight);
    _titleBar->move(0, 0);
    _tabWidget->move(0, g_titleBarHeight);
    _tabWidget->resize(this->width(), this->height() - g_titleBarHeight);
    _indexPage->resize(this->width(), this->height() - g_titleBarHeight);
    _tabWidget->addTab(_indexPage, "");
    _tabWidget->addTab(_libraryPage, "");
    _tabWidget->addTab(_videoPage, "");
    _tabWidget->addTab(_blogPage, "");
    _tabWidget->addTab(_exhibitionPage, "");
    _tabWidget->addTab(_aboutPage, "");
    _tabWidget->setStyleSheet("QTabWidget{border:none;}");
    _tabWidget->tabBar()->hide();

    connect(_titleBar, &TitleBar::emitMenuSwitch, this, &Cthulhu::pageSwitch);
    connect(_titleBar, &TitleBar::emitChangeBackground, this, &Cthulhu::setBackgroundPic);
//    _layout->addWidget(_stackedWidget);
//    setLayout(_layout);
//    btn_test1 = new ZBtnLink(_bgColor, "rgb(61,185,221)", QFont("黑体", 16), "Preferences", "", this);
//    btn_test1->move(0, 70);
//    btn_test2 = new ZBtnRec(_bgColor, "rgb(61,185,221)", QFont("黑体", 16), "Preferences", "", this);
//    btn_test2->move(0, 100);
//    btn_test2->resize(180, 30);
//    btn_test3 = new ZBtnNor(_bgColor, "rgb(61,185,221)", QFont("黑体", 16), "Preferences", "", this);
//    btn_test3->move(0, 140);
//    btn_test3->resize(180, 30);
}

Cthulhu::~Cthulhu()
{
}

void Cthulhu::paintEvent(QPaintEvent *)
{
    _titleBar->resize(this->width(), g_titleBarHeight);
    _tabWidget->move(0, g_titleBarHeight);
    _tabWidget->resize(this->width(), this->height() - g_titleBarHeight);
}

void Cthulhu::pageSwitch(int index)
{
    _tabWidget->setCurrentIndex(index);
}

void Cthulhu::setBackgroundPic(const QString &bgPath)
{
    _blogPage->setBackgroundPic(bgPath);
}
