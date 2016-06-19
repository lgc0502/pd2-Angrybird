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
#include <Box2D/Dynamics/Joints/b2MouseJoint.h>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <sling.h>
#include<blackbird.h>
#include<bluebird.h>
#include<yellowbird.h>
#include<pig.h>
#include<QLabel>
#include<QtWidgets>
#include<obj.h>
#include<obj2.h>

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
    void pig_disappear();
    void newobj();
    void deleteobj();

    Bird *birdie;
    bluebird *bbirdie;
    blackbird *lbirdie;
    yellowbird *ybirdie;
    Bird *birdie1;
    blackbird *birdie2;
    bluebird *birdie3;
    yellowbird *birdie4;
    sling *sling1;
    pig *pigi;
    pig *pigi2;
    QGraphicsPixmapItem *Main;
    QLabel *showscore;
    QLabel *showlife;
    QLabel *life1;
    QLabel *life2;
    QLabel *life3;
    QLabel *win;
    QPushButton *train_button;
    QPushButton *restartb;
    QPushButton *exit;
    obj *obj1;
    obj *obj3;
    obj2 *obj4;

signals:
    // Signal for closing the game
    void quitGame();



private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void restart();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    b2Contact *contact;
    QList<GameItem *> itemList;
    QTimer timer;
    bool whetherclick;
    bool clicked;
    int click=0;
    int rightclick=0;
    int timecount=0;
    int j=0;
    int k=0;
    int f=0;
    int h=0;
    int i;
    int m=0;
    int n=0;
    float xp;
    float yp;
    int x0,x1,xx,yy;
    int release_count=0;
    int y0,y1,d;
    float fvx,fvy;
    int vx;
    int vy;
    float v;
    int life=4;
    int score=0;
    int mx,nx;
    int my,ny;
    int time=0;
    bool whether_win=false;
    bool pigi_exist=true;
    bool pigii_exist=true;
    float pig_vx=0,pig_vy=0,pig_angle=0;
    float pig2_vx=0,pig2_vy=0,pig2_angle=0;
    bool birdie_exist=false;
    bool bbirdie_exist=false;
    bool lbirdie_exist=false;
    bool ybirdie_exist=false;
    bool birdie1_exist=false;
    bool birdie2_exist=false;
    bool birdie3_exist=false;
    bool birdie4_exist=false;
    bool sling_exist=false;
};

#endif // MAINWINDOW_H
