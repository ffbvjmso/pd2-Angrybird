#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QPoint>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include "background.h"
#include "bluebird.h"
#include "yellowbird.h"
#include "blackbird.h"
#include "pig.h"
#include "shooter.h"
#include "wood.h"
#include "whitebird.h"
#include "egg.h"
#include "win.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void delBlueBird();
    void restart();
    void showResult();
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    void check();
    void IsPigDead();

    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    Bird *red;
    blueBird *blue1;
    blueBird *blue2;
    blueBird *blue3;
    yellowBird *yellow;
    blackBird *black;
    whiteBird *white;
    Pig *piggy;
    wood *w1;
    egg *e;
    int press;
    int release;
    int del;
    int de;
    int deb1;
    int deb2;
    int deb3;
    int birdtype;
    float Mx;
    float My;
    float Px;
    float Py;
    int pigdead;
    int r;
};

#endif // MAINWINDOW_H
