#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qgraphicsview.h>
#include<obj.h>
#include<obj2.h>
#include<pig.h>
#include<sling.h>
#include<blackbird.h>
#include<bluebird.h>
#include<QGraphicsPixmapItem>
#include<yellowbird.h>
#include <QtWidgets>
#include<QMediaPlayer>

QMediaPlayer *bgmusic=new QMediaPlayer();
QMediaPlayer *laughmusic=new QMediaPlayer();
QMediaPlayer *screammusic=new QMediaPlayer();
QMediaPlayer *skillmusic=new QMediaPlayer();


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);

    bgmusic->setMedia(QUrl("qrc:/music/+Horror+Scare+Thriller+MOVIE+MUSIC+BY+DJ.HOT.mp3"));
    laughmusic->setMedia(QUrl("qrc:/music/laugh.wav"));
    screammusic->setMedia(QUrl("qrc:/music/scream.wav"));
    skillmusic->setMedia(QUrl("qrc:/hhh/blood.wav"));

    clicked=false;
    click=0;
    whetherclick=false;
    vx=20;
    vy=20;
    i=0;
    v=0;

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,960,540);
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

    QPixmap Mainscreen(":/hhh/Haunted House-2.jpg");
    Mainscreen=Mainscreen.scaled(1000,600);
    Main=new QGraphicsPixmapItem();
    Main->setPixmap(Mainscreen);
    Main->setPos(0,0);
    scene->addItem(Main);

    bgmusic->play();
    showscore =new QLabel(this);
    showscore->setFont(QFont("BlackMagic",15,QFont::Bold));
    showscore->setText("<h1><font color=white>Score : "+QString::number(score));
    showscore->setGeometry(20,-60,400,200);
    showscore->show();

    QPixmap s(":/all/shooter.png");
    QLabel *shooter =new QLabel(this);
    shooter->setPixmap(s);
    shooter->setGeometry(240,350,70,100);
    shooter->show();

    train_button = new QPushButton(this);
    train_button->setText(tr("restart"));
    train_button->setGeometry(830,20,100,50);
    train_button->show();

    exit= new QPushButton(this);
    exit->setText(tr("exit"));
    exit->setGeometry(700,20,100,50);
    exit->show();

    win =new QLabel(this);
    win->setFont(QFont("BlackMagic",30,QFont::Bold));
    win->setText("<h1><font color=black>win!!! ");
    win->setGeometry(350,120,400,200);
    win->hide();


    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(960,height()/6.0),world,scene));
    newobj();
    pigi=new pig(23.0f,4.0f,1.6f,&timer,QPixmap(":/thing/pigi.png").scaled(120,150),world,scene);
    printf("sNew1");
    pigi2=new pig(30.0f,4.0f,1.6f,&timer,QPixmap(":/thing/pigi.png").scaled(120,150),world,scene);
    printf("sNew2");
    pigi_exist=true;
    pigii_exist=true;

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);

    connect(train_button,SIGNAL(clicked(bool)),this,SLOT(restart()));
    connect(exit,SIGNAL(clicked(bool)),this,SLOT(close()));
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!


    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
        if(mouse_event->button()==Qt::LeftButton){
            mx = QCursor::pos().x();
            my= QCursor::pos().y();
            //printf("\n%d\n%d\n",mx,my);
            if(mx<1160&&my>320){
                click++;
                printf("c%d",click);
                whetherclick=true;
                if(click>0&&click<60&&click%5==0){
                if(((click/5)%11)==1){
                    sling1=new sling(8.0f,7.0f,1.0f,0.5f,world,scene);
                    sling_exist=true;
                    itemList.push_back(sling1);
                    delete birdie;
                    birdie_exist=false;
                    birdie1 = new Bird(8.0f,10.0f,0.3f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
                    birdie1_exist=true;
                    itemList.push_back(birdie1);
                }
                if(((click/5)%11)==3){
                   sling1=new sling(8.0f,7.0f,1.0f,0.5f,world,scene);
                   sling_exist=true;
                   itemList.push_back(sling1);
                    delete lbirdie;
                   lbirdie_exist=false;
                    birdie2 = new blackbird(8.0f,10.0f,0.3f,&timer,QPixmap(":/all/black.png").scaled(height()/9.0,height()/9.0),world,scene);
                    itemList.push_back(birdie2);
                    birdie2_exist=true;
                }
                if(((click/5)%11)==5){
                    birdie2->skill();
                    skillmusic->play();
                }
                if(((click/5)%11)==6){
                    sling1=new sling(8.0f,7.0f,1.0f,0.5f,world,scene);
                    sling_exist=true;
                    itemList.push_back(sling1);
                    delete bbirdie;
                    bbirdie_exist=false;
                    birdie3 = new bluebird(8.0f,10.0f,0.3f,&timer,QPixmap(":/all/blue.png").scaled(height()/9.0,height()/9.0),world,scene);
                    itemList.push_back(birdie3);
                    birdie3_exist=true;
                }
                if(((click/5)%11)==8){
                    birdie3->skill();
                    skillmusic->play();
                 }
                if(((click/5)%11)==9){
                    sling1=new sling(8.0f,7.0f,1.0f,0.5f,world,scene);
                    sling_exist=true;
                    itemList.push_back(sling1);
                    delete ybirdie;
                    ybirdie_exist=false;
                    birdie4 = new yellowbird(8.0f,10.0f,0.3f,&timer,QPixmap(":/all/yellow.png").scaled(height()/9.0,height()/9.0),world,scene);
                    itemList.push_back(birdie4);
                    birdie4_exist=true;
                }
                if(((click/5)%11)==0){
                    birdie4->skill();
                    skillmusic->play();
                 }
                 if(((click/5)%11)==2||((click/5)%11)==4||((click/5)%11)==7||((click/5)%11)==10){
                     clicked=true;
                     x0 = QCursor::pos().x();
                     y0= QCursor::pos().y();
                     xx=x0;
                     yy=y0;
                }
            }

            }
        }
    }
    if(event->type() == QEvent::MouseMove)
    {
        if(clicked==true&&i==0){
            birdie1->g_body->SetTransform(b2Vec2(((float)x0-480.0)*(32.0/960.0),18.0/2.0-(((float)y0-550.0)*(18.0/540.0))),0);
            x0 = QCursor::pos().x();
            y0= QCursor::pos().y();

        }
        if(clicked==true&&i==1){
            birdie2->g_body->SetTransform(b2Vec2(((float)x0-480.0)*(32.0/960.0),18.0/2.0-(((float)y0-550.0)*(18.0/540.0))),0);
            x0 = QCursor::pos().x();
            y0= QCursor::pos().y();

        }
        if(clicked==true&&i==2){
            birdie3->g_body->SetTransform(b2Vec2(((float)x0-480.0)*(32.0/960.0),18.0/2.0-(((float)y0-550.0)*(18.0/540.0))),0);
            x0 = QCursor::pos().x();
            y0= QCursor::pos().y();

        }
        if(clicked==true&&i==3){
            birdie4->g_body->SetTransform(b2Vec2(((float)x0-480.0)*(32.0/960.0),18.0/2.0-(((float)y0-550.0)*(18.0/540.0))),0);
            x0 = QCursor::pos().x();
            y0= QCursor::pos().y();

        }
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        nx = QCursor::pos().x();
        ny= QCursor::pos().y();
        if(nx<1160&&ny>320){
            release_count++;
            printf("r%d",release_count);
            if(click>0&&release_count>0&&click<60&&click%5==0&&(release_count%2)==0&&release_count<24){
             if(((click/5)%11)==2){
                 i++;
                 screammusic->play();
                 clicked=false;
                 delete sling1;
                 sling_exist=false;
                 x1 = QCursor::pos().x();
                 y1= QCursor::pos().y();
                 //printf("\n%d\n%d",x1,y1);
                 d=sqrt((xx-x1)*(xx-x1)+(yy-y1)*(yy-y1));
                 fvx=(float)vx*(((float)xx-(float)x1)/(float)d);
                 fvy=(float)vy*(((float)y1-(float)yy)/(float)d);
                 birdie1->setLinearVelocity(b2Vec2(fvx,fvy));


            }
             if(((click/5)%11)==4){
                 i++;
                 clicked=false;
                 screammusic->play();
                 delete sling1;
                 sling_exist=false;
                 x1 = QCursor::pos().x();
                 y1= QCursor::pos().y();
                 //printf("\n%d\n%d",x1,y1);
                 d=sqrt((xx-x1)*(xx-x1)+(yy-y1)*(yy-y1));
                 fvx=(float)vx*(((float)xx-(float)x1)/(float)d);
                 fvy=(float)vy*(((float)y1-(float)yy)/(float)d);
                 birdie2->setLinearVelocity(b2Vec2(fvx,fvy));


            }
             if(((click/5)%11)==7){
                 i++;
                 clicked=false;
                 screammusic->play();
                 delete sling1;
                 sling_exist=false;
                 x1 = QCursor::pos().x();
                 y1= QCursor::pos().y();
                 //printf("\n%d\n%d",x1,y1);
                 d=sqrt((xx-x1)*(xx-x1)+(yy-y1)*(yy-y1));
                 fvx=(float)vx*(((float)xx-(float)x1)/(float)d);
                 fvy=(float)vy*(((float)y1-(float)yy)/(float)d);
                 birdie3->setLinearVelocity(b2Vec2(fvx,fvy));


            }
             if(((click/5)%11)==10){
                 i++;
                 clicked=false;
                 screammusic->play();
                 delete sling1;
                 sling_exist=false;
                 x1 = QCursor::pos().x();
                 y1= QCursor::pos().y();
                 //printf("\n%d\n%d",x1,y1);
                 d=sqrt((xx-x1)*(xx-x1)+(yy-y1)*(yy-y1));
                 fvx=(float)vx*(((float)xx-(float)x1)/(float)d);
                 fvy=(float)vy*(((float)y1-(float)yy)/(float)d);
                 birdie4->setLinearVelocity(b2Vec2(fvx,fvy));


            }
        }
        }

    }
    return false;
}
void MainWindow::pig_disappear()
{   timecount++;
    if(timecount%100==0&&pigi_exist==true){
        pig_vx=pigi->g_body->GetLinearVelocity().x;
        pig_vy=pigi->g_body->GetLinearVelocity().y;
        pig_angle=pigi->g_body->GetAngularVelocity();
    }
    if(timecount%100==0&&pigii_exist==true){
        pig2_vx=pigi2->g_body->GetLinearVelocity().x;
        pig2_vy=pigi2->g_body->GetLinearVelocity().y;
        pig2_angle=pigi2->g_body->GetAngularVelocity();
    }
        if(pig_vx>0.05||pig_vy>0.05||pig_angle>0.05||pig_vx<-0.05||pig_vy<-0.05||pig_angle<-0.05){
            if(j==0){
                laughmusic->play();
                delete pigi;

                pigi_exist=false;
                score=score+500;
                showscore->setText("<h1><font color=white>Score : "+QString::number(score));


                j++;
            }
        }
        if(pig2_vx>0.05||pig2_vy>0.05||pig2_angle>0.05||pig2_vx<-0.05||pig2_vy<-0.05||pig2_angle<-0.05){
            if(k==0){
                laughmusic->play();
                delete pigi2;

                pigii_exist=false;
                score=score+500;
                showscore->setText("<h1><font color=white>Score : "+QString::number(score));
                k++;
            }
        }
        if(pigi_exist==false&&pigii_exist==false){
            whether_win=true;
            if(h==0){
                time++;
                printf("%d",time);
                h++;
            }
            //win->show();
            click=100;
        }


}

void MainWindow::newobj()
{
    birdie = new Bird(3.5f,10.0f,0.3f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    lbirdie = new blackbird(2.5f,10.0f,0.3f,&timer,QPixmap(":/all/black.png").scaled(height()/9.0,height()/9.0),world,scene);
    bbirdie = new bluebird(1.5f,10.0f,0.3f,&timer,QPixmap(":/all/blue.png").scaled(height()/9.0,height()/9.0),world,scene);
    ybirdie = new yellowbird(0.5f,10.0f,0.3f,&timer,QPixmap(":/all/yellow.png").scaled(height()/9.0,height()/9.0),world,scene);

    birdie_exist=true;
    lbirdie_exist=true;
    bbirdie_exist=true;
    ybirdie_exist=true;

    obj1 = new obj(26.0f,18.0f,0.8f,8.5f,&timer,QPixmap(":/thing/woodii.png").scaled(60,300),world,scene);
    obj3 = new obj(19.0f,18.0f,0.8f,8.5f,&timer,QPixmap(":/thing/woodii.png").scaled(60,300),world,scene);
    obj4 = new obj2(22.5f,28.0f,8.5f,0.8f,&timer,QPixmap(":/thing/woodi.png").scaled(300,60),world,scene);

    // Setting the Velocity
    birdie->setLinearVelocity(b2Vec2(0,7));
    lbirdie->setLinearVelocity(b2Vec2(0,8));
    bbirdie->setLinearVelocity(b2Vec2(0,9));
    ybirdie->setLinearVelocity(b2Vec2(0,10));

    itemList.push_back(birdie);
    itemList.push_back(lbirdie);
    itemList.push_back(bbirdie);
    itemList.push_back(ybirdie);
    itemList.push_back(obj1);
    itemList.push_back(obj3);
    itemList.push_back(obj4);
    itemList.push_back(pigi);
}

void MainWindow::deleteobj()
{

    if(birdie_exist==true){delete  birdie ;}
    if(lbirdie_exist==true){delete lbirdie ;}
    if(bbirdie_exist==true){delete bbirdie ;}
    if(ybirdie_exist==true){delete ybirdie ;}
    if(birdie1_exist==true){delete birdie1 ;}
    if(birdie2_exist==true){delete birdie2 ;}
    if(birdie3_exist==true){delete birdie3 ;}
    if(birdie4_exist==true){delete birdie4 ;}
    if(sling_exist==true){delete sling1;}
    if(pigi_exist==true){delete pigi ; }

    if(pigii_exist==true){delete pigi2 ;}
    bgmusic->stop();
    delete  obj1 ;
    delete  obj3 ;
    delete  obj4 ;
}


void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::restart(){
        win->clear();
        deleteobj();
        score=0;
        showscore->setText("<h1><font color=white>Score : "+QString::number(score));
        whetherclick=false;
        clicked=false;
        release_count=0;
        click=0;
        rightclick=0;
        timecount=0;
        j=0;
        k=0;
        f=0;
        m=0;
        n=0;
        x1=0;
        i=0;
        h=0;
        whether_win=false;
        pig_vx=0.0;
        pig_vy=0.0;
        pig_angle=0.0;
        pig2_vx=0.0;
        pig2_vy=0.0;
        pig2_angle=0.0;
        clicked=false;
        newobj();
        pigi=new pig(23.0f,4.0f,1.6f,&timer,QPixmap(":/thing/pigi.png").scaled(120,150),world,scene);
        pigi2=new pig(30.0f,4.0f,1.6f,&timer,QPixmap(":/thing/pigi.png").scaled(120,150),world,scene);


        bgmusic->play();
        pigi_exist=true;
        pigii_exist=true;



}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    pig_disappear();
    scene->update();

}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
