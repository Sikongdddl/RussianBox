#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QDebug>
#include <QPixmap>
#include <QFile>
#include <QFileDialog>
#include <QPoint>
#include <QmessageBox>
#include <QTimer>

#include "box.h"
#include "item.h"

#define HEIGHT 20
#define WIDTH 10
#define BLOCK_SIZE 50

class gamewidget:public QWidget
{
private:
    box** map;
    QPushButton* fall;
    QPushButton* moveLeft;
    QPushButton* moveRight;
    QPushButton* traverse;
    QTimer *timer;
    void init();
public:
    Item curOne;
    std::vector<Item::locat> nextPos;
    std::vector<Item::locat> formerPos;
    gamewidget();
    ~gamewidget();
    void lambdaConnection();
    void nextOne();
    void checkDel();
    void maintainDel(int);
    void copy(int , int );
protected:
    void paintEvent(QPaintEvent*);

};

#endif // GAMEWIDGET_H
