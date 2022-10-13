#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include "gamewidget.h"
#include <QPixmap>
#include <QPainter>
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPushButton* b1,*b2;
    gamewidget w1;
    QPixmap image1;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent*);
};

#endif // MAINWINDOW_H
