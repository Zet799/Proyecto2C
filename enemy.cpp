#include "enemy.h"

#include <QGraphicsScene>

Enemy::Enemy(QObject *parent, const char *dir) : Sprite(parent)
{
    spriteEnemy = new Sprite();
    pixmap = new QPixmap(dir);

    timerSprite->start(150);
    connect(timerSprite, &QTimer::timeout, this, &Sprite::refresh);

    QTimer* timerEvent = new QTimer(this);
    timerEvent->start(1000);
    connect(timerEvent, &QTimer::timeout, this, &Enemy::move);

}

void Enemy::move()
{
    switch (_movementDirection) {
    case MovementDirection::UP:
        row = 192;
        if(y() >= 32) setPos(x(),y()-32);
        break;
    case MovementDirection::DOWN:
        row = 0;
        if(y() <= 532) setPos(x(),y()+32);
        break;
    case MovementDirection::LEFT:
        row = 64;
        if(x() >= 32) setPos(x()-32,y());
        break;
    case MovementDirection::RIGHT:
        row = 128;
        if(x() <= 538) setPos(x()+32,y());
        break;
    default:
        ;
    }
}

void Enemy::direction(int x, int y)
{
    _distanceUp = sqrt(pow((pos().x() - x), 2) + pow(((pos().y()-32) - y), 2));
    _distanceDown = sqrt(pow((pos().x() - x), 2) + pow(((pos().y()+32) - y), 2));
    _distanceRight = sqrt(pow(((pos().x()+32) - x), 2) + pow((pos().y() - y), 2));
    _distanceLeft = sqrt(pow(((pos().x()-32) - x), 2) + pow((pos().y() - y), 2));

    distance[0] = _distanceUp;
    distance[1] = _distanceDown;
    distance[2] = _distanceRight;
    distance[3] = _distanceLeft;

    int index = indexSmall(distance, 4);

    switch (index) {
    case 0:
        _movementDirection = MovementDirection::UP;
        break;
    case 1:
        _movementDirection = MovementDirection::DOWN;
        break;
    case 2:
        _movementDirection = MovementDirection::RIGHT;
        break;
    case 3:
        _movementDirection = MovementDirection::LEFT;
        break;
    default:
        ;
    }

}

int Enemy::indexSmall(float array[], int size)
{
    int index = 0;

    for(int i = 1; i < size; i++)
    {
        if(array[i] < array[index])
            index = i;
    }

    return index;
}




