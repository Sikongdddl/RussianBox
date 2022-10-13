#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(500,500);
    b1 = new QPushButton("开始游戏",this);
    b2 = new QPushButton("退出游戏",this);
    b1->resize(200,50);
    b2->resize(200,50);
    b1->move(150,150);
    b2->move(150,300);
    image1.load(":/picture/R-C.jfif");
    connect(b1,&QPushButton::clicked,this,[=]()
    {
        w1.show();
        this->hide();
    });
    connect(b2,&QPushButton::clicked,this,[=]()
    {
       this->hide();
    });
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,500,image1);
}
