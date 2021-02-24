#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QRect desktop = QApplication::desktop()->screenGeometry();
    x = desktop.x();
    y = desktop.y();
    width = 570;
    height = 570;

    scene = new QGraphicsScene(x, y, width, height);

    ui->graphicsView->setScene(scene);

    // Instanciacion de Personaje
    personaje = new Player(nullptr, ":/img/sprite.png");
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    scene->addItem(personaje);
    personaje->setPos(30,30);

    // Instanciacion de Enemigo
    enemy = new Enemy(nullptr, ":/img/enemy.png");
    scene->addItem(enemy);
    enemy->setPos(256,500);

    QTimer* timerEvent = new QTimer(this);
    timerEvent->start(300);
    connect(timerEvent, &QTimer::timeout, this, &Widget::playerPosition);

    // Instancia Obstaculos
    box1 = new Box(nullptr, ":/img/box.png");
    box2 = new Box(nullptr, ":/img/box.png");
    box3 = new Box(nullptr, ":/img/box.png");
    box4 = new Box(nullptr, ":/img/box.png");
    box5 = new Box(nullptr, ":/img/box.png");
    box6 = new Box(nullptr, ":/img/box.png");
    box7 = new Box(nullptr, ":/img/box.png");
    box8 = new Box(nullptr, ":/img/box.png");
    box9 = new Box(nullptr, ":/img/box.png");
    box10 = new Box(nullptr, ":/img/box.png");
    box11 = new Box(nullptr, ":/img/box.png");
    box12 = new Box(nullptr, ":/img/box.png");
    box13 = new Box(nullptr, ":/img/box.png");
    box14 = new Box(nullptr, ":/img/box.png");
    box15 = new Box(nullptr, ":/img/box.png");
    box16 = new Box(nullptr, ":/img/box.png");

    // Obstaculo superior
    scene->addItem(box1);
    scene->addItem(box2);
    scene->addItem(box3);
    scene->addItem(box4);
    scene->addItem(box5);
    scene->addItem(box6);
    scene->addItem(box7);
    scene->addItem(box8);
    scene->addItem(box9);
    scene->addItem(box10);
    scene->addItem(box11);
    scene->addItem(box12);

    box1->setPos(128,128);
    box2->setPos(192,128);
    box3->setPos(256,128);
    box4->setPos(128,208);
    box5->setPos(192,208);
    box6->setPos(256,208);

    box7->setPos(320,128);
    box8->setPos(384,128);
    box9->setPos(448,128);
    box10->setPos(320,208);
    box11->setPos(384,208);
    box12->setPos(448,208);

    // Obstaculo Inferior
    scene->addItem(box13);
    scene->addItem(box14);
    scene->addItem(box15);
    scene->addItem(box16);

    box13->setPos(320,448);
    box14->setPos(384,448);
    box15->setPos(320,512);
    box16->setPos(384,512);

    // Objetivo-Premio
    reward = new Reward(nullptr, ":/img/reward.png");
    scene->addItem(reward);
    reward->setPos(526,526);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::playerPosition()
{
    enemy->direction(personaje->_x, personaje->_y);
}

