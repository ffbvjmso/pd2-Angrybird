#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
    press = 0;
    release = 0;
    del = 0;
    de=0;
    deb1=0;
    deb2=0;
    deb3=0;
    birdtype = 0;
    pigdead=0;
    r=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));

    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

    // Create ground (You can edit here)
    new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene);
 //   itemList.push_back(new shooter(10.0f,3.0f,10.0f,10.0f,QPixmap(":/image/shooter_t.png"),world,scene));

    //Create enemey
    piggy = new Pig(25.0f,6.0f,0.3f,&timer,QPixmap(":/image/PIGLETTE_BIG_01.png").scaled(height()/9.0,height()/9.0),world,scene);
    itemList.push_back(piggy);
    Px = piggy->getPosX();
    Py = piggy->getPosY();

    w1 = new wood(20.0f,10.0f,0.2f,3.7f,&timer,QPixmap(":/image/thinwood1.png"),world,scene);
    itemList.push_back(w1);

    // Create bird (You can edit here)
    red = new Bird(3.0f,6.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdtype = 1;
    itemList.push_back(red);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));    
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(check()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(IsPigDead()));
    timer.start(100/6);
}


bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouse = static_cast<QMouseEvent *>(event);
        std::cout<<mouse->globalX()<<" "<<mouse->globalY()<<std::endl;
        if((mouse->globalX()<250 && mouse->globalX()>165) && (mouse->globalY()<200 && mouse->globalY()>115))
        {
            //restart

                std::cout<<"restart!!"<<std::endl;
                restart();


        }
        else if((mouse->globalX()>265 && mouse->globalX()<350) && (mouse->globalY()<200 && mouse->globalY()>115))
        {
            //exit
            press=0;
            std::cout<<"exit!!"<<std::endl;
            emit quitGame();
        }

        /* TODO : add your code here */
        else
        {
            std::cout << "Press !" << std::endl ;
            press=1;
        }

    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
    //    std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouse = static_cast<QMouseEvent *>(event);
        QPoint mpt = QWidget::mapFromGlobal(mouse->globalPos());

        /* TODO : add your code here */
        std::cout << "Release !" << std::endl ;

        switch (birdtype) {
        case 1:
        {
            if(release==0)
            {
                float Px = red->getPosx() - red->trans(mpt).x;
                float Py = red->getPosy() - red->trans(mpt).y;
                red->setLinearVelocity(b2Vec2(Px*5,Py*4));
                release++;
                press=0;
                std::cout<<"release="<<release<<std::endl;
                break;
            }

        }
            break;
        case 2:
        {
            if(release==0)
            {
                float Px = yellow->getPosx() - yellow->trans(mpt).x;
                float Py = yellow->getPosy() - yellow->trans(mpt).y;
                yellow->setLinearVelocity(b2Vec2(Px*5,Py*4));
                release++;
                press=0;
                std::cout<<"release="<<release<<std::endl;
                break;
            }
            if(release==1)
            {
                if(press==1)
                {
                    std::cout<<"yellow bird!!"<<std::endl;
                    float Vx = yellow->getVelocityX();
                    float Vy = yellow->getVelocityY();
                    yellow->setLinearVelocity(b2Vec2(Vx*5,Vy*5));
                    release++;
                }
                break;
            }
        }
            break;
        case 3:
        {
            if(release==0)
            {
                float Px = white->getPosx() - white->trans(mpt).x;
                float Py = white->getPosy() - white->trans(mpt).y;
                white->setLinearVelocity(b2Vec2(Px*5,Py*4));
                release++;
                press=0;
                std::cout<<"release="<<release<<std::endl;
                break;
            }
            if(release==1)
            {
                if(press==1)
                {
                    std::cout<<"white bird!!"<<std::endl;
                    float Wx = white->getPosx();
                    float Wy = white->getPosy();
                    e = new egg(Wx,Wy,0.05f,&timer,QPixmap(":/image/egg.png").scaled(36,36),world,scene);
                    itemList.push_back(e);
                    e->eggsetLinearVelocity(b2Vec2((-1),(-10)));
                    release++;
                }
                break;
            }
        }
            break;
        case 4:
        {
            if(release==0)
            {
                float Px = blue1->getPosx() - blue1->trans(mpt).x;
                float Py = blue1->getPosy() - blue1->trans(mpt).y;
                blue1->setLinearVelocity(b2Vec2(Px*5,Py*4));
                release++;
                press=0;
                std::cout<<"release="<<release<<std::endl;
                break;
            }
            if(release==1)
            {
                if(press==1)
                {
                    birdtype = 5;
                }
            }
        }
            break;
        case 5:
        {
            if(release==1)
            {
                std::cout<<"blue bird!!"<<std::endl;
                float Bx = blue1->getPosx();
                float By = blue1->getPosy();
                float Vx = blue1->getVelocityX();
                float Vy = blue1->getVelocityY();

                blue2 = new blueBird(Bx,By,0.3f,&timer,QPixmap(":/image/blue.png").scaled(height()/9.0,height()/9.0),world,scene);
                itemList.push_back(blue2);
                blue3 = new blueBird(Bx,By,0.3f,&timer,QPixmap(":/image/blue.png").scaled(height()/9.0,height()/9.0),world,scene);
                itemList.push_back(blue3);

                blue2->setLinearVelocity(b2Vec2(Vx,Vy*3+4));
                blue3->setLinearVelocity(b2Vec2(Vx,Vy*2-4));
                release++;
            }
        }

        default:
            break;
        }
    }
    if(de==1)
        showResult();
    return false;
}
void MainWindow::delBlueBird()
{
    if(deb1==0)
    {
        if(((blue1->getVelocityX())==0 && (blue1->getVelocityY())==0) || (blue1->getPosx())>35 || (blue1->getPosy())>20)
        {
            delete blue1;
            deb1=1;
        }
    }
    if(release>=1 && press==1)
    {
        if(deb2==0)
        {
            if(((blue2->getVelocityX())==0 && (blue2->getVelocityY())==0) || (blue2->getPosx())>35 || (blue2->getPosy())>20)
            {
                delete blue2;
                deb2=1;
            }
        }
        if(deb3==0)
        {
            if(((blue3->getVelocityX())==0 && (blue3->getVelocityY())==0) || (blue3->getPosx())>35 || (blue3->getPosy())>20)
            {
                delete blue3;
                deb3=1;
            }
        }
    }
}

void MainWindow::check()
{
    if(release!=0)
    {
        switch (birdtype) {
        case 1:
        {
            if(((red->getVelocityX())==0 && (red->getVelocityY())==0) || (red->getPosx())>35 || (red->getPosy())>20)
            {
                delete red;                
                yellow = new yellowBird(4.6f,5.0f,0.27f,&timer,QPixmap(":/image/yellow.png").scaled(height()/9.0,height()/9.0),world,scene);
                itemList.push_back(yellow);
                birdtype = 2;
                release=0;
            }
        }
            break;
        case 2:
        {
            if(((yellow->getVelocityX())==0 && (yellow->getVelocityY())==0) || (yellow->getPosx())>35 || (yellow->getPosy())>20)
            {
                delete yellow;
                white = new whiteBird(4.6f,5.0f,0.27f,&timer,QPixmap(":/image/white.png").scaled(height()/9.0,height()/9.0),world,scene);
                itemList.push_back(white);
                birdtype = 3;
                release=0;
            }
        }
            break;
        case 3:
        {
            if(((white->getVelocityX())==0 && (white->getVelocityY())==0) || (white->getPosx())>35 || (white->getPosy())>20)
            {
                delete white;
                delete e;
                blue1 = new blueBird(4.6f,5.0f,0.27f,&timer,QPixmap(":/image/blue.png").scaled(height()/9.0,height()/9.0),world,scene);
                itemList.push_back(blue1);
                birdtype = 4;
                release=0;
            }
        }
            break;
        case 4:
        {
            if(((blue1->getVelocityX())==0 && (blue1->getVelocityY())==0) || (blue1->getPosx())>35 || (blue1->getPosy())>20)
            {
                delete blue1;
                release=0;

                de=1;
            }
        }
            break;
        case 5:
        {
            delBlueBird();

            de=1;
        }
            break;

        default:
            break;
        }
    }
}

void MainWindow::IsPigDead()
{
    if(pigdead==0)
    {
        float tempx = piggy->getPosX();
        float tempy = piggy->getPosY();
        if((tempx-Px)>2 || (tempy-Py)>5 || (piggy->getVelX())>5 || (piggy->getVelY())>5)
        {
            delete piggy;
            pigdead=1;

        }

    }

}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}


void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::restart()
{

    //clear
    for(int i=0;i<itemList.size();i++)
    {
        std::cout<<"delete"<<i<<std::endl;

        delete itemList.at(i);
    }

    //initialize
    std::cout<<"initialize"<<std::endl;
    press = 0;
    release = 0;
    del = 0;
    de=0;
    deb1=0;
    deb2=0;
    deb3=0;
    birdtype = 0;
    pigdead=0;

    //Create enemey
    std::cout<<"Create"<<std::endl;
    piggy = new Pig(25.0f,6.0f,0.3f,&timer,QPixmap(":/image/PIGLETTE_BIG_01.png").scaled(height()/9.0,height()/9.0),world,scene);
    itemList.push_back(piggy);
    Px = piggy->getPosX();
    Py = piggy->getPosY();

    w1 = new wood(20.0f,10.0f,0.2f,3.7f,&timer,QPixmap(":/image/thinwood1.png"),world,scene);
    itemList.push_back(w1);

    // Create bird
    red = new Bird(3.0f,6.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdtype = 1;
    itemList.push_back(red);
}
void MainWindow::showResult()
{
    if(pigdead==0)
    {
        //lose
        std::cout<<"lose!!"<<std::endl;
    }
    if(pigdead==1)
    {
        //win
        std::cout<<"win!!"<<std::endl;
    }
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
