#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QDesktopWidget>
#include <QtDebug>
#include <QGraphicsScene>

#include "sprite.h"
#include "player.h"
#include "enemy.h"
#include "box.h"
#include "reward.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void playerPosition();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;

    float x, y, width, height;

    Player *personaje;
    Enemy *enemy;

    Box *box1;
    Box *box2;
    Box *box3;
    Box *box4;
    Box *box5;
    Box *box6;
    Box *box7;
    Box *box8;
    Box *box9;
    Box *box10;
    Box *box11;
    Box *box12;

    Box *box13;
    Box *box14;
    Box *box15;
    Box *box16;

    Reward *reward;

};
#endif // WIDGET_H
